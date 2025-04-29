/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse.c
 *
 * Code generated for Simulink model 'Micro_mouse'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Apr 29 19:44:56 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Micro_mouse.h"
#include "Micro_mouse_types.h"
#include "Micro_mouse_private.h"
#include "rtwtypes.h"
#include "stm_adc_ll.h"
#include "stm_timer_ll.h"
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
B_Micro_mouse_T Micro_mouse_B;

/* Block states (default storage) */
DW_Micro_mouse_T Micro_mouse_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Micro_mouse_T Micro_mouse_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Micro_mouse_T Micro_mouse_Y;

/* Real-time model */
static RT_MODEL_Micro_mouse_T Micro_mouse_M_;
RT_MODEL_Micro_mouse_T *const Micro_mouse_M = &Micro_mouse_M_;

/* Forward declaration for local functions */
static void Micro_mouse_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);
static void Micro_mouse_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Mi_T *obj);
static void Micro_mou_PWMOutput_setupImpl_c(stm32cube_blocks_PWMOutput_Mi_T *obj);
static void Micro_mouse_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S113>/Analog to Digital Converter' */
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

static void Micro_mouse_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Mi_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S124>/PWM Output' */
  b.PeripheralPtr = TIM16;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S124>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S124>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void Micro_mou_PWMOutput_setupImpl_c(stm32cube_blocks_PWMOutput_Mi_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S142>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S142>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S142>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

/* Model step function */
void Micro_mouse_step(void)
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_FilterCoefficient;
  real_T rtb_FilterCoefficient_p;
  real_T rtb_Sum1;
  real_T rtb_TmpRTBAtTriggeredSubsyste_n;
  real_T rtb_TmpRTBAtTriggeredSubsystemO;
  int32_T i;
  uint32_T rtb_Gain2[5];
  uint16_T rtb_AnalogtoDigitalConverter_0[5];

  /* MATLABSystem: '<S113>/Analog to Digital Converter' */
  regularReadADCDMA(Micro_mouse_DW.obj.ADCHandle, ADC_TRIGGER_AND_READ,
                    &rtb_AnalogtoDigitalConverter_0[0]);

  /* Gain: '<S4>/Gain2' incorporates:
   *  MATLABSystem: '<S113>/Analog to Digital Converter'
   */
  for (i = 0; i < 5; i++) {
    rtb_Gain2[i] = 54080U * rtb_AnalogtoDigitalConverter_0[i];
  }

  /* End of Gain: '<S4>/Gain2' */

  /* SignalConversion: '<S4>/Signal Conversion4' */
  Micro_mouse_B.SignalConversion4 = rtb_Gain2[0];

  /* SignalConversion: '<S4>/Signal Conversion' */
  Micro_mouse_B.SignalConversion = rtb_Gain2[4];

  /* Sum: '<S1>/Sum2' incorporates:
   *  SignalConversion: '<S4>/Signal Conversion'
   *  SignalConversion: '<S4>/Signal Conversion4'
   */
  Micro_mouse_B.Sum2 = Micro_mouse_B.SignalConversion4 -
    Micro_mouse_B.SignalConversion;

  /* Gain: '<S1>/Gain' incorporates:
   *  Sum: '<S1>/Sum2'
   */
  Micro_mouse_B.Gain = 3435973837ULL * Micro_mouse_B.Sum2;

  /* RateTransition generated from: '<S5>/Triggered Subsystem' */
  rtb_TmpRTBAtTriggeredSubsystemO = Micro_mouse_B.OutportBufferForPosition_a;

  /* Gain: '<S5>/Ratio' */
  Micro_mouse_B.Ratio = 0.0014285714285714286 * rtb_TmpRTBAtTriggeredSubsystemO;

  /* Sum: '<Root>/Sum' incorporates:
   *  Inport: '<Root>/Ref'
   */
  rtb_TmpRTBAtTriggeredSubsystemO = Micro_mouse_U.Ref - Micro_mouse_B.Ratio;

  /* Gain: '<S44>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S36>/Filter'
   *  Gain: '<S34>/Derivative Gain'
   *  Sum: '<S36>/SumD'
   */
  rtb_FilterCoefficient = (0.0 * rtb_TmpRTBAtTriggeredSubsystemO -
    Micro_mouse_DW.Filter_DSTATE) * 100.0;

  /* Sum: '<Root>/Sum3' incorporates:
   *  DiscreteIntegrator: '<S41>/Integrator'
   *  Gain: '<S1>/Gain'
   *  Sum: '<S50>/Sum'
   */
  rtb_TmpRTBAtTriggeredSubsyste_n = ((rtb_TmpRTBAtTriggeredSubsystemO +
    Micro_mouse_DW.Integrator_DSTATE) + rtb_FilterCoefficient) + (real_T)
    Micro_mouse_B.Gain * 4.3368086899420177E-19;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_TmpRTBAtTriggeredSubsyste_n > 100.0) {
    rtb_TmpRTBAtTriggeredSubsyste_n = 100.0;
  } else if (rtb_TmpRTBAtTriggeredSubsyste_n < 0.0) {
    rtb_TmpRTBAtTriggeredSubsyste_n = 0.0;
  }

  /* MATLABSystem: '<S124>/PWM Output' incorporates:
   *  Saturate: '<Root>/Saturation'
   */
  setDutyCycleInPercentageChannel1(Micro_mouse_DW.obj_g.TimerHandle,
    rtb_TmpRTBAtTriggeredSubsyste_n);

  /* Outport: '<Root>/position' */
  Micro_mouse_Y.position = Micro_mouse_B.Ratio;

  /* RateTransition generated from: '<S6>/Triggered Subsystem' */
  rtb_TmpRTBAtTriggeredSubsyste_n = Micro_mouse_B.OutportBufferForPosition;

  /* Gain: '<S6>/Ratio' */
  Micro_mouse_B.Ratio_l = 0.0014285714285714286 *
    rtb_TmpRTBAtTriggeredSubsyste_n;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Inport: '<Root>/Ref1'
   */
  rtb_Sum1 = Micro_mouse_U.Ref1 - Micro_mouse_B.Ratio_l;

  /* Gain: '<S96>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S88>/Filter'
   *  Gain: '<S86>/Derivative Gain'
   *  Sum: '<S88>/SumD'
   */
  rtb_FilterCoefficient_p = (0.0 * rtb_Sum1 - Micro_mouse_DW.Filter_DSTATE_d) *
    100.0;

  /* Sum: '<Root>/Sum2' incorporates:
   *  DiscreteIntegrator: '<S93>/Integrator'
   *  Gain: '<S1>/Gain'
   *  Sum: '<S102>/Sum'
   */
  rtb_TmpRTBAtTriggeredSubsyste_n = ((rtb_Sum1 +
    Micro_mouse_DW.Integrator_DSTATE_e) + rtb_FilterCoefficient_p) - (real_T)
    Micro_mouse_B.Gain * 4.3368086899420177E-19;

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_TmpRTBAtTriggeredSubsyste_n > 100.0) {
    rtb_TmpRTBAtTriggeredSubsyste_n = 100.0;
  } else if (rtb_TmpRTBAtTriggeredSubsyste_n < 0.0) {
    rtb_TmpRTBAtTriggeredSubsyste_n = 0.0;
  }

  /* MATLABSystem: '<S142>/PWM Output' incorporates:
   *  Saturate: '<Root>/Saturation1'
   */
  setDutyCycleInPercentageChannel1(Micro_mouse_DW.obj_j.TimerHandle,
    rtb_TmpRTBAtTriggeredSubsyste_n);

  /* Outport: '<Root>/position1' */
  Micro_mouse_Y.position1 = Micro_mouse_B.Ratio_l;

  /* MATLABSystem: '<S122>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (Micro_mouse_ConstB.NOT) {
    i = 4096;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 4096U);

  /* End of MATLABSystem: '<S122>/Digital Port Write' */

  /* MATLABSystem: '<S140>/Digital Port Write' */
  portNameLoc = GPIOA;
  LL_GPIO_SetOutputPin(portNameLoc, 0U);
  LL_GPIO_ResetOutputPin(portNameLoc, 2048U);

  /* Update for DiscreteIntegrator: '<S41>/Integrator' */
  Micro_mouse_DW.Integrator_DSTATE += 0.01 * rtb_TmpRTBAtTriggeredSubsystemO;

  /* Update for DiscreteIntegrator: '<S36>/Filter' */
  Micro_mouse_DW.Filter_DSTATE += 0.01 * rtb_FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S93>/Integrator' */
  Micro_mouse_DW.Integrator_DSTATE_e += 0.01 * rtb_Sum1;

  /* Update for DiscreteIntegrator: '<S88>/Filter' */
  Micro_mouse_DW.Filter_DSTATE_d += 0.01 * rtb_FilterCoefficient_p;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Micro_mouse_M->Timing.taskTime0 =
    ((time_T)(++Micro_mouse_M->Timing.clockTick0)) *
    Micro_mouse_M->Timing.stepSize0;
}

