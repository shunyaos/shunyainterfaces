/** 
 * @file        simple_mode.c
 * @brief       This file contains functions for the simple mode
 *              of the shunya interfaces library. 
 *
 */

/*
 *#####################################################################
 *  Initialization block
 *  ---------------------
 *#####################################################################
 */

/* --- Standard Includes --- */
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <shunyaInterfaces.h>

/* --- Project Includes --- */
#include "simple_mode.h"

/*
 *#####################################################################
 *  Generic Digital Sensor
 *  ------------------------
 *#####################################################################
 */
/**
 * @brief Gets the status of any generic GPIO pin.
 *
 */
int8_t getStatus(uint8_t phyPin)
{
        return get_pin_status(phyPin);
}

/*
 *#####################################################################
 *  Digital Sensor - ADC
 *  -----------------------------
 *#####################################################################
 */

/**
 * @brief Gets the Analog to digital converted value.
 *
 */
int16_t getAdc(uint8_t channel)
{
        return get_adc(channel);
}