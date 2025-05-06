/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse_types.h
 *
 * Code generated for Simulink model 'Micro_mouse'.
 *
 * Model version                  : 1.47
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue May  6 15:09:43 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Micro_mouse_types_h_
#define Micro_mouse_types_h_
#include "rtwtypes.h"
#include "stm_timer_ll.h"
#include "stm_adc_ll.h"
#ifndef struct_tag_GSKovyH6bCN42HwFzVB4DE
#define struct_tag_GSKovyH6bCN42HwFzVB4DE

struct tag_GSKovyH6bCN42HwFzVB4DE
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_GSKovyH6bCN42HwFzVB4DE */

#ifndef typedef_stm32cube_blocks_DigitalPortR_T
#define typedef_stm32cube_blocks_DigitalPortR_T

typedef struct tag_GSKovyH6bCN42HwFzVB4DE stm32cube_blocks_DigitalPortR_T;

#endif                             /* typedef_stm32cube_blocks_DigitalPortR_T */

/* Custom Type definition for MATLABSystem: '<S120>/Analog to Digital Converter' */
#include "stm_adc_ll.h"
#include "stm_adc_ll.h"
#ifndef struct_tag_tsKyPuhWUdS8zBSeRGR2aC
#define struct_tag_tsKyPuhWUdS8zBSeRGR2aC

struct tag_tsKyPuhWUdS8zBSeRGR2aC
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_tsKyPuhWUdS8zBSeRGR2aC */

#ifndef typedef_stm32cube_blocks_DigitalPortW_T
#define typedef_stm32cube_blocks_DigitalPortW_T

typedef struct tag_tsKyPuhWUdS8zBSeRGR2aC stm32cube_blocks_DigitalPortW_T;

#endif                             /* typedef_stm32cube_blocks_DigitalPortW_T */

/* Custom Type definition for MATLABSystem: '<S147>/PWM Output' */
#include "stm_timer_ll.h"
#include "stm_timer_ll.h"
#ifndef struct_tag_0RzKA0TA5eXyA1b3sjyvMG
#define struct_tag_0RzKA0TA5eXyA1b3sjyvMG

struct tag_0RzKA0TA5eXyA1b3sjyvMG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  TIM_Type_T* TimerHandle;
};

#endif                                 /* struct_tag_0RzKA0TA5eXyA1b3sjyvMG */

#ifndef typedef_stm32cube_blocks_PWMOutput_Mi_T
#define typedef_stm32cube_blocks_PWMOutput_Mi_T

typedef struct tag_0RzKA0TA5eXyA1b3sjyvMG stm32cube_blocks_PWMOutput_Mi_T;

#endif                             /* typedef_stm32cube_blocks_PWMOutput_Mi_T */

#ifndef struct_tag_3OAw49hDQooKvXqEqjPgYE
#define struct_tag_3OAw49hDQooKvXqEqjPgYE

struct tag_3OAw49hDQooKvXqEqjPgYE
{
  int32_T S0_isInitialized;
  real_T W0_states[38];
  real_T W1_simContextBuf[76];
  real_T W2_simRevCoeff[39];
  int32_T W3_halideSimTBBGrainSize;
  real_T P0_InitialStates;
  real_T P1_Coefficients[39];
};

#endif                                 /* struct_tag_3OAw49hDQooKvXqEqjPgYE */

#ifndef typedef_b_dsp_FIRFilter_0_Micro_mouse_T
#define typedef_b_dsp_FIRFilter_0_Micro_mouse_T

typedef struct tag_3OAw49hDQooKvXqEqjPgYE b_dsp_FIRFilter_0_Micro_mouse_T;

#endif                             /* typedef_b_dsp_FIRFilter_0_Micro_mouse_T */

#ifndef struct_tag_pwPXbUUDo2fDZ0SiTl22oC
#define struct_tag_pwPXbUUDo2fDZ0SiTl22oC

struct tag_pwPXbUUDo2fDZ0SiTl22oC
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRFilter_0_Micro_mouse_T cSFunObject;
};

#endif                                 /* struct_tag_pwPXbUUDo2fDZ0SiTl22oC */

#ifndef typedef_b_dspcodegen_FIRFilter_Micro__T
#define typedef_b_dspcodegen_FIRFilter_Micro__T

typedef struct tag_pwPXbUUDo2fDZ0SiTl22oC b_dspcodegen_FIRFilter_Micro__T;

#endif                             /* typedef_b_dspcodegen_FIRFilter_Micro__T */

#ifndef struct_tag_tBisVK7smkqUfksMe4Md0
#define struct_tag_tBisVK7smkqUfksMe4Md0

struct tag_tBisVK7smkqUfksMe4Md0
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  ADC_Type_T* ADCHandle;
  uint16_T ADCInternalBuffer[10];
};

#endif                                 /* struct_tag_tBisVK7smkqUfksMe4Md0 */

#ifndef typedef_stm32cube_blocks_AnalogInput__T
#define typedef_stm32cube_blocks_AnalogInput__T

typedef struct tag_tBisVK7smkqUfksMe4Md0 stm32cube_blocks_AnalogInput__T;

#endif                             /* typedef_stm32cube_blocks_AnalogInput__T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_Micro_mouse_T
#define typedef_cell_wrap_Micro_mouse_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_Micro_mouse_T;

#endif                                 /* typedef_cell_wrap_Micro_mouse_T */

#ifndef struct_tag_KnCFN7D4v4EaxfgZPBAfxB
#define struct_tag_KnCFN7D4v4EaxfgZPBAfxB

struct tag_KnCFN7D4v4EaxfgZPBAfxB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_Micro_mouse_T inputVarSize;
  int32_T NumChannels;
  b_dspcodegen_FIRFilter_Micro__T *FilterObj;
  b_dspcodegen_FIRFilter_Micro__T _pobj0;
};

#endif                                 /* struct_tag_KnCFN7D4v4EaxfgZPBAfxB */

#ifndef typedef_dsp_simulink_LowpassFilter_Mi_T
#define typedef_dsp_simulink_LowpassFilter_Mi_T

typedef struct tag_KnCFN7D4v4EaxfgZPBAfxB dsp_simulink_LowpassFilter_Mi_T;

#endif                             /* typedef_dsp_simulink_LowpassFilter_Mi_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_Micro_mouse_T RT_MODEL_Micro_mouse_T;

#endif                                 /* Micro_mouse_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
