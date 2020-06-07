/* Include files */

#include "LQR_ABS_sfun.h"
#include "c4_LQR_ABS.h"
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
static const char * c4_debug_family_names[19] = { "alpha", "beta", "K", "A", "B",
  "Q", "R", "u", "nargin", "nargout", "Tb", "lamda", "v", "r", "m", "Fz", "J",
  "mu", "y" };

/* Function Declarations */
static void initialize_c4_LQR_ABS(SFc4_LQR_ABSInstanceStruct *chartInstance);
static void initialize_params_c4_LQR_ABS(SFc4_LQR_ABSInstanceStruct
  *chartInstance);
static void enable_c4_LQR_ABS(SFc4_LQR_ABSInstanceStruct *chartInstance);
static void disable_c4_LQR_ABS(SFc4_LQR_ABSInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_LQR_ABS(SFc4_LQR_ABSInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_LQR_ABS(SFc4_LQR_ABSInstanceStruct
  *chartInstance);
static void set_sim_state_c4_LQR_ABS(SFc4_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c4_st);
static void finalize_c4_LQR_ABS(SFc4_LQR_ABSInstanceStruct *chartInstance);
static void sf_gateway_c4_LQR_ABS(SFc4_LQR_ABSInstanceStruct *chartInstance);
static void mdl_start_c4_LQR_ABS(SFc4_LQR_ABSInstanceStruct *chartInstance);
static void initSimStructsc4_LQR_ABS(SFc4_LQR_ABSInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn(SFc4_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c4_b_y, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_c_emlrt_marshallIn(SFc4_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_b_y[4]);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_d_emlrt_marshallIn(SFc4_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_b_y[2]);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static void c4_e_emlrt_marshallIn(SFc4_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c4_K, const char_T *c4_identifier, real_T c4_b_y[2]);
static void c4_f_emlrt_marshallIn(SFc4_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_b_y[2]);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_g_emlrt_marshallIn(SFc4_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_h_emlrt_marshallIn(SFc4_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_LQR_ABS, const char_T *c4_identifier);
static uint8_T c4_i_emlrt_marshallIn(SFc4_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_LQR_ABSInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc4_LQR_ABSInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_LQR_ABS(SFc4_LQR_ABSInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc4_LQR_ABS(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_is_active_c4_LQR_ABS = 0U;
}

static void initialize_params_c4_LQR_ABS(SFc4_LQR_ABSInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_LQR_ABS(SFc4_LQR_ABSInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_LQR_ABS(SFc4_LQR_ABSInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_LQR_ABS(SFc4_LQR_ABSInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_LQR_ABS(SFc4_LQR_ABSInstanceStruct
  *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_b_y = NULL;
  real_T c4_hoistedGlobal;
  const mxArray *c4_c_y = NULL;
  uint8_T c4_b_hoistedGlobal;
  const mxArray *c4_d_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_createcellmatrix(2, 1), false);
  c4_hoistedGlobal = *chartInstance->c4_y;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_hoistedGlobal, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c4_b_y, 0, c4_c_y);
  c4_b_hoistedGlobal = chartInstance->c4_is_active_c4_LQR_ABS;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_b_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_b_y, 1, c4_d_y);
  sf_mex_assign(&c4_st, c4_b_y, false);
  return c4_st;
}

static void set_sim_state_c4_LQR_ABS(SFc4_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c4_st)
{
  const mxArray *c4_u;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  *chartInstance->c4_y = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 0)), "y");
  chartInstance->c4_is_active_c4_LQR_ABS = c4_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 1)), "is_active_c4_LQR_ABS");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_LQR_ABS(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_LQR_ABS(SFc4_LQR_ABSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c4_LQR_ABS(SFc4_LQR_ABSInstanceStruct *chartInstance)
{
  real_T c4_b_Tb;
  real_T c4_b_lamda;
  real_T c4_b_v;
  real_T c4_b_r;
  real_T c4_b_m;
  real_T c4_b_Fz;
  real_T c4_b_J;
  real_T c4_b_mu;
  uint32_T c4_debug_family_var_map[19];
  real_T c4_alpha;
  real_T c4_beta;
  real_T c4_K[2];
  real_T c4_A[4];
  real_T c4_B[2];
  real_T c4_Q[4];
  real_T c4_R;
  real_T c4_u;
  real_T c4_nargin = 8.0;
  real_T c4_nargout = 1.0;
  real_T c4_b_y;
  real_T c4_b_B;
  real_T c4_a;
  real_T c4_c_B;
  real_T c4_b_A;
  real_T c4_d_B;
  real_T c4_c_A;
  int32_T c4_i0;
  real_T c4_e_B;
  int32_T c4_i1;
  int32_T c4_i2;
  real_T c4_d_A;
  real_T c4_f_B;
  const mxArray *c4_unusedU0 = NULL;
  const mxArray *c4_unusedU1 = NULL;
  const mxArray *c4_b_K = NULL;
  const mxArray *c4_b_unusedU0 = NULL;
  int32_T c4_i3;
  const mxArray *c4_b_unusedU1 = NULL;
  static real_T c4_dv0[4] = { 1.0, 0.0, 0.0, 1.0 };

  int32_T c4_i4;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  real_T c4_dv1[2];
  int32_T c4_i5;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_mu, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_J, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_Fz, 5U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_m, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_r, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_v, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_lamda, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_Tb, 0U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  c4_b_Tb = *chartInstance->c4_Tb;
  c4_b_lamda = *chartInstance->c4_lamda;
  c4_b_v = *chartInstance->c4_v;
  c4_b_r = *chartInstance->c4_r;
  c4_b_m = *chartInstance->c4_m;
  c4_b_Fz = *chartInstance->c4_Fz;
  c4_b_J = *chartInstance->c4_J;
  c4_b_mu = *chartInstance->c4_mu;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 19U, 19U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_alpha, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_beta, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_K, 2U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_A, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_B, 4U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_Q, 5U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_R, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_u, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 8U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 9U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_Tb, 10U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_lamda, 11U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_v, 12U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_r, 13U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_m, 14U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_Fz, 15U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_J, 16U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_mu, 17U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_y, 18U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 3);
  c4_b_B = c4_b_m;
  c4_a = c4_b_r;
  c4_c_B = c4_b_J;
  c4_alpha = (1.0 / c4_b_B * (1.0 - c4_b_lamda) + c4_a * c4_a / c4_c_B) *
    c4_b_Fz * c4_b_mu;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_b_A = c4_b_r;
  c4_d_B = c4_b_J;
  c4_beta = c4_b_A / c4_d_B;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c4_b_v, 1.0, -1, 3U,
        c4_b_v <= 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 7);
    for (c4_i0 = 0; c4_i0 < 2; c4_i0++) {
      c4_K[c4_i0] = 1.0;
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
    c4_c_A = c4_alpha;
    c4_e_B = c4_b_v;
    c4_i1 = 0;
    for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
      c4_A[c4_i1] = (real_T)c4_i2;
      c4_i1 += 2;
    }

    c4_A[1] = 0.0;
    c4_A[3] = c4_c_A / c4_e_B;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
    c4_d_A = c4_beta;
    c4_f_B = c4_b_v;
    c4_B[0] = 0.0;
    c4_B[1] = c4_d_A / c4_f_B;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
    for (c4_i3 = 0; c4_i3 < 4; c4_i3++) {
      c4_Q[c4_i3] = c4_dv0[c4_i3];
    }

    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 12);
    c4_R = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 13);
    for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
      c4_K[c4_i4] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_A, 0, 0U, 1U, 0U, 2, 2, 2),
                  false);
    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_B, 0, 0U, 1U, 0U, 1, 2), false);
    c4_e_y = NULL;
    sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_Q, 0, 0U, 1U, 0U, 2, 2, 2),
                  false);
    c4_f_y = NULL;
    sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_R, 0, 0U, 0U, 0U, 0), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "lqr", 3U, 4U, 14, c4_c_y, 14,
                      c4_d_y, 14, c4_e_y, 14, c4_f_y, &c4_b_K, &c4_b_unusedU0,
                      &c4_b_unusedU1);
    c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_K), "K", c4_dv1);
    for (c4_i5 = 0; c4_i5 < 2; c4_i5++) {
      c4_K[c4_i5] = c4_dv1[c4_i5];
    }

    sf_mex_assign(&c4_unusedU0, sf_mex_dup(c4_b_unusedU0), false);
    sf_mex_assign(&c4_unusedU1, sf_mex_dup(c4_b_unusedU1), false);
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 16);
  c4_u = -c4_K[1] * c4_b_Tb;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 17);
  c4_b_y = c4_u;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -17);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c4_unusedU0);
  sf_mex_destroy(&c4_unusedU1);
  sf_mex_destroy(&c4_b_K);
  sf_mex_destroy(&c4_b_unusedU0);
  sf_mex_destroy(&c4_b_unusedU1);
  *chartInstance->c4_y = c4_b_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_LQR_ABSMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_y, 8U);
}

