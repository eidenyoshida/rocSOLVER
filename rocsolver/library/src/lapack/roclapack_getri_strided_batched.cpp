/* ************************************************************************
 * Copyright 2019-2020 Advanced Micro Devices, Inc.
 * ************************************************************************ */

#include "roclapack_getri.hpp"

template <typename T, typename U>
rocblas_status rocsolver_getri_strided_batched_impl(rocblas_handle handle, const rocblas_int n, U A,
                                        const rocblas_int lda, const rocblas_stride strideA, rocblas_int* ipiv,
                                        const rocblas_stride strideP, rocblas_int *info, const rocblas_int batch_count) 
{ 
    if(!handle)
        return rocblas_status_invalid_handle;
    
    //logging is missing ???    
    
    // argument checking
    rocblas_status st = rocsolver_getri_argCheck(n,lda,A,ipiv,info,batch_count);
    if (st != rocblas_status_continue)
        return st;
        
    // memory managment
    size_t size_1;  //size of constants
    size_t size_2;  //size of workspace
    size_t size_3;  //size of array of pointers to workspace
    rocsolver_getri_getMemorySize<false,T>(n,batch_count,&size_1,&size_2,&size_3);

    // (TODO) MEMORY SIZE QUERIES AND ALLOCATIONS TO BE DONE WITH ROCBLAS HANDLE
    void *scalars, *work, *workArr;
    hipMalloc(&scalars,size_1);
    hipMalloc(&work,size_2);
    hipMalloc(&workArr,size_3);
    if (!scalars || (size_2 && !work) || (size_3 && !workArr))
        return rocblas_status_memory_error;

    // scalar constants for rocblas functions calls
    // (to standarize and enable re-use, size_1 always equals 3*sizeof(T))
    T sca[] = { -1, 0, 1 };
    RETURN_IF_HIP_ERROR(hipMemcpy(scalars, sca, size_1, hipMemcpyHostToDevice));

    // execution
    rocblas_status status = 
           rocsolver_getri_template<false,true,T>(handle,n,
                                                  A,0,    //the matrix is shifted 0 entries (will work on the entire matrix)
                                                  lda,strideA,
                                                  ipiv,0, //the vector is shifted 0 entries (will work on the entire vector)
                                                  strideP,
                                                  info,
                                                  batch_count,
                                                  (T*)scalars,
                                                  (T*)work,
                                                  (T**)workArr);

    hipFree(scalars);
    hipFree(work);
    hipFree(workArr);
    return status;
}


/*
 * ===========================================================================
 *    C wrapper
 * ===========================================================================
 */

extern "C" {

ROCSOLVER_EXPORT rocblas_status rocsolver_sgetri_strided_batched(rocblas_handle handle, const rocblas_int n, float *A,
                 const rocblas_int lda, const rocblas_stride strideA, rocblas_int* ipiv, const rocblas_stride strideP, rocblas_int *info,
                 const rocblas_int batch_count) 
{
    return rocsolver_getri_strided_batched_impl<float>(handle, n, A, lda, strideA, ipiv, strideP, info, batch_count);
}

ROCSOLVER_EXPORT rocblas_status rocsolver_dgetri_strided_batched(rocblas_handle handle, const rocblas_int n, double *A,
                 const rocblas_int lda, const rocblas_stride strideA, rocblas_int* ipiv, const rocblas_stride strideP, rocblas_int *info,
                 const rocblas_int batch_count) 
{
    return rocsolver_getri_strided_batched_impl<double>(handle, n, A, lda, strideA, ipiv, strideP, info, batch_count);
}

ROCSOLVER_EXPORT rocblas_status rocsolver_cgetri_strided_batched(rocblas_handle handle, const rocblas_int n, rocblas_float_complex *A,
                 const rocblas_int lda, const rocblas_stride strideA, rocblas_int* ipiv, const rocblas_stride strideP, rocblas_int *info,
                 const rocblas_int batch_count) 
{
    return rocsolver_getri_strided_batched_impl<rocblas_float_complex>(handle, n, A, lda, strideA, ipiv, strideP, info, batch_count);
}

ROCSOLVER_EXPORT rocblas_status rocsolver_zgetri_strided_batched(rocblas_handle handle, const rocblas_int n, rocblas_double_complex *A,
                 const rocblas_int lda, const rocblas_stride strideA, rocblas_int* ipiv, const rocblas_stride strideP, rocblas_int *info,
                 const rocblas_int batch_count) 
{
    return rocsolver_getri_strided_batched_impl<rocblas_double_complex>(handle, n, A, lda, strideA, ipiv, strideP, info, batch_count);
}

} //extern C
