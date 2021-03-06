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


