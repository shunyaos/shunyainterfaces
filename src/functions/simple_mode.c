/** 
 * @file        simple_mode.c
 * @brief       This file contains functions for the simple mode
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
#include <shunyaInterfaces.h>

/* --- Project Includes --- */
#include "simple_mode.h"
#include "generic.h"

/*
 *#####################################################################
 *  Generic Digital Sensor
 *  ------------------------
 *#####################################################################
 */
/**
 * @brief Gets the status of any generic GPIO pin.
 *
 */
int8_t getStatus(uint8_t phyPin)
{
        return get_pin_status(phyPin);
}

/*
 *#####################################################################
 *  Digital Sensor - ADC
 *  -----------------------------
 *#####################################################################
 */

/**
 * @brief Gets the Analog to digital converted value.
 *
 */
int16_t getAdc(uint8_t channel)
{
        return get_adc(channel);
}

/*
 *#####################################################################
 *  Digital Sensor - Light Intensity
 *  ---------------------------------
 *#####################################################################
 */
int16_t getLux()
{
        return get_lux();
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
int16_t getCm()
{
        return get_cm();
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
int16_t getBpm()
{
        return get_bpm();
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
int16_t getLph()
{
        return get_lph();
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
uint8_t motionStatus() 
{
        return motion_status();
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
uint8_t proxmityStatus() 
{
        return proxmity_status();
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
uint8_t touchStatus() 
{
        return touch_status();
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
uint8_t lightStatus() 
{
        return light_status();
}
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
uint8_t tiltStatus() 
{
        return tilt_status();
}

/*
 *#####################################################################
 *  Generic Digital Actuator
 *  ------------------------
 *#####################################################################
 */
/**
 * @brief Set any generic GPIO pin.
 *
 */
void setPin(uint8_t phyPin, uint8_t mode)
{
        generic_set(phyPin, mode);
}

/*
 *#####################################################################
 *  LED
 *  ------------------------
 *#####################################################################
 */
/**
 * @brief Set any generic GPIO pin.
 *
 */
void setLed(uint8_t phyPin, uint8_t mode)
{
        generic_set(phyPin, mode);
}

/*
 *#####################################################################
 *  RELAY
 *  ------------------------
 *#####################################################################
 */
/**
 * @brief Set any generic GPIO pin.
 *
 */
void setRelay(uint8_t phyPin, uint8_t mode)
{
        generic_set(phyPin, mode);
}