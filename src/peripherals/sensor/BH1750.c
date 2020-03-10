/** @file       BH1750.c
 *  @brief      This file provides the functions for library
 *               BH1750.
 * 
 *  @author Yogesh Hegde
 *  @bug No known bugs.
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
#include <stdio.h>
#include <stdlib.h>

/* --- Project Includes --- */
#include "shunyaInterfaces.h"
#include "BH1750.h"

/**
 * @brief Flag to check if the setup is done 
 */
static int isbh1750Setuped = FALSE;

/*
 *#####################################################################
 *  Initialization block
 *  ---------------------
 *  This block contains initialization code for this particular file.
 *  It typically contains Includes, constants or global variables used
 *  throughout the file.
 *#####################################################################
 */

/**
 * @brief Internal function used to write to the BH1750 device 
 *
 * @param data Data to be sent to the device 
 */
static void write_to_bh1750 (uint8_t data)
{
        /* Start I2C communication */
        wireBeginTransmission(BH1750_I2C_ADDR);
        /* Data to be sent */
        wireWrite(data);
        /* End I2C communication */
        wireEndTransmission();
}

/**
 * @brief Initialize the Sensor 
 */
void bh1750Begin(uint8_t busNum)
{
        if (!isbh1750Setuped) {
                wireBegin(busNum);
                isbh1750Setuped = TRUE;

                /* Set Sensor to output data in continuous High-resolution mode */
                write_to_bh1750(BH1750_CONTINIOUS_MODE);
                /* Delay of 1 secs */
                delay(1000);                
        }
 
}

/**
 * @brief Deinit the Sensor 
 */
void bh1750End()
{
        if (!isbh1750Setuped) {
                wireEnd();
                isbh1750Setuped = FALSE;                
        }
 
}



/**
 * @brief Read the lux data from the sensor 
 *
 * @return value of Lux in 
 */
int16_t bh1750_read (uint8_t busNum)
{

        int rawData = 0, lux;

        /* Initializes the I2C device */
        bh1750Begin(busNum);    
        
        /* Read 16-bit value from the device register */
        if (2 == wireRequestFrom(BH1750_I2C_ADDR, 2)) {
                unsigned int tmp = 0;
                tmp = wireRead();
                tmp <<= 8;
                tmp |= wireRead();
                rawData = tmp;
        }
        bh1750End();
        /* Normally the average conversion factor is 1.2 for 
         * Raw data read to lux value 
         * For more info on this read Datasheet (page 2, Measurement Accuracy)
         * Link - https://www.mouser.com/datasheet/2/348/bh1750fvi-e-186247.pdf
         */
        lux = (1.2*rawData); 

        return lux;
}

/*
 *#####################################################################
 *  Passing block
 *  -------------
 *  This block contains functions which pass the data to the next layer.
 *
 *  Note : This block is not implemented yet.
 *  Reason : Since the code for passing the data is very trivial and
 *           Creating another function just to pass the data will make 
 *           a copy of the data increasing program's memory consumption.
 *#####################################################################
 */
