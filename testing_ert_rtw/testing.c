/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: testing.c
 *
 * Code generated for Simulink model 'testing'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Mon May  5 10:12:22 2025
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
static void testing_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);
static void testing_PWMOutput_setupImpl_o(stm32cube_blocks_PWMOutput_te_T *obj);
static void testing_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_te_T *obj);
static void testing_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S115>/Analog to Digital Converter' */
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

/* Model step function */
void testing_step(void)
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_FilterCoefficient;
  real_T rtb_FilterCoefficient_i;
  real_T rtb_Saturation;
  real_T rtb_TmpRTBAtRatioInport1;
  real_T rtb_TmpRTBAtTriggeredSubsystemO;
  int32_T i;
  uint32_T rtb_Gain2[5];
  uint16_T rtb_AnalogtoDigitalConverter_0[5];

  /* MATLABSystem: '<S115>/Analog to Digital Converter' */
  regularReadADCDMA(testing_DW.obj.ADCHandle, ADC_TRIGGER_AND_READ,
                    &rtb_AnalogtoDigitalConverter_0[0]);

  /* Gain: '<S6>/Gain2' incorporates:
   *  MATLABSystem: '<S115>/Analog to Digital Converter'
   */
  for (i = 0; i < 5; i++) {
    rtb_Gain2[i] = 54080U * rtb_AnalogtoDigitalConverter_0[i];
  }

  /* End of Gain: '<S6>/Gain2' */

  /* SignalConversion: '<S6>/Signal Conversion4' */
  testing_B.SignalConversion4 = rtb_Gain2[0];

  /* SignalConversion: '<S6>/Signal Conversion' */
  testing_B.SignalConversion = rtb_Gain2[4];

  /* Sum: '<S1>/Sum2' incorporates:
   *  SignalConversion: '<S6>/Signal Conversion'
   *  SignalConversion: '<S6>/Signal Conversion4'
   */
  testing_B.Sum2 = testing_B.SignalConversion4 - testing_B.SignalConversion;

  /* Gain: '<S1>/Gain' incorporates:
   *  Sum: '<S1>/Sum2'
   */
  testing_B.Gain = 3435973837ULL * testing_B.Sum2;

  /* RateTransition generated from: '<S8>/Ratio' */
  rtb_TmpRTBAtRatioInport1 = testing_B.OutportBufferForPosition;

  /* Gain: '<S8>/Ratio' */
  testing_B.Ratio = 15.25916431743614 * rtb_TmpRTBAtRatioInport1;

  /* SampleTimeMath: '<S136>/TSamp'
   *
   * About '<S136>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TmpRTBAtRatioInport1 = testing_B.Ratio * 100.0;

  /* Sum: '<S136>/Diff' incorporates:
   *  UnitDelay: '<S136>/UD'
   *
   * Block description for '<S136>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S136>/UD':
   *
   *  Store in Global RAM
   */
  testing_B.Diff = rtb_TmpRTBAtRatioInport1 - testing_DW.UD_DSTATE;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  testing_B.Sum1 = 20.0 - testing_B.Diff;

  /* Gain: '<S46>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S38>/Filter'
   *  Gain: '<S36>/Derivative Gain'
   *  Sum: '<S38>/SumD'
   */
  rtb_FilterCoefficient = (0.0 * testing_B.Sum1 - testing_DW.Filter_DSTATE) *
    100.0;

  /* Sum: '<S52>/Sum' incorporates:
   *  DiscreteIntegrator: '<S43>/Integrator'
   */
  testing_B.Saturation1 = (testing_B.Sum1 + testing_DW.Integrator_DSTATE) +
    rtb_FilterCoefficient;

  /* Saturate: '<Root>/Saturation1' */
  if (testing_B.Saturation1 > 99.0) {
    /* Sum: '<S52>/Sum' incorporates:
     *  Saturate: '<Root>/Saturation1'
     */
    testing_B.Saturation1 = 99.0;
  } else if (testing_B.Saturation1 < -99.0) {
    /* Sum: '<S52>/Sum' incorporates:
     *  Saturate: '<Root>/Saturation1'
     */
    testing_B.Saturation1 = -99.0;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* MATLABSystem: '<S142>/Digital Port Write' incorporates:
   *  Constant: '<S2>/Constant'
   *  RelationalOperator: '<S2>/Compare'
   */
  portNameLoc = GPIOA;
  if (testing_B.Saturation1 > 0.0) {
    i = 2048;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 2048U);

  /* End of MATLABSystem: '<S142>/Digital Port Write' */
  /* MATLABSystem: '<S144>/PWM Output' incorporates:
   *  Abs: '<Root>/Abs1'
   */
  setDutyCycleInPercentageChannel1(testing_DW.obj_i.TimerHandle, fabs
    (testing_B.Saturation1));

  /* Outport: '<Root>/speed' */
  testing_Y.speed = testing_B.Diff;

  /* Outport: '<Root>/position1' */
  testing_Y.position1 = testing_B.Ratio;

  /* RateTransition generated from: '<S7>/Triggered Subsystem' */
  rtb_TmpRTBAtTriggeredSubsystemO = testing_B.OutportBufferForPosition_a;

  /* Gain: '<S7>/Ratio' */
  testing_B.Ratio_c = 15.25916431743614 * rtb_TmpRTBAtTriggeredSubsystemO;

  /* SampleTimeMath: '<S118>/TSamp'
   *
   * About '<S118>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TmpRTBAtTriggeredSubsystemO = testing_B.Ratio_c * 100.0;

  /* Sum: '<S118>/Diff' incorporates:
   *  UnitDelay: '<S118>/UD'
   *
   * Block description for '<S118>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S118>/UD':
   *
   *  Store in Global RAM
   */
  testing_B.Diff_a = rtb_TmpRTBAtTriggeredSubsystemO - testing_DW.UD_DSTATE_f;

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  testing_B.Sum = 20.0 - testing_B.Diff_a;

  /* Gain: '<S98>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S90>/Filter'
   *  Gain: '<S88>/Derivative Gain'
   *  Sum: '<S90>/SumD'
   */
  rtb_FilterCoefficient_i = (0.0 * testing_B.Sum - testing_DW.Filter_DSTATE_d) *
    100.0;

  /* Sum: '<S104>/Sum' incorporates:
   *  DiscreteIntegrator: '<S95>/Integrator'
   */
  rtb_Saturation = (testing_B.Sum + testing_DW.Integrator_DSTATE_m) +
    rtb_FilterCoefficient_i;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Saturation > 99.0) {
    rtb_Saturation = 99.0;
  } else if (rtb_Saturation < -99.0) {
    rtb_Saturation = -99.0;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* MATLABSystem: '<S124>/Digital Port Write' incorporates:
   *  Constant: '<S3>/Constant'
   *  RelationalOperator: '<S3>/Compare'
   */
  portNameLoc = GPIOA;
  if (rtb_Saturation < 0.0) {
    i = 4096;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 4096U);

  /* End of MATLABSystem: '<S124>/Digital Port Write' */

  /* MATLABSystem: '<S126>/PWM Output' incorporates:
   *  Abs: '<Root>/Abs'
   */
  setDutyCycleInPercentageChannel1(testing_DW.obj_n.TimerHandle, fabs
    (rtb_Saturation));

  /* Outport: '<Root>/speed2' */
  testing_Y.speed2 = testing_B.Diff_a;

  /* Outport: '<Root>/position' */
  testing_Y.position = testing_B.Ratio_c;

  /* RateTransition generated from: '<S8>/Scope' */
  testing_B.TmpRTBAtScopeInport1 = testing_B.OutportBufferForPosition;

  /* Update for UnitDelay: '<S136>/UD'
   *
   * Block description for '<S136>/UD':
   *
   *  Store in Global RAM
   */
  testing_DW.UD_DSTATE = rtb_TmpRTBAtRatioInport1;

  /* Update for DiscreteIntegrator: '<S43>/Integrator' incorporates:
   *  Gain: '<S40>/Integral Gain'
   */
  testing_DW.Integrator_DSTATE += 0.0 * testing_B.Sum1 * 0.01;

  /* Update for DiscreteIntegrator: '<S38>/Filter' */
  testing_DW.Filter_DSTATE += 0.01 * rtb_FilterCoefficient;

  /* Update for UnitDelay: '<S118>/UD'
   *
   * Block description for '<S118>/UD':
   *
   *  Store in Global RAM
   */
  testing_DW.UD_DSTATE_f = rtb_TmpRTBAtTriggeredSubsystemO;

  /* Update for DiscreteIntegrator: '<S90>/Filter' */
  testing_DW.Filter_DSTATE_d += 0.01 * rtb_FilterCoefficient_i;

  /* Update for DiscreteIntegrator: '<S95>/Integrator' incorporates:
   *  Gain: '<S92>/Integral Gain'
   */
  testing_DW.Integrator_DSTATE_m += 0.0 * testing_B.Sum * 0.01;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  testing_M->Timing.taskTime0 =
    ((time_T)(++testing_M->Timing.clockTick0)) * testing_M->Timing.stepSize0;
}

