/************************************************************************
 * Derived from the BSD3-licensed
 * LAPACK routine (version 3.7.1) --
 *     Univ. of Tennessee, Univ. of California Berkeley,
 *     Univ. of Colorado Denver and NAG Ltd..
 *     June 2017
 * Copyright 2019-2020 Advanced Micro Devices, Inc.
 * ***********************************************************************/

#ifndef ROCLAPACK_GEBD2_H
#define ROCLAPACK_GEBD2_H

#include "rocblas.hpp"
#include "rocsolver.h"
#include "common_device.hpp"
#include "../auxiliary/rocauxiliary_lacgv.hpp"
#include "../auxiliary/rocauxiliary_larfg.hpp"
#include "../auxiliary/rocauxiliary_larf.hpp"


template <typename T, bool BATCHED>
void rocsolver_gebd2_getMemorySize(const rocblas_int m, const rocblas_int n, const rocblas_int batch_count,
                                  size_t *size_1, size_t *size_2, size_t *size_3, size_t *size_4)
{
    size_t s1, s2;
    rocsolver_larf_getMemorySize<T,BATCHED>(m,n,batch_count,size_1,&s1,size_3);
    rocsolver_larfg_getMemorySize<T>(m,n,batch_count,size_4,&s2);
    *size_2 = max(s1, s2);
}

template <typename S, typename T, typename U>
rocblas_status rocsolver_gebd2_gebrd_argCheck(const rocblas_int m, const rocblas_int n, const rocblas_int lda,
                                              T A, S D, S E, U tauq, U taup, const rocblas_int batch_count = 1)
{
    // order is important for unit tests:

    // 1. invalid/non-supported values
    // N/A

    // 2. invalid size
    if (m < 0 || n < 0 || lda < m || batch_count < 0)
        return rocblas_status_invalid_size;

    // 3. invalid pointers
    if ((m*n && !A) || (m*n && !D) || (m*n && !E) || (m*n && !tauq) || (m*n && !taup))
        return rocblas_status_invalid_pointer;

    return rocblas_status_continue;
}

