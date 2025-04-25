/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse.c
 *
 * Code generated for Simulink model 'Micro_mouse'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Fri Apr 25 15:54:46 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Micro_mouse.h"
#include "Micro_mouse_types.h"
#include "rtwtypes.h"
#include "stm_adc_ll.h"
#include "stm_timer_ll.h"
#include "Micro_mouse_private.h"

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

  /* Start for MATLABSystem: '<S24>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S24>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S24>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

/* Model step function */
void Micro_mouse_step(void)
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_Output;
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

  /* MATLABSystem: '<S20>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);
  Micro_mouse_B.DigitalPortRead[0] = ((pinReadLoc & 1U) != 0U);
  Micro_mouse_B.DigitalPortRead[1] = ((pinReadLoc & 2U) != 0U);

  /* MATLABSystem: '<S22>/Digital Port Write' */
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

  /* Sum: '<S3>/Output' incorporates:
   *  Clock: '<S3>/Clock'
   *  Product: '<S3>/Product'
   *  Step: '<S3>/Step'
   */
  rtb_Output = (real_T)!(Micro_mouse_M->Timing.t[0] < 0.0) *
    Micro_mouse_M->Timing.t[0];

  /* MATLABSystem: '<S15>/PWM Output' */
  setDutyCycleInPercentageChannel1(Micro_mouse_DW.obj_j.TimerHandle, rtb_Output);

  /* MATLABSystem: '<S24>/PWM Output' */
  setDutyCycleInPercentageChannel1(Micro_mouse_DW.obj_e.TimerHandle, rtb_Output);

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
  rtmSetTFinal(Micro_mouse_M, 100.0);
  Micro_mouse_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Micro_mouse_M->Sizes.checksums[0] = (3729902666U);
  Micro_mouse_M->Sizes.checksums[1] = (3936130693U);
  Micro_mouse_M->Sizes.checksums[2] = (339829807U);
  Micro_mouse_M->Sizes.checksums[3] = (715601555U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    Micro_mouse_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Micro_mouse_M->extModeInfo,
      &Micro_mouse_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Micro_mouse_M->extModeInfo,
                        Micro_mouse_M->Sizes.checksums);
    rteiSetTPtr(Micro_mouse_M->extModeInfo, rtmGetTPtr(Micro_mouse_M));
  }

  /* Start for MATLABSystem: '<S6>/Analog to Digital Converter' */
  Micro_mouse_DW.obj.isInitialized = 0;
  Micro_mouse_DW.obj.matlabCodegenIsDeleted = false;
  Micro_mouse_SystemCore_setup(&Micro_mouse_DW.obj);

  /* Start for MATLABSystem: '<S15>/PWM Output' */
  Micro_mouse_DW.obj_j.matlabCodegenIsDeleted = false;
  Micro_mouse_DW.obj_j.isSetupComplete = false;
  Micro_mouse_DW.obj_j.isInitialized = 1;
  Micro_mouse_PWMOutput_setupImpl(&Micro_mouse_DW.obj_j);
  Micro_mouse_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S24>/PWM Output' */
  Micro_mouse_DW.obj_e.matlabCodegenIsDeleted = false;
  Micro_mouse_DW.obj_e.isSetupComplete = false;
  Micro_mouse_DW.obj_e.isInitialized = 1;
  Micro_mou_PWMOutput_setupImpl_c(&Micro_mouse_DW.obj_e);
  Micro_mouse_DW.obj_e.isSetupComplete = true;
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
  if (!Micro_mouse_DW.obj_j.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj_j.isInitialized == 1) &&
        Micro_mouse_DW.obj_j.isSetupComplete) {
      disableCounter(Micro_mouse_DW.obj_j.TimerHandle);
      disableTimerInterrupts(Micro_mouse_DW.obj_j.TimerHandle, 0);
      disableTimerChannel1(Micro_mouse_DW.obj_j.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S15>/PWM Output' */

  /* Terminate for MATLABSystem: '<S24>/PWM Output' */
  if (!Micro_mouse_DW.obj_e.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj_e.isInitialized == 1) &&
        Micro_mouse_DW.obj_e.isSetupComplete) {
      disableCounter(Micro_mouse_DW.obj_e.TimerHandle);
      disableTimerInterrupts(Micro_mouse_DW.obj_e.TimerHandle, 0);
      disableTimerChannel1(Micro_mouse_DW.obj_e.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S24>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
