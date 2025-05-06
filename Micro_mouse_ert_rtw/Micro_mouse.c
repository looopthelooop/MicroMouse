/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse.c
 *
 * Code generated for Simulink model 'Micro_mouse'.
 *
 * Model version                  : 1.42
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue May  6 10:23:15 2025
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
#include "stm_adc_ll.h"
#include "stm_timer_ll.h"
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
B_Micro_mouse_T Micro_mouse_B;

/* Block states (default storage) */
DW_Micro_mouse_T Micro_mouse_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Micro_mouse_T Micro_mouse_Y;

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

  /* Start for MATLABSystem: '<S13>/Analog to Digital Converter' */
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

  /* Start for MATLABSystem: '<S40>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S40>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S40>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void Micro_mouse_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Mi_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S23>/PWM Output' */
  b.PeripheralPtr = TIM16;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S23>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S23>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

/* Model step function */
void Micro_mouse_step(void)
{
  /* local block i/o variables */
  real_T rtb_TSamp;
  real_T rtb_TSamp_g;
  real_T rtb_TSamp_j;
  real_T rtb_TSamp_b;
  GPIO_TypeDef * portNameLoc;
  real_T rtb_SineWave;
  int32_T i;
  uint32_T rtb_Gain2[5];
  uint16_T rtb_AnalogtoDigitalConverter_0[5];

  /* MATLABSystem: '<S13>/Analog to Digital Converter' */
  regularReadADCDMA(Micro_mouse_DW.obj.ADCHandle, ADC_TRIGGER_AND_READ,
                    &rtb_AnalogtoDigitalConverter_0[0]);

  /* Gain: '<S8>/Gain2' incorporates:
   *  MATLABSystem: '<S13>/Analog to Digital Converter'
   */
  for (i = 0; i < 5; i++) {
    rtb_Gain2[i] = 54080U * rtb_AnalogtoDigitalConverter_0[i];
  }

  /* End of Gain: '<S8>/Gain2' */

  /* SignalConversion: '<S8>/Signal Conversion4' */
  Micro_mouse_B.SignalConversion4 = rtb_Gain2[0];

  /* SignalConversion: '<S8>/Signal Conversion' */
  Micro_mouse_B.SignalConversion = rtb_Gain2[4];

  /* Sum: '<S1>/Sum2' incorporates:
   *  SignalConversion: '<S8>/Signal Conversion'
   *  SignalConversion: '<S8>/Signal Conversion4'
   */
  Micro_mouse_B.Sum2 = Micro_mouse_B.SignalConversion4 -
    Micro_mouse_B.SignalConversion;

  /* Gain: '<S1>/Gain' incorporates:
   *  Sum: '<S1>/Sum2'
   */
  Micro_mouse_B.Gain = 3435973837ULL * Micro_mouse_B.Sum2;

  /* Gain: '<S10>/Ratio' incorporates:
   *  RateTransition generated from: '<S10>/Triggered Subsystem'
   */
  Micro_mouse_B.Ratio = 0.00015259164317436139 * Micro_mouse_B.UnitDelay;

  /* SampleTimeMath: '<S4>/TSamp'
   *
   * About '<S4>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp = Micro_mouse_B.Ratio * 100.0;

  /* Sum: '<S4>/Diff' incorporates:
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
  Micro_mouse_B.Diff = rtb_TSamp - Micro_mouse_DW.UD_DSTATE;

  /* Sin: '<Root>/Sine Wave' */
  rtb_SineWave = sin(0.5 * Micro_mouse_M->Timing.t[0]) * 20.0;

  /* Sum: '<Root>/Sum1' */
  Micro_mouse_B.Sum1 = rtb_SineWave - Micro_mouse_B.Ratio;

  /* SampleTimeMath: '<S5>/TSamp'
   *
   * About '<S5>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp_g = Micro_mouse_B.Sum1 * 100.0;

  /* Sum: '<Root>/Sum' incorporates:
   *  Sum: '<S5>/Diff'
   *  UnitDelay: '<S5>/UD'
   *
   * Block description for '<S5>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S5>/UD':
   *
   *  Store in Global RAM
   */
  Micro_mouse_B.Saturation1 = (rtb_TSamp_g - Micro_mouse_DW.UD_DSTATE_p) -
    Micro_mouse_B.Diff;

  /* Saturate: '<Root>/Saturation1' */
  if (Micro_mouse_B.Saturation1 > 99.0) {
    /* Sum: '<Root>/Sum' incorporates:
     *  Saturate: '<Root>/Saturation1'
     */
    Micro_mouse_B.Saturation1 = 99.0;
  } else if (Micro_mouse_B.Saturation1 < -99.0) {
    /* Sum: '<Root>/Sum' incorporates:
     *  Saturate: '<Root>/Saturation1'
     */
    Micro_mouse_B.Saturation1 = -99.0;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* MATLABSystem: '<S38>/Digital Port Write' incorporates:
   *  Constant: '<S2>/Constant'
   *  RelationalOperator: '<S2>/Compare'
   */
  portNameLoc = GPIOA;
  if (Micro_mouse_B.Saturation1 > 0.0) {
    i = 2048;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 2048U);

  /* End of MATLABSystem: '<S38>/Digital Port Write' */
  /* MATLABSystem: '<S40>/PWM Output' incorporates:
   *  Abs: '<Root>/Abs1'
   */
  setDutyCycleInPercentageChannel1(Micro_mouse_DW.obj_j.TimerHandle, fabs
    (Micro_mouse_B.Saturation1));

  /* Gain: '<S9>/Ratio' incorporates:
   *  RateTransition generated from: '<S9>/Triggered Subsystem'
   */
  Micro_mouse_B.Ratio_p = 0.00015259164317436139 * Micro_mouse_B.UnitDelay_j;

  /* SampleTimeMath: '<S7>/TSamp' incorporates:
   *  Sum: '<Root>/Sum3'
   *
   * About '<S7>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp_j = (rtb_SineWave - Micro_mouse_B.Ratio_p) * 100.0;

  /* SampleTimeMath: '<S6>/TSamp'
   *
   * About '<S6>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp_b = Micro_mouse_B.Ratio_p * 100.0;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Sum: '<S6>/Diff'
   *  Sum: '<S7>/Diff'
   *  UnitDelay: '<S6>/UD'
   *  UnitDelay: '<S7>/UD'
   *
   * Block description for '<S6>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S7>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S6>/UD':
   *
   *  Store in Global RAM
   *
   * Block description for '<S7>/UD':
   *
   *  Store in Global RAM
   */
  rtb_SineWave = (rtb_TSamp_j - Micro_mouse_DW.UD_DSTATE_e) - (rtb_TSamp_b -
    Micro_mouse_DW.UD_DSTATE_ee);

  /* Saturate: '<Root>/Saturation' */
  if (rtb_SineWave > 100.0) {
    rtb_SineWave = 100.0;
  } else if (rtb_SineWave < -100.0) {
    rtb_SineWave = -100.0;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* MATLABSystem: '<S21>/Digital Port Write' incorporates:
   *  Constant: '<S3>/Constant'
   *  RelationalOperator: '<S3>/Compare'
   */
  portNameLoc = GPIOA;
  if (rtb_SineWave < 0.0) {
    i = 4096;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 4096U);

  /* End of MATLABSystem: '<S21>/Digital Port Write' */

  /* MATLABSystem: '<S23>/PWM Output' incorporates:
   *  Abs: '<Root>/Abs'
   */
  setDutyCycleInPercentageChannel1(Micro_mouse_DW.obj_g.TimerHandle, fabs
    (rtb_SineWave));

  /* Outport: '<Root>/position' */
  Micro_mouse_Y.position = Micro_mouse_B.Ratio_p;

  /* Outport: '<Root>/position1' */
  Micro_mouse_Y.position1 = Micro_mouse_B.Ratio;

  /* Update for UnitDelay: '<S4>/UD'
   *
   * Block description for '<S4>/UD':
   *
   *  Store in Global RAM
   */
  Micro_mouse_DW.UD_DSTATE = rtb_TSamp;

  /* Update for UnitDelay: '<S5>/UD'
   *
   * Block description for '<S5>/UD':
   *
   *  Store in Global RAM
   */
  Micro_mouse_DW.UD_DSTATE_p = rtb_TSamp_g;

  /* Update for UnitDelay: '<S7>/UD'
   *
   * Block description for '<S7>/UD':
   *
   *  Store in Global RAM
   */
  Micro_mouse_DW.UD_DSTATE_e = rtb_TSamp_j;

  /* Update for UnitDelay: '<S6>/UD'
   *
   * Block description for '<S6>/UD':
   *
   *  Store in Global RAM
   */
  Micro_mouse_DW.UD_DSTATE_ee = rtb_TSamp_b;

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
  Micro_mouse_M->Sizes.checksums[0] = (1606339285U);
  Micro_mouse_M->Sizes.checksums[1] = (1471805835U);
  Micro_mouse_M->Sizes.checksums[2] = (3101760234U);
  Micro_mouse_M->Sizes.checksums[3] = (2418836257U);

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
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_j;
    systemRan[5] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_j;
    systemRan[6] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_j;
    systemRan[7] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_j;
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

  /* Start for MATLABSystem: '<S13>/Analog to Digital Converter' */
  Micro_mouse_DW.obj.isInitialized = 0;
  Micro_mouse_DW.obj.matlabCodegenIsDeleted = false;
  Micro_mouse_SystemCore_setup(&Micro_mouse_DW.obj);

  /* Start for MATLABSystem: '<S40>/PWM Output' */
  Micro_mouse_DW.obj_j.matlabCodegenIsDeleted = false;
  Micro_mouse_DW.obj_j.isSetupComplete = false;
  Micro_mouse_DW.obj_j.isInitialized = 1;
  Micro_mou_PWMOutput_setupImpl_c(&Micro_mouse_DW.obj_j);
  Micro_mouse_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S23>/PWM Output' */
  Micro_mouse_DW.obj_g.matlabCodegenIsDeleted = false;
  Micro_mouse_DW.obj_g.isSetupComplete = false;
  Micro_mouse_DW.obj_g.isInitialized = 1;
  Micro_mouse_PWMOutput_setupImpl(&Micro_mouse_DW.obj_g);
  Micro_mouse_DW.obj_g.isSetupComplete = true;
}

/* Model terminate function */
void Micro_mouse_terminate(void)
{
  /* Terminate for MATLABSystem: '<S13>/Analog to Digital Converter' */
  if (!Micro_mouse_DW.obj.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj.isInitialized == 1) &&
        Micro_mouse_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(Micro_mouse_DW.obj.ADCHandle, ADC_DMA_INTERRUPT_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S13>/Analog to Digital Converter' */
  /* Terminate for MATLABSystem: '<S40>/PWM Output' */
  if (!Micro_mouse_DW.obj_j.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj_j.isInitialized == 1) &&
        Micro_mouse_DW.obj_j.isSetupComplete) {
      disableCounter(Micro_mouse_DW.obj_j.TimerHandle);
      disableTimerInterrupts(Micro_mouse_DW.obj_j.TimerHandle, 0);
      disableTimerChannel1(Micro_mouse_DW.obj_j.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S40>/PWM Output' */
  /* Terminate for MATLABSystem: '<S23>/PWM Output' */
  if (!Micro_mouse_DW.obj_g.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj_g.isInitialized == 1) &&
        Micro_mouse_DW.obj_g.isSetupComplete) {
      disableCounter(Micro_mouse_DW.obj_g.TimerHandle);
      disableTimerInterrupts(Micro_mouse_DW.obj_g.TimerHandle, 0);
      disableTimerChannel1(Micro_mouse_DW.obj_g.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S23>/PWM Output' */
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

/* Hardware Interrupt Block: '<S19>/Hardware Interrupt' */
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
        srClearBC(Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_j);

        /* S-Function (HardwareInterrupt_sfun): '<S19>/Hardware Interrupt' */

        /* Output and update for function-call system: '<S9>/Triggered Subsystem' */
        {
          int32_T tmp;
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_p;
          Micro_mouse_M->Timing.clockTick2 = Micro_mouse_M->Timing.clockTick0;

          /* MATLABSystem: '<S28>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* MATLABSystem: '<S30>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOB);

          /* UnitDelay: '<S17>/Unit Delay' */
          Micro_mouse_B.UnitDelay_j = Micro_mouse_DW.UnitDelay_DSTATE_e;

          /* MATLAB Function: '<S17>/MATLAB Function' incorporates:
           *  MATLABSystem: '<S28>/Digital Port Read'
           *  MATLABSystem: '<S30>/Digital Port Read'
           * */
          if (((pinReadLoc & 8U) != 0U) == ((pinReadLoc_p & 16U) != 0U)) {
            tmp = 1;
          } else {
            tmp = -1;
          }

          /* Update for UnitDelay: '<S17>/Unit Delay' incorporates:
           *  MATLAB Function: '<S17>/MATLAB Function'
           *  Sum: '<S17>/Sum'
           */
          Micro_mouse_DW.UnitDelay_DSTATE_e = (real_T)tmp +
            Micro_mouse_B.UnitDelay_j;
          Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_j = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S19>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((Micro_mouse_M->Timing.clockTick2)
        * 0.01);
      extmodeEvent(2,currentTime);
    }
  }

  __ISB();
  __DSB();
}

/* Hardware Interrupt Block: '<S36>/Hardware Interrupt' */
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

        /* S-Function (HardwareInterrupt_sfun): '<S36>/Hardware Interrupt' */

        /* Output and update for function-call system: '<S10>/Triggered Subsystem' */
        {
          int32_T tmp;
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_p;
          Micro_mouse_M->Timing.clockTick3 = Micro_mouse_M->Timing.clockTick0;

          /* MATLABSystem: '<S45>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* MATLABSystem: '<S47>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOB);

          /* UnitDelay: '<S34>/Unit Delay' */
          Micro_mouse_B.UnitDelay = Micro_mouse_DW.UnitDelay_DSTATE;

          /* MATLAB Function: '<S34>/MATLAB Function' incorporates:
           *  MATLABSystem: '<S45>/Digital Port Read'
           *  MATLABSystem: '<S47>/Digital Port Read'
           * */
          if (((pinReadLoc & 1U) != 0U) == ((pinReadLoc_p & 2U) != 0U)) {
            tmp = -1;
          } else {
            tmp = 1;
          }

          /* Update for UnitDelay: '<S34>/Unit Delay' incorporates:
           *  MATLAB Function: '<S34>/MATLAB Function'
           *  Sum: '<S34>/Sum'
           */
          Micro_mouse_DW.UnitDelay_DSTATE = (real_T)tmp +
            Micro_mouse_B.UnitDelay;
          Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S36>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((Micro_mouse_M->Timing.clockTick3)
        * 0.01);
      extmodeEvent(3,currentTime);
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
