/* Include files */

#include "LQR_ABS_sfun.h"
#include "c3_LQR_ABS.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "LQR_ABS_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[19] = { "alpha", "beta", "K", "A", "B",
  "Q", "R", "u", "nargin", "nargout", "Tb", "lamda", "v", "r", "m", "Fz", "J",
  "mu", "y" };

/* Function Declarations */
static void initialize_c3_LQR_ABS(SFc3_LQR_ABSInstanceStruct *chartInstance);
static void initialize_params_c3_LQR_ABS(SFc3_LQR_ABSInstanceStruct
  *chartInstance);
static void enable_c3_LQR_ABS(SFc3_LQR_ABSInstanceStruct *chartInstance);
static void disable_c3_LQR_ABS(SFc3_LQR_ABSInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_LQR_ABS(SFc3_LQR_ABSInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_LQR_ABS(SFc3_LQR_ABSInstanceStruct
  *chartInstance);
static void set_sim_state_c3_LQR_ABS(SFc3_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c3_st);
static void finalize_c3_LQR_ABS(SFc3_LQR_ABSInstanceStruct *chartInstance);
static void sf_gateway_c3_LQR_ABS(SFc3_LQR_ABSInstanceStruct *chartInstance);
static void mdl_start_c3_LQR_ABS(SFc3_LQR_ABSInstanceStruct *chartInstance);
static void initSimStructsc3_LQR_ABS(SFc3_LQR_ABSInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c3_b_y, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_emlrt_marshallIn(SFc3_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_b_y[4]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_d_emlrt_marshallIn(SFc3_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_b_y[2]);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_e_emlrt_marshallIn(SFc3_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c3_K, const char_T *c3_identifier, real_T c3_b_y[2]);
static void c3_f_emlrt_marshallIn(SFc3_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_b_y[2]);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_g_emlrt_marshallIn(SFc3_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_h_emlrt_marshallIn(SFc3_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_LQR_ABS, const char_T *c3_identifier);
static uint8_T c3_i_emlrt_marshallIn(SFc3_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_LQR_ABSInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc3_LQR_ABSInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_LQR_ABS(SFc3_LQR_ABSInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc3_LQR_ABS(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_is_active_c3_LQR_ABS = 0U;
}

static void initialize_params_c3_LQR_ABS(SFc3_LQR_ABSInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_LQR_ABS(SFc3_LQR_ABSInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_LQR_ABS(SFc3_LQR_ABSInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_LQR_ABS(SFc3_LQR_ABSInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_LQR_ABS(SFc3_LQR_ABSInstanceStruct
  *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_b_y = NULL;
  real_T c3_hoistedGlobal;
  const mxArray *c3_c_y = NULL;
  uint8_T c3_b_hoistedGlobal;
  const mxArray *c3_d_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_createcellmatrix(2, 1), false);
  c3_hoistedGlobal = *chartInstance->c3_y;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_hoistedGlobal, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c3_b_y, 0, c3_c_y);
  c3_b_hoistedGlobal = chartInstance->c3_is_active_c3_LQR_ABS;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_b_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 1, c3_d_y);
  sf_mex_assign(&c3_st, c3_b_y, false);
  return c3_st;
}

static void set_sim_state_c3_LQR_ABS(SFc3_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c3_st)
{
  const mxArray *c3_u;
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  *chartInstance->c3_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 0)), "y");
  chartInstance->c3_is_active_c3_LQR_ABS = c3_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 1)), "is_active_c3_LQR_ABS");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_LQR_ABS(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_LQR_ABS(SFc3_LQR_ABSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c3_LQR_ABS(SFc3_LQR_ABSInstanceStruct *chartInstance)
{
  real_T c3_b_Tb;
  real_T c3_b_lamda;
  real_T c3_b_v;
  real_T c3_b_r;
  real_T c3_b_m;
  real_T c3_b_Fz;
  real_T c3_b_J;
  real_T c3_b_mu;
  uint32_T c3_debug_family_var_map[19];
  real_T c3_alpha;
  real_T c3_beta;
  real_T c3_K[2];
  real_T c3_A[4];
  real_T c3_B[2];
  real_T c3_Q[4];
  real_T c3_R;
  real_T c3_u;
  real_T c3_nargin = 8.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_y;
  real_T c3_b_B;
  real_T c3_a;
  real_T c3_c_B;
  real_T c3_b_A;
  real_T c3_d_B;
  real_T c3_c_A;
  int32_T c3_i0;
  real_T c3_e_B;
  int32_T c3_i1;
  int32_T c3_i2;
  real_T c3_d_A;
  real_T c3_f_B;
  const mxArray *c3_unusedU0 = NULL;
  const mxArray *c3_unusedU1 = NULL;
  const mxArray *c3_b_K = NULL;
  const mxArray *c3_b_unusedU0 = NULL;
  int32_T c3_i3;
  const mxArray *c3_b_unusedU1 = NULL;
  static real_T c3_dv0[4] = { 1.0, 0.0, 0.0, 1.0 };

  int32_T c3_i4;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_e_y = NULL;
  const mxArray *c3_f_y = NULL;
  real_T c3_dv1[2];
  int32_T c3_i5;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_mu, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_J, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Fz, 5U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_m, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_r, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_lamda, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Tb, 0U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_b_Tb = *chartInstance->c3_Tb;
  c3_b_lamda = *chartInstance->c3_lamda;
  c3_b_v = *chartInstance->c3_v;
  c3_b_r = *chartInstance->c3_r;
  c3_b_m = *chartInstance->c3_m;
  c3_b_Fz = *chartInstance->c3_Fz;
  c3_b_J = *chartInstance->c3_J;
  c3_b_mu = *chartInstance->c3_mu;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 19U, 19U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_alpha, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_beta, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_K, 2U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_A, 3U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_B, 4U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_Q, 5U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_R, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_u, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 8U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 9U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_Tb, 10U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_lamda, 11U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_v, 12U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_r, 13U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_m, 14U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_Fz, 15U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_J, 16U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_mu, 17U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_y, 18U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
  c3_b_B = c3_b_m;
  c3_a = c3_b_r;
  c3_c_B = c3_b_J;
  c3_alpha = (1.0 / c3_b_B * (1.0 - c3_b_lamda) + c3_a * c3_a / c3_c_B) *
    c3_b_Fz * c3_b_mu;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_b_A = c3_b_r;
  c3_d_B = c3_b_J;
  c3_beta = c3_b_A / c3_d_B;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c3_b_v, 1.0, -1, 3U,
        c3_b_v <= 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
    for (c3_i0 = 0; c3_i0 < 2; c3_i0++) {
      c3_K[c3_i0] = 1.0;
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
    c3_c_A = c3_alpha;
    c3_e_B = c3_b_v;
    c3_i1 = 0;
    for (c3_i2 = 0; c3_i2 < 2; c3_i2++) {
      c3_A[c3_i1] = (real_T)c3_i2;
      c3_i1 += 2;
    }

    c3_A[1] = 0.0;
    c3_A[3] = c3_c_A / c3_e_B;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
    c3_d_A = c3_beta;
    c3_f_B = c3_b_v;
    c3_B[0] = 0.0;
    c3_B[1] = c3_d_A / c3_f_B;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 11);
    for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
      c3_Q[c3_i3] = c3_dv0[c3_i3];
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 12);
    c3_R = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 13);
    for (c3_i4 = 0; c3_i4 < 2; c3_i4++) {
      c3_K[c3_i4] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 14);
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_A, 0, 0U, 1U, 0U, 2, 2, 2),
                  false);
    c3_d_y = NULL;
    sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_B, 0, 0U, 1U, 0U, 1, 2), false);
    c3_e_y = NULL;
    sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_Q, 0, 0U, 1U, 0U, 2, 2, 2),
                  false);
    c3_f_y = NULL;
    sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_R, 0, 0U, 0U, 0U, 0), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "lqr", 3U, 4U, 14, c3_c_y, 14,
                      c3_d_y, 14, c3_e_y, 14, c3_f_y, &c3_b_K, &c3_b_unusedU0,
                      &c3_b_unusedU1);
    c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_K), "K", c3_dv1);
    for (c3_i5 = 0; c3_i5 < 2; c3_i5++) {
      c3_K[c3_i5] = c3_dv1[c3_i5];
    }

    sf_mex_assign(&c3_unusedU0, sf_mex_dup(c3_b_unusedU0), false);
    sf_mex_assign(&c3_unusedU1, sf_mex_dup(c3_b_unusedU1), false);
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 16);
  c3_u = -c3_K[1] * c3_b_Tb;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 17);
  c3_b_y = c3_u;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -17);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c3_unusedU0);
  sf_mex_destroy(&c3_unusedU1);
  sf_mex_destroy(&c3_b_K);
  sf_mex_destroy(&c3_b_unusedU0);
  sf_mex_destroy(&c3_b_unusedU1);
  *chartInstance->c3_y = c3_b_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_LQR_ABSMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_y, 8U);
}

