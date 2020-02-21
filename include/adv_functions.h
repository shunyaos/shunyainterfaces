/** 
 * @file       adv_functions.h
 * @brief      Header file for Advance mode functions for 
 *             shunya interfaces library.
 *
 */

/*! Include Guard */
#ifndef __ADV_FUNCTIONS_H__
#define __ADV_FUNCTIONS_H__

/*! CPP guard */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *#####################################################################
 *  Initialization block
 *  ---------------------
 *#####################################################################
 */

/* --- Standard Includes --- */
#include <stdlib.h>
#include <stdint.h>

/* --- Project Includes --- */
#include "pcf8591.h"
 

/*
 *#####################################################################
 *  Digital Sensor - ADC
 *  -----------------------------
 *#####################################################################
 */


/**
 * @brief Get the ADC value from the PCF8591 sensor
 * 
 * @param set PCF8591 settings structure
 * @param channel PCF8591 ADC Channel number
 * @return int16_t (0-255s) ADC Value on Success and -1 on Failure.
 */
extern int16_t getAdc6(struct pcf8591Settings set, uint8_t channel);


#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __ADV_FUNCTIONS_H__ */  /* End of Include Guard */
