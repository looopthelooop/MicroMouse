/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse.c
 *
 * Code generated for Simulink model 'Micro_mouse'.
 *
 * Model version                  : 1.76
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Fri Jun  6 13:51:01 2025
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
#include <math.h>
#include "stm_timer_ll.h"
#include "stm_adc_ll.h"
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
B_Micro_mouse_T Micro_mouse_B;

/* Block states (default storage) */
DW_Micro_mouse_T Micro_mouse_DW;

/* Real-time model */
static RT_MODEL_Micro_mouse_T Micro_mouse_M_;
RT_MODEL_Micro_mouse_T *const Micro_mouse_M = &Micro_mouse_M_;

/* Forward declaration for local functions */
static void Micro_mouse_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);
static void Micro_mou_PWMOutput_setupImpl_c(stm32cube_blocks_PWMOutput_Mi_T *obj);
static void Micro_mouse_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Mi_T *obj);
static void Micro_mouse_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S155>/Analog to Digital Converter' */
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

static void Micro_mou_PWMOutput_setupImpl_c(stm32cube_blocks_PWMOutput_Mi_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S145>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S145>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S145>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void Micro_mouse_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Mi_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S128>/PWM Output' */
  b.PeripheralPtr = TIM16;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S128>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S128>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

/* Model step function */
void Micro_mouse_step(void)
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_FilterCoefficient;
  real_T rtb_FilterCoefficient_l;
  real_T rtb_Integrator;
  real_T rtb_Integrator_l;
  real_T rtb_Saturation;
  real_T rtb_TmpRTBAtTriggeredSubsyste_n;
  real_T rtb_TmpRTBAtTriggeredSubsystemO;
  int32_T rtb_PulseGenerator;
  uint16_T tmp[5];

  /* MATLABSystem: '<S155>/Analog to Digital Converter' */
  regularReadADCDMA(Micro_mouse_DW.obj.ADCHandle, ADC_TRIGGER_AND_READ, &tmp[0]);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = ((Micro_mouse_DW.clockTickCounter < 50) &&
                        (Micro_mouse_DW.clockTickCounter >= 0));
  if (Micro_mouse_DW.clockTickCounter >= 99) {
    Micro_mouse_DW.clockTickCounter = 0;
  } else {
    Micro_mouse_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<S6>/Digital Port Write' */
  portNameLoc = GPIOA;
  rtb_PulseGenerator = (rtb_PulseGenerator != 0);
  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)rtb_PulseGenerator);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)rtb_PulseGenerator & 1U);

  /* RateTransition generated from: '<S14>/Triggered Subsystem' */
  rtb_TmpRTBAtTriggeredSubsystemO = Micro_mouse_B.UnitDelay;

  /* Gain: '<S14>/Ratio' */
  rtb_Integrator = 0.015259164317436139 * rtb_TmpRTBAtTriggeredSubsystemO;

  /* SampleTimeMath: '<S9>/TSamp'
   *
   * About '<S9>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TmpRTBAtTriggeredSubsystemO = rtb_Integrator * 50.0;

  /* Sum: '<S3>/Sum' incorporates:
   *  Constant: '<S3>/Constant'
   *  Sum: '<S3>/Sum1'
   *  Sum: '<S9>/Diff'
   *  UnitDelay: '<S9>/UD'
   *
   * Block description for '<S9>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S9>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Integrator = (100.0 - rtb_Integrator) - (rtb_TmpRTBAtTriggeredSubsystemO -
    Micro_mouse_DW.UD_DSTATE);

  /* Gain: '<S52>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S44>/Filter'
   *  Gain: '<S42>/Derivative Gain'
   *  Sum: '<S44>/SumD'
   */
  rtb_FilterCoefficient = (0.0 * rtb_Integrator - Micro_mouse_DW.Filter_DSTATE) *
    100.0;

  /* Sum: '<S58>/Sum' incorporates:
   *  DiscreteIntegrator: '<S49>/Integrator'
   *  Gain: '<S54>/Proportional Gain'
   */
  rtb_Integrator_l = (5.0 * rtb_Integrator + Micro_mouse_DW.Integrator_DSTATE) +
    rtb_FilterCoefficient;

  /* Saturate: '<S3>/Saturation1' */
  if (rtb_Integrator_l > 99.0) {
    rtb_Integrator_l = 99.0;
  } else if (rtb_Integrator_l < -99.0) {
    rtb_Integrator_l = -99.0;
  }

  /* End of Saturate: '<S3>/Saturation1' */

  /* MATLABSystem: '<S143>/Digital Port Write' incorporates:
   *  Constant: '<S7>/Constant'
   *  RelationalOperator: '<S7>/Compare'
   */
  portNameLoc = GPIOA;
  if (rtb_Integrator_l > 0.0) {
    rtb_PulseGenerator = 2048;
  } else {
    rtb_PulseGenerator = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)rtb_PulseGenerator);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)rtb_PulseGenerator & 2048U);

  /* End of MATLABSystem: '<S143>/Digital Port Write' */

  /* MATLABSystem: '<S145>/PWM Output' incorporates:
   *  Abs: '<S3>/Abs1'
   */
  setDutyCycleInPercentageChannel1(Micro_mouse_DW.obj_e.TimerHandle, fabs
    (rtb_Integrator_l));

  /* RateTransition generated from: '<S13>/Triggered Subsystem' */
  rtb_TmpRTBAtTriggeredSubsyste_n = Micro_mouse_B.UnitDelay_n;

  /* Gain: '<S13>/Ratio' */
  rtb_Integrator_l = 0.015259164317436139 * rtb_TmpRTBAtTriggeredSubsyste_n;

  /* SampleTimeMath: '<S10>/TSamp'
   *
   * About '<S10>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TmpRTBAtTriggeredSubsyste_n = rtb_Integrator_l * 50.0;

  /* Sum: '<S3>/Sum2' incorporates:
   *  Constant: '<S3>/Constant'
   *  Sum: '<S10>/Diff'
   *  Sum: '<S3>/Sum3'
   *  UnitDelay: '<S10>/UD'
   *
   * Block description for '<S10>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S10>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Integrator_l = (100.0 - rtb_Integrator_l) -
    (rtb_TmpRTBAtTriggeredSubsyste_n - Micro_mouse_DW.UD_DSTATE_b);

  /* Gain: '<S104>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S96>/Filter'
   *  Gain: '<S94>/Derivative Gain'
   *  Sum: '<S96>/SumD'
   */
  rtb_FilterCoefficient_l = (0.0 * rtb_Integrator_l -
    Micro_mouse_DW.Filter_DSTATE_c) * 100.0;

  /* Sum: '<S110>/Sum' incorporates:
   *  DiscreteIntegrator: '<S101>/Integrator'
   *  Gain: '<S106>/Proportional Gain'
   */
  rtb_Saturation = (5.0 * rtb_Integrator_l + Micro_mouse_DW.Integrator_DSTATE_k)
    + rtb_FilterCoefficient_l;

  /* Saturate: '<S3>/Saturation' */
  if (rtb_Saturation > 100.0) {
    rtb_Saturation = 100.0;
  } else if (rtb_Saturation < -100.0) {
    rtb_Saturation = -100.0;
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* RelationalOperator: '<S8>/Compare' incorporates:
   *  Constant: '<S8>/Constant'
   */
  Micro_mouse_B.Compare = (rtb_Saturation < 0.0);

  /* MATLABSystem: '<S126>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (Micro_mouse_B.Compare) {
    rtb_PulseGenerator = 4096;
  } else {
    rtb_PulseGenerator = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)rtb_PulseGenerator);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)rtb_PulseGenerator & 4096U);

  /* End of MATLABSystem: '<S126>/Digital Port Write' */
  /* Abs: '<S3>/Abs' */
  Micro_mouse_B.Abs = fabs(rtb_Saturation);

  /* MATLABSystem: '<S128>/PWM Output' */
  setDutyCycleInPercentageChannel1(Micro_mouse_DW.obj_d.TimerHandle,
    Micro_mouse_B.Abs);

  /* Update for UnitDelay: '<S9>/UD'
   *
   * Block description for '<S9>/UD':
   *
   *  Store in Global RAM
   */
  Micro_mouse_DW.UD_DSTATE = rtb_TmpRTBAtTriggeredSubsystemO;

  /* Update for DiscreteIntegrator: '<S49>/Integrator' */
  Micro_mouse_DW.Integrator_DSTATE += 0.02 * rtb_Integrator;

  /* Update for DiscreteIntegrator: '<S44>/Filter' */
  Micro_mouse_DW.Filter_DSTATE += 0.02 * rtb_FilterCoefficient;

  /* Update for UnitDelay: '<S10>/UD'
   *
   * Block description for '<S10>/UD':
   *
   *  Store in Global RAM
   */
  Micro_mouse_DW.UD_DSTATE_b = rtb_TmpRTBAtTriggeredSubsyste_n;

  /* Update for DiscreteIntegrator: '<S101>/Integrator' */
  Micro_mouse_DW.Integrator_DSTATE_k += 0.02 * rtb_Integrator_l;

  /* Update for DiscreteIntegrator: '<S96>/Filter' */
  Micro_mouse_DW.Filter_DSTATE_c += 0.02 * rtb_FilterCoefficient_l;

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
  Micro_mouse_M->Timing.stepSize0 = 0.02;

  /* External mode info */
  Micro_mouse_M->Sizes.checksums[0] = (2330080268U);
  Micro_mouse_M->Sizes.checksums[1] = (1564572150U);
  Micro_mouse_M->Sizes.checksums[2] = (29758318U);
  Micro_mouse_M->Sizes.checksums[3] = (3497453620U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[15];
    Micro_mouse_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_l;
    systemRan[5] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_l;
    systemRan[6] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_l;
    systemRan[7] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_l;
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
    systemRan[14] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Micro_mouse_M->extModeInfo,
      &Micro_mouse_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Micro_mouse_M->extModeInfo,
                        Micro_mouse_M->Sizes.checksums);
    rteiSetTPtr(Micro_mouse_M->extModeInfo, rtmGetTPtr(Micro_mouse_M));
  }

  /* Start for MATLABSystem: '<S155>/Analog to Digital Converter' */
  Micro_mouse_DW.obj.isInitialized = 0;
  Micro_mouse_DW.obj.matlabCodegenIsDeleted = false;
  Micro_mouse_SystemCore_setup(&Micro_mouse_DW.obj);

  /* Start for MATLABSystem: '<S145>/PWM Output' */
  Micro_mouse_DW.obj_e.matlabCodegenIsDeleted = false;
  Micro_mouse_DW.obj_e.isSetupComplete = false;
  Micro_mouse_DW.obj_e.isInitialized = 1;
  Micro_mou_PWMOutput_setupImpl_c(&Micro_mouse_DW.obj_e);
  Micro_mouse_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S128>/PWM Output' */
  Micro_mouse_DW.obj_d.matlabCodegenIsDeleted = false;
  Micro_mouse_DW.obj_d.isSetupComplete = false;
  Micro_mouse_DW.obj_d.isInitialized = 1;
  Micro_mouse_PWMOutput_setupImpl(&Micro_mouse_DW.obj_d);
  Micro_mouse_DW.obj_d.isSetupComplete = true;
}

