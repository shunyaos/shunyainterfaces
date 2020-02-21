/** 
 * @file       simple_mode.h
 * @brief      Header file contains simple mode function prototypes.
 *
 */

/*! Include Guard */
#ifndef __SIMPLE_MODE_H__
#define __SIMPLE_MODE_H__

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
 * @brief      Gets the status of any generic GPIO pin.
 *
 * @param[in]  phyPin  The phy pin
 *
 * @return     0 & 1 as digital values and -1 if error occurs.
 */
extern int8_t get_pin_status(uint8_t phyPin);

/*
 *#####################################################################
 *  Digital Sensor - ADC
 *  -----------------------------
 *#####################################################################
 */

/**
 * @brief      Gets the Analog to digital converted value.
 *
 * @param[in]  channel  The ADC channel
 *
 * @return     The digital value for analog reading.
 */
extern int16_t get_adc(uint8_t channel);


#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __SIMPLE_MODE_H__ */  /* End of Include Guard */