static void mdl_start_c4_LQR_ABS(SFc4_LQR_ABSInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc4_LQR_ABS(SFc4_LQR_ABSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)(c4_machineNumber);
  (void)(c4_chartNumber);
  (void)(c4_instanceNumber);
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  SFc4_LQR_ABSInstanceStruct *chartInstance;
  chartInstance = (SFc4_LQR_ABSInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_b_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn(SFc4_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c4_b_y, const char_T *c4_identifier)
{
  real_T c4_c_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_c_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_y), &c4_thisId);
  sf_mex_destroy(&c4_b_y);
  return c4_c_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_b_y;
  real_T c4_d0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_b_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_b_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_y;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_c_y;
  SFc4_LQR_ABSInstanceStruct *chartInstance;
  chartInstance = (SFc4_LQR_ABSInstanceStruct *)chartInstanceVoid;
  c4_b_y = sf_mex_dup(c4_mxArrayInData);
  c4_thisId.fIdentifier = (const char *)c4_varName;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_c_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_y), &c4_thisId);
  sf_mex_destroy(&c4_b_y);
  *(real_T *)c4_outData = c4_c_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_i6;
  int32_T c4_i7;
  const mxArray *c4_b_y = NULL;
  int32_T c4_i8;
  real_T c4_u[4];
  SFc4_LQR_ABSInstanceStruct *chartInstance;
  chartInstance = (SFc4_LQR_ABSInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_i6 = 0;
  for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
    for (c4_i8 = 0; c4_i8 < 2; c4_i8++) {
      c4_u[c4_i8 + c4_i6] = (*(real_T (*)[4])c4_inData)[c4_i8 + c4_i6];
    }

    c4_i6 += 2;
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_b_y, false);
  return c4_mxArrayOutData;
}

