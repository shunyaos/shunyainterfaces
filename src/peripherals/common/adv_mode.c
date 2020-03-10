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
#include "HC-SR04.h"
#include "BH1750.h"
#include "YF-S201.h"
#include "SEN-11574.h"
#include "gpio_sensors.h"
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
                uint8_t busNum = get_i2c_bus_from_pin(pin);

                pcf8591Begin(busNum, set);

                adc = pcf8591_adc_read(busNum, channel);
        } else {
                /*Add Error: No such sensor connected! */
                adc = -1;
        }

        return adc;
}

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
int16_t get_lux_bh1750()
{

        uint8_t pin = get_pins_from_sids(BH1750, GEN_SDA);
        int16_t light;
        if (pin) {
                uint8_t busNum = get_i2c_bus_from_pin(pin);
                light = bh1750Read(busNum);
        } else {

                /*printf("Error: No such sensor connected!\n"); */
                light = -1;
        }

        return light;
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
int16_t get_cm_hcsr04()
{
        uint8_t echoPin = get_pins_from_sids(HCSR04, HCSR04_ECHO_PIN);
        uint8_t triggerPin = get_pins_from_sids(HCSR04, HCSR04_TRIG_PIN);

        return ultrasonic_dist_read(echoPin, triggerPin);
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
int16_t get_bpm_sen11574()
{

        int16_t rate = 0;
        uint8_t phyPin = get_pins_from_sids(SEN11574, 1);
        rate = sen11574_read(phyPin);

        return rate;
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
int16_t get_lph_yfs201()
{
        int16_t rate = 0;
        uint8_t phyPin = get_pins_from_sids(YFS201, 1);
        rate = yfs201_flow_read(phyPin);
        return rate;
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
uint8_t motion_status_pir()
{
        uint8_t value = 0;

        uint8_t phyPin = get_pins_from_sids(PIR, 1);
        value = read_pir(phyPin);

        return value;
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
uint8_t proxmity_status_ir()
{
        uint8_t value = 0;

        uint8_t phyPin = get_pins_from_sids(IR_PROXY, 1);
        value = read_ir_proximity(phyPin);

        return value;
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
uint8_t touch_status_touch()
{
        uint8_t value = 0;
        uint8_t phyPin = get_pins_from_sids(TOUCH, 1);
        value = read_touch(phyPin);
        return value;
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
uint8_t light_status_block()
{

        uint8_t value = 0;
        uint8_t phyPin = get_pins_from_sids(LIGHT_BLOCK, 1);
        value = read_light_blocking(phyPin);

        return value;
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
uint8_t tilt_status_reed()
{
        uint8_t value = 0;
        uint8_t phyPin;
        phyPin = get_pins_from_sids(KY_025, 1);
        value = read_reed(phyPin);

        return value;
}

/**
 * @brief      Get status from the tilt sensor
 *
 * @return     1 if motion detected else 0, -1 if error 
 */
uint8_t tilt_status_tilt()
{
        uint8_t value = 0;
        uint8_t phyPin;

        phyPin = get_pins_from_sids(KY_017, 1);
        value = read_tilt(phyPin);

        return value;
}

/**
 * @brief      Get status from the ball switch sensor
 *
 * @return     1 if motion detected else 0, -1 if error 
 */
uint8_t tilt_status_ball()
{
        uint8_t value = 0;
        uint8_t phyPin;

        phyPin = get_pins_from_sids(BALL_SWITCH, 1);
        value = read_tilt(phyPin);

        return value;
}