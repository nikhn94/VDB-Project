#ifndef __c2_LQR_ABS_h__
#define __c2_LQR_ABS_h__

/* Type Definitions */
#ifndef typedef_SFc2_LQR_ABSInstanceStruct
#define typedef_SFc2_LQR_ABSInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_LQR_ABS;
  void *c2_fEmlrtCtx;
  real_T *c2_Tb;
  real_T *c2_y;
  real_T *c2_lamda;
  real_T *c2_v;
  real_T *c2_r;
  real_T *c2_m;
  real_T *c2_Fz;
  real_T *c2_J;
  real_T *c2_mu;
} SFc2_LQR_ABSInstanceStruct;

#endif                                 /*typedef_SFc2_LQR_ABSInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_LQR_ABS_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_LQR_ABS_get_check_sum(mxArray *plhs[]);
extern void c2_LQR_ABS_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
