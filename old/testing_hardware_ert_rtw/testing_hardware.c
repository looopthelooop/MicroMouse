/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: testing_hardware.c
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

#include "testing_hardware.h"
#include "testing_hardware_types.h"
#include "rtwtypes.h"
#include "stm_timer_ll.h"

/* Block states (default storage) */
DW_testing_hardware_T testing_hardware_DW;

/* Real-time model */
static RT_MODEL_testing_hardware_T testing_hardware_M_;
RT_MODEL_testing_hardware_T *const testing_hardware_M = &testing_hardware_M_;

/* Forward declaration for local functions */
static void testing_har_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_te_T *obj);
static void testing_har_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_te_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S6>/PWM Output' */
  b.PeripheralPtr = TIM16;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S6>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S6>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

/* Model step function */
void testing_hardware_step(void)
{
  GPIO_TypeDef * portNameLoc;
  int32_T rtb_PulseGenerator;

  /* MATLABSystem: '<S6>/PWM Output' incorporates:
   *  Constant: '<Root>/Constant'
   */
  setDutyCycleInPercentageChannel1(testing_hardware_DW.obj.TimerHandle, 10.0);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = ((testing_hardware_DW.clockTickCounter < 1) &&
                        (testing_hardware_DW.clockTickCounter >= 0));
  if (testing_hardware_DW.clockTickCounter >= 1) {
    testing_hardware_DW.clockTickCounter = 0;
  } else {
    testing_hardware_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<S4>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (rtb_PulseGenerator != 0) {
    rtb_PulseGenerator = 4096;
  } else {
    rtb_PulseGenerator = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)rtb_PulseGenerator);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)rtb_PulseGenerator & 4096U);

  /* End of MATLABSystem: '<S4>/Digital Port Write' */
}

/* Model initialize function */
void testing_hardware_initialize(void)
{
  /* Start for MATLABSystem: '<S6>/PWM Output' */
  testing_hardware_DW.obj.matlabCodegenIsDeleted = false;
  testing_hardware_DW.obj.isSetupComplete = false;
  testing_hardware_DW.obj.isInitialized = 1;
  testing_har_PWMOutput_setupImpl(&testing_hardware_DW.obj);
  testing_hardware_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void testing_hardware_terminate(void)
{
  /* Terminate for MATLABSystem: '<S6>/PWM Output' */
  if (!testing_hardware_DW.obj.matlabCodegenIsDeleted) {
    testing_hardware_DW.obj.matlabCodegenIsDeleted = true;
    if ((testing_hardware_DW.obj.isInitialized == 1) &&
        testing_hardware_DW.obj.isSetupComplete) {
      disableCounter(testing_hardware_DW.obj.TimerHandle);
      disableTimerInterrupts(testing_hardware_DW.obj.TimerHandle, 0);
      disableTimerChannel1(testing_hardware_DW.obj.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
