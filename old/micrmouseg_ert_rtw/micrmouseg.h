/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: micrmouseg.h
 *
 * Code generated for Simulink model 'micrmouseg'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Mon Jun  9 15:16:17 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef micrmouseg_h_
#define micrmouseg_h_
#ifndef micrmouseg_COMMON_INCLUDES_
#define micrmouseg_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#include "ext_mode.h"
#include "main.h"
#endif                                 /* micrmouseg_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "micrmouseg_types.h"
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
  real_T Ratio;                        /* '<S9>/Ratio' */
  real_T Ratio_c;                      /* '<S7>/Ratio' */
  real_T UnitDelay;                    /* '<S134>/Unit Delay' */
  real_T UnitDelay_i;                  /* '<S117>/Unit Delay' */
} B_micrmouseg_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_PWMOutput_mi_T obj; /* '<S140>/PWM Output' */
  stm32cube_blocks_PWMOutput_mi_T obj_f;/* '<S123>/PWM Output' */
  real_T UD_DSTATE;                    /* '<S3>/UD' */
  real_T Integrator_DSTATE;            /* '<S44>/Integrator' */
  real_T Filter_DSTATE;                /* '<S39>/Filter' */
  real_T UD_DSTATE_b;                  /* '<S4>/UD' */
  real_T Integrator_DSTATE_f;          /* '<S96>/Integrator' */
  real_T Filter_DSTATE_e;              /* '<S91>/Filter' */
  real_T UnitDelay_DSTATE;             /* '<S134>/Unit Delay' */
  real_T UnitDelay_DSTATE_l;           /* '<S117>/Unit Delay' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S9>/Triggered Subsystem' */
  int8_T TriggeredSubsystem_SubsysRanB_l;/* '<S7>/Triggered Subsystem' */
} DW_micrmouseg_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T PosL;                         /* '<Root>/PosL' */
  real_T PosR;                         /* '<Root>/PosR' */
} ExtY_micrmouseg_T;

