/** 
 * @file        peripheral.h
 * @brief       Header file contains function prototype to functions 
 *              common to the layer.
 *
 */

/*! Include Guard */
#ifndef __PERIPHERAL_H__
#define __PERIPHERAL_H__


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
#include <stdint.h>
/* --- Project Includes --- */

#define MAX_PINS 64
#define MAX_CONN 5

/**
* @brief      Gets the pins from sids.
*
* @param[in]  sids      The sensor identifier 
* @param[in]  sconn_id  The sensor connection identifier
*
* @return     The pins from sids.
*/
extern uint8_t get_pins_from_sids (uint16_t sids, uint8_t sconn_id);

 /**
 * @brief      Gets I2C bus from pin.
 *
 * @param[in]  pin   The pin
 *
 * @return     I2C bus from pin.
 */
extern int8_t get_i2c_bus_from_pin ( int8_t pin );

/**
 * @brief      Gets the spi bus from pin.
 *
 * @param[in]  pin   The pin
 *
 * @return     The spi bus from pin.
 */
extern int8_t get_spi_bus_from_pin ( int8_t pin );
/**
 * @brief      Gets the uart bus from pin.
 *
 * @param[in]  pin   The pin
 * @param[out] bus   The bus
 *
 * @return     The uart bus from pin.
 */
extern int8_t get_uart_bus_from_pin ( int8_t pin, char bus[] );
/**
 * @brief      Gets the PWM bus from pin.
 *
 * @param[in]  pin   The pin
 * @param[out] bus   The bus
 *
 * @return     The PWM bus from pin.
 */
extern int8_t get_pwm_bus_from_pin ( int8_t pin, int8_t bus[] );

/**
 * @brief      Checks if the sensor id exists
 *
 * @param[in]  sids  The sids
 *
 * @return     The pins from sids.
 */
extern uint8_t check_sid_exist (uint16_t sids);

/**
 * @brief      Initializes the library.
 *
 * @return     { description_of_the_return_value }
 */
extern uint8_t pass_to_sensor_layer (void);

#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __PERIPHERAL_H__ */ /* End of Include Guard */