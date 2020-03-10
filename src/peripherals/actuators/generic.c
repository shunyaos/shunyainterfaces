/** @file       generic.c
 *  @brief      File contains code for generic actuator.
 * 
 *  @author Yogesh Hegde
 *  @bug No known bugs.
 */

/*
 *#####################################################################
 *  Initialization block
 *  ---------------------
 *#####################################################################
 */


/* --- Standard Includes --- */
#include <stdio.h>
#include <stdlib.h>

/* --- Project Includes --- */
#include "shunyaInterfaces.h"
#include "generic.h"

/**
 * @brief Flag to check if the setup is done 
 */
/* Global variable to store the status of the setup */
static uint8_t isActuatorSetup = 0;

/*
 *#####################################################################
 *  Process block
 *  -------------
 *#####################################################################
 */

/**
 * @brief      Initializes the actuator
 *
 * @param[in]  pin   The physical pin number that the led is connected.
 */
void generic_begin(uint8_t pin)
{
    /* Initialize pin as INPUT */
        if (isActuatorSetup == 0) {
                pinMode(pin,OUTPUT);
                isActuatorSetup = 1;
        }
}

/**
 * @brief      Sets the actuator to on or off
 *
 * @param[in]  pin   The physical pin number that the actuator is connected.
 * @param[in]  mode  the mode of the pin ON or OFF.
 *
 */
void generic_set(uint8_t pin, uint8_t mode) 
{
          generic_begin(pin);
          digitalWrite(pin, mode);
}