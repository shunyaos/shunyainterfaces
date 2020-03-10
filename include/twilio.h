/** 
 * @file twilio.h
 * @brief Header file containing functions prototypes for 
 *        sending sms & whatsapp msg from IoT Device via Twilio.
 *  
 */


/*! Include Guard */
#ifndef __TWILIO_H__
#define __TWILIO_H__

/*! CPP guard */
#ifdef __cplusplus
extern "C" {
#endif

/* Default - 10K max memory for our param strings */
#define MAX_TWILIO_MESSAGE_SIZE 10000
#define MAX_PAYLOAD_SIZE 2048

/**
 * @brief Send Message via Twilio API
 * 
 * @param account_sid the Account SID from the Twilio console.
 * @param auth_token the Authorization Token from the Twilio console.
 * @param from_number the sending (Number in your Twilio account).
 * @param to_number the Receiving mobile number.
 * @param payload the msg to be sent. 
 * @return int8_t 0 on Success and -1 on Failure.
 */
extern int8_t twilio_send_message(char *account_sid,
                                  char *auth_token,
                                  char *from_number,
                                  char *to_number,
                                  char *payload);
/**
 * @brief Send Whatsapp Message via Twilio API
 * 
 * @param account_sid the Account SID from the Twilio console.
 * @param auth_token the Authorization Token from the Twilio console.
 * @param from_number the sending (Number in your Twilio account).
 * @param to_number the Receiving mobile number.
 * @param payload the msg to be sent.
 * @return int8_t 0 on Success and -1 on Failure.
 */
extern int8_t twilio_send_whatsapp_message(char *account_sid,
                                        char *auth_token,
                                        char *from_number,
                                        char *to_number,
                                        char *payload);

#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __TWILIO_H__ */  /* End of Include Guard */