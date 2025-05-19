/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse.c
 *
 * Code generated for Simulink model 'Micro_mouse'.
 *
 * Model version                  : 1.62
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Mon May 19 11:43:17 2025
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
#include <string.h>
#include <stddef.h>
#include "mw_stm32_i2c_ll.h"
#include "stm_adc_ll.h"
#include "stm_timer_ll.h"

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
static void Micro_mouse_SystemCore_setup(stm32cube_blocks_I2CControlle_T *obj);
static void Micro_mou_I2CDrvBlock_setupImpl(stm32cube_blocks_I2CControl_c_T *obj);
static void Micro_mouse_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Mi_T *obj);
static void Micro_mou_PWMOutput_setupImpl_c(stm32cube_blocks_PWMOutput_Mi_T *obj);
static void Micro_mouse_SystemCore_setup_c(stm32cube_blocks_AnalogInput__T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Micro_mouse_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Micro_mouse_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Micro_mouse_M->Timing.TaskCounters.TID[1])++;
  if ((Micro_mouse_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.1s, 0.0s] */
    Micro_mouse_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void Micro_mouse_SystemCore_setup(stm32cube_blocks_I2CControlle_T *obj)
{
  STM32_I2C_Struct_T * i2cBlockStruct_loc;
  STM32_I2C_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S4>/I2C Controller Read' */
  obj->isInitialized = 1;
  c.instance = I2C1;
  c.txCommunicationMode = MW_I2C_COMMUNICATION_POLLING;
  c.rxCommunicationMode = MW_I2C_COMMUNICATION_POLLING;
  obj->MW_I2C_BlockStruct.h_i2c = NULL;
  obj->MW_I2C_BlockStruct.rxBufferStructPtr = NULL;
  obj->MW_I2C_BlockStruct.txBufferStructPtr = NULL;
  i2cBlockStruct_loc = (STM32_I2C_Struct_T *)(&obj->MW_I2C_BlockStruct);
  obj->MW_I2C_HANDLE = I2C_Init(&c, i2cBlockStruct_loc);
  obj->isSetupComplete = true;
}

static void Micro_mou_I2CDrvBlock_setupImpl(stm32cube_blocks_I2CControl_c_T *obj)
{
  STM32_I2C_Struct_T * i2cBlockStruct_loc;
  STM32_I2C_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S4>/I2C Controller Write' incorporates:
   *  MATLABSystem: '<Root>/I2C Controller Write'
   */
  c.instance = I2C1;
  c.txCommunicationMode = MW_I2C_COMMUNICATION_POLLING;
  c.rxCommunicationMode = MW_I2C_COMMUNICATION_POLLING;
  obj->MW_I2C_BlockStruct.h_i2c = NULL;
  obj->MW_I2C_BlockStruct.rxBufferStructPtr = NULL;
  obj->MW_I2C_BlockStruct.txBufferStructPtr = NULL;
  i2cBlockStruct_loc = (STM32_I2C_Struct_T *)(&obj->MW_I2C_BlockStruct);
  obj->MW_I2C_HANDLE = I2C_Init(&c, i2cBlockStruct_loc);
}

static void Micro_mouse_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Mi_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S138>/PWM Output' */
  b.PeripheralPtr = TIM16;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S138>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S138>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void Micro_mou_PWMOutput_setupImpl_c(stm32cube_blocks_PWMOutput_Mi_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S155>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S155>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S155>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void Micro_mouse_SystemCore_setup_c(stm32cube_blocks_AnalogInput__T *obj)
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

/* Model step function for TID0 */
void Micro_mouse_step0(void)           /* Sample time: [0.02s, 0.0s] */
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_FilterCoefficient;
  real_T rtb_FilterCoefficient_f;
  real_T rtb_Saturation;
  real_T rtb_Saturation1;
  real_T rtb_TSamp_a;
  real_T rtb_TmpRTBAtTriggeredSubsyste_e;
  real_T rtb_TmpRTBAtTriggeredSubsyste_n;
  real_T rtb_TmpRTBAtTriggeredSubsystemO;
  int32_T rtb_y;
  uint16_T tmp[5];
  uint8_T SwappedDataBytes[2];

  {                                    /* Sample time: [0.02s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition generated from: '<S24>/Triggered Subsystem' */
  rtb_TmpRTBAtTriggeredSubsystemO = Micro_mouse_B.UnitDelay;

  /* Gain: '<S24>/Ratio' */
  rtb_TmpRTBAtTriggeredSubsystemO *= 0.015259164317436139;

  /* Outport: '<Root>/position' */
  Micro_mouse_Y.position = rtb_TmpRTBAtTriggeredSubsystemO;

  /* RateTransition generated from: '<S23>/Triggered Subsystem' */
  rtb_TmpRTBAtTriggeredSubsyste_n = Micro_mouse_B.UnitDelay_n;

  /* Gain: '<S23>/Ratio' */
  rtb_TmpRTBAtTriggeredSubsyste_n *= 0.015259164317436139;

  /* Outport: '<Root>/position1' */
  Micro_mouse_Y.position1 = rtb_TmpRTBAtTriggeredSubsyste_n;

  /* RateTransition generated from: '<Root>/Triggered Subsystem' */
  rtb_TmpRTBAtTriggeredSubsyste_e = Micro_mouse_B.UnitDelay_e;

  /* MATLAB Function: '<Root>/MATLAB Function' */
  if (rtb_TmpRTBAtTriggeredSubsyste_e == 0.0) {
    rtb_y = 0;
  } else if (rtb_TmpRTBAtTriggeredSubsyste_e == 1.0) {
    rtb_y = 20;
  } else {
    rtb_y = 0;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* SampleTimeMath: '<S20>/TSamp'
   *
   * About '<S20>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TmpRTBAtTriggeredSubsyste_e = rtb_TmpRTBAtTriggeredSubsyste_n * 50.0;

  /* Sum: '<S7>/Sum2' incorporates:
   *  Sum: '<S20>/Diff'
   *  Sum: '<S7>/Sum3'
   *  UnitDelay: '<S20>/UD'
   *
   * Block description for '<S20>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S20>/UD':
   *
   *  Store in Global RAM
   */
  rtb_TmpRTBAtTriggeredSubsyste_n = ((real_T)rtb_y -
    rtb_TmpRTBAtTriggeredSubsyste_n) - (rtb_TmpRTBAtTriggeredSubsyste_e -
    Micro_mouse_DW.UD_DSTATE);

  /* Gain: '<S114>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S106>/Filter'
   *  Gain: '<S104>/Derivative Gain'
   *  Sum: '<S106>/SumD'
   */
  rtb_FilterCoefficient = (0.0 * rtb_TmpRTBAtTriggeredSubsyste_n -
    Micro_mouse_DW.Filter_DSTATE) * 100.0;

  /* Sum: '<S120>/Sum' incorporates:
   *  DiscreteIntegrator: '<S111>/Integrator'
   *  Gain: '<S116>/Proportional Gain'
   */
  rtb_Saturation = (1.5 * rtb_TmpRTBAtTriggeredSubsyste_n +
                    Micro_mouse_DW.Integrator_DSTATE) + rtb_FilterCoefficient;

  /* Saturate: '<S7>/Saturation' */
  if (rtb_Saturation > 100.0) {
    rtb_Saturation = 100.0;
  } else if (rtb_Saturation < -100.0) {
    rtb_Saturation = -100.0;
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* SampleTimeMath: '<S19>/TSamp'
   *
   * About '<S19>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp_a = rtb_TmpRTBAtTriggeredSubsystemO * 50.0;

  /* Sum: '<S7>/Sum' incorporates:
   *  Sum: '<S19>/Diff'
   *  Sum: '<S7>/Sum1'
   *  UnitDelay: '<S19>/UD'
   *
   * Block description for '<S19>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S19>/UD':
   *
   *  Store in Global RAM
   */
  rtb_TmpRTBAtTriggeredSubsystemO = ((real_T)rtb_y -
    rtb_TmpRTBAtTriggeredSubsystemO) - (rtb_TSamp_a - Micro_mouse_DW.UD_DSTATE_o);

  /* Gain: '<S62>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S54>/Filter'
   *  Gain: '<S52>/Derivative Gain'
   *  Sum: '<S54>/SumD'
   */
  rtb_FilterCoefficient_f = (0.0 * rtb_TmpRTBAtTriggeredSubsystemO -
    Micro_mouse_DW.Filter_DSTATE_f) * 100.0;

  /* Sum: '<S68>/Sum' incorporates:
   *  DiscreteIntegrator: '<S59>/Integrator'
   *  Gain: '<S64>/Proportional Gain'
   */
  rtb_Saturation1 = (1.5 * rtb_TmpRTBAtTriggeredSubsystemO +
                     Micro_mouse_DW.Integrator_DSTATE_f) +
    rtb_FilterCoefficient_f;

  /* Saturate: '<S7>/Saturation1' */
  if (rtb_Saturation1 > 99.0) {
    rtb_Saturation1 = 99.0;
  } else if (rtb_Saturation1 < -99.0) {
    rtb_Saturation1 = -99.0;
  }

  /* End of Saturate: '<S7>/Saturation1' */

  /* MATLABSystem: '<S138>/PWM Output' incorporates:
   *  Abs: '<S7>/Abs'
   */
  setDutyCycleInPercentageChannel1(Micro_mouse_DW.obj_du.TimerHandle, fabs
    (rtb_Saturation));

  /* MATLABSystem: '<S136>/Digital Port Write' incorporates:
   *  Constant: '<S18>/Constant'
   *  RelationalOperator: '<S18>/Compare'
   */
  portNameLoc = GPIOA;
  if (rtb_Saturation < 0.0) {
    rtb_y = 4096;
  } else {
    rtb_y = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)rtb_y);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)rtb_y & 4096U);

  /* End of MATLABSystem: '<S136>/Digital Port Write' */

  /* MATLABSystem: '<S155>/PWM Output' incorporates:
   *  Abs: '<S7>/Abs1'
   */
  setDutyCycleInPercentageChannel1(Micro_mouse_DW.obj_e.TimerHandle, fabs
    (rtb_Saturation1));

  /* MATLABSystem: '<S153>/Digital Port Write' incorporates:
   *  Constant: '<S17>/Constant'
   *  RelationalOperator: '<S17>/Compare'
   */
  portNameLoc = GPIOA;
  if (rtb_Saturation1 > 0.0) {
    rtb_y = 2048;
  } else {
    rtb_y = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)rtb_y);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)rtb_y & 2048U);

  /* End of MATLABSystem: '<S153>/Digital Port Write' */

  /* MATLABSystem: '<Root>/I2C Controller Write' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  SwappedDataBytes[0] = 107U;
  SwappedDataBytes[1] = 0U;
  I2C_Controller_TransmitData_Polling(Micro_mouse_DW.obj_o.MW_I2C_HANDLE, 104,
    &SwappedDataBytes[0], 2U, false, false, 1U);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_y = ((Micro_mouse_DW.clockTickCounter < 50) &&
           (Micro_mouse_DW.clockTickCounter >= 0));
  if (Micro_mouse_DW.clockTickCounter >= 99) {
    Micro_mouse_DW.clockTickCounter = 0;
  } else {
    Micro_mouse_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<S12>/Digital Port Write' */
  portNameLoc = GPIOA;
  rtb_y = (rtb_y != 0);
  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)rtb_y);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)rtb_y & 1U);

  /* MATLABSystem: '<S16>/Analog to Digital Converter' */
  regularReadADCDMA(Micro_mouse_DW.obj.ADCHandle, ADC_TRIGGER_AND_READ, &tmp[0]);

  /* Update for UnitDelay: '<S20>/UD'
   *
   * Block description for '<S20>/UD':
   *
   *  Store in Global RAM
   */
  Micro_mouse_DW.UD_DSTATE = rtb_TmpRTBAtTriggeredSubsyste_e;

  /* Update for DiscreteIntegrator: '<S111>/Integrator' incorporates:
   *  Gain: '<S108>/Integral Gain'
   */
  Micro_mouse_DW.Integrator_DSTATE += 0.2 * rtb_TmpRTBAtTriggeredSubsyste_n *
    0.02;

  /* Update for DiscreteIntegrator: '<S106>/Filter' */
  Micro_mouse_DW.Filter_DSTATE += 0.02 * rtb_FilterCoefficient;

  /* Update for UnitDelay: '<S19>/UD'
   *
   * Block description for '<S19>/UD':
   *
   *  Store in Global RAM
   */
  Micro_mouse_DW.UD_DSTATE_o = rtb_TSamp_a;

  /* Update for DiscreteIntegrator: '<S59>/Integrator' incorporates:
   *  Gain: '<S56>/Integral Gain'
   */
  Micro_mouse_DW.Integrator_DSTATE_f += 0.2 * rtb_TmpRTBAtTriggeredSubsystemO *
    0.02;

  /* Update for DiscreteIntegrator: '<S54>/Filter' */
  Micro_mouse_DW.Filter_DSTATE_f += 0.02 * rtb_FilterCoefficient_f;
}

