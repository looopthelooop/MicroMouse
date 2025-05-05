/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse.c
 *
 * Code generated for Simulink model 'Micro_mouse'.
 *
 * Model version                  : 1.43
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sun May  4 16:21:55 2025
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

static void Micro_mou_PWMOutput_setupImpl_c(stm32cube_blocks_PWMOutput_Mi_T *obj)
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

static void Micro_mouse_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Mi_T *obj)
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
void Micro_mouse_step(void)
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_Saturation;
  real_T rtb_TmpRTBAtTriggeredSubsyste_n;
  real_T rtb_TmpRTBAtTriggeredSubsystemO;
  int32_T c;
  uint16_T tmp[5];

  /* MATLABSystem: '<S115>/Analog to Digital Converter' */
  regularReadADCDMA(Micro_mouse_DW.obj.ADCHandle, ADC_TRIGGER_AND_READ, &tmp[0]);

  /* RateTransition generated from: '<S8>/Triggered Subsystem' */
  rtb_TmpRTBAtTriggeredSubsystemO = Micro_mouse_B.OutportBufferForPosition;

  /* DiscreteIntegrator: '<S95>/Integrator' incorporates:
   *  Gain: '<S8>/Ratio'
   */
  Micro_mouse_Y.position1 = 0.0076295821587180693 *
    rtb_TmpRTBAtTriggeredSubsystemO;

  /* Gain: '<S46>/Filter Coefficient' incorporates:
   *  Constant: '<Root>/Constant'
   *  DiscreteIntegrator: '<S38>/Filter'
   *  Sum: '<Root>/Sum1'
   *  Sum: '<S38>/SumD'
   */
  rtb_TmpRTBAtTriggeredSubsystemO = ((0.1 - Micro_mouse_Y.position1) -
    Micro_mouse_DW.Filter_DSTATE) * 100.0;

  /* Gain: '<S7>/Ratio' incorporates:
   *  Constant: '<Root>/Constant'
   *  DiscreteIntegrator: '<S43>/Integrator'
   *  Gain: '<S48>/Proportional Gain'
   *  Sum: '<Root>/Sum1'
   *  Sum: '<S52>/Sum'
   */
  Micro_mouse_Y.position = ((0.1 - Micro_mouse_Y.position1) * 100.0 +
    Micro_mouse_DW.Integrator_DSTATE) + rtb_TmpRTBAtTriggeredSubsystemO;

  /* Saturate: '<Root>/Saturation1' */
  if (Micro_mouse_Y.position > 100.0) {
    /* Gain: '<S7>/Ratio' */
    Micro_mouse_Y.position = 100.0;
  } else if (Micro_mouse_Y.position < -100.0) {
    /* Gain: '<S7>/Ratio' */
    Micro_mouse_Y.position = -100.0;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* MATLABSystem: '<S142>/Digital Port Write' incorporates:
   *  Constant: '<S2>/Constant'
   *  RelationalOperator: '<S2>/Compare'
   */
  portNameLoc = GPIOA;
  if (Micro_mouse_Y.position > 0.0) {
    c = 2048;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 2048U);

  /* End of MATLABSystem: '<S142>/Digital Port Write' */

  /* MATLABSystem: '<S144>/PWM Output' incorporates:
   *  Abs: '<Root>/Abs1'
   */
  setDutyCycleInPercentageChannel1(Micro_mouse_DW.obj_j.TimerHandle, fabs
    (Micro_mouse_Y.position));

  /* RateTransition generated from: '<S7>/Triggered Subsystem' */
  rtb_TmpRTBAtTriggeredSubsyste_n = Micro_mouse_B.OutportBufferForPosition_a;

  /* Gain: '<S7>/Ratio' */
  Micro_mouse_Y.position = 0.0076295821587180693 *
    rtb_TmpRTBAtTriggeredSubsyste_n;

  /* Gain: '<S98>/Filter Coefficient' incorporates:
   *  Constant: '<Root>/Constant'
   *  DiscreteIntegrator: '<S90>/Filter'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S90>/SumD'
   */
  rtb_TmpRTBAtTriggeredSubsyste_n = ((0.1 - Micro_mouse_Y.position) -
    Micro_mouse_DW.Filter_DSTATE_h) * 100.0;

  /* Sum: '<S104>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   *  DiscreteIntegrator: '<S95>/Integrator'
   *  Gain: '<S100>/Proportional Gain'
   *  Sum: '<Root>/Sum'
   */
  rtb_Saturation = ((0.1 - Micro_mouse_Y.position) * 100.0 +
                    Micro_mouse_DW.Integrator_DSTATE_j) +
    rtb_TmpRTBAtTriggeredSubsyste_n;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Saturation > 100.0) {
    rtb_Saturation = 100.0;
  } else if (rtb_Saturation < -100.0) {
    rtb_Saturation = -100.0;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* MATLABSystem: '<S124>/Digital Port Write' incorporates:
   *  Constant: '<S3>/Constant'
   *  RelationalOperator: '<S3>/Compare'
   */
  portNameLoc = GPIOA;
  if (rtb_Saturation > 0.0) {
    c = 4096;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 4096U);

  /* End of MATLABSystem: '<S124>/Digital Port Write' */

  /* MATLABSystem: '<S126>/PWM Output' incorporates:
   *  Abs: '<Root>/Abs'
   */
  setDutyCycleInPercentageChannel1(Micro_mouse_DW.obj_g.TimerHandle, fabs
    (rtb_Saturation));

  /* Update for DiscreteIntegrator: '<S43>/Integrator' incorporates:
   *  Constant: '<Root>/Constant'
   *  Sum: '<Root>/Sum1'
   */
  Micro_mouse_DW.Integrator_DSTATE += (0.1 - Micro_mouse_Y.position1) * 0.01;

  /* Update for DiscreteIntegrator: '<S38>/Filter' */
  Micro_mouse_DW.Filter_DSTATE += 0.01 * rtb_TmpRTBAtTriggeredSubsystemO;

  /* Update for DiscreteIntegrator: '<S95>/Integrator' incorporates:
   *  Constant: '<Root>/Constant'
   *  Sum: '<Root>/Sum'
   */
  Micro_mouse_DW.Integrator_DSTATE_j += (0.1 - Micro_mouse_Y.position) * 0.01;

  /* Update for DiscreteIntegrator: '<S90>/Filter' */
  Micro_mouse_DW.Filter_DSTATE_h += 0.01 * rtb_TmpRTBAtTriggeredSubsyste_n;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Micro_mouse_M->Timing.clockTick0++;
}

