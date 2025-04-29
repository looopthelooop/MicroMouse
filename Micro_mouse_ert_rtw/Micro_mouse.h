/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse.h
 *
 * Code generated for Simulink model 'Micro_mouse'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Apr 29 10:29:49 2025
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
  real_T Ratio;                        /* '<S4>/Ratio' */
  real_T Diff;                         /* '<S18>/Diff' */
  real_T TmpRTBAtScope1Inport1;        /* '<S4>/Triggered Subsystem' */
  real_T DiscreteTimeIntegrator;       /* '<S20>/Discrete-Time Integrator' */
  real_T OutportBufferForPosition;     /* '<S20>/OutportBufferForPosition' */
  real_T delta;                        /* '<S20>/MATLAB Function' */
  uint32_T Gain1[5];                   /* '<Root>/Gain1' */
  boolean_T prevA;                     /* '<S20>/prevA' */
  boolean_T DigitalPortRead;           /* '<S31>/Digital Port Read' */
  boolean_T DigitalPortRead_a[2];      /* '<S11>/Digital Port Read' */
} B_Micro_mouse_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S6>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_Mi_T obj_j;/* '<S26>/PWM Output' */
  stm32cube_blocks_PWMOutput_Mi_T obj_jt;/* '<S15>/PWM Output' */
  real_T UD_DSTATE;                    /* '<S18>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S20>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_PREV_U;/* '<S20>/Discrete-Time Integrator' */
  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_g;                    /* '<S4>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_a;                     /* '<S20>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope2_PWORK_e;                    /* '<S20>/Scope2' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_ge;                   /* '<S20>/Scope1' */

  uint32_T TriggeredSubsystem_PREV_T;  /* '<S4>/Triggered Subsystem' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S4>/Triggered Subsystem' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S20>/Discrete-Time Integrator' */
  boolean_T TriggeredSubsystem_RESET_ELAPS_;/* '<S4>/Triggered Subsystem' */
  boolean_T prevA_PreviousInput;       /* '<S20>/prevA' */
  boolean_T PrevB_PreviousInput;       /* '<S20>/PrevB' */
} DW_Micro_mouse_T;

/* Invariant block signals (default storage) */
typedef struct {
  const boolean_T NOT;                 /* '<S2>/NOT' */
} ConstB_Micro_mouse_T;

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
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block signals (default storage) */
extern B_Micro_mouse_T Micro_mouse_B;

/* Block states (default storage) */
extern DW_Micro_mouse_T Micro_mouse_DW;
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

  void EXTI0_IRQHandler(void);
  void Micro_mouse_configure_interrupts (void);
  void Micro_mouse_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Clock' : Unused code path elimination
 * Block '<S3>/Constant' : Unused code path elimination
 * Block '<S3>/Constant1' : Unused code path elimination
 * Block '<S3>/Output' : Unused code path elimination
 * Block '<S3>/Product' : Unused code path elimination
 * Block '<S3>/Step' : Unused code path elimination
 * Block '<S3>/Sum' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<Root>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<Root>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<Root>/Signal Conversion2' : Eliminate redundant signal conversion block
 * Block '<Root>/Signal Conversion3' : Eliminate redundant signal conversion block
 * Block '<Root>/Signal Conversion4' : Eliminate redundant signal conversion block
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
 * '<S1>'   : 'Micro_mouse/Analog to Digital Converter'
 * '<S2>'   : 'Micro_mouse/Left Motor'
 * '<S3>'   : 'Micro_mouse/Ramp'
 * '<S4>'   : 'Micro_mouse/Right Motor1'
 * '<S5>'   : 'Micro_mouse/Analog to Digital Converter/ECSoC'
 * '<S6>'   : 'Micro_mouse/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S7>'   : 'Micro_mouse/Left Motor/Digital Port Read'
 * '<S8>'   : 'Micro_mouse/Left Motor/Digital Port Write'
 * '<S9>'   : 'Micro_mouse/Left Motor/PWM Output'
 * '<S10>'  : 'Micro_mouse/Left Motor/Digital Port Read/ECSoC'
 * '<S11>'  : 'Micro_mouse/Left Motor/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S12>'  : 'Micro_mouse/Left Motor/Digital Port Write/ECSoC'
 * '<S13>'  : 'Micro_mouse/Left Motor/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S14>'  : 'Micro_mouse/Left Motor/PWM Output/ECSoC'
 * '<S15>'  : 'Micro_mouse/Left Motor/PWM Output/ECSoC/ECSimCodegen'
 * '<S16>'  : 'Micro_mouse/Right Motor1/Channel A'
 * '<S17>'  : 'Micro_mouse/Right Motor1/Direction'
 * '<S18>'  : 'Micro_mouse/Right Motor1/Discrete Derivative'
 * '<S19>'  : 'Micro_mouse/Right Motor1/PWM'
 * '<S20>'  : 'Micro_mouse/Right Motor1/Triggered Subsystem'
 * '<S21>'  : 'Micro_mouse/Right Motor1/Channel A/ECSoC'
 * '<S22>'  : 'Micro_mouse/Right Motor1/Channel A/ECSoC/ECSimCodegen'
 * '<S23>'  : 'Micro_mouse/Right Motor1/Direction/ECSoC'
 * '<S24>'  : 'Micro_mouse/Right Motor1/Direction/ECSoC/ECSimCodegen'
 * '<S25>'  : 'Micro_mouse/Right Motor1/PWM/ECSoC'
 * '<S26>'  : 'Micro_mouse/Right Motor1/PWM/ECSoC/ECSimCodegen'
 * '<S27>'  : 'Micro_mouse/Right Motor1/Triggered Subsystem/MATLAB Function'
 * '<S28>'  : 'Micro_mouse/Right Motor1/Triggered Subsystem/PB0 (currA)'
 * '<S29>'  : 'Micro_mouse/Right Motor1/Triggered Subsystem/PB1 (currB)'
 * '<S30>'  : 'Micro_mouse/Right Motor1/Triggered Subsystem/PB0 (currA)/ECSoC'
 * '<S31>'  : 'Micro_mouse/Right Motor1/Triggered Subsystem/PB0 (currA)/ECSoC/ECSimCodegen'
 * '<S32>'  : 'Micro_mouse/Right Motor1/Triggered Subsystem/PB1 (currB)/ECSoC'
 * '<S33>'  : 'Micro_mouse/Right Motor1/Triggered Subsystem/PB1 (currB)/ECSoC/ECSimCodegen'
 */
#endif                                 /* Micro_mouse_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
