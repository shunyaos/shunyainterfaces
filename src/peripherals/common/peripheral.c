/** 
 * @file       peripheral.c
 * @brief      This file contains internal functions of the layer.
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
#include <stdio.h>
#include <stdint.h>
#include <shunyaInterfaces.h>

/* --- Project Includes --- */
#include "sensors.h"
#include "parse_config.h"
#include "parse_translational.h"

/**
 * TODO : ERROR Handling
 * 
 */

/* Board is the representation of 64 Pins */
struct cPin board_pins[MAX_PINS];
/* Board is the representation of 64 Pins */
struct tPin bpins[MAX_PINS];

/*
 *#####################################################################
 *  Process block
 *  -------------
 *  This block contains all the process code for the particular layer.
 *  It typically contains internal functions and external functions 
 *  which implement the functionalities of the respective layer.
 *#####################################################################
 */

/**
 * @brief      Initializes the function layer.
 */
static uint8_t init_driver_layer(void)
{
        /**
         * Parse the YAML file
         */
	int ret = 0;
        ret = parse_config_file(board_pins, MAX_PINS);
        if (ret < 0 ) {
		fprintf(stderr, "problem in config file \n"); 
	}
	/**
         * Parse the translational file 
         */
        parse_trans_file(bpins, MAX_PINS);
	
	libInit();
        return 0;
}

/**
 * @brief      Function which gets called when the execution 
 *             passes to sensor layer.
 */
uint8_t pass_to_sensor_layer (void)
{
        int8_t ret = -1;
        /**
         * Start a chain of Initialization 
         */
        /** For now initialize the layer */
        ret = init_driver_layer();

        if (ret < 0) {
                /**
                 * Error in Initializing the driver layer 
                 */
        }

        return ret;
}


/**
 * @brief      Checks if the sensor id exists
 *
 * @param[in]  sids  The sids
 *
 * @return     The pins from sids.
 */
uint8_t check_sid_exist (uint16_t sids) 
{
        uint8_t ret = 0;
        /**
         * Linear search for searching 
         * the board pin map 
         * 
         */
        uint8_t pindex, sindex;
        for (pindex = 0; pindex < MAX_PINS; pindex++) {
                for (sindex = 0; sindex < MAX_CONN; sindex++) {
			if (board_pins[pindex].sensor[sindex].sensor_uid == sids){
                                return pindex;
                        }       
                }
        }

        return ret;
}

/**
 * @brief      Gets the pins from sids.
 *
 * @param[in]  sids      The sids
 * @param[in]  sconn_id  The sconn identifier
 *
 * @return     The pins from sids.
 */
uint8_t get_pins_from_sids (uint16_t sids, uint8_t sconn_id) 
{
        uint8_t ret = 0;
        /**
         * Linear search for searching 
         * the board pin map 
         * 
         */
	
        uint8_t pindex, sindex;
        for (pindex = 0; pindex < MAX_PINS; pindex++) {
                for (sindex = 0; sindex < MAX_CONN; sindex++) {
			if (board_pins[pindex].sensor[sindex].sensor_uid == sids &&
                            board_pins[pindex].sensor[sindex].sensor_conid == sconn_id){
				return pindex;
                        }  
                }
        }

        return ret;
}

/**
 * @brief      Gets I2C bus from pin.
 *
 * @param[in]  pin   The pin
 *
 * @return     I2C bus from pin.
 */
int8_t get_i2c_bus_from_pin ( int8_t pin ) 
{
        int8_t ret = -1;

        if (bpins[pin].active == PIN_ACTIVE) {

                if (bpins[pin].i2c_bus_number < 0) {

                } else {
		
                        ret = bpins[pin].i2c_bus_number;   
		}
        }
 
        return ret;
}

/**
 * @brief      Gets the spi bus from pin.
 *
 * @param[in]  pin   The pin
 *
 * @return     The spi bus from pin.
 */
int8_t get_spi_bus_from_pin ( int8_t pin ) 
{
        int8_t ret = -1;
        if (bpins[pin].active == PIN_ACTIVE) {

                if (bpins[pin].spi_bus_number < 0) {

                } else {
                
                        ret = bpins[pin].spi_bus_number;   
                }  
        }
        return ret;
}
/**
 * @brief      Gets the uart bus from pin.
 *
 * @param[in]  pin   The pin
 * @param[out] bus   The bus
 *
 * @return     The uart bus from pin.
 */
int8_t get_uart_bus_from_pin ( int8_t pin, char bus[] ) 
{
        int8_t ret = -1;
        /**
         * Check if the pin is active before proceeding 
         */
        if (bpins[pin].active == PIN_ACTIVE) {
                /**
                 * Check if the PWM entry is present 
                 */
                if (bpins[pin].uart_dev_name[0] != '\0'){

                     strcpy(bus, bpins[pin].uart_dev_name);
                     ret = 0;   
                }  
        }
        return ret;
}
/**
 * @brief      Gets the PWM bus from pin.
 *
 * @param[in]  pin   The pin
 * @param[out] bus   The bus
 *
 * @return     The PWM bus from pin.
 */
int8_t get_pwm_bus_from_pin ( int8_t pin, int8_t bus[] ) 
{
        int8_t ret = -1;
        /**
         * Check if the pin is active before proceeding 
         */
        if (bpins[pin].active == PIN_ACTIVE) {
                /**
                 * Check if the PWM entry is present 
                 */

                if (bpins[pin].pwm[0] >= 0 && bpins[pin].pwm[1] >= 0){

                     bus[0] = bpins[pin].pwm[0];
                     bus[1] = bpins[pin].pwm[1];

                     ret = 0;   
                }  
        }
        return ret;
}