static void mdl_start_c3_LQR_ABS(SFc3_LQR_ABSInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc3_LQR_ABS(SFc3_LQR_ABSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)(c3_machineNumber);
  (void)(c3_chartNumber);
  (void)(c3_instanceNumber);
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  SFc3_LQR_ABSInstanceStruct *chartInstance;
  chartInstance = (SFc3_LQR_ABSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c3_b_y, const char_T *c3_identifier)
{
  real_T c3_c_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_c_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_y), &c3_thisId);
  sf_mex_destroy(&c3_b_y);
  return c3_c_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_b_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_b_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_b_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_c_y;
  SFc3_LQR_ABSInstanceStruct *chartInstance;
  chartInstance = (SFc3_LQR_ABSInstanceStruct *)chartInstanceVoid;
  c3_b_y = sf_mex_dup(c3_mxArrayInData);
  c3_thisId.fIdentifier = (const char *)c3_varName;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_c_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_y), &c3_thisId);
  sf_mex_destroy(&c3_b_y);
  *(real_T *)c3_outData = c3_c_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_i6;
  int32_T c3_i7;
  const mxArray *c3_b_y = NULL;
  int32_T c3_i8;
  real_T c3_u[4];
  SFc3_LQR_ABSInstanceStruct *chartInstance;
  chartInstance = (SFc3_LQR_ABSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_i6 = 0;
  for (c3_i7 = 0; c3_i7 < 2; c3_i7++) {
    for (c3_i8 = 0; c3_i8 < 2; c3_i8++) {
      c3_u[c3_i8 + c3_i6] = (*(real_T (*)[4])c3_inData)[c3_i8 + c3_i6];
    }

    c3_i6 += 2;
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn(SFc3_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_b_y[4])
{
  real_T c3_dv2[4];
  int32_T c3_i9;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv2, 1, 0, 0U, 1, 0U, 2, 2, 2);
  for (c3_i9 = 0; c3_i9 < 4; c3_i9++) {
    c3_b_y[c3_i9] = c3_dv2[c3_i9];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_Q;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_b_y[4];
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  SFc3_LQR_ABSInstanceStruct *chartInstance;
  chartInstance = (SFc3_LQR_ABSInstanceStruct *)chartInstanceVoid;
  c3_Q = sf_mex_dup(c3_mxArrayInData);
  c3_thisId.fIdentifier = (const char *)c3_varName;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_Q), &c3_thisId, c3_b_y);
  sf_mex_destroy(&c3_Q);
  c3_i10 = 0;
  for (c3_i11 = 0; c3_i11 < 2; c3_i11++) {
    for (c3_i12 = 0; c3_i12 < 2; c3_i12++) {
      (*(real_T (*)[4])c3_outData)[c3_i12 + c3_i10] = c3_b_y[c3_i12 + c3_i10];
    }

    c3_i10 += 2;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_i13;
  const mxArray *c3_b_y = NULL;
  real_T c3_u[2];
  SFc3_LQR_ABSInstanceStruct *chartInstance;
  chartInstance = (SFc3_LQR_ABSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  for (c3_i13 = 0; c3_i13 < 2; c3_i13++) {
    c3_u[c3_i13] = (*(real_T (*)[2])c3_inData)[c3_i13];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static void c3_d_emlrt_marshallIn(SFc3_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_b_y[2])
{
  real_T c3_dv3[2];
  int32_T c3_i14;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv3, 1, 0, 0U, 1, 0U, 1, 2);
  for (c3_i14 = 0; c3_i14 < 2; c3_i14++) {
    c3_b_y[c3_i14] = c3_dv3[c3_i14];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_B;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_b_y[2];
  int32_T c3_i15;
  SFc3_LQR_ABSInstanceStruct *chartInstance;
  chartInstance = (SFc3_LQR_ABSInstanceStruct *)chartInstanceVoid;
  c3_B = sf_mex_dup(c3_mxArrayInData);
  c3_thisId.fIdentifier = (const char *)c3_varName;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_B), &c3_thisId, c3_b_y);
  sf_mex_destroy(&c3_B);
  for (c3_i15 = 0; c3_i15 < 2; c3_i15++) {
    (*(real_T (*)[2])c3_outData)[c3_i15] = c3_b_y[c3_i15];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_i16;
  const mxArray *c3_b_y = NULL;
  real_T c3_u[2];
  SFc3_LQR_ABSInstanceStruct *chartInstance;
  chartInstance = (SFc3_LQR_ABSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  for (c3_i16 = 0; c3_i16 < 2; c3_i16++) {
    c3_u[c3_i16] = (*(real_T (*)[2])c3_inData)[c3_i16];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_K;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_b_y[2];
  int32_T c3_i17;
  SFc3_LQR_ABSInstanceStruct *chartInstance;
  chartInstance = (SFc3_LQR_ABSInstanceStruct *)chartInstanceVoid;
  c3_K = sf_mex_dup(c3_mxArrayInData);
  c3_thisId.fIdentifier = (const char *)c3_varName;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_K), &c3_thisId, c3_b_y);
  sf_mex_destroy(&c3_K);
  for (c3_i17 = 0; c3_i17 < 2; c3_i17++) {
    (*(real_T (*)[2])c3_outData)[c3_i17] = c3_b_y[c3_i17];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_LQR_ABS_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static void c3_e_emlrt_marshallIn(SFc3_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c3_K, const char_T *c3_identifier, real_T c3_b_y[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_K), &c3_thisId, c3_b_y);
  sf_mex_destroy(&c3_K);
}

static void c3_f_emlrt_marshallIn(SFc3_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_b_y[2])
{
  real_T c3_dv4[2];
  int32_T c3_i18;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv4, 1, 0, 0U, 1, 0U, 2, 1, 2);
  for (c3_i18 = 0; c3_i18 < 2; c3_i18++) {
    c3_b_y[c3_i18] = c3_dv4[c3_i18];
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_u;
  const mxArray *c3_b_y = NULL;
  SFc3_LQR_ABSInstanceStruct *chartInstance;
  chartInstance = (SFc3_LQR_ABSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_g_emlrt_marshallIn(SFc3_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_b_y;
  int32_T c3_i19;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i19, 1, 6, 0U, 0, 0U, 0);
  c3_b_y = c3_i19;
  sf_mex_destroy(&c3_u);
  return c3_b_y;
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_b_y;
  SFc3_LQR_ABSInstanceStruct *chartInstance;
  chartInstance = (SFc3_LQR_ABSInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_thisId.fIdentifier = (const char *)c3_varName;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_b_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_h_emlrt_marshallIn(SFc3_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_LQR_ABS, const char_T *c3_identifier)
{
  uint8_T c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_LQR_ABS), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_LQR_ABS);
  return c3_b_y;
}

static uint8_T c3_i_emlrt_marshallIn(SFc3_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_b_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_b_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_b_y;
}

static void init_dsm_address_info(SFc3_LQR_ABSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_LQR_ABSInstanceStruct *chartInstance)
{
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_Tb = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c3_y = (real_T *)ssGetOutputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c3_lamda = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_v = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    2);
  chartInstance->c3_r = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    3);
  chartInstance->c3_m = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    4);
  chartInstance->c3_Fz = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    5);
  chartInstance->c3_J = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    6);
  chartInstance->c3_mu = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    7);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c3_LQR_ABS_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(800563874U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4268576070U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2450605402U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2131562423U);
}

