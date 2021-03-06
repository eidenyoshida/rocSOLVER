
*************
rocSOLVER API
*************

.. toctree::
   :maxdepth: 4 
   :caption: Contents:

This section provides details of the rocSOLVER library API as in last ROCm release. 

Types
=====

rocSOLVER Types
-----------------

Most rocSOLVER types are aliases of rocBLAS types. 
See the `rocBLAS types <https://rocblas.readthedocs.io/en/latest/api.html#types>`_.

rocsolver_int
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygentypedef:: rocsolver_int
.. deprecated:: 3.5
   Use :c:type:`rocblas_int`.

rocsolver_handle
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygentypedef:: rocsolver_handle
.. deprecated:: 3.5
   Use :c:type:`rocblas_handle`.

rocsolver_direction
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygentypedef:: rocsolver_direction
.. deprecated:: 3.5
   Use :c:enum:`rocblas_direct`.

rocsolver_storev
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygentypedef:: rocsolver_storev
.. deprecated:: 3.5
   Use :c:enum:`rocblas_storev`.

rocsolver_operation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygentypedef:: rocsolver_operation
.. deprecated:: 3.5
   Use :c:enum:`rocblas_operation`.

rocsolver_fill
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygentypedef:: rocsolver_fill
.. deprecated:: 3.5
   Use :c:enum:`rocblas_fill`.

rocsolver_diagonal
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygentypedef:: rocsolver_diagonal
.. deprecated:: 3.5
   Use :c:enum:`rocblas_diagonal`.

rocsolver_side
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygentypedef:: rocsolver_side
.. deprecated:: 3.5
   Use :c:enum:`rocblas_side`.

rocsolver_status
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygentypedef:: rocsolver_status
.. deprecated:: 3.5
   Use :c:enum:`rocblas_status`.


Additional Types
-------------------

rocblas_direct
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenenum:: rocblas_direct

rocblas_storev
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenenum:: rocblas_storev


LAPACK Auxiliary Functions
============================

These are functions that support more advanced LAPACK routines.

Complex vector manipulations
--------------------------------------

rocsolver_<type>lacgv()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zlacgv
.. doxygenfunction:: rocsolver_clacgv

Matrix permutations and manipulations
--------------------------------------

rocsolver_<type>laswp()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zlaswp
.. doxygenfunction:: rocsolver_claswp
.. doxygenfunction:: rocsolver_dlaswp
.. doxygenfunction:: rocsolver_slaswp

Householder reflexions
--------------------------

rocsolver_<type>larfg()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zlarfg
.. doxygenfunction:: rocsolver_clarfg
.. doxygenfunction:: rocsolver_dlarfg
.. doxygenfunction:: rocsolver_slarfg

rocsolver_<type>larft()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zlarft
.. doxygenfunction:: rocsolver_clarft
.. doxygenfunction:: rocsolver_dlarft
.. doxygenfunction:: rocsolver_slarft

rocsolver_<type>larf()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zlarf
.. doxygenfunction:: rocsolver_clarf
.. doxygenfunction:: rocsolver_dlarf
.. doxygenfunction:: rocsolver_slarf

rocsolver_<type>larfb()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zlarfb
.. doxygenfunction:: rocsolver_clarfb
.. doxygenfunction:: rocsolver_dlarfb
.. doxygenfunction:: rocsolver_slarfb

Bidiagonal forms
--------------------------

rocsolver_<type>labrd()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zlabrd
.. doxygenfunction:: rocsolver_clabrd
.. doxygenfunction:: rocsolver_dlabrd
.. doxygenfunction:: rocsolver_slabrd

rocsolver_<type>bdsqr()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zbdsqr
.. doxygenfunction:: rocsolver_cbdsqr
.. doxygenfunction:: rocsolver_dbdsqr
.. doxygenfunction:: rocsolver_sbdsqr


Orthonormal matrices
---------------------------

rocsolver_<type>org2r()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_dorg2r
.. doxygenfunction:: rocsolver_sorg2r

rocsolver_<type>orgqr()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_dorgqr
.. doxygenfunction:: rocsolver_sorgqr

rocsolver_<type>orgl2()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_dorgl2
.. doxygenfunction:: rocsolver_sorgl2

rocsolver_<type>orglq()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_dorglq
.. doxygenfunction:: rocsolver_sorglq

rocsolver_<type>orgbr()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_dorgbr
.. doxygenfunction:: rocsolver_sorgbr

rocsolver_<type>orm2r()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_dorm2r
.. doxygenfunction:: rocsolver_sorm2r

rocsolver_<type>ormqr()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_dormqr
.. doxygenfunction:: rocsolver_sormqr

rocsolver_<type>orml2()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_dorml2
.. doxygenfunction:: rocsolver_sorml2