/* Model initialize function */
void Micro_mouse_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Micro_mouse_M, -1);
  Micro_mouse_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Micro_mouse_M->Sizes.checksums[0] = (3351052504U);
  Micro_mouse_M->Sizes.checksums[1] = (1518425002U);
  Micro_mouse_M->Sizes.checksums[2] = (1574309191U);
  Micro_mouse_M->Sizes.checksums[3] = (2489898830U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[14];
    Micro_mouse_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_a;
    systemRan[5] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_a;
    systemRan[6] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_a;
    systemRan[7] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_a;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Micro_mouse_M->extModeInfo,
      &Micro_mouse_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Micro_mouse_M->extModeInfo,
                        Micro_mouse_M->Sizes.checksums);
    rteiSetTPtr(Micro_mouse_M->extModeInfo, rtmGetTPtr(Micro_mouse_M));
  }

  /* Start for MATLABSystem: '<S113>/Analog to Digital Converter' */
  Micro_mouse_DW.obj.isInitialized = 0;
  Micro_mouse_DW.obj.matlabCodegenIsDeleted = false;
  Micro_mouse_SystemCore_setup(&Micro_mouse_DW.obj);

  /* Start for MATLABSystem: '<S124>/PWM Output' */
  Micro_mouse_DW.obj_g.matlabCodegenIsDeleted = false;
  Micro_mouse_DW.obj_g.isSetupComplete = false;
  Micro_mouse_DW.obj_g.isInitialized = 1;
  Micro_mouse_PWMOutput_setupImpl(&Micro_mouse_DW.obj_g);
  Micro_mouse_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S142>/PWM Output' */
  Micro_mouse_DW.obj_j.matlabCodegenIsDeleted = false;
  Micro_mouse_DW.obj_j.isSetupComplete = false;
  Micro_mouse_DW.obj_j.isInitialized = 1;
  Micro_mou_PWMOutput_setupImpl_c(&Micro_mouse_DW.obj_j);
  Micro_mouse_DW.obj_j.isSetupComplete = true;

  /* Enable for S-Function (HardwareInterrupt_sfun): '<S120>/Hardware Interrupt' incorporates:
   *  SubSystem: '<S5>/Triggered Subsystem'
   */

  /* Enable for function-call system: '<S5>/Triggered Subsystem' */
  Micro_mouse_M->Timing.clockTick1 = Micro_mouse_M->Timing.clockTick0;
  Micro_mouse_DW.TriggeredSubsystem_RESET_ELAP_c = true;

  /* Enable for DiscreteIntegrator: '<S118>/Discrete-Time Integrator' */
  Micro_mouse_DW.DiscreteTimeIntegrator_SYSTEM_o = 1U;

  /* End of Enable for S-Function (HardwareInterrupt_sfun): '<S120>/Hardware Interrupt' */

  /* Enable for S-Function (HardwareInterrupt_sfun): '<S138>/Hardware Interrupt' incorporates:
   *  SubSystem: '<S6>/Triggered Subsystem'
   */

  /* Enable for function-call system: '<S6>/Triggered Subsystem' */
  Micro_mouse_M->Timing.clockTick2 = Micro_mouse_M->Timing.clockTick0;
  Micro_mouse_DW.TriggeredSubsystem_RESET_ELAPS_ = true;

  /* Enable for DiscreteIntegrator: '<S136>/Discrete-Time Integrator' */
  Micro_mouse_DW.DiscreteTimeIntegrator_SYSTEM_E = 1U;

  /* End of Enable for S-Function (HardwareInterrupt_sfun): '<S138>/Hardware Interrupt' */
}

