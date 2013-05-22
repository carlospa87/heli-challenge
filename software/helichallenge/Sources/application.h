/**
 * @file application.h
 * @version 0.1
 * @date 02/05/2013
 * @author: Carlos Pereira Atencio
 * 
 * This header file contains the function calls for the general application
 * developed for the Heli-Challenge software.
 * It has been designed to work with FreeRTOS, and the functions defined here
 * are called within the scheduler.h/.c functions.
 * 
 * The software has been designed this way to hide a lot of the complexity
 * of the RTOS, and to reduce the amount of code introduced within the source
 * files automatically generated by the Processor Expert FreeRTOS component.
 *************************************************************************** */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "common.h"

typedef enum {
  Standby, Calibrate, Play, Difficulty, Test
} ApplicationState_t;

inline void initialiseAll(void);
inline void schedule20HzRelative(void);
inline void schedule50HzAbsolute(void);
inline void schedule1HzAbsolute(void);
ApplicationState_t stateStandBy(void);
ApplicationState_t statePlay(void);
ApplicationState_t stateCalibrate(void);
ApplicationState_t stateSelectDifficulty(void);
ApplicationState_t stateTestMode(void);

#endif /* APPLICATION_H_ */
