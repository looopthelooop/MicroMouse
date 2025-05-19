/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Micro_mouse.h
 *
 * Code generated for Simulink model 'Micro_mouse'.
 *
 * Model version                  : 1.62
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Mon May 19 11:43:17 2025
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
#include "mw_stm32_i2c_ll.h"
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T UnitDelay;                    /* '<S149>/Unit Delay' */
  real_T UnitDelay_n;                  /* '<S132>/Unit Delay' */
  real_T UnitDelay_e;                  /* '<S8>/Unit Delay' */
} B_Micro_mouse_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S16>/Analog to Digital Converter' */
  stm32cube_blocks_I2CControlle_T obj_d;/* '<S4>/I2C Controller Read' */
  stm32cube_blocks_I2CControl_c_T obj_o;/* '<Root>/I2C Controller Write' */
  stm32cube_blocks_I2CControl_c_T obj_a;/* '<S4>/I2C Controller Write' */
  stm32cube_blocks_PWMOutput_Mi_T obj_e;/* '<S155>/PWM Output' */
  stm32cube_blocks_PWMOutput_Mi_T obj_du;/* '<S138>/PWM Output' */
  real_T UD_DSTATE;                    /* '<S20>/UD' */
  real_T Integrator_DSTATE;            /* '<S111>/Integrator' */
  real_T Filter_DSTATE;                /* '<S106>/Filter' */
  real_T UD_DSTATE_o;                  /* '<S19>/UD' */
  real_T Integrator_DSTATE_f;          /* '<S59>/Integrator' */
  real_T Filter_DSTATE_f;              /* '<S54>/Filter' */
  real_T UnitDelay_DSTATE;             /* '<S149>/Unit Delay' */
  real_T UnitDelay_DSTATE_o;           /* '<S132>/Unit Delay' */
  real_T UnitDelay_DSTATE_i;           /* '<S8>/Unit Delay' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_Micro_mouse_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T position;                     /* '<Root>/position' */
  real_T position1;                    /* '<Root>/position1' */
} ExtY_Micro_mouse_T;

