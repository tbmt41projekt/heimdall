//
// MATLAB Compiler: 6.6 (R2018a)
// Date: Wed Apr 11 10:05:47 2018
// Arguments:
// "-B""macro_default""-W""cpplib:matlabLibrary,all""-T""link:lib""-d""C:\heimda
// ll\matlabFunktioner\matlabLibrary\for_testing""-v""C:\Users\nilsg\Documents\M
// ATLAB\divideBy2.m""C:\Users\nilsg\Documents\MATLAB\square.m"
//

#include <stdio.h>
#define EXPORTING_matlabLibrary 1
#include "matlabLibrary.h"

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
#ifndef LIB_matlabLibrary_C_API
#define LIB_matlabLibrary_C_API /* No special import/export declaration */
#endif

LIB_matlabLibrary_C_API 
bool MW_CALL_CONV matlabLibraryInitializeWithHandlers(
    mclOutputHandlerFcn error_handler,
    mclOutputHandlerFcn print_handler)
{
    int bResult = 0;
    if (_mcr_inst != NULL)
        return true;
    if (!mclmcrInitialize())
        return false;
    if (!GetModuleFileName(GetModuleHandle("matlabLibrary"), path_to_dll, _MAX_PATH))
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

LIB_matlabLibrary_C_API 
bool MW_CALL_CONV matlabLibraryInitialize(void)
{
    return matlabLibraryInitializeWithHandlers(mclDefaultErrorHandler, 
                                             mclDefaultPrintHandler);
}

LIB_matlabLibrary_C_API 
void MW_CALL_CONV matlabLibraryTerminate(void)
{
    if (_mcr_inst != NULL)
        mclTerminateInstance(&_mcr_inst);
}

LIB_matlabLibrary_C_API 
void MW_CALL_CONV matlabLibraryPrintStackTrace(void) 
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


LIB_matlabLibrary_C_API 
bool MW_CALL_CONV mlxDivideBy2(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "divideBy2", nlhs, plhs, nrhs, prhs);
}

LIB_matlabLibrary_C_API 
bool MW_CALL_CONV mlxSquare(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "square", nlhs, plhs, nrhs, prhs);
}

LIB_matlabLibrary_CPP_API 
void MW_CALL_CONV divideBy2(int nargout, mwArray& y, const mwArray& x)
{
    mclcppMlfFeval(_mcr_inst, "divideBy2", nargout, 1, 1, &y, &x);
}

LIB_matlabLibrary_CPP_API 
void MW_CALL_CONV square(int nargout, mwArray& y, const mwArray& x)
{
    mclcppMlfFeval(_mcr_inst, "square", nargout, 1, 1, &y, &x);
}

