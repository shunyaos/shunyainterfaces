/** @file ball-switch.c
 *  @brief Contains low level functions for the ball switch
 *         sensor.
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
#include <stdint.h>
/* --- Project Includes --- */
#include <shunyaInterfaces.h>

/*
 * I know Global variables are evil. I you find a better way to 
 * do this without using Global variables then Please tell me 
 * by mail yogesh@iotiot.in
 */
/* Global variable to store the status of the setup */
static uint8_t isSensorSetup = 0;

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
 * @brief      Initializes the ball switch sensor
 *
 * @param[in]  pin   The physical pin number that the sensor is connected.
 */
void ball_switch_begin(uint8_t pin)
{
    /* Initialize pin as INPUT */
        if (isSensorSetup == 0) {
                pinMode(pin,INPUT);
                isSensorSetup = 1;
        }
}

/**
 * @brief      Reads the ball_switch sensor.
 *
 * @param[in]  pin   The physical pin number that the sensor is connected.
 *
 * @return     0 if Not Tilted and 
 *             1 if Tilted. 
 */
uint8_t read_ball_switch(uint8_t pin) 
{
          ball_switch_begin(pin);
          return digitalRead(pin);
}
