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

/*
 *#####################################################################
 *  Digital Sensor - Light Intensity
 *  ---------------------------------
 *#####################################################################
 */

/**
 * @brief      Gets the Light Intensity from the supported sensors.
 *
 * @return     The Light Intensity in Lux.
 */
extern int16_t get_lux();

/*
 *#####################################################################
 *  Digital Sensor - Distance
 *  -----------------------------
 *#####################################################################
 */

/**
 * @brief      Gets the distance from supported sensors.
 *
 * @param[in]  sensor      Sensor Unique number 
 * @param[in]  echoPin     The echo pin
 * @param[in]  triggerPin  The trigger pin
 *
 * @return     The distance in cm.
 */
extern int16_t get_cm();

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
extern int16_t get_bpm();

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
extern int16_t get_lph();

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
extern uint8_t motion_status();
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
extern uint8_t proxmity_status();
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
extern uint8_t touch_status();
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
extern uint8_t light_status();
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
extern uint8_t tilt_status();
/*
 *#####################################################################
 *  Digital Sensor - Current 
 *  -----------------------------
 *#####################################################################
 */
/**
 * @brief      Gets the Flow from supported sensors.
 *
 * @return     The Flow in Liters per hour.
 */
extern int16_t get_ampac();

/**
 * @brief      Gets the Flow from supported sensors.
 *
 * @return     The Flow in Liters per hour.
 */
extern int16_t get_ampdc();


#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __SIMPLE_MODE_H__ */  /* End of Include Guard */
