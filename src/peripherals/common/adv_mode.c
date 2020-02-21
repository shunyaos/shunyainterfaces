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
 *  This block contains initialization code for this particular file.
 *  It typically contains Includes, constants or global variables used
 *  throughout the file.
 *#####################################################################
 */

/* --- Standard Includes --- */
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/* --- Project Includes --- */
#include "sensor_ids.h"
#include "peripheral.h"
#include "adv_mode.h"

#include "pcf8591.h"
 
/*
 *#####################################################################
 *  Process block
 *  -------------
 *#####################################################################
 */

/**
 * @brief Get the ADC value from the PCF8591 sensor
 * 
 */
int16_t get_adc_pcf8591(struct pcf8591Settings set, uint8_t channel)
{

        uint8_t pin = get_pins_from_sids(PCF8591, GEN_SDA);
        int16_t adc;
        if (pin) {
                uint8_t busNum = get_i2c_bus_from_pin (pin);

                pcf8591Begin(busNum, set);
                
                adc = pcf8591_adc_read(busNum, channel);
        } else {
                /*Add Error: No such sensor connected! */
                adc = -1;
        }

        return adc;
}