rocsolver_<type>ormlq()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_dormlq
.. doxygenfunction:: rocsolver_sormlq

rocsolver_<type>ormbr()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_dormbr
.. doxygenfunction:: rocsolver_sormbr

Unitary matrices
---------------------------

rocsolver_<type>ung2r()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zung2r
.. doxygenfunction:: rocsolver_cung2r

rocsolver_<type>ungqr()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zungqr
.. doxygenfunction:: rocsolver_cungqr

rocsolver_<type>ungl2()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zungl2
.. doxygenfunction:: rocsolver_cungl2

rocsolver_<type>unglq()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zunglq
.. doxygenfunction:: rocsolver_cunglq

rocsolver_<type>ungbr()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zungbr
.. doxygenfunction:: rocsolver_cungbr

rocsolver_<type>unm2r()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zunm2r
.. doxygenfunction:: rocsolver_cunm2r

rocsolver_<type>unmqr()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zunmqr
.. doxygenfunction:: rocsolver_cunmqr

rocsolver_<type>unml2()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zunml2
.. doxygenfunction:: rocsolver_cunml2

rocsolver_<type>unmlq()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zunmlq
.. doxygenfunction:: rocsolver_cunmlq

rocsolver_<type>unmbr()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zunmbr
.. doxygenfunction:: rocsolver_cunmbr



LAPACK Functions
==================

LAPACK routines solve complex Numerical Linear Algebra problems.

Special Matrix Factorizations
---------------------------------

rocsolver_<type>potf2()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zpotf2
.. doxygenfunction:: rocsolver_cpotf2
.. doxygenfunction:: rocsolver_dpotf2
.. doxygenfunction:: rocsolver_spotf2

rocsolver_<type>potf2_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zpotf2_batched
.. doxygenfunction:: rocsolver_cpotf2_batched
.. doxygenfunction:: rocsolver_dpotf2_batched
.. doxygenfunction:: rocsolver_spotf2_batched

rocsolver_<type>potf2_strided_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zpotf2_strided_batched
.. doxygenfunction:: rocsolver_cpotf2_strided_batched
.. doxygenfunction:: rocsolver_dpotf2_strided_batched
.. doxygenfunction:: rocsolver_spotf2_strided_batched

rocsolver_<type>potrf()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zpotrf
.. doxygenfunction:: rocsolver_cpotrf
.. doxygenfunction:: rocsolver_dpotrf
.. doxygenfunction:: rocsolver_spotrf

rocsolver_<type>potrf_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zpotrf_batched
.. doxygenfunction:: rocsolver_cpotrf_batched
.. doxygenfunction:: rocsolver_dpotrf_batched
.. doxygenfunction:: rocsolver_spotrf_batched

rocsolver_<type>potrf_strided_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zpotrf_strided_batched
.. doxygenfunction:: rocsolver_cpotrf_strided_batched
.. doxygenfunction:: rocsolver_dpotrf_strided_batched
.. doxygenfunction:: rocsolver_spotrf_strided_batched


General Matrix Factorizations
------------------------------

rocsolver_<type>getf2()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgetf2
.. doxygenfunction:: rocsolver_cgetf2
.. doxygenfunction:: rocsolver_dgetf2
.. doxygenfunction:: rocsolver_sgetf2

rocsolver_<type>getf2_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgetf2_batched
.. doxygenfunction:: rocsolver_cgetf2_batched
.. doxygenfunction:: rocsolver_dgetf2_batched
.. doxygenfunction:: rocsolver_sgetf2_batched

rocsolver_<type>getf2_strided_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgetf2_strided_batched
.. doxygenfunction:: rocsolver_cgetf2_strided_batched
.. doxygenfunction:: rocsolver_dgetf2_strided_batched
.. doxygenfunction:: rocsolver_sgetf2_strided_batched

rocsolver_<type>getrf()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgetrf
.. doxygenfunction:: rocsolver_cgetrf
.. doxygenfunction:: rocsolver_dgetrf
.. doxygenfunction:: rocsolver_sgetrf

rocsolver_<type>getrf_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgetrf_batched
.. doxygenfunction:: rocsolver_cgetrf_batched
.. doxygenfunction:: rocsolver_dgetrf_batched
.. doxygenfunction:: rocsolver_sgetrf_batched

rocsolver_<type>getrf_strided_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgetrf_strided_batched
.. doxygenfunction:: rocsolver_cgetrf_strided_batched
.. doxygenfunction:: rocsolver_dgetrf_strided_batched
.. doxygenfunction:: rocsolver_sgetrf_strided_batched

rocsolver_<type>geqr2()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgeqr2
.. doxygenfunction:: rocsolver_cgeqr2
.. doxygenfunction:: rocsolver_dgeqr2
.. doxygenfunction:: rocsolver_sgeqr2

rocsolver_<type>geqr2_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgeqr2_batched
.. doxygenfunction:: rocsolver_cgeqr2_batched
.. doxygenfunction:: rocsolver_dgeqr2_batched
.. doxygenfunction:: rocsolver_sgeqr2_batched

rocsolver_<type>geqr2_strided_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgeqr2_strided_batched
.. doxygenfunction:: rocsolver_cgeqr2_strided_batched
.. doxygenfunction:: rocsolver_dgeqr2_strided_batched
.. doxygenfunction:: rocsolver_sgeqr2_strided_batched

.. _qr_label:

rocsolver_<type>geqrf()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgeqrf
.. doxygenfunction:: rocsolver_cgeqrf
.. doxygenfunction:: rocsolver_dgeqrf
.. doxygenfunction:: rocsolver_sgeqrf

.. _qr_batched_label:

rocsolver_<type>geqrf_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgeqrf_batched
.. doxygenfunction:: rocsolver_cgeqrf_batched
.. doxygenfunction:: rocsolver_dgeqrf_batched
.. doxygenfunction:: rocsolver_sgeqrf_batched

.. _qr_strided_label:

rocsolver_<type>geqrf_strided_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgeqrf_strided_batched
.. doxygenfunction:: rocsolver_cgeqrf_strided_batched
.. doxygenfunction:: rocsolver_dgeqrf_strided_batched
.. doxygenfunction:: rocsolver_sgeqrf_strided_batched

rocsolver_<type>gelq2()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgelq2
.. doxygenfunction:: rocsolver_cgelq2
.. doxygenfunction:: rocsolver_dgelq2
.. doxygenfunction:: rocsolver_sgelq2

rocsolver_<type>gelq2_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgelq2_batched
.. doxygenfunction:: rocsolver_cgelq2_batched
.. doxygenfunction:: rocsolver_dgelq2_batched
.. doxygenfunction:: rocsolver_sgelq2_batched

rocsolver_<type>gelq2_strided_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgelq2_strided_batched
.. doxygenfunction:: rocsolver_cgelq2_strided_batched
.. doxygenfunction:: rocsolver_dgelq2_strided_batched
.. doxygenfunction:: rocsolver_sgelq2_strided_batched

rocsolver_<type>gelqf()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgelqf
.. doxygenfunction:: rocsolver_cgelqf
.. doxygenfunction:: rocsolver_dgelqf
.. doxygenfunction:: rocsolver_sgelqf

rocsolver_<type>gelqf_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgelqf_batched
.. doxygenfunction:: rocsolver_cgelqf_batched
.. doxygenfunction:: rocsolver_dgelqf_batched
.. doxygenfunction:: rocsolver_sgelqf_batched

rocsolver_<type>gelqf_strided_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgelqf_strided_batched
.. doxygenfunction:: rocsolver_cgelqf_strided_batched
.. doxygenfunction:: rocsolver_dgelqf_strided_batched
.. doxygenfunction:: rocsolver_sgelqf_strided_batched

General Matrix Diagonalizations
-------------------------------

rocsolver_<type>gebd2()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgebd2
.. doxygenfunction:: rocsolver_cgebd2
.. doxygenfunction:: rocsolver_dgebd2
.. doxygenfunction:: rocsolver_sgebd2

rocsolver_<type>gebd2_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgebd2_batched
.. doxygenfunction:: rocsolver_cgebd2_batched
.. doxygenfunction:: rocsolver_dgebd2_batched
.. doxygenfunction:: rocsolver_sgebd2_batched

rocsolver_<type>gebd2_strided_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgebd2_strided_batched
.. doxygenfunction:: rocsolver_cgebd2_strided_batched
.. doxygenfunction:: rocsolver_dgebd2_strided_batched
.. doxygenfunction:: rocsolver_sgebd2_strided_batched

rocsolver_<type>gebrd()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgebrd
.. doxygenfunction:: rocsolver_cgebrd
.. doxygenfunction:: rocsolver_dgebrd
.. doxygenfunction:: rocsolver_sgebrd

rocsolver_<type>gebrd_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgebrd_batched
.. doxygenfunction:: rocsolver_cgebrd_batched
.. doxygenfunction:: rocsolver_dgebrd_batched
.. doxygenfunction:: rocsolver_sgebrd_batched

rocsolver_<type>gebrd_strided_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgebrd_strided_batched
.. doxygenfunction:: rocsolver_cgebrd_strided_batched
.. doxygenfunction:: rocsolver_dgebrd_strided_batched
.. doxygenfunction:: rocsolver_sgebrd_strided_batched

General Matrix Inversion
--------------------------

rocsolver_<type>getri()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgetri
.. doxygenfunction:: rocsolver_cgetri
.. doxygenfunction:: rocsolver_dgetri
.. doxygenfunction:: rocsolver_sgetri

