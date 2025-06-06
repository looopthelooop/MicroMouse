/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse.h
 *
 * Code generated for Simulink model 'Micro_mouse'.
 *
 * Model version                  : 1.76
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Fri Jun  6 13:51:01 2025
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
  real_T Abs;                          /* '<S3>/Abs' */
  real_T UnitDelay;                    /* '<S139>/Unit Delay' */
  real_T UnitDelay_n;                  /* '<S122>/Unit Delay' */
  boolean_T Compare;                   /* '<S8>/Compare' */
} B_Micro_mouse_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj;/* '<S155>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_Mi_T obj_e;/* '<S145>/PWM Output' */
  stm32cube_blocks_PWMOutput_Mi_T obj_d;/* '<S128>/PWM Output' */
  real_T UD_DSTATE;                    /* '<S9>/UD' */
  real_T Integrator_DSTATE;            /* '<S49>/Integrator' */
  real_T Filter_DSTATE;                /* '<S44>/Filter' */
  real_T UD_DSTATE_b;                  /* '<S10>/UD' */
  real_T Integrator_DSTATE_k;          /* '<S101>/Integrator' */
  real_T Filter_DSTATE_c;              /* '<S96>/Filter' */
  real_T UnitDelay_DSTATE;             /* '<S139>/Unit Delay' */
  real_T UnitDelay_DSTATE_o;           /* '<S122>/Unit Delay' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S14>/Triggered Subsystem' */
  int8_T TriggeredSubsystem_SubsysRanB_l;/* '<S13>/Triggered Subsystem' */
} DW_Micro_mouse_T;

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
 * Block '<S1>/Data Type Conversion' : Unused code path elimination
 * Block '<S1>/Data Type Conversion1' : Unused code path elimination
 * Block '<S1>/Sum2' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/Gain2' : Unused code path elimination
 * Block '<S4>/Signal Conversion' : Unused code path elimination
 * Block '<S4>/Signal Conversion1' : Unused code path elimination
 * Block '<S4>/Signal Conversion2' : Unused code path elimination
 * Block '<S4>/Signal Conversion3' : Unused code path elimination
 * Block '<S4>/Signal Conversion4' : Unused code path elimination
 * Block '<S46>/Integral Gain' : Eliminated nontunable gain of 1
 * Block '<S98>/Integral Gain' : Eliminated nontunable gain of 1
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
 * '<S2>'   : 'Micro_mouse/Digital Port Write'
 * '<S3>'   : 'Micro_mouse/Forward'
 * '<S4>'   : 'Micro_mouse/IR'
 * '<S5>'   : 'Micro_mouse/Digital Port Write/ECSoC'
 * '<S6>'   : 'Micro_mouse/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S7>'   : 'Micro_mouse/Forward/Compare To Constant'
 * '<S8>'   : 'Micro_mouse/Forward/Compare To Constant1'
 * '<S9>'   : 'Micro_mouse/Forward/Discrete Derivative'
 * '<S10>'  : 'Micro_mouse/Forward/Discrete Derivative2'
 * '<S11>'  : 'Micro_mouse/Forward/Discrete PID Controller'
 * '<S12>'  : 'Micro_mouse/Forward/Discrete PID Controller1'
 * '<S13>'  : 'Micro_mouse/Forward/Left Motor'
 * '<S14>'  : 'Micro_mouse/Forward/Right Motor'
 * '<S15>'  : 'Micro_mouse/Forward/Discrete PID Controller/Anti-windup'
 * '<S16>'  : 'Micro_mouse/Forward/Discrete PID Controller/D Gain'
 * '<S17>'  : 'Micro_mouse/Forward/Discrete PID Controller/External Derivative'
 * '<S18>'  : 'Micro_mouse/Forward/Discrete PID Controller/Filter'
 * '<S19>'  : 'Micro_mouse/Forward/Discrete PID Controller/Filter ICs'
 * '<S20>'  : 'Micro_mouse/Forward/Discrete PID Controller/I Gain'
 * '<S21>'  : 'Micro_mouse/Forward/Discrete PID Controller/Ideal P Gain'
 * '<S22>'  : 'Micro_mouse/Forward/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S23>'  : 'Micro_mouse/Forward/Discrete PID Controller/Integrator'
 * '<S24>'  : 'Micro_mouse/Forward/Discrete PID Controller/Integrator ICs'
 * '<S25>'  : 'Micro_mouse/Forward/Discrete PID Controller/N Copy'
 * '<S26>'  : 'Micro_mouse/Forward/Discrete PID Controller/N Gain'
 * '<S27>'  : 'Micro_mouse/Forward/Discrete PID Controller/P Copy'
 * '<S28>'  : 'Micro_mouse/Forward/Discrete PID Controller/Parallel P Gain'
 * '<S29>'  : 'Micro_mouse/Forward/Discrete PID Controller/Reset Signal'
 * '<S30>'  : 'Micro_mouse/Forward/Discrete PID Controller/Saturation'
 * '<S31>'  : 'Micro_mouse/Forward/Discrete PID Controller/Saturation Fdbk'
 * '<S32>'  : 'Micro_mouse/Forward/Discrete PID Controller/Sum'
 * '<S33>'  : 'Micro_mouse/Forward/Discrete PID Controller/Sum Fdbk'
 * '<S34>'  : 'Micro_mouse/Forward/Discrete PID Controller/Tracking Mode'
 * '<S35>'  : 'Micro_mouse/Forward/Discrete PID Controller/Tracking Mode Sum'
 * '<S36>'  : 'Micro_mouse/Forward/Discrete PID Controller/Tsamp - Integral'
 * '<S37>'  : 'Micro_mouse/Forward/Discrete PID Controller/Tsamp - Ngain'
 * '<S38>'  : 'Micro_mouse/Forward/Discrete PID Controller/postSat Signal'
 * '<S39>'  : 'Micro_mouse/Forward/Discrete PID Controller/preInt Signal'
 * '<S40>'  : 'Micro_mouse/Forward/Discrete PID Controller/preSat Signal'
 * '<S41>'  : 'Micro_mouse/Forward/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S42>'  : 'Micro_mouse/Forward/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S43>'  : 'Micro_mouse/Forward/Discrete PID Controller/External Derivative/Error'
 * '<S44>'  : 'Micro_mouse/Forward/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S45>'  : 'Micro_mouse/Forward/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S46>'  : 'Micro_mouse/Forward/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S47>'  : 'Micro_mouse/Forward/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S48>'  : 'Micro_mouse/Forward/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S49>'  : 'Micro_mouse/Forward/Discrete PID Controller/Integrator/Discrete'
 * '<S50>'  : 'Micro_mouse/Forward/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S51>'  : 'Micro_mouse/Forward/Discrete PID Controller/N Copy/Disabled'
 * '<S52>'  : 'Micro_mouse/Forward/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S53>'  : 'Micro_mouse/Forward/Discrete PID Controller/P Copy/Disabled'
 * '<S54>'  : 'Micro_mouse/Forward/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S55>'  : 'Micro_mouse/Forward/Discrete PID Controller/Reset Signal/Disabled'
 * '<S56>'  : 'Micro_mouse/Forward/Discrete PID Controller/Saturation/Passthrough'
 * '<S57>'  : 'Micro_mouse/Forward/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S58>'  : 'Micro_mouse/Forward/Discrete PID Controller/Sum/Sum_PID'
 * '<S59>'  : 'Micro_mouse/Forward/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S60>'  : 'Micro_mouse/Forward/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S61>'  : 'Micro_mouse/Forward/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S62>'  : 'Micro_mouse/Forward/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S63>'  : 'Micro_mouse/Forward/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S64>'  : 'Micro_mouse/Forward/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S65>'  : 'Micro_mouse/Forward/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S66>'  : 'Micro_mouse/Forward/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S67>'  : 'Micro_mouse/Forward/Discrete PID Controller1/Anti-windup'
 * '<S68>'  : 'Micro_mouse/Forward/Discrete PID Controller1/D Gain'
 * '<S69>'  : 'Micro_mouse/Forward/Discrete PID Controller1/External Derivative'
 * '<S70>'  : 'Micro_mouse/Forward/Discrete PID Controller1/Filter'
 * '<S71>'  : 'Micro_mouse/Forward/Discrete PID Controller1/Filter ICs'
 * '<S72>'  : 'Micro_mouse/Forward/Discrete PID Controller1/I Gain'
 * '<S73>'  : 'Micro_mouse/Forward/Discrete PID Controller1/Ideal P Gain'
 * '<S74>'  : 'Micro_mouse/Forward/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S75>'  : 'Micro_mouse/Forward/Discrete PID Controller1/Integrator'
 * '<S76>'  : 'Micro_mouse/Forward/Discrete PID Controller1/Integrator ICs'
 * '<S77>'  : 'Micro_mouse/Forward/Discrete PID Controller1/N Copy'
 * '<S78>'  : 'Micro_mouse/Forward/Discrete PID Controller1/N Gain'
 * '<S79>'  : 'Micro_mouse/Forward/Discrete PID Controller1/P Copy'
 * '<S80>'  : 'Micro_mouse/Forward/Discrete PID Controller1/Parallel P Gain'
 * '<S81>'  : 'Micro_mouse/Forward/Discrete PID Controller1/Reset Signal'
 * '<S82>'  : 'Micro_mouse/Forward/Discrete PID Controller1/Saturation'
 * '<S83>'  : 'Micro_mouse/Forward/Discrete PID Controller1/Saturation Fdbk'
 * '<S84>'  : 'Micro_mouse/Forward/Discrete PID Controller1/Sum'
 * '<S85>'  : 'Micro_mouse/Forward/Discrete PID Controller1/Sum Fdbk'
 * '<S86>'  : 'Micro_mouse/Forward/Discrete PID Controller1/Tracking Mode'
 * '<S87>'  : 'Micro_mouse/Forward/Discrete PID Controller1/Tracking Mode Sum'
 * '<S88>'  : 'Micro_mouse/Forward/Discrete PID Controller1/Tsamp - Integral'
 * '<S89>'  : 'Micro_mouse/Forward/Discrete PID Controller1/Tsamp - Ngain'
 * '<S90>'  : 'Micro_mouse/Forward/Discrete PID Controller1/postSat Signal'
 * '<S91>'  : 'Micro_mouse/Forward/Discrete PID Controller1/preInt Signal'
 * '<S92>'  : 'Micro_mouse/Forward/Discrete PID Controller1/preSat Signal'
 * '<S93>'  : 'Micro_mouse/Forward/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S94>'  : 'Micro_mouse/Forward/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S95>'  : 'Micro_mouse/Forward/Discrete PID Controller1/External Derivative/Error'
 * '<S96>'  : 'Micro_mouse/Forward/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S97>'  : 'Micro_mouse/Forward/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S98>'  : 'Micro_mouse/Forward/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S99>'  : 'Micro_mouse/Forward/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S100>' : 'Micro_mouse/Forward/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S101>' : 'Micro_mouse/Forward/Discrete PID Controller1/Integrator/Discrete'
 * '<S102>' : 'Micro_mouse/Forward/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S103>' : 'Micro_mouse/Forward/Discrete PID Controller1/N Copy/Disabled'
 * '<S104>' : 'Micro_mouse/Forward/Discrete PID Controller1/N Gain/Internal Parameters'
 * '<S105>' : 'Micro_mouse/Forward/Discrete PID Controller1/P Copy/Disabled'
 * '<S106>' : 'Micro_mouse/Forward/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S107>' : 'Micro_mouse/Forward/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S108>' : 'Micro_mouse/Forward/Discrete PID Controller1/Saturation/Passthrough'
 * '<S109>' : 'Micro_mouse/Forward/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S110>' : 'Micro_mouse/Forward/Discrete PID Controller1/Sum/Sum_PID'
 * '<S111>' : 'Micro_mouse/Forward/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S112>' : 'Micro_mouse/Forward/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S113>' : 'Micro_mouse/Forward/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S114>' : 'Micro_mouse/Forward/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S115>' : 'Micro_mouse/Forward/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S116>' : 'Micro_mouse/Forward/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S117>' : 'Micro_mouse/Forward/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S118>' : 'Micro_mouse/Forward/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S119>' : 'Micro_mouse/Forward/Left Motor/Channel A'
 * '<S120>' : 'Micro_mouse/Forward/Left Motor/Direction'
 * '<S121>' : 'Micro_mouse/Forward/Left Motor/PWM'
 * '<S122>' : 'Micro_mouse/Forward/Left Motor/Triggered Subsystem'
 * '<S123>' : 'Micro_mouse/Forward/Left Motor/Channel A/ECSoC'
 * '<S124>' : 'Micro_mouse/Forward/Left Motor/Channel A/ECSoC/ECSimCodegen'
 * '<S125>' : 'Micro_mouse/Forward/Left Motor/Direction/ECSoC'
 * '<S126>' : 'Micro_mouse/Forward/Left Motor/Direction/ECSoC/ECSimCodegen'
 * '<S127>' : 'Micro_mouse/Forward/Left Motor/PWM/ECSoC'
 * '<S128>' : 'Micro_mouse/Forward/Left Motor/PWM/ECSoC/ECSimCodegen'
 * '<S129>' : 'Micro_mouse/Forward/Left Motor/Triggered Subsystem/MATLAB Function'
 * '<S130>' : 'Micro_mouse/Forward/Left Motor/Triggered Subsystem/PB0 (currA)'
 * '<S131>' : 'Micro_mouse/Forward/Left Motor/Triggered Subsystem/PB1 (currB)'
 * '<S132>' : 'Micro_mouse/Forward/Left Motor/Triggered Subsystem/PB0 (currA)/ECSoC'
 * '<S133>' : 'Micro_mouse/Forward/Left Motor/Triggered Subsystem/PB0 (currA)/ECSoC/ECSimCodegen'
 * '<S134>' : 'Micro_mouse/Forward/Left Motor/Triggered Subsystem/PB1 (currB)/ECSoC'
 * '<S135>' : 'Micro_mouse/Forward/Left Motor/Triggered Subsystem/PB1 (currB)/ECSoC/ECSimCodegen'
 * '<S136>' : 'Micro_mouse/Forward/Right Motor/Channel A'
 * '<S137>' : 'Micro_mouse/Forward/Right Motor/Direction'
 * '<S138>' : 'Micro_mouse/Forward/Right Motor/PWM'
 * '<S139>' : 'Micro_mouse/Forward/Right Motor/Triggered Subsystem'
 * '<S140>' : 'Micro_mouse/Forward/Right Motor/Channel A/ECSoC'
 * '<S141>' : 'Micro_mouse/Forward/Right Motor/Channel A/ECSoC/ECSimCodegen'
 * '<S142>' : 'Micro_mouse/Forward/Right Motor/Direction/ECSoC'
 * '<S143>' : 'Micro_mouse/Forward/Right Motor/Direction/ECSoC/ECSimCodegen'
 * '<S144>' : 'Micro_mouse/Forward/Right Motor/PWM/ECSoC'
 * '<S145>' : 'Micro_mouse/Forward/Right Motor/PWM/ECSoC/ECSimCodegen'
 * '<S146>' : 'Micro_mouse/Forward/Right Motor/Triggered Subsystem/MATLAB Function'
 * '<S147>' : 'Micro_mouse/Forward/Right Motor/Triggered Subsystem/PB0 (currA)'
 * '<S148>' : 'Micro_mouse/Forward/Right Motor/Triggered Subsystem/PB1 (currB)'
 * '<S149>' : 'Micro_mouse/Forward/Right Motor/Triggered Subsystem/PB0 (currA)/ECSoC'
 * '<S150>' : 'Micro_mouse/Forward/Right Motor/Triggered Subsystem/PB0 (currA)/ECSoC/ECSimCodegen'
 * '<S151>' : 'Micro_mouse/Forward/Right Motor/Triggered Subsystem/PB1 (currB)/ECSoC'
 * '<S152>' : 'Micro_mouse/Forward/Right Motor/Triggered Subsystem/PB1 (currB)/ECSoC/ECSimCodegen'
 * '<S153>' : 'Micro_mouse/IR/Analog to Digital Converter'
 * '<S154>' : 'Micro_mouse/IR/Analog to Digital Converter/ECSoC'
 * '<S155>' : 'Micro_mouse/IR/Analog to Digital Converter/ECSoC/ECSimCodegen'
 */
#endif                                 /* Micro_mouse_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
