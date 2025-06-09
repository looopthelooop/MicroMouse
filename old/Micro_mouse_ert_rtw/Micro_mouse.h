/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse.h
 *
 * Code generated for Simulink model 'Micro_mouse'.
 *
 * Model version                  : 1.77
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sun Jun  8 09:42:44 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Micro_mouse_h_
#define Micro_mouse_h_
#ifndef Micro_mouse_COMMON_INCLUDES_
#define Micro_mouse_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#include "main.h"
#endif                                 /* Micro_mouse_COMMON_INCLUDES_ */

#include "Micro_mouse_types.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S16>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_Mi_T obj_l;/* '<S20>/PWM Output' */
  stm32cube_blocks_PWMOutput_Mi_T obj_i;/* '<S18>/PWM Output' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_Micro_mouse_T;

/* Real-time Model Data Structure */
struct tag_RTM_Micro_mouse_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_Micro_mouse_T Micro_mouse_DW;

/* Model entry point functions */
extern void Micro_mouse_initialize(void);
extern void Micro_mouse_step(void);
extern void Micro_mouse_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Micro_mouse_T *const Micro_mouse_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Conversion' : Unused code path elimination
 * Block '<S1>/Data Type Conversion1' : Unused code path elimination
 * Block '<S1>/Sum2' : Unused code path elimination
 * Block '<S5>/Gain2' : Unused code path elimination
 * Block '<S5>/Signal Conversion' : Unused code path elimination
 * Block '<S5>/Signal Conversion1' : Unused code path elimination
 * Block '<S5>/Signal Conversion2' : Unused code path elimination
 * Block '<S5>/Signal Conversion3' : Unused code path elimination
 * Block '<S5>/Signal Conversion4' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Micro_mouse'
 * '<S1>'   : 'Micro_mouse/Centering'
 * '<S2>'   : 'Micro_mouse/Digital Port Write'
 * '<S3>'   : 'Micro_mouse/Direction'
 * '<S4>'   : 'Micro_mouse/Direction1'
 * '<S5>'   : 'Micro_mouse/IR'
 * '<S6>'   : 'Micro_mouse/PWM'
 * '<S7>'   : 'Micro_mouse/PWM1'
 * '<S8>'   : 'Micro_mouse/Digital Port Write/ECSoC'
 * '<S9>'   : 'Micro_mouse/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S10>'  : 'Micro_mouse/Direction/ECSoC'
 * '<S11>'  : 'Micro_mouse/Direction/ECSoC/ECSimCodegen'
 * '<S12>'  : 'Micro_mouse/Direction1/ECSoC'
 * '<S13>'  : 'Micro_mouse/Direction1/ECSoC/ECSimCodegen'
 * '<S14>'  : 'Micro_mouse/IR/Analog to Digital Converter'
 * '<S15>'  : 'Micro_mouse/IR/Analog to Digital Converter/ECSoC'
 * '<S16>'  : 'Micro_mouse/IR/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S17>'  : 'Micro_mouse/PWM/ECSoC'
 * '<S18>'  : 'Micro_mouse/PWM/ECSoC/ECSimCodegen'
 * '<S19>'  : 'Micro_mouse/PWM1/ECSoC'
 * '<S20>'  : 'Micro_mouse/PWM1/ECSoC/ECSimCodegen'
 */
#endif                                 /* Micro_mouse_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