/* Model step function for TID1 */
void Micro_mouse_step1(void)           /* Sample time: [0.1s, 0.0s] */
{
  int32_T i;
  uint32_T status;
  int16_T rtb_ax;
  int16_T rtb_ay;
  int16_T rtb_az;
  int16_T rtb_gx;
  int16_T rtb_gy;
  int16_T rtb_gz;
  uint8_T rtb_I2CControllerRead_o1_0[14];
  uint8_T SwappedDataBytes[2];
  uint8_T txData;

  /* S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* MATLABSystem: '<S4>/I2C Controller Read' */
  txData = 59U;
  status = I2C_Controller_TransmitData_Polling
    (Micro_mouse_DW.obj_d.MW_I2C_HANDLE, 104, &txData, 1U, true, true, 1U);
  if (status == 0U) {
    I2C_Controller_ReceiveData_Polling(Micro_mouse_DW.obj_d.MW_I2C_HANDLE, 104,
      &rtb_I2CControllerRead_o1_0[0], 14U, false, false, 1U);
  } else {
    for (i = 0; i < 14; i++) {
      rtb_I2CControllerRead_o1_0[i] = 0U;
    }
  }

  /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
   *  MATLABSystem: '<S4>/I2C Controller Read'
   */
  SwappedDataBytes[0] = rtb_I2CControllerRead_o1_0[0];
  SwappedDataBytes[1] = rtb_I2CControllerRead_o1_0[1];
  memcpy((void *)&rtb_ax, (void *)&SwappedDataBytes[0], (size_t)1 * sizeof
         (int16_T));
  SwappedDataBytes[0] = rtb_I2CControllerRead_o1_0[2];
  SwappedDataBytes[1] = rtb_I2CControllerRead_o1_0[3];
  memcpy((void *)&rtb_ay, (void *)&SwappedDataBytes[0], (size_t)1 * sizeof
         (int16_T));
  SwappedDataBytes[0] = rtb_I2CControllerRead_o1_0[4];
  SwappedDataBytes[1] = rtb_I2CControllerRead_o1_0[5];
  memcpy((void *)&rtb_az, (void *)&SwappedDataBytes[0], (size_t)1 * sizeof
         (int16_T));
  SwappedDataBytes[0] = rtb_I2CControllerRead_o1_0[6];
  SwappedDataBytes[1] = rtb_I2CControllerRead_o1_0[7];
  memcpy((void *)&rtb_ax, (void *)&SwappedDataBytes[0], (size_t)1 * sizeof
         (int16_T));
  SwappedDataBytes[0] = rtb_I2CControllerRead_o1_0[8];
  SwappedDataBytes[1] = rtb_I2CControllerRead_o1_0[9];
  memcpy((void *)&rtb_gx, (void *)&SwappedDataBytes[0], (size_t)1 * sizeof
         (int16_T));
  SwappedDataBytes[0] = rtb_I2CControllerRead_o1_0[10];
  SwappedDataBytes[1] = rtb_I2CControllerRead_o1_0[11];
  memcpy((void *)&rtb_gy, (void *)&SwappedDataBytes[0], (size_t)1 * sizeof
         (int16_T));
  SwappedDataBytes[0] = rtb_I2CControllerRead_o1_0[12];
  SwappedDataBytes[1] = rtb_I2CControllerRead_o1_0[13];
  memcpy((void *)&rtb_gz, (void *)&SwappedDataBytes[0], (size_t)1 * sizeof
         (int16_T));

  /* MATLABSystem: '<S4>/I2C Controller Write' incorporates:
   *  Constant: '<S4>/Constant1'
   */
  SwappedDataBytes[0] = 107U;
  SwappedDataBytes[1] = 59U;
  I2C_Controller_TransmitData_Polling(Micro_mouse_DW.obj_a.MW_I2C_HANDLE, 104,
    &SwappedDataBytes[0], 2U, false, false, 1U);

  /* End of Outputs for S-Function (fcgen): '<Root>/Function-Call Generator' */
}

