/** @file KY-017.c
 *  @brief Contains low level functions for the Reed
 *         sensor. 
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
#include <stdint.h>
#include <stdio.h>
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
 * @brief      Initializes the Tilt sensor
 *
 * @param[in]  pin   The physical pin number that the sensor is connected.
 */
static void reed_begin(uint8_t pin)
{
        /* Check if this is already done */
        if (isSensorSetup == 0) {
                /* Initialize pin as INPUT */
                pinMode( pin, INPUT );
                /*Mark it as Done*/
                isSensorSetup = 1;
        }
}

/**
 * @brief      Reads the Reed sensor.
 *
 * @param[in]  pin   The physical pin number that the sensor is connected.
 *
 * @return     0 if the Not Tilted and 1 if Tilted.
 */
uint8_t read_reed(uint8_t pin) 
{       
        /* Initialize the sensor */        
        reed_begin(pin);
        /* Read the sensor */
        return digitalRead(pin);
}