mxArray* sf_c3_LQR_ABS_get_post_codegen_info(void);
mxArray *sf_c3_LQR_ABS_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("qCX6evCPDmZPLDLqJLbLGH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c3_LQR_ABS_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_LQR_ABS_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_LQR_ABS_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c3_LQR_ABS_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_LQR_ABS_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c3_LQR_ABS(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c3_LQR_ABS\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_LQR_ABS_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_LQR_ABSInstanceStruct *chartInstance = (SFc3_LQR_ABSInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _LQR_ABSMachineNumber_,
           3,
           1,
           1,
           0,
           9,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_LQR_ABSMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_LQR_ABSMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _LQR_ABSMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Tb");
          _SFD_SET_DATA_PROPS(1,1,1,0,"lamda");
          _SFD_SET_DATA_PROPS(2,1,1,0,"v");
          _SFD_SET_DATA_PROPS(3,1,1,0,"r");
          _SFD_SET_DATA_PROPS(4,1,1,0,"m");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Fz");
          _SFD_SET_DATA_PROPS(6,1,1,0,"J");
          _SFD_SET_DATA_PROPS(7,1,1,0,"mu");
          _SFD_SET_DATA_PROPS(8,2,0,1,"y");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,307);
        _SFD_CV_INIT_EML_IF(0,1,0,128,137,152,279);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,131,137,-1,3);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _LQR_ABSMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_LQR_ABSInstanceStruct *chartInstance = (SFc3_LQR_ABSInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c3_Tb);
        _SFD_SET_DATA_VALUE_PTR(8U, (void *)chartInstance->c3_y);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c3_lamda);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c3_v);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c3_r);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c3_m);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c3_Fz);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c3_J);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)chartInstance->c3_mu);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sSEJTW9c4LM9SMzPXK9xpFH";
}

