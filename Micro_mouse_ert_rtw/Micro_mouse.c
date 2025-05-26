/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse.c
 *
 * Code generated for Simulink model 'Micro_mouse'.
 *
 * Model version                  : 1.68
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Mon May 26 12:07:39 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Micro_mouse.h"
#include "Micro_mouse_types.h"
#include "rtwtypes.h"
#include "Micro_mouse_private.h"
#include <math.h>
#include "stm_adc_ll.h"
#include "rt_nonfinite.h"
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
static real_T Micro_mouse_mod(real_T x);
static void Micro_mouse_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);
static void Micro_mou_PWMOutput_setupImpl_c(stm32cube_blocks_PWMOutput_Mi_T *obj);
static void Micro_mouse_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Mi_T *obj);

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static real_T Micro_mouse_mod(real_T x)
{
  real_T r;
  if (rtIsNaN(x)) {
    r = (rtNaN);
  } else if (rtIsInf(x)) {
    r = (rtNaN);
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = fmod(x, 4.0);
    if (r == 0.0) {
      r = 0.0;
    } else if (r < 0.0) {
      r += 4.0;
    }
  }

  return r;
}

static void Micro_mouse_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S17>/Analog to Digital Converter' */
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

  /* Start for MATLABSystem: '<S156>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S156>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S156>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void Micro_mouse_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Mi_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S139>/PWM Output' */
  b.PeripheralPtr = TIM16;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S139>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S139>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

