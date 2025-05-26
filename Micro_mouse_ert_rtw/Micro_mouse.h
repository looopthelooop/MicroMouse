/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse.h
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

#ifndef Micro_mouse_h_
#define Micro_mouse_h_
#ifndef Micro_mouse_COMMON_INCLUDES_
#define Micro_mouse_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "ext_mode.h"
#include "main.h"
#endif                                 /* Micro_mouse_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "Micro_mouse_types.h"
#include "rtGetNaN.h"
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
  real_T Ratio;                        /* '<S25>/Ratio' */
  real_T DataTypeConversion;           /* '<S1>/Data Type Conversion' */
  real_T DataTypeConversion1;          /* '<S1>/Data Type Conversion1' */
  real_T Sum2;                         /* '<S1>/Sum2' */
  real_T Sum1;                         /* '<S8>/Sum1' */
  real_T UnitDelay;                    /* '<S150>/Unit Delay' */
  real_T UnitDelay_n;                  /* '<S133>/Unit Delay' */
  real_T UnitDelay_e;                  /* '<S9>/Unit Delay' */
  uint32_T SignalConversion4;          /* '<S5>/Signal Conversion4' */
  uint32_T SignalConversion;           /* '<S5>/Signal Conversion' */
} B_Micro_mouse_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S17>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_Mi_T obj_e;/* '<S156>/PWM Output' */
  stm32cube_blocks_PWMOutput_Mi_T obj_d;/* '<S139>/PWM Output' */
  real_T UD_DSTATE;                    /* '<S20>/UD' */
  real_T Integrator_DSTATE;            /* '<S60>/Integrator' */
  real_T Filter_DSTATE;                /* '<S55>/Filter' */
  real_T UD_DSTATE_b;                  /* '<S21>/UD' */
  real_T Integrator_DSTATE_k;          /* '<S112>/Integrator' */
  real_T Filter_DSTATE_c;              /* '<S107>/Filter' */
  real_T UnitDelay_DSTATE;             /* '<S150>/Unit Delay' */
  real_T UnitDelay_DSTATE_o;           /* '<S133>/Unit Delay' */
  real_T UnitDelay_DSTATE_i;           /* '<S9>/Unit Delay' */
  real_T i;                            /* '<Root>/MATLAB Function' */
  real_T j;                            /* '<Root>/MATLAB Function' */
  real_T dir;                          /* '<Root>/MATLAB Function' */
  real_T prevL;                        /* '<Root>/MATLAB Function' */
  real_T prevR;                        /* '<Root>/MATLAB Function' */
  real_T threshold;                    /* '<Root>/MATLAB Function' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S1>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<S1>/Scope1' */

  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S25>/Triggered Subsystem' */
  int8_T TriggeredSubsystem_SubsysRanB_l;/* '<S24>/Triggered Subsystem' */
  int8_T Donothing_SubsysRanBC;        /* '<Root>/Do nothing' */
  int8_T solve_SubsysRanBC;            /* '<Root>/solve' */
  int8_T Search_SubsysRanBC;           /* '<Root>/Search' */
  int8_T TriggeredSubsystem_SubsysRanB_e;/* '<Root>/Triggered Subsystem' */
  boolean_T i_not_empty;               /* '<Root>/MATLAB Function' */
} DW_Micro_mouse_T;

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

  void EXTI9_5_IRQHandler(void);
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
 * Block '<S5>/Signal Conversion1' : Unused code path elimination
 * Block '<S5>/Signal Conversion2' : Unused code path elimination
 * Block '<S5>/Signal Conversion3' : Unused code path elimination
 * Block '<S7>/Step' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/Step' : Unused code path elimination
 * Block '<S57>/Integral Gain' : Eliminated nontunable gain of 1
 * Block '<S109>/Integral Gain' : Eliminated nontunable gain of 1
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
 * '<S2>'   : 'Micro_mouse/Channel A'
 * '<S3>'   : 'Micro_mouse/Digital Port Write'
 * '<S4>'   : 'Micro_mouse/Do nothing'
 * '<S5>'   : 'Micro_mouse/IR'
 * '<S6>'   : 'Micro_mouse/MATLAB Function'
 * '<S7>'   : 'Micro_mouse/Search'
 * '<S8>'   : 'Micro_mouse/Subsystem'
 * '<S9>'   : 'Micro_mouse/Triggered Subsystem'
 * '<S10>'  : 'Micro_mouse/solve'
 * '<S11>'  : 'Micro_mouse/Channel A/ECSoC'
 * '<S12>'  : 'Micro_mouse/Channel A/ECSoC/ECSimCodegen'
 * '<S13>'  : 'Micro_mouse/Digital Port Write/ECSoC'
 * '<S14>'  : 'Micro_mouse/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S15>'  : 'Micro_mouse/IR/Analog to Digital Converter'
 * '<S16>'  : 'Micro_mouse/IR/Analog to Digital Converter/ECSoC'
 * '<S17>'  : 'Micro_mouse/IR/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S18>'  : 'Micro_mouse/Subsystem/Compare To Constant'
 * '<S19>'  : 'Micro_mouse/Subsystem/Compare To Constant1'
 * '<S20>'  : 'Micro_mouse/Subsystem/Discrete Derivative'
 * '<S21>'  : 'Micro_mouse/Subsystem/Discrete Derivative2'
 * '<S22>'  : 'Micro_mouse/Subsystem/Discrete PID Controller'
 * '<S23>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1'
 * '<S24>'  : 'Micro_mouse/Subsystem/Left Motor'
 * '<S25>'  : 'Micro_mouse/Subsystem/Right Motor'
 * '<S26>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Anti-windup'
 * '<S27>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/D Gain'
 * '<S28>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/External Derivative'
 * '<S29>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Filter'
 * '<S30>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Filter ICs'
 * '<S31>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/I Gain'
 * '<S32>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Ideal P Gain'
 * '<S33>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S34>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Integrator'
 * '<S35>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Integrator ICs'
 * '<S36>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/N Copy'
 * '<S37>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/N Gain'
 * '<S38>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/P Copy'
 * '<S39>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Parallel P Gain'
 * '<S40>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Reset Signal'
 * '<S41>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Saturation'
 * '<S42>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Saturation Fdbk'
 * '<S43>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Sum'
 * '<S44>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Sum Fdbk'
 * '<S45>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Tracking Mode'
 * '<S46>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Tracking Mode Sum'
 * '<S47>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Tsamp - Integral'
 * '<S48>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Tsamp - Ngain'
 * '<S49>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/postSat Signal'
 * '<S50>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/preInt Signal'
 * '<S51>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/preSat Signal'
 * '<S52>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S53>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S54>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/External Derivative/Error'
 * '<S55>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S56>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S57>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S58>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S59>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S60>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Integrator/Discrete'
 * '<S61>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S62>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/N Copy/Disabled'
 * '<S63>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S64>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/P Copy/Disabled'
 * '<S65>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S66>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Reset Signal/Disabled'
 * '<S67>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Saturation/Passthrough'
 * '<S68>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S69>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Sum/Sum_PID'
 * '<S70>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S71>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S72>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S73>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S74>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S75>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S76>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S77>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S78>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Anti-windup'
 * '<S79>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/D Gain'
 * '<S80>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/External Derivative'
 * '<S81>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Filter'
 * '<S82>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Filter ICs'
 * '<S83>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/I Gain'
 * '<S84>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Ideal P Gain'
 * '<S85>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S86>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Integrator'
 * '<S87>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Integrator ICs'
 * '<S88>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/N Copy'
 * '<S89>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/N Gain'
 * '<S90>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/P Copy'
 * '<S91>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Parallel P Gain'
 * '<S92>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Reset Signal'
 * '<S93>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Saturation'
 * '<S94>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Saturation Fdbk'
 * '<S95>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Sum'
 * '<S96>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Sum Fdbk'
 * '<S97>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Tracking Mode'
 * '<S98>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Tracking Mode Sum'
 * '<S99>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Tsamp - Integral'
 * '<S100>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Tsamp - Ngain'
 * '<S101>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/postSat Signal'
 * '<S102>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/preInt Signal'
 * '<S103>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/preSat Signal'
 * '<S104>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S105>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S106>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/External Derivative/Error'
 * '<S107>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S108>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S109>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S110>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S111>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S112>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Integrator/Discrete'
 * '<S113>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S114>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/N Copy/Disabled'
 * '<S115>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/N Gain/Internal Parameters'
 * '<S116>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/P Copy/Disabled'
 * '<S117>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S118>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S119>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Saturation/Passthrough'
 * '<S120>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S121>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Sum/Sum_PID'
 * '<S122>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S123>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S124>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S125>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S126>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S127>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S128>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S129>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S130>' : 'Micro_mouse/Subsystem/Left Motor/Channel A'
 * '<S131>' : 'Micro_mouse/Subsystem/Left Motor/Direction'
 * '<S132>' : 'Micro_mouse/Subsystem/Left Motor/PWM'
 * '<S133>' : 'Micro_mouse/Subsystem/Left Motor/Triggered Subsystem'
 * '<S134>' : 'Micro_mouse/Subsystem/Left Motor/Channel A/ECSoC'
 * '<S135>' : 'Micro_mouse/Subsystem/Left Motor/Channel A/ECSoC/ECSimCodegen'
 * '<S136>' : 'Micro_mouse/Subsystem/Left Motor/Direction/ECSoC'
 * '<S137>' : 'Micro_mouse/Subsystem/Left Motor/Direction/ECSoC/ECSimCodegen'
 * '<S138>' : 'Micro_mouse/Subsystem/Left Motor/PWM/ECSoC'
 * '<S139>' : 'Micro_mouse/Subsystem/Left Motor/PWM/ECSoC/ECSimCodegen'
 * '<S140>' : 'Micro_mouse/Subsystem/Left Motor/Triggered Subsystem/MATLAB Function'
 * '<S141>' : 'Micro_mouse/Subsystem/Left Motor/Triggered Subsystem/PB0 (currA)'
 * '<S142>' : 'Micro_mouse/Subsystem/Left Motor/Triggered Subsystem/PB1 (currB)'
 * '<S143>' : 'Micro_mouse/Subsystem/Left Motor/Triggered Subsystem/PB0 (currA)/ECSoC'
 * '<S144>' : 'Micro_mouse/Subsystem/Left Motor/Triggered Subsystem/PB0 (currA)/ECSoC/ECSimCodegen'
 * '<S145>' : 'Micro_mouse/Subsystem/Left Motor/Triggered Subsystem/PB1 (currB)/ECSoC'
 * '<S146>' : 'Micro_mouse/Subsystem/Left Motor/Triggered Subsystem/PB1 (currB)/ECSoC/ECSimCodegen'
 * '<S147>' : 'Micro_mouse/Subsystem/Right Motor/Channel A'
 * '<S148>' : 'Micro_mouse/Subsystem/Right Motor/Direction'
 * '<S149>' : 'Micro_mouse/Subsystem/Right Motor/PWM'
 * '<S150>' : 'Micro_mouse/Subsystem/Right Motor/Triggered Subsystem'
 * '<S151>' : 'Micro_mouse/Subsystem/Right Motor/Channel A/ECSoC'
 * '<S152>' : 'Micro_mouse/Subsystem/Right Motor/Channel A/ECSoC/ECSimCodegen'
 * '<S153>' : 'Micro_mouse/Subsystem/Right Motor/Direction/ECSoC'
 * '<S154>' : 'Micro_mouse/Subsystem/Right Motor/Direction/ECSoC/ECSimCodegen'
 * '<S155>' : 'Micro_mouse/Subsystem/Right Motor/PWM/ECSoC'
 * '<S156>' : 'Micro_mouse/Subsystem/Right Motor/PWM/ECSoC/ECSimCodegen'
 * '<S157>' : 'Micro_mouse/Subsystem/Right Motor/Triggered Subsystem/MATLAB Function'
 * '<S158>' : 'Micro_mouse/Subsystem/Right Motor/Triggered Subsystem/PB0 (currA)'
 * '<S159>' : 'Micro_mouse/Subsystem/Right Motor/Triggered Subsystem/PB1 (currB)'
 * '<S160>' : 'Micro_mouse/Subsystem/Right Motor/Triggered Subsystem/PB0 (currA)/ECSoC'
 * '<S161>' : 'Micro_mouse/Subsystem/Right Motor/Triggered Subsystem/PB0 (currA)/ECSoC/ECSimCodegen'
 * '<S162>' : 'Micro_mouse/Subsystem/Right Motor/Triggered Subsystem/PB1 (currB)/ECSoC'
 * '<S163>' : 'Micro_mouse/Subsystem/Right Motor/Triggered Subsystem/PB1 (currB)/ECSoC/ECSimCodegen'
 */
#endif                                 /* Micro_mouse_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
