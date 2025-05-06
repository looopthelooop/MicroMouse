/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse.h
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  uint64_T Gain;                       /* '<S1>/Gain' */
  real_T Ratio;                        /* '<S13>/Ratio' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T Diff;                         /* '<S6>/Diff' */
  real_T Diff_p;                       /* '<S5>/Diff' */
  real_T Saturation1;                  /* '<Root>/Saturation1' */
  real_T Ratio_p;                      /* '<S12>/Ratio' */
  real_T UnitDelay;                    /* '<S141>/Unit Delay' */
  real_T UnitDelay_j;                  /* '<S124>/Unit Delay' */
  uint32_T SignalConversion4;          /* '<S11>/Signal Conversion4' */
  uint32_T SignalConversion;           /* '<S11>/Signal Conversion' */
  uint32_T Sum2;                       /* '<S1>/Sum2' */
} B_Micro_mouse_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_LowpassFilter_Mi_T obj; /* '<Root>/Lowpass Filter' */
  stm32cube_blocks_AnalogInput__T obj_c;
                                      /* '<S120>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_Mi_T obj_j;/* '<S147>/PWM Output' */
  stm32cube_blocks_PWMOutput_Mi_T obj_g;/* '<S130>/PWM Output' */
  real_T Integrator_DSTATE;            /* '<S100>/Integrator' */
  real_T Filter_DSTATE;                /* '<S95>/Filter' */
  real_T UD_DSTATE;                    /* '<S6>/UD' */
  real_T UD_DSTATE_h;                  /* '<S5>/UD' */
  real_T Integrator_DSTATE_g;          /* '<S48>/Integrator' */
  real_T Filter_DSTATE_b;              /* '<S43>/Filter' */
  real_T UD_DSTATE_e;                  /* '<S8>/UD' */
  real_T UD_DSTATE_ee;                 /* '<S7>/UD' */
  real_T UnitDelay_DSTATE;             /* '<S141>/Unit Delay' */
  real_T UnitDelay_DSTATE_e;           /* '<S124>/Unit Delay' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S1>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<S1>/Scope1' */

  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S13>/Triggered Subsystem' */
  int8_T TriggeredSubsystem_SubsysRanB_j;/* '<S12>/Triggered Subsystem' */
  boolean_T isInitialized;             /* '<Root>/Lowpass Filter' */
  boolean_T isInitialized_m;           /* '<Root>/Lowpass Filter' */
} DW_Micro_mouse_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T position;                     /* '<Root>/position' */
  real_T position1;                    /* '<Root>/position1' */
} ExtY_Micro_mouse_T;

/* Real-time Model Data Structure */
struct tag_RTM_Micro_mouse_T {
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
    uint32_T clockTick4;
    struct {
      uint16_T TID[3];
    } TaskCounters;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[5];
  } Timing;
};

/* Block signals (default storage) */
extern B_Micro_mouse_T Micro_mouse_B;

/* Block states (default storage) */
extern DW_Micro_mouse_T Micro_mouse_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Micro_mouse_T Micro_mouse_Y;