/* Model terminate function */
void Micro_mouse_terminate(void)
{
  /* Terminate for MATLABSystem: '<S113>/Analog to Digital Converter' */
  if (!Micro_mouse_DW.obj.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj.isInitialized == 1) &&
        Micro_mouse_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(Micro_mouse_DW.obj.ADCHandle, ADC_DMA_INTERRUPT_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S113>/Analog to Digital Converter' */
  /* Terminate for MATLABSystem: '<S124>/PWM Output' */
  if (!Micro_mouse_DW.obj_g.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj_g.isInitialized == 1) &&
        Micro_mouse_DW.obj_g.isSetupComplete) {
      disableCounter(Micro_mouse_DW.obj_g.TimerHandle);
      disableTimerInterrupts(Micro_mouse_DW.obj_g.TimerHandle, 0);
      disableTimerChannel1(Micro_mouse_DW.obj_g.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S124>/PWM Output' */
  /* Terminate for MATLABSystem: '<S142>/PWM Output' */
  if (!Micro_mouse_DW.obj_j.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj_j.isInitialized == 1) &&
        Micro_mouse_DW.obj_j.isSetupComplete) {
      disableCounter(Micro_mouse_DW.obj_j.TimerHandle);
      disableTimerInterrupts(Micro_mouse_DW.obj_j.TimerHandle, 0);
      disableTimerChannel1(Micro_mouse_DW.obj_j.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S142>/PWM Output' */
}

void Micro_mouse_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(24,&EXTI3_IRQHandler,2);
  MW_NVIC_EnableIRQ(24);

  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(21,&EXTI0_IRQHandler,2);
  MW_NVIC_EnableIRQ(21);
}

/* Hardware Interrupt Block: '<S120>/Hardware Interrupt' */
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
        srClearBC(Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_a);

        /* S-Function (HardwareInterrupt_sfun): '<S120>/Hardware Interrupt' */

        /* Output and update for function-call system: '<S5>/Triggered Subsystem' */
        {
          uint32_T TriggeredSubsystem_ELAPS_T_n;
          uint32_T pinReadLoc;
          Micro_mouse_M->Timing.clockTick1 = Micro_mouse_M->Timing.clockTick0;
          if (Micro_mouse_DW.TriggeredSubsystem_RESET_ELAP_c) {
            TriggeredSubsystem_ELAPS_T_n = 0U;
          } else {
            TriggeredSubsystem_ELAPS_T_n = Micro_mouse_M->Timing.clockTick1 -
              Micro_mouse_DW.TriggeredSubsystem_PREV_T_c;
          }

          Micro_mouse_DW.TriggeredSubsystem_PREV_T_c =
            Micro_mouse_M->Timing.clockTick1;
          Micro_mouse_DW.TriggeredSubsystem_RESET_ELAP_c = false;

          /* DiscreteIntegrator: '<S118>/Discrete-Time Integrator' */
          if (Micro_mouse_DW.DiscreteTimeIntegrator_SYSTEM_o == 0) {
            /* DiscreteIntegrator: '<S118>/Discrete-Time Integrator' */
            Micro_mouse_DW.DiscreteTimeIntegrator_DSTATE_g += 0.01 * (real_T)
              TriggeredSubsystem_ELAPS_T_n *
              Micro_mouse_DW.DiscreteTimeIntegrator_PREV_U_p;
          }

          /* End of DiscreteIntegrator: '<S118>/Discrete-Time Integrator' */

          /* SignalConversion generated from: '<S118>/Position' */
          Micro_mouse_B.OutportBufferForPosition_a =
            Micro_mouse_DW.DiscreteTimeIntegrator_DSTATE_g;

          /* MATLABSystem: '<S129>/Digital Port Read' */
          TriggeredSubsystem_ELAPS_T_n = LL_GPIO_ReadInputPort(GPIOB);

          /* MATLABSystem: '<S131>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* Update for DiscreteIntegrator: '<S118>/Discrete-Time Integrator' */
          Micro_mouse_DW.DiscreteTimeIntegrator_SYSTEM_o = 0U;

          /* MATLAB Function: '<S118>/MATLAB Function' incorporates:
           *  MATLABSystem: '<S129>/Digital Port Read'
           *  MATLABSystem: '<S131>/Digital Port Read'
           * */
          if (((TriggeredSubsystem_ELAPS_T_n & 8U) != 0U) == ((pinReadLoc & 16U)
               != 0U)) {
            /* Update for DiscreteIntegrator: '<S118>/Discrete-Time Integrator' */
            Micro_mouse_DW.DiscreteTimeIntegrator_PREV_U_p = 1.0;
          } else {
            /* Update for DiscreteIntegrator: '<S118>/Discrete-Time Integrator' */
            Micro_mouse_DW.DiscreteTimeIntegrator_PREV_U_p = -1.0;
          }

          /* End of MATLAB Function: '<S118>/MATLAB Function' */
          Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_a = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S120>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((Micro_mouse_M->Timing.clockTick1)
        * 0.01);
      extmodeEvent(1,currentTime);
    }
  }

  __ISB();
  __DSB();
}

