/** @file plc_modbus.c
 *  @brief  This file contains YAML parsing functions for the translational.yaml 
 *          file
 *
 *  @author     Yogesh Hegde (yh42)
 *  @bug        No known bugs.
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
#include <stdint.h>
#include <string.h>
#include <modbus.h>

/* --- Project Includes --- */
#include "plc_modbus.h"

#define MODBUS_MAX_READ_BITS 1

#define SERIAL_BITS_PER_FRAME 8
#define SERIAL_STOP_BITS 1

#define MIN_VALID_PORT_NUM 1024

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
uint8_t plc_eth_read(char ip[], uint16_t port, uint16_t addr) 
{
        /* Declare the modbus data instance*/
        modbus_t *mb;
        uint8_t bit;
        /* Declare the variable to store the return value */
        uint8_t ret = 0;
        /* Check if the port argument is correct 
         * I have kept the port threshold to be 1024, since you need special 
         * permissions to access these ports in Linux and mostly 
         * these ports are reserved for some other programs.
         * If the argument is incorrect then assume the port to be default port.
         */
        if (port < MIN_VALID_PORT_NUM) {
                port = MODBUS_TCP_DEFAULT_PORT;
        }
        /* Create a new context for communication */
        mb = modbus_new_tcp(ip, port);

        /* Connect to device over modbus */
        ret = modbus_connect(mb);
        /* Check if the context creation succeeded */ 
        if (-1 == ret) {
                /* if connection fails then print error*/
                fprintf (stderr, "%s\n", modbus_strerror(errno));
                ret = -1;
        } else {
                /* if connected, Read the data */
                int rc = modbus_read_bits(mb, addr, MODBUS_MAX_READ_BITS, &bit);
                if (rc == -1) {
                        fprintf(stderr, "%s\n", modbus_strerror(errno));
                } else {
                        ret = bit;
                }
                /* Close the connection */                
                modbus_close(mb);        
        }
        /* Free the memory assigned to the context */
        modbus_free(mb);
        /* Return the data */
        return ret;        
}

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
int8_t plc_eth_write(char ip[], uint16_t port, uint16_t addr, uint8_t val) 
{
        /* Declare the modbus data instance*/
        modbus_t *mb;
        /* Declare the variable to store the return value */
        uint8_t ret = 0;
        /* Check if the port argument is correct 
         * I have kept the port threshold to be 1024, since you need special 
         * permissions to access these ports in Linux and mostly 
         * these ports are reserved for some other programs.
         * If the argument is incorrect then assume the port to be default port.
         */
        if (port < MIN_VALID_PORT_NUM) {
                port = MODBUS_TCP_DEFAULT_PORT;
        }
        /* Create a new context for communication */
        mb = modbus_new_tcp(ip, port);

        /* Connect to device over modbus */
        ret = modbus_connect(mb);
        /* Check if the context creation succeeded */ 
        if (-1 == ret) {
                /* if connection fails then print error*/
                fprintf (stderr, "%s\n", modbus_strerror(errno));
                ret = -1;
        } else {
                /* if connected, Write the data */
                modbus_write_bit(mb, addr, val);
                /* Close the connection */                
                modbus_close(mb);        
        }
        /* Free the memory assigned to the context */
        modbus_free(mb);
        /* Return the data */
        return ret;
}

/**
 * @brief      Read the Data from the PLC device connected via Serial
 *
 * @param      ip    IP address of the PLC device.
 * @param[in]  port  The port
 * @param[in]  addr  The register address
 *
 * @return     { description_of_the_return_value }
 */
uint8_t plc_serial_read(char dev[], uint16_t baud, uint16_t addr) 
{
        /* Declare the modbus data instance*/
        modbus_t *mb;
        uint8_t bit;
        /* Declare the variable to store the return value */
        uint8_t ret = 0;
        /* Check if the baud rate argument is correct 
         * If the argument is incorrect then assume the port to be default port.
         */
        switch (baud)
        {
                case     50:
                case     75:
                case    110:
                case    134:
                case    150:
                case    200:
                case    300:
                case    600:
                case   1200:
                case   1800:
                case   2400:
                case   4800:
                case   9600:
                case  19200:
                case  38400:
                case  57600:
                case 115200:
                case 230400: break ;
                
                default:
                        baud = 9600;
        }
        /* Create a new context for communication */
        mb = modbus_new_rtu(dev, baud, 'N', SERIAL_BITS_PER_FRAME, SERIAL_STOP_BITS);

        /* Connect to device over modbus */
        ret = modbus_connect(mb);
        /* Check if the context creation succeeded */ 
        if (-1 == ret) {
                /* if connection fails then print error*/
                fprintf (stderr, "%s\n", modbus_strerror(errno));
                ret = -1;
        } else {
                /* if connected, Read the data */
                int rc = modbus_read_bits(mb, addr, MODBUS_MAX_READ_BITS, &bit);
                if (rc == -1) {
                        fprintf(stderr, "%s\n", modbus_strerror(errno));
                } else {
                        ret = bit;
                }
                /* Close the connection */                
                modbus_close(mb);        
        }
        /* Free the memory assigned to the context */
        modbus_free(mb);
        /* Return the data */
        return ret;        
}

/**
 * @brief      Write data to PLC address connected via Serial
 *
 * @param      ip    IP address of the PLC
 * @param[in]  port  The port
 * @param[in]  addr  The address
 * @param[in]  val   The value
 *
 * @return     { description_of_the_return_value }
 */
int8_t plc_serial_write(char dev[], uint16_t baud, uint16_t addr, uint8_t val) 
{
        /* Declare the modbus data instance*/
        modbus_t *mb;
        /* Declare the variable to store the return value */
        uint8_t ret = 0;
        /* Check if the baud argument is correct 
         * If the argument is incorrect then assume the port to be default port.
         */
        switch (baud)
        {
                case     50:
                case     75:
                case    110:
                case    134:
                case    150:
                case    200:
                case    300:
                case    600:
                case   1200:
                case   1800:
                case   2400:
                case   4800:
                case   9600:
                case  19200:
                case  38400:
                case  57600:
                case 115200:
                case 230400: break ;
                
                default:
                        baud = 9600;
        }
        /* Create a new context for communication */
        mb = modbus_new_rtu(dev, baud, 'N', SERIAL_BITS_PER_FRAME, SERIAL_STOP_BITS);

        /* Connect to device over modbus */
        ret = modbus_connect(mb);
        /* Check if the context creation succeeded */ 
        if (-1 == ret) {
                /* if connection fails then print error*/
                fprintf (stderr, "%s\n", modbus_strerror(errno));
                ret = -1;
        } else {
                /* if connected, Write the data */
                modbus_write_bit(mb, addr, val);
                /* Close the connection */                
                modbus_close(mb);        
        }
        /* Free the memory assigned to the context */
        modbus_free(mb);
        /* Return the data */
        return ret;
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