/* Model initialize function */
void testing_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(testing_M, -1);
  testing_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  testing_M->Sizes.checksums[0] = (2683025217U);
  testing_M->Sizes.checksums[1] = (2617316880U);
  testing_M->Sizes.checksums[2] = (3519869461U);
  testing_M->Sizes.checksums[3] = (4156398876U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[14];
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
    rteiSetModelMappingInfoPtr(testing_M->extModeInfo,
      &testing_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(testing_M->extModeInfo, testing_M->Sizes.checksums);
    rteiSetTPtr(testing_M->extModeInfo, rtmGetTPtr(testing_M));
  }

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S140>/Hardware Interrupt' incorporates:
   *  SubSystem: '<S8>/Triggered Subsystem'
   */

  /* System initialize for function-call system: '<S8>/Triggered Subsystem' */
  testing_M->Timing.clockTick2 = testing_M->Timing.clockTick0;

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S140>/Hardware Interrupt' */

  /* Start for MATLABSystem: '<S115>/Analog to Digital Converter' */
  testing_DW.obj.isInitialized = 0;
  testing_DW.obj.matlabCodegenIsDeleted = false;
  testing_SystemCore_setup(&testing_DW.obj);

  /* Start for MATLABSystem: '<S144>/PWM Output' */
  testing_DW.obj_i.matlabCodegenIsDeleted = false;
  testing_DW.obj_i.isSetupComplete = false;
  testing_DW.obj_i.isInitialized = 1;
  testing_PWMOutput_setupImpl_o(&testing_DW.obj_i);
  testing_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S126>/PWM Output' */
  testing_DW.obj_n.matlabCodegenIsDeleted = false;
  testing_DW.obj_n.isSetupComplete = false;
  testing_DW.obj_n.isInitialized = 1;
  testing_PWMOutput_setupImpl(&testing_DW.obj_n);
  testing_DW.obj_n.isSetupComplete = true;

  /* Enable for S-Function (HardwareInterrupt_sfun): '<S122>/Hardware Interrupt' incorporates:
   *  SubSystem: '<S7>/Triggered Subsystem'
   */

  /* Enable for function-call system: '<S7>/Triggered Subsystem' */
  testing_M->Timing.clockTick1 = testing_M->Timing.clockTick0;
  testing_DW.TriggeredSubsystem_RESET_ELAP_d = true;

  /* Enable for DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */
  testing_DW.DiscreteTimeIntegrator_SYSTEM_e = 1U;

  /* End of Enable for S-Function (HardwareInterrupt_sfun): '<S122>/Hardware Interrupt' */

  /* Enable for S-Function (HardwareInterrupt_sfun): '<S140>/Hardware Interrupt' incorporates:
   *  SubSystem: '<S8>/Triggered Subsystem'
   */

  /* Enable for function-call system: '<S8>/Triggered Subsystem' */
  testing_M->Timing.clockTick2 = testing_M->Timing.clockTick0;
  testing_DW.TriggeredSubsystem_RESET_ELAPS_ = true;

  /* Enable for DiscreteIntegrator: '<S138>/Discrete-Time Integrator' */
  testing_DW.DiscreteTimeIntegrator_SYSTEM_E = 1U;

  /* End of Enable for S-Function (HardwareInterrupt_sfun): '<S140>/Hardware Interrupt' */
}

