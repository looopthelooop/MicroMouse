/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse.h
 *
 * Code generated for Simulink model 'Micro_mouse'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Apr 29 19:44:56 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Micro_mouse_h_
#define Micro_mouse_h_
#ifndef Micro_mouse_COMMON_INCLUDES_
#define Micro_mouse_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#include "main.h"
#endif                                 /* Micro_mouse_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "Micro_mouse_types.h"
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
  real_T Ratio;                        /* '<S5>/Ratio' */
  real_T Ratio_l;                      /* '<S6>/Ratio' */
  real_T OutportBufferForPosition;     /* '<S136>/Discrete-Time Integrator' */
  real_T OutportBufferForPosition_a;   /* '<S118>/Discrete-Time Integrator' */
  uint32_T SignalConversion4;          /* '<S4>/Signal Conversion4' */
  uint32_T SignalConversion;           /* '<S4>/Signal Conversion' */
  uint32_T Sum2;                       /* '<S1>/Sum2' */
} B_Micro_mouse_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj;/* '<S113>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_Mi_T obj_j;/* '<S142>/PWM Output' */
  stm32cube_blocks_PWMOutput_Mi_T obj_g;/* '<S124>/PWM Output' */
  real_T Integrator_DSTATE;            /* '<S41>/Integrator' */
  real_T Filter_DSTATE;                /* '<S36>/Filter' */
  real_T Integrator_DSTATE_e;          /* '<S93>/Integrator' */
  real_T Filter_DSTATE_d;              /* '<S88>/Filter' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S136>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_g;/* '<S118>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_PREV_U;/* '<S136>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_PREV_U_p;/* '<S118>/Discrete-Time Integrator' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_l;                     /* '<S1>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S1>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<S1>/Scope1' */

  uint32_T TriggeredSubsystem_PREV_T;  /* '<S6>/Triggered Subsystem' */
  uint32_T TriggeredSubsystem_PREV_T_c;/* '<S5>/Triggered Subsystem' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S6>/Triggered Subsystem' */
  int8_T TriggeredSubsystem_SubsysRanB_a;/* '<S5>/Triggered Subsystem' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S136>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_o;/* '<S118>/Discrete-Time Integrator' */
  boolean_T TriggeredSubsystem_RESET_ELAPS_;/* '<S6>/Triggered Subsystem' */
  boolean_T TriggeredSubsystem_RESET_ELAP_c;/* '<S5>/Triggered Subsystem' */
} DW_Micro_mouse_T;

/* Invariant block signals (default storage) */
typedef struct {
  const boolean_T NOT;                 /* '<S5>/NOT' */
} ConstB_Micro_mouse_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Ref;                          /* '<Root>/Ref' */
  real_T Ref1;                         /* '<Root>/Ref1' */
} ExtU_Micro_mouse_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T position;                     /* '<Root>/position' */
  real_T position1;                    /* '<Root>/position1' */
} ExtY_Micro_mouse_T;

