/*
										Mechatronics Department
										Gradution Project (2024)
							"Development and Design an Autonomous Self-parking Car"
	ADAS system that capable of performing perpendicular and parallel parking maneuvers was designed and developed. 
*/


/******************************
 * Includes
 *******************************/
#include "STM32F103x8.h"
#include "RCC.h"
#include "GPIO.h"
#include "ISR.h"
#include "TIMER.h"

#include "DC_MOTOR.h"
#include "SERVO_MOTOR.h"
#include "ULTRASONIC.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

//===========================================================================

/******************************
 * Generic Macros
 *****************************/

#define CLK											36000000

#define CAR_SPEED		    						6.7
#define total_counter								170

#define  BUZZER_PIN									PIN_12
#define  BUZZER_PORT								GPIOA

#define  ULTRA1_DISTANCE							5

uint32_t dist3;
uint32_t dist1, dist2;

uint8_t STATE = 0;

uint32_t total_steps_parallel=0, total_steps_perpendicular=0;

uint32_t PERPENDICULAR_COUNTER=0, PARALLEL_COUNTER=0;


/******************************
 * Parking Slot Consideration
 *****************************/

/* PERPINDECULAR PARK */
#define PERPINDECULAR_PARKING_WIDTH					40
#define PERPINDECULAR_PARKING_LENGTH				20

/* PARALLEL PARK */
#define PARALLEL_PARKING_WIDTH						20
#define PARALLEL_PARKING_LENGTH						40


/********************************
 * Path Planning Consideration
 ********************************/

/* PARALLEL PARKING */
//delay
#define PARALLEL_START_POS_TIME						1350
#define PARALLEL_ARC1_TIME							2600
#define PARALLEL_ARC2_TIME							2800
#define PARALLEL_LINE_TIME							2600
//Servo Angle
#define PARALLEL_ARC_STEERING_ANGLE1				135
#define PARALLEL_LINE_STEERING_ANGLE				90
#define PARALLEL_ARC_STEERING_ANGLE3				45


/* PERPINDECULAR PARKING */
//delay
#define PERPINDECULAR_START_POS_TIME				2000
#define PERPINDECULAR_ARC_TIME						6800
#define PERPINDECULAR_LINE__TIME					1300
//Servo Angle
#define PERPINDECULAR_ARC_STEERING_ANGLE1			130
#define PERPINDECULAR_LINE_STEERING_ANGLE			90


//===========================================================================
void STATE0(void);
void STATE1(void);
void STATE2(void);
void STATE3(void);
void AVOID_FRONT_OBSTACLES(void);
void PARALLEL_PATH_PLANNING(void);
void PERPENDICULAR_PATH_PLANNING(void);
void DIAMOND_PATH_PLANNING(void);
//===========================================================================

/******************************
 * Generic Functions
 *****************************/

void RCC_INIT(void)
{
	MCAL_RCC_GetSYS_CLCKFreq(RCC_36MHZ);
	MCAL_RCC_GetHCLKFreq();
	MCAL_RCC_GetPCLK1Freq();
	MCAL_RCC_GetPCLK2Freq();
	MCAL_RCC_Peripherals_enable(APB2, RCC_GPIOA, Enable);
	MCAL_RCC_Peripherals_enable(APB2, RCC_GPIOB, Enable);
}


void HW_INIT()
{
	//DC Motor Initialization
	HAL_MOTOR_Init();

	//Ultrasonic Sensors Initialization
	HAL_ULTRASONIC_INIT(ULT1);
	HAL_ULTRASONIC_INIT(ULT2);
	HAL_ULTRASONIC_INIT(ULT3);
	HAL_ULTRASONIC_INIT(ULT4);

}


/**================================================================
 * @Fn			- CALCULATION_COUNTER
 * @brief 		-
 * @param [in] 	- distance - speed
 * @retval 		- counter
 * Note			- none
 */
uint32_t CALCULATION_COUNTER (uint32_t distance ,float speed )
{
	uint32_t counter;
	counter=((distance/speed)*1000)/40.01;
	return counter;

}

//=============================================================================================

//===================================================================================

