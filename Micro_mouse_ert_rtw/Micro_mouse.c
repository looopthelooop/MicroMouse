/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse.c
 *
 * Code generated for Simulink model 'Micro_mouse'.
 *
 * Model version                  : 1.47
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue May  6 15:09:43 2025
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
  eventFlags[2] = ((boolean_T)rtmStepTask(Micro_mouse_M, 2));
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
  (Micro_mouse_M->Timing.TaskCounters.TID[2])++;
  if ((Micro_mouse_M->Timing.TaskCounters.TID[2]) > 999) {/* Sample time: [1.0s, 0.0s] */
    Micro_mouse_M->Timing.TaskCounters.TID[2] = 0;
  }
}

static void Micro_mouse_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S120>/Analog to Digital Converter' */
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

  /* Start for MATLABSystem: '<S147>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S147>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S147>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void Micro_mouse_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Mi_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S130>/PWM Output' */
  b.PeripheralPtr = TIM16;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S130>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S130>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

/* Model step function for TID0 */
void Micro_mouse_step0(void)           /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_FilterCoefficient;
  real_T rtb_TSamp;
  real_T rtb_TSamp_f;
  real_T rtb_FilterCoefficient_e;
  real_T rtb_IntegralGain;
  real_T rtb_IntegralGain_f;
  real_T rtb_TSamp_j;
  real_T rtb_TSamp_b;
  GPIO_TypeDef * portNameLoc;
  b_dspcodegen_FIRFilter_Micro__T *obj;
  real_T rtb_TmpRTBAtTriggeredSubsystemO;
  int32_T i;
  uint32_T rtb_Gain2[5];
  uint16_T rtb_AnalogtoDigitalConverter_0[5];

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<S120>/Analog to Digital Converter' */
  regularReadADCDMA(Micro_mouse_DW.obj_c.ADCHandle, ADC_TRIGGER_AND_READ,
                    &rtb_AnalogtoDigitalConverter_0[0]);

  /* Gain: '<S11>/Gain2' incorporates:
   *  MATLABSystem: '<S120>/Analog to Digital Converter'
   */
  for (i = 0; i < 5; i++) {
    rtb_Gain2[i] = 54080U * rtb_AnalogtoDigitalConverter_0[i];
  }

  /* End of Gain: '<S11>/Gain2' */

  /* SignalConversion: '<S11>/Signal Conversion4' */
  Micro_mouse_B.SignalConversion4 = rtb_Gain2[0];

  /* SignalConversion: '<S11>/Signal Conversion' */
  Micro_mouse_B.SignalConversion = rtb_Gain2[4];

  /* Sum: '<S1>/Sum2' incorporates:
   *  SignalConversion: '<S11>/Signal Conversion'
   *  SignalConversion: '<S11>/Signal Conversion4'
   */
  Micro_mouse_B.Sum2 = Micro_mouse_B.SignalConversion4 -
    Micro_mouse_B.SignalConversion;

  /* Gain: '<S1>/Gain' incorporates:
   *  Sum: '<S1>/Sum2'
   */
  Micro_mouse_B.Gain = 3435973837ULL * Micro_mouse_B.Sum2;

  /* RateTransition generated from: '<S13>/Triggered Subsystem' */
  rtb_TmpRTBAtTriggeredSubsystemO = Micro_mouse_B.UnitDelay;

  /* Gain: '<S13>/Ratio' */
  Micro_mouse_B.Ratio = 0.00015259164317436139 * rtb_TmpRTBAtTriggeredSubsystemO;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  Micro_mouse_B.Sum1 = 10.0 - Micro_mouse_B.Ratio;

  /* Gain: '<S103>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S95>/Filter'
   *  Gain: '<S93>/Derivative Gain'
   *  Sum: '<S95>/SumD'
   */
  rtb_FilterCoefficient = (0.0 * Micro_mouse_B.Sum1 -
    Micro_mouse_DW.Filter_DSTATE) * 100.0;

  /* SampleTimeMath: '<S6>/TSamp' incorporates:
   *  DiscreteIntegrator: '<S100>/Integrator'
   *  Sum: '<S109>/Sum'
   *
   * About '<S6>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp = ((Micro_mouse_B.Sum1 + Micro_mouse_DW.Integrator_DSTATE) +
               rtb_FilterCoefficient) * 1000.0;

  /* Sum: '<S6>/Diff' incorporates:
   *  UnitDelay: '<S6>/UD'
   *
   * Block description for '<S6>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S6>/UD':
   *
   *  Store in Global RAM
   */
  Micro_mouse_B.Diff = rtb_TSamp - Micro_mouse_DW.UD_DSTATE;

  /* SampleTimeMath: '<S5>/TSamp'
   *
   * About '<S5>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp_f = Micro_mouse_B.Ratio * 1000.0;

  /* Sum: '<S5>/Diff' incorporates:
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
  Micro_mouse_B.Diff_p = rtb_TSamp_f - Micro_mouse_DW.UD_DSTATE_h;

  /* Sum: '<Root>/Sum' */
  rtb_TmpRTBAtTriggeredSubsystemO = Micro_mouse_B.Diff - Micro_mouse_B.Diff_p;

  /* Gain: '<S51>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S43>/Filter'
   *  Gain: '<S41>/Derivative Gain'
   *  Sum: '<S43>/SumD'
   */
  rtb_FilterCoefficient_e = (0.0 * rtb_TmpRTBAtTriggeredSubsystemO -
    Micro_mouse_DW.Filter_DSTATE_b) * 100.0;

  /* Sum: '<S57>/Sum' incorporates:
   *  DiscreteIntegrator: '<S48>/Integrator'
   */
  Micro_mouse_B.Saturation1 = (rtb_TmpRTBAtTriggeredSubsystemO +
    Micro_mouse_DW.Integrator_DSTATE_g) + rtb_FilterCoefficient_e;

  /* Saturate: '<Root>/Saturation1' */
  if (Micro_mouse_B.Saturation1 > 99.0) {
    /* Sum: '<S57>/Sum' incorporates:
     *  Saturate: '<Root>/Saturation1'
     */
    Micro_mouse_B.Saturation1 = 99.0;
  } else if (Micro_mouse_B.Saturation1 < -99.0) {
    /* Sum: '<S57>/Sum' incorporates:
     *  Saturate: '<Root>/Saturation1'
     */
    Micro_mouse_B.Saturation1 = -99.0;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* MATLABSystem: '<S145>/Digital Port Write' incorporates:
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

  /* End of MATLABSystem: '<S145>/Digital Port Write' */
  /* MATLABSystem: '<S147>/PWM Output' incorporates:
   *  Abs: '<Root>/Abs1'
   */
  setDutyCycleInPercentageChannel1(Micro_mouse_DW.obj_j.TimerHandle, fabs
    (Micro_mouse_B.Saturation1));

  /* Gain: '<S45>/Integral Gain' */
  rtb_IntegralGain = 0.1 * rtb_TmpRTBAtTriggeredSubsystemO;

  /* Gain: '<S97>/Integral Gain' */
  rtb_IntegralGain_f = 0.1 * Micro_mouse_B.Sum1;

  /* Outport: '<Root>/position1' */
  Micro_mouse_Y.position1 = Micro_mouse_B.Ratio;

  /* RateTransition generated from: '<S12>/Triggered Subsystem' */
  rtb_TmpRTBAtTriggeredSubsystemO = Micro_mouse_B.UnitDelay_j;

  /* Gain: '<S12>/Ratio' */
  Micro_mouse_B.Ratio_p = 0.00015259164317436139 *
    rtb_TmpRTBAtTriggeredSubsystemO;

  /* SampleTimeMath: '<S8>/TSamp' incorporates:
   *  Constant: '<Root>/Constant'
   *  Sum: '<Root>/Sum3'
   *
   * About '<S8>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp_j = (10.0 - Micro_mouse_B.Ratio_p) * 1000.0;

  /* SampleTimeMath: '<S7>/TSamp'
   *
   * About '<S7>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp_b = Micro_mouse_B.Ratio_p * 1000.0;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Sum: '<S7>/Diff'
   *  Sum: '<S8>/Diff'
   *  UnitDelay: '<S7>/UD'
   *  UnitDelay: '<S8>/UD'
   *
   * Block description for '<S7>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S8>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S7>/UD':
   *
   *  Store in Global RAM
   *
   * Block description for '<S8>/UD':
   *
   *  Store in Global RAM
   */
  rtb_TmpRTBAtTriggeredSubsystemO = (rtb_TSamp_j - Micro_mouse_DW.UD_DSTATE_e) -
    (rtb_TSamp_b - Micro_mouse_DW.UD_DSTATE_ee);

  /* Saturate: '<Root>/Saturation' */
  if (rtb_TmpRTBAtTriggeredSubsystemO > 100.0) {
    rtb_TmpRTBAtTriggeredSubsystemO = 100.0;
  } else if (rtb_TmpRTBAtTriggeredSubsystemO < -100.0) {
    rtb_TmpRTBAtTriggeredSubsystemO = -100.0;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* MATLABSystem: '<S128>/Digital Port Write' incorporates:
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

  /* End of MATLABSystem: '<S128>/Digital Port Write' */

  /* MATLABSystem: '<S130>/PWM Output' incorporates:
   *  Abs: '<Root>/Abs'
   */
  setDutyCycleInPercentageChannel1(Micro_mouse_DW.obj_g.TimerHandle, fabs
    (rtb_TmpRTBAtTriggeredSubsystemO));

  /* Outport: '<Root>/position' */
  Micro_mouse_Y.position = Micro_mouse_B.Ratio_p;

  /* MATLABSystem: '<Root>/Lowpass Filter' */
  obj = Micro_mouse_DW.obj.FilterObj;
  if (Micro_mouse_DW.obj.FilterObj->isInitialized != 1) {
    Micro_mouse_DW.obj.FilterObj->isSetupComplete = false;
    Micro_mouse_DW.obj.FilterObj->isInitialized = 1;
    Micro_mouse_DW.obj.FilterObj->isSetupComplete = true;

    /* System object Initialization function: dsp.FIRFilter */
    for (i = 0; i < 38; i++) {
      Micro_mouse_DW.obj.FilterObj->cSFunObject.W0_states[i] =
        Micro_mouse_DW.obj.FilterObj->cSFunObject.P0_InitialStates;
    }
  }

  /* System object Outputs function: dsp.FIRFilter */
  /* Reverse the coefficients */
  for (i = 0; i < 39; i++) {
    obj->cSFunObject.W2_simRevCoeff[38 - i] = obj->cSFunObject.P1_Coefficients[i];
  }

  /* Reverse copy the states from States_Dwork to ContextBuff_Dwork */
  /* Copy the initial part of input to ContextBuff_Dwork */
  for (i = 0; i < 38; i++) {
    obj->cSFunObject.W1_simContextBuf[37 - i] = obj->cSFunObject.W0_states[i];
  }

  obj->cSFunObject.W1_simContextBuf[38] = 0.0;

  /* Shift state buffer when input buffer is shorter than state buffer */
  for (i = 36; i >= 0; i--) {
    obj->cSFunObject.W0_states[i + 1] = obj->cSFunObject.W0_states[i];
  }

  /* Reverse copy the states from input to States_Dwork */
  obj->cSFunObject.W0_states[0] = 0.0;

  /* End of MATLABSystem: '<Root>/Lowpass Filter' */

  /* Update for DiscreteIntegrator: '<S100>/Integrator' */
  Micro_mouse_DW.Integrator_DSTATE += 0.001 * rtb_IntegralGain_f;

  /* Update for DiscreteIntegrator: '<S95>/Filter' */
  Micro_mouse_DW.Filter_DSTATE += 0.001 * rtb_FilterCoefficient;

  /* Update for UnitDelay: '<S6>/UD'
   *
   * Block description for '<S6>/UD':
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
  Micro_mouse_DW.UD_DSTATE_h = rtb_TSamp_f;

  /* Update for DiscreteIntegrator: '<S48>/Integrator' */
  Micro_mouse_DW.Integrator_DSTATE_g += 0.001 * rtb_IntegralGain;

  /* Update for DiscreteIntegrator: '<S43>/Filter' */
  Micro_mouse_DW.Filter_DSTATE_b += 0.001 * rtb_FilterCoefficient_e;

  /* Update for UnitDelay: '<S8>/UD'
   *
   * Block description for '<S8>/UD':
   *
   *  Store in Global RAM
   */
  Micro_mouse_DW.UD_DSTATE_e = rtb_TSamp_j;

  /* Update for UnitDelay: '<S7>/UD'
   *
   * Block description for '<S7>/UD':
   *
   *  Store in Global RAM
   */
  Micro_mouse_DW.UD_DSTATE_ee = rtb_TSamp_b;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Micro_mouse_M->Timing.t[0] =
    ((time_T)(++Micro_mouse_M->Timing.clockTick0)) *
    Micro_mouse_M->Timing.stepSize0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Micro_mouse_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void Micro_mouse_step2(void)           /* Sample time: [1.0s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 1.0, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Micro_mouse_M->Timing.clockTick2++;
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
  Micro_mouse_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Micro_mouse_M->Sizes.checksums[0] = (4152972722U);
  Micro_mouse_M->Sizes.checksums[1] = (1229146360U);
  Micro_mouse_M->Sizes.checksums[2] = (840176974U);
  Micro_mouse_M->Sizes.checksums[3] = (1398988853U);

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
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_j;
    systemRan[5] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_j;
    systemRan[6] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_j;
    systemRan[7] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_j;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Micro_mouse_M->extModeInfo,
      &Micro_mouse_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Micro_mouse_M->extModeInfo,
                        Micro_mouse_M->Sizes.checksums);
    rteiSetTPtr(Micro_mouse_M->extModeInfo, rtmGetTPtr(Micro_mouse_M));
  }

  {
    int32_T i;
    static const real_T tmp[39] = { -0.00059249716026085677,
      -0.0020237151019090495, -0.0021051716132991219, 0.0012581546346926275,
      0.0045838138209808709, 0.0008101820785051452, -0.0074967798682261952,
      -0.0059816467843209192, 0.0089225864350714924, 0.014760271107288081,
      -0.0061216071244679275, -0.026666367690000855, -0.0045063659737724108,
      0.040073523645200719, 0.028615212604478531, -0.052524257886488068,
      -0.082380786808864889, 0.061364820833367056, 0.309911296424881,
      0.43543471248777532, 0.309911296424881, 0.061364820833367056,
      -0.082380786808864889, -0.052524257886488068, 0.028615212604478531,
      0.040073523645200719, -0.0045063659737724108, -0.026666367690000855,
      -0.0061216071244679275, 0.014760271107288081, 0.0089225864350714924,
      -0.0059816467843209192, -0.0074967798682261952, 0.0008101820785051452,
      0.0045838138209808709, 0.0012581546346926275, -0.0021051716132991219,
      -0.0020237151019090495, -0.00059249716026085677 };

    /* Start for MATLABSystem: '<S120>/Analog to Digital Converter' */
    Micro_mouse_DW.obj_c.isInitialized = 0;
    Micro_mouse_DW.obj_c.matlabCodegenIsDeleted = false;
    Micro_mouse_SystemCore_setup(&Micro_mouse_DW.obj_c);

    /* Start for MATLABSystem: '<S147>/PWM Output' */
    Micro_mouse_DW.obj_j.matlabCodegenIsDeleted = false;
    Micro_mouse_DW.obj_j.isSetupComplete = false;
    Micro_mouse_DW.obj_j.isInitialized = 1;
    Micro_mou_PWMOutput_setupImpl_c(&Micro_mouse_DW.obj_j);
    Micro_mouse_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S130>/PWM Output' */
    Micro_mouse_DW.obj_g.matlabCodegenIsDeleted = false;
    Micro_mouse_DW.obj_g.isSetupComplete = false;
    Micro_mouse_DW.obj_g.isInitialized = 1;
    Micro_mouse_PWMOutput_setupImpl(&Micro_mouse_DW.obj_g);
    Micro_mouse_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Lowpass Filter' */
    Micro_mouse_DW.obj.NumChannels = -1;
    Micro_mouse_DW.obj.matlabCodegenIsDeleted = false;
    Micro_mouse_DW.obj.isInitialized = 1;
    if (Micro_mouse_DW.obj.NumChannels == -1) {
      Micro_mouse_DW.obj.NumChannels = 1;
    }

    Micro_mouse_DW.obj._pobj0.isInitialized = 0;

    /* System object Constructor function: dsp.FIRFilter */
    Micro_mouse_DW.obj._pobj0.cSFunObject.P0_InitialStates = 0.0;
    memcpy(&Micro_mouse_DW.obj._pobj0.cSFunObject.P1_Coefficients[0], &tmp[0],
           39U * sizeof(real_T));
    Micro_mouse_DW.obj.FilterObj = &Micro_mouse_DW.obj._pobj0;
    Micro_mouse_DW.obj.isSetupComplete = true;

    /* InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter' */
    if (Micro_mouse_DW.obj.FilterObj->isInitialized == 1) {
      /* System object Initialization function: dsp.FIRFilter */
      for (i = 0; i < 38; i++) {
        Micro_mouse_DW.obj.FilterObj->cSFunObject.W0_states[i] =
          Micro_mouse_DW.obj.FilterObj->cSFunObject.P0_InitialStates;
      }
    }

    /* End of InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter' */
  }
}