/* External function called from main */
extern void Micro_mouse_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Micro_mouse_initialize(void);
extern void Micro_mouse_step0(void);   /* Sample time: [0.0s, 0.0s] */
extern void Micro_mouse_step2(void);   /* Sample time: [1.0s, 0.0s] */
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
 * Block '<S4>/Discrete State Space' : Unused code path elimination
 * Block '<S5>/Data Type Duplicate' : Unused code path elimination
 * Block '<S6>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/Signal Conversion1' : Unused code path elimination
 * Block '<S11>/Signal Conversion2' : Unused code path elimination
 * Block '<S11>/Signal Conversion3' : Unused code path elimination
 * Block '<Root>/Sine Wave' : Unused code path elimination
 * Block '<S53>/Proportional Gain' : Eliminated nontunable gain of 1
 * Block '<S105>/Proportional Gain' : Eliminated nontunable gain of 1
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
 * '<S4>'   : 'Micro_mouse/Discrete Zero-Pole (with initial outputs)'
 * '<S5>'   : 'Micro_mouse/Discrete Derivative'
 * '<S6>'   : 'Micro_mouse/Discrete Derivative1'
 * '<S7>'   : 'Micro_mouse/Discrete Derivative2'
 * '<S8>'   : 'Micro_mouse/Discrete Derivative3'
 * '<S9>'   : 'Micro_mouse/Discrete PID Controller'
 * '<S10>'  : 'Micro_mouse/Discrete PID Controller1'
 * '<S11>'  : 'Micro_mouse/IR'
 * '<S12>'  : 'Micro_mouse/Left Motor'
 * '<S13>'  : 'Micro_mouse/Right Motor'
 * '<S14>'  : 'Micro_mouse/Discrete PID Controller/Anti-windup'
 * '<S15>'  : 'Micro_mouse/Discrete PID Controller/D Gain'
 * '<S16>'  : 'Micro_mouse/Discrete PID Controller/External Derivative'
 * '<S17>'  : 'Micro_mouse/Discrete PID Controller/Filter'
 * '<S18>'  : 'Micro_mouse/Discrete PID Controller/Filter ICs'
 * '<S19>'  : 'Micro_mouse/Discrete PID Controller/I Gain'
 * '<S20>'  : 'Micro_mouse/Discrete PID Controller/Ideal P Gain'
 * '<S21>'  : 'Micro_mouse/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S22>'  : 'Micro_mouse/Discrete PID Controller/Integrator'
 * '<S23>'  : 'Micro_mouse/Discrete PID Controller/Integrator ICs'
 * '<S24>'  : 'Micro_mouse/Discrete PID Controller/N Copy'
 * '<S25>'  : 'Micro_mouse/Discrete PID Controller/N Gain'
 * '<S26>'  : 'Micro_mouse/Discrete PID Controller/P Copy'
 * '<S27>'  : 'Micro_mouse/Discrete PID Controller/Parallel P Gain'
 * '<S28>'  : 'Micro_mouse/Discrete PID Controller/Reset Signal'
 * '<S29>'  : 'Micro_mouse/Discrete PID Controller/Saturation'
 * '<S30>'  : 'Micro_mouse/Discrete PID Controller/Saturation Fdbk'
 * '<S31>'  : 'Micro_mouse/Discrete PID Controller/Sum'
 * '<S32>'  : 'Micro_mouse/Discrete PID Controller/Sum Fdbk'
 * '<S33>'  : 'Micro_mouse/Discrete PID Controller/Tracking Mode'
 * '<S34>'  : 'Micro_mouse/Discrete PID Controller/Tracking Mode Sum'
 * '<S35>'  : 'Micro_mouse/Discrete PID Controller/Tsamp - Integral'
 * '<S36>'  : 'Micro_mouse/Discrete PID Controller/Tsamp - Ngain'
 * '<S37>'  : 'Micro_mouse/Discrete PID Controller/postSat Signal'
 * '<S38>'  : 'Micro_mouse/Discrete PID Controller/preInt Signal'
 * '<S39>'  : 'Micro_mouse/Discrete PID Controller/preSat Signal'
 * '<S40>'  : 'Micro_mouse/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S41>'  : 'Micro_mouse/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S42>'  : 'Micro_mouse/Discrete PID Controller/External Derivative/Error'
 * '<S43>'  : 'Micro_mouse/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S44>'  : 'Micro_mouse/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S45>'  : 'Micro_mouse/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S46>'  : 'Micro_mouse/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S47>'  : 'Micro_mouse/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S48>'  : 'Micro_mouse/Discrete PID Controller/Integrator/Discrete'
 * '<S49>'  : 'Micro_mouse/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S50>'  : 'Micro_mouse/Discrete PID Controller/N Copy/Disabled'
 * '<S51>'  : 'Micro_mouse/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S52>'  : 'Micro_mouse/Discrete PID Controller/P Copy/Disabled'
 * '<S53>'  : 'Micro_mouse/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S54>'  : 'Micro_mouse/Discrete PID Controller/Reset Signal/Disabled'
 * '<S55>'  : 'Micro_mouse/Discrete PID Controller/Saturation/Passthrough'
 * '<S56>'  : 'Micro_mouse/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S57>'  : 'Micro_mouse/Discrete PID Controller/Sum/Sum_PID'
 * '<S58>'  : 'Micro_mouse/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S59>'  : 'Micro_mouse/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S60>'  : 'Micro_mouse/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S61>'  : 'Micro_mouse/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S62>'  : 'Micro_mouse/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S63>'  : 'Micro_mouse/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S64>'  : 'Micro_mouse/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S65>'  : 'Micro_mouse/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S66>'  : 'Micro_mouse/Discrete PID Controller1/Anti-windup'
 * '<S67>'  : 'Micro_mouse/Discrete PID Controller1/D Gain'
 * '<S68>'  : 'Micro_mouse/Discrete PID Controller1/External Derivative'
 * '<S69>'  : 'Micro_mouse/Discrete PID Controller1/Filter'
 * '<S70>'  : 'Micro_mouse/Discrete PID Controller1/Filter ICs'
 * '<S71>'  : 'Micro_mouse/Discrete PID Controller1/I Gain'
 * '<S72>'  : 'Micro_mouse/Discrete PID Controller1/Ideal P Gain'
 * '<S73>'  : 'Micro_mouse/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S74>'  : 'Micro_mouse/Discrete PID Controller1/Integrator'
 * '<S75>'  : 'Micro_mouse/Discrete PID Controller1/Integrator ICs'
 * '<S76>'  : 'Micro_mouse/Discrete PID Controller1/N Copy'
 * '<S77>'  : 'Micro_mouse/Discrete PID Controller1/N Gain'
 * '<S78>'  : 'Micro_mouse/Discrete PID Controller1/P Copy'
 * '<S79>'  : 'Micro_mouse/Discrete PID Controller1/Parallel P Gain'
 * '<S80>'  : 'Micro_mouse/Discrete PID Controller1/Reset Signal'
 * '<S81>'  : 'Micro_mouse/Discrete PID Controller1/Saturation'
 * '<S82>'  : 'Micro_mouse/Discrete PID Controller1/Saturation Fdbk'
 * '<S83>'  : 'Micro_mouse/Discrete PID Controller1/Sum'
 * '<S84>'  : 'Micro_mouse/Discrete PID Controller1/Sum Fdbk'
 * '<S85>'  : 'Micro_mouse/Discrete PID Controller1/Tracking Mode'
 * '<S86>'  : 'Micro_mouse/Discrete PID Controller1/Tracking Mode Sum'
 * '<S87>'  : 'Micro_mouse/Discrete PID Controller1/Tsamp - Integral'
 * '<S88>'  : 'Micro_mouse/Discrete PID Controller1/Tsamp - Ngain'
 * '<S89>'  : 'Micro_mouse/Discrete PID Controller1/postSat Signal'
 * '<S90>'  : 'Micro_mouse/Discrete PID Controller1/preInt Signal'
 * '<S91>'  : 'Micro_mouse/Discrete PID Controller1/preSat Signal'
 * '<S92>'  : 'Micro_mouse/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S93>'  : 'Micro_mouse/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S94>'  : 'Micro_mouse/Discrete PID Controller1/External Derivative/Error'
 * '<S95>'  : 'Micro_mouse/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S96>'  : 'Micro_mouse/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S97>'  : 'Micro_mouse/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S98>'  : 'Micro_mouse/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S99>'  : 'Micro_mouse/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S100>' : 'Micro_mouse/Discrete PID Controller1/Integrator/Discrete'
 * '<S101>' : 'Micro_mouse/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S102>' : 'Micro_mouse/Discrete PID Controller1/N Copy/Disabled'
 * '<S103>' : 'Micro_mouse/Discrete PID Controller1/N Gain/Internal Parameters'
 * '<S104>' : 'Micro_mouse/Discrete PID Controller1/P Copy/Disabled'
 * '<S105>' : 'Micro_mouse/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S106>' : 'Micro_mouse/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S107>' : 'Micro_mouse/Discrete PID Controller1/Saturation/Passthrough'
 * '<S108>' : 'Micro_mouse/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S109>' : 'Micro_mouse/Discrete PID Controller1/Sum/Sum_PID'
 * '<S110>' : 'Micro_mouse/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S111>' : 'Micro_mouse/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S112>' : 'Micro_mouse/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S113>' : 'Micro_mouse/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S114>' : 'Micro_mouse/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S115>' : 'Micro_mouse/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S116>' : 'Micro_mouse/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S117>' : 'Micro_mouse/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S118>' : 'Micro_mouse/IR/Analog to Digital Converter'
 * '<S119>' : 'Micro_mouse/IR/Analog to Digital Converter/ECSoC'
 * '<S120>' : 'Micro_mouse/IR/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S121>' : 'Micro_mouse/Left Motor/Channel A'
 * '<S122>' : 'Micro_mouse/Left Motor/Direction'
 * '<S123>' : 'Micro_mouse/Left Motor/PWM'
 * '<S124>' : 'Micro_mouse/Left Motor/Triggered Subsystem'
 * '<S125>' : 'Micro_mouse/Left Motor/Channel A/ECSoC'
 * '<S126>' : 'Micro_mouse/Left Motor/Channel A/ECSoC/ECSimCodegen'
 * '<S127>' : 'Micro_mouse/Left Motor/Direction/ECSoC'
 * '<S128>' : 'Micro_mouse/Left Motor/Direction/ECSoC/ECSimCodegen'
 * '<S129>' : 'Micro_mouse/Left Motor/PWM/ECSoC'
 * '<S130>' : 'Micro_mouse/Left Motor/PWM/ECSoC/ECSimCodegen'
 * '<S131>' : 'Micro_mouse/Left Motor/Triggered Subsystem/MATLAB Function'
 * '<S132>' : 'Micro_mouse/Left Motor/Triggered Subsystem/PB0 (currA)'
 * '<S133>' : 'Micro_mouse/Left Motor/Triggered Subsystem/PB1 (currB)'
 * '<S134>' : 'Micro_mouse/Left Motor/Triggered Subsystem/PB0 (currA)/ECSoC'
 * '<S135>' : 'Micro_mouse/Left Motor/Triggered Subsystem/PB0 (currA)/ECSoC/ECSimCodegen'
 * '<S136>' : 'Micro_mouse/Left Motor/Triggered Subsystem/PB1 (currB)/ECSoC'
 * '<S137>' : 'Micro_mouse/Left Motor/Triggered Subsystem/PB1 (currB)/ECSoC/ECSimCodegen'
 * '<S138>' : 'Micro_mouse/Right Motor/Channel A'
 * '<S139>' : 'Micro_mouse/Right Motor/Direction'
 * '<S140>' : 'Micro_mouse/Right Motor/PWM'
 * '<S141>' : 'Micro_mouse/Right Motor/Triggered Subsystem'
 * '<S142>' : 'Micro_mouse/Right Motor/Channel A/ECSoC'
 * '<S143>' : 'Micro_mouse/Right Motor/Channel A/ECSoC/ECSimCodegen'
 * '<S144>' : 'Micro_mouse/Right Motor/Direction/ECSoC'
 * '<S145>' : 'Micro_mouse/Right Motor/Direction/ECSoC/ECSimCodegen'
 * '<S146>' : 'Micro_mouse/Right Motor/PWM/ECSoC'
 * '<S147>' : 'Micro_mouse/Right Motor/PWM/ECSoC/ECSimCodegen'
 * '<S148>' : 'Micro_mouse/Right Motor/Triggered Subsystem/MATLAB Function'
 * '<S149>' : 'Micro_mouse/Right Motor/Triggered Subsystem/PB0 (currA)'
 * '<S150>' : 'Micro_mouse/Right Motor/Triggered Subsystem/PB1 (currB)'
 * '<S151>' : 'Micro_mouse/Right Motor/Triggered Subsystem/PB0 (currA)/ECSoC'
 * '<S152>' : 'Micro_mouse/Right Motor/Triggered Subsystem/PB0 (currA)/ECSoC/ECSimCodegen'
 * '<S153>' : 'Micro_mouse/Right Motor/Triggered Subsystem/PB1 (currB)/ECSoC'
 * '<S154>' : 'Micro_mouse/Right Motor/Triggered Subsystem/PB1 (currB)/ECSoC/ECSimCodegen'
 */
#endif                                 /* Micro_mouse_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