rocsolver_<type>getri_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgetri_batched
.. doxygenfunction:: rocsolver_cgetri_batched
.. doxygenfunction:: rocsolver_dgetri_batched
.. doxygenfunction:: rocsolver_sgetri_batched

rocsolver_<type>getri_strided_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgetri_strided_batched
.. doxygenfunction:: rocsolver_cgetri_strided_batched
.. doxygenfunction:: rocsolver_dgetri_strided_batched
.. doxygenfunction:: rocsolver_sgetri_strided_batched

General Systems Solvers
--------------------------

rocsolver_<type>getrs()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgetrs
.. doxygenfunction:: rocsolver_cgetrs
.. doxygenfunction:: rocsolver_dgetrs
.. doxygenfunction:: rocsolver_sgetrs

rocsolver_<type>getrs_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgetrs_batched
.. doxygenfunction:: rocsolver_cgetrs_batched
.. doxygenfunction:: rocsolver_dgetrs_batched
.. doxygenfunction:: rocsolver_sgetrs_batched

rocsolver_<type>getrs_strided_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgetrs_strided_batched
.. doxygenfunction:: rocsolver_cgetrs_strided_batched
.. doxygenfunction:: rocsolver_dgetrs_strided_batched
.. doxygenfunction:: rocsolver_sgetrs_strided_batched


Lapack-like Functions
========================

Other Lapack-like routines provided by rocSOLVER.

General Matrix Factorizations
---------------------------------

rocsolver_<type>getf2_npvt()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgetf2_npvt
.. doxygenfunction:: rocsolver_cgetf2_npvt
.. doxygenfunction:: rocsolver_dgetf2_npvt
.. doxygenfunction:: rocsolver_sgetf2_npvt

rocsolver_<type>getf2_npvt_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgetf2_npvt_batched
.. doxygenfunction:: rocsolver_cgetf2_npvt_batched
.. doxygenfunction:: rocsolver_dgetf2_npvt_batched
.. doxygenfunction:: rocsolver_sgetf2_npvt_batched

rocsolver_<type>getf2_npvt_strided_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgetf2_npvt_strided_batched
.. doxygenfunction:: rocsolver_cgetf2_npvt_strided_batched
.. doxygenfunction:: rocsolver_dgetf2_npvt_strided_batched
.. doxygenfunction:: rocsolver_sgetf2_npvt_strided_batched

rocsolver_<type>getrf_npvt()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgetrf_npvt
.. doxygenfunction:: rocsolver_cgetrf_npvt
.. doxygenfunction:: rocsolver_dgetrf_npvt
.. doxygenfunction:: rocsolver_sgetrf_npvt

rocsolver_<type>getrf_npvt_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgetrf_npvt_batched
.. doxygenfunction:: rocsolver_cgetrf_npvt_batched
.. doxygenfunction:: rocsolver_dgetrf_npvt_batched
.. doxygenfunction:: rocsolver_sgetrf_npvt_batched

rocsolver_<type>getrf_npvt_strided_batched()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_zgetrf_npvt_strided_batched
.. doxygenfunction:: rocsolver_cgetrf_npvt_strided_batched
.. doxygenfunction:: rocsolver_dgetrf_npvt_strided_batched
.. doxygenfunction:: rocsolver_sgetrf_npvt_strided_batched



Auxiliaries
=========================

Auxiliary Functions
---------------------

rocSOLVER auxiliary functions are aliases of rocBLAS auxiliary functions.
See the `rocBLAS auxiliary functions <https://rocblas.readthedocs.io/en/latest/api.html#auxiliary>`_.

rocsolver_create_handle()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_create_handle
.. deprecated:: 3.5
   Use :c:func:`rocblas_create_handle`.

rocsolver_destroy_handle()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_destroy_handle
.. deprecated:: 3.5
   Use :c:func:`rocblas_destroy_handle`.

rocsolver_set_stream()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_set_stream
.. deprecated:: 3.5
   Use :c:func:`rocblas_set_stream`.

rocsolver_get_stream()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_get_stream
.. deprecated:: 3.5
   Use :c:func:`rocblas_get_stream`.

rocsolver_set_vector()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_set_vector
.. deprecated:: 3.5
   Use :c:func:`rocblas_set_vector`.

rocsolver_get_vector()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_get_vector
.. deprecated:: 3.5
   Use :c:func:`rocblas_get_vector`.

rocsolver_set_matrix()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_set_matrix
.. deprecated:: 3.5
   Use :c:func:`rocblas_set_matrix`.

rocsolver_get_matrix()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. doxygenfunction:: rocsolver_get_matrix
.. deprecated:: 3.5
   Use :c:func:`rocblas_get_matrix`.
