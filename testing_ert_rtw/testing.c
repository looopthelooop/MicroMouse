/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: testing.c
 *
 * Code generated for Simulink model 'testing'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Mon May  5 14:35:01 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "testing.h"
#include "testing_types.h"
#include "testing_private.h"
#include "rtwtypes.h"
#include <math.h>
#include "stm_adc_ll.h"
#include "stm_timer_ll.h"
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
B_testing_T testing_B;

/* Block states (default storage) */
DW_testing_T testing_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_testing_T testing_Y;

/* Real-time model */
static RT_MODEL_testing_T testing_M_;
RT_MODEL_testing_T *const testing_M = &testing_M_;

/* Forward declaration for local functions */
static void testing_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_te_T *obj);
static void testing_PWMOutput_setupImpl_o(stm32cube_blocks_PWMOutput_te_T *obj);
static void testing_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);
static void testing_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_te_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S126>/PWM Output' */
  b.PeripheralPtr = TIM16;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S126>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S126>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void testing_PWMOutput_setupImpl_o(stm32cube_blocks_PWMOutput_te_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S144>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S144>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S144>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void testing_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S116>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void*)(&obj->ADCInternalBuffer[0]);
  adcStructLoc.InjectedNoOfConversion = 0U;
  adcStructLoc.peripheralPtr = ADC1;
  adcStructLoc.dmaPeripheralPtr = DMA1;
  adcStructLoc.dmastream = LL_DMA_CHANNEL_1;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_UNLIMITED;
  adcStructLoc.InternalBufferSize = 5U;
  adcStructLoc.RegularNoOfConversion = 5U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_DMA_INTERRUPT_MODE, 1,
    ADC_TRIGGER_AND_READ, LL_ADC_REG_SEQ_SCAN_ENABLE_5RANKS);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 1);
  obj->isSetupComplete = true;
}