/* Model initialize function */
void Micro_mouse_initialize(void)
{
  /* Start for MATLABSystem: '<S115>/Analog to Digital Converter' */
  Micro_mouse_DW.obj.isInitialized = 0;
  Micro_mouse_DW.obj.matlabCodegenIsDeleted = false;
  Micro_mouse_SystemCore_setup(&Micro_mouse_DW.obj);

  /* Start for MATLABSystem: '<S144>/PWM Output' */
  Micro_mouse_DW.obj_j.matlabCodegenIsDeleted = false;
  Micro_mouse_DW.obj_j.isSetupComplete = false;
  Micro_mouse_DW.obj_j.isInitialized = 1;
  Micro_mou_PWMOutput_setupImpl_c(&Micro_mouse_DW.obj_j);
  Micro_mouse_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S126>/PWM Output' */
  Micro_mouse_DW.obj_g.matlabCodegenIsDeleted = false;
  Micro_mouse_DW.obj_g.isSetupComplete = false;
  Micro_mouse_DW.obj_g.isInitialized = 1;
  Micro_mouse_PWMOutput_setupImpl(&Micro_mouse_DW.obj_g);
  Micro_mouse_DW.obj_g.isSetupComplete = true;

  /* Enable for S-Function (HardwareInterrupt_sfun): '<S122>/Hardware Interrupt' incorporates:
   *  SubSystem: '<S7>/Triggered Subsystem'
   */

  /* Enable for function-call system: '<S7>/Triggered Subsystem' */
  Micro_mouse_M->Timing.clockTick1 = Micro_mouse_M->Timing.clockTick0;
  Micro_mouse_DW.TriggeredSubsystem_RESET_ELAP_c = true;

  /* Enable for DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */
  Micro_mouse_DW.DiscreteTimeIntegrator_SYSTEM_o = 1U;

  /* End of Enable for S-Function (HardwareInterrupt_sfun): '<S122>/Hardware Interrupt' */

  /* Enable for S-Function (HardwareInterrupt_sfun): '<S140>/Hardware Interrupt' incorporates:
   *  SubSystem: '<S8>/Triggered Subsystem'
   */

  /* Enable for function-call system: '<S8>/Triggered Subsystem' */
  Micro_mouse_M->Timing.clockTick2 = Micro_mouse_M->Timing.clockTick0;
  Micro_mouse_DW.TriggeredSubsystem_RESET_ELAPS_ = true;

  /* Enable for DiscreteIntegrator: '<S138>/Discrete-Time Integrator' */
  Micro_mouse_DW.DiscreteTimeIntegrator_SYSTEM_E = 1U;

  /* End of Enable for S-Function (HardwareInterrupt_sfun): '<S140>/Hardware Interrupt' */
}

