/** 
 * @file       simple_functions.h
 * @brief      Header file contains simple mode function prototypes.
 *
 */

/*! Include Guard */
#ifndef __SIMPLE_FUNCTIONS_H__
#define __SIMPLE_FUNCTIONS_H__

#include <stdlib.h>
#include <stdint.h>

/*! CPP guard */
#ifdef __cplusplus
extern "C" {
#endif
 
/*
 *#####################################################################
 *  Generic Digital Sensor
 *  ------------------------
 *#####################################################################
 */

/**
 * @brief Gets the status of any generic GPIO pin
 * 
 * @param phyPin Physical GPIO pin number
 * @return int8_t GPIO pin values on Success and -1 on Failure
 */
extern int8_t getStatus(uint8_t phyPin);


/*
 *#####################################################################
 *  Digital Sensor - ADC
 *  -----------------------------
 *#####################################################################
 */

/**
 * @brief Get the Adc value from the sensor.
 * 
 * @param channel ADC Channel number.
 * @return int16_t N bit ADC value on Success and -1 on Failure.
 */
extern int16_t getAdc(uint8_t channel);


#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __SIMPLE_FUNCTIONS_H__ */  /* End of Include Guard */