/* Model initialize function */
void Micro_mouse_initialize(void)
{
  /* SystemInitialize for S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* Start for MATLABSystem: '<S4>/I2C Controller Read' */
  Micro_mouse_DW.obj_d.isInitialized = 0;
  Micro_mouse_DW.obj_d.matlabCodegenIsDeleted = false;
  Micro_mouse_SystemCore_setup(&Micro_mouse_DW.obj_d);

  /* Start for MATLABSystem: '<S4>/I2C Controller Write' */
  Micro_mouse_DW.obj_a.matlabCodegenIsDeleted = false;
  Micro_mouse_DW.obj_a.isSetupComplete = false;
  Micro_mouse_DW.obj_a.isInitialized = 1;
  Micro_mou_I2CDrvBlock_setupImpl(&Micro_mouse_DW.obj_a);
  Micro_mouse_DW.obj_a.isSetupComplete = true;

  /* End of SystemInitialize for S-Function (fcgen): '<Root>/Function-Call Generator' */

  /* Start for MATLABSystem: '<S138>/PWM Output' */
  Micro_mouse_DW.obj_du.matlabCodegenIsDeleted = false;
  Micro_mouse_DW.obj_du.isSetupComplete = false;
  Micro_mouse_DW.obj_du.isInitialized = 1;
  Micro_mouse_PWMOutput_setupImpl(&Micro_mouse_DW.obj_du);
  Micro_mouse_DW.obj_du.isSetupComplete = true;

  /* Start for MATLABSystem: '<S155>/PWM Output' */
  Micro_mouse_DW.obj_e.matlabCodegenIsDeleted = false;
  Micro_mouse_DW.obj_e.isSetupComplete = false;
  Micro_mouse_DW.obj_e.isInitialized = 1;
  Micro_mou_PWMOutput_setupImpl_c(&Micro_mouse_DW.obj_e);
  Micro_mouse_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/I2C Controller Write' */
  Micro_mouse_DW.obj_o.matlabCodegenIsDeleted = false;
  Micro_mouse_DW.obj_o.isSetupComplete = false;
  Micro_mouse_DW.obj_o.isInitialized = 1;
  Micro_mou_I2CDrvBlock_setupImpl(&Micro_mouse_DW.obj_o);
  Micro_mouse_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S16>/Analog to Digital Converter' */
  Micro_mouse_DW.obj.isInitialized = 0;
  Micro_mouse_DW.obj.matlabCodegenIsDeleted = false;
  Micro_mouse_SystemCore_setup_c(&Micro_mouse_DW.obj);
}