static void c4_c_emlrt_marshallIn(SFc4_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_b_y[4])
{
  real_T c4_dv2[4];
  int32_T c4_i9;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv2, 1, 0, 0U, 1, 0U, 2, 2, 2);
  for (c4_i9 = 0; c4_i9 < 4; c4_i9++) {
    c4_b_y[c4_i9] = c4_dv2[c4_i9];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_Q;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_b_y[4];
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  SFc4_LQR_ABSInstanceStruct *chartInstance;
  chartInstance = (SFc4_LQR_ABSInstanceStruct *)chartInstanceVoid;
  c4_Q = sf_mex_dup(c4_mxArrayInData);
  c4_thisId.fIdentifier = (const char *)c4_varName;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_Q), &c4_thisId, c4_b_y);
  sf_mex_destroy(&c4_Q);
  c4_i10 = 0;
  for (c4_i11 = 0; c4_i11 < 2; c4_i11++) {
    for (c4_i12 = 0; c4_i12 < 2; c4_i12++) {
      (*(real_T (*)[4])c4_outData)[c4_i12 + c4_i10] = c4_b_y[c4_i12 + c4_i10];
    }

    c4_i10 += 2;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_i13;
  const mxArray *c4_b_y = NULL;
  real_T c4_u[2];
  SFc4_LQR_ABSInstanceStruct *chartInstance;
  chartInstance = (SFc4_LQR_ABSInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  for (c4_i13 = 0; c4_i13 < 2; c4_i13++) {
    c4_u[c4_i13] = (*(real_T (*)[2])c4_inData)[c4_i13];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_b_y, false);
  return c4_mxArrayOutData;
}

static void c4_d_emlrt_marshallIn(SFc4_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_b_y[2])
{
  real_T c4_dv3[2];
  int32_T c4_i14;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv3, 1, 0, 0U, 1, 0U, 1, 2);
  for (c4_i14 = 0; c4_i14 < 2; c4_i14++) {
    c4_b_y[c4_i14] = c4_dv3[c4_i14];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_B;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_b_y[2];
  int32_T c4_i15;
  SFc4_LQR_ABSInstanceStruct *chartInstance;
  chartInstance = (SFc4_LQR_ABSInstanceStruct *)chartInstanceVoid;
  c4_B = sf_mex_dup(c4_mxArrayInData);
  c4_thisId.fIdentifier = (const char *)c4_varName;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_B), &c4_thisId, c4_b_y);
  sf_mex_destroy(&c4_B);
  for (c4_i15 = 0; c4_i15 < 2; c4_i15++) {
    (*(real_T (*)[2])c4_outData)[c4_i15] = c4_b_y[c4_i15];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_i16;
  const mxArray *c4_b_y = NULL;
  real_T c4_u[2];
  SFc4_LQR_ABSInstanceStruct *chartInstance;
  chartInstance = (SFc4_LQR_ABSInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  for (c4_i16 = 0; c4_i16 < 2; c4_i16++) {
    c4_u[c4_i16] = (*(real_T (*)[2])c4_inData)[c4_i16];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_b_y, false);
  return c4_mxArrayOutData;
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_K;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_b_y[2];
  int32_T c4_i17;
  SFc4_LQR_ABSInstanceStruct *chartInstance;
  chartInstance = (SFc4_LQR_ABSInstanceStruct *)chartInstanceVoid;
  c4_K = sf_mex_dup(c4_mxArrayInData);
  c4_thisId.fIdentifier = (const char *)c4_varName;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_K), &c4_thisId, c4_b_y);
  sf_mex_destroy(&c4_K);
  for (c4_i17 = 0; c4_i17 < 2; c4_i17++) {
    (*(real_T (*)[2])c4_outData)[c4_i17] = c4_b_y[c4_i17];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_LQR_ABS_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static void c4_e_emlrt_marshallIn(SFc4_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c4_K, const char_T *c4_identifier, real_T c4_b_y[2])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_K), &c4_thisId, c4_b_y);
  sf_mex_destroy(&c4_K);
}

