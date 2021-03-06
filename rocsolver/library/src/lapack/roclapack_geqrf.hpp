/************************************************************************
 * Derived from the BSD3-licensed
 * LAPACK routine (version 3.9.0) --
 *     Univ. of Tennessee, Univ. of California Berkeley,
 *     Univ. of Colorado Denver and NAG Ltd..
 *     November 2019
 * Copyright 2019-2020 Advanced Micro Devices, Inc.
 * ***********************************************************************/

#ifndef ROCLAPACK_GEQRF_H
#define ROCLAPACK_GEQRF_H

#include "rocblas.hpp"
#include "rocsolver.h"
#include "roclapack_geqr2.hpp"
#include "../auxiliary/rocauxiliary_larft.hpp"
#include "../auxiliary/rocauxiliary_larfb.hpp"

template <typename T, bool BATCHED>
void rocsolver_geqrf_getMemorySize(const rocblas_int m, const rocblas_int n, const rocblas_int batch_count,
                                  size_t *size_1, size_t *size_2, size_t *size_3, size_t *size_4, size_t *size_5)
{
    size_t s1,s2,s3;
    rocsolver_geqr2_getMemorySize<T,BATCHED>(m,n,batch_count,size_1,&s1,size_3,size_4);
    if (m <= GEQRF_GEQR2_SWITCHSIZE || n <= GEQRF_GEQR2_SWITCHSIZE) {
        *size_2 = s1;
        *size_5 = 0;
    } else {
        rocblas_int jb = GEQRF_GEQR2_BLOCKSIZE;
        rocsolver_larft_getMemorySize<T>(jb,batch_count,&s2);
        rocsolver_larfb_getMemorySize<T>(rocblas_side_left,m,n-jb,jb,batch_count,&s3);
        *size_2 = max(s1,max(s2,s3));
        *size_5 = sizeof(T)*jb*jb*batch_count;
    }        
}

template <bool BATCHED, bool STRIDED, typename T, typename U>
rocblas_status rocsolver_geqrf_template(rocblas_handle handle, const rocblas_int m,
                                        const rocblas_int n, U A, const rocblas_int shiftA, const rocblas_int lda, 
                                        const rocblas_stride strideA, T* ipiv,  
                                        const rocblas_stride strideP, const rocblas_int batch_count,
                                        T* scalars, T* work, T** workArr, T* diag, T* trfact)
{
    // quick return
    if (m == 0 || n == 0 || batch_count == 0) 
        return rocblas_status_success;

    hipStream_t stream;
    rocblas_get_stream(handle, &stream);

    // if the matrix is small, use the unblocked (BLAS-levelII) variant of the algorithm
    if (m <= GEQRF_GEQR2_SWITCHSIZE || n <= GEQRF_GEQR2_SWITCHSIZE) 
        return rocsolver_geqr2_template<T>(handle, m, n, A, shiftA, lda, strideA, ipiv, strideP, batch_count, scalars, work, workArr, diag);
    
    rocblas_int dim = min(m, n);    //total number of pivots
    rocblas_int jb, j = 0;

    rocblas_int ldw = GEQRF_GEQR2_BLOCKSIZE;
    rocblas_stride strideW = rocblas_stride(ldw) *ldw;

    while (j < dim - GEQRF_GEQR2_SWITCHSIZE) {
        // Factor diagonal and subdiagonal blocks 
        jb = min(dim - j, GEQRF_GEQR2_BLOCKSIZE);  //number of columns in the block
        rocsolver_geqr2_template<T>(handle, m-j, jb, A, shiftA + idx2D(j,j,lda), lda, strideA, (ipiv + j), strideP, batch_count, scalars, work, workArr, diag);

        //apply transformation to the rest of the matrix
        if (j + jb < n) {
            
            //compute block reflector
            rocsolver_larft_template<T>(handle, rocblas_forward_direction, 
                                        rocblas_column_wise, m-j, jb, 
                                        A, shiftA + idx2D(j,j,lda), lda, strideA, 
                                        (ipiv + j), strideP,
                                        trfact, ldw, strideW, batch_count, scalars, work, workArr);

            //apply the block reflector
            rocsolver_larfb_template<BATCHED,STRIDED,T>(handle,rocblas_side_left,rocblas_operation_conjugate_transpose,rocblas_forward_direction,
                                        rocblas_column_wise,m-j, n-j-jb, jb,
                                        A, shiftA + idx2D(j,j,lda), lda, strideA,
                                        trfact, 0, ldw, strideW,
                                        A, shiftA + idx2D(j,j+jb,lda), lda, strideA, batch_count, work, workArr);

        }
        j += GEQRF_GEQR2_BLOCKSIZE;
    }

    //factor last block
    if (j < dim) 
        rocsolver_geqr2_template<T>(handle, m-j, n-j, A, shiftA + idx2D(j,j,lda), lda, strideA, (ipiv + j), strideP, batch_count, scalars, work, workArr, diag);
        
    return rocblas_status_success;
}

#endif /* ROCLAPACK_GEQRF_H */
