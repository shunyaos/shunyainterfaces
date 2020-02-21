/** 
 * @file pcf8591.c
 * @brief This file contains low level code for pcf8591 ADC
 *
 */

/*
 *#####################################################################
 *  Initialization block
 *  ---------------------
 *#####################################################################
 */

/* --- Standard Includes --- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* --- Project Includes --- */
#include <shunyaInterfaces.h>
#include "pcf8591.h"

/* Global variable to store if Sensor has already been setup */
static int isPcf8951Setuped = FALSE;

/* Global variable to store the Advance Sensor Settings */
static struct pcf8591Settings settings = {.def=1};

/*
 *#####################################################################
 *  Process block
 *  -------------
 *#####################################################################
 */

/**
 * @brief Initialize the PCF8591 sensor.
 *
 */
void pcf8591Begin(uint8_t busNum, struct pcf8591Settings set)
{
	/*Check if the sensor has been setup */
	if (!isPcf8951Setuped) {
		/* Start the I2C interface */         
                /**
                 * Currently it is zero but take the argument of wireEnd() from the user 
                 */
                wireBegin(busNum);
		/* Make the flag TRUE so that setup does not execute 
		 * twice */
                isPcf8951Setuped = TRUE;                
        }
        if (set.def ==1){

                /* Store all the settings into a variable */
                set.autoIncrement = CHANNEL0;
                set.inputMode = SINGLE_ENDED_INPUT;
                set.outputMode = DISABLE_OUTPUT;
        }
        /* Set advance sensor settings */
        ( void ) memcpy ( &settings, &set, sizeof( set ) );
 
}

/**
 * @brief Internal function to write to the PCF8591
 */
static void write_to_pcf8591 (uint8_t data)
{
        /* Start I2C communication */
        wireBeginTransmission(PCF8591_I2C_ADDRESS);
        /* Data to be sent */
        wireWrite(data);
        /* End I2C communication */
        wireEndTransmission();
}

/**
 * @brief Deinit the sensor 
 */
void pcf8591End()
{
        if (isPcf8951Setuped) {
                wireEnd();
                isPcf8951Setuped = FALSE;                
        }
}


/**
 * @brief Read data from the sensor.
 */
int16_t pcf8591Read(uint8_t channel)
{
	int16_t val = -1;

        uint8_t ctrl_reg = 0;

        ctrl_reg = settings.autoIncrement;
        ctrl_reg |= settings.inputMode;
        ctrl_reg |= settings.outputMode;

        /* Select one ADC channel to Read */
        if (channel == Ain0 ) {
                ctrl_reg |=  CHANNEL0;
        } else if (channel == Ain1) {
                ctrl_reg |=  CHANNEL1;
        } else if (channel == Ain2) {
                ctrl_reg |=  CHANNEL2;
        } else if (channel == Ain3){
                ctrl_reg |=  CHANNEL3;
        } else {
                /* Set Error Number */
                return val;
        } 
                 
        write_to_pcf8591(ctrl_reg);
        /* Request 2 bytes of data from PCF8591*/
        wireRequestFrom(PCF8591_I2C_ADDRESS, 2);
        /* Discard the 1st byte */
        (void) wireRead();
        /* 2nd Byte is useful */
        val = wireRead();

        pcf8591End();
        
        return val;   
}


/*
 *#####################################################################
 *  Passing block
 *  -------------
 *#####################################################################
 */

/**
 * @brief Simple wrapper to read from the ADC.
 */
int16_t pcf8591_adc_read (uint8_t bus, uint8_t channel)
{
        /*Check if the sensor has been setup */
        if (!isPcf8951Setuped) {
                pcf8591Begin(bus, settings);              
        }

        return pcf8591Read (channel);
}
