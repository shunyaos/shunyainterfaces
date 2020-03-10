/** @file plc_modbus.h
 *  @brief  File contains the list of function prototypes exported to
 *          for PLC communication over modbus protocol. 
 *
 *  @author     Yogesh Hegde (yh42)
 *  @bug        No known bugs.
 */

/*! Include Guard */
#ifndef __PLC_MODBUS_H__
#define __PLC_MODBUS_H__


/*! CPP guard */
#ifdef __cplusplus
extern "C" {
#endif


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
#include <stdint.h>

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
 * @brief      Read the Data from the PLC device connected via Ethernet
 *
 * @param      ip    IP address of the PLC device.
 * @param[in]  port  The port
 * @param[in]  addr  The register address
 *
 * @return     { description_of_the_return_value }
 */
extern uint8_t plc_eth_read(char ip[], uint16_t port, uint16_t addr);

/**
 * @brief      Write data to PLC address connected via Ethernet
 *
 * @param      ip    IP address of the PLC
 * @param[in]  port  The port
 * @param[in]  addr  The address
 * @param[in]  val   The value
 *
 * @return     { description_of_the_return_value }
 */
extern int8_t plc_eth_write(char ip[], uint16_t port, uint16_t addr, uint8_t val);

/**
 * @brief Write data to PLC address connected via Serial
 * 
 * @param dev Device getting connected
 * @param baud the baud rate of the serial communication
 * @param addr the PLC address
 * @param val the value to be written
 * @return int8_t 0 on Success and -1 on Failure
 */

extern int8_t plc_serial_write(char dev[], uint16_t baud, uint16_t addr, uint8_t val);

/**
 * @brief Read data from PLC address connected via Serial
 * 
 * @param dev Device getting connected
 * @param baud the baud rate of the serial communication
 * @param addr the PLC address
 * @return uint8_t the value at the address
 */
extern uint8_t plc_serial_read(char dev[], uint16_t baud, uint16_t addr);

#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __PLC_MODBUS_H__ */ /* End of Include Guard */