/* Model terminate function */
void Micro_mouse_terminate(void)
{
  /* Terminate for MATLABSystem: '<S138>/PWM Output' */
  if (!Micro_mouse_DW.obj_du.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_du.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj_du.isInitialized == 1) &&
        Micro_mouse_DW.obj_du.isSetupComplete) {
      disableCounter(Micro_mouse_DW.obj_du.TimerHandle);
      disableTimerInterrupts(Micro_mouse_DW.obj_du.TimerHandle, 0);
      disableTimerChannel1(Micro_mouse_DW.obj_du.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S138>/PWM Output' */

  /* Terminate for MATLABSystem: '<S155>/PWM Output' */
  if (!Micro_mouse_DW.obj_e.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj_e.isInitialized == 1) &&
        Micro_mouse_DW.obj_e.isSetupComplete) {
      disableCounter(Micro_mouse_DW.obj_e.TimerHandle);
      disableTimerInterrupts(Micro_mouse_DW.obj_e.TimerHandle, 0);
      disableTimerChannel1(Micro_mouse_DW.obj_e.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S155>/PWM Output' */

  /* Terminate for MATLABSystem: '<Root>/I2C Controller Write' */
  if (!Micro_mouse_DW.obj_o.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/I2C Controller Write' */

  /* Terminate for MATLABSystem: '<S16>/Analog to Digital Converter' */
  if (!Micro_mouse_DW.obj.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj.isInitialized == 1) &&
        Micro_mouse_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(Micro_mouse_DW.obj.ADCHandle, ADC_DMA_INTERRUPT_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S16>/Analog to Digital Converter' */

  /* Terminate for S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* Terminate for MATLABSystem: '<S4>/I2C Controller Read' */
  if (!Micro_mouse_DW.obj_d.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/I2C Controller Read' */

  /* Terminate for MATLABSystem: '<S4>/I2C Controller Write' */
  if (!Micro_mouse_DW.obj_a.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/I2C Controller Write' */
  /* End of Terminate for S-Function (fcgen): '<Root>/Function-Call Generator' */
}

void Micro_mouse_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(38,&EXTI9_5_IRQHandler,2);
  MW_NVIC_EnableIRQ(38);

  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(24,&EXTI3_IRQHandler,2);
  MW_NVIC_EnableIRQ(24);

  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(21,&EXTI0_IRQHandler,2);
  MW_NVIC_EnableIRQ(21);
}

/* Hardware Interrupt Block: '<S10>/Hardware Interrupt' */
void EXTI9_5_IRQHandler(void)
{
  /* Event: EXTI5 Event */
  /* Check event EXTI5 Event occurred */
  if (0 != ((0 != LL_EXTI_IsEnabledIT_0_31(LL_EXTI_LINE_5)) && (0 !=
        LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_5)))) {
    /* Clear occurred EXTI5 Event event */
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_5);
    if (1 == runModel) {
      {
        /* S-Function (HardwareInterrupt_sfun): '<S10>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Triggered Subsystem' */

        /* UnitDelay: '<S8>/Unit Delay' */
        Micro_mouse_B.UnitDelay_e = Micro_mouse_DW.UnitDelay_DSTATE_i;

        /* Update for UnitDelay: '<S8>/Unit Delay' incorporates:
         *  Constant: '<S8>/Constant'
         *  Sum: '<S8>/Sum4'
         */
        Micro_mouse_DW.UnitDelay_DSTATE_i = Micro_mouse_B.UnitDelay_e + 1.0;

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S10>/Hardware Interrupt' */
      }
    }
  }

  __ISB();
  __DSB();
}

/* Hardware Interrupt Block: '<S134>/Hardware Interrupt' */
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
        /* S-Function (HardwareInterrupt_sfun): '<S134>/Hardware Interrupt' */

        /* Output and update for function-call system: '<S23>/Triggered Subsystem' */
        {
          int32_T tmp;
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_p;

          /* MATLABSystem: '<S143>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* MATLABSystem: '<S145>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOB);

          /* UnitDelay: '<S132>/Unit Delay' */
          Micro_mouse_B.UnitDelay_n = Micro_mouse_DW.UnitDelay_DSTATE_o;

          /* MATLAB Function: '<S132>/MATLAB Function' incorporates:
           *  MATLABSystem: '<S143>/Digital Port Read'
           *  MATLABSystem: '<S145>/Digital Port Read'
           * */
          if (((pinReadLoc & 8U) != 0U) == ((pinReadLoc_p & 16U) != 0U)) {
            tmp = 1;
          } else {
            tmp = -1;
          }

          /* Update for UnitDelay: '<S132>/Unit Delay' incorporates:
           *  MATLAB Function: '<S132>/MATLAB Function'
           *  Sum: '<S132>/Sum'
           */
          Micro_mouse_DW.UnitDelay_DSTATE_o = (real_T)tmp +
            Micro_mouse_B.UnitDelay_n;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S134>/Hardware Interrupt' */
      }
    }
  }

  __ISB();
  __DSB();
}

