/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse.c
 *
 * Code generated for Simulink model 'Micro_mouse'.
 *
 * Model version                  : 1.77
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sun Jun  8 09:42:44 2025
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

  /* Start for MATLABSystem: '<S16>/Analog to Digital Converter' */
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

  /* Start for MATLABSystem: '<S18>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S18>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S18>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void Micro_mou_PWMOutput_setupImpl_c(stm32cube_blocks_PWMOutput_Mi_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S20>/PWM Output' */
  b.PeripheralPtr = TIM16;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S20>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S20>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

/* Model step function */
void Micro_mouse_step(void)
{
  GPIO_TypeDef * portNameLoc;
  int32_T rtb_PulseGenerator;
  uint16_T tmp[5];

  /* MATLABSystem: '<S16>/Analog to Digital Converter' */
  regularReadADCDMA(Micro_mouse_DW.obj.ADCHandle, ADC_TRIGGER_AND_READ, &tmp[0]);

  /* MATLABSystem: '<S18>/PWM Output' incorporates:
   *  Constant: '<Root>/Constant'
   */
  setDutyCycleInPercentageChannel1(Micro_mouse_DW.obj_i.TimerHandle, 10.0);

  /* MATLABSystem: '<S11>/Digital Port Write' */
  portNameLoc = GPIOA;
  LL_GPIO_SetOutputPin(portNameLoc, 0U);
  LL_GPIO_ResetOutputPin(portNameLoc, 2048U);

  /* MATLABSystem: '<S20>/PWM Output' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  setDutyCycleInPercentageChannel1(Micro_mouse_DW.obj_l.TimerHandle, 10.0);

  /* MATLABSystem: '<S13>/Digital Port Write' */
  portNameLoc = GPIOA;
  LL_GPIO_SetOutputPin(portNameLoc, 0U);
  LL_GPIO_ResetOutputPin(portNameLoc, 4096U);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = ((Micro_mouse_DW.clockTickCounter < 50) &&
                        (Micro_mouse_DW.clockTickCounter >= 0));
  if (Micro_mouse_DW.clockTickCounter >= 99) {
    Micro_mouse_DW.clockTickCounter = 0;
  } else {
    Micro_mouse_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<S9>/Digital Port Write' */
  portNameLoc = GPIOA;
  rtb_PulseGenerator = (rtb_PulseGenerator != 0);
  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)rtb_PulseGenerator);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)rtb_PulseGenerator & 1U);
}

/* Model initialize function */
void Micro_mouse_initialize(void)
{
  /* Start for MATLABSystem: '<S16>/Analog to Digital Converter' */
  Micro_mouse_DW.obj.isInitialized = 0;
  Micro_mouse_DW.obj.matlabCodegenIsDeleted = false;
  Micro_mouse_SystemCore_setup(&Micro_mouse_DW.obj);

  /* Start for MATLABSystem: '<S18>/PWM Output' */
  Micro_mouse_DW.obj_i.matlabCodegenIsDeleted = false;
  Micro_mouse_DW.obj_i.isSetupComplete = false;
  Micro_mouse_DW.obj_i.isInitialized = 1;
  Micro_mouse_PWMOutput_setupImpl(&Micro_mouse_DW.obj_i);
  Micro_mouse_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S20>/PWM Output' */
  Micro_mouse_DW.obj_l.matlabCodegenIsDeleted = false;
  Micro_mouse_DW.obj_l.isSetupComplete = false;
  Micro_mouse_DW.obj_l.isInitialized = 1;
  Micro_mou_PWMOutput_setupImpl_c(&Micro_mouse_DW.obj_l);
  Micro_mouse_DW.obj_l.isSetupComplete = true;
}

/* Model terminate function */
void Micro_mouse_terminate(void)
{
  /* Terminate for MATLABSystem: '<S16>/Analog to Digital Converter' */
  if (!Micro_mouse_DW.obj.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj.isInitialized == 1) &&
        Micro_mouse_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(Micro_mouse_DW.obj.ADCHandle, ADC_DMA_INTERRUPT_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S16>/Analog to Digital Converter' */

  /* Terminate for MATLABSystem: '<S18>/PWM Output' */
  if (!Micro_mouse_DW.obj_i.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj_i.isInitialized == 1) &&
        Micro_mouse_DW.obj_i.isSetupComplete) {
      disableCounter(Micro_mouse_DW.obj_i.TimerHandle);
      disableTimerInterrupts(Micro_mouse_DW.obj_i.TimerHandle, 0);
      disableTimerChannel1(Micro_mouse_DW.obj_i.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S18>/PWM Output' */

  /* Terminate for MATLABSystem: '<S20>/PWM Output' */
  if (!Micro_mouse_DW.obj_l.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj_l.isInitialized == 1) &&
        Micro_mouse_DW.obj_l.isSetupComplete) {
      disableCounter(Micro_mouse_DW.obj_l.TimerHandle);
      disableTimerInterrupts(Micro_mouse_DW.obj_l.TimerHandle, 0);
      disableTimerChannel1(Micro_mouse_DW.obj_l.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S20>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