template <typename S, typename T, typename U, bool COMPLEX = is_complex<T>>
rocblas_status rocsolver_gebd2_template(rocblas_handle handle, const rocblas_int m, const rocblas_int n,
                                        U A, const rocblas_int shiftA, const rocblas_int lda, const rocblas_stride strideA,
                                        S* D, const rocblas_stride strideD, S* E, const rocblas_stride strideE,
                                        T* tauq, const rocblas_stride strideQ, T* taup, const rocblas_stride strideP,
                                        const rocblas_int batch_count, T* scalars, T* work, T** workArr, T* diag)
{
    // quick return
    if (m == 0 || n == 0 || batch_count == 0) 
        return rocblas_status_success;

    hipStream_t stream;
    rocblas_get_stream(handle, &stream);

    rocblas_int dim = min(m, n);    //total number of pivots

    if (m >= n)
    {
        // generate upper bidiagonal form
        for (rocblas_int j = 0; j < n; j++)
        {
            // generate Householder reflector H(j)
            rocsolver_larfg_template(handle,
                                    m - j,                                 //order of reflector
                                    A, shiftA + idx2D(j,j,lda),            //value of alpha
                                    A, shiftA + idx2D(min(j+1,m-1),j,lda), //vector x to work on
                                    1, strideA,                            //inc of x    
                                    (tauq + j), strideQ,                   //tau
                                    batch_count, diag, work);

            // copy A(j,j) to D and insert one to build/apply the householder matrix 
            hipLaunchKernelGGL(set_diag<T>, dim3(batch_count,1,1), dim3(1,1,1), 0, stream,
                D, j, strideD, A, shiftA + idx2D(j,j,lda), lda, strideA, 1, true);

            // Apply Householder reflector H(j)
            if (j < n - 1)
            {
                // conjugate tauq
                if (COMPLEX)
                    rocsolver_lacgv_template<T>(handle, 1, tauq, j, 1, strideQ, batch_count);
                
                rocsolver_larf_template(handle,rocblas_side_left,           //side
                                        m - j,                              //number of rows of matrix to modify
                                        n - j - 1,                          //number of columns of matrix to modify    
                                        A, shiftA + idx2D(j,j,lda),         //householder vector x
                                        1, strideA,                         //inc of x
                                        (tauq + j), strideQ,                //householder scalar (alpha)
                                        A, shiftA + idx2D(j,j+1,lda),       //matrix to work on
                                        lda, strideA,                       //leading dimension
                                        batch_count, scalars, work, workArr);
                
                // restore tauq
                if (COMPLEX)
                    rocsolver_lacgv_template<T>(handle, 1, tauq, j, 1, strideQ, batch_count);
            }
            
            // restore original value of A(j,j)
            hipLaunchKernelGGL(restore_diag<T>, dim3(batch_count,1,1), dim3(1,1,1), 0, stream,
                D, j, strideD, A, shiftA + idx2D(j,j,lda), lda, strideA, 1);
            
            if (j < n - 1)
            {
                if (COMPLEX)
                    rocsolver_lacgv_template<T>(handle, n-j-1, A, shiftA + idx2D(j,j+1,lda), lda, strideA, batch_count);

                // generate Householder reflector G(j)
                rocsolver_larfg_template(handle,
                                        n - j - 1,                             //order of reflector
                                        A, shiftA + idx2D(j,j+1,lda),          //value of alpha
                                        A, shiftA + idx2D(j,min(j+2,n-1),lda), //vector x to work on
                                        lda, strideA,                          //inc of x    
                                        (taup + j), strideP,                   //tau
                                        batch_count, diag, work);

                // copy A(j,j+1) to E and insert one to build/apply the householder matrix 
                hipLaunchKernelGGL(set_diag<T>, dim3(batch_count,1,1), dim3(1,1,1), 0, stream,
                    E, j, strideE, A, shiftA + idx2D(j,j+1,lda), lda, strideA, 1, true);
                
                // Apply Householder reflector G(j)
                rocsolver_larf_template(handle,rocblas_side_right,          //side
                                        m - j - 1,                          //number of rows of matrix to modify
                                        n - j - 1,                          //number of columns of matrix to modify    
                                        A, shiftA + idx2D(j,j+1,lda),       //householder vector x
                                        lda, strideA,                       //inc of x
                                        (taup + j), strideP,                //householder scalar (alpha)
                                        A, shiftA + idx2D(j+1,j+1,lda),     //matrix to work on
                                        lda, strideA,                       //leading dimension
                                        batch_count, scalars, work, workArr);
                
                if (COMPLEX)
                    rocsolver_lacgv_template<T>(handle, n-j-1, A, shiftA + idx2D(j,j+1,lda), lda, strideA, batch_count);

                // restore original value of A(j,j+1)
                hipLaunchKernelGGL(restore_diag<T>, dim3(batch_count,1,1), dim3(1,1,1), 0, stream,
                    E, j, strideE, A, shiftA + idx2D(j,j+1,lda), lda, strideA, 1);
            }
            else
            {
                // zero taup(j)
                hipLaunchKernelGGL(reset_batch_info<T>, dim3(1,batch_count), dim3(1,1), 0, stream, taup + j, strideP, 1, 0);
            }
        }
    }
    else
    {
        // generate lower bidiagonal form
        for (rocblas_int j = 0; j < m; j++)
        {
            if (COMPLEX)
                rocsolver_lacgv_template<T>(handle, n-j, A, shiftA + idx2D(j,j,lda), lda, strideA, batch_count);

            // generate Householder reflector G(j)
            rocsolver_larfg_template(handle,
                                    n - j,                                 //order of reflector
                                    A, shiftA + idx2D(j,j,lda),            //value of alpha
                                    A, shiftA + idx2D(j,min(j+1,n-1),lda), //vector x to work on
                                    lda, strideA,                          //inc of x    
                                    (taup + j), strideP,                   //tau
                                    batch_count, diag, work);
            
            // copy A(j,j) to D and insert one to build/apply the householder matrix 
            hipLaunchKernelGGL(set_diag<T>, dim3(batch_count,1,1), dim3(1,1,1), 0, stream,
                D, j, strideD, A, shiftA + idx2D(j,j,lda), lda, strideA, 1, true);

            // Apply Householder reflector G(j)
            if (j < m - 1)
            {
                rocsolver_larf_template(handle,rocblas_side_right,          //side
                                        m - j - 1,                          //number of rows of matrix to modify
                                        n - j,                              //number of columns of matrix to modify    
                                        A, shiftA + idx2D(j,j,lda),         //householder vector x
                                        lda, strideA,                       //inc of x
                                        (taup + j), strideP,                //householder scalar (alpha)
                                        A, shiftA + idx2D(j+1,j,lda),       //matrix to work on
                                        lda, strideA,                       //leading dimension
                                        batch_count, scalars, work, workArr);
            }
            
            if (COMPLEX)
                rocsolver_lacgv_template<T>(handle, n-j, A, shiftA + idx2D(j,j,lda), lda, strideA, batch_count);
            
            // restore original value of A(j,j)
            hipLaunchKernelGGL(restore_diag<T>, dim3(batch_count,1,1), dim3(1,1,1), 0, stream,
                D, j, strideD, A, shiftA + idx2D(j,j,lda), lda, strideA, 1);
            
            if (j < m - 1)
            {
                // generate Householder reflector H(j)
                rocsolver_larfg_template(handle,
                                        m - j - 1,                             //order of reflector
                                        A, shiftA + idx2D(j+1,j,lda),          //value of alpha
                                        A, shiftA + idx2D(min(j+2,m-1),j,lda), //vector x to work on
                                        1, strideA,                            //inc of x    
                                        (tauq + j), strideQ,                   //tau
                                        batch_count, diag, work);

                // copy A(j+1,j) to D and insert one to build/apply the householder matrix 
                hipLaunchKernelGGL(set_diag<T>, dim3(batch_count,1,1), dim3(1,1,1), 0, stream,
                    E, j, strideE, A, shiftA + idx2D(j+1,j,lda), lda, strideA, 1, true);
                
                // conjugate tauq
                if (COMPLEX)
                    rocsolver_lacgv_template<T>(handle, 1, tauq, j, 1, strideQ, batch_count);
                
                // Apply Householder reflector H(j)
                rocsolver_larf_template(handle,rocblas_side_left,           //side
                                        m - j - 1,                          //number of rows of matrix to modify
                                        n - j - 1,                          //number of columns of matrix to modify    
                                        A, shiftA + idx2D(j+1,j,lda),       //householder vector x
                                        1, strideA,                         //inc of x
                                        (tauq + j), strideQ,                //householder scalar (alpha)
                                        A, shiftA + idx2D(j+1,j+1,lda),     //matrix to work on
                                        lda, strideA,                       //leading dimension
                                        batch_count, scalars, work, workArr);
                
                // restore tauq
                if (COMPLEX)
                    rocsolver_lacgv_template<T>(handle, 1, tauq, j, 1, strideQ, batch_count);

                // restore original value of A(j,j+1)
                hipLaunchKernelGGL(restore_diag<T>, dim3(batch_count,1,1), dim3(1,1,1), 0, stream,
                    E, j, strideE, A, shiftA + idx2D(j+1,j,lda), lda, strideA, 1);
            }
            else
            {
                // zero tauq(j)
                hipLaunchKernelGGL(reset_batch_info<T>, dim3(1,batch_count), dim3(1,1), 0, stream, tauq + j, strideQ, 1, 0);
            }
        }
    }

    return rocblas_status_success;
}

#endif /* ROCLAPACK_GEBD2_H */
