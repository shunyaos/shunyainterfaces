/** 
 * @file influxdb.h
 * @brief Header file containing functions prototypes for 
 *        sending data from IoT Device to Influx DB.
 *  
 */

/*! Include Guard */
#ifndef __INFLUXDB_H__
#define __INFLUXDB_H__

/*! CPP guard */
#ifdef __cplusplus
extern "C" {
#endif

#define MAX_URL_PATH 1024
#define MAX_DB_NAME 512
#define MAX_PAYLOAD_SIZE 1024
#define MAX_CURL_URL_PATH 2048

/**
 * @brief Influx DB settings
 * 
 */
struct InfluxdbSettings { 
        char dbURL[MAX_URL_PATH]; /* Database URL */
        char dbName[MAX_DB_NAME]; /* Database Name */
};

/**
 * @brief Send Data to Influx DB
 * 
 * @param set the InfulxDB settings 
 * @param payload the payload to be sent to Influxdb
 * @param ... 
 * @return int8_t 0 on Success and -1 on Failure
 */
int8_t send_to_influxdb(struct InfluxdbSettings set, const char *payload);

#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __INFLUXDB_H__ */  /* End of Include Guard */