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
 *  Digital Sensor - Light Intensity
 *  ---------------------------------
 *#####################################################################
 */

/**
 * @brief Get the Light intensity from the sensor
 * 
 * @return int16_t the lux value on Success and -1 on Failure.
 */
int16_t getLux5()
{
        return get_lux_bh1750();
}

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
int16_t getCm7()
{
        return get_cm_hcsr04();
}

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
int16_t getBpm8()
{
        return get_bpm_sen11574();
}

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
int16_t getLph9()
{
        return get_lph_yfs201();
}

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
uint8_t motionStatus10()
{
        return motion_status_pir();
}
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
uint8_t proxmityStatus11()
{
        return proxmity_status_ir();
}
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
uint8_t touchStatus12()
{
        return touch_status_touch();
}
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
uint8_t lightStatus13()
{
        return light_status_block();
}
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
uint8_t tiltStatus15()
{
        return tilt_status_reed();
}

/**
 * @brief      Get status from the tilt sensor
 *
 * @return     1 if motion detected else 0, -1 if error 
 */
uint8_t tiltStatus14()
{
        return tilt_status_tilt();
}

/**
 * @brief      Get status from the ball switch sensor
 *
 * @return     1 if motion detected else 0, -1 if error 
 */
uint8_t tiltStatus18()
{
        return tilt_status_ball();
}