/* Real-time Model Data Structure */
struct tag_RTM_Micro_mouse_T {
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
extern B_Micro_mouse_T Micro_mouse_B;

/* Block states (default storage) */
extern DW_Micro_mouse_T Micro_mouse_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Micro_mouse_T Micro_mouse_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Micro_mouse_T Micro_mouse_Y;
extern const ConstB_Micro_mouse_T Micro_mouse_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void Micro_mouse_initialize(void);
extern void Micro_mouse_step(void);
extern void Micro_mouse_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Micro_mouse_T *const Micro_mouse_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  void EXTI3_IRQHandler(void);
  void EXTI0_IRQHandler(void);
  void Micro_mouse_configure_interrupts (void);
  void Micro_mouse_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Signal Conversion1' : Unused code path elimination
 * Block '<S4>/Signal Conversion2' : Unused code path elimination
 * Block '<S4>/Signal Conversion3' : Unused code path elimination
 * Block '<S116>/Data Type Duplicate' : Unused code path elimination
 * Block '<S116>/Diff' : Unused code path elimination
 * Block '<S116>/TSamp' : Unused code path elimination
 * Block '<S116>/UD' : Unused code path elimination
 * Block '<S134>/Data Type Duplicate' : Unused code path elimination
 * Block '<S134>/Diff' : Unused code path elimination
 * Block '<S134>/TSamp' : Unused code path elimination
 * Block '<S134>/UD' : Unused code path elimination
 * Block '<S38>/Integral Gain' : Eliminated nontunable gain of 1
 * Block '<S46>/Proportional Gain' : Eliminated nontunable gain of 1
 * Block '<S90>/Integral Gain' : Eliminated nontunable gain of 1
 * Block '<S98>/Proportional Gain' : Eliminated nontunable gain of 1
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
 * '<Root>' : 'Micro_mouse'
 * '<S1>'   : 'Micro_mouse/Centering'
 * '<S2>'   : 'Micro_mouse/Discrete PID Controller'
 * '<S3>'   : 'Micro_mouse/Discrete PID Controller1'
 * '<S4>'   : 'Micro_mouse/IR'
 * '<S5>'   : 'Micro_mouse/Left Motor'
 * '<S6>'   : 'Micro_mouse/Right Motor'
 * '<S7>'   : 'Micro_mouse/Discrete PID Controller/Anti-windup'
 * '<S8>'   : 'Micro_mouse/Discrete PID Controller/D Gain'
 * '<S9>'   : 'Micro_mouse/Discrete PID Controller/External Derivative'
 * '<S10>'  : 'Micro_mouse/Discrete PID Controller/Filter'
 * '<S11>'  : 'Micro_mouse/Discrete PID Controller/Filter ICs'
 * '<S12>'  : 'Micro_mouse/Discrete PID Controller/I Gain'
 * '<S13>'  : 'Micro_mouse/Discrete PID Controller/Ideal P Gain'
 * '<S14>'  : 'Micro_mouse/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S15>'  : 'Micro_mouse/Discrete PID Controller/Integrator'
 * '<S16>'  : 'Micro_mouse/Discrete PID Controller/Integrator ICs'
 * '<S17>'  : 'Micro_mouse/Discrete PID Controller/N Copy'
 * '<S18>'  : 'Micro_mouse/Discrete PID Controller/N Gain'
 * '<S19>'  : 'Micro_mouse/Discrete PID Controller/P Copy'
 * '<S20>'  : 'Micro_mouse/Discrete PID Controller/Parallel P Gain'
 * '<S21>'  : 'Micro_mouse/Discrete PID Controller/Reset Signal'
 * '<S22>'  : 'Micro_mouse/Discrete PID Controller/Saturation'
 * '<S23>'  : 'Micro_mouse/Discrete PID Controller/Saturation Fdbk'
 * '<S24>'  : 'Micro_mouse/Discrete PID Controller/Sum'
 * '<S25>'  : 'Micro_mouse/Discrete PID Controller/Sum Fdbk'
 * '<S26>'  : 'Micro_mouse/Discrete PID Controller/Tracking Mode'
 * '<S27>'  : 'Micro_mouse/Discrete PID Controller/Tracking Mode Sum'
 * '<S28>'  : 'Micro_mouse/Discrete PID Controller/Tsamp - Integral'
 * '<S29>'  : 'Micro_mouse/Discrete PID Controller/Tsamp - Ngain'
 * '<S30>'  : 'Micro_mouse/Discrete PID Controller/postSat Signal'
 * '<S31>'  : 'Micro_mouse/Discrete PID Controller/preInt Signal'
 * '<S32>'  : 'Micro_mouse/Discrete PID Controller/preSat Signal'
 * '<S33>'  : 'Micro_mouse/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S34>'  : 'Micro_mouse/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S35>'  : 'Micro_mouse/Discrete PID Controller/External Derivative/Error'
 * '<S36>'  : 'Micro_mouse/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S37>'  : 'Micro_mouse/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S38>'  : 'Micro_mouse/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S39>'  : 'Micro_mouse/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S40>'  : 'Micro_mouse/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S41>'  : 'Micro_mouse/Discrete PID Controller/Integrator/Discrete'
 * '<S42>'  : 'Micro_mouse/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S43>'  : 'Micro_mouse/Discrete PID Controller/N Copy/Disabled'
 * '<S44>'  : 'Micro_mouse/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S45>'  : 'Micro_mouse/Discrete PID Controller/P Copy/Disabled'
 * '<S46>'  : 'Micro_mouse/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S47>'  : 'Micro_mouse/Discrete PID Controller/Reset Signal/Disabled'
 * '<S48>'  : 'Micro_mouse/Discrete PID Controller/Saturation/Passthrough'
 * '<S49>'  : 'Micro_mouse/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S50>'  : 'Micro_mouse/Discrete PID Controller/Sum/Sum_PID'
 * '<S51>'  : 'Micro_mouse/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S52>'  : 'Micro_mouse/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S53>'  : 'Micro_mouse/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S54>'  : 'Micro_mouse/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S55>'  : 'Micro_mouse/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S56>'  : 'Micro_mouse/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S57>'  : 'Micro_mouse/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S58>'  : 'Micro_mouse/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S59>'  : 'Micro_mouse/Discrete PID Controller1/Anti-windup'
 * '<S60>'  : 'Micro_mouse/Discrete PID Controller1/D Gain'
 * '<S61>'  : 'Micro_mouse/Discrete PID Controller1/External Derivative'
 * '<S62>'  : 'Micro_mouse/Discrete PID Controller1/Filter'
 * '<S63>'  : 'Micro_mouse/Discrete PID Controller1/Filter ICs'
 * '<S64>'  : 'Micro_mouse/Discrete PID Controller1/I Gain'
 * '<S65>'  : 'Micro_mouse/Discrete PID Controller1/Ideal P Gain'
 * '<S66>'  : 'Micro_mouse/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S67>'  : 'Micro_mouse/Discrete PID Controller1/Integrator'
 * '<S68>'  : 'Micro_mouse/Discrete PID Controller1/Integrator ICs'
 * '<S69>'  : 'Micro_mouse/Discrete PID Controller1/N Copy'
 * '<S70>'  : 'Micro_mouse/Discrete PID Controller1/N Gain'
 * '<S71>'  : 'Micro_mouse/Discrete PID Controller1/P Copy'
 * '<S72>'  : 'Micro_mouse/Discrete PID Controller1/Parallel P Gain'
 * '<S73>'  : 'Micro_mouse/Discrete PID Controller1/Reset Signal'
 * '<S74>'  : 'Micro_mouse/Discrete PID Controller1/Saturation'
 * '<S75>'  : 'Micro_mouse/Discrete PID Controller1/Saturation Fdbk'
 * '<S76>'  : 'Micro_mouse/Discrete PID Controller1/Sum'
 * '<S77>'  : 'Micro_mouse/Discrete PID Controller1/Sum Fdbk'
 * '<S78>'  : 'Micro_mouse/Discrete PID Controller1/Tracking Mode'
 * '<S79>'  : 'Micro_mouse/Discrete PID Controller1/Tracking Mode Sum'
 * '<S80>'  : 'Micro_mouse/Discrete PID Controller1/Tsamp - Integral'
 * '<S81>'  : 'Micro_mouse/Discrete PID Controller1/Tsamp - Ngain'
 * '<S82>'  : 'Micro_mouse/Discrete PID Controller1/postSat Signal'
 * '<S83>'  : 'Micro_mouse/Discrete PID Controller1/preInt Signal'
 * '<S84>'  : 'Micro_mouse/Discrete PID Controller1/preSat Signal'
 * '<S85>'  : 'Micro_mouse/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S86>'  : 'Micro_mouse/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S87>'  : 'Micro_mouse/Discrete PID Controller1/External Derivative/Error'
 * '<S88>'  : 'Micro_mouse/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S89>'  : 'Micro_mouse/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S90>'  : 'Micro_mouse/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S91>'  : 'Micro_mouse/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S92>'  : 'Micro_mouse/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S93>'  : 'Micro_mouse/Discrete PID Controller1/Integrator/Discrete'
 * '<S94>'  : 'Micro_mouse/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S95>'  : 'Micro_mouse/Discrete PID Controller1/N Copy/Disabled'
 * '<S96>'  : 'Micro_mouse/Discrete PID Controller1/N Gain/Internal Parameters'
 * '<S97>'  : 'Micro_mouse/Discrete PID Controller1/P Copy/Disabled'
 * '<S98>'  : 'Micro_mouse/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S99>'  : 'Micro_mouse/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S100>' : 'Micro_mouse/Discrete PID Controller1/Saturation/Passthrough'
 * '<S101>' : 'Micro_mouse/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S102>' : 'Micro_mouse/Discrete PID Controller1/Sum/Sum_PID'
 * '<S103>' : 'Micro_mouse/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S104>' : 'Micro_mouse/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S105>' : 'Micro_mouse/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S106>' : 'Micro_mouse/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S107>' : 'Micro_mouse/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S108>' : 'Micro_mouse/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S109>' : 'Micro_mouse/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S110>' : 'Micro_mouse/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S111>' : 'Micro_mouse/IR/Analog to Digital Converter'
 * '<S112>' : 'Micro_mouse/IR/Analog to Digital Converter/ECSoC'
 * '<S113>' : 'Micro_mouse/IR/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S114>' : 'Micro_mouse/Left Motor/Channel A'
 * '<S115>' : 'Micro_mouse/Left Motor/Direction'
 * '<S116>' : 'Micro_mouse/Left Motor/Discrete Derivative'
 * '<S117>' : 'Micro_mouse/Left Motor/PWM'
 * '<S118>' : 'Micro_mouse/Left Motor/Triggered Subsystem'
 * '<S119>' : 'Micro_mouse/Left Motor/Channel A/ECSoC'
 * '<S120>' : 'Micro_mouse/Left Motor/Channel A/ECSoC/ECSimCodegen'
 * '<S121>' : 'Micro_mouse/Left Motor/Direction/ECSoC'
 * '<S122>' : 'Micro_mouse/Left Motor/Direction/ECSoC/ECSimCodegen'
 * '<S123>' : 'Micro_mouse/Left Motor/PWM/ECSoC'
 * '<S124>' : 'Micro_mouse/Left Motor/PWM/ECSoC/ECSimCodegen'
 * '<S125>' : 'Micro_mouse/Left Motor/Triggered Subsystem/MATLAB Function'
 * '<S126>' : 'Micro_mouse/Left Motor/Triggered Subsystem/PB0 (currA)'
 * '<S127>' : 'Micro_mouse/Left Motor/Triggered Subsystem/PB1 (currB)'
 * '<S128>' : 'Micro_mouse/Left Motor/Triggered Subsystem/PB0 (currA)/ECSoC'
 * '<S129>' : 'Micro_mouse/Left Motor/Triggered Subsystem/PB0 (currA)/ECSoC/ECSimCodegen'
 * '<S130>' : 'Micro_mouse/Left Motor/Triggered Subsystem/PB1 (currB)/ECSoC'
 * '<S131>' : 'Micro_mouse/Left Motor/Triggered Subsystem/PB1 (currB)/ECSoC/ECSimCodegen'
 * '<S132>' : 'Micro_mouse/Right Motor/Channel A'
 * '<S133>' : 'Micro_mouse/Right Motor/Direction'
 * '<S134>' : 'Micro_mouse/Right Motor/Discrete Derivative'
 * '<S135>' : 'Micro_mouse/Right Motor/PWM'
 * '<S136>' : 'Micro_mouse/Right Motor/Triggered Subsystem'
 * '<S137>' : 'Micro_mouse/Right Motor/Channel A/ECSoC'
 * '<S138>' : 'Micro_mouse/Right Motor/Channel A/ECSoC/ECSimCodegen'
 * '<S139>' : 'Micro_mouse/Right Motor/Direction/ECSoC'
 * '<S140>' : 'Micro_mouse/Right Motor/Direction/ECSoC/ECSimCodegen'
 * '<S141>' : 'Micro_mouse/Right Motor/PWM/ECSoC'
 * '<S142>' : 'Micro_mouse/Right Motor/PWM/ECSoC/ECSimCodegen'
 * '<S143>' : 'Micro_mouse/Right Motor/Triggered Subsystem/MATLAB Function'
 * '<S144>' : 'Micro_mouse/Right Motor/Triggered Subsystem/PB0 (currA)'
 * '<S145>' : 'Micro_mouse/Right Motor/Triggered Subsystem/PB1 (currB)'
 * '<S146>' : 'Micro_mouse/Right Motor/Triggered Subsystem/PB0 (currA)/ECSoC'
 * '<S147>' : 'Micro_mouse/Right Motor/Triggered Subsystem/PB0 (currA)/ECSoC/ECSimCodegen'
 * '<S148>' : 'Micro_mouse/Right Motor/Triggered Subsystem/PB1 (currB)/ECSoC'
 * '<S149>' : 'Micro_mouse/Right Motor/Triggered Subsystem/PB1 (currB)/ECSoC/ECSimCodegen'
 */
#endif                                 /* Micro_mouse_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
