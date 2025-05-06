/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse.h
 *
 * Code generated for Simulink model 'Micro_mouse'.
 *
 * Model version                  : 1.42
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue May  6 10:23:15 2025
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
#include "ext_mode.h"
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
  real_T Ratio;                        /* '<S10>/Ratio' */
  real_T Diff;                         /* '<S4>/Diff' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T Saturation1;                  /* '<Root>/Saturation1' */
  real_T Ratio_p;                      /* '<S9>/Ratio' */
  real_T UnitDelay;                    /* '<S34>/Unit Delay' */
  real_T UnitDelay_j;                  /* '<S17>/Unit Delay' */
  uint32_T SignalConversion4;          /* '<S8>/Signal Conversion4' */
  uint32_T SignalConversion;           /* '<S8>/Signal Conversion' */
  uint32_T Sum2;                       /* '<S1>/Sum2' */
} B_Micro_mouse_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S13>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_Mi_T obj_j;/* '<S40>/PWM Output' */
  stm32cube_blocks_PWMOutput_Mi_T obj_g;/* '<S23>/PWM Output' */
  real_T UD_DSTATE;                    /* '<S4>/UD' */
  real_T UD_DSTATE_p;                  /* '<S5>/UD' */
  real_T UD_DSTATE_e;                  /* '<S7>/UD' */
  real_T UD_DSTATE_ee;                 /* '<S6>/UD' */
  real_T UnitDelay_DSTATE;             /* '<S34>/Unit Delay' */
  real_T UnitDelay_DSTATE_e;           /* '<S17>/Unit Delay' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S1>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<S1>/Scope1' */

  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S10>/Triggered Subsystem' */
  int8_T TriggeredSubsystem_SubsysRanB_j;/* '<S9>/Triggered Subsystem' */
} DW_Micro_mouse_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T position;                     /* '<Root>/position' */
  real_T position1;                    /* '<Root>/position1' */
  real_T Out1;                         /* '<Root>/Out1' */
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
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[4];
  } Timing;
};

/* Block signals (default storage) */
extern B_Micro_mouse_T Micro_mouse_B;

/* Block states (default storage) */
extern DW_Micro_mouse_T Micro_mouse_DW;

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
 * Block '<S4>/Data Type Duplicate' : Unused code path elimination
 * Block '<S5>/Data Type Duplicate' : Unused code path elimination
 * Block '<S6>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/Signal Conversion1' : Unused code path elimination
 * Block '<S8>/Signal Conversion2' : Unused code path elimination
 * Block '<S8>/Signal Conversion3' : Unused code path elimination
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
 * '<S4>'   : 'Micro_mouse/Discrete Derivative'
 * '<S5>'   : 'Micro_mouse/Discrete Derivative1'
 * '<S6>'   : 'Micro_mouse/Discrete Derivative2'
 * '<S7>'   : 'Micro_mouse/Discrete Derivative3'
 * '<S8>'   : 'Micro_mouse/IR'
 * '<S9>'   : 'Micro_mouse/Left Motor'
 * '<S10>'  : 'Micro_mouse/Right Motor'
 * '<S11>'  : 'Micro_mouse/IR/Analog to Digital Converter'
 * '<S12>'  : 'Micro_mouse/IR/Analog to Digital Converter/ECSoC'
 * '<S13>'  : 'Micro_mouse/IR/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S14>'  : 'Micro_mouse/Left Motor/Channel A'
 * '<S15>'  : 'Micro_mouse/Left Motor/Direction'
 * '<S16>'  : 'Micro_mouse/Left Motor/PWM'
 * '<S17>'  : 'Micro_mouse/Left Motor/Triggered Subsystem'
 * '<S18>'  : 'Micro_mouse/Left Motor/Channel A/ECSoC'
 * '<S19>'  : 'Micro_mouse/Left Motor/Channel A/ECSoC/ECSimCodegen'
 * '<S20>'  : 'Micro_mouse/Left Motor/Direction/ECSoC'
 * '<S21>'  : 'Micro_mouse/Left Motor/Direction/ECSoC/ECSimCodegen'
 * '<S22>'  : 'Micro_mouse/Left Motor/PWM/ECSoC'
 * '<S23>'  : 'Micro_mouse/Left Motor/PWM/ECSoC/ECSimCodegen'
 * '<S24>'  : 'Micro_mouse/Left Motor/Triggered Subsystem/MATLAB Function'
 * '<S25>'  : 'Micro_mouse/Left Motor/Triggered Subsystem/PB0 (currA)'
 * '<S26>'  : 'Micro_mouse/Left Motor/Triggered Subsystem/PB1 (currB)'
 * '<S27>'  : 'Micro_mouse/Left Motor/Triggered Subsystem/PB0 (currA)/ECSoC'
 * '<S28>'  : 'Micro_mouse/Left Motor/Triggered Subsystem/PB0 (currA)/ECSoC/ECSimCodegen'
 * '<S29>'  : 'Micro_mouse/Left Motor/Triggered Subsystem/PB1 (currB)/ECSoC'
 * '<S30>'  : 'Micro_mouse/Left Motor/Triggered Subsystem/PB1 (currB)/ECSoC/ECSimCodegen'
 * '<S31>'  : 'Micro_mouse/Right Motor/Channel A'
 * '<S32>'  : 'Micro_mouse/Right Motor/Direction'
 * '<S33>'  : 'Micro_mouse/Right Motor/PWM'
 * '<S34>'  : 'Micro_mouse/Right Motor/Triggered Subsystem'
 * '<S35>'  : 'Micro_mouse/Right Motor/Channel A/ECSoC'
 * '<S36>'  : 'Micro_mouse/Right Motor/Channel A/ECSoC/ECSimCodegen'
 * '<S37>'  : 'Micro_mouse/Right Motor/Direction/ECSoC'
 * '<S38>'  : 'Micro_mouse/Right Motor/Direction/ECSoC/ECSimCodegen'
 * '<S39>'  : 'Micro_mouse/Right Motor/PWM/ECSoC'
 * '<S40>'  : 'Micro_mouse/Right Motor/PWM/ECSoC/ECSimCodegen'
 * '<S41>'  : 'Micro_mouse/Right Motor/Triggered Subsystem/MATLAB Function'
 * '<S42>'  : 'Micro_mouse/Right Motor/Triggered Subsystem/PB0 (currA)'
 * '<S43>'  : 'Micro_mouse/Right Motor/Triggered Subsystem/PB1 (currB)'
 * '<S44>'  : 'Micro_mouse/Right Motor/Triggered Subsystem/PB0 (currA)/ECSoC'
 * '<S45>'  : 'Micro_mouse/Right Motor/Triggered Subsystem/PB0 (currA)/ECSoC/ECSimCodegen'
 * '<S46>'  : 'Micro_mouse/Right Motor/Triggered Subsystem/PB1 (currB)/ECSoC'
 * '<S47>'  : 'Micro_mouse/Right Motor/Triggered Subsystem/PB1 (currB)/ECSoC/ECSimCodegen'
 */
#endif                                 /* Micro_mouse_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