/* Hardware Interrupt Block: '<S151>/Hardware Interrupt' */
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
        /* S-Function (HardwareInterrupt_sfun): '<S151>/Hardware Interrupt' */

        /* Output and update for function-call system: '<S24>/Triggered Subsystem' */
        {
          int32_T tmp;
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_p;

          /* MATLABSystem: '<S160>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* MATLABSystem: '<S162>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOB);

          /* UnitDelay: '<S149>/Unit Delay' */
          Micro_mouse_B.UnitDelay = Micro_mouse_DW.UnitDelay_DSTATE;

          /* MATLAB Function: '<S149>/MATLAB Function' incorporates:
           *  MATLABSystem: '<S160>/Digital Port Read'
           *  MATLABSystem: '<S162>/Digital Port Read'
           * */
          if (((pinReadLoc & 1U) != 0U) == ((pinReadLoc_p & 2U) != 0U)) {
            tmp = -1;
          } else {
            tmp = 1;
          }

          /* Update for UnitDelay: '<S149>/Unit Delay' incorporates:
           *  MATLAB Function: '<S149>/MATLAB Function'
           *  Sum: '<S149>/Sum'
           */
          Micro_mouse_DW.UnitDelay_DSTATE = (real_T)tmp +
            Micro_mouse_B.UnitDelay;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S151>/Hardware Interrupt' */
      }
    }
  }

  __ISB();
  __DSB();
}

void Micro_mouse_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(38);
  MW_NVIC_DisableIRQ(24);
  MW_NVIC_DisableIRQ(21);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
