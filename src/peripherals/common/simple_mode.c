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

/**
 * TODO : Error Handling for the Layer
 */

/* --- Project Includes --- */
#include "sensor_ids.h"
#include "peripheral.h"
#include "simple_mode.h"

#include "pcf8591.h"
#include "HC-SR04.h"
#include "BH1750.h"
#include "YF-S201.h"
#include "SEN-11574.h"
#include "gpio_sensors.h"

#define SENSORS_MAX 10

extern int32_t errNum;

/*
 *#####################################################################
 *  Process block
 *  ---------------------
 *#####################################################################
 */

/**
 * @brief      Find the sensors connected to the Boards
 *
 * @param      list[in]  list of sensors to find the id from
 *
 * @return     int16_t Sensor ID on Success and -1 on Failure
 */
static int16_t find_connected_sensors (uint8_t list[])
{
        /* Default value -1 to be returned if unable to find the sensor */ 
        uint8_t sensor = -1;
        for (uint8_t index = 0; index < SENSORS_MAX ; index++ ) {

                int32_t tmp;
                /* Check if the sensor ID exists in the YAML */
                tmp = check_sid_exist(list[index]);

                /* If exists then the sensor is connected */
                if (tmp > 0) {
                        /* If sensor connected then return the correct value 
                         * Else return -1 */
                        sensor = list[index];
                        break;
                }
        }

        return sensor;
}

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
int8_t get_pin_status(uint8_t phyPin)
{
        pinMode(phyPin, INPUT);

        return digitalRead(phyPin);
}

/*
 *#####################################################################
 *  Digital Sensor - ADC
 *  -----------------------------
 *#####################################################################
 */
/**
 * Right now sensor lists are stored in arrays, this decision is not at all 
 * well thought 
 * Change it whenever possible this is done for 
 * quick implementation  
 */
static uint8_t adc[SENSORS_MAX] = {PCF8591};
/**
 * @brief      Gets the Analog to digital converted value.
 *
 * @return     int16_t digital value for analog reading on Success and
 *             -1 on Failure
 */
int16_t get_adc(uint8_t channel)
{
        /* Find Analog to digital converter connected to the Board */
        int16_t sensor = find_connected_sensors(adc);
        int16_t analog = 0;
        switch (sensor) {
                        
                case PCF8591:{
                        uint8_t pin = get_pins_from_sids (sensor, GEN_SDA);
                        uint8_t busNum = get_i2c_bus_from_pin (pin);

                        analog = pcf8591_adc_read(busNum, channel);
                        
                        break;
                }

                default:
                        /*Call error handler here */
                        analog = -1;
        }
        return analog;
}
/*
 *#####################################################################
 *  Digital Sensor - Light Intensity
 *  ---------------------------------
 *#####################################################################
 */
/**
 * Right now these are arrays, this decision is not at all 
 * well thought 
 * Change it whenever possible this is done for 
 * quick implementation  
 */
static uint8_t lightSensors[SENSORS_MAX] = {BH1750};
/**
 * @brief      Gets the Light Intensity from the supported sensors.
 *
 * @return     The Light Intensity in Lux.
 */
int16_t get_lux()
{

        /* Find Light Intensity sensor connected to the Board */
        int16_t sensor = find_connected_sensors(lightSensors);
        int16_t lux = 0;
        
        switch (sensor) {
                        
                case BH1750:;
                        uint8_t pin = get_pins_from_sids (sensor, GEN_SDA);
                        uint8_t busNum = get_i2c_bus_from_pin (pin);

                        lux = bh1750Read(busNum);
                        break;

                default:
                        lux = -1;
                        errNum = 56;
        }
        
        return lux;
} 

/*
 *#####################################################################
 *  Digital Sensor - Distance
 *  -----------------------------
 *#####################################################################
 */

/**
 * Right now these are arrays, this decision is not at all 
 * well thought 
 * Change it whenever possible this is done for 
 * quick implementation  
 */
static uint8_t distSensors[SENSORS_MAX] = {HCSR04};

/**
 * @brief      Gets the distance from supported sensors.
 *
 * @param[in]  sensor      Sensor Unique number 
 * @param[in]  echoPin     The echo pin
 * @param[in]  triggerPin  The trigger pin
 *
 * @return     The distance in cm.
 */
int16_t get_cm()
{
        int16_t sensor = find_connected_sensors(distSensors);
        int16_t distance = 0;
        
        switch (sensor) {
                        
                case HCSR04:;
                        uint8_t echoPin, triggerPin;
                        echoPin = get_pins_from_sids(HCSR04, HCSR04_ECHO_PIN);
                        triggerPin = get_pins_from_sids(HCSR04, HCSR04_TRIG_PIN);
                        distance = ultrasonic_dist_read(echoPin, triggerPin);
                        break;

                default:
                        distance = -1;
                        errNum = 56;
        }

        return distance;
}


/*
 *#####################################################################
 *  Digital Sensor - Heart Rate
 *  -----------------------------
 *#####################################################################
 */
/**
 * Right now these are arrays, this decision is not at all 
 * well thought 
 * Change it whenever possible this is done for 
 * quick implementation  
 */
static uint8_t heartRateSensors[SENSORS_MAX] = {SEN11574};

/**
 * @brief      Gets the Heart rate from supported sensors.
 *
 * @return     The Heart rate in bpm.
 */
int16_t get_bpm()
{
        int16_t sensor = find_connected_sensors(heartRateSensors);
        int16_t rate = 0;
        
        switch (sensor) {
                        
                case SEN11574:;
                        uint8_t phyPin = get_pins_from_sids(SEN11574, 1);
                        rate = sen11574_read(phyPin);
                        break;

                default:
                        rate = -1;
                        errNum = 56;
        }

        return rate;
}

