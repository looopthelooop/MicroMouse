/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse.h
 *
 * Code generated for Simulink model 'Micro_mouse'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Apr 29 20:19:01 2025
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
  real_T Ratio;                        /* '<S7>/Ratio' */
  real_T Ratio_l;                      /* '<S8>/Ratio' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T OutportBufferForPosition;     /* '<S138>/Discrete-Time Integrator' */
  real_T OutportBufferForPosition_a;   /* '<S120>/Discrete-Time Integrator' */
  uint32_T SignalConversion4;          /* '<S6>/Signal Conversion4' */
  uint32_T SignalConversion;           /* '<S6>/Signal Conversion' */
  uint32_T Sum2;                       /* '<S1>/Sum2' */
} B_Micro_mouse_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj;/* '<S115>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_Mi_T obj_j;/* '<S144>/PWM Output' */
  stm32cube_blocks_PWMOutput_Mi_T obj_g;/* '<S126>/PWM Output' */
  real_T Integrator_DSTATE;            /* '<S43>/Integrator' */
  real_T Filter_DSTATE;                /* '<S38>/Filter' */
  real_T Integrator_DSTATE_e;          /* '<S95>/Integrator' */
  real_T Filter_DSTATE_d;              /* '<S90>/Filter' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S138>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_g;/* '<S120>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_PREV_U;/* '<S138>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_PREV_U_p;/* '<S120>/Discrete-Time Integrator' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope_PWORK_j;                     /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_n;                    /* '<S1>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK_m;                    /* '<S1>/Scope1' */

  uint32_T TriggeredSubsystem_PREV_T;  /* '<S8>/Triggered Subsystem' */
  uint32_T TriggeredSubsystem_PREV_T_c;/* '<S7>/Triggered Subsystem' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S8>/Triggered Subsystem' */
  int8_T TriggeredSubsystem_SubsysRanB_a;/* '<S7>/Triggered Subsystem' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S138>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_o;/* '<S120>/Discrete-Time Integrator' */
  boolean_T TriggeredSubsystem_RESET_ELAPS_;/* '<S8>/Triggered Subsystem' */
  boolean_T TriggeredSubsystem_RESET_ELAP_c;/* '<S7>/Triggered Subsystem' */
} DW_Micro_mouse_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Ref;                          /* '<Root>/Ref' */
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
 * Block '<S6>/Signal Conversion1' : Unused code path elimination
 * Block '<S6>/Signal Conversion2' : Unused code path elimination
 * Block '<S6>/Signal Conversion3' : Unused code path elimination
 * Block '<S118>/Data Type Duplicate' : Unused code path elimination
 * Block '<S118>/Diff' : Unused code path elimination
 * Block '<S118>/TSamp' : Unused code path elimination
 * Block '<S118>/UD' : Unused code path elimination
 * Block '<S136>/Data Type Duplicate' : Unused code path elimination
 * Block '<S136>/Diff' : Unused code path elimination
 * Block '<S136>/TSamp' : Unused code path elimination
 * Block '<S136>/UD' : Unused code path elimination
 * Block '<S40>/Integral Gain' : Eliminated nontunable gain of 1
 * Block '<S48>/Proportional Gain' : Eliminated nontunable gain of 1
 * Block '<S92>/Integral Gain' : Eliminated nontunable gain of 1
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
 * '<Root>' : 'Micro_mouse'
 * '<S1>'   : 'Micro_mouse/Centering'
 * '<S2>'   : 'Micro_mouse/Compare To Constant'
 * '<S3>'   : 'Micro_mouse/Compare To Constant1'
 * '<S4>'   : 'Micro_mouse/Discrete PID Controller'
 * '<S5>'   : 'Micro_mouse/Discrete PID Controller1'
 * '<S6>'   : 'Micro_mouse/IR'
 * '<S7>'   : 'Micro_mouse/Left Motor'
 * '<S8>'   : 'Micro_mouse/Right Motor'
 * '<S9>'   : 'Micro_mouse/Discrete PID Controller/Anti-windup'
 * '<S10>'  : 'Micro_mouse/Discrete PID Controller/D Gain'
 * '<S11>'  : 'Micro_mouse/Discrete PID Controller/External Derivative'
 * '<S12>'  : 'Micro_mouse/Discrete PID Controller/Filter'
 * '<S13>'  : 'Micro_mouse/Discrete PID Controller/Filter ICs'
 * '<S14>'  : 'Micro_mouse/Discrete PID Controller/I Gain'
 * '<S15>'  : 'Micro_mouse/Discrete PID Controller/Ideal P Gain'
 * '<S16>'  : 'Micro_mouse/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S17>'  : 'Micro_mouse/Discrete PID Controller/Integrator'
 * '<S18>'  : 'Micro_mouse/Discrete PID Controller/Integrator ICs'
 * '<S19>'  : 'Micro_mouse/Discrete PID Controller/N Copy'
 * '<S20>'  : 'Micro_mouse/Discrete PID Controller/N Gain'
 * '<S21>'  : 'Micro_mouse/Discrete PID Controller/P Copy'
 * '<S22>'  : 'Micro_mouse/Discrete PID Controller/Parallel P Gain'
 * '<S23>'  : 'Micro_mouse/Discrete PID Controller/Reset Signal'
 * '<S24>'  : 'Micro_mouse/Discrete PID Controller/Saturation'
 * '<S25>'  : 'Micro_mouse/Discrete PID Controller/Saturation Fdbk'
 * '<S26>'  : 'Micro_mouse/Discrete PID Controller/Sum'
 * '<S27>'  : 'Micro_mouse/Discrete PID Controller/Sum Fdbk'
 * '<S28>'  : 'Micro_mouse/Discrete PID Controller/Tracking Mode'
 * '<S29>'  : 'Micro_mouse/Discrete PID Controller/Tracking Mode Sum'
 * '<S30>'  : 'Micro_mouse/Discrete PID Controller/Tsamp - Integral'
 * '<S31>'  : 'Micro_mouse/Discrete PID Controller/Tsamp - Ngain'
 * '<S32>'  : 'Micro_mouse/Discrete PID Controller/postSat Signal'
 * '<S33>'  : 'Micro_mouse/Discrete PID Controller/preInt Signal'
 * '<S34>'  : 'Micro_mouse/Discrete PID Controller/preSat Signal'
 * '<S35>'  : 'Micro_mouse/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S36>'  : 'Micro_mouse/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S37>'  : 'Micro_mouse/Discrete PID Controller/External Derivative/Error'
 * '<S38>'  : 'Micro_mouse/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S39>'  : 'Micro_mouse/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S40>'  : 'Micro_mouse/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S41>'  : 'Micro_mouse/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S42>'  : 'Micro_mouse/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S43>'  : 'Micro_mouse/Discrete PID Controller/Integrator/Discrete'
 * '<S44>'  : 'Micro_mouse/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S45>'  : 'Micro_mouse/Discrete PID Controller/N Copy/Disabled'
 * '<S46>'  : 'Micro_mouse/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S47>'  : 'Micro_mouse/Discrete PID Controller/P Copy/Disabled'
 * '<S48>'  : 'Micro_mouse/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S49>'  : 'Micro_mouse/Discrete PID Controller/Reset Signal/Disabled'
 * '<S50>'  : 'Micro_mouse/Discrete PID Controller/Saturation/Passthrough'
 * '<S51>'  : 'Micro_mouse/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S52>'  : 'Micro_mouse/Discrete PID Controller/Sum/Sum_PID'
 * '<S53>'  : 'Micro_mouse/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S54>'  : 'Micro_mouse/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S55>'  : 'Micro_mouse/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S56>'  : 'Micro_mouse/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S57>'  : 'Micro_mouse/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S58>'  : 'Micro_mouse/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S59>'  : 'Micro_mouse/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S60>'  : 'Micro_mouse/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S61>'  : 'Micro_mouse/Discrete PID Controller1/Anti-windup'
 * '<S62>'  : 'Micro_mouse/Discrete PID Controller1/D Gain'
 * '<S63>'  : 'Micro_mouse/Discrete PID Controller1/External Derivative'
 * '<S64>'  : 'Micro_mouse/Discrete PID Controller1/Filter'
 * '<S65>'  : 'Micro_mouse/Discrete PID Controller1/Filter ICs'
 * '<S66>'  : 'Micro_mouse/Discrete PID Controller1/I Gain'
 * '<S67>'  : 'Micro_mouse/Discrete PID Controller1/Ideal P Gain'
 * '<S68>'  : 'Micro_mouse/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S69>'  : 'Micro_mouse/Discrete PID Controller1/Integrator'
 * '<S70>'  : 'Micro_mouse/Discrete PID Controller1/Integrator ICs'
 * '<S71>'  : 'Micro_mouse/Discrete PID Controller1/N Copy'
 * '<S72>'  : 'Micro_mouse/Discrete PID Controller1/N Gain'
 * '<S73>'  : 'Micro_mouse/Discrete PID Controller1/P Copy'
 * '<S74>'  : 'Micro_mouse/Discrete PID Controller1/Parallel P Gain'
 * '<S75>'  : 'Micro_mouse/Discrete PID Controller1/Reset Signal'
 * '<S76>'  : 'Micro_mouse/Discrete PID Controller1/Saturation'
 * '<S77>'  : 'Micro_mouse/Discrete PID Controller1/Saturation Fdbk'
 * '<S78>'  : 'Micro_mouse/Discrete PID Controller1/Sum'
 * '<S79>'  : 'Micro_mouse/Discrete PID Controller1/Sum Fdbk'
 * '<S80>'  : 'Micro_mouse/Discrete PID Controller1/Tracking Mode'
 * '<S81>'  : 'Micro_mouse/Discrete PID Controller1/Tracking Mode Sum'
 * '<S82>'  : 'Micro_mouse/Discrete PID Controller1/Tsamp - Integral'
 * '<S83>'  : 'Micro_mouse/Discrete PID Controller1/Tsamp - Ngain'
 * '<S84>'  : 'Micro_mouse/Discrete PID Controller1/postSat Signal'
 * '<S85>'  : 'Micro_mouse/Discrete PID Controller1/preInt Signal'
 * '<S86>'  : 'Micro_mouse/Discrete PID Controller1/preSat Signal'
 * '<S87>'  : 'Micro_mouse/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S88>'  : 'Micro_mouse/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S89>'  : 'Micro_mouse/Discrete PID Controller1/External Derivative/Error'
 * '<S90>'  : 'Micro_mouse/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S91>'  : 'Micro_mouse/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S92>'  : 'Micro_mouse/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S93>'  : 'Micro_mouse/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S94>'  : 'Micro_mouse/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S95>'  : 'Micro_mouse/Discrete PID Controller1/Integrator/Discrete'
 * '<S96>'  : 'Micro_mouse/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S97>'  : 'Micro_mouse/Discrete PID Controller1/N Copy/Disabled'
 * '<S98>'  : 'Micro_mouse/Discrete PID Controller1/N Gain/Internal Parameters'
 * '<S99>'  : 'Micro_mouse/Discrete PID Controller1/P Copy/Disabled'
 * '<S100>' : 'Micro_mouse/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S101>' : 'Micro_mouse/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S102>' : 'Micro_mouse/Discrete PID Controller1/Saturation/Passthrough'
 * '<S103>' : 'Micro_mouse/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S104>' : 'Micro_mouse/Discrete PID Controller1/Sum/Sum_PID'
 * '<S105>' : 'Micro_mouse/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S106>' : 'Micro_mouse/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S107>' : 'Micro_mouse/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S108>' : 'Micro_mouse/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S109>' : 'Micro_mouse/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S110>' : 'Micro_mouse/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S111>' : 'Micro_mouse/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S112>' : 'Micro_mouse/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S113>' : 'Micro_mouse/IR/Analog to Digital Converter'
 * '<S114>' : 'Micro_mouse/IR/Analog to Digital Converter/ECSoC'
 * '<S115>' : 'Micro_mouse/IR/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S116>' : 'Micro_mouse/Left Motor/Channel A'
 * '<S117>' : 'Micro_mouse/Left Motor/Direction'
 * '<S118>' : 'Micro_mouse/Left Motor/Discrete Derivative'
 * '<S119>' : 'Micro_mouse/Left Motor/PWM'
 * '<S120>' : 'Micro_mouse/Left Motor/Triggered Subsystem'
 * '<S121>' : 'Micro_mouse/Left Motor/Channel A/ECSoC'
 * '<S122>' : 'Micro_mouse/Left Motor/Channel A/ECSoC/ECSimCodegen'
 * '<S123>' : 'Micro_mouse/Left Motor/Direction/ECSoC'
 * '<S124>' : 'Micro_mouse/Left Motor/Direction/ECSoC/ECSimCodegen'
 * '<S125>' : 'Micro_mouse/Left Motor/PWM/ECSoC'
 * '<S126>' : 'Micro_mouse/Left Motor/PWM/ECSoC/ECSimCodegen'
 * '<S127>' : 'Micro_mouse/Left Motor/Triggered Subsystem/MATLAB Function'
 * '<S128>' : 'Micro_mouse/Left Motor/Triggered Subsystem/PB0 (currA)'
 * '<S129>' : 'Micro_mouse/Left Motor/Triggered Subsystem/PB1 (currB)'
 * '<S130>' : 'Micro_mouse/Left Motor/Triggered Subsystem/PB0 (currA)/ECSoC'
 * '<S131>' : 'Micro_mouse/Left Motor/Triggered Subsystem/PB0 (currA)/ECSoC/ECSimCodegen'
 * '<S132>' : 'Micro_mouse/Left Motor/Triggered Subsystem/PB1 (currB)/ECSoC'
 * '<S133>' : 'Micro_mouse/Left Motor/Triggered Subsystem/PB1 (currB)/ECSoC/ECSimCodegen'
 * '<S134>' : 'Micro_mouse/Right Motor/Channel A'
 * '<S135>' : 'Micro_mouse/Right Motor/Direction'
 * '<S136>' : 'Micro_mouse/Right Motor/Discrete Derivative'
 * '<S137>' : 'Micro_mouse/Right Motor/PWM'
 * '<S138>' : 'Micro_mouse/Right Motor/Triggered Subsystem'
 * '<S139>' : 'Micro_mouse/Right Motor/Channel A/ECSoC'
 * '<S140>' : 'Micro_mouse/Right Motor/Channel A/ECSoC/ECSimCodegen'
 * '<S141>' : 'Micro_mouse/Right Motor/Direction/ECSoC'
 * '<S142>' : 'Micro_mouse/Right Motor/Direction/ECSoC/ECSimCodegen'
 * '<S143>' : 'Micro_mouse/Right Motor/PWM/ECSoC'
 * '<S144>' : 'Micro_mouse/Right Motor/PWM/ECSoC/ECSimCodegen'
 * '<S145>' : 'Micro_mouse/Right Motor/Triggered Subsystem/MATLAB Function'
 * '<S146>' : 'Micro_mouse/Right Motor/Triggered Subsystem/PB0 (currA)'
 * '<S147>' : 'Micro_mouse/Right Motor/Triggered Subsystem/PB1 (currB)'
 * '<S148>' : 'Micro_mouse/Right Motor/Triggered Subsystem/PB0 (currA)/ECSoC'
 * '<S149>' : 'Micro_mouse/Right Motor/Triggered Subsystem/PB0 (currA)/ECSoC/ECSimCodegen'
 * '<S150>' : 'Micro_mouse/Right Motor/Triggered Subsystem/PB1 (currB)/ECSoC'
 * '<S151>' : 'Micro_mouse/Right Motor/Triggered Subsystem/PB1 (currB)/ECSoC/ECSimCodegen'
 */
#endif                                 /* Micro_mouse_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