static void c4_f_emlrt_marshallIn(SFc4_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_b_y[2])
{
  real_T c4_dv4[2];
  int32_T c4_i18;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv4, 1, 0, 0U, 1, 0U, 2, 1, 2);
  for (c4_i18 = 0; c4_i18 < 2; c4_i18++) {
    c4_b_y[c4_i18] = c4_dv4[c4_i18];
  }

  sf_mex_destroy(&c4_u);
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_u;
  const mxArray *c4_b_y = NULL;
  SFc4_LQR_ABSInstanceStruct *chartInstance;
  chartInstance = (SFc4_LQR_ABSInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_b_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_g_emlrt_marshallIn(SFc4_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_b_y;
  int32_T c4_i19;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i19, 1, 6, 0U, 0, 0U, 0);
  c4_b_y = c4_i19;
  sf_mex_destroy(&c4_u);
  return c4_b_y;
}

static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_b_y;
  SFc4_LQR_ABSInstanceStruct *chartInstance;
  chartInstance = (SFc4_LQR_ABSInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_thisId.fIdentifier = (const char *)c4_varName;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_y = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_b_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_h_emlrt_marshallIn(SFc4_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_LQR_ABS, const char_T *c4_identifier)
{
  uint8_T c4_b_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_y = c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_LQR_ABS), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_LQR_ABS);
  return c4_b_y;
}

