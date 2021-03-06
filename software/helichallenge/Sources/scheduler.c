/**
 * @file scheduler.c
 * @date 02/05/2013
 * @author: Carlos Pereira Atencio
 **************************************************************************** */
#include "scheduler.h"
#include "application.h"
#include "portmacro.h"
#include "FRTOS1.h"
#ifdef DEBUGFLAG
#include "accelerometer.h"
#endif


/**
 * portTASK_FUNCTION for task50HzAbsolute
 * This one is meant to flash the 7 segment display at 50hz
 * @param task50HzAbsolute Name of the task
 *        pvParameters Parameter to pass, not used
 *************************************************************************** */
static portTASK_FUNCTION(task500HzAbsolute, pvParameters) {
  (void)pvParameters; /* parameter not used */
  /* Set up the parameters for vTaskDelayUntil */
  portTickType xLastWakeTime = xTaskGetTickCount();
  const portTickType xFrequency = 2/portTICK_RATE_MS;
  for(;;) {
    /* Wait for the next cycle */
    vTaskDelayUntil(&xLastWakeTime, xFrequency);
    schedule500HzAbsolute();
  }
} 


/**
 * portTASK_FUNCTION for task20HzRelative
 * This is the main function of the application where the state machine and
 * all operational code will be executed.
 * @param task20HzRelative Name of the task
 *        pvParameters Parameter to pass, not used
 *************************************************************************** */
static portTASK_FUNCTION(task40HzRelative, pvParameters) {
  (void)pvParameters; /* parameter not used */
  for(;;) {
    schedule40HzRelative();
	FRTOS1_vTaskDelay(25/portTICK_RATE_MS);
  }
}


/**
 * portTASK_FUNCTION for task1HzAbsolute
 * This function is to be called once a second in a absolute manner.
 * @param task1HzAbsolute Name of the task
 *        pvParameters Parameter to pass, not used
 *************************************************************************** */
static portTASK_FUNCTION(task1HzAbsolute, pvParameters) {
  (void)pvParameters; /* parameter not used */
  /* Set up the parameters for vTaskDelayUntil */
  portTickType xLastWakeTime = xTaskGetTickCount();
  const portTickType xFrequency = 1000/portTICK_RATE_MS;
  for(;;) {
    /* Wait for the next cycle */
    vTaskDelayUntil(&xLastWakeTime, xFrequency);
    schedule1HzAbsolute();
  }
} 


/**
 * Creates and assigns the tasks to the RTOS.
 *************************************************************************** */
void createTasks() {
  if (FRTOS1_xTaskCreate(
      task40HzRelative,           /* pointer to the task */
      (signed portCHAR *)"task40HzRelative", /* task name */
      configMINIMAL_STACK_SIZE,   /* task stack size */
      (void*)NULL,                /* optional task startup argument */
      tskIDLE_PRIORITY,           /* initial priority */
      (xTaskHandle*)NULL          /* optional task handle to create */
    ) != pdPASS) {
    /*lint -e527 */
    for(;;){}; /* error! probably out of memory */
    /*lint +e527 */
  }
  
  if (FRTOS1_xTaskCreate(
      task500HzAbsolute,           /* pointer to the task */
      (signed portCHAR *)"task500HzAbsolute", /* task name */
      configMINIMAL_STACK_SIZE,   /* task stack size */
      (void*)NULL,                /* optional task startup argument */
      tskIDLE_PRIORITY,           /* initial priority */
      (xTaskHandle*)NULL          /* optional task handle to create */
    ) != pdPASS) {
    /*lint -e527 */
    for(;;){}; /* error! probably out of memory */
    /*lint +e527 */
  }
  
  if (FRTOS1_xTaskCreate(
      task1HzAbsolute,             /* pointer to the task */
      (signed portCHAR *)"task1HzAbsolute", /* task name */
      configMINIMAL_STACK_SIZE,   /* task stack size */
      (void*)NULL,                /* optional task startup argument */
      tskIDLE_PRIORITY,           /* initial priority */
      (xTaskHandle*)NULL          /* optional task handle to create */
    ) != pdPASS) {
    /*lint -e527 */
    for(;;){}; /* error! probably out of memory */
    /*lint +e527 */
  } 
}
