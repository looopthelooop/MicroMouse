/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse.c
 *
 * Code generated for Simulink model 'Micro_mouse'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Mon Apr 28 11:13:01 2025
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
#include "stm_adc_ll.h"
#include "stm_timer_ll.h"

/* Block signals (default storage) */
B_Micro_mouse_T Micro_mouse_B;

/* Continuous states */
X_Micro_mouse_T Micro_mouse_X;

/* Disabled State Vector */
XDis_Micro_mouse_T Micro_mouse_XDis;

/* Block states (default storage) */
DW_Micro_mouse_T Micro_mouse_DW;

/* Real-time model */
static RT_MODEL_Micro_mouse_T Micro_mouse_M_;
RT_MODEL_Micro_mouse_T *const Micro_mouse_M = &Micro_mouse_M_;

/* Forward declaration for local functions */
static void Micro_mouse_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);
static void Micro_mouse_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Mi_T *obj);
static void Micro_mou_PWMOutput_setupImpl_c(stm32cube_blocks_PWMOutput_Mi_T *obj);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Micro_mouse_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Micro_mouse_step();
  Micro_mouse_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Micro_mouse_step();
  Micro_mouse_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

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

  /* Start for MATLABSystem: '<S30>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S30>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S30>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

/* Model step function */
void Micro_mouse_step(void)
{
  if (rtmIsMajorTimeStep(Micro_mouse_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Micro_mouse_M->solverInfo,
                          ((Micro_mouse_M->Timing.clockTick0+1)*
      Micro_mouse_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Micro_mouse_M)) {
    Micro_mouse_M->Timing.t[0] = rtsiGetT(&Micro_mouse_M->solverInfo);
  }

  {
    GPIO_TypeDef * portNameLoc;
    real_T lastTime;
    real_T tmp_0;
    real_T *lastU;
    int32_T i;
    uint32_T pinReadLoc;
    uint16_T rtb_AnalogtoDigitalConverter_0[5];
    boolean_T tmp;
    boolean_T tmp_1;

    /* Reset subsysRan breadcrumbs */
    srClearBC(Micro_mouse_DW.EnabledSubsystem_SubsysRanBC);
    tmp_1 = rtmIsMajorTimeStep(Micro_mouse_M);
    if (tmp_1) {
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
      setDutyCycleInPercentageChannel1(Micro_mouse_DW.obj_j.TimerHandle, 50.0);

      /* MATLABSystem: '<S30>/PWM Output' incorporates:
       *  Constant: '<Root>/Constant'
       */
      setDutyCycleInPercentageChannel1(Micro_mouse_DW.obj_e.TimerHandle, 50.0);

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

      /* MATLABSystem: '<S22>/Digital Port Read' */
      pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

      /* MATLABSystem: '<S22>/Digital Port Read' */
      Micro_mouse_B.DigitalPortRead = ((pinReadLoc & 1U) != 0U);

      /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
       *  EnablePort: '<S19>/Enable'
       */
      if (rtsiIsModeUpdateTimeStep(&Micro_mouse_M->solverInfo)) {
        /* RelationalOperator: '<S16>/FixPt Relational Operator' incorporates:
         *  UnitDelay: '<S16>/Delay Input1'
         *
         * Block description for '<S16>/Delay Input1':
         *
         *  Store in Global RAM
         */
        if (Micro_mouse_B.DigitalPortRead != Micro_mouse_DW.DelayInput1_DSTATE)
        {
          if (!Micro_mouse_DW.EnabledSubsystem_MODE) {
            (void) memset(&(Micro_mouse_XDis.Integrator_CSTATE), 0,
                          1*sizeof(boolean_T));
            Micro_mouse_DW.EnabledSubsystem_MODE = true;
          }
        } else {
          if (((Micro_mouse_M->Timing.clockTick1) * 0.01) == rtmGetTStart
              (Micro_mouse_M)) {
            (void) memset(&(Micro_mouse_XDis.Integrator_CSTATE), 1,
                          1*sizeof(boolean_T));
          }

          if (Micro_mouse_DW.EnabledSubsystem_MODE) {
            (void) memset(&(Micro_mouse_XDis.Integrator_CSTATE), 1,
                          1*sizeof(boolean_T));
            Micro_mouse_DW.EnabledSubsystem_MODE = false;
          }
        }

        /* End of RelationalOperator: '<S16>/FixPt Relational Operator' */
      }

      /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */
    }

    /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S19>/Enable'
     */
    if (Micro_mouse_DW.EnabledSubsystem_MODE) {
      /* Integrator: '<S19>/Integrator' */
      Micro_mouse_B.Integrator = Micro_mouse_X.Integrator_CSTATE;
      tmp = rtmIsMajorTimeStep(Micro_mouse_M);
      if (tmp) {
      }

      /* MATLABSystem: '<S28>/Digital Port Read' */
      pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

      /* DataTypeConversion: '<S19>/Data Type Conversion' incorporates:
       *  MATLABSystem: '<S28>/Digital Port Read'
       * */
      Micro_mouse_B.DataTypeConversion = ((pinReadLoc & 2U) != 0U);
      if (tmp) {
        /* Switch: '<S19>/Switch' incorporates:
         *  Constant: '<S25>/Constant'
         *  DiscreteFir: '<S19>/Discrete FIR Filter'
         *  RelationalOperator: '<S25>/Compare'
         */
        if (Micro_mouse_B.DataTypeConversion * 0.5 +
            Micro_mouse_DW.DiscreteFIRFilter_states * 0.5 >= 0.6) {
          /* Switch: '<S19>/Switch' incorporates:
           *  Constant: '<S19>/Constant'
           */
          Micro_mouse_B.Switch = 1.0;
        } else {
          /* Switch: '<S19>/Switch' incorporates:
           *  Constant: '<S19>/Constant1'
           */
          Micro_mouse_B.Switch = -1.0;
        }

        /* End of Switch: '<S19>/Switch' */
      }

      if (rtsiIsModeUpdateTimeStep(&Micro_mouse_M->solverInfo)) {
        srUpdateBC(Micro_mouse_DW.EnabledSubsystem_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */

    /* Derivative: '<Root>/Derivative' */
    tmp_0 = Micro_mouse_M->Timing.t[0];
    if ((Micro_mouse_DW.TimeStampA >= tmp_0) && (Micro_mouse_DW.TimeStampB >=
         tmp_0)) {
      /* Derivative: '<Root>/Derivative' */
      Micro_mouse_B.speed = 0.0;
    } else {
      lastTime = Micro_mouse_DW.TimeStampA;
      lastU = &Micro_mouse_DW.LastUAtTimeA;
      if (Micro_mouse_DW.TimeStampA < Micro_mouse_DW.TimeStampB) {
        if (Micro_mouse_DW.TimeStampB < tmp_0) {
          lastTime = Micro_mouse_DW.TimeStampB;
          lastU = &Micro_mouse_DW.LastUAtTimeB;
        }
      } else if (Micro_mouse_DW.TimeStampA >= tmp_0) {
        lastTime = Micro_mouse_DW.TimeStampB;
        lastU = &Micro_mouse_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/Derivative' */
      Micro_mouse_B.speed = (Micro_mouse_B.Integrator - *lastU) / (tmp_0 -
        lastTime);
    }

    /* End of Derivative: '<Root>/Derivative' */
    if (tmp_1) {
    }
  }

  if (rtmIsMajorTimeStep(Micro_mouse_M)) {
    real_T *lastU;
    if (rtmIsMajorTimeStep(Micro_mouse_M)) {
      /* Update for UnitDelay: '<S16>/Delay Input1'
       *
       * Block description for '<S16>/Delay Input1':
       *
       *  Store in Global RAM
       */
      Micro_mouse_DW.DelayInput1_DSTATE = Micro_mouse_B.DigitalPortRead;
    }

    /* Update for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S19>/Enable'
     */
    if (Micro_mouse_DW.EnabledSubsystem_MODE && rtmIsMajorTimeStep(Micro_mouse_M))
    {
      /* Update for DiscreteFir: '<S19>/Discrete FIR Filter' */
      /* Update states */
      Micro_mouse_DW.DiscreteFIRFilter_states = Micro_mouse_B.DataTypeConversion;
    }

    /* End of Update for SubSystem: '<S4>/Enabled Subsystem' */

    /* Update for Derivative: '<Root>/Derivative' */
    if (Micro_mouse_DW.TimeStampA == (rtInf)) {
      Micro_mouse_DW.TimeStampA = Micro_mouse_M->Timing.t[0];
      lastU = &Micro_mouse_DW.LastUAtTimeA;
    } else if (Micro_mouse_DW.TimeStampB == (rtInf)) {
      Micro_mouse_DW.TimeStampB = Micro_mouse_M->Timing.t[0];
      lastU = &Micro_mouse_DW.LastUAtTimeB;
    } else if (Micro_mouse_DW.TimeStampA < Micro_mouse_DW.TimeStampB) {
      Micro_mouse_DW.TimeStampA = Micro_mouse_M->Timing.t[0];
      lastU = &Micro_mouse_DW.LastUAtTimeA;
    } else {
      Micro_mouse_DW.TimeStampB = Micro_mouse_M->Timing.t[0];
      lastU = &Micro_mouse_DW.LastUAtTimeB;
    }

    *lastU = Micro_mouse_B.Integrator;

    /* End of Update for Derivative: '<Root>/Derivative' */
    if (rtmIsMajorTimeStep(Micro_mouse_M)) {/* Sample time: [0.01s, 0.0s] */
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
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Micro_mouse_M)) {
    rt_ertODEUpdateContinuousStates(&Micro_mouse_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++Micro_mouse_M->Timing.clockTick0;
    Micro_mouse_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Micro_mouse_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      Micro_mouse_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Micro_mouse_derivatives(void)
{
  XDot_Micro_mouse_T *_rtXdot;
  _rtXdot = ((XDot_Micro_mouse_T *) Micro_mouse_M->derivs);

  /* Derivatives for Enabled SubSystem: '<S4>/Enabled Subsystem' */
  if (Micro_mouse_DW.EnabledSubsystem_MODE) {
    /* Derivatives for Integrator: '<S19>/Integrator' */
    _rtXdot->Integrator_CSTATE = Micro_mouse_B.Switch;
  } else {
    ((XDot_Micro_mouse_T *) Micro_mouse_M->derivs)->Integrator_CSTATE = 0.0;
  }

  /* End of Derivatives for SubSystem: '<S4>/Enabled Subsystem' */
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
    rtsiSetdXPtr(&Micro_mouse_M->solverInfo, &Micro_mouse_M->derivs);
    rtsiSetContStatesPtr(&Micro_mouse_M->solverInfo, (real_T **)
                         &Micro_mouse_M->contStates);
    rtsiSetNumContStatesPtr(&Micro_mouse_M->solverInfo,
      &Micro_mouse_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Micro_mouse_M->solverInfo,
      &Micro_mouse_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Micro_mouse_M->solverInfo,
      &Micro_mouse_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Micro_mouse_M->solverInfo,
      &Micro_mouse_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&Micro_mouse_M->solverInfo, (boolean_T**)
      &Micro_mouse_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&Micro_mouse_M->solverInfo, (&rtmGetErrorStatus
      (Micro_mouse_M)));
    rtsiSetRTModelPtr(&Micro_mouse_M->solverInfo, Micro_mouse_M);
  }

  rtsiSetSimTimeStep(&Micro_mouse_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&Micro_mouse_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&Micro_mouse_M->solverInfo, false);
  Micro_mouse_M->intgData.y = Micro_mouse_M->odeY;
  Micro_mouse_M->intgData.f[0] = Micro_mouse_M->odeF[0];
  Micro_mouse_M->intgData.f[1] = Micro_mouse_M->odeF[1];
  Micro_mouse_M->intgData.f[2] = Micro_mouse_M->odeF[2];
  Micro_mouse_M->contStates = ((X_Micro_mouse_T *) &Micro_mouse_X);
  Micro_mouse_M->contStateDisabled = ((XDis_Micro_mouse_T *) &Micro_mouse_XDis);
  Micro_mouse_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&Micro_mouse_M->solverInfo, (void *)&Micro_mouse_M->intgData);
  rtsiSetSolverName(&Micro_mouse_M->solverInfo,"ode3");
  rtmSetTPtr(Micro_mouse_M, &Micro_mouse_M->Timing.tArray[0]);
  rtmSetTFinal(Micro_mouse_M, -1);
  Micro_mouse_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Micro_mouse_M->Sizes.checksums[0] = (80249019U);
  Micro_mouse_M->Sizes.checksums[1] = (1842384402U);
  Micro_mouse_M->Sizes.checksums[2] = (3501573970U);
  Micro_mouse_M->Sizes.checksums[3] = (2842429549U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    Micro_mouse_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = (sysRanDType *)&Micro_mouse_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[8] = (sysRanDType *)&Micro_mouse_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[9] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Micro_mouse_M->extModeInfo,
      &Micro_mouse_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Micro_mouse_M->extModeInfo,
                        Micro_mouse_M->Sizes.checksums);
    rteiSetTPtr(Micro_mouse_M->extModeInfo, rtmGetTPtr(Micro_mouse_M));
  }

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  Micro_mouse_DW.TimeStampA = (rtInf);
  Micro_mouse_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Integrator: '<S19>/Integrator' */
  Micro_mouse_X.Integrator_CSTATE = 0.0;

  /* End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem' */

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

  /* Start for MATLABSystem: '<S30>/PWM Output' */
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

  /* Terminate for MATLABSystem: '<S30>/PWM Output' */
  if (!Micro_mouse_DW.obj_e.matlabCodegenIsDeleted) {
    Micro_mouse_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Micro_mouse_DW.obj_e.isInitialized == 1) &&
        Micro_mouse_DW.obj_e.isSetupComplete) {
      disableCounter(Micro_mouse_DW.obj_e.TimerHandle);
      disableTimerInterrupts(Micro_mouse_DW.obj_e.TimerHandle, 0);
      disableTimerChannel1(Micro_mouse_DW.obj_e.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S30>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
