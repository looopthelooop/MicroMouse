/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sun May  4 16:18:33 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_types.h"
#include "stm_timer_ll.h"
#include "rtwtypes.h"
#include "untitled_private.h"

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Forward declaration for local functions */
static void untitled_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_un_T *obj);
static void untitled_PWMOutput_setupImpl_b(stm32cube_blocks_PWMOutput_un_T *obj);
static void untitled_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_un_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S4>/PWM Output' */
  b.PeripheralPtr = TIM16;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S4>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S4>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void untitled_PWMOutput_setupImpl_b(stm32cube_blocks_PWMOutput_un_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S6>/PWM Output' */
  b.PeripheralPtr = TIM1;
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
void untitled_step(void)
{
  /* MATLABSystem: '<S4>/PWM Output' incorporates:
   *  Constant: '<Root>/Constant'
   */
  setDutyCycleInPercentageChannel1(untitled_DW.obj_e.TimerHandle, 50.0);

  /* MATLABSystem: '<S6>/PWM Output' incorporates:
   *  Constant: '<Root>/Constant'
   */
  setDutyCycleInPercentageChannel1(untitled_DW.obj.TimerHandle, 50.0);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled_M->Timing.taskTime0 =
    ((time_T)(++untitled_M->Timing.clockTick0)) * untitled_M->Timing.stepSize0;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (761583124U);
  untitled_M->Sizes.checksums[1] = (78329095U);
  untitled_M->Sizes.checksums[2] = (3955227884U);
  untitled_M->Sizes.checksums[3] = (1770732717U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* Start for MATLABSystem: '<S4>/PWM Output' */
  untitled_DW.obj_e.matlabCodegenIsDeleted = false;
  untitled_DW.obj_e.isSetupComplete = false;
  untitled_DW.obj_e.isInitialized = 1;
  untitled_PWMOutput_setupImpl(&untitled_DW.obj_e);
  untitled_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/PWM Output' */
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.obj.isSetupComplete = false;
  untitled_DW.obj.isInitialized = 1;
  untitled_PWMOutput_setupImpl_b(&untitled_DW.obj);
  untitled_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for MATLABSystem: '<S4>/PWM Output' */
  if (!untitled_DW.obj_e.matlabCodegenIsDeleted) {
    untitled_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_e.isInitialized == 1) &&
        untitled_DW.obj_e.isSetupComplete) {
      disableCounter(untitled_DW.obj_e.TimerHandle);
      disableTimerInterrupts(untitled_DW.obj_e.TimerHandle, 0);
      disableTimerChannel1(untitled_DW.obj_e.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM Output' */

  /* Terminate for MATLABSystem: '<S6>/PWM Output' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj.isInitialized == 1) && untitled_DW.obj.isSetupComplete)
    {
      disableCounter(untitled_DW.obj.TimerHandle);
      disableTimerInterrupts(untitled_DW.obj.TimerHandle, 0);
      disableTimerChannel1(untitled_DW.obj.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
