/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: testing.h
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

#ifndef testing_h_
#define testing_h_
#ifndef testing_COMMON_INCLUDES_
#define testing_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "math.h"
#include "main.h"
#endif                                 /* testing_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "testing_types.h"
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
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  uint64_T Gain;                       /* '<S1>/Gain' */
  real_T Ratio;                        /* '<S8>/Ratio' */
  real_T Diff;                         /* '<S136>/Diff' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T Saturation1;                  /* '<Root>/Saturation1' */
  real_T Ratio_c;                      /* '<S7>/Ratio' */
  real_T Diff_a;                       /* '<S118>/Diff' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T TmpRTBAtScopeInport1;         /* '<S8>/Triggered Subsystem' */
  real_T DiscreteTimeIntegrator;       /* '<S138>/Discrete-Time Integrator' */
  real_T OutportBufferForPosition;     /* '<S138>/OutportBufferForPosition' */
  real_T OutportBufferForPosition_a;   /* '<S120>/Discrete-Time Integrator' */
  uint32_T SignalConversion4;          /* '<S6>/Signal Conversion4' */
  uint32_T SignalConversion;           /* '<S6>/Signal Conversion' */
  uint32_T Sum2;                       /* '<S1>/Sum2' */
  boolean_T DigitalPortRead;           /* '<S149>/Digital Port Read' */
} B_testing_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj;/* '<S115>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_te_T obj_i;/* '<S144>/PWM Output' */
  stm32cube_blocks_PWMOutput_te_T obj_n;/* '<S126>/PWM Output' */
  real_T UD_DSTATE;                    /* '<S136>/UD' */
  real_T Integrator_DSTATE;            /* '<S43>/Integrator' */
  real_T Filter_DSTATE;                /* '<S38>/Filter' */
  real_T UD_DSTATE_f;                  /* '<S118>/UD' */
  real_T Filter_DSTATE_d;              /* '<S90>/Filter' */
  real_T Integrator_DSTATE_m;          /* '<S95>/Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S138>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_e;/* '<S120>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_PREV_U;/* '<S138>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_PREV_U_m;/* '<S120>/Discrete-Time Integrator' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S1>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<S1>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_g;                    /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope_PWORK_i;                     /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_g;                    /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_k;                     /* '<S8>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_o;                     /* '<S138>/Scope' */

  uint32_T TriggeredSubsystem_PREV_T;  /* '<S8>/Triggered Subsystem' */
  uint32_T TriggeredSubsystem_PREV_T_k;/* '<S7>/Triggered Subsystem' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S8>/Triggered Subsystem' */
  int8_T TriggeredSubsystem_SubsysRanB_g;/* '<S7>/Triggered Subsystem' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S138>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_e;/* '<S120>/Discrete-Time Integrator' */
  boolean_T TriggeredSubsystem_RESET_ELAPS_;/* '<S8>/Triggered Subsystem' */
  boolean_T TriggeredSubsystem_RESET_ELAP_d;/* '<S7>/Triggered Subsystem' */
} DW_testing_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T position;                     /* '<Root>/position' */
  real_T position1;                    /* '<Root>/position1' */
  real_T speed;                        /* '<Root>/speed' */
  real_T speed2;                       /* '<Root>/speed2' */
} ExtY_testing_T;