/*
 *#####################################################################
 *  Digital Sensor - Liquid Flow
 *  -----------------------------
 *#####################################################################
 */
/**
 * Right now these are arrays, this decision is not at all 
 * well thought 
 * Change it whenever possible this is done for 
 * quick implementation  
 */
static uint8_t flowSensors[SENSORS_MAX] = {YFS201};
/**
 * @brief      Gets the Flow from supported sensors.
 *
 * @return     The Flow in Liters per hour.
 */
int16_t get_lph()
{
        int16_t sensor = find_connected_sensors(flowSensors);
        int16_t rate = 0;
        
        switch (sensor) {
                        
                case YFS201:;
                        uint8_t phyPin = get_pins_from_sids(YFS201, 1);
                        rate = yfs201_flow_read(phyPin);
                        break;

                default:
                        rate = -1;
                        errNum = 56;
        }

        return rate;
}

/*
 *#####################################################################
 *  Digital Sensor - Motion sensor
 *  -----------------------------
 *#####################################################################
 */
/**
 * Right now these are arrays, this decision is not at all 
 * well thought 
 * Change it whenever possible this is done for 
 * quick implementation  
 */
static uint8_t motionSensors[SENSORS_MAX] = {PIR};
/**
 * @brief      Get the status of the motion sensor
 *
 * @return     1 if motion detected else 0, -1 if error 
 */
uint8_t motion_status() 
{
        int16_t sensor = find_connected_sensors(motionSensors);
        uint8_t value = 0;
        
        switch (sensor) {
                        
                case PIR:;
                        uint8_t phyPin = get_pins_from_sids(PIR, 1);
                        value = read_pir(phyPin);
                        break;

                default:
                        value = -1;
                        errNum = 56;
        }

        return value;
}
/*
 *#####################################################################
 *  Digital Sensor - Proximity
 *  -----------------------------
 *#####################################################################
 */
/**
 * Right now these are arrays, this decision is not at all 
 * well thought 
 * Change it whenever possible this is done for 
 * quick implementation  
 */
static uint8_t proximitySensors[SENSORS_MAX] = {IR_PROXY};
/**
 * @brief      Get status from the proximity sensor
 *
 * @return     1 if motion detected else 0, -1 if error 
 */
uint8_t proxmity_status() 
{
        int16_t sensor = find_connected_sensors(proximitySensors);
        uint8_t value = 0;
                switch (sensor) {
                        
                case IR_PROXY:;
                        uint8_t phyPin = get_pins_from_sids(IR_PROXY, 1);
                        value = read_ir_proximity(phyPin);
                        break;

                default:
                        value = -1;
                        errNum = 56;
        }

        return value;
}
/*
 *#####################################################################
 *  Digital Sensor - Touch
 *  -----------------------------
 *#####################################################################
 */
/**
 * Right now these are arrays, this decision is not at all 
 * well thought 
 * Change it whenever possible this is done for 
 * quick implementation  
 */
static uint8_t touchSensors[SENSORS_MAX] = {TOUCH};

/**
 * @brief      Get status from the touch sensor
 *
 * @return     1 if motion detected else 0, -1 if error 
 */
uint8_t touch_status() 
{
        int16_t sensor = find_connected_sensors(touchSensors);
        uint8_t value = 0;
                switch (sensor) {
                        
                case TOUCH:;
                        uint8_t phyPin = get_pins_from_sids(TOUCH, 1);
                        value = read_touch(phyPin);
                        break;

                default:
                        value = -1;
                        errNum = 56;
        }

        return value;
}
/*
 *#####################################################################
 *  Digital Sensor - Light
 *  -----------------------------
 *#####################################################################
 */
/**
 * Right now these are arrays, this decision is not at all 
 * well thought 
 * Change it whenever possible this is done for 
 * quick implementation  
 */
static uint8_t lightStatSensors[SENSORS_MAX] = {LIGHT_BLOCK};

/**
 * @brief      Get status from the light blocking sensor
 *
 * @return     1 if motion detected else 0, -1 if error 
 */
uint8_t light_status() 
{
        int16_t sensor = find_connected_sensors(lightStatSensors);
        uint8_t value = 0;
                switch (sensor) {
                        
                case LIGHT_BLOCK:;
                        uint8_t phyPin = get_pins_from_sids(LIGHT_BLOCK, 1);
                        value = read_light_blocking(phyPin);
                        break;

                default:
                        value = -1;
                        errNum = 56;
        }

        return value;
}
/*
 *#####################################################################
 *  Digital Sensor - Tilt
 *  -----------------------------
 *#####################################################################
 */
/**
 * Right now these are arrays, this decision is not at all 
 * well thought 
 * Change it whenever possible this is done for 
 * quick implementation  
 */
static uint8_t tiltSensors[SENSORS_MAX] = {KY_017,KY_025,BALL_SWITCH};

/**
 * @brief      Get status from the light blocking sensor
 *
 * @return     1 if motion detected else 0, -1 if error 
 */
uint8_t tilt_status() 
{
        int16_t sensor = find_connected_sensors(tiltSensors);
        uint8_t value = 0;
        uint8_t phyPin;
                switch (sensor) {
                        
                case KY_017:;
                        phyPin = get_pins_from_sids(KY_017, 1);
                        value = read_tilt(phyPin);
                        break;
                case KY_025:;
                        phyPin = get_pins_from_sids(KY_025, 1);
                        value = read_reed(phyPin);
                        break;
                case BALL_SWITCH:;
                        phyPin = get_pins_from_sids(BALL_SWITCH, 1);
                        value = read_ball_switch(phyPin);
                        break;
                default:
                        value = -1;
                        errNum = 56;
        }

        return value;
}