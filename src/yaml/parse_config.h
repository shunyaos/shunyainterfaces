/** 
 * @file   parse_config.h
 * @brief  Header file contains YAML parsing functions prototypes for config
 *
 */

/*! Include Guard */
#ifndef __PARSE_CONF_H__
#define __PARSE_CONF_H__


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

/* --- Project Includes --- */

/**
 * TODO : Error HANDLING
 */


/* Data structure to store the Sensor Properties */
struct cSensor {
        /* Sensor Unique ID's*/
        int16_t sensor_uid;
        /* Sensor Connection ID's*/
        int8_t sensor_conid;
};

/* Data Structure to store the Pin connections */
struct cPin {
        /* Physical sensors representation in data structure*/
        struct cSensor sensor[5];
};



/*
 *#####################################################################
 *  Definition block
 *  ---------------------
 *#####################################################################
 */

/**
 * @brief      Parse the Config.yaml file 
 *
 * @return     0 on SUCCESS and -1 on FAILURE
 */
extern int8_t parse_config_file (struct cPin *pins, uint8_t size);

#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __PARSE_CONF_H__ */ /* End of Include Guard */