/* Model step function */
void Micro_mouse_step(void)
{
  /* local block i/o variables */
  real_T rtb_TSamp;
  real_T rtb_Sum_c;
  real_T rtb_FilterCoefficient;
  real_T rtb_TSamp_h;
  real_T rtb_Sum2;
  real_T rtb_FilterCoefficient_p;
  GPIO_TypeDef * portNameLoc;
  real_T dR;
  real_T rtb_TmpRTBAtTriggeredSubsyste_n;
  real_T rtb_TmpRTBAtTriggeredSubsystemO;
  real_T turn;
  int32_T i;
  uint32_T rtb_Gain2[5];
  uint16_T rtb_AnalogtoDigitalConverter_0[5];

  /* Reset subsysRan breadcrumbs */
  srClearBC(Micro_mouse_DW.Search_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Micro_mouse_DW.solve_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Micro_mouse_DW.Donothing_SubsysRanBC);

  /* MATLABSystem: '<S17>/Analog to Digital Converter' */
  regularReadADCDMA(Micro_mouse_DW.obj.ADCHandle, ADC_TRIGGER_AND_READ,
                    &rtb_AnalogtoDigitalConverter_0[0]);

  /* Gain: '<S5>/Gain2' incorporates:
   *  MATLABSystem: '<S17>/Analog to Digital Converter'
   */
  for (i = 0; i < 5; i++) {
    rtb_Gain2[i] = 54080U * rtb_AnalogtoDigitalConverter_0[i];
  }

  /* End of Gain: '<S5>/Gain2' */
  /* RateTransition generated from: '<S24>/Triggered Subsystem' */
  rtb_TmpRTBAtTriggeredSubsystemO = Micro_mouse_B.UnitDelay_n;

  /* Gain: '<S24>/Ratio' */
  rtb_TmpRTBAtTriggeredSubsystemO *= 0.015259164317436139;

  /* RateTransition generated from: '<S25>/Triggered Subsystem' */
  rtb_TmpRTBAtTriggeredSubsyste_n = Micro_mouse_B.UnitDelay;

  /* Gain: '<S25>/Ratio' */
  Micro_mouse_B.Ratio = 0.015259164317436139 * rtb_TmpRTBAtTriggeredSubsyste_n;

  /* MATLAB Function: '<Root>/MATLAB Function' */
  if (!Micro_mouse_DW.i_not_empty) {
    Micro_mouse_DW.i_not_empty = true;
    Micro_mouse_DW.prevL = rtb_TmpRTBAtTriggeredSubsystemO;
    Micro_mouse_DW.prevR = Micro_mouse_B.Ratio;
  }

  rtb_TmpRTBAtTriggeredSubsyste_n = rtb_TmpRTBAtTriggeredSubsystemO -
    Micro_mouse_DW.prevL;
  dR = Micro_mouse_B.Ratio - Micro_mouse_DW.prevR;
  turn = dR - rtb_TmpRTBAtTriggeredSubsyste_n;
  if (fabs(turn) > Micro_mouse_DW.threshold / 2.0) {
    if (turn > 0.0) {
      Micro_mouse_DW.dir = Micro_mouse_mod(Micro_mouse_DW.dir) + 1.0;
    } else {
      Micro_mouse_DW.dir = Micro_mouse_mod(Micro_mouse_DW.dir - 2.0) + 1.0;
    }
  }

  if ((rtb_TmpRTBAtTriggeredSubsyste_n + dR) / 2.0 > Micro_mouse_DW.threshold) {
    switch ((int32_T)Micro_mouse_DW.dir) {
     case 1:
      Micro_mouse_DW.i--;
      break;

     case 2:
      Micro_mouse_DW.j++;
      break;

     case 3:
      Micro_mouse_DW.i++;
      break;

     case 4:
      Micro_mouse_DW.j--;
      break;
    }
  }

  Micro_mouse_DW.prevL = rtb_TmpRTBAtTriggeredSubsystemO;
  Micro_mouse_DW.prevR = Micro_mouse_B.Ratio;

  /* End of MATLAB Function: '<Root>/MATLAB Function' */
  /* SampleTimeMath: '<S20>/TSamp'
   *
   * About '<S20>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp = Micro_mouse_B.Ratio * 50.0;

  /* SignalConversion: '<S5>/Signal Conversion4' */
  Micro_mouse_B.SignalConversion4 = rtb_Gain2[0];

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  SignalConversion: '<S5>/Signal Conversion4'
   */
  Micro_mouse_B.DataTypeConversion = (real_T)Micro_mouse_B.SignalConversion4 *
    1.4901161193847656E-8;

  /* SignalConversion: '<S5>/Signal Conversion' */
  Micro_mouse_B.SignalConversion = rtb_Gain2[4];

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S5>/Signal Conversion'
   */
  Micro_mouse_B.DataTypeConversion1 = (real_T)Micro_mouse_B.SignalConversion *
    1.4901161193847656E-8;

  /* Sum: '<S1>/Sum2' */
  Micro_mouse_B.Sum2 = Micro_mouse_B.DataTypeConversion -
    Micro_mouse_B.DataTypeConversion1;

  /* Sum: '<S8>/Sum1' incorporates:
   *  Constant: '<S8>/Constant'
   */
  Micro_mouse_B.Sum1 = 10.0 - Micro_mouse_B.Ratio;

  /* Sum: '<S8>/Sum' incorporates:
   *  Sum: '<S20>/Diff'
   *  Sum: '<S8>/Sum4'
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
  rtb_Sum_c = (Micro_mouse_B.Sum2 + Micro_mouse_B.Sum1) - (rtb_TSamp -
    Micro_mouse_DW.UD_DSTATE);

  /* Gain: '<S63>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S55>/Filter'
   *  Gain: '<S53>/Derivative Gain'
   *  Sum: '<S55>/SumD'
   */
  rtb_FilterCoefficient = (0.0 * rtb_Sum_c - Micro_mouse_DW.Filter_DSTATE) *
    100.0;

  /* Sum: '<S69>/Sum' incorporates:
   *  DiscreteIntegrator: '<S60>/Integrator'
   *  Gain: '<S65>/Proportional Gain'
   */
  rtb_TmpRTBAtTriggeredSubsyste_n = (5.0 * rtb_Sum_c +
    Micro_mouse_DW.Integrator_DSTATE) + rtb_FilterCoefficient;

  /* Saturate: '<S8>/Saturation1' */
  if (rtb_TmpRTBAtTriggeredSubsyste_n > 99.0) {
    rtb_TmpRTBAtTriggeredSubsyste_n = 99.0;
  } else if (rtb_TmpRTBAtTriggeredSubsyste_n < -99.0) {
    rtb_TmpRTBAtTriggeredSubsyste_n = -99.0;
  }

  /* End of Saturate: '<S8>/Saturation1' */

  /* MATLABSystem: '<S154>/Digital Port Write' incorporates:
   *  Constant: '<S18>/Constant'
   *  RelationalOperator: '<S18>/Compare'
   */
  portNameLoc = GPIOA;
  if (rtb_TmpRTBAtTriggeredSubsyste_n > 0.0) {
    i = 2048;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 2048U);

  /* End of MATLABSystem: '<S154>/Digital Port Write' */

  /* MATLABSystem: '<S156>/PWM Output' incorporates:
   *  Abs: '<S8>/Abs1'
   */
  setDutyCycleInPercentageChannel1(Micro_mouse_DW.obj_e.TimerHandle, fabs
    (rtb_TmpRTBAtTriggeredSubsyste_n));

  /* SampleTimeMath: '<S21>/TSamp'
   *
   * About '<S21>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp_h = rtb_TmpRTBAtTriggeredSubsystemO * 50.0;

  /* Sum: '<S8>/Sum2' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Sum: '<S21>/Diff'
   *  Sum: '<S8>/Sum3'
   *  Sum: '<S8>/Sum5'
   *  UnitDelay: '<S21>/UD'
   *
   * Block description for '<S21>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S21>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Sum2 = ((-10.0 - rtb_TmpRTBAtTriggeredSubsystemO) + Micro_mouse_B.Sum2) -
    (rtb_TSamp_h - Micro_mouse_DW.UD_DSTATE_b);

  /* Gain: '<S115>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S107>/Filter'
   *  Gain: '<S105>/Derivative Gain'
   *  Sum: '<S107>/SumD'
   */
  rtb_FilterCoefficient_p = (0.0 * rtb_Sum2 - Micro_mouse_DW.Filter_DSTATE_c) *
    100.0;

  /* Sum: '<S121>/Sum' incorporates:
   *  DiscreteIntegrator: '<S112>/Integrator'
   *  Gain: '<S117>/Proportional Gain'
   */
  rtb_TmpRTBAtTriggeredSubsystemO = (5.0 * rtb_Sum2 +
    Micro_mouse_DW.Integrator_DSTATE_k) + rtb_FilterCoefficient_p;

  /* Saturate: '<S8>/Saturation' */
  if (rtb_TmpRTBAtTriggeredSubsystemO > 100.0) {
    rtb_TmpRTBAtTriggeredSubsystemO = 100.0;
  } else if (rtb_TmpRTBAtTriggeredSubsystemO < -100.0) {
    rtb_TmpRTBAtTriggeredSubsystemO = -100.0;
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* MATLABSystem: '<S137>/Digital Port Write' incorporates:
   *  Constant: '<S19>/Constant'
   *  RelationalOperator: '<S19>/Compare'
   */
  portNameLoc = GPIOA;
  if (rtb_TmpRTBAtTriggeredSubsystemO < 0.0) {
    i = 4096;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 4096U);

  /* End of MATLABSystem: '<S137>/Digital Port Write' */

  /* MATLABSystem: '<S139>/PWM Output' incorporates:
   *  Abs: '<S8>/Abs'
   */
  setDutyCycleInPercentageChannel1(Micro_mouse_DW.obj_d.TimerHandle, fabs
    (rtb_TmpRTBAtTriggeredSubsystemO));

  /* If: '<Root>/If' incorporates:
   *  RateTransition generated from: '<Root>/Triggered Subsystem'
   */
  if ((!(Micro_mouse_B.UnitDelay_e == 1.0)) && (!(Micro_mouse_B.UnitDelay_e ==
        2.0))) {
    /* Outputs for IfAction SubSystem: '<Root>/Do nothing' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    srUpdateBC(Micro_mouse_DW.Donothing_SubsysRanBC);

    /* End of Outputs for SubSystem: '<Root>/Do nothing' */
  }

  /* End of If: '<Root>/If' */

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  i = ((Micro_mouse_DW.clockTickCounter < 50) &&
       (Micro_mouse_DW.clockTickCounter >= 0));
  if (Micro_mouse_DW.clockTickCounter >= 99) {
    Micro_mouse_DW.clockTickCounter = 0;
  } else {
    Micro_mouse_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<S14>/Digital Port Write' */
  portNameLoc = GPIOA;
  i = (i != 0);
  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 1U);

  /* Update for UnitDelay: '<S20>/UD'
   *
   * Block description for '<S20>/UD':
   *
   *  Store in Global RAM
   */
  Micro_mouse_DW.UD_DSTATE = rtb_TSamp;

  /* Update for DiscreteIntegrator: '<S60>/Integrator' */
  Micro_mouse_DW.Integrator_DSTATE += 0.02 * rtb_Sum_c;

  /* Update for DiscreteIntegrator: '<S55>/Filter' */
  Micro_mouse_DW.Filter_DSTATE += 0.02 * rtb_FilterCoefficient;

  /* Update for UnitDelay: '<S21>/UD'
   *
   * Block description for '<S21>/UD':
   *
   *  Store in Global RAM
   */
  Micro_mouse_DW.UD_DSTATE_b = rtb_TSamp_h;

  /* Update for DiscreteIntegrator: '<S112>/Integrator' */
  Micro_mouse_DW.Integrator_DSTATE_k += 0.02 * rtb_Sum2;

  /* Update for DiscreteIntegrator: '<S107>/Filter' */
  Micro_mouse_DW.Filter_DSTATE_c += 0.02 * rtb_FilterCoefficient_p;

  {                                    /* Sample time: [0.02s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((Micro_mouse_M->Timing.clockTick1) * 0.02);

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
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.02, which is the step size
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
  Micro_mouse_M->Timing.stepSize0 = 0.02;

  /* External mode info */
  Micro_mouse_M->Sizes.checksums[0] = (2789257587U);
  Micro_mouse_M->Sizes.checksums[1] = (1343890945U);
  Micro_mouse_M->Sizes.checksums[2] = (660521080U);
  Micro_mouse_M->Sizes.checksums[3] = (2827990401U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[20];
    Micro_mouse_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&Micro_mouse_DW.Donothing_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = (sysRanDType *)&Micro_mouse_DW.Search_SubsysRanBC;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_l;
    systemRan[9] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_l;
    systemRan[10] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_l;
    systemRan[11] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_l;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_e;
    systemRan[19] = (sysRanDType *)&Micro_mouse_DW.solve_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Micro_mouse_M->extModeInfo,
      &Micro_mouse_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Micro_mouse_M->extModeInfo,
                        Micro_mouse_M->Sizes.checksums);
    rteiSetTPtr(Micro_mouse_M->extModeInfo, rtmGetTPtr(Micro_mouse_M));
  }

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */
  Micro_mouse_DW.i = 1.0;
  Micro_mouse_DW.j = 1.0;
  Micro_mouse_DW.dir = 1.0;
  Micro_mouse_DW.threshold = 18.0;

  /* Start for MATLABSystem: '<S17>/Analog to Digital Converter' */
  Micro_mouse_DW.obj.isInitialized = 0;
  Micro_mouse_DW.obj.matlabCodegenIsDeleted = false;
  Micro_mouse_SystemCore_setup(&Micro_mouse_DW.obj);

  /* Start for MATLABSystem: '<S156>/PWM Output' */
  Micro_mouse_DW.obj_e.matlabCodegenIsDeleted = false;
  Micro_mouse_DW.obj_e.isSetupComplete = false;
  Micro_mouse_DW.obj_e.isInitialized = 1;
  Micro_mou_PWMOutput_setupImpl_c(&Micro_mouse_DW.obj_e);
  Micro_mouse_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S139>/PWM Output' */
  Micro_mouse_DW.obj_d.matlabCodegenIsDeleted = false;
  Micro_mouse_DW.obj_d.isSetupComplete = false;
  Micro_mouse_DW.obj_d.isInitialized = 1;
  Micro_mouse_PWMOutput_setupImpl(&Micro_mouse_DW.obj_d);
  Micro_mouse_DW.obj_d.isSetupComplete = true;
}

/* Model terminate function */
void Micro_mouse_terminate(void)
{
  /* Terminate for MATLABSystem: '<S17>/Analog to Digital Converter' */
  if (!Micro_mouse_DW.obj.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj.isInitialized == 1) &&
        Micro_mouse_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(Micro_mouse_DW.obj.ADCHandle, ADC_DMA_INTERRUPT_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S17>/Analog to Digital Converter' */
  /* Terminate for MATLABSystem: '<S156>/PWM Output' */
  if (!Micro_mouse_DW.obj_e.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj_e.isInitialized == 1) &&
        Micro_mouse_DW.obj_e.isSetupComplete) {
      disableCounter(Micro_mouse_DW.obj_e.TimerHandle);
      disableTimerInterrupts(Micro_mouse_DW.obj_e.TimerHandle, 0);
      disableTimerChannel1(Micro_mouse_DW.obj_e.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S156>/PWM Output' */
  /* Terminate for MATLABSystem: '<S139>/PWM Output' */
  if (!Micro_mouse_DW.obj_d.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj_d.isInitialized == 1) &&
        Micro_mouse_DW.obj_d.isSetupComplete) {
      disableCounter(Micro_mouse_DW.obj_d.TimerHandle);
      disableTimerInterrupts(Micro_mouse_DW.obj_d.TimerHandle, 0);
      disableTimerChannel1(Micro_mouse_DW.obj_d.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S139>/PWM Output' */
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

/* Hardware Interrupt Block: '<S12>/Hardware Interrupt' */
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
        /* Reset subsysRan breadcrumbs */
        srClearBC(Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_e);

        /* S-Function (HardwareInterrupt_sfun): '<S12>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Triggered Subsystem' */
        Micro_mouse_M->Timing.clockTick2 = Micro_mouse_M->Timing.clockTick0;

        /* UnitDelay: '<S9>/Unit Delay' */
        Micro_mouse_B.UnitDelay_e = Micro_mouse_DW.UnitDelay_DSTATE_i;

        /* Update for UnitDelay: '<S9>/Unit Delay' incorporates:
         *  Constant: '<S9>/Constant'
         *  Sum: '<S9>/Sum4'
         */
        Micro_mouse_DW.UnitDelay_DSTATE_i = Micro_mouse_B.UnitDelay_e + 1.0;
        Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_e = 4;

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S12>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((Micro_mouse_M->Timing.clockTick2)
        * 0.02);
      extmodeEvent(2,currentTime);
    }
  }

  __ISB();
  __DSB();
}

/* Hardware Interrupt Block: '<S135>/Hardware Interrupt' */
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

        /* S-Function (HardwareInterrupt_sfun): '<S135>/Hardware Interrupt' */

        /* Output and update for function-call system: '<S24>/Triggered Subsystem' */
        {
          int32_T tmp;
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_p;
          Micro_mouse_M->Timing.clockTick3 = Micro_mouse_M->Timing.clockTick0;

          /* MATLABSystem: '<S144>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* MATLABSystem: '<S146>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOB);

          /* UnitDelay: '<S133>/Unit Delay' */
          Micro_mouse_B.UnitDelay_n = Micro_mouse_DW.UnitDelay_DSTATE_o;

          /* MATLAB Function: '<S133>/MATLAB Function' incorporates:
           *  MATLABSystem: '<S144>/Digital Port Read'
           *  MATLABSystem: '<S146>/Digital Port Read'
           * */
          if (((pinReadLoc & 8U) != 0U) == ((pinReadLoc_p & 16U) != 0U)) {
            tmp = 1;
          } else {
            tmp = -1;
          }

          /* Update for UnitDelay: '<S133>/Unit Delay' incorporates:
           *  MATLAB Function: '<S133>/MATLAB Function'
           *  Sum: '<S133>/Sum'
           */
          Micro_mouse_DW.UnitDelay_DSTATE_o = (real_T)tmp +
            Micro_mouse_B.UnitDelay_n;
          Micro_mouse_DW.TriggeredSubsystem_SubsysRanB_l = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S135>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((Micro_mouse_M->Timing.clockTick3)
        * 0.02);
      extmodeEvent(3,currentTime);
    }
  }

  __ISB();
  __DSB();
}