static void sf_opaque_initialize_c3_LQR_ABS(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_LQR_ABSInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c3_LQR_ABS((SFc3_LQR_ABSInstanceStruct*) chartInstanceVar);
  initialize_c3_LQR_ABS((SFc3_LQR_ABSInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_LQR_ABS(void *chartInstanceVar)
{
  enable_c3_LQR_ABS((SFc3_LQR_ABSInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_LQR_ABS(void *chartInstanceVar)
{
  disable_c3_LQR_ABS((SFc3_LQR_ABSInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_LQR_ABS(void *chartInstanceVar)
{
  sf_gateway_c3_LQR_ABS((SFc3_LQR_ABSInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_LQR_ABS(SimStruct* S)
{
  return get_sim_state_c3_LQR_ABS((SFc3_LQR_ABSInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_LQR_ABS(SimStruct* S, const mxArray *st)
{
  set_sim_state_c3_LQR_ABS((SFc3_LQR_ABSInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c3_LQR_ABS(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_LQR_ABSInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_LQR_ABS_optimization_info();
    }

    finalize_c3_LQR_ABS((SFc3_LQR_ABSInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_LQR_ABS((SFc3_LQR_ABSInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_LQR_ABS(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_LQR_ABS((SFc3_LQR_ABSInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c3_LQR_ABS(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetInputPortDirectFeedThrough(S, 2, 1);
  ssSetInputPortDirectFeedThrough(S, 3, 1);
  ssSetInputPortDirectFeedThrough(S, 4, 1);
  ssSetInputPortDirectFeedThrough(S, 5, 1);
  ssSetInputPortDirectFeedThrough(S, 6, 1);
  ssSetInputPortDirectFeedThrough(S, 7, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_LQR_ABS_optimization_info(sim_mode_is_rtw_gen(S),
      sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 3);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 8; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1044176115U));
  ssSetChecksum1(S,(865702752U));
  ssSetChecksum2(S,(2466725963U));
  ssSetChecksum3(S,(269874808U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_LQR_ABS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_LQR_ABS(SimStruct *S)
{
  SFc3_LQR_ABSInstanceStruct *chartInstance;
  chartInstance = (SFc3_LQR_ABSInstanceStruct *)utMalloc(sizeof
    (SFc3_LQR_ABSInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_LQR_ABSInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_LQR_ABS;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_LQR_ABS;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_LQR_ABS;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_LQR_ABS;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_LQR_ABS;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_LQR_ABS;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_LQR_ABS;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_LQR_ABS;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_LQR_ABS;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_LQR_ABS;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_LQR_ABS;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c3_LQR_ABS(chartInstance);
}

void c3_LQR_ABS_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_LQR_ABS(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_LQR_ABS(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_LQR_ABS(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_LQR_ABS_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