/* Real-time Model Data Structure */
struct tag_RTM_micrmouseg_T {
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
extern B_micrmouseg_T micrmouseg_B;

/* Block states (default storage) */
extern DW_micrmouseg_T micrmouseg_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_micrmouseg_T micrmouseg_Y;

/* Model entry point functions */
extern void micrmouseg_initialize(void);
extern void micrmouseg_step(void);
extern void micrmouseg_terminate(void);

/* Real-time Model object */
extern RT_MODEL_micrmouseg_T *const micrmouseg_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  void EXTI3_IRQHandler(void);
  void EXTI0_IRQHandler(void);
  void micrmouseg_configure_interrupts (void);
  void micrmouseg_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/Data Type Duplicate' : Unused code path elimination
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
 * '<Root>' : 'micrmouseg'
 * '<S1>'   : 'micrmouseg/Compare To Constant'
 * '<S2>'   : 'micrmouseg/Compare To Constant1'
 * '<S3>'   : 'micrmouseg/Discrete Derivative'
 * '<S4>'   : 'micrmouseg/Discrete Derivative2'
 * '<S5>'   : 'micrmouseg/Discrete PID Controller'
 * '<S6>'   : 'micrmouseg/Discrete PID Controller1'
 * '<S7>'   : 'micrmouseg/Left Motor'
 * '<S8>'   : 'micrmouseg/Ramp'
 * '<S9>'   : 'micrmouseg/Right Motor'
 * '<S10>'  : 'micrmouseg/Discrete PID Controller/Anti-windup'
 * '<S11>'  : 'micrmouseg/Discrete PID Controller/D Gain'
 * '<S12>'  : 'micrmouseg/Discrete PID Controller/External Derivative'
 * '<S13>'  : 'micrmouseg/Discrete PID Controller/Filter'
 * '<S14>'  : 'micrmouseg/Discrete PID Controller/Filter ICs'
 * '<S15>'  : 'micrmouseg/Discrete PID Controller/I Gain'
 * '<S16>'  : 'micrmouseg/Discrete PID Controller/Ideal P Gain'
 * '<S17>'  : 'micrmouseg/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S18>'  : 'micrmouseg/Discrete PID Controller/Integrator'
 * '<S19>'  : 'micrmouseg/Discrete PID Controller/Integrator ICs'
 * '<S20>'  : 'micrmouseg/Discrete PID Controller/N Copy'
 * '<S21>'  : 'micrmouseg/Discrete PID Controller/N Gain'
 * '<S22>'  : 'micrmouseg/Discrete PID Controller/P Copy'
 * '<S23>'  : 'micrmouseg/Discrete PID Controller/Parallel P Gain'
 * '<S24>'  : 'micrmouseg/Discrete PID Controller/Reset Signal'
 * '<S25>'  : 'micrmouseg/Discrete PID Controller/Saturation'
 * '<S26>'  : 'micrmouseg/Discrete PID Controller/Saturation Fdbk'
 * '<S27>'  : 'micrmouseg/Discrete PID Controller/Sum'
 * '<S28>'  : 'micrmouseg/Discrete PID Controller/Sum Fdbk'
 * '<S29>'  : 'micrmouseg/Discrete PID Controller/Tracking Mode'
 * '<S30>'  : 'micrmouseg/Discrete PID Controller/Tracking Mode Sum'
 * '<S31>'  : 'micrmouseg/Discrete PID Controller/Tsamp - Integral'
 * '<S32>'  : 'micrmouseg/Discrete PID Controller/Tsamp - Ngain'
 * '<S33>'  : 'micrmouseg/Discrete PID Controller/postSat Signal'
 * '<S34>'  : 'micrmouseg/Discrete PID Controller/preInt Signal'
 * '<S35>'  : 'micrmouseg/Discrete PID Controller/preSat Signal'
 * '<S36>'  : 'micrmouseg/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S37>'  : 'micrmouseg/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S38>'  : 'micrmouseg/Discrete PID Controller/External Derivative/Error'
 * '<S39>'  : 'micrmouseg/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S40>'  : 'micrmouseg/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S41>'  : 'micrmouseg/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S42>'  : 'micrmouseg/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S43>'  : 'micrmouseg/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S44>'  : 'micrmouseg/Discrete PID Controller/Integrator/Discrete'
 * '<S45>'  : 'micrmouseg/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S46>'  : 'micrmouseg/Discrete PID Controller/N Copy/Disabled'
 * '<S47>'  : 'micrmouseg/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S48>'  : 'micrmouseg/Discrete PID Controller/P Copy/Disabled'
 * '<S49>'  : 'micrmouseg/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S50>'  : 'micrmouseg/Discrete PID Controller/Reset Signal/Disabled'
 * '<S51>'  : 'micrmouseg/Discrete PID Controller/Saturation/Passthrough'
 * '<S52>'  : 'micrmouseg/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S53>'  : 'micrmouseg/Discrete PID Controller/Sum/Sum_PID'
 * '<S54>'  : 'micrmouseg/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S55>'  : 'micrmouseg/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S56>'  : 'micrmouseg/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S57>'  : 'micrmouseg/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S58>'  : 'micrmouseg/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S59>'  : 'micrmouseg/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S60>'  : 'micrmouseg/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S61>'  : 'micrmouseg/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S62>'  : 'micrmouseg/Discrete PID Controller1/Anti-windup'
 * '<S63>'  : 'micrmouseg/Discrete PID Controller1/D Gain'
 * '<S64>'  : 'micrmouseg/Discrete PID Controller1/External Derivative'
 * '<S65>'  : 'micrmouseg/Discrete PID Controller1/Filter'
 * '<S66>'  : 'micrmouseg/Discrete PID Controller1/Filter ICs'
 * '<S67>'  : 'micrmouseg/Discrete PID Controller1/I Gain'
 * '<S68>'  : 'micrmouseg/Discrete PID Controller1/Ideal P Gain'
 * '<S69>'  : 'micrmouseg/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S70>'  : 'micrmouseg/Discrete PID Controller1/Integrator'
 * '<S71>'  : 'micrmouseg/Discrete PID Controller1/Integrator ICs'
 * '<S72>'  : 'micrmouseg/Discrete PID Controller1/N Copy'
 * '<S73>'  : 'micrmouseg/Discrete PID Controller1/N Gain'
 * '<S74>'  : 'micrmouseg/Discrete PID Controller1/P Copy'
 * '<S75>'  : 'micrmouseg/Discrete PID Controller1/Parallel P Gain'
 * '<S76>'  : 'micrmouseg/Discrete PID Controller1/Reset Signal'
 * '<S77>'  : 'micrmouseg/Discrete PID Controller1/Saturation'
 * '<S78>'  : 'micrmouseg/Discrete PID Controller1/Saturation Fdbk'
 * '<S79>'  : 'micrmouseg/Discrete PID Controller1/Sum'
 * '<S80>'  : 'micrmouseg/Discrete PID Controller1/Sum Fdbk'
 * '<S81>'  : 'micrmouseg/Discrete PID Controller1/Tracking Mode'
 * '<S82>'  : 'micrmouseg/Discrete PID Controller1/Tracking Mode Sum'
 * '<S83>'  : 'micrmouseg/Discrete PID Controller1/Tsamp - Integral'
 * '<S84>'  : 'micrmouseg/Discrete PID Controller1/Tsamp - Ngain'
 * '<S85>'  : 'micrmouseg/Discrete PID Controller1/postSat Signal'
 * '<S86>'  : 'micrmouseg/Discrete PID Controller1/preInt Signal'
 * '<S87>'  : 'micrmouseg/Discrete PID Controller1/preSat Signal'
 * '<S88>'  : 'micrmouseg/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S89>'  : 'micrmouseg/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S90>'  : 'micrmouseg/Discrete PID Controller1/External Derivative/Error'
 * '<S91>'  : 'micrmouseg/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S92>'  : 'micrmouseg/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S93>'  : 'micrmouseg/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S94>'  : 'micrmouseg/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S95>'  : 'micrmouseg/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S96>'  : 'micrmouseg/Discrete PID Controller1/Integrator/Discrete'
 * '<S97>'  : 'micrmouseg/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S98>'  : 'micrmouseg/Discrete PID Controller1/N Copy/Disabled'
 * '<S99>'  : 'micrmouseg/Discrete PID Controller1/N Gain/Internal Parameters'
 * '<S100>' : 'micrmouseg/Discrete PID Controller1/P Copy/Disabled'
 * '<S101>' : 'micrmouseg/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S102>' : 'micrmouseg/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S103>' : 'micrmouseg/Discrete PID Controller1/Saturation/Passthrough'
 * '<S104>' : 'micrmouseg/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S105>' : 'micrmouseg/Discrete PID Controller1/Sum/Sum_PID'
 * '<S106>' : 'micrmouseg/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S107>' : 'micrmouseg/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S108>' : 'micrmouseg/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S109>' : 'micrmouseg/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S110>' : 'micrmouseg/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S111>' : 'micrmouseg/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S112>' : 'micrmouseg/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S113>' : 'micrmouseg/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S114>' : 'micrmouseg/Left Motor/Channel A1'
 * '<S115>' : 'micrmouseg/Left Motor/Direction'
 * '<S116>' : 'micrmouseg/Left Motor/PWM'
 * '<S117>' : 'micrmouseg/Left Motor/Triggered Subsystem'
 * '<S118>' : 'micrmouseg/Left Motor/Channel A1/ECSoC'
 * '<S119>' : 'micrmouseg/Left Motor/Channel A1/ECSoC/ECSimCodegen'
 * '<S120>' : 'micrmouseg/Left Motor/Direction/ECSoC'
 * '<S121>' : 'micrmouseg/Left Motor/Direction/ECSoC/ECSimCodegen'
 * '<S122>' : 'micrmouseg/Left Motor/PWM/ECSoC'
 * '<S123>' : 'micrmouseg/Left Motor/PWM/ECSoC/ECSimCodegen'
 * '<S124>' : 'micrmouseg/Left Motor/Triggered Subsystem/MATLAB Function'
 * '<S125>' : 'micrmouseg/Left Motor/Triggered Subsystem/PB0 (currA)'
 * '<S126>' : 'micrmouseg/Left Motor/Triggered Subsystem/PB1 (currB)'
 * '<S127>' : 'micrmouseg/Left Motor/Triggered Subsystem/PB0 (currA)/ECSoC'
 * '<S128>' : 'micrmouseg/Left Motor/Triggered Subsystem/PB0 (currA)/ECSoC/ECSimCodegen'
 * '<S129>' : 'micrmouseg/Left Motor/Triggered Subsystem/PB1 (currB)/ECSoC'
 * '<S130>' : 'micrmouseg/Left Motor/Triggered Subsystem/PB1 (currB)/ECSoC/ECSimCodegen'
 * '<S131>' : 'micrmouseg/Right Motor/Channel A'
 * '<S132>' : 'micrmouseg/Right Motor/Direction'
 * '<S133>' : 'micrmouseg/Right Motor/PWM Output'
 * '<S134>' : 'micrmouseg/Right Motor/Triggered Subsystem'
 * '<S135>' : 'micrmouseg/Right Motor/Channel A/ECSoC'
 * '<S136>' : 'micrmouseg/Right Motor/Channel A/ECSoC/ECSimCodegen'
 * '<S137>' : 'micrmouseg/Right Motor/Direction/ECSoC'
 * '<S138>' : 'micrmouseg/Right Motor/Direction/ECSoC/ECSimCodegen'
 * '<S139>' : 'micrmouseg/Right Motor/PWM Output/ECSoC'
 * '<S140>' : 'micrmouseg/Right Motor/PWM Output/ECSoC/ECSimCodegen'
 * '<S141>' : 'micrmouseg/Right Motor/Triggered Subsystem/MATLAB Function'
 * '<S142>' : 'micrmouseg/Right Motor/Triggered Subsystem/PB0 (currA)'
 * '<S143>' : 'micrmouseg/Right Motor/Triggered Subsystem/PB1 (currB)'
 * '<S144>' : 'micrmouseg/Right Motor/Triggered Subsystem/PB0 (currA)/ECSoC'
 * '<S145>' : 'micrmouseg/Right Motor/Triggered Subsystem/PB0 (currA)/ECSoC/ECSimCodegen'
 * '<S146>' : 'micrmouseg/Right Motor/Triggered Subsystem/PB1 (currB)/ECSoC'
 * '<S147>' : 'micrmouseg/Right Motor/Triggered Subsystem/PB1 (currB)/ECSoC/ECSimCodegen'
 */
#endif                                 /* micrmouseg_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
