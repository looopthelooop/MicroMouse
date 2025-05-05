/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: testing.h
 *
 * Code generated for Simulink model 'testing'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Mon May  5 14:35:01 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef testing_h_
#define testing_h_
#ifndef testing_COMMON_INCLUDES_
#define testing_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "ext_mode.h"
#include "main.h"
#endif                                 /* testing_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "testing_types.h"
#include "rtGetInf.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  uint64_T Gain;                       /* '<S1>/Gain' */
  real_T Ratio;                        /* '<S8>/Ratio' */
  real_T Ratio_p;                      /* '<S9>/Ratio' */
  real_T Derivative;                   /* '<Root>/Derivative' */
  real_T Saturation1;                  /* '<Root>/Saturation1' */
  real_T SumofElements;                /* '<S138>/Sum of Elements' */
  real_T delta;                        /* '<S137>/MATLAB Function' */
  real_T OutportBufferForPosition;     /* '<S120>/Discrete-Time Integrator' */
  uint32_T SignalConversion4;          /* '<S7>/Signal Conversion4' */
  uint32_T SignalConversion;           /* '<S7>/Signal Conversion' */
  uint32_T Sum2;                       /* '<S1>/Sum2' */
  boolean_T DigitalPortRead;           /* '<S149>/Digital Port Read' */
} B_testing_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj;/* '<S116>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_te_T obj_i;/* '<S144>/PWM Output' */
  stm32cube_blocks_PWMOutput_te_T obj_n;/* '<S126>/PWM Output' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S9>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE;            /* '<S44>/Integrator' */
  real_T Filter_DSTATE;                /* '<S39>/Filter' */
  real_T Integrator_DSTATE_d;          /* '<S96>/Integrator' */
  real_T Filter_DSTATE_o;              /* '<S91>/Filter' */
  real_T DiscreteTimeIntegrator_DSTATE_e;/* '<S120>/Discrete-Time Integrator' */
  real_T TimeStampA;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative' */
  real_T TimeStampB;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative' */
  real_T DiscreteTimeIntegrator_PREV_U;/* '<S120>/Discrete-Time Integrator' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<S1>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S1>/Scope2' */

  uint32_T TriggeredSubsystem_PREV_T;  /* '<S8>/Triggered Subsystem' */
  int8_T TriggeredSubsystem1_SubsysRanBC;/* '<S9>/Triggered Subsystem1' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S9>/Triggered Subsystem' */
  int8_T TriggeredSubsystem_SubsysRanB_g;/* '<S8>/Triggered Subsystem' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S120>/Discrete-Time Integrator' */
  boolean_T TriggeredSubsystem_RESET_ELAPS_;/* '<S8>/Triggered Subsystem' */
} DW_testing_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T position;                     /* '<Root>/position' */
  real_T position1;                    /* '<Root>/position1' */
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_testing_T;

/* Real-time Model Data Structure */
struct tag_RTM_testing_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    uint32_T clockTick3;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[4];
  } Timing;
};

/* Block signals (default storage) */
extern B_testing_T testing_B;

/* Block states (default storage) */
extern DW_testing_T testing_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_testing_T testing_Y;

/* Model entry point functions */
extern void testing_initialize(void);
extern void testing_step(void);
extern void testing_terminate(void);

