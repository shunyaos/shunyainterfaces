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
