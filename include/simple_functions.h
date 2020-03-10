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

/*
 *#####################################################################
 *  Digital Sensor - Light Intensity
 *  ---------------------------------
 *#####################################################################
 */

/**
 * @brief Get the Lux value from the sensor.
 * 
 * @return int16_t the lux value on Success and -1 on Failure.
 */
extern int16_t getLux();

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
extern int16_t getCm();

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
extern int16_t getBpm();

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
extern int16_t getLph();

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
extern uint8_t motionStatus();
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
extern uint8_t proxmityStatus();
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
extern uint8_t touchStatus();
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
extern uint8_t lightStatus();
/*
 *#####################################################################
 *  Digital Sensor - Tilt
 *  -----------------------------
 *#####################################################################
 */

/**
 * @brief      Get status from the light blocking sensor
 *
 * @return     1 if motion detected else 0, -1 if error 
 */
extern uint8_t tiltStatus();

#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __SIMPLE_FUNCTIONS_H__ */  /* End of Include Guard */
