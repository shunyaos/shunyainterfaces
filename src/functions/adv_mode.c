/** 
 * @file        adv_mode.c
 * @brief       This file contains functions for the advance mode
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
/* --- Project Includes --- */
#include "adv_mode.h"

/*
 *#####################################################################
 *  Digital Sensor - ADC
 *  -----------------------------
 *#####################################################################
 */

/**
 * @brief Get the ADC value from the PCF8591 sensor
 * 
 */
int16_t getAdc6(struct pcf8591Settings set, uint8_t channel)
{
        return get_adc_pcf8591(set, channel);
}