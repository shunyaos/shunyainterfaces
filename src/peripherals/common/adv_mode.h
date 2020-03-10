/** 
 * @file       adv_mode.h
 * @brief      Header file for Advance mode functions for 
 *             shunya interfaces library.
 *
 */

/*! Include Guard */
#ifndef __ADV_MODE_H__
#define __ADV_MODE_H__

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
 * @param set[in] PCF8591 settings structure
 * @param channel[in] PCF8591 ADC Channel number
 * @return int16_t (0-255) ADC Value on Success and -1 on Failure.
 */
extern int16_t get_adc_pcf8591(struct pcf8591Settings set, uint8_t channel);

/*
 *#####################################################################
 *  Digital Sensor - Light Intensity
 *  ---------------------------------
 *#####################################################################
 */
/**
 * @brief Get the LUX value from the BH1750 sensor
 * 
 */
extern int16_t get_lux_bh1750();
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
extern int16_t get_cm_hcsr04();

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
extern int16_t get_bpm_sen11574();

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
extern int16_t get_lph_yfs201();

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
extern uint8_t motion_status_pir();
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
extern uint8_t proxmity_status_ir();
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
extern uint8_t touch_status_touch();
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
extern uint8_t light_status_block();
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
extern uint8_t tilt_status_reed();

/**
 * @brief      Get status from the tilt sensor
 *
 * @return     1 if motion detected else 0, -1 if error 
 */
extern uint8_t tilt_status_tilt();

/**
 * @brief      Get status from the ball switch sensor
 *
 * @return     1 if motion detected else 0, -1 if error 
 */
extern uint8_t tilt_status_ball();

#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __ADV_MODE_H__ */  /* End of Include Guard */