/* Hardware Interrupt Block: '<S152>/Hardware Interrupt' */
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

        /* S-Function (HardwareInterrupt_sfun): '<S152>/Hardware Interrupt' */

        /* Output and update for function-call system: '<S25>/Triggered Subsystem' */
        {
          int32_T tmp;
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_p;
          Micro_mouse_M->Timing.clockTick4 = Micro_mouse_M->Timing.clockTick0;

          /* MATLABSystem: '<S161>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* MATLABSystem: '<S163>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOB);

          /* UnitDelay: '<S150>/Unit Delay' */
          Micro_mouse_B.UnitDelay = Micro_mouse_DW.UnitDelay_DSTATE;

          /* MATLAB Function: '<S150>/MATLAB Function' incorporates:
           *  MATLABSystem: '<S161>/Digital Port Read'
           *  MATLABSystem: '<S163>/Digital Port Read'
           * */
          if (((pinReadLoc & 1U) != 0U) == ((pinReadLoc_p & 2U) != 0U)) {
            tmp = -1;
          } else {
            tmp = 1;
          }

          /* Update for UnitDelay: '<S150>/Unit Delay' incorporates:
           *  MATLAB Function: '<S150>/MATLAB Function'
           *  Sum: '<S150>/Sum'
           */
          Micro_mouse_DW.UnitDelay_DSTATE = (real_T)tmp +
            Micro_mouse_B.UnitDelay;
          Micro_mouse_DW.TriggeredSubsystem_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S152>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((Micro_mouse_M->Timing.clockTick4)
        * 0.02);
      extmodeEvent(4,currentTime);
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
