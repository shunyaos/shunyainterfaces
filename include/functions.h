/** 
 * @file       functions.h
 * @brief      Header File contains prototypes for Functions Layer
 *             to be exported to the user.
 * 
 */

/*! Include Guard */
#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

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

#include "adv_functions.h"
#include "simple_functions.h"

/*
 *#####################################################################
 *  Definition block
 *  ---------------------
 *#####################################################################
 */

/**
 * @brief      Initializes the Shunya Interfaces library.
 */
extern void initLib (void);

/*
 *#####################################################################
 *  Generic Digital Actuator
 *  ------------------------
 *#####################################################################
 */
/**
 * @brief Set any generic GPIO pin.
 *
 */
extern void setPin(uint8_t phyPin, uint8_t mode);
/*
 *#####################################################################
 *  LED
 *  ------------------------
 *#####################################################################
 */
/**
 * @brief Set any generic LED pin.
 *
 */
extern void setLed(uint8_t phyPin, uint8_t mode);
/*
 *#####################################################################
 *  RELAY
 *  ------------------------
 *#####################################################################
 */
/**
 * @brief Set any generic Relay pin.
 *
 */
extern void setRelay(uint8_t phyPin, uint8_t mode);

/*
 *#####################################################################
 *  Dashboard API's
 *  ------------------------
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
extern int8_t writeDbInflux (struct InfluxdbSettings set, const char *fmt, ...);


/*
 *#####################################################################
 *  Alert API's
 *  ------------------------
 *#####################################################################
 */

/**
 * @brief Send Message via Twilio API
 * 
 * @param account_sid the Account SID from the Twilio console.
 * @param auth_token the Authorization Token from the Twilio console.
 * @param from_number the sending (Number in your Twilio account).
 * @param to_number the Receiving mobile number.
 * @param msg the msg to be sent. 
 * @return int8_t 0 on Success and -1 on Failure.
 */
extern int8_t sendSmsTwilio(char *account_sid,
                                  char *auth_token,
                                  char *from_number,
                                  char *to_number,
                                  char *msg, ...);
/**
 * @brief Send Whatsapp Message via Twilio API
 * 
 * @param account_sid the Account SID from the Twilio console.
 * @param auth_token the Authorization Token from the Twilio console.
 * @param from_number the sending (Number in your Twilio account).
 * @param to_number the Receiving mobile number.
 * @param msg the msg to be sent.
 * @return int8_t 0 on Success and -1 on Failure.
 */
extern int8_t sendWhatsappTwilio(char *account_sid,
                                        char *auth_token,
                                        char *from_number,
                                        char *to_number,
                                        char *msg, ...);


#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __FUNCTIONS_H__ */  /* End of Include Guard */
