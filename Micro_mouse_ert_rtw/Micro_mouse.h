/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse.h
 *
 * Code generated for Simulink model 'Micro_mouse'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Mon Apr 28 11:13:01 2025
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

#include "Micro_mouse_types.h"
#include <string.h>
#include "rtGetInf.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
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

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T speed;                        /* '<Root>/Derivative' */
  real_T Integrator;                   /* '<S19>/Integrator' */
  real_T DataTypeConversion;           /* '<S19>/Data Type Conversion' */
  real_T Switch;                       /* '<S19>/Switch' */
  uint32_T Gain1[5];                   /* '<Root>/Gain1' */
  boolean_T DigitalPortRead;           /* '<S22>/Digital Port Read' */
  boolean_T DigitalPortRead_a[2];      /* '<S11>/Digital Port Read' */
} B_Micro_mouse_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S6>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_Mi_T obj_e;/* '<S30>/PWM Output' */
  stm32cube_blocks_PWMOutput_Mi_T obj_j;/* '<S15>/PWM Output' */
  real_T DiscreteFIRFilter_states;     /* '<S19>/Discrete FIR Filter' */
  real_T TimeStampA;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative' */
  real_T TimeStampB;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative' */
  real_T DiscreteFIRFilter_simContextBuf[2];/* '<S19>/Discrete FIR Filter' */
  real_T DiscreteFIRFilter_simRevCoeff[2];/* '<S19>/Discrete FIR Filter' */
  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope_PWORK_f;                     /* '<S19>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S19>/Scope1' */

  boolean_T DelayInput1_DSTATE;        /* '<S16>/Delay Input1' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S4>/Enabled Subsystem' */
  boolean_T EnabledSubsystem_MODE;     /* '<S4>/Enabled Subsystem' */
} DW_Micro_mouse_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S19>/Integrator' */
} X_Micro_mouse_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S19>/Integrator' */
} XDot_Micro_mouse_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S19>/Integrator' */
} XDis_Micro_mouse_T;

/* Invariant block signals (default storage) */
typedef struct {
  const boolean_T NOT;                 /* '<S2>/NOT' */
} ConstB_Micro_mouse_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Real-time Model Data Structure */
struct tag_RTM_Micro_mouse_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_Micro_mouse_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_Micro_mouse_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[1];
  real_T odeF[3][1];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
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
    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_Micro_mouse_T Micro_mouse_B;

/* Continuous states (default storage) */
extern X_Micro_mouse_T Micro_mouse_X;

/* Disabled states (default storage) */
extern XDis_Micro_mouse_T Micro_mouse_XDis;

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
 * '<S4>'   : 'Micro_mouse/Right Motor'
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
 * '<S16>'  : 'Micro_mouse/Right Motor/Detect Change1'
 * '<S17>'  : 'Micro_mouse/Right Motor/Digital Port Read'
 * '<S18>'  : 'Micro_mouse/Right Motor/Digital Port Write'
 * '<S19>'  : 'Micro_mouse/Right Motor/Enabled Subsystem'
 * '<S20>'  : 'Micro_mouse/Right Motor/PWM Output'
 * '<S21>'  : 'Micro_mouse/Right Motor/Digital Port Read/ECSoC'
 * '<S22>'  : 'Micro_mouse/Right Motor/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S23>'  : 'Micro_mouse/Right Motor/Digital Port Write/ECSoC'
 * '<S24>'  : 'Micro_mouse/Right Motor/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S25>'  : 'Micro_mouse/Right Motor/Enabled Subsystem/Compare To Constant'
 * '<S26>'  : 'Micro_mouse/Right Motor/Enabled Subsystem/Digital Port Read1'
 * '<S27>'  : 'Micro_mouse/Right Motor/Enabled Subsystem/Digital Port Read1/ECSoC'
 * '<S28>'  : 'Micro_mouse/Right Motor/Enabled Subsystem/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S29>'  : 'Micro_mouse/Right Motor/PWM Output/ECSoC'
 * '<S30>'  : 'Micro_mouse/Right Motor/PWM Output/ECSoC/ECSimCodegen'
 */
#endif                                 /* Micro_mouse_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
