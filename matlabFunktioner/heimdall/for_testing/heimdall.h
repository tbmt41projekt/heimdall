//
// MATLAB Compiler: 6.6 (R2018a)
// Date: Mon Apr 16 10:03:25 2018
// Arguments:
// "-B""macro_default""-W""cpplib:heimdall,all""-T""link:lib""-d""C:\Users\nilsg
// \Documents\MATLAB\heimdall\for_testing""-v""C:\Users\nilsg\Documents\MATLAB\f
// ilterAndCalcFreq.m""C:\Users\nilsg\Documents\MATLAB\square.m"
//

#ifndef __heimdall_h
#define __heimdall_h 1

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
#ifndef LIB_heimdall_C_API 
#define LIB_heimdall_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_heimdall_C_API 
bool MW_CALL_CONV heimdallInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_heimdall_C_API 
bool MW_CALL_CONV heimdallInitialize(void);

extern LIB_heimdall_C_API 
void MW_CALL_CONV heimdallTerminate(void);

extern LIB_heimdall_C_API 
void MW_CALL_CONV heimdallPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_heimdall_C_API 
bool MW_CALL_CONV mlxFilterAndCalcFreq(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                       *prhs[]);

extern LIB_heimdall_C_API 
bool MW_CALL_CONV mlxSquare(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_heimdall
#define PUBLIC_heimdall_CPP_API __declspec(dllexport)
#else
#define PUBLIC_heimdall_CPP_API __declspec(dllimport)
#endif

#define LIB_heimdall_CPP_API PUBLIC_heimdall_CPP_API

#else

#if !defined(LIB_heimdall_CPP_API)
#if defined(LIB_heimdall_C_API)
#define LIB_heimdall_CPP_API LIB_heimdall_C_API
#else
#define LIB_heimdall_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_heimdall_CPP_API void MW_CALL_CONV filterAndCalcFreq(int nargout, mwArray& freq, const mwArray& signal, const mwArray& passBand, const mwArray& frameRate);

extern LIB_heimdall_CPP_API void MW_CALL_CONV square(int nargout, mwArray& y, const mwArray& x);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
