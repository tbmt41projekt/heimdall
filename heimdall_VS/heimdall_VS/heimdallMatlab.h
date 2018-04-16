//
// MATLAB Compiler: 6.6 (R2018a)
// Date: Mon Apr 16 13:44:02 2018
// Arguments:
// "-B""macro_default""-W""cpplib:heimdallMatlab,all""-T""link:lib""-d""C:\Users
// \nilge293\Documents\heimdallMatlab\heimdallMatlab\for_testing""-v""C:\Users\n
// ilge293\Documents\filterAndCalcFreq.m""C:\Users\nilge293\Documents\square.m"
//

#ifndef __heimdallMatlab_h
#define __heimdallMatlab_h 1

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
#ifndef LIB_heimdallMatlab_C_API 
#define LIB_heimdallMatlab_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_heimdallMatlab_C_API 
bool MW_CALL_CONV heimdallMatlabInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_heimdallMatlab_C_API 
bool MW_CALL_CONV heimdallMatlabInitialize(void);

extern LIB_heimdallMatlab_C_API 
void MW_CALL_CONV heimdallMatlabTerminate(void);

extern LIB_heimdallMatlab_C_API 
void MW_CALL_CONV heimdallMatlabPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_heimdallMatlab_C_API 
bool MW_CALL_CONV mlxFilterAndCalcFreq(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                       *prhs[]);

extern LIB_heimdallMatlab_C_API 
bool MW_CALL_CONV mlxSquare(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_heimdallMatlab
#define PUBLIC_heimdallMatlab_CPP_API __declspec(dllexport)
#else
#define PUBLIC_heimdallMatlab_CPP_API __declspec(dllimport)
#endif

#define LIB_heimdallMatlab_CPP_API PUBLIC_heimdallMatlab_CPP_API

#else

#if !defined(LIB_heimdallMatlab_CPP_API)
#if defined(LIB_heimdallMatlab_C_API)
#define LIB_heimdallMatlab_CPP_API LIB_heimdallMatlab_C_API
#else
#define LIB_heimdallMatlab_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_heimdallMatlab_CPP_API void MW_CALL_CONV filterAndCalcFreq(int nargout, mwArray& freq, const mwArray& signal, const mwArray& passBand, const mwArray& frameRate);

extern LIB_heimdallMatlab_CPP_API void MW_CALL_CONV square(int nargout, mwArray& y, const mwArray& x);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