int main(void)
{
	/*MCU Peripherals and HW Components Initialization*/
	RCC_INIT();
	HW_INIT();

	PARALLEL_COUNTER=(CALCULATION_COUNTER(PARALLEL_PARKING_LENGTH, CAR_SPEED)/2);
	PERPENDICULAR_COUNTER=(CALCULATION_COUNTER(PERPINDECULAR_PARKING_LENGTH, CAR_SPEED)/2);

	while(1)
	{
		STATE1();
		STATE2();
		if(STATE == 3)
		{
			STATE3();
		}
		//DIAMOND_PATH_PLANNING();
	}
}


//=====================================================================================

/**================================================================
 * @Fn			- STATE0
 * @brief 		- Calibration of if car is parallel to the track or not
 * @param [in] 	- none
 * @retval 		- none
 * Note			- none
 */
void STATE0(void)
{
	HAL_Servo_Set_Angle(90, CLK);

	int DIS1, DIS2, DIFFERENCE;
	uint32_t ANGLE;

	DIS1 = HAL_ULTRASONIC_GET_DISTANCE(ULT2);
	DIS2 = HAL_ULTRASONIC_GET_DISTANCE(ULT3);
	DIFFERENCE = DIS1 - DIS2;

	//If (difference>1); the car is heading to the left, change steering angle to the right {90-(1.5*difference)}
	if(DIFFERENCE > 1)
	{
		while(DIFFERENCE > 1)
		{
			DIS1 = HAL_ULTRASONIC_GET_DISTANCE(ULT2);
			DIS2 = HAL_ULTRASONIC_GET_DISTANCE(ULT3);
			DIFFERENCE = DIS1 - DIS2;

			ANGLE = 90 - (1.5 * DIFFERENCE);
			HAL_Servo_Set_Angle(ANGLE, CLK);
			HAL_MOTOR_Motion(FORWARD);
		}
		HAL_MOTOR_Motion(STOP);
		HAL_Servo_Set_Angle(90, CLK);
	}
	//If (difference<-1); the car is heading to the right, change steering angle to the left {90+(1.5*difference)}
	else if(DIFFERENCE < -1)
	{
		while(DIFFERENCE < -1)
		{
			DIS1 = HAL_ULTRASONIC_GET_DISTANCE(ULT2);
			DIS2 = HAL_ULTRASONIC_GET_DISTANCE(ULT3);
			DIFFERENCE = DIS1 - DIS2;

			ANGLE = 90 + (1.5 * DIFFERENCE);
			HAL_Servo_Set_Angle(ANGLE, CLK);
			HAL_MOTOR_Motion(FORWARD);
		}
		HAL_MOTOR_Motion(STOP);
		HAL_Servo_Set_Angle(90, CLK);
	}
	//If their is no difference ( (difference < 1) && (difference > -1) )
	else if( (DIFFERENCE < 1) && (DIFFERENCE > -1) )
	{
		HAL_MOTOR_Motion(STOP);
		HAL_Servo_Set_Angle(90, CLK);
	}
}



/**================================================================
 * @Fn			- STATE1
 * @brief 		- Car moves straight and starts detection if their is any empty spots
 * @param [in] 	- none
 * @retval 		- none
 * Note			- none
 */
void STATE1(void)
{
	//Start Moving and Searching
	HAL_MOTOR_Motion(FORWARD);
	HAL_Servo_Set_Angle(90, clk);
	MCAL_GPIO_WRITEPIN(GPIOA, PIN_10, 0);

	//Check if any obstacle in front of the car
	dist3=HAL_ULTRASONIC_GET_DISTANCE(ULT1);
	if (dist3 <= ULTRA1_DISTANCE)
	{
		AVOID_FRONT_OBSTACLES();
	}

	//Start moving again
	HAL_MOTOR_Motion(FORWARD);

}



/**================================================================
 * @Fn			- STATE2
 * @brief 		- Car detect a spot and decide if it enough or not
 * @param [in] 	- none
 * @retval 		- none
 * Note			- none
 */
void STATE2(void)
{
	//Update the distance of ULT2
	dist1=HAL_ULTRASONIC_GET_DISTANCE(ULT2);

	//Check for empty spot
	if(dist1>=PARALLEL_PARKING_WIDTH)
	{
		while(dist1>=PARALLEL_PARKING_WIDTH ) // update the distance
		{
			dist3=HAL_ULTRASONIC_GET_DISTANCE(ULT1);

			//Check if any obstacle in front of the car
			if (dist3<=ULTRA1_DISTANCE)
			{
				AVOID_FRONT_OBSTACLES();
			}

			HAL_MOTOR_Motion(FORWARD);

			if((dist1>=PERPINDECULAR_PARKING_WIDTH))
			{
				total_steps_perpendicular++;
			}

			dist1=HAL_ULTRASONIC_GET_DISTANCE(ULT2);
			total_steps_parallel++;

			//if their is no more obstacles or the car is parking in a free space, it will parking without a feedback from ultrasonic sensor
			dist1=HAL_ULTRASONIC_GET_DISTANCE(ULT2);
			dist2=HAL_ULTRASONIC_GET_DISTANCE(ULT3);
			if(total_steps_parallel >= (PARALLEL_COUNTER*1.2))
			{

				if((dist2>=PARALLEL_PARKING_WIDTH) && (dist1>=PARALLEL_PARKING_WIDTH))
				{
					HAL_MOTOR_Motion(STOP);
					delay(250, U_ms, clk);
					PARALLEL_PATH_PLANNING();
					HAL_MOTOR_Motion(STOP);
					delay(5000, U_ms, clk);
				}
			}

			if(total_steps_perpendicular >=  (PERPENDICULAR_COUNTER*1.8))
			{

				if((dist2>=PERPINDECULAR_PARKING_WIDTH) && (dist1>=PARALLEL_PARKING_WIDTH))
				{
					HAL_MOTOR_Motion(STOP);
					delay(250, U_ms, clk);
					PERPENDICULAR_PATH_PLANNING();
					HAL_MOTOR_Motion(STOP);
					delay(5000, U_ms, clk);
				}
			}
			//
		}
		STATE = 3;
	}

}



/**================================================================
 * @Fn			- STATE3
 * @brief 		- Car detect an enough spot and stop at the start point
 * @param [in] 	- none
 * @retval 		- none
 * Note			- none
 */
void STATE3(void)
{

	if(STATE == 3)
	{

		HAL_MOTOR_Motion(FORWARD);
		dist2=HAL_ULTRASONIC_GET_DISTANCE(ULT3);

		while(dist2>=PARALLEL_PARKING_WIDTH) // update the distance
		{
			dist2=HAL_ULTRASONIC_GET_DISTANCE(ULT3);
			HAL_MOTOR_Motion(FORWARD);

			//

			//
		}

		if( total_steps_parallel >=PARALLEL_COUNTER )
		{

			HAL_MOTOR_Motion(STOP);
			delay(250, U_ms, clk);
			PARALLEL_PATH_PLANNING();
			HAL_MOTOR_Motion(STOP);
			delay(5000, U_ms, clk);
		}
		else if (total_steps_perpendicular >=  PERPENDICULAR_COUNTER)
		{
			HAL_MOTOR_Motion(STOP);
			delay(250, U_ms, clk);
			PERPENDICULAR_PATH_PLANNING();
			HAL_MOTOR_Motion(STOP);
			delay(5000, U_ms, clk);
		}
	}

}



/**================================================================
 * @Fn			- AVOID_FRONT_OBSTACLES
 * @brief 		- Get the distance from front ultrasonic sensor (ULT1)
 * 				  and if any obstacle is front of the car stop and start buzzer
 * @param [in] 	- none
 * @retval 		- none
 * Note			- none
 */
void AVOID_FRONT_OBSTACLES(void)
{
	while(dist3<=ULTRA1_DISTANCE)
	{

		MCAL_GPIO_INIT(BUZZER_PORT, BUZZER_PIN, Output_PP_Mode_Speed10MHZ);
		HAL_MOTOR_Motion(STOP);
		MCAL_GPIO_WRITEPIN(BUZZER_PORT, BUZZER_PIN, 1);
		delay(1000, U_ms, clk);
		MCAL_GPIO_WRITEPIN(BUZZER_PORT, BUZZER_PIN, 0);
		delay(500, U_ms, clk);

		dist3=HAL_ULTRASONIC_GET_DISTANCE(ULT1);

	}

}



/**================================================================
 * @Fn			- PARALLEL_PATH_PLANNING
 * @brief 		- Parallel self-parking
 * @param [in] 	- none
 * @retval 		- none
 * Note			- none
 */
