/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_PPB_ann_api.h
 *
 * Code generation for function '_coder_PPB_ann_api'
 *
 */

#ifndef ___CODER_PPB_ANN_API_H__
#define ___CODER_PPB_ANN_API_H__

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_PPB_ann_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern real_T PPB_ann(real_T x1[16]);
extern void PPB_ann_api(const mxArray *prhs[1], const mxArray *plhs[1]);
extern void PPB_ann_atexit(void);
extern void PPB_ann_initialize(void);
extern void PPB_ann_terminate(void);
extern void PPB_ann_xil_terminate(void);

#endif

/* End of code generation (_coder_PPB_ann_api.h) */
