#ifndef __c3_LQR_ABS_h__
#define __c3_LQR_ABS_h__

/* Type Definitions */
#ifndef typedef_SFc3_LQR_ABSInstanceStruct
#define typedef_SFc3_LQR_ABSInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_LQR_ABS;
  void *c3_fEmlrtCtx;
  real_T *c3_Tb;
  real_T *c3_y;
  real_T *c3_lamda;
  real_T *c3_v;
  real_T *c3_r;
  real_T *c3_m;
  real_T *c3_Fz;
  real_T *c3_J;
  real_T *c3_mu;
} SFc3_LQR_ABSInstanceStruct;

#endif                                 /*typedef_SFc3_LQR_ABSInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_LQR_ABS_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_LQR_ABS_get_check_sum(mxArray *plhs[]);
extern void c3_LQR_ABS_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
