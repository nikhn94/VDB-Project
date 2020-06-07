#ifndef __c1_LQR_ABS_h__
#define __c1_LQR_ABS_h__

/* Type Definitions */
#ifndef typedef_SFc1_LQR_ABSInstanceStruct
#define typedef_SFc1_LQR_ABSInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_LQR_ABS;
  void *c1_fEmlrtCtx;
  real_T *c1_Tb;
  real_T *c1_y;
  real_T *c1_lamda;
  real_T *c1_v;
  real_T *c1_r;
  real_T *c1_m;
  real_T *c1_Fz;
  real_T *c1_J;
  real_T *c1_mu;
} SFc1_LQR_ABSInstanceStruct;

#endif                                 /*typedef_SFc1_LQR_ABSInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_LQR_ABS_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_LQR_ABS_get_check_sum(mxArray *plhs[]);
extern void c1_LQR_ABS_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
