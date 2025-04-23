/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse.h
 *
 * Code generated for Simulink model 'Micro_mouse'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Apr 23 18:17:43 2025
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
#include "math.h"
#include "main.h"
#endif                                 /* Micro_mouse_COMMON_INCLUDES_ */

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
  uint16_T AnalogtoDigitalConverter[5];/* '<S5>/Analog to Digital Converter' */
} B_Micro_mouse_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S5>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_Mi_T obj_e;/* '<S17>/PWM Output' */
  stm32cube_blocks_PWMOutput_Mi_T obj_j;/* '<S11>/PWM Output' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_Micro_mouse_T;

/* Invariant block signals (default storage) */
typedef struct {
  const boolean_T NOT;                 /* '<S2>/NOT' */
} ConstB_Micro_mouse_T;

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
    time_T tFinal;
    boolean_T stopRequestedFlag;
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
 * '<S3>'   : 'Micro_mouse/Right Motor'
 * '<S4>'   : 'Micro_mouse/Analog to Digital Converter/ECSoC'
 * '<S5>'   : 'Micro_mouse/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S6>'   : 'Micro_mouse/Left Motor/Digital Port Write'
 * '<S7>'   : 'Micro_mouse/Left Motor/PWM Output'
 * '<S8>'   : 'Micro_mouse/Left Motor/Digital Port Write/ECSoC'
 * '<S9>'   : 'Micro_mouse/Left Motor/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S10>'  : 'Micro_mouse/Left Motor/PWM Output/ECSoC'
 * '<S11>'  : 'Micro_mouse/Left Motor/PWM Output/ECSoC/ECSimCodegen'
 * '<S12>'  : 'Micro_mouse/Right Motor/Digital Port Write'
 * '<S13>'  : 'Micro_mouse/Right Motor/PWM Output'
 * '<S14>'  : 'Micro_mouse/Right Motor/Digital Port Write/ECSoC'
 * '<S15>'  : 'Micro_mouse/Right Motor/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S16>'  : 'Micro_mouse/Right Motor/PWM Output/ECSoC'
 * '<S17>'  : 'Micro_mouse/Right Motor/PWM Output/ECSoC/ECSimCodegen'
 */
#endif                                 /* Micro_mouse_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