/* Model terminate function */
void Micro_mouse_terminate(void)
{
  /* Terminate for MATLABSystem: '<S120>/Analog to Digital Converter' */
  if (!Micro_mouse_DW.obj_c.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj_c.isInitialized == 1) &&
        Micro_mouse_DW.obj_c.isSetupComplete) {
      ADC_Handle_Deinit(Micro_mouse_DW.obj_c.ADCHandle, ADC_DMA_INTERRUPT_MODE,
                        1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S120>/Analog to Digital Converter' */
  /* Terminate for MATLABSystem: '<S147>/PWM Output' */
  if (!Micro_mouse_DW.obj_j.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj_j.isInitialized == 1) &&
        Micro_mouse_DW.obj_j.isSetupComplete) {
      disableCounter(Micro_mouse_DW.obj_j.TimerHandle);
      disableTimerInterrupts(Micro_mouse_DW.obj_j.TimerHandle, 0);
      disableTimerChannel1(Micro_mouse_DW.obj_j.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S147>/PWM Output' */
  /* Terminate for MATLABSystem: '<S130>/PWM Output' */
  if (!Micro_mouse_DW.obj_g.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj_g.isInitialized == 1) &&
        Micro_mouse_DW.obj_g.isSetupComplete) {
      disableCounter(Micro_mouse_DW.obj_g.TimerHandle);
      disableTimerInterrupts(Micro_mouse_DW.obj_g.TimerHandle, 0);
      disableTimerChannel1(Micro_mouse_DW.obj_g.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S130>/PWM Output' */
  /* Terminate for MATLABSystem: '<Root>/Lowpass Filter' */
  if (!Micro_mouse_DW.obj.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj.isInitialized == 1) &&
        Micro_mouse_DW.obj.isSetupComplete) {
      if (Micro_mouse_DW.obj.FilterObj->isInitialized == 1) {
        Micro_mouse_DW.obj.FilterObj->isInitialized = 2;
      }

      Micro_mouse_DW.obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Lowpass Filter' */
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

/* Hardware Interrupt Block: '<S126>/Hardware Interrupt' */
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

        /* S-Function (HardwareInterrupt_sfun): '<S126>/Hardware Interrupt' */

        /* Output and update for function-call system: '<S12>/Triggered Subsystem' */
        {
          int32_T tmp;
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_p;
          Micro_mouse_M->Timing.clockTick3 = Micro_mouse_M->Timing.clockTick0;

          /* MATLABSystem: '<S135>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* MATLABSystem: '<S137>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOB);

          /* UnitDelay: '<S124>/Unit Delay' */
          Micro_mouse_B.UnitDelay_j = Micro_mouse_DW.UnitDelay_DSTATE_e;

          /* MATLAB Function: '<S124>/MATLAB Function' incorporates:
           *  MATLABSystem: '<S135>/Digital Port Read'
           *  MATLABSystem: '<S137>/Digital Port Read'
           * */
          if (((pinReadLoc & 8U) != 0U) == ((pinReadLoc_p & 16U) != 0U)) {
            tmp = 1;
          } else {
            tmp = -1;
          }

          /* Update for UnitDelay: '<S124>/Unit Delay' incorporates:
           *  MATLAB Function: '<S124>/MATLAB Function'
           *  Sum: '<S124>/Sum'
           */
          Micro_mouse_DW.UnitDelay_DSTATE_e = (real_T)tmp +
            Micro_mouse_B.UnitDelay_j;
          Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_j = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S126>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((Micro_mouse_M->Timing.clockTick3)
        * 0.001);
      extmodeEvent(3,currentTime);
    }
  }

  __ISB();
  __DSB();
}

/* Hardware Interrupt Block: '<S143>/Hardware Interrupt' */
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

        /* S-Function (HardwareInterrupt_sfun): '<S143>/Hardware Interrupt' */

        /* Output and update for function-call system: '<S13>/Triggered Subsystem' */
        {
          int32_T tmp;
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_p;
          Micro_mouse_M->Timing.clockTick4 = Micro_mouse_M->Timing.clockTick0;

          /* MATLABSystem: '<S152>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* MATLABSystem: '<S154>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOB);

          /* UnitDelay: '<S141>/Unit Delay' */
          Micro_mouse_B.UnitDelay = Micro_mouse_DW.UnitDelay_DSTATE;

          /* MATLAB Function: '<S141>/MATLAB Function' incorporates:
           *  MATLABSystem: '<S152>/Digital Port Read'
           *  MATLABSystem: '<S154>/Digital Port Read'
           * */
          if (((pinReadLoc & 1U) != 0U) == ((pinReadLoc_p & 2U) != 0U)) {
            tmp = -1;
          } else {
            tmp = 1;
          }

          /* Update for UnitDelay: '<S141>/Unit Delay' incorporates:
           *  MATLAB Function: '<S141>/MATLAB Function'
           *  Sum: '<S141>/Sum'
           */
          Micro_mouse_DW.UnitDelay_DSTATE = (real_T)tmp +
            Micro_mouse_B.UnitDelay;
          Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S143>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((Micro_mouse_M->Timing.clockTick4)
        * 0.001);
      extmodeEvent(4,currentTime);
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
