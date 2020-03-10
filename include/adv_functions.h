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

/*
 *#####################################################################
 *  Digital Sensor - Light Intensity
 *  ---------------------------------
 *#####################################################################
 */

/**
 * @brief Get the Light intensity from the sensor
 * 
 * @return int16_t the lux value on Success and -1 on Failure.
 */
extern int16_t getLux5();
/*
 *#####################################################################
 *  Digital Sensor - Distance
 *  -----------------------------
 *#####################################################################
 */
/**
 * @brief      Gets the distance from supported sensors.
 *
 * @return     The distance in cm.
 */
extern int16_t getCm7();
/*
 *#####################################################################
 *  Digital Sensor - Heart Rate
 *  -----------------------------
 *#####################################################################
 */

/**
 * @brief      Gets the Heart rate from supported sensors.
 *
 * @return     The Heart rate in bpm.
 */
extern int16_t getBpm8();

/*
 *#####################################################################
 *  Digital Sensor - Liquid Flow
 *  -----------------------------
 *#####################################################################
 */
/**
 * @brief      Gets the Flow from supported sensors.
 *
 * @return     The Flow in Liters per hour.
 */
extern int16_t getLph9();

/*
 *#####################################################################
 *  Digital Sensor - Motion sensor
 *  -----------------------------
 *#####################################################################
 */
/**
 * @brief      Get the status of the motion sensor
 *
 * @return     1 if motion detected else 0, -1 if error 
 */
extern uint8_t motionStatus10();
/*
 *#####################################################################
 *  Digital Sensor - Proximity
 *  -----------------------------
 *#####################################################################
 */
/**
 * @brief      Get status from the proximity sensor
 *
 * @return     1 if motion detected else 0, -1 if error 
 */
extern uint8_t proxmityStatus11();
/*
 *#####################################################################
 *  Digital Sensor - Touch
 *  -----------------------------
 *#####################################################################
 */

/**
 * @brief      Get status from the touch sensor
 *
 * @return     1 if motion detected else 0, -1 if error 
 */
extern uint8_t touchStatus12();
/*
 *#####################################################################
 *  Digital Sensor - Light
 *  -----------------------------
 *#####################################################################
 */

/**
 * @brief      Get status from the light blocking sensor
 *
 * @return     1 if motion detected else 0, -1 if error 
 */
extern uint8_t lightStatus13();
/*
 *#####################################################################
 *  Digital Sensor - Tilt
 *  -----------------------------
 *#####################################################################
 */
/**
 * @brief      Get status from the reed sensor
 *
 * @return     1 if motion detected else 0, -1 if error 
 */
extern uint8_t tiltStatus15();

/**
 * @brief      Get status from the tilt sensor
 *
 * @return     1 if motion detected else 0, -1 if error 
 */
extern uint8_t tiltStatus14();

/**
 * @brief      Get status from the ball switch sensor
 *
 * @return     1 if motion detected else 0, -1 if error 
 */
extern uint8_t tiltStatus18();

#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __ADV_FUNCTIONS_H__ */  /* End of Include Guard */
