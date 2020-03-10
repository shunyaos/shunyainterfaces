/** 
 * @file        twilio.c
 * @brief       This file contains code to send SMS and Whatsapp messages
 *              using libcurl and Twilio.
 *
 */

/*
 *#####################################################################
 *  Initialization block
 *  ---------------------
 *#####################################################################
 */

/* --- Standard Includes --- */
#include <stdarg.h>
#include <string.h>
#include <curl/curl.h>

/* --- Project Includes --- */
#include "twilio.h"

/*
 *#####################################################################
 *  Process block
 *  -------------
 *#####################################################################
 */

/**
 * @brief       null_write is a portable way to ignore the response from 
 *              curl_easy_perform
 */
static size_t null_write(char *ptr, size_t size, size_t nmemb, void *userdata)
{
        return size * nmemb;
}

/**
 * @brief Send Message via Twilio API
 * 
 */
int8_t twilio_send_message(char *account_sid,
                           char *auth_token,
                           char *from_number,
                           char *to_number,
                           char *payload)
{

        // See: https://www.twilio.com/docs/api/rest/sending-messages for
        // information on Twilio body size limits.
        if (strlen(payload) > 1600) {
                fprintf(stderr, "SMS send failed.\n"
                                "Message body must be less than 1601 characters.\n"
                                "The message had %zu characters.\n",
                        strlen(payload));
                return -1;
        }

        CURL *curl;
        CURLcode res;
        curl_global_init(CURL_GLOBAL_ALL);
        curl = curl_easy_init();

        char url[MAX_TWILIO_MESSAGE_SIZE];
        snprintf(url,
                 sizeof(url),
                 "%s%s%s",
                 "https://api.twilio.com/2010-04-01/Accounts/",
                 account_sid,
                 "/Messages");

        char parameters[MAX_TWILIO_MESSAGE_SIZE];
        snprintf(parameters,
                 sizeof(parameters),
                 "%s%s%s%s%s%s",
                 "To=",
                 to_number,
                 "&From=",
                 from_number,
                 "&Body=",
                 payload);

        curl_easy_setopt(curl, CURLOPT_POST, 1);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, parameters);
        curl_easy_setopt(curl, CURLOPT_USERNAME, account_sid);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, auth_token);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, null_write);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        long http_code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

        if (res != CURLE_OK) {
                fprintf(stderr,"SMS send failed: %s.\n",
                                curl_easy_strerror(res));
                return -1;
        }
        else if (http_code != 200 && http_code != 201) {
                       fprintf(stderr,
                                "SMS send failed, HTTP Status Code: %ld.\n",
                                http_code);
                return -1;
        }
        else {
                return 0;
        }
}

/**
 * @brief Send Whatsapp Message via Twilio API
 * 
 */
int8_t twilio_send_whatsapp_message(char *account_sid,
                                char *auth_token,
                                char *from_number,
                                char *to_number,
                                char *payload)
{
        // See: https://www.twilio.com/docs/api/rest/sending-messages for
        // information on Twilio body size limits.
        if (strlen(payload) > 1600) {
                fprintf(stderr, "SMS send failed.\n"
                                "Message body must be less than 1601 characters.\n"
                                "The message had %zu characters.\n",
                        strlen(payload));
                return -1;
        }

        CURL *curl;
        CURLcode res;
        curl_global_init(CURL_GLOBAL_ALL);
        curl = curl_easy_init();

        char url[MAX_TWILIO_MESSAGE_SIZE];
        snprintf(url,
                 sizeof(url),
                 "%s%s%s",
                 "https://api.twilio.com/2010-04-01/Accounts/",
                 account_sid,
                 "/Messages");

        char parameters[MAX_TWILIO_MESSAGE_SIZE];
        snprintf(parameters,
                 sizeof(parameters),
                 "%s%s%s%s%s%s",
                 "To=whatsapp:",
                 to_number,
                 "&From=whatsapp:",
                 from_number,
                 "&Body=",
                 payload);

        curl_easy_setopt(curl, CURLOPT_POST, 1);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, parameters);
        curl_easy_setopt(curl, CURLOPT_USERNAME, account_sid);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, auth_token);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, null_write);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        long http_code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

        if (res != CURLE_OK) {
                fprintf(stderr,"SMS send failed: %s.\n",
                                curl_easy_strerror(res));
                return -1;
        }
        else if (http_code != 200 && http_code != 201) {
                       fprintf(stderr,
                                "SMS send failed, HTTP Status Code: %ld.\n",
                                http_code);
                return -1;
        }
        else {
                return 0;
        }
}