/* Model step function */
void testing_step(void)
{
  /* local block i/o variables */
  real_T rtb_FilterCoefficient;
  real_T rtb_FilterCoefficient_d;
  real_T rtb_IntegralGain;
  real_T rtb_IntegralGain_p;
  real_T rtb_delta_h;

  {
    GPIO_TypeDef * portNameLoc;
    real_T rtb_Abs1;
    real_T rtb_SineWave;
    real_T rtb_TmpRTBAtTriggeredSubsystemO;
    real_T *lastU;
    int32_T i;
    uint32_T rtb_Gain2[5];
    uint16_T rtb_AnalogtoDigitalConverter_0[5];
    boolean_T rtb_Compare;

    /* RateTransition generated from: '<S8>/Triggered Subsystem' */
    rtb_TmpRTBAtTriggeredSubsystemO = testing_B.OutportBufferForPosition;

    /* Gain: '<S8>/Ratio' */
    testing_B.Ratio = 15.25916431743614 * rtb_TmpRTBAtTriggeredSubsystemO;

    /* Outport: '<Root>/position' */
    testing_Y.position = testing_B.Ratio;

    /* Gain: '<S9>/Ratio' incorporates:
     *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
     */
    testing_B.Ratio_p = 15.25916431743614 *
      testing_DW.DiscreteTimeIntegrator_DSTATE;

    /* Outport: '<Root>/position1' */
    testing_Y.position1 = testing_B.Ratio_p;

    /* Derivative: '<Root>/Derivative' */
    rtb_TmpRTBAtTriggeredSubsystemO = testing_M->Timing.t[0];
    if ((testing_DW.TimeStampA >= rtb_TmpRTBAtTriggeredSubsystemO) &&
        (testing_DW.TimeStampB >= rtb_TmpRTBAtTriggeredSubsystemO)) {
      /* Derivative: '<Root>/Derivative' */
      testing_B.Derivative = 0.0;
    } else {
      rtb_Abs1 = testing_DW.TimeStampA;
      lastU = &testing_DW.LastUAtTimeA;
      if (testing_DW.TimeStampA < testing_DW.TimeStampB) {
        if (testing_DW.TimeStampB < rtb_TmpRTBAtTriggeredSubsystemO) {
          rtb_Abs1 = testing_DW.TimeStampB;
          lastU = &testing_DW.LastUAtTimeB;
        }
      } else if (testing_DW.TimeStampA >= rtb_TmpRTBAtTriggeredSubsystemO) {
        rtb_Abs1 = testing_DW.TimeStampB;
        lastU = &testing_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/Derivative' */
      testing_B.Derivative = (testing_B.Ratio_p - *lastU) /
        (rtb_TmpRTBAtTriggeredSubsystemO - rtb_Abs1);
    }

    /* End of Derivative: '<Root>/Derivative' */

    /* Outport: '<Root>/Out1' */
    testing_Y.Out1 = testing_B.Derivative;

    /* Sin: '<Root>/Sine Wave' */
    rtb_SineWave = sin(testing_M->Timing.t[0]) * 10.0 + 20.0;

    /* Gain: '<S47>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S39>/Filter'
     *  Gain: '<S37>/Derivative Gain'
     *  Sum: '<Root>/Sum'
     *  Sum: '<S39>/SumD'
     */
    rtb_FilterCoefficient = (0.0 * rtb_SineWave - testing_DW.Filter_DSTATE) *
      100.0;

    /* Sum: '<S53>/Sum' incorporates:
     *  DiscreteIntegrator: '<S44>/Integrator'
     *  Sum: '<Root>/Sum'
     */
    testing_B.Saturation1 = (rtb_SineWave + testing_DW.Integrator_DSTATE) +
      rtb_FilterCoefficient;

    /* Saturate: '<Root>/Saturation1' */
    if (testing_B.Saturation1 > 99.0) {
      /* Sum: '<S53>/Sum' incorporates:
       *  Saturate: '<Root>/Saturation1'
       */
      testing_B.Saturation1 = 99.0;
    } else if (testing_B.Saturation1 < -99.0) {
      /* Sum: '<S53>/Sum' incorporates:
       *  Saturate: '<Root>/Saturation1'
       */
      testing_B.Saturation1 = -99.0;
    }

    /* End of Saturate: '<Root>/Saturation1' */
    /* Gain: '<S99>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S91>/Filter'
     *  Gain: '<S89>/Derivative Gain'
     *  Sum: '<Root>/Sum1'
     *  Sum: '<S91>/SumD'
     */
    rtb_FilterCoefficient_d = (0.0 * rtb_SineWave - testing_DW.Filter_DSTATE_o) *
      100.0;

    /* Sum: '<S105>/Sum' incorporates:
     *  DiscreteIntegrator: '<S96>/Integrator'
     *  Sum: '<Root>/Sum1'
     */
    rtb_TmpRTBAtTriggeredSubsystemO = (rtb_SineWave +
      testing_DW.Integrator_DSTATE_d) + rtb_FilterCoefficient_d;

    /* Saturate: '<Root>/Saturation' */
    if (rtb_TmpRTBAtTriggeredSubsystemO > 99.0) {
      rtb_TmpRTBAtTriggeredSubsystemO = 99.0;
    } else if (rtb_TmpRTBAtTriggeredSubsystemO < -99.0) {
      rtb_TmpRTBAtTriggeredSubsystemO = -99.0;
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* Abs: '<Root>/Abs1' */
    rtb_Abs1 = fabs(testing_B.Saturation1);

    /* RelationalOperator: '<S2>/Compare' incorporates:
     *  Constant: '<S2>/Constant'
     */
    rtb_Compare = (testing_B.Saturation1 > 0.0);

    /* Gain: '<S41>/Integral Gain' incorporates:
     *  Gain: '<S93>/Integral Gain'
     *  Sum: '<Root>/Sum'
     */
    rtb_IntegralGain = 0.0 * rtb_SineWave;

    /* Gain: '<S93>/Integral Gain' */
    rtb_IntegralGain_p = rtb_IntegralGain;

    /* MATLABSystem: '<S126>/PWM Output' incorporates:
     *  Abs: '<Root>/Abs'
     */
    setDutyCycleInPercentageChannel1(testing_DW.obj_n.TimerHandle, fabs
      (rtb_TmpRTBAtTriggeredSubsystemO));

    /* MATLABSystem: '<S124>/Digital Port Write' incorporates:
     *  Constant: '<S3>/Constant'
     *  RelationalOperator: '<S3>/Compare'
     */
    portNameLoc = GPIOA;
    if (rtb_TmpRTBAtTriggeredSubsystemO < 0.0) {
      i = 4096;
    } else {
      i = 0;
    }

    LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
    LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 4096U);

    /* End of MATLABSystem: '<S124>/Digital Port Write' */
    /* RateTransition generated from: '<S9>/Discrete-Time Integrator' */
    rtb_delta_h = testing_B.delta;

    /* MATLABSystem: '<S144>/PWM Output' */
    setDutyCycleInPercentageChannel1(testing_DW.obj_i.TimerHandle, rtb_Abs1);

    /* MATLABSystem: '<S142>/Digital Port Write' */
    portNameLoc = GPIOA;
    if (rtb_Compare) {
      i = 2048;
    } else {
      i = 0;
    }

    LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
    LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 2048U);

    /* End of MATLABSystem: '<S142>/Digital Port Write' */

    /* MATLABSystem: '<S116>/Analog to Digital Converter' */
    regularReadADCDMA(testing_DW.obj.ADCHandle, ADC_TRIGGER_AND_READ,
                      &rtb_AnalogtoDigitalConverter_0[0]);

    /* Gain: '<S7>/Gain2' incorporates:
     *  MATLABSystem: '<S116>/Analog to Digital Converter'
     */
    for (i = 0; i < 5; i++) {
      rtb_Gain2[i] = 54080U * rtb_AnalogtoDigitalConverter_0[i];
    }

    /* End of Gain: '<S7>/Gain2' */

    /* SignalConversion: '<S7>/Signal Conversion4' */
    testing_B.SignalConversion4 = rtb_Gain2[0];

    /* SignalConversion: '<S7>/Signal Conversion' */
    testing_B.SignalConversion = rtb_Gain2[4];

    /* Sum: '<S1>/Sum2' incorporates:
     *  SignalConversion: '<S7>/Signal Conversion'
     *  SignalConversion: '<S7>/Signal Conversion4'
     */
    testing_B.Sum2 = testing_B.SignalConversion4 - testing_B.SignalConversion;

    /* Gain: '<S1>/Gain' incorporates:
     *  Sum: '<S1>/Sum2'
     */
    testing_B.Gain = 3435973837ULL * testing_B.Sum2;
  }

  {
    real_T *lastU;

    /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
    testing_DW.DiscreteTimeIntegrator_DSTATE += 0.01 * rtb_delta_h;

    /* Update for Derivative: '<Root>/Derivative' */
    if (testing_DW.TimeStampA == (rtInf)) {
      testing_DW.TimeStampA = testing_M->Timing.t[0];
      lastU = &testing_DW.LastUAtTimeA;
    } else if (testing_DW.TimeStampB == (rtInf)) {
      testing_DW.TimeStampB = testing_M->Timing.t[0];
      lastU = &testing_DW.LastUAtTimeB;
    } else if (testing_DW.TimeStampA < testing_DW.TimeStampB) {
      testing_DW.TimeStampA = testing_M->Timing.t[0];
      lastU = &testing_DW.LastUAtTimeA;
    } else {
      testing_DW.TimeStampB = testing_M->Timing.t[0];
      lastU = &testing_DW.LastUAtTimeB;
    }

    *lastU = testing_B.Ratio_p;

    /* End of Update for Derivative: '<Root>/Derivative' */

    /* Update for DiscreteIntegrator: '<S44>/Integrator' */
    testing_DW.Integrator_DSTATE += 0.01 * rtb_IntegralGain;

    /* Update for DiscreteIntegrator: '<S39>/Filter' */
    testing_DW.Filter_DSTATE += 0.01 * rtb_FilterCoefficient;

    /* Update for DiscreteIntegrator: '<S96>/Integrator' */
    testing_DW.Integrator_DSTATE_d += 0.01 * rtb_IntegralGain_p;

    /* Update for DiscreteIntegrator: '<S91>/Filter' */
    testing_DW.Filter_DSTATE_o += 0.01 * rtb_FilterCoefficient_d;
  }

  {                                    /* Sample time: [0.01s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((testing_M->Timing.clockTick1) * 0.01);

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
  testing_M->Timing.t[0] =
    ((time_T)(++testing_M->Timing.clockTick0)) * testing_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    testing_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void testing_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&testing_M->solverInfo, &testing_M->Timing.simTimeStep);
    rtsiSetTPtr(&testing_M->solverInfo, &rtmGetTPtr(testing_M));
    rtsiSetStepSizePtr(&testing_M->solverInfo, &testing_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&testing_M->solverInfo, (&rtmGetErrorStatus(testing_M)));
    rtsiSetRTModelPtr(&testing_M->solverInfo, testing_M);
  }

  rtsiSetSimTimeStep(&testing_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&testing_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&testing_M->solverInfo, false);
  rtsiSetSolverName(&testing_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(testing_M, &testing_M->Timing.tArray[0]);
  rtmSetTFinal(testing_M, 20.0);
  testing_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  testing_M->Sizes.checksums[0] = (3843680989U);
  testing_M->Sizes.checksums[1] = (3491648164U);
  testing_M->Sizes.checksums[2] = (1384151119U);
  testing_M->Sizes.checksums[3] = (4127796207U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[15];
    testing_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)&testing_DW.TriggeredSubsystem_SubsysRanB_g;
    systemRan[5] = (sysRanDType *)&testing_DW.TriggeredSubsystem_SubsysRanB_g;
    systemRan[6] = (sysRanDType *)&testing_DW.TriggeredSubsystem_SubsysRanB_g;
    systemRan[7] = (sysRanDType *)&testing_DW.TriggeredSubsystem_SubsysRanB_g;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = (sysRanDType *)&testing_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[11] = (sysRanDType *)&testing_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[12] = (sysRanDType *)&testing_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[13] = (sysRanDType *)&testing_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[14] = (sysRanDType *)&testing_DW.TriggeredSubsystem1_SubsysRanBC;
    rteiSetModelMappingInfoPtr(testing_M->extModeInfo,
      &testing_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(testing_M->extModeInfo, testing_M->Sizes.checksums);
    rteiSetTPtr(testing_M->extModeInfo, rtmGetTPtr(testing_M));
  }

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  testing_DW.TimeStampA = (rtInf);
  testing_DW.TimeStampB = (rtInf);

  /* Start for MATLABSystem: '<S126>/PWM Output' */
  testing_DW.obj_n.matlabCodegenIsDeleted = false;
  testing_DW.obj_n.isSetupComplete = false;
  testing_DW.obj_n.isInitialized = 1;
  testing_PWMOutput_setupImpl(&testing_DW.obj_n);
  testing_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S144>/PWM Output' */
  testing_DW.obj_i.matlabCodegenIsDeleted = false;
  testing_DW.obj_i.isSetupComplete = false;
  testing_DW.obj_i.isInitialized = 1;
  testing_PWMOutput_setupImpl_o(&testing_DW.obj_i);
  testing_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S116>/Analog to Digital Converter' */
  testing_DW.obj.isInitialized = 0;
  testing_DW.obj.matlabCodegenIsDeleted = false;
  testing_SystemCore_setup(&testing_DW.obj);

  /* Enable for S-Function (HardwareInterrupt_sfun): '<S122>/Hardware Interrupt' incorporates:
   *  SubSystem: '<S8>/Triggered Subsystem'
   */

  /* Enable for function-call system: '<S8>/Triggered Subsystem' */
  testing_M->Timing.clockTick2 = testing_M->Timing.clockTick0;
  testing_DW.TriggeredSubsystem_RESET_ELAPS_ = true;

  /* Enable for DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */
  testing_DW.DiscreteTimeIntegrator_SYSTEM_E = 1U;

  /* End of Enable for S-Function (HardwareInterrupt_sfun): '<S122>/Hardware Interrupt' */
}

/* Model terminate function */
void testing_terminate(void)
{
  /* Terminate for MATLABSystem: '<S126>/PWM Output' */
  if (!testing_DW.obj_n.matlabCodegenIsDeleted) {
    testing_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((testing_DW.obj_n.isInitialized == 1) &&
        testing_DW.obj_n.isSetupComplete) {
      disableCounter(testing_DW.obj_n.TimerHandle);
      disableTimerInterrupts(testing_DW.obj_n.TimerHandle, 0);
      disableTimerChannel1(testing_DW.obj_n.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S126>/PWM Output' */
  /* Terminate for MATLABSystem: '<S144>/PWM Output' */
  if (!testing_DW.obj_i.matlabCodegenIsDeleted) {
    testing_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((testing_DW.obj_i.isInitialized == 1) &&
        testing_DW.obj_i.isSetupComplete) {
      disableCounter(testing_DW.obj_i.TimerHandle);
      disableTimerInterrupts(testing_DW.obj_i.TimerHandle, 0);
      disableTimerChannel1(testing_DW.obj_i.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S144>/PWM Output' */

  /* Terminate for MATLABSystem: '<S116>/Analog to Digital Converter' */
  if (!testing_DW.obj.matlabCodegenIsDeleted) {
    testing_DW.obj.matlabCodegenIsDeleted = true;
    if ((testing_DW.obj.isInitialized == 1) && testing_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(testing_DW.obj.ADCHandle, ADC_DMA_INTERRUPT_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S116>/Analog to Digital Converter' */
}

void testing_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(24,&EXTI3_IRQHandler,2);
  MW_NVIC_EnableIRQ(24);

  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(21,&EXTI0_IRQHandler,2);
  MW_NVIC_EnableIRQ(21);
}

/* Hardware Interrupt Block: '<S122>/Hardware Interrupt' */
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
        srClearBC(testing_DW.TriggeredSubsystem_SubsysRanB_g);

        /* S-Function (HardwareInterrupt_sfun): '<S122>/Hardware Interrupt' */

        /* Output and update for function-call system: '<S8>/Triggered Subsystem' */
        {
          uint32_T TriggeredSubsystem_ELAPS_T;
          uint32_T pinReadLoc;
          testing_M->Timing.clockTick2 = testing_M->Timing.clockTick0;
          if (testing_DW.TriggeredSubsystem_RESET_ELAPS_) {
            TriggeredSubsystem_ELAPS_T = 0U;
          } else {
            TriggeredSubsystem_ELAPS_T = testing_M->Timing.clockTick2 -
              testing_DW.TriggeredSubsystem_PREV_T;
          }

          testing_DW.TriggeredSubsystem_PREV_T = testing_M->Timing.clockTick2;
          testing_DW.TriggeredSubsystem_RESET_ELAPS_ = false;

          /* DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */
          if (testing_DW.DiscreteTimeIntegrator_SYSTEM_E == 0) {
            /* DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */
            testing_DW.DiscreteTimeIntegrator_DSTATE_e += 0.01 * (real_T)
              TriggeredSubsystem_ELAPS_T
              * testing_DW.DiscreteTimeIntegrator_PREV_U;
          }

          /* End of DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */

          /* SignalConversion generated from: '<S120>/Position' */
          testing_B.OutportBufferForPosition =
            testing_DW.DiscreteTimeIntegrator_DSTATE_e;

          /* MATLABSystem: '<S131>/Digital Port Read' */
          TriggeredSubsystem_ELAPS_T = LL_GPIO_ReadInputPort(GPIOB);

          /* MATLABSystem: '<S133>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* Update for DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */
          testing_DW.DiscreteTimeIntegrator_SYSTEM_E = 0U;

          /* MATLAB Function: '<S120>/MATLAB Function' incorporates:
           *  MATLABSystem: '<S131>/Digital Port Read'
           *  MATLABSystem: '<S133>/Digital Port Read'
           * */
          if (((TriggeredSubsystem_ELAPS_T & 8U) != 0U) == ((pinReadLoc & 16U)
               != 0U)) {
            /* Update for DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */
            testing_DW.DiscreteTimeIntegrator_PREV_U = 1.0;
          } else {
            /* Update for DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */
            testing_DW.DiscreteTimeIntegrator_PREV_U = -1.0;
          }

          /* End of MATLAB Function: '<S120>/MATLAB Function' */
          testing_DW.TriggeredSubsystem_SubsysRanB_g = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S122>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((testing_M->Timing.clockTick2) *
        0.01);
      extmodeEvent(2,currentTime);
    }
  }

  __ISB();
  __DSB();
}

/* Hardware Interrupt Block: '<S140>/Hardware Interrupt' */
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
        testing_M->Timing.clockTick3 = testing_M->Timing.clockTick0;

        /* Reset subsysRan breadcrumbs */
        srClearBC(testing_DW.TriggeredSubsystem_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(testing_DW.TriggeredSubsystem1_SubsysRanBC);

        /* S-Function (HardwareInterrupt_sfun): '<S140>/Hardware Interrupt' */

        /* Output and update for function-call system: '<S9>/Triggered Subsystem' */
        {
          uint32_T pinReadLoc;

          /* MATLABSystem: '<S149>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* MATLABSystem: '<S149>/Digital Port Read' */
          testing_B.DigitalPortRead = ((pinReadLoc & 1U) != 0U);

          /* MATLABSystem: '<S151>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* MATLAB Function: '<S137>/MATLAB Function' incorporates:
           *  MATLABSystem: '<S151>/Digital Port Read'
           * */
          if (((pinReadLoc & 2U) != 0U) == (int32_T)testing_B.DigitalPortRead) {
            testing_B.delta = -1.0;
          } else {
            testing_B.delta = 1.0;
          }

          /* End of MATLAB Function: '<S137>/MATLAB Function' */
          testing_DW.TriggeredSubsystem_SubsysRanBC = 4;
        }

        /* Output and update for function-call system: '<S9>/Triggered Subsystem1' */

        /* Sum: '<S138>/Sum of Elements' */
        testing_B.SumofElements = testing_B.delta;
        testing_DW.TriggeredSubsystem1_SubsysRanBC = 4;

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S140>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((testing_M->Timing.clockTick3) *
        0.01);
      extmodeEvent(3,currentTime);
    }
  }

  __ISB();
  __DSB();
}

void testing_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(24);
  MW_NVIC_DisableIRQ(21);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
