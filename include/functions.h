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
 * @brief Send Data to Influx DB
 * 
 * @param set the InfulxDB settings 
 * @param fmt the payload to be sent to Influxdb
 * @param ... 
 * @return int8_t 0 on Success and -1 on Failure
 */
extern int8_t writeDbInflux (struct InfluxdbSettings set, const char *fmt, ...);

#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __FUNCTIONS_H__ */  /* End of Include Guard */