/* Real-time Model Data Structure */
struct tag_RTM_testing_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

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
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    time_T tFinal;
    boolean_T stopRequestedFlag;
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
 * Block '<S6>/Signal Conversion1' : Unused code path elimination
 * Block '<S6>/Signal Conversion2' : Unused code path elimination
 * Block '<S6>/Signal Conversion3' : Unused code path elimination
 * Block '<S118>/Data Type Duplicate' : Unused code path elimination
 * Block '<S136>/Data Type Duplicate' : Unused code path elimination
 * Block '<S48>/Proportional Gain' : Eliminated nontunable gain of 1
 * Block '<S100>/Proportional Gain' : Eliminated nontunable gain of 1
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
 * '<S4>'   : 'testing/Discrete PID Controller'
 * '<S5>'   : 'testing/Discrete PID Controller1'
 * '<S6>'   : 'testing/IR'
 * '<S7>'   : 'testing/Left Motor'
 * '<S8>'   : 'testing/Right Motor'
 * '<S9>'   : 'testing/Discrete PID Controller/Anti-windup'
 * '<S10>'  : 'testing/Discrete PID Controller/D Gain'
 * '<S11>'  : 'testing/Discrete PID Controller/External Derivative'
 * '<S12>'  : 'testing/Discrete PID Controller/Filter'
 * '<S13>'  : 'testing/Discrete PID Controller/Filter ICs'
 * '<S14>'  : 'testing/Discrete PID Controller/I Gain'
 * '<S15>'  : 'testing/Discrete PID Controller/Ideal P Gain'
 * '<S16>'  : 'testing/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S17>'  : 'testing/Discrete PID Controller/Integrator'
 * '<S18>'  : 'testing/Discrete PID Controller/Integrator ICs'
 * '<S19>'  : 'testing/Discrete PID Controller/N Copy'
 * '<S20>'  : 'testing/Discrete PID Controller/N Gain'
 * '<S21>'  : 'testing/Discrete PID Controller/P Copy'
 * '<S22>'  : 'testing/Discrete PID Controller/Parallel P Gain'
 * '<S23>'  : 'testing/Discrete PID Controller/Reset Signal'
 * '<S24>'  : 'testing/Discrete PID Controller/Saturation'
 * '<S25>'  : 'testing/Discrete PID Controller/Saturation Fdbk'
 * '<S26>'  : 'testing/Discrete PID Controller/Sum'
 * '<S27>'  : 'testing/Discrete PID Controller/Sum Fdbk'
 * '<S28>'  : 'testing/Discrete PID Controller/Tracking Mode'
 * '<S29>'  : 'testing/Discrete PID Controller/Tracking Mode Sum'
 * '<S30>'  : 'testing/Discrete PID Controller/Tsamp - Integral'
 * '<S31>'  : 'testing/Discrete PID Controller/Tsamp - Ngain'
 * '<S32>'  : 'testing/Discrete PID Controller/postSat Signal'
 * '<S33>'  : 'testing/Discrete PID Controller/preInt Signal'
 * '<S34>'  : 'testing/Discrete PID Controller/preSat Signal'
 * '<S35>'  : 'testing/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S36>'  : 'testing/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S37>'  : 'testing/Discrete PID Controller/External Derivative/Error'
 * '<S38>'  : 'testing/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S39>'  : 'testing/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S40>'  : 'testing/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S41>'  : 'testing/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S42>'  : 'testing/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S43>'  : 'testing/Discrete PID Controller/Integrator/Discrete'
 * '<S44>'  : 'testing/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S45>'  : 'testing/Discrete PID Controller/N Copy/Disabled'
 * '<S46>'  : 'testing/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S47>'  : 'testing/Discrete PID Controller/P Copy/Disabled'
 * '<S48>'  : 'testing/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S49>'  : 'testing/Discrete PID Controller/Reset Signal/Disabled'
 * '<S50>'  : 'testing/Discrete PID Controller/Saturation/Passthrough'
 * '<S51>'  : 'testing/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S52>'  : 'testing/Discrete PID Controller/Sum/Sum_PID'
 * '<S53>'  : 'testing/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S54>'  : 'testing/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S55>'  : 'testing/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S56>'  : 'testing/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S57>'  : 'testing/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S58>'  : 'testing/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S59>'  : 'testing/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S60>'  : 'testing/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S61>'  : 'testing/Discrete PID Controller1/Anti-windup'
 * '<S62>'  : 'testing/Discrete PID Controller1/D Gain'
 * '<S63>'  : 'testing/Discrete PID Controller1/External Derivative'
 * '<S64>'  : 'testing/Discrete PID Controller1/Filter'
 * '<S65>'  : 'testing/Discrete PID Controller1/Filter ICs'
 * '<S66>'  : 'testing/Discrete PID Controller1/I Gain'
 * '<S67>'  : 'testing/Discrete PID Controller1/Ideal P Gain'
 * '<S68>'  : 'testing/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S69>'  : 'testing/Discrete PID Controller1/Integrator'
 * '<S70>'  : 'testing/Discrete PID Controller1/Integrator ICs'
 * '<S71>'  : 'testing/Discrete PID Controller1/N Copy'
 * '<S72>'  : 'testing/Discrete PID Controller1/N Gain'
 * '<S73>'  : 'testing/Discrete PID Controller1/P Copy'
 * '<S74>'  : 'testing/Discrete PID Controller1/Parallel P Gain'
 * '<S75>'  : 'testing/Discrete PID Controller1/Reset Signal'
 * '<S76>'  : 'testing/Discrete PID Controller1/Saturation'
 * '<S77>'  : 'testing/Discrete PID Controller1/Saturation Fdbk'
 * '<S78>'  : 'testing/Discrete PID Controller1/Sum'
 * '<S79>'  : 'testing/Discrete PID Controller1/Sum Fdbk'
 * '<S80>'  : 'testing/Discrete PID Controller1/Tracking Mode'
 * '<S81>'  : 'testing/Discrete PID Controller1/Tracking Mode Sum'
 * '<S82>'  : 'testing/Discrete PID Controller1/Tsamp - Integral'
 * '<S83>'  : 'testing/Discrete PID Controller1/Tsamp - Ngain'
 * '<S84>'  : 'testing/Discrete PID Controller1/postSat Signal'
 * '<S85>'  : 'testing/Discrete PID Controller1/preInt Signal'
 * '<S86>'  : 'testing/Discrete PID Controller1/preSat Signal'
 * '<S87>'  : 'testing/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S88>'  : 'testing/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S89>'  : 'testing/Discrete PID Controller1/External Derivative/Error'
 * '<S90>'  : 'testing/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S91>'  : 'testing/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S92>'  : 'testing/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S93>'  : 'testing/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S94>'  : 'testing/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S95>'  : 'testing/Discrete PID Controller1/Integrator/Discrete'
 * '<S96>'  : 'testing/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S97>'  : 'testing/Discrete PID Controller1/N Copy/Disabled'
 * '<S98>'  : 'testing/Discrete PID Controller1/N Gain/Internal Parameters'
 * '<S99>'  : 'testing/Discrete PID Controller1/P Copy/Disabled'
 * '<S100>' : 'testing/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S101>' : 'testing/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S102>' : 'testing/Discrete PID Controller1/Saturation/Passthrough'
 * '<S103>' : 'testing/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S104>' : 'testing/Discrete PID Controller1/Sum/Sum_PID'
 * '<S105>' : 'testing/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S106>' : 'testing/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S107>' : 'testing/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S108>' : 'testing/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S109>' : 'testing/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S110>' : 'testing/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S111>' : 'testing/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S112>' : 'testing/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S113>' : 'testing/IR/Analog to Digital Converter'
 * '<S114>' : 'testing/IR/Analog to Digital Converter/ECSoC'
 * '<S115>' : 'testing/IR/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S116>' : 'testing/Left Motor/Channel A'
 * '<S117>' : 'testing/Left Motor/Direction'
 * '<S118>' : 'testing/Left Motor/Discrete Derivative'
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
 * '<S136>' : 'testing/Right Motor/Discrete Derivative'
 * '<S137>' : 'testing/Right Motor/PWM'
 * '<S138>' : 'testing/Right Motor/Triggered Subsystem'
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