/* Model terminate function */
void Micro_mouse_terminate(void)
{
  /* Terminate for MATLABSystem: '<S115>/Analog to Digital Converter' */
  if (!Micro_mouse_DW.obj.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj.isInitialized == 1) &&
        Micro_mouse_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(Micro_mouse_DW.obj.ADCHandle, ADC_DMA_INTERRUPT_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S115>/Analog to Digital Converter' */
  /* Terminate for MATLABSystem: '<S144>/PWM Output' */
  if (!Micro_mouse_DW.obj_j.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj_j.isInitialized == 1) &&
        Micro_mouse_DW.obj_j.isSetupComplete) {
      disableCounter(Micro_mouse_DW.obj_j.TimerHandle);
      disableTimerInterrupts(Micro_mouse_DW.obj_j.TimerHandle, 0);
      disableTimerChannel1(Micro_mouse_DW.obj_j.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S144>/PWM Output' */

  /* Terminate for MATLABSystem: '<S126>/PWM Output' */
  if (!Micro_mouse_DW.obj_g.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj_g.isInitialized == 1) &&
        Micro_mouse_DW.obj_g.isSetupComplete) {
      disableCounter(Micro_mouse_DW.obj_g.TimerHandle);
      disableTimerInterrupts(Micro_mouse_DW.obj_g.TimerHandle, 0);
      disableTimerChannel1(Micro_mouse_DW.obj_g.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S126>/PWM Output' */
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
        /* S-Function (HardwareInterrupt_sfun): '<S122>/Hardware Interrupt' */

        /* Output and update for function-call system: '<S7>/Triggered Subsystem' */
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

          /* DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */
          if (Micro_mouse_DW.DiscreteTimeIntegrator_SYSTEM_o == 0) {
            /* DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */
            Micro_mouse_DW.DiscreteTimeIntegrator_DSTATE_g += 0.01 * (real_T)
              TriggeredSubsystem_ELAPS_T_n *
              Micro_mouse_DW.DiscreteTimeIntegrator_PREV_U_p;
          }

          /* End of DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */

          /* SignalConversion generated from: '<S120>/Position' */
          Micro_mouse_B.OutportBufferForPosition_a =
            Micro_mouse_DW.DiscreteTimeIntegrator_DSTATE_g;

          /* MATLABSystem: '<S131>/Digital Port Read' */
          TriggeredSubsystem_ELAPS_T_n = LL_GPIO_ReadInputPort(GPIOB);

          /* MATLABSystem: '<S133>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* Update for DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */
          Micro_mouse_DW.DiscreteTimeIntegrator_SYSTEM_o = 0U;

          /* MATLAB Function: '<S120>/MATLAB Function' incorporates:
           *  MATLABSystem: '<S131>/Digital Port Read'
           *  MATLABSystem: '<S133>/Digital Port Read'
           * */
          if (((TriggeredSubsystem_ELAPS_T_n & 8U) != 0U) == ((pinReadLoc & 16U)
               != 0U)) {
            /* Update for DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */
            Micro_mouse_DW.DiscreteTimeIntegrator_PREV_U_p = 1.0;
          } else {
            /* Update for DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */
            Micro_mouse_DW.DiscreteTimeIntegrator_PREV_U_p = -1.0;
          }

          /* End of MATLAB Function: '<S120>/MATLAB Function' */
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S122>/Hardware Interrupt' */
      }
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
        /* S-Function (HardwareInterrupt_sfun): '<S140>/Hardware Interrupt' */

        /* Output and update for function-call system: '<S8>/Triggered Subsystem' */
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

          /* DiscreteIntegrator: '<S138>/Discrete-Time Integrator' */
          if (Micro_mouse_DW.DiscreteTimeIntegrator_SYSTEM_E == 0) {
            /* DiscreteIntegrator: '<S138>/Discrete-Time Integrator' */
            Micro_mouse_DW.DiscreteTimeIntegrator_DSTATE += 0.01 * (real_T)
              TriggeredSubsystem_ELAPS_T
              * Micro_mouse_DW.DiscreteTimeIntegrator_PREV_U;
          }

          /* End of DiscreteIntegrator: '<S138>/Discrete-Time Integrator' */

          /* SignalConversion generated from: '<S138>/Position' */
          Micro_mouse_B.OutportBufferForPosition =
            Micro_mouse_DW.DiscreteTimeIntegrator_DSTATE;

          /* MATLABSystem: '<S149>/Digital Port Read' */
          TriggeredSubsystem_ELAPS_T = LL_GPIO_ReadInputPort(GPIOB);

          /* MATLABSystem: '<S151>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

          /* Update for DiscreteIntegrator: '<S138>/Discrete-Time Integrator' */
          Micro_mouse_DW.DiscreteTimeIntegrator_SYSTEM_E = 0U;

          /* MATLAB Function: '<S138>/MATLAB Function' incorporates:
           *  MATLABSystem: '<S149>/Digital Port Read'
           *  MATLABSystem: '<S151>/Digital Port Read'
           * */
          if (((TriggeredSubsystem_ELAPS_T & 1U) != 0U) == ((pinReadLoc & 2U) !=
               0U)) {
            /* Update for DiscreteIntegrator: '<S138>/Discrete-Time Integrator' */
            Micro_mouse_DW.DiscreteTimeIntegrator_PREV_U = -1.0;
          } else {
            /* Update for DiscreteIntegrator: '<S138>/Discrete-Time Integrator' */
            Micro_mouse_DW.DiscreteTimeIntegrator_PREV_U = 1.0;
          }

          /* End of MATLAB Function: '<S138>/MATLAB Function' */
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S140>/Hardware Interrupt' */
      }
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