/* Real-time Model object */
extern RT_MODEL_testing_T *const testing_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  void EXTI3_IRQHandler(void);
  void EXTI0_IRQHandler(void);
  void testing_configure_interrupts (void);
  void testing_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/Diff' : Unused code path elimination
 * Block '<S4>/TSamp' : Unused code path elimination
 * Block '<S4>/UD' : Unused code path elimination
 * Block '<S7>/Signal Conversion1' : Unused code path elimination
 * Block '<S7>/Signal Conversion2' : Unused code path elimination
 * Block '<S7>/Signal Conversion3' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'testing'
 * '<S1>'   : 'testing/Centering'
 * '<S2>'   : 'testing/Compare To Constant'
 * '<S3>'   : 'testing/Compare To Constant1'
 * '<S4>'   : 'testing/Discrete Derivative'
 * '<S5>'   : 'testing/Discrete PID Controller'
 * '<S6>'   : 'testing/Discrete PID Controller1'
 * '<S7>'   : 'testing/IR'
 * '<S8>'   : 'testing/Left Motor'
 * '<S9>'   : 'testing/Right Motor'
 * '<S10>'  : 'testing/Discrete PID Controller/Anti-windup'
 * '<S11>'  : 'testing/Discrete PID Controller/D Gain'
 * '<S12>'  : 'testing/Discrete PID Controller/External Derivative'
 * '<S13>'  : 'testing/Discrete PID Controller/Filter'
 * '<S14>'  : 'testing/Discrete PID Controller/Filter ICs'
 * '<S15>'  : 'testing/Discrete PID Controller/I Gain'
 * '<S16>'  : 'testing/Discrete PID Controller/Ideal P Gain'
 * '<S17>'  : 'testing/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S18>'  : 'testing/Discrete PID Controller/Integrator'
 * '<S19>'  : 'testing/Discrete PID Controller/Integrator ICs'
 * '<S20>'  : 'testing/Discrete PID Controller/N Copy'
 * '<S21>'  : 'testing/Discrete PID Controller/N Gain'
 * '<S22>'  : 'testing/Discrete PID Controller/P Copy'
 * '<S23>'  : 'testing/Discrete PID Controller/Parallel P Gain'
 * '<S24>'  : 'testing/Discrete PID Controller/Reset Signal'
 * '<S25>'  : 'testing/Discrete PID Controller/Saturation'
 * '<S26>'  : 'testing/Discrete PID Controller/Saturation Fdbk'
 * '<S27>'  : 'testing/Discrete PID Controller/Sum'
 * '<S28>'  : 'testing/Discrete PID Controller/Sum Fdbk'
 * '<S29>'  : 'testing/Discrete PID Controller/Tracking Mode'
 * '<S30>'  : 'testing/Discrete PID Controller/Tracking Mode Sum'
 * '<S31>'  : 'testing/Discrete PID Controller/Tsamp - Integral'
 * '<S32>'  : 'testing/Discrete PID Controller/Tsamp - Ngain'
 * '<S33>'  : 'testing/Discrete PID Controller/postSat Signal'
 * '<S34>'  : 'testing/Discrete PID Controller/preInt Signal'
 * '<S35>'  : 'testing/Discrete PID Controller/preSat Signal'
 * '<S36>'  : 'testing/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S37>'  : 'testing/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S38>'  : 'testing/Discrete PID Controller/External Derivative/Error'
 * '<S39>'  : 'testing/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S40>'  : 'testing/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S41>'  : 'testing/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S42>'  : 'testing/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S43>'  : 'testing/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S44>'  : 'testing/Discrete PID Controller/Integrator/Discrete'
 * '<S45>'  : 'testing/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S46>'  : 'testing/Discrete PID Controller/N Copy/Disabled'
 * '<S47>'  : 'testing/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S48>'  : 'testing/Discrete PID Controller/P Copy/Disabled'
 * '<S49>'  : 'testing/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S50>'  : 'testing/Discrete PID Controller/Reset Signal/Disabled'
 * '<S51>'  : 'testing/Discrete PID Controller/Saturation/Passthrough'
 * '<S52>'  : 'testing/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S53>'  : 'testing/Discrete PID Controller/Sum/Sum_PID'
 * '<S54>'  : 'testing/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S55>'  : 'testing/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S56>'  : 'testing/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S57>'  : 'testing/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S58>'  : 'testing/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S59>'  : 'testing/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S60>'  : 'testing/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S61>'  : 'testing/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S62>'  : 'testing/Discrete PID Controller1/Anti-windup'
 * '<S63>'  : 'testing/Discrete PID Controller1/D Gain'
 * '<S64>'  : 'testing/Discrete PID Controller1/External Derivative'
 * '<S65>'  : 'testing/Discrete PID Controller1/Filter'
 * '<S66>'  : 'testing/Discrete PID Controller1/Filter ICs'
 * '<S67>'  : 'testing/Discrete PID Controller1/I Gain'
 * '<S68>'  : 'testing/Discrete PID Controller1/Ideal P Gain'
 * '<S69>'  : 'testing/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S70>'  : 'testing/Discrete PID Controller1/Integrator'
 * '<S71>'  : 'testing/Discrete PID Controller1/Integrator ICs'
 * '<S72>'  : 'testing/Discrete PID Controller1/N Copy'
 * '<S73>'  : 'testing/Discrete PID Controller1/N Gain'
 * '<S74>'  : 'testing/Discrete PID Controller1/P Copy'
 * '<S75>'  : 'testing/Discrete PID Controller1/Parallel P Gain'
 * '<S76>'  : 'testing/Discrete PID Controller1/Reset Signal'
 * '<S77>'  : 'testing/Discrete PID Controller1/Saturation'
 * '<S78>'  : 'testing/Discrete PID Controller1/Saturation Fdbk'
 * '<S79>'  : 'testing/Discrete PID Controller1/Sum'
 * '<S80>'  : 'testing/Discrete PID Controller1/Sum Fdbk'
 * '<S81>'  : 'testing/Discrete PID Controller1/Tracking Mode'
 * '<S82>'  : 'testing/Discrete PID Controller1/Tracking Mode Sum'
 * '<S83>'  : 'testing/Discrete PID Controller1/Tsamp - Integral'
 * '<S84>'  : 'testing/Discrete PID Controller1/Tsamp - Ngain'
 * '<S85>'  : 'testing/Discrete PID Controller1/postSat Signal'
 * '<S86>'  : 'testing/Discrete PID Controller1/preInt Signal'
 * '<S87>'  : 'testing/Discrete PID Controller1/preSat Signal'
 * '<S88>'  : 'testing/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S89>'  : 'testing/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S90>'  : 'testing/Discrete PID Controller1/External Derivative/Error'
 * '<S91>'  : 'testing/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S92>'  : 'testing/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S93>'  : 'testing/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S94>'  : 'testing/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S95>'  : 'testing/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S96>'  : 'testing/Discrete PID Controller1/Integrator/Discrete'
 * '<S97>'  : 'testing/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S98>'  : 'testing/Discrete PID Controller1/N Copy/Disabled'
 * '<S99>'  : 'testing/Discrete PID Controller1/N Gain/Internal Parameters'
 * '<S100>' : 'testing/Discrete PID Controller1/P Copy/Disabled'
 * '<S101>' : 'testing/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S102>' : 'testing/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S103>' : 'testing/Discrete PID Controller1/Saturation/Passthrough'
 * '<S104>' : 'testing/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S105>' : 'testing/Discrete PID Controller1/Sum/Sum_PID'
 * '<S106>' : 'testing/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S107>' : 'testing/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S108>' : 'testing/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S109>' : 'testing/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S110>' : 'testing/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S111>' : 'testing/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S112>' : 'testing/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S113>' : 'testing/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S114>' : 'testing/IR/Analog to Digital Converter'
 * '<S115>' : 'testing/IR/Analog to Digital Converter/ECSoC'
 * '<S116>' : 'testing/IR/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S117>' : 'testing/Left Motor/Channel A'
 * '<S118>' : 'testing/Left Motor/Direction'
 * '<S119>' : 'testing/Left Motor/PWM'
 * '<S120>' : 'testing/Left Motor/Triggered Subsystem'
 * '<S121>' : 'testing/Left Motor/Channel A/ECSoC'
 * '<S122>' : 'testing/Left Motor/Channel A/ECSoC/ECSimCodegen'
 * '<S123>' : 'testing/Left Motor/Direction/ECSoC'
 * '<S124>' : 'testing/Left Motor/Direction/ECSoC/ECSimCodegen'
 * '<S125>' : 'testing/Left Motor/PWM/ECSoC'
 * '<S126>' : 'testing/Left Motor/PWM/ECSoC/ECSimCodegen'
 * '<S127>' : 'testing/Left Motor/Triggered Subsystem/MATLAB Function'
 * '<S128>' : 'testing/Left Motor/Triggered Subsystem/PB0 (currA)'
 * '<S129>' : 'testing/Left Motor/Triggered Subsystem/PB1 (currB)'
 * '<S130>' : 'testing/Left Motor/Triggered Subsystem/PB0 (currA)/ECSoC'
 * '<S131>' : 'testing/Left Motor/Triggered Subsystem/PB0 (currA)/ECSoC/ECSimCodegen'
 * '<S132>' : 'testing/Left Motor/Triggered Subsystem/PB1 (currB)/ECSoC'
 * '<S133>' : 'testing/Left Motor/Triggered Subsystem/PB1 (currB)/ECSoC/ECSimCodegen'
 * '<S134>' : 'testing/Right Motor/Channel A'
 * '<S135>' : 'testing/Right Motor/Direction'
 * '<S136>' : 'testing/Right Motor/PWM'
 * '<S137>' : 'testing/Right Motor/Triggered Subsystem'
 * '<S138>' : 'testing/Right Motor/Triggered Subsystem1'
 * '<S139>' : 'testing/Right Motor/Channel A/ECSoC'
 * '<S140>' : 'testing/Right Motor/Channel A/ECSoC/ECSimCodegen'
 * '<S141>' : 'testing/Right Motor/Direction/ECSoC'
 * '<S142>' : 'testing/Right Motor/Direction/ECSoC/ECSimCodegen'
 * '<S143>' : 'testing/Right Motor/PWM/ECSoC'
 * '<S144>' : 'testing/Right Motor/PWM/ECSoC/ECSimCodegen'
 * '<S145>' : 'testing/Right Motor/Triggered Subsystem/MATLAB Function'
 * '<S146>' : 'testing/Right Motor/Triggered Subsystem/PB0 (currA)'
 * '<S147>' : 'testing/Right Motor/Triggered Subsystem/PB1 (currB)'
 * '<S148>' : 'testing/Right Motor/Triggered Subsystem/PB0 (currA)/ECSoC'
 * '<S149>' : 'testing/Right Motor/Triggered Subsystem/PB0 (currA)/ECSoC/ECSimCodegen'
 * '<S150>' : 'testing/Right Motor/Triggered Subsystem/PB1 (currB)/ECSoC'
 * '<S151>' : 'testing/Right Motor/Triggered Subsystem/PB1 (currB)/ECSoC/ECSimCodegen'
 */
#endif                                 /* testing_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