/* Hardware Interrupt Block: '<S138>/Hardware Interrupt' */
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
        srClearBC(Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC);

        /* S-Function (HardwareInterrupt_sfun): '<S138>/Hardware Interrupt' */

        /* Output and update for function-call system: '<S6>/Triggered Subsystem' */
        {
          uint32_T TriggeredSubsystem_ELAPS_T;
          uint32_T pinReadLoc;
          Micro_mouse_M->Timing.clockTick2 = Micro_mouse_M->Timing.clockTick0;
          if (Micro_mouse_DW.TriggeredSubsystem_RESET_ELAPS_) {
            TriggeredSubsystem_ELAPS_T = 0U;
          } else {
            TriggeredSubsystem_ELAPS_T = Micro_mouse_M->Timing.clockTick2 -
              Micro_mouse_DW.TriggeredSubsystem_PREV_T;
          }

          Micro_mouse_DW.TriggeredSubsystem_PREV_T =
            Micro_mouse_M->Timing.clockTick2;
          Micro_mouse_DW.TriggeredSubsystem_RESET_ELAPS_ = false;

          /* DiscreteIntegrator: '<S136>/Discrete-Time Integrator' */
          if (Micro_mouse_DW.DiscreteTimeIntegrator_SYSTEM_E == 0) {
            /* DiscreteIntegrator: '<S136>/Discrete-Time Integrator' */
            Micro_mouse_DW.DiscreteTimeIntegrator_DSTATE += 0.01 * (real_T)
              TriggeredSubsystem_ELAPS_T
              * Micro_mouse_DW.DiscreteTimeIntegrator_PREV_U;
          }

          /* End of DiscreteIntegrator: '<S136>/Discrete-Time Integrator' */

          /* SignalConversion generated from: '<S136>/Position' */
          Micro_mouse_B.OutportBufferForPosition =
            Micro_mouse_DW.DiscreteTimeIntegrator_DSTATE;

          /* MATLABSystem: '<S147>/Digital Port Read' */
          TriggeredSubsystem_ELAPS_T = LL_GPIO_ReadInputPort(GPIOB);

          /* MATLABSystem: '<S149>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* Update for DiscreteIntegrator: '<S136>/Discrete-Time Integrator' */
          Micro_mouse_DW.DiscreteTimeIntegrator_SYSTEM_E = 0U;

          /* MATLAB Function: '<S136>/MATLAB Function' incorporates:
           *  MATLABSystem: '<S147>/Digital Port Read'
           *  MATLABSystem: '<S149>/Digital Port Read'
           * */
          if (((TriggeredSubsystem_ELAPS_T & 1U) != 0U) == ((pinReadLoc & 2U) !=
               0U)) {
            /* Update for DiscreteIntegrator: '<S136>/Discrete-Time Integrator' */
            Micro_mouse_DW.DiscreteTimeIntegrator_PREV_U = -1.0;
          } else {
            /* Update for DiscreteIntegrator: '<S136>/Discrete-Time Integrator' */
            Micro_mouse_DW.DiscreteTimeIntegrator_PREV_U = 1.0;
          }

          /* End of MATLAB Function: '<S136>/MATLAB Function' */
          Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S138>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((Micro_mouse_M->Timing.clockTick2)
        * 0.01);
      extmodeEvent(2,currentTime);
    }
  }

  __ISB();
  __DSB();
}

void Micro_mouse_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(24);
  MW_NVIC_DisableIRQ(21);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
