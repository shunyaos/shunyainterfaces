/** 
 * @file        functions.c
 * @brief       This file contains internal methods for Shunya Functions layer
 *
 */

/*
 *#####################################################################
 *  Initialization block
 *  ---------------------
 *#####################################################################
 */

/* --- Standard Includes --- */
#include <stdint.h>
/* --- Project Includes --- */
#include "peripheral.h"
/*
 *#####################################################################
 *  Process block
 *  -------------
 *#####################################################################
 */

/**
 * @brief Initializes the function layer.
 */
static uint8_t init_func_layer(void)
{
        /**
         * Nothing to initialize in this layer 
         * Call the Sensor Layer Initialize function
         */
        pass_to_sensor_layer();

        return 0;
}

/*
 *#####################################################################
 *  Passing block
 *  -------------
 *#####################################################################
 */

/**
 * @brief      Initializes the library.
 */
void initLib (void)
{
        /**
         * Start a chain of Initialization 
         */
        /** For now initialize the layer */
        init_func_layer();
}
