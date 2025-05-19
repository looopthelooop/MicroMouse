/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse_types.h
 *
 * Code generated for Simulink model 'Micro_mouse'.
 *
 * Model version                  : 1.62
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Mon May 19 11:43:17 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Micro_mouse_types_h_
#define Micro_mouse_types_h_
#include "rtwtypes.h"
#include "mw_stm32_i2c_ll.h"
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

/* Custom Type definition for MATLABSystem: '<Root>/I2C Controller Write' */
#include "mw_stm32_i2c_ll.h"
#include "mw_stm32_i2c_ll.h"
#include "mw_stm32_i2c_ll.h"
#ifndef struct_tag_pu2p5c8LXP2BpmWuMrlbBG
#define struct_tag_pu2p5c8LXP2BpmWuMrlbBG

struct tag_pu2p5c8LXP2BpmWuMrlbBG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  STM32_I2C_Struct_T * MW_I2C_HANDLE;
  STM32_I2C_Struct_T MW_I2C_BlockStruct;
};

#endif                                 /* struct_tag_pu2p5c8LXP2BpmWuMrlbBG */

#ifndef typedef_stm32cube_blocks_I2CControlle_T
#define typedef_stm32cube_blocks_I2CControlle_T

typedef struct tag_pu2p5c8LXP2BpmWuMrlbBG stm32cube_blocks_I2CControlle_T;

#endif                             /* typedef_stm32cube_blocks_I2CControlle_T */

#ifndef struct_tag_WKZZxaSTc4IMRsLrLiAxdC
#define struct_tag_WKZZxaSTc4IMRsLrLiAxdC

struct tag_WKZZxaSTc4IMRsLrLiAxdC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  STM32_I2C_Struct_T * MW_I2C_HANDLE;
  STM32_I2C_Struct_T MW_I2C_BlockStruct;
};

#endif                                 /* struct_tag_WKZZxaSTc4IMRsLrLiAxdC */

#ifndef typedef_stm32cube_blocks_I2CControl_c_T
#define typedef_stm32cube_blocks_I2CControl_c_T

typedef struct tag_WKZZxaSTc4IMRsLrLiAxdC stm32cube_blocks_I2CControl_c_T;

#endif                             /* typedef_stm32cube_blocks_I2CControl_c_T */

/* Custom Type definition for MATLABSystem: '<S16>/Analog to Digital Converter' */
#include "stm_adc_ll.h"
#include "stm_adc_ll.h"

/* Custom Type definition for MATLABSystem: '<S155>/PWM Output' */
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

/* Forward declaration for rtModel */
typedef struct tag_RTM_Micro_mouse_T RT_MODEL_Micro_mouse_T;

#endif                                 /* Micro_mouse_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