/* Model terminate function */
void testing_terminate(void)
{
  /* Terminate for MATLABSystem: '<S115>/Analog to Digital Converter' */
  if (!testing_DW.obj.matlabCodegenIsDeleted) {
    testing_DW.obj.matlabCodegenIsDeleted = true;
    if ((testing_DW.obj.isInitialized == 1) && testing_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(testing_DW.obj.ADCHandle, ADC_DMA_INTERRUPT_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S115>/Analog to Digital Converter' */
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

        /* Output and update for function-call system: '<S7>/Triggered Subsystem' */
        {
          uint32_T TriggeredSubsystem_ELAPS_T_c;
          uint32_T pinReadLoc;
          testing_M->Timing.clockTick1 = testing_M->Timing.clockTick0;
          if (testing_DW.TriggeredSubsystem_RESET_ELAP_d) {
            TriggeredSubsystem_ELAPS_T_c = 0U;
          } else {
            TriggeredSubsystem_ELAPS_T_c = testing_M->Timing.clockTick1 -
              testing_DW.TriggeredSubsystem_PREV_T_k;
          }

          testing_DW.TriggeredSubsystem_PREV_T_k = testing_M->Timing.clockTick1;
          testing_DW.TriggeredSubsystem_RESET_ELAP_d = false;

          /* DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */
          if (testing_DW.DiscreteTimeIntegrator_SYSTEM_e == 0) {
            /* DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */
            testing_DW.DiscreteTimeIntegrator_DSTATE_e += 0.01 * (real_T)
              TriggeredSubsystem_ELAPS_T_c *
              testing_DW.DiscreteTimeIntegrator_PREV_U_m;
          }

          /* End of DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */

          /* SignalConversion generated from: '<S120>/Position' */
          testing_B.OutportBufferForPosition_a =
            testing_DW.DiscreteTimeIntegrator_DSTATE_e;

          /* MATLABSystem: '<S131>/Digital Port Read' */
          TriggeredSubsystem_ELAPS_T_c = LL_GPIO_ReadInputPort(GPIOB);

          /* MATLABSystem: '<S133>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* Update for DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */
          testing_DW.DiscreteTimeIntegrator_SYSTEM_e = 0U;

          /* MATLAB Function: '<S120>/MATLAB Function' incorporates:
           *  MATLABSystem: '<S131>/Digital Port Read'
           *  MATLABSystem: '<S133>/Digital Port Read'
           * */
          if (((TriggeredSubsystem_ELAPS_T_c & 8U) != 0U) == ((pinReadLoc & 16U)
               != 0U)) {
            /* Update for DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */
            testing_DW.DiscreteTimeIntegrator_PREV_U_m = 1.0;
          } else {
            /* Update for DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */
            testing_DW.DiscreteTimeIntegrator_PREV_U_m = -1.0;
          }

          /* End of MATLAB Function: '<S120>/MATLAB Function' */
          testing_DW.TriggeredSubsystem_SubsysRanB_g = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S122>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((testing_M->Timing.clockTick1) *
        0.01);
      extmodeEvent(1,currentTime);
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
        /* Reset subsysRan breadcrumbs */
        srClearBC(testing_DW.TriggeredSubsystem_SubsysRanBC);

        /* S-Function (HardwareInterrupt_sfun): '<S140>/Hardware Interrupt' */

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

          /* MATLABSystem: '<S149>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* MATLABSystem: '<S149>/Digital Port Read' */
          testing_B.DigitalPortRead = ((pinReadLoc & 1U) != 0U);

          /* MATLABSystem: '<S151>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* DiscreteIntegrator: '<S138>/Discrete-Time Integrator' */
          if (testing_DW.DiscreteTimeIntegrator_SYSTEM_E != 0) {
            /* DiscreteIntegrator: '<S138>/Discrete-Time Integrator' */
            testing_B.DiscreteTimeIntegrator =
              testing_DW.DiscreteTimeIntegrator_DSTATE;
          } else {
            /* DiscreteIntegrator: '<S138>/Discrete-Time Integrator' */
            testing_B.DiscreteTimeIntegrator = 0.01 * (real_T)
              TriggeredSubsystem_ELAPS_T
              * testing_DW.DiscreteTimeIntegrator_PREV_U +
              testing_DW.DiscreteTimeIntegrator_DSTATE;
          }

          /* End of DiscreteIntegrator: '<S138>/Discrete-Time Integrator' */

          /* SignalConversion generated from: '<S138>/Position' */
          testing_B.OutportBufferForPosition = testing_B.DiscreteTimeIntegrator;

          /* Update for DiscreteIntegrator: '<S138>/Discrete-Time Integrator' */
          testing_DW.DiscreteTimeIntegrator_SYSTEM_E = 0U;
          testing_DW.DiscreteTimeIntegrator_DSTATE =
            testing_B.DiscreteTimeIntegrator;

          /* MATLAB Function: '<S138>/MATLAB Function' incorporates:
           *  MATLABSystem: '<S151>/Digital Port Read'
           * */
          if (((pinReadLoc & 2U) != 0U) == (int32_T)testing_B.DigitalPortRead) {
            /* Update for DiscreteIntegrator: '<S138>/Discrete-Time Integrator' */
            testing_DW.DiscreteTimeIntegrator_PREV_U = -1.0;
          } else {
            /* Update for DiscreteIntegrator: '<S138>/Discrete-Time Integrator' */
            testing_DW.DiscreteTimeIntegrator_PREV_U = 1.0;
          }

          /* End of MATLAB Function: '<S138>/MATLAB Function' */
          testing_DW.TriggeredSubsystem_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S140>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((testing_M->Timing.clockTick2) *
        0.01);
      extmodeEvent(2,currentTime);
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
