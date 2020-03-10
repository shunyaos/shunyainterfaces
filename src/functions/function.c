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
#include <stdarg.h>
/* --- Project Includes --- */
#include "peripheral.h"
#include "influxdb.h"
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

/*
 *#####################################################################
 *  Dashboard API
 *  -------------
 *#####################################################################
 */

/**
 * @brief Send Data to Influx DB
 * 
 * @param set the InfulxDB settings 
 * @param fmt the payload to be sent to Influxdb
 * @param ... 
 * @return int8_t 0 on Success and -1 on Failure
 */
int8_t writeDbInflux (struct InfluxdbSettings set, const char *fmt, ...) 
{

        va_list ap;
        char payload [MAX_PAYLOAD_SIZE] ;
        va_start(ap, fmt);
        vsnprintf(payload, sizeof(payload), fmt, ap);
        va_end(ap);

        return send_to_influxdb(set, payload);
}
/*
 *#####################################################################
 *  Twilio API
 *  -------------
 *#####################################################################
 */

/**
 * @brief Send Message via Twilio API
 * 
 */
int8_t sendSmsTwilio (char *account_sid,
                           char *auth_token,
                           char *from_number,
                           char *to_number,
                           char *msg, ...)
{
        va_list ap;
        char payload[MAX_PAYLOAD_SIZE];

        va_start(ap, msg);
        vsnprintf(payload, sizeof(payload), msg, ap);
        va_end(ap);

        return twilio_send_message(account_sid, auth_token, from_number,
                                to_number,payload);
}

/**
 * @brief Send Whatsapp Message via Twilio API
 * 
 */
int8_t sendWhatsappTwilio(char *account_sid,
                                char *auth_token,
                                char *from_number,
                                char *to_number,
                                char *msg, ...)
{
        va_list ap;
        char payload[MAX_PAYLOAD_SIZE];

        va_start(ap, msg);
        vsnprintf(payload, sizeof(payload), msg, ap);
        va_end(ap);

        return twilio_send_message(account_sid, auth_token, from_number,
                                to_number,payload);
}

/*
 *#####################################################################
 *  Modbus API's
 *  -------------
 *#####################################################################
 */

/**
 * @brief      Read the Data from the PLC device connected via Ethernet
 *
 * @param      ip    IP address of the PLC device.
 * @param[in]  port  The port
 * @param[in]  addr  The register address
 *
 * @return     uint8_t the value at the PLC address 
 */

uint8_t modbusTCPRead (char ip[], uint16_t port, uint16_t addr) 
{
        return plc_eth_read(ip, port, addr);
}

/**
 * @brief      Write data to PLC address connected via Ethernet
 *
 * @param      ip    IP address of the PLC
 * @param[in]  port  The port
 * @param[in]  addr  The address
 * @param[in]  val   The value
 *
 * @return    int8_t 0 on Success and -1 on Failure
 */

int8_t modbusTCPWrite (char ip[], uint16_t port, uint16_t addr, uint8_t val) 
{
        return plc_eth_write(ip, port, addr, val);
}

/**
 * @brief Read data from PLC address connected via Serial
 * 
 * @param dev Device getting connected
 * @param baud the baud rate of the serial communication
 * @param addr the PLC address
 * @return uint8_t the value at the address
 */
uint8_t modbusRTURead (char dev[], uint16_t baud, uint16_t addr) 
{
        return plc_serial_read(dev, baud, addr, val);
}

/**
 * @brief Write data to PLC address connected via Serial
 * 
 * @param dev Device getting connected
 * @param baud the baud rate of the serial communication
 * @param addr the PLC address
 * @param val the value to be written
 * @return int8_t 0 on Success and -1 on Failure
 */

int8_t modbusRTUWrite (char dev[], uint16_t baud, uint16_t addr, uint8_t val) 
{
        return plc_serial_write(dev, baud, addr, val);
}