void PARALLEL_PATH_PLANNING(void)
{
	/**********************
	 * Start point
	 *********************/
	// Stop the car with the end of the obstacle
	HAL_MOTOR_Motion(STOP);
	delay(200, U_ms, CLK);
	HAL_MOTOR_Motion(FORWARD);
	delay(PARALLEL_START_POS_TIME, U_ms, CLK);
	HAL_MOTOR_Motion(STOP);
	delay(250, U_ms, CLK);


	/**********************
	 * First maneuver
	 *********************/
	// First arc mode
	HAL_Servo_Set_Angle(PARALLEL_ARC_STEERING_ANGLE1, CLK);
	delay(250, U_ms, CLK);
	HAL_MOTOR_Motion(REVERSE);
	delay(PARALLEL_ARC1_TIME, U_ms, CLK);
	HAL_MOTOR_Motion(STOP);
	delay(250, U_ms, CLK);

	// Straight line mode
	HAL_Servo_Set_Angle(PARALLEL_LINE_STEERING_ANGLE, CLK);
	delay(250, U_ms, CLK);
	HAL_MOTOR_Motion(REVERSE);
	delay(PARALLEL_LINE_TIME, U_ms, CLK);
	HAL_MOTOR_Motion(STOP);
	delay(250, U_ms, CLK);

	// Second arc mode
	HAL_Servo_Set_Angle(PARALLEL_ARC_STEERING_ANGLE3, CLK);
	delay(250, U_ms, CLK);
	HAL_MOTOR_Motion(REVERSE);
	delay(PARALLEL_ARC2_TIME, U_ms, CLK);
	HAL_MOTOR_Motion(STOP);
	delay(250, U_ms, CLK);
	HAL_Servo_Set_Angle(90, CLK);
	delay(10000, U_ms, CLK);


	/**********************
	 * Second maneuver
	 *********************/
	// Made the car stop in the middle of its parking space
	// Front distance = 8cm, move 4cm

}



/**================================================================
 * @Fn			- PERPENDICULAR_PATH_PLANNING
 * @brief 		- PERPENDICULAR self-parking
 * @param [in] 	- none
 * @retval 		- none
 * Note			- none
 */
void PERPENDICULAR_PATH_PLANNING(void)
{
	/**********************
	 * Start point
	 *********************/
	// Stop the car with the end of the obstacle
	HAL_MOTOR_Motion(STOP);
	delay(200, U_ms, CLK);
	HAL_MOTOR_Motion(FORWARD);
	delay(PERPINDECULAR_START_POS_TIME, U_ms, CLK);
	HAL_MOTOR_Motion(STOP);
	delay(250, U_ms, CLK);

	//second arc mode
	HAL_Servo_Set_Angle(PERPINDECULAR_ARC_STEERING_ANGLE1, clk);
	HAL_MOTOR_Motion(REVERSE);
	delay(PERPINDECULAR_ARC_TIME, U_ms, clk);
	HAL_MOTOR_Motion(STOP);
	delay(250, U_ms, clk);

	//straight line mode
	HAL_Servo_Set_Angle(PERPINDECULAR_LINE_STEERING_ANGLE, clk);
	HAL_MOTOR_Motion(REVERSE);
	delay(PERPINDECULAR_LINE__TIME, U_ms, clk);
	HAL_MOTOR_Motion(STOP);
	delay(10000, U_ms, CLK);
}



/**================================================================
 * @Fn			- DIAMOND_PATH_PLANNING
 * @brief 		- DIAMOND self-parking
 * @param [in] 	- none
 * @retval 		- none
 * Note			- none
 */
void DIAMOND_PATH_PLANNING(void)
{
	HAL_Servo_Set_Angle(90, clk);
	delay(1000, U_ms, CLK);
	HAL_Servo_Set_Angle(120, clk);
	delay(250, U_ms, CLK);
	HAL_MOTOR_Motion(FORWARD);
	delay(6500, U_ms, CLK);
	HAL_MOTOR_Motion(STOP);
	delay(250, U_ms, CLK);
	HAL_Servo_Set_Angle(90, CLK);
	delay(10000, U_ms, CLK);
}

