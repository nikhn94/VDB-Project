#ifndef __c4_LQR_ABS_h__
#define __c4_LQR_ABS_h__

/* Type Definitions */
#ifndef typedef_SFc4_LQR_ABSInstanceStruct
#define typedef_SFc4_LQR_ABSInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_LQR_ABS;
  void *c4_fEmlrtCtx;
  real_T *c4_Tb;
  real_T *c4_y;
  real_T *c4_lamda;
  real_T *c4_v;
  real_T *c4_r;
  real_T *c4_m;
  real_T *c4_Fz;
  real_T *c4_J;
  real_T *c4_mu;
} SFc4_LQR_ABSInstanceStruct;

#endif                                 /*typedef_SFc4_LQR_ABSInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_LQR_ABS_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_LQR_ABS_get_check_sum(mxArray *plhs[]);
extern void c4_LQR_ABS_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
