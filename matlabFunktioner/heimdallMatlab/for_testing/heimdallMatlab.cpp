//
// MATLAB Compiler: 6.6 (R2018a)
// Date: Wed Apr 18 14:23:43 2018
// Arguments:
// "-B""macro_default""-W""cpplib:heimdallMatlab,all""-T""link:lib""-d""C:\Users
// \nilge293\heimdall\matlabFunktioner\heimdallMatlab\for_testing""-v""C:\Users\
// nilge293\Documents\filterAndCalcFreq.m""C:\Users\nilge293\heimdall\matlabFunk
// tioner\peakFinder.m""C:\Users\nilge293\Documents\square.m"
//

#include <stdio.h>
#define EXPORTING_heimdallMatlab 1
#include "heimdallMatlab.h"

static HMCRINSTANCE _mcr_inst = NULL;

#if defined( _MSC_VER) || defined(__LCC__) || defined(__MINGW64__)
#ifdef __LCC__
#undef EXTERN_C
#endif
#include <windows.h>

static char path_to_dll[_MAX_PATH];

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, void *pv)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        if (GetModuleFileName(hInstance, path_to_dll, _MAX_PATH) == 0)
            return FALSE;
    }
    else if (dwReason == DLL_PROCESS_DETACH)
    {
    }
    return TRUE;
}
#endif
#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultPrintHandler(const char *s)
{
    return mclWrite(1 /* stdout */, s, sizeof(char)*strlen(s));
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultErrorHandler(const char *s)
{
    int written = 0;
    size_t len = 0;
    len = strlen(s);
    written = mclWrite(2 /* stderr */, s, sizeof(char)*len);
    if (len > 0 && s[ len-1 ] != '\n')
        written += mclWrite(2 /* stderr */, "\n", sizeof(char));
    return written;
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_heimdallMatlab_C_API
#define LIB_heimdallMatlab_C_API /* No special import/export declaration */
#endif

LIB_heimdallMatlab_C_API 
bool MW_CALL_CONV heimdallMatlabInitializeWithHandlers(
    mclOutputHandlerFcn error_handler,
    mclOutputHandlerFcn print_handler)
{
    int bResult = 0;
    if (_mcr_inst != NULL)
        return true;
    if (!mclmcrInitialize())
        return false;
    if (!GetModuleFileName(GetModuleHandle("heimdallMatlab"), path_to_dll, _MAX_PATH))
        return false;
    {
        mclCtfStream ctfStream = 
            mclGetEmbeddedCtfStream(path_to_dll);
        if (ctfStream) {
            bResult = mclInitializeComponentInstanceEmbedded(&_mcr_inst,
                                                             error_handler, 
                                                             print_handler,
                                                             ctfStream);
            mclDestroyStream(ctfStream);
        } else {
            bResult = 0;
        }
    }  
    if (!bResult)
    return false;
    return true;
}

LIB_heimdallMatlab_C_API 
bool MW_CALL_CONV heimdallMatlabInitialize(void)
{
    return heimdallMatlabInitializeWithHandlers(mclDefaultErrorHandler, 
                                              mclDefaultPrintHandler);
}

LIB_heimdallMatlab_C_API 
void MW_CALL_CONV heimdallMatlabTerminate(void)
{
    if (_mcr_inst != NULL)
        mclTerminateInstance(&_mcr_inst);
}

LIB_heimdallMatlab_C_API 
void MW_CALL_CONV heimdallMatlabPrintStackTrace(void) 
{
    char** stackTrace;
    int stackDepth = mclGetStackTrace(&stackTrace);
    int i;
    for(i=0; i<stackDepth; i++)
    {
        mclWrite(2 /* stderr */, stackTrace[i], sizeof(char)*strlen(stackTrace[i]));
        mclWrite(2 /* stderr */, "\n", sizeof(char)*strlen("\n"));
    }
    mclFreeStackTrace(&stackTrace, stackDepth);
}


LIB_heimdallMatlab_C_API 
bool MW_CALL_CONV mlxFilterAndCalcFreq(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                       *prhs[])
{
    return mclFeval(_mcr_inst, "filterAndCalcFreq", nlhs, plhs, nrhs, prhs);
}

LIB_heimdallMatlab_C_API 
bool MW_CALL_CONV mlxPeakFinder(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "peakFinder", nlhs, plhs, nrhs, prhs);
}

LIB_heimdallMatlab_C_API 
bool MW_CALL_CONV mlxSquare(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "square", nlhs, plhs, nrhs, prhs);
}

LIB_heimdallMatlab_CPP_API 
void MW_CALL_CONV filterAndCalcFreq(int nargout, mwArray& freq, const mwArray& signal, 
                                    const mwArray& passBand, const mwArray& frameRate)
{
    mclcppMlfFeval(_mcr_inst, "filterAndCalcFreq", nargout, 1, 3, &freq, &signal, &passBand, &frameRate);
}

LIB_heimdallMatlab_CPP_API 
void MW_CALL_CONV peakFinder(int nargout, mwArray& output, const mwArray& signal, const 
                             mwArray& passBand, const mwArray& frameRate, const mwArray& 
                             peakLimit, const mwArray& ampLim)
{
    mclcppMlfFeval(_mcr_inst, "peakFinder", nargout, 1, 5, &output, &signal, &passBand, &frameRate, &peakLimit, &ampLim);
}

LIB_heimdallMatlab_CPP_API 
void MW_CALL_CONV square(int nargout, mwArray& y, const mwArray& x)
{
    mclcppMlfFeval(_mcr_inst, "square", nargout, 1, 1, &y, &x);
}

