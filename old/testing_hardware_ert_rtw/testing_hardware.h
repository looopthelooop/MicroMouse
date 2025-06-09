/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: testing_hardware.h
 *
 * Code generated for Simulink model 'testing_hardware'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Mon Jun  9 09:55:11 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef testing_hardware_h_
#define testing_hardware_h_
#ifndef testing_hardware_COMMON_INCLUDES_
#define testing_hardware_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#include "main.h"
#endif                                 /* testing_hardware_COMMON_INCLUDES_ */

#include "testing_hardware_types.h"
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
  stm32cube_blocks_PWMOutput_te_T obj; /* '<S6>/PWM Output' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_testing_hardware_T;

/* Real-time Model Data Structure */
struct tag_RTM_testing_hardware_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_testing_hardware_T testing_hardware_DW;

/* Model entry point functions */
extern void testing_hardware_initialize(void);
extern void testing_hardware_step(void);
extern void testing_hardware_terminate(void);

/* Real-time Model object */
extern RT_MODEL_testing_hardware_T *const testing_hardware_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'testing_hardware'
 * '<S1>'   : 'testing_hardware/Digital Port Write'
 * '<S2>'   : 'testing_hardware/PWM Output'
 * '<S3>'   : 'testing_hardware/Digital Port Write/ECSoC'
 * '<S4>'   : 'testing_hardware/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S5>'   : 'testing_hardware/PWM Output/ECSoC'
 * '<S6>'   : 'testing_hardware/PWM Output/ECSoC/ECSimCodegen'
 */
#endif                                 /* testing_hardware_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
