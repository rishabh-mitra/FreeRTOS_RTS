#include <stdio.h>
#include <stdlib.h>

#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"

void vTask1(void *pvParameters)
{
	TickType_t xLastWakeTime;
	const TickType_t xPeriod = pdMS_TO_TICKS( 100 );
	//the above function converts milliseconds to ticks for system interrupts
	xLastWakeTime = xTaskGetTickCount();
	for(;;){
		printf("This is task for RTS group1 \n");
		vTaskDelayUntil( &xLastWakeTime, xPeriod );

	}
}

void vTask2(void *pvParameters)
{
	TickType_t xLastWakeTime;
	const TickType_t xPeriod = pdMS_TO_TICKS( 500 );
	//the above function converts milliseconds to ticks for system interrupts
	xLastWakeTime = xTaskGetTickCount();
	for(;;){
		printf("This is another task for RTS group1 \n");
		vTaskDelayUntil( &xLastWakeTime, xPeriod );

	}
}


int main_tasks( void )
{
	xTaskCreate( vTask1, 					/* Pointer to the function that implements the task. */
				"Task 1",					/* Text name for the task. This is to facilitate debugging only. */
				1000, 						/* Stack depth - small microcontrollers will use much less stack than this. */
				NULL, 						/* This example does not use the task parameter. */
				3, 							/* This task will run at priority 3. */
				NULL ); 					/* This example does not use the task handle. */

	/* Create the other task in exactly the same way and at different priority. */
	xTaskCreate( vTask2, "Task 2", 100, NULL, 1, NULL );

	/* Start the scheduler so the tasks start executing. */
	vTaskStartScheduler();

	return 0;
}
