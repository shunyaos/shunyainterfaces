/** 
 * @file        influxdb.c
 * @brief       This file contains code for sending data to InfluxDB
 *              using libcurl.
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
#include "influxdb.h"

/*
 *#####################################################################
 *  Process block
 *  -------------
 *#####################################################################
 */

/**
 * @brief Send Data to Influx DB
 * 
 */
int8_t send_to_influxdb(struct InfluxdbSettings set, const char *payload)
{
        int8_t rc = -1;

	CURL *curl;
	CURLcode res;

        char influxdb_url[MAX_CURL_URL_PATH];
        
        snprintf(influxdb_url,
                 sizeof(influxdb_url),
                 "%s%s%s",
                 set.dbURL,
                 "/write?db=",
                 set.dbName);
	
	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, influxdb_url);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload);
		res = curl_easy_perform(curl);

		if(res != CURLE_OK) {
                        fprintf(stderr, "curl_easy_perform failed: %s\n", curl_easy_strerror(res));
                }
                curl_easy_cleanup(curl);
                rc = 0;
	}
	curl_global_cleanup();
	return rc;
}
