/** 
 * @file SEN-11574.c
 * @brief This file provides the source code for interfacing the
 *               Heartbeat Sensor module SEN-11574
 *
 * @author Gaurav Kelkar
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

/* --- Project Includes --- */
#include "shunyaInterfaces.h"
#include "SEN-11574.h"

static int isSENSetup = FALSE;

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
 *  @brief      Setup Heartbeat Sensor on given GPIO pin
 *  @param      pin Physical GPIO pin number
 *  @return     None
 */
static void heartbeatSensorSetup(int8_t pin) 
{
        pinMode(pin, INPUT);
        isSENSetup = TRUE;
}

/**
 *  @brief      Setup Heartbeat Sensor on given GPIO pin
 *  @param      pin Physical GPIO pin number
 *  @return     Return Heart rate in bpm on SUCCESS, 
 *              Return -1 on FAILURE
 */
static int16_t heartbeatSensorRead(int8_t pin) 
{
        int time = 0;
        int tempLOW, tempHIGH, bpm; 
        
        tempHIGH = millis();

        while (digitalRead(pin));
        
        time = millis() - tempHIGH;
        
        delay(10);

        tempLOW = millis();
        
        while (!digitalRead(pin));
        
        time += millis() - tempLOW;

        bpm = 60 * (1000.0 / time);
        if (bpm < 220)
                return bpm;
        else
                return -1;       
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

int16_t sen11574_read (int8_t pin)
{

        /* Initializes the I2C device */
        if (!isSENSetup){
                heartbeatSensorSetup(pin);    
        }

        return heartbeatSensorRead(pin);

} 