static uint8_T c4_i_emlrt_marshallIn(SFc4_LQR_ABSInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_b_y;
  uint8_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_b_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_b_y;
}

static void init_dsm_address_info(SFc4_LQR_ABSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_LQR_ABSInstanceStruct *chartInstance)
{
  chartInstance->c4_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c4_Tb = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c4_y = (real_T *)ssGetOutputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c4_lamda = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_v = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    2);
  chartInstance->c4_r = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    3);
  chartInstance->c4_m = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    4);
  chartInstance->c4_Fz = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    5);
  chartInstance->c4_J = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    6);
  chartInstance->c4_mu = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
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

void sf_c4_LQR_ABS_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(800563874U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4268576070U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2450605402U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2131562423U);
}

mxArray* sf_c4_LQR_ABS_get_post_codegen_info(void);
mxArray *sf_c4_LQR_ABS_get_autoinheritance_info(void)
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
    mxArray* mxPostCodegenInfo = sf_c4_LQR_ABS_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_LQR_ABS_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_LQR_ABS_jit_fallback_info(void)
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

mxArray *sf_c4_LQR_ABS_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c4_LQR_ABS_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c4_LQR_ABS(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c4_LQR_ABS\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_LQR_ABS_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_LQR_ABSInstanceStruct *chartInstance = (SFc4_LQR_ABSInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _LQR_ABSMachineNumber_,
           4,
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
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
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
    SFc4_LQR_ABSInstanceStruct *chartInstance = (SFc4_LQR_ABSInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c4_Tb);
        _SFD_SET_DATA_VALUE_PTR(8U, (void *)chartInstance->c4_y);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c4_lamda);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c4_v);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c4_r);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c4_m);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c4_Fz);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c4_J);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)chartInstance->c4_mu);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sSEJTW9c4LM9SMzPXK9xpFH";
}

static void sf_opaque_initialize_c4_LQR_ABS(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_LQR_ABSInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c4_LQR_ABS((SFc4_LQR_ABSInstanceStruct*) chartInstanceVar);
  initialize_c4_LQR_ABS((SFc4_LQR_ABSInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_LQR_ABS(void *chartInstanceVar)
{
  enable_c4_LQR_ABS((SFc4_LQR_ABSInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_LQR_ABS(void *chartInstanceVar)
{
  disable_c4_LQR_ABS((SFc4_LQR_ABSInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_LQR_ABS(void *chartInstanceVar)
{
  sf_gateway_c4_LQR_ABS((SFc4_LQR_ABSInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_LQR_ABS(SimStruct* S)
{
  return get_sim_state_c4_LQR_ABS((SFc4_LQR_ABSInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_LQR_ABS(SimStruct* S, const mxArray *st)
{
  set_sim_state_c4_LQR_ABS((SFc4_LQR_ABSInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c4_LQR_ABS(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_LQR_ABSInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_LQR_ABS_optimization_info();
    }

    finalize_c4_LQR_ABS((SFc4_LQR_ABSInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_LQR_ABS((SFc4_LQR_ABSInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_LQR_ABS(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_LQR_ABS((SFc4_LQR_ABSInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c4_LQR_ABS(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 4);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,4);
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
        infoStruct,4,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
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

static void mdlRTW_c4_LQR_ABS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_LQR_ABS(SimStruct *S)
{
  SFc4_LQR_ABSInstanceStruct *chartInstance;
  chartInstance = (SFc4_LQR_ABSInstanceStruct *)utMalloc(sizeof
    (SFc4_LQR_ABSInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_LQR_ABSInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_LQR_ABS;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_LQR_ABS;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_LQR_ABS;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_LQR_ABS;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_LQR_ABS;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_LQR_ABS;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_LQR_ABS;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_LQR_ABS;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_LQR_ABS;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_LQR_ABS;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_LQR_ABS;
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
  mdl_start_c4_LQR_ABS(chartInstance);
}

void c4_LQR_ABS_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_LQR_ABS(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_LQR_ABS(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_LQR_ABS(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_LQR_ABS_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
