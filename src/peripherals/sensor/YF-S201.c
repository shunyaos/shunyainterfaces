/** 
 * @file YF-S201.c
 * @brief This file provides the functions for library
 *               Water flow Sensor module YF-S201.
 *
 * @author Vaibhav Shinde
 * @bug No known bugs.
 */

/*
 *#####################################################################
 *  Initialization block
 *  ---------------------
 *  This block contains initialization code for this particular file.
 *  It typically contains Includes, constants or global variables used
 *  throughout the file.
 *#####################################################################
 */

/* --- Standard Includes --- */
#include <stdio.h>
#include <stdlib.h>
#include <shunyaInterfaces.h>

/* --- Project Includes --- */
#include "YF-S201.h"

static int isWaterFlowInit = FALSE;
/* Measures flow meter pulses */
volatile int  flow_frequency;  
/* Calculated litres/hour */     
int  l_hour;                                    
long currentTime;
long cloopTime;

/*
 *#####################################################################
 *  Process block
 *  -------------
 *  This block contains all the process code for the particular layer.
 *  It typically contains internal functions and external functions 
 *  which implement the functionalities of the respective layer.
 *#####################################################################
 */

/**
 * @brief Interrupt function to count when pulse rises.
 */
static void flowFunction() 
{ 
	flow_frequency++;
} 
/**
 *  @brief      Setup Water Flow Sensor on given GPIO pin
 *  @param      Physical GPIO pin number
 *  @return     None
 */
void yfs201Begin(int pin) 
{

	/* Initializing flow_frequency */
	flow_frequency = 0;

	/* Setup Interrupt */ 
	attachInterrupt(pin, flowFunction, INT_EDGE_RISING);

	currentTime = millis();
	cloopTime = currentTime;
	isWaterFlowInit = TRUE;
}
/**
 *  @brief      Read Water Flow Sensor on given GPIO pin
 *  @param      Physical GPIO pin number
 *  @return     Return Heart rate in bpm on SUCCESS, 
 *              Return -1 on FAILURE
 */
int16_t yfs201getFlow() 
{
	currentTime = millis();

	/* Every second, calculate and print liters/hour */
	if(currentTime >= (cloopTime + 1000)) {
		/* Updates cloopTime */
		cloopTime = currentTime; 

		/* Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min. 
		 * (Results in +/- 3% range)
		 */
		/* (Pulse frequency x 60 min) / 7.5 = flow rate in L/hour */ 
		l_hour = (flow_frequency * 60 / 7.5);

		flow_frequency = 0;
	}
	return l_hour;
}

/*
 *#####################################################################
 *  Passing block
 *  -------------
 *  This block contains functions which pass the data to the next layer.
 *
 *  Note : This block is not implemented yet.
 *  Reason : Since the code for passing the data is very trivial and
 *           Creating another function just to pass the data will make 
 *           a copy of the data increasing program's memory consumption.
 *#####################################################################
 */

/**
 * @brief Simple Wrappers for reading data from the sensor 
 *
 * @param pin GPIO pin connected to sensor 
 *
 * @return Water flow in liters/hour
 */
int16_t yfs201_flow_read (int pin)
{

	/* Initializes the I2C device */
	if (!isWaterFlowInit){
		yfs201Begin(pin);    
	}

	return yfs201getFlow();
} 