/* Model terminate function */
void Micro_mouse_terminate(void)
{
  /* Terminate for MATLABSystem: '<S155>/Analog to Digital Converter' */
  if (!Micro_mouse_DW.obj.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj.isInitialized == 1) &&
        Micro_mouse_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(Micro_mouse_DW.obj.ADCHandle, ADC_DMA_INTERRUPT_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S155>/Analog to Digital Converter' */
  /* Terminate for MATLABSystem: '<S145>/PWM Output' */
  if (!Micro_mouse_DW.obj_e.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj_e.isInitialized == 1) &&
        Micro_mouse_DW.obj_e.isSetupComplete) {
      disableCounter(Micro_mouse_DW.obj_e.TimerHandle);
      disableTimerInterrupts(Micro_mouse_DW.obj_e.TimerHandle, 0);
      disableTimerChannel1(Micro_mouse_DW.obj_e.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S145>/PWM Output' */
  /* Terminate for MATLABSystem: '<S128>/PWM Output' */
  if (!Micro_mouse_DW.obj_d.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj_d.isInitialized == 1) &&
        Micro_mouse_DW.obj_d.isSetupComplete) {
      disableCounter(Micro_mouse_DW.obj_d.TimerHandle);
      disableTimerInterrupts(Micro_mouse_DW.obj_d.TimerHandle, 0);
      disableTimerChannel1(Micro_mouse_DW.obj_d.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S128>/PWM Output' */
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

/* Hardware Interrupt Block: '<S124>/Hardware Interrupt' */
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
        srClearBC(Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_l);

        /* S-Function (HardwareInterrupt_sfun): '<S124>/Hardware Interrupt' */

        /* Output and update for function-call system: '<S13>/Triggered Subsystem' */
        {
          int32_T tmp;
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_p;
          Micro_mouse_M->Timing.clockTick1 = Micro_mouse_M->Timing.clockTick0;

          /* MATLABSystem: '<S133>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* MATLABSystem: '<S135>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOB);

          /* UnitDelay: '<S122>/Unit Delay' */
          Micro_mouse_B.UnitDelay_n = Micro_mouse_DW.UnitDelay_DSTATE_o;

          /* MATLAB Function: '<S122>/MATLAB Function' incorporates:
           *  MATLABSystem: '<S133>/Digital Port Read'
           *  MATLABSystem: '<S135>/Digital Port Read'
           * */
          if (((pinReadLoc & 8U) != 0U) == ((pinReadLoc_p & 16U) != 0U)) {
            tmp = 1;
          } else {
            tmp = -1;
          }

          /* Update for UnitDelay: '<S122>/Unit Delay' incorporates:
           *  MATLAB Function: '<S122>/MATLAB Function'
           *  Sum: '<S122>/Sum'
           */
          Micro_mouse_DW.UnitDelay_DSTATE_o = (real_T)tmp +
            Micro_mouse_B.UnitDelay_n;
          Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_l = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S124>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((Micro_mouse_M->Timing.clockTick1)
        * 0.02);
      extmodeEvent(1,currentTime);
    }
  }

  __ISB();
  __DSB();
}

/* Hardware Interrupt Block: '<S141>/Hardware Interrupt' */
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

        /* S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' */

        /* Output and update for function-call system: '<S14>/Triggered Subsystem' */
        {
          int32_T tmp;
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_p;
          Micro_mouse_M->Timing.clockTick2 = Micro_mouse_M->Timing.clockTick0;

          /* MATLABSystem: '<S150>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* MATLABSystem: '<S152>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOB);

          /* UnitDelay: '<S139>/Unit Delay' */
          Micro_mouse_B.UnitDelay = Micro_mouse_DW.UnitDelay_DSTATE;

          /* MATLAB Function: '<S139>/MATLAB Function' incorporates:
           *  MATLABSystem: '<S150>/Digital Port Read'
           *  MATLABSystem: '<S152>/Digital Port Read'
           * */
          if (((pinReadLoc & 1U) != 0U) == ((pinReadLoc_p & 2U) != 0U)) {
            tmp = -1;
          } else {
            tmp = 1;
          }

          /* Update for UnitDelay: '<S139>/Unit Delay' incorporates:
           *  MATLAB Function: '<S139>/MATLAB Function'
           *  Sum: '<S139>/Sum'
           */
          Micro_mouse_DW.UnitDelay_DSTATE = (real_T)tmp +
            Micro_mouse_B.UnitDelay;
          Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((Micro_mouse_M->Timing.clockTick2)
        * 0.02);
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
