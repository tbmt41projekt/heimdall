//
// MATLAB Compiler: 6.6 (R2018a)
// Date: Wed Apr 11 09:02:16 2018
// Arguments:
// "-B""macro_default""-W""cpplib:matlabLibrary,all""-T""link:lib""-d""C:\Users\
// nilsg\Documents\MATLAB\Compiled
// Libraries\matlabLibrary\for_testing""-v""C:\Users\nilsg\Documents\MATLAB\squa
// re.m"
//

#ifndef __matlabLibrary_h
#define __matlabLibrary_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" {
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_matlabLibrary_C_API 
#define LIB_matlabLibrary_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_matlabLibrary_C_API 
bool MW_CALL_CONV matlabLibraryInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_matlabLibrary_C_API 
bool MW_CALL_CONV matlabLibraryInitialize(void);

extern LIB_matlabLibrary_C_API 
void MW_CALL_CONV matlabLibraryTerminate(void);

extern LIB_matlabLibrary_C_API 
void MW_CALL_CONV matlabLibraryPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_matlabLibrary_C_API 
bool MW_CALL_CONV mlxSquare(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_matlabLibrary
#define PUBLIC_matlabLibrary_CPP_API __declspec(dllexport)
#else
#define PUBLIC_matlabLibrary_CPP_API __declspec(dllimport)
#endif

#define LIB_matlabLibrary_CPP_API PUBLIC_matlabLibrary_CPP_API

#else

#if !defined(LIB_matlabLibrary_CPP_API)
#if defined(LIB_matlabLibrary_C_API)
#define LIB_matlabLibrary_CPP_API LIB_matlabLibrary_C_API
#else
#define LIB_matlabLibrary_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_matlabLibrary_CPP_API void MW_CALL_CONV square(int nargout, mwArray& y, const mwArray& x);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
