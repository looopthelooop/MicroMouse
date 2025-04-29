/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse.c
 *
 * Code generated for Simulink model 'Micro_mouse'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Apr 29 10:29:49 2025
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

  /* Start for MATLABSystem: '<S6>/Analog to Digital Converter' */
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

  /* Start for MATLABSystem: '<S15>/PWM Output' */
  b.PeripheralPtr = TIM16;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S15>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S15>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void Micro_mou_PWMOutput_setupImpl_c(stm32cube_blocks_PWMOutput_Mi_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S26>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S26>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S26>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

/* Model step function */
void Micro_mouse_step(void)
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_TmpRTBAtRatioInport1;
  real_T rtb_Uk1;
  int32_T i;
  uint32_T pinReadLoc;
  uint16_T rtb_AnalogtoDigitalConverter_0[5];

  /* MATLABSystem: '<S6>/Analog to Digital Converter' */
  regularReadADCDMA(Micro_mouse_DW.obj.ADCHandle, ADC_TRIGGER_AND_READ,
                    &rtb_AnalogtoDigitalConverter_0[0]);
  for (i = 0; i < 5; i++) {
    /* Gain: '<Root>/Gain1' incorporates:
     *  MATLABSystem: '<S6>/Analog to Digital Converter'
     */
    Micro_mouse_B.Gain1[i] = 54080U * rtb_AnalogtoDigitalConverter_0[i];
  }

  /* MATLABSystem: '<S11>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);
  Micro_mouse_B.DigitalPortRead_a[0] = ((pinReadLoc & 8U) != 0U);
  Micro_mouse_B.DigitalPortRead_a[1] = ((pinReadLoc & 16U) != 0U);

  /* MATLABSystem: '<S15>/PWM Output' incorporates:
   *  Constant: '<Root>/Constant'
   */
  setDutyCycleInPercentageChannel1(Micro_mouse_DW.obj_jt.TimerHandle, 20.0);

  /* MATLABSystem: '<S26>/PWM Output' incorporates:
   *  Constant: '<Root>/Constant'
   */
  setDutyCycleInPercentageChannel1(Micro_mouse_DW.obj_j.TimerHandle, 20.0);

  /* MATLABSystem: '<S24>/Digital Port Write' */
  portNameLoc = GPIOA;
  LL_GPIO_SetOutputPin(portNameLoc, 2048U);
  LL_GPIO_ResetOutputPin(portNameLoc, 0U);

  /* MATLABSystem: '<S13>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (Micro_mouse_ConstB.NOT) {
    i = 2048;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 2048U);

  /* End of MATLABSystem: '<S13>/Digital Port Write' */

  /* UnitDelay: '<S18>/UD'
   *
   * Block description for '<S18>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Uk1 = Micro_mouse_DW.UD_DSTATE;

  /* RateTransition generated from: '<S4>/Ratio' */
  rtb_TmpRTBAtRatioInport1 = Micro_mouse_B.OutportBufferForPosition;

  /* Gain: '<S4>/Ratio' */
  Micro_mouse_B.Ratio = 0.00071428571428571429 * rtb_TmpRTBAtRatioInport1;

  /* SampleTimeMath: '<S18>/TSamp' incorporates:
   *  UnitDelay: '<S18>/UD'
   *
   * About '<S18>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   *
   * Block description for '<S18>/UD':
   *
   *  Store in Global RAM
   */
  Micro_mouse_DW.UD_DSTATE = Micro_mouse_B.Ratio * 100.0;

  /* Sum: '<S18>/Diff' incorporates:
   *  UnitDelay: '<S18>/UD'
   *
   * Block description for '<S18>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S18>/UD':
   *
   *  Store in Global RAM
   */
  Micro_mouse_B.Diff = Micro_mouse_DW.UD_DSTATE - rtb_Uk1;

  /* RateTransition generated from: '<S4>/Scope1' */
  Micro_mouse_B.TmpRTBAtScope1Inport1 = Micro_mouse_B.OutportBufferForPosition;

  {                                    /* Sample time: [0.01s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((Micro_mouse_M->Timing.clockTick1) * 0.01);

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
  Micro_mouse_M->Timing.t[0] =
    ((time_T)(++Micro_mouse_M->Timing.clockTick0)) *
    Micro_mouse_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Micro_mouse_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Micro_mouse_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Micro_mouse_M->solverInfo,
                          &Micro_mouse_M->Timing.simTimeStep);
    rtsiSetTPtr(&Micro_mouse_M->solverInfo, &rtmGetTPtr(Micro_mouse_M));
    rtsiSetStepSizePtr(&Micro_mouse_M->solverInfo,
                       &Micro_mouse_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Micro_mouse_M->solverInfo, (&rtmGetErrorStatus
      (Micro_mouse_M)));
    rtsiSetRTModelPtr(&Micro_mouse_M->solverInfo, Micro_mouse_M);
  }

  rtsiSetSimTimeStep(&Micro_mouse_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&Micro_mouse_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&Micro_mouse_M->solverInfo, false);
  rtsiSetSolverName(&Micro_mouse_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Micro_mouse_M, &Micro_mouse_M->Timing.tArray[0]);
  rtmSetTFinal(Micro_mouse_M, -1);
  Micro_mouse_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Micro_mouse_M->Sizes.checksums[0] = (1942029958U);
  Micro_mouse_M->Sizes.checksums[1] = (370723985U);
  Micro_mouse_M->Sizes.checksums[2] = (3054472059U);
  Micro_mouse_M->Sizes.checksums[3] = (2454910838U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
    Micro_mouse_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = (sysRanDType *)&Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[8] = (sysRanDType *)&Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[9] = (sysRanDType *)&Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Micro_mouse_M->extModeInfo,
      &Micro_mouse_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Micro_mouse_M->extModeInfo,
                        Micro_mouse_M->Sizes.checksums);
    rteiSetTPtr(Micro_mouse_M->extModeInfo, rtmGetTPtr(Micro_mouse_M));
  }

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' incorporates:
   *  SubSystem: '<S4>/Triggered Subsystem'
   */

  /* System initialize for function-call system: '<S4>/Triggered Subsystem' */
  Micro_mouse_M->Timing.clockTick2 = Micro_mouse_M->Timing.clockTick0;

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' */

  /* Start for MATLABSystem: '<S6>/Analog to Digital Converter' */
  Micro_mouse_DW.obj.isInitialized = 0;
  Micro_mouse_DW.obj.matlabCodegenIsDeleted = false;
  Micro_mouse_SystemCore_setup(&Micro_mouse_DW.obj);

  /* Start for MATLABSystem: '<S15>/PWM Output' */
  Micro_mouse_DW.obj_jt.matlabCodegenIsDeleted = false;
  Micro_mouse_DW.obj_jt.isSetupComplete = false;
  Micro_mouse_DW.obj_jt.isInitialized = 1;
  Micro_mouse_PWMOutput_setupImpl(&Micro_mouse_DW.obj_jt);
  Micro_mouse_DW.obj_jt.isSetupComplete = true;

  /* Start for MATLABSystem: '<S26>/PWM Output' */
  Micro_mouse_DW.obj_j.matlabCodegenIsDeleted = false;
  Micro_mouse_DW.obj_j.isSetupComplete = false;
  Micro_mouse_DW.obj_j.isInitialized = 1;
  Micro_mou_PWMOutput_setupImpl_c(&Micro_mouse_DW.obj_j);
  Micro_mouse_DW.obj_j.isSetupComplete = true;

  /* Enable for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' incorporates:
   *  SubSystem: '<S4>/Triggered Subsystem'
   */

  /* Enable for function-call system: '<S4>/Triggered Subsystem' */
  Micro_mouse_M->Timing.clockTick2 = Micro_mouse_M->Timing.clockTick0;
  Micro_mouse_DW.TriggeredSubsystem_RESET_ELAPS_ = true;

  /* Enable for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
  Micro_mouse_DW.DiscreteTimeIntegrator_SYSTEM_E = 1U;

  /* End of Enable for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' */
}

/* Model terminate function */
void Micro_mouse_terminate(void)
{
  /* Terminate for MATLABSystem: '<S6>/Analog to Digital Converter' */
  if (!Micro_mouse_DW.obj.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj.isInitialized == 1) &&
        Micro_mouse_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(Micro_mouse_DW.obj.ADCHandle, ADC_DMA_INTERRUPT_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Analog to Digital Converter' */
  /* Terminate for MATLABSystem: '<S15>/PWM Output' */
  if (!Micro_mouse_DW.obj_jt.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_jt.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj_jt.isInitialized == 1) &&
        Micro_mouse_DW.obj_jt.isSetupComplete) {
      disableCounter(Micro_mouse_DW.obj_jt.TimerHandle);
      disableTimerInterrupts(Micro_mouse_DW.obj_jt.TimerHandle, 0);
      disableTimerChannel1(Micro_mouse_DW.obj_jt.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S15>/PWM Output' */

  /* Terminate for MATLABSystem: '<S26>/PWM Output' */
  if (!Micro_mouse_DW.obj_j.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj_j.isInitialized == 1) &&
        Micro_mouse_DW.obj_j.isSetupComplete) {
      disableCounter(Micro_mouse_DW.obj_j.TimerHandle);
      disableTimerInterrupts(Micro_mouse_DW.obj_j.TimerHandle, 0);
      disableTimerChannel1(Micro_mouse_DW.obj_j.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S26>/PWM Output' */
}

void Micro_mouse_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(21,&EXTI0_IRQHandler,2);
  MW_NVIC_EnableIRQ(21);
}

/* Hardware Interrupt Block: '<S22>/Hardware Interrupt' */
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

        /* S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' */

        /* Output and update for function-call system: '<S4>/Triggered Subsystem' */
        {
          uint32_T TriggeredSubsystem_ELAPS_T;
          uint32_T pinReadLoc;
          boolean_T rtb_DigitalPortRead;
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

          /* Memory: '<S20>/prevA' */
          Micro_mouse_B.prevA = Micro_mouse_DW.prevA_PreviousInput;

          /* MATLABSystem: '<S31>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* MATLABSystem: '<S31>/Digital Port Read' */
          Micro_mouse_B.DigitalPortRead = ((pinReadLoc & 1U) != 0U);

          /* MATLABSystem: '<S33>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);
          rtb_DigitalPortRead = ((pinReadLoc & 2U) != 0U);

          /* MATLAB Function: '<S20>/MATLAB Function' incorporates:
           *  Memory: '<S20>/PrevB'
           */
          switch ((uint8_T)((((Micro_mouse_B.prevA << 3) +
                              (Micro_mouse_DW.PrevB_PreviousInput << 2)) +
                             (Micro_mouse_B.DigitalPortRead << 1)) +
                            rtb_DigitalPortRead)) {
           case 1U:
            Micro_mouse_B.delta = 1.0;
            break;

           case 7U:
            Micro_mouse_B.delta = 1.0;
            break;

           case 14U:
            Micro_mouse_B.delta = 1.0;
            break;

           case 8U:
            Micro_mouse_B.delta = 1.0;
            break;

           case 2U:
            Micro_mouse_B.delta = -1.0;
            break;

           case 4U:
            Micro_mouse_B.delta = -1.0;
            break;

           case 13U:
            Micro_mouse_B.delta = -1.0;
            break;

           case 11U:
            Micro_mouse_B.delta = -1.0;
            break;

           default:
            Micro_mouse_B.delta = 0.0;
            break;
          }

          /* End of MATLAB Function: '<S20>/MATLAB Function' */
          /* DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
          if (Micro_mouse_DW.DiscreteTimeIntegrator_SYSTEM_E != 0) {
            /* DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
            Micro_mouse_B.DiscreteTimeIntegrator =
              Micro_mouse_DW.DiscreteTimeIntegrator_DSTATE;
          } else {
            /* DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
            Micro_mouse_B.DiscreteTimeIntegrator = 0.01 * (real_T)
              TriggeredSubsystem_ELAPS_T
              * Micro_mouse_DW.DiscreteTimeIntegrator_PREV_U +
              Micro_mouse_DW.DiscreteTimeIntegrator_DSTATE;
          }

          /* End of DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
          /* SignalConversion generated from: '<S20>/Position' */
          Micro_mouse_B.OutportBufferForPosition =
            Micro_mouse_B.DiscreteTimeIntegrator;

          /* Update for Memory: '<S20>/prevA' */
          Micro_mouse_DW.prevA_PreviousInput = Micro_mouse_B.DigitalPortRead;

          /* Update for Memory: '<S20>/PrevB' */
          Micro_mouse_DW.PrevB_PreviousInput = rtb_DigitalPortRead;

          /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
          Micro_mouse_DW.DiscreteTimeIntegrator_SYSTEM_E = 0U;
          Micro_mouse_DW.DiscreteTimeIntegrator_DSTATE =
            Micro_mouse_B.DiscreteTimeIntegrator;
          Micro_mouse_DW.DiscreteTimeIntegrator_PREV_U = Micro_mouse_B.delta;
          Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' */
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
  MW_NVIC_DisableIRQ(21);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
