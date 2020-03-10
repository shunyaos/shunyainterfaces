/** 
 * @file        LM393.c
 * @brief       Contains low level functions for the LM393 small sound 
 *              sensor. 
 *
 *  @author Yogesh Hegde
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
 * @brief      Initializes the Small sound sensor
 *
 * @param[in]  pin   The physical pin number that the sensor is connected.
 */
void small_sound_begin(uint8_t pin)
{
    /* Initialize pin as INPUT */
        if (isSensorSetup == 0) {
                pinMode(pin,INPUT);
                isSensorSetup = 1;
        }
}

/**
 * @brief      Reads the small sound sensor.
 *
 * @param[in]  pin   The physical pin number that the sensor is connected.
 *
 * @return     0 if the Sound is lower than threshold and 
 *             1 if the Sound is higher than threshold. 
 */
uint8_t read_small_sound(uint8_t pin) 
{
          small_sound_begin(pin);
          return digitalRead(pin);
}