/* Real-time Model Data Structure */
struct tag_RTM_Micro_mouse_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
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
extern void Micro_mouse_step0(void);   /* Sample time: [0.02s, 0.0s] */
extern void Micro_mouse_step1(void);   /* Sample time: [0.1s, 0.0s] */
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
  void EXTI3_IRQHandler(void);
  void EXTI9_5_IRQHandler(void);
  void Micro_mouse_configure_interrupts (void);
  void Micro_mouse_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Gain' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S1>/Scope2' : Unused code path elimination
 * Block '<S1>/Sum2' : Unused code path elimination
 * Block '<S5>/Gain2' : Unused code path elimination
 * Block '<S5>/Signal Conversion' : Unused code path elimination
 * Block '<S5>/Signal Conversion1' : Unused code path elimination
 * Block '<S5>/Signal Conversion2' : Unused code path elimination
 * Block '<S5>/Signal Conversion3' : Unused code path elimination
 * Block '<S5>/Signal Conversion4' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
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
 * '<S4>'   : 'Micro_mouse/Function-Call Subsystem'
 * '<S5>'   : 'Micro_mouse/IR'
 * '<S6>'   : 'Micro_mouse/MATLAB Function'
 * '<S7>'   : 'Micro_mouse/Subsystem'
 * '<S8>'   : 'Micro_mouse/Triggered Subsystem'
 * '<S9>'   : 'Micro_mouse/Channel A/ECSoC'
 * '<S10>'  : 'Micro_mouse/Channel A/ECSoC/ECSimCodegen'
 * '<S11>'  : 'Micro_mouse/Digital Port Write/ECSoC'
 * '<S12>'  : 'Micro_mouse/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S13>'  : 'Micro_mouse/Function-Call Subsystem/MATLAB Function'
 * '<S14>'  : 'Micro_mouse/IR/Analog to Digital Converter'
 * '<S15>'  : 'Micro_mouse/IR/Analog to Digital Converter/ECSoC'
 * '<S16>'  : 'Micro_mouse/IR/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S17>'  : 'Micro_mouse/Subsystem/Compare To Constant'
 * '<S18>'  : 'Micro_mouse/Subsystem/Compare To Constant1'
 * '<S19>'  : 'Micro_mouse/Subsystem/Discrete Derivative'
 * '<S20>'  : 'Micro_mouse/Subsystem/Discrete Derivative2'
 * '<S21>'  : 'Micro_mouse/Subsystem/Discrete PID Controller'
 * '<S22>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1'
 * '<S23>'  : 'Micro_mouse/Subsystem/Left Motor'
 * '<S24>'  : 'Micro_mouse/Subsystem/Right Motor'
 * '<S25>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Anti-windup'
 * '<S26>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/D Gain'
 * '<S27>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/External Derivative'
 * '<S28>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Filter'
 * '<S29>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Filter ICs'
 * '<S30>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/I Gain'
 * '<S31>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Ideal P Gain'
 * '<S32>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S33>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Integrator'
 * '<S34>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Integrator ICs'
 * '<S35>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/N Copy'
 * '<S36>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/N Gain'
 * '<S37>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/P Copy'
 * '<S38>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Parallel P Gain'
 * '<S39>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Reset Signal'
 * '<S40>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Saturation'
 * '<S41>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Saturation Fdbk'
 * '<S42>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Sum'
 * '<S43>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Sum Fdbk'
 * '<S44>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Tracking Mode'
 * '<S45>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Tracking Mode Sum'
 * '<S46>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Tsamp - Integral'
 * '<S47>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Tsamp - Ngain'
 * '<S48>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/postSat Signal'
 * '<S49>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/preInt Signal'
 * '<S50>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/preSat Signal'
 * '<S51>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S52>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S53>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/External Derivative/Error'
 * '<S54>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S55>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S56>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S57>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S58>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S59>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Integrator/Discrete'
 * '<S60>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S61>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/N Copy/Disabled'
 * '<S62>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S63>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/P Copy/Disabled'
 * '<S64>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S65>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Reset Signal/Disabled'
 * '<S66>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Saturation/Passthrough'
 * '<S67>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S68>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Sum/Sum_PID'
 * '<S69>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S70>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S71>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S72>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S73>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S74>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S75>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S76>'  : 'Micro_mouse/Subsystem/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S77>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Anti-windup'
 * '<S78>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/D Gain'
 * '<S79>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/External Derivative'
 * '<S80>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Filter'
 * '<S81>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Filter ICs'
 * '<S82>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/I Gain'
 * '<S83>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Ideal P Gain'
 * '<S84>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S85>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Integrator'
 * '<S86>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Integrator ICs'
 * '<S87>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/N Copy'
 * '<S88>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/N Gain'
 * '<S89>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/P Copy'
 * '<S90>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Parallel P Gain'
 * '<S91>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Reset Signal'
 * '<S92>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Saturation'
 * '<S93>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Saturation Fdbk'
 * '<S94>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Sum'
 * '<S95>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Sum Fdbk'
 * '<S96>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Tracking Mode'
 * '<S97>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Tracking Mode Sum'
 * '<S98>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Tsamp - Integral'
 * '<S99>'  : 'Micro_mouse/Subsystem/Discrete PID Controller1/Tsamp - Ngain'
 * '<S100>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/postSat Signal'
 * '<S101>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/preInt Signal'
 * '<S102>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/preSat Signal'
 * '<S103>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S104>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S105>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/External Derivative/Error'
 * '<S106>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S107>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S108>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S109>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S110>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S111>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Integrator/Discrete'
 * '<S112>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S113>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/N Copy/Disabled'
 * '<S114>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/N Gain/Internal Parameters'
 * '<S115>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/P Copy/Disabled'
 * '<S116>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S117>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S118>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Saturation/Passthrough'
 * '<S119>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S120>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Sum/Sum_PID'
 * '<S121>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S122>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S123>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S124>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S125>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S126>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S127>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S128>' : 'Micro_mouse/Subsystem/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S129>' : 'Micro_mouse/Subsystem/Left Motor/Channel A'
 * '<S130>' : 'Micro_mouse/Subsystem/Left Motor/Direction'
 * '<S131>' : 'Micro_mouse/Subsystem/Left Motor/PWM'
 * '<S132>' : 'Micro_mouse/Subsystem/Left Motor/Triggered Subsystem'
 * '<S133>' : 'Micro_mouse/Subsystem/Left Motor/Channel A/ECSoC'
 * '<S134>' : 'Micro_mouse/Subsystem/Left Motor/Channel A/ECSoC/ECSimCodegen'
 * '<S135>' : 'Micro_mouse/Subsystem/Left Motor/Direction/ECSoC'
 * '<S136>' : 'Micro_mouse/Subsystem/Left Motor/Direction/ECSoC/ECSimCodegen'
 * '<S137>' : 'Micro_mouse/Subsystem/Left Motor/PWM/ECSoC'
 * '<S138>' : 'Micro_mouse/Subsystem/Left Motor/PWM/ECSoC/ECSimCodegen'
 * '<S139>' : 'Micro_mouse/Subsystem/Left Motor/Triggered Subsystem/MATLAB Function'
 * '<S140>' : 'Micro_mouse/Subsystem/Left Motor/Triggered Subsystem/PB0 (currA)'
 * '<S141>' : 'Micro_mouse/Subsystem/Left Motor/Triggered Subsystem/PB1 (currB)'
 * '<S142>' : 'Micro_mouse/Subsystem/Left Motor/Triggered Subsystem/PB0 (currA)/ECSoC'
 * '<S143>' : 'Micro_mouse/Subsystem/Left Motor/Triggered Subsystem/PB0 (currA)/ECSoC/ECSimCodegen'
 * '<S144>' : 'Micro_mouse/Subsystem/Left Motor/Triggered Subsystem/PB1 (currB)/ECSoC'
 * '<S145>' : 'Micro_mouse/Subsystem/Left Motor/Triggered Subsystem/PB1 (currB)/ECSoC/ECSimCodegen'
 * '<S146>' : 'Micro_mouse/Subsystem/Right Motor/Channel A'
 * '<S147>' : 'Micro_mouse/Subsystem/Right Motor/Direction'
 * '<S148>' : 'Micro_mouse/Subsystem/Right Motor/PWM'
 * '<S149>' : 'Micro_mouse/Subsystem/Right Motor/Triggered Subsystem'
 * '<S150>' : 'Micro_mouse/Subsystem/Right Motor/Channel A/ECSoC'
 * '<S151>' : 'Micro_mouse/Subsystem/Right Motor/Channel A/ECSoC/ECSimCodegen'
 * '<S152>' : 'Micro_mouse/Subsystem/Right Motor/Direction/ECSoC'
 * '<S153>' : 'Micro_mouse/Subsystem/Right Motor/Direction/ECSoC/ECSimCodegen'
 * '<S154>' : 'Micro_mouse/Subsystem/Right Motor/PWM/ECSoC'
 * '<S155>' : 'Micro_mouse/Subsystem/Right Motor/PWM/ECSoC/ECSimCodegen'
 * '<S156>' : 'Micro_mouse/Subsystem/Right Motor/Triggered Subsystem/MATLAB Function'
 * '<S157>' : 'Micro_mouse/Subsystem/Right Motor/Triggered Subsystem/PB0 (currA)'
 * '<S158>' : 'Micro_mouse/Subsystem/Right Motor/Triggered Subsystem/PB1 (currB)'
 * '<S159>' : 'Micro_mouse/Subsystem/Right Motor/Triggered Subsystem/PB0 (currA)/ECSoC'
 * '<S160>' : 'Micro_mouse/Subsystem/Right Motor/Triggered Subsystem/PB0 (currA)/ECSoC/ECSimCodegen'
 * '<S161>' : 'Micro_mouse/Subsystem/Right Motor/Triggered Subsystem/PB1 (currB)/ECSoC'
 * '<S162>' : 'Micro_mouse/Subsystem/Right Motor/Triggered Subsystem/PB1 (currB)/ECSoC/ECSimCodegen'
 */
#endif                                 /* Micro_mouse_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
