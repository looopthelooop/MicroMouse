/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: micrmouseg.c
 *
 * Code generated for Simulink model 'micrmouseg'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Mon Jun  9 15:16:17 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "micrmouseg.h"
#include "micrmouseg_types.h"
#include "micrmouseg_private.h"
#include "rtwtypes.h"
#include <math.h>
#include "stm_timer_ll.h"
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
B_micrmouseg_T micrmouseg_B;

/* Block states (default storage) */
DW_micrmouseg_T micrmouseg_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_micrmouseg_T micrmouseg_Y;

/* Real-time model */
static RT_MODEL_micrmouseg_T micrmouseg_M_;
RT_MODEL_micrmouseg_T *const micrmouseg_M = &micrmouseg_M_;

/* Forward declaration for local functions */
static void micrmouse_PWMOutput_setupImpl_d(stm32cube_blocks_PWMOutput_mi_T *obj);
static void micrmouseg_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_mi_T *obj);
static void micrmouse_PWMOutput_setupImpl_d(stm32cube_blocks_PWMOutput_mi_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S140>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S140>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S140>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void micrmouseg_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_mi_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S123>/PWM Output' */
  b.PeripheralPtr = TIM16;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S123>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S123>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

/* Model step function */
void micrmouseg_step(void)
{
  /* local block i/o variables */
  real_T rtb_TSamp;
  real_T rtb_FilterCoefficient;
  real_T rtb_IntegralGain;
  real_T rtb_TSamp_c;
  real_T rtb_FilterCoefficient_j;
  real_T rtb_IntegralGain_g;
  GPIO_TypeDef * portNameLoc;
  real_T rtb_Integrator_l;
  real_T rtb_Output;
  int32_T c;

  /* Gain: '<S9>/Ratio' incorporates:
   *  RateTransition generated from: '<S9>/Triggered Subsystem'
   */
  micrmouseg_B.Ratio = 0.015259164317436139 * micrmouseg_B.UnitDelay;

  /* Step: '<S8>/Step' */
  if (micrmouseg_M->Timing.t[0] < 0.0) {
    c = 0;
  } else {
    c = 15;
  }

  /* Sum: '<S8>/Output' incorporates:
   *  Clock: '<S8>/Clock'
   *  Product: '<S8>/Product'
   *  Step: '<S8>/Step'
   */
  rtb_Output = (real_T)c * micrmouseg_M->Timing.t[0];

  /* SampleTimeMath: '<S3>/TSamp'
   *
   * About '<S3>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp = micrmouseg_B.Ratio * 5.0;

  /* Sum: '<Root>/Sum' incorporates:
   *  Sum: '<Root>/Sum1'
   *  Sum: '<S3>/Diff'
   *  UnitDelay: '<S3>/UD'
   *
   * Block description for '<S3>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  rtb_IntegralGain = (rtb_Output - micrmouseg_B.Ratio) - (rtb_TSamp -
    micrmouseg_DW.UD_DSTATE);

  /* Gain: '<S47>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S39>/Filter'
   *  Gain: '<S37>/Derivative Gain'
   *  Sum: '<S39>/SumD'
   */
  rtb_FilterCoefficient = (0.0 * rtb_IntegralGain - micrmouseg_DW.Filter_DSTATE)
    * 100.0;

  /* Sum: '<S53>/Sum' incorporates:
   *  DiscreteIntegrator: '<S44>/Integrator'
   *  Gain: '<S49>/Proportional Gain'
   */
  rtb_Integrator_l = (5.0 * rtb_IntegralGain + micrmouseg_DW.Integrator_DSTATE)
    + rtb_FilterCoefficient;

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_Integrator_l > 99.0) {
    rtb_Integrator_l = 99.0;
  } else if (rtb_Integrator_l < -99.0) {
    rtb_Integrator_l = -99.0;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* MATLABSystem: '<S138>/Digital Port Write' incorporates:
   *  Constant: '<S1>/Constant'
   *  RelationalOperator: '<S1>/Compare'
   */
  portNameLoc = GPIOA;
  if (rtb_Integrator_l > 0.0) {
    c = 2048;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 2048U);

  /* End of MATLABSystem: '<S138>/Digital Port Write' */

  /* MATLABSystem: '<S140>/PWM Output' incorporates:
   *  Abs: '<Root>/Abs1'
   */
  setDutyCycleInPercentageChannel1(micrmouseg_DW.obj.TimerHandle, fabs
    (rtb_Integrator_l));

  /* Gain: '<S7>/Ratio' incorporates:
   *  RateTransition generated from: '<S7>/Triggered Subsystem'
   */
  micrmouseg_B.Ratio_c = 0.015259164317436139 * micrmouseg_B.UnitDelay_i;

  /* SampleTimeMath: '<S4>/TSamp'
   *
   * About '<S4>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp_c = micrmouseg_B.Ratio_c * 5.0;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Sum: '<Root>/Sum3'
   *  Sum: '<S4>/Diff'
   *  UnitDelay: '<S4>/UD'
   *
   * Block description for '<S4>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S4>/UD':
   *
   *  Store in Global RAM
   */
  rtb_IntegralGain_g = (rtb_Output - micrmouseg_B.Ratio_c) - (rtb_TSamp_c -
    micrmouseg_DW.UD_DSTATE_b);

  /* Gain: '<S99>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S91>/Filter'
   *  Gain: '<S89>/Derivative Gain'
   *  Sum: '<S91>/SumD'
   */
  rtb_FilterCoefficient_j = (0.0 * rtb_IntegralGain_g -
    micrmouseg_DW.Filter_DSTATE_e) * 100.0;

  /* Sum: '<S105>/Sum' incorporates:
   *  DiscreteIntegrator: '<S96>/Integrator'
   *  Gain: '<S101>/Proportional Gain'
   */
  rtb_Output = (5.0 * rtb_IntegralGain_g + micrmouseg_DW.Integrator_DSTATE_f) +
    rtb_FilterCoefficient_j;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Output > 100.0) {
    rtb_Output = 100.0;
  } else if (rtb_Output < -100.0) {
    rtb_Output = -100.0;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* MATLABSystem: '<S121>/Digital Port Write' incorporates:
   *  Constant: '<S2>/Constant'
   *  RelationalOperator: '<S2>/Compare'
   */
  portNameLoc = GPIOA;
  if (rtb_Output < 0.0) {
    c = 4096;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 4096U);

  /* End of MATLABSystem: '<S121>/Digital Port Write' */

  /* MATLABSystem: '<S123>/PWM Output' incorporates:
   *  Abs: '<Root>/Abs'
   */
  setDutyCycleInPercentageChannel1(micrmouseg_DW.obj_f.TimerHandle, fabs
    (rtb_Output));

  /* Outport: '<Root>/PosL' */
  micrmouseg_Y.PosL = micrmouseg_B.Ratio_c;

  /* Outport: '<Root>/PosR' */
  micrmouseg_Y.PosR = micrmouseg_B.Ratio;

  /* Update for UnitDelay: '<S3>/UD'
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  micrmouseg_DW.UD_DSTATE = rtb_TSamp;

  /* Update for DiscreteIntegrator: '<S44>/Integrator' */
  micrmouseg_DW.Integrator_DSTATE += 0.2 * rtb_IntegralGain;

  /* Update for DiscreteIntegrator: '<S39>/Filter' */
  micrmouseg_DW.Filter_DSTATE += 0.2 * rtb_FilterCoefficient;

  /* Update for UnitDelay: '<S4>/UD'
   *
   * Block description for '<S4>/UD':
   *
   *  Store in Global RAM
   */
  micrmouseg_DW.UD_DSTATE_b = rtb_TSamp_c;

  /* Update for DiscreteIntegrator: '<S96>/Integrator' */
  micrmouseg_DW.Integrator_DSTATE_f += 0.2 * rtb_IntegralGain_g;

  /* Update for DiscreteIntegrator: '<S91>/Filter' */
  micrmouseg_DW.Filter_DSTATE_e += 0.2 * rtb_FilterCoefficient_j;

  {                                    /* Sample time: [0.2s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((micrmouseg_M->Timing.clockTick1) * 0.2);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1, extmodeTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  micrmouseg_M->Timing.t[0] =
    ((time_T)(++micrmouseg_M->Timing.clockTick0)) *
    micrmouseg_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.2, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    micrmouseg_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void micrmouseg_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&micrmouseg_M->solverInfo,
                          &micrmouseg_M->Timing.simTimeStep);
    rtsiSetTPtr(&micrmouseg_M->solverInfo, &rtmGetTPtr(micrmouseg_M));
    rtsiSetStepSizePtr(&micrmouseg_M->solverInfo,
                       &micrmouseg_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&micrmouseg_M->solverInfo, (&rtmGetErrorStatus
      (micrmouseg_M)));
    rtsiSetRTModelPtr(&micrmouseg_M->solverInfo, micrmouseg_M);
  }

  rtsiSetSimTimeStep(&micrmouseg_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&micrmouseg_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&micrmouseg_M->solverInfo, false);
  rtsiSetSolverName(&micrmouseg_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(micrmouseg_M, &micrmouseg_M->Timing.tArray[0]);
  rtmSetTFinal(micrmouseg_M, 10.0);
  micrmouseg_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  micrmouseg_M->Sizes.checksums[0] = (1290882479U);
  micrmouseg_M->Sizes.checksums[1] = (1379323892U);
  micrmouseg_M->Sizes.checksums[2] = (2977308218U);
  micrmouseg_M->Sizes.checksums[3] = (540803627U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    micrmouseg_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)&micrmouseg_DW.TriggeredSubsystem_SubsysRanB_l;
    systemRan[4] = (sysRanDType *)&micrmouseg_DW.TriggeredSubsystem_SubsysRanB_l;
    systemRan[5] = (sysRanDType *)&micrmouseg_DW.TriggeredSubsystem_SubsysRanB_l;
    systemRan[6] = (sysRanDType *)&micrmouseg_DW.TriggeredSubsystem_SubsysRanB_l;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = (sysRanDType *)&micrmouseg_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[10] = (sysRanDType *)&micrmouseg_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[11] = (sysRanDType *)&micrmouseg_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[12] = (sysRanDType *)&micrmouseg_DW.TriggeredSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(micrmouseg_M->extModeInfo,
      &micrmouseg_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(micrmouseg_M->extModeInfo, micrmouseg_M->Sizes.checksums);
    rteiSetTPtr(micrmouseg_M->extModeInfo, rtmGetTPtr(micrmouseg_M));
  }

  /* Start for MATLABSystem: '<S140>/PWM Output' */
  micrmouseg_DW.obj.matlabCodegenIsDeleted = false;
  micrmouseg_DW.obj.isSetupComplete = false;
  micrmouseg_DW.obj.isInitialized = 1;
  micrmouse_PWMOutput_setupImpl_d(&micrmouseg_DW.obj);
  micrmouseg_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S123>/PWM Output' */
  micrmouseg_DW.obj_f.matlabCodegenIsDeleted = false;
  micrmouseg_DW.obj_f.isSetupComplete = false;
  micrmouseg_DW.obj_f.isInitialized = 1;
  micrmouseg_PWMOutput_setupImpl(&micrmouseg_DW.obj_f);
  micrmouseg_DW.obj_f.isSetupComplete = true;
}

/* Model terminate function */
void micrmouseg_terminate(void)
{
  /* Terminate for MATLABSystem: '<S140>/PWM Output' */
  if (!micrmouseg_DW.obj.matlabCodegenIsDeleted) {
    micrmouseg_DW.obj.matlabCodegenIsDeleted = true;
    if ((micrmouseg_DW.obj.isInitialized == 1) &&
        micrmouseg_DW.obj.isSetupComplete) {
      disableCounter(micrmouseg_DW.obj.TimerHandle);
      disableTimerInterrupts(micrmouseg_DW.obj.TimerHandle, 0);
      disableTimerChannel1(micrmouseg_DW.obj.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S140>/PWM Output' */

  /* Terminate for MATLABSystem: '<S123>/PWM Output' */
  if (!micrmouseg_DW.obj_f.matlabCodegenIsDeleted) {
    micrmouseg_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((micrmouseg_DW.obj_f.isInitialized == 1) &&
        micrmouseg_DW.obj_f.isSetupComplete) {
      disableCounter(micrmouseg_DW.obj_f.TimerHandle);
      disableTimerInterrupts(micrmouseg_DW.obj_f.TimerHandle, 0);
      disableTimerChannel1(micrmouseg_DW.obj_f.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S123>/PWM Output' */
}

void micrmouseg_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(24,&EXTI3_IRQHandler,2);
  MW_NVIC_EnableIRQ(24);

  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(21,&EXTI0_IRQHandler,2);
  MW_NVIC_EnableIRQ(21);
}

/* Hardware Interrupt Block: '<S119>/Hardware Interrupt' */
void EXTI3_IRQHandler(void)
{
  /* Event: EXTI3 Event */
  /* Check event EXTI3 Event occurred */
  if (0 != ((0 != LL_EXTI_IsEnabledIT_0_31(LL_EXTI_LINE_3)) && (0 !=
        LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_3)))) {
    /* Clear occurred EXTI3 Event event */
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_3);
    if (1 == runModel) {
      {
        /* Reset subsysRan breadcrumbs */
        srClearBC(micrmouseg_DW.TriggeredSubsystem_SubsysRanB_l);

        /* S-Function (HardwareInterrupt_sfun): '<S119>/Hardware Interrupt' */

        /* Output and update for function-call system: '<S7>/Triggered Subsystem' */
        {
          int32_T tmp;
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_p;
          micrmouseg_M->Timing.clockTick2 = micrmouseg_M->Timing.clockTick0;

          /* MATLABSystem: '<S128>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* MATLABSystem: '<S130>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOB);

          /* UnitDelay: '<S117>/Unit Delay' */
          micrmouseg_B.UnitDelay_i = micrmouseg_DW.UnitDelay_DSTATE_l;

          /* MATLAB Function: '<S117>/MATLAB Function' incorporates:
           *  MATLABSystem: '<S128>/Digital Port Read'
           *  MATLABSystem: '<S130>/Digital Port Read'
           * */
          if (((pinReadLoc & 8U) != 0U) == ((pinReadLoc_p & 16U) != 0U)) {
            tmp = 1;
          } else {
            tmp = -1;
          }

          /* Update for UnitDelay: '<S117>/Unit Delay' incorporates:
           *  MATLAB Function: '<S117>/MATLAB Function'
           *  Sum: '<S117>/Sum'
           */
          micrmouseg_DW.UnitDelay_DSTATE_l = (real_T)tmp +
            micrmouseg_B.UnitDelay_i;
          micrmouseg_DW.TriggeredSubsystem_SubsysRanB_l = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S119>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((micrmouseg_M->Timing.clockTick2)
        * 0.2);
      extmodeEvent(2,currentTime);
    }
  }

  __ISB();
  __DSB();
}

/* Hardware Interrupt Block: '<S136>/Hardware Interrupt' */
void EXTI0_IRQHandler(void)
{
  /* Event: EXTI0 Event */
  /* Check event EXTI0 Event occurred */
  if (0 != ((0 != LL_EXTI_IsEnabledIT_0_31(LL_EXTI_LINE_0)) && (0 !=
        LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_0)))) {
    /* Clear occurred EXTI0 Event event */
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_0);
    if (1 == runModel) {
      {
        /* Reset subsysRan breadcrumbs */
        srClearBC(micrmouseg_DW.TriggeredSubsystem_SubsysRanBC);

        /* S-Function (HardwareInterrupt_sfun): '<S136>/Hardware Interrupt' */

        /* Output and update for function-call system: '<S9>/Triggered Subsystem' */
        {
          int32_T tmp;
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_p;
          micrmouseg_M->Timing.clockTick3 = micrmouseg_M->Timing.clockTick0;

          /* MATLABSystem: '<S145>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* MATLABSystem: '<S147>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOB);

          /* UnitDelay: '<S134>/Unit Delay' */
          micrmouseg_B.UnitDelay = micrmouseg_DW.UnitDelay_DSTATE;

          /* MATLAB Function: '<S134>/MATLAB Function' incorporates:
           *  MATLABSystem: '<S145>/Digital Port Read'
           *  MATLABSystem: '<S147>/Digital Port Read'
           * */
          if (((pinReadLoc & 1U) != 0U) == ((pinReadLoc_p & 64U) != 0U)) {
            tmp = -1;
          } else {
            tmp = 1;
          }

          /* Update for UnitDelay: '<S134>/Unit Delay' incorporates:
           *  MATLAB Function: '<S134>/MATLAB Function'
           *  Sum: '<S134>/Sum'
           */
          micrmouseg_DW.UnitDelay_DSTATE = (real_T)tmp + micrmouseg_B.UnitDelay;
          micrmouseg_DW.TriggeredSubsystem_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S136>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((micrmouseg_M->Timing.clockTick3)
        * 0.2);
      extmodeEvent(3,currentTime);
    }
  }

  __ISB();
  __DSB();
}

void micrmouseg_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(24);
  MW_NVIC_DisableIRQ(21);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
