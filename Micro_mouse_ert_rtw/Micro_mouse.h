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
 * C/C++ source code generated on : Tue Apr 29 14:07:24 2025
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
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#include "main.h"
#endif                                 /* Micro_mouse_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "Micro_mouse_types.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S6>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_Mi_T obj_j;/* '<S26>/PWM Output' */
  stm32cube_blocks_PWMOutput_Mi_T obj_jt;/* '<S15>/PWM Output' */
} DW_Micro_mouse_T;

/* Invariant block signals (default storage) */
typedef struct {
  const boolean_T NOT;                 /* '<S2>/NOT' */
} ConstB_Micro_mouse_T;

/* Real-time Model Data Structure */
struct tag_RTM_Micro_mouse_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

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
 * Block '<Root>/Gain1' : Unused code path elimination
 * Block '<S3>/Clock' : Unused code path elimination
 * Block '<S3>/Constant' : Unused code path elimination
 * Block '<S3>/Constant1' : Unused code path elimination
 * Block '<S3>/Output' : Unused code path elimination
 * Block '<S3>/Product' : Unused code path elimination
 * Block '<S3>/Step' : Unused code path elimination
 * Block '<S3>/Sum' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Diff' : Unused code path elimination
 * Block '<S18>/TSamp' : Unused code path elimination
 * Block '<S18>/UD' : Unused code path elimination
 * Block '<S4>/Ratio' : Unused code path elimination
 * Block '<S20>/Discrete-Time Integrator' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope3' : Unused code path elimination
 * Block '<Root>/Signal Conversion' : Unused code path elimination
 * Block '<Root>/Signal Conversion1' : Unused code path elimination
 * Block '<Root>/Signal Conversion2' : Unused code path elimination
 * Block '<Root>/Signal Conversion3' : Unused code path elimination
 * Block '<Root>/Signal Conversion4' : Unused code path elimination
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
 * '<S16>'  : 'Micro_mouse/Right Motor/Channel A'
 * '<S17>'  : 'Micro_mouse/Right Motor/Direction'
 * '<S18>'  : 'Micro_mouse/Right Motor/Discrete Derivative'
 * '<S19>'  : 'Micro_mouse/Right Motor/PWM'
 * '<S20>'  : 'Micro_mouse/Right Motor/Triggered Subsystem'
 * '<S21>'  : 'Micro_mouse/Right Motor/Channel A/ECSoC'
 * '<S22>'  : 'Micro_mouse/Right Motor/Channel A/ECSoC/ECSimCodegen'
 * '<S23>'  : 'Micro_mouse/Right Motor/Direction/ECSoC'
 * '<S24>'  : 'Micro_mouse/Right Motor/Direction/ECSoC/ECSimCodegen'
 * '<S25>'  : 'Micro_mouse/Right Motor/PWM/ECSoC'
 * '<S26>'  : 'Micro_mouse/Right Motor/PWM/ECSoC/ECSimCodegen'
 * '<S27>'  : 'Micro_mouse/Right Motor/Triggered Subsystem/MATLAB Function'
 * '<S28>'  : 'Micro_mouse/Right Motor/Triggered Subsystem/PB0 (currA)'
 * '<S29>'  : 'Micro_mouse/Right Motor/Triggered Subsystem/PB1 (currB)'
 * '<S30>'  : 'Micro_mouse/Right Motor/Triggered Subsystem/PB0 (currA)/ECSoC'
 * '<S31>'  : 'Micro_mouse/Right Motor/Triggered Subsystem/PB0 (currA)/ECSoC/ECSimCodegen'
 * '<S32>'  : 'Micro_mouse/Right Motor/Triggered Subsystem/PB1 (currB)/ECSoC'
 * '<S33>'  : 'Micro_mouse/Right Motor/Triggered Subsystem/PB1 (currB)/ECSoC/ECSimCodegen'
 */
#endif                                 /* Micro_mouse_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
