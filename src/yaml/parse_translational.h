/** 
 * @file parse_translational.h
 * @brief  This file contains YAML parsing functions for the translational.yaml 
 *          file
 *
 */

/*! Include Guard */
#ifndef __PARSE_TRANS_H__
#define __PARSE_TRANS_H__


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
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <yaml.h>

/* --- Project Includes --- */

#define PIN_INACTIVE 0
#define PIN_ACTIVE 1

/* Data Structure to store the Pin connections */
struct tPin {
        /* Physical sensors representation in data structure*/
        int8_t i2c_bus_number;
        int8_t spi_bus_number;
        char uart_dev_name[10];
        int8_t pwm[2];
        uint8_t active;
};

/*
 *#####################################################################
 *  Definition block
 *  ---------------------
 *#####################################################################
 */

/**
 * @brief      Parse the translational.yaml file 
 *
 * @return     0 on SUCCESS and -1 on FAILURE
 */
int8_t parse_trans_file (struct tPin pins[], uint8_t size);

#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __PARSE_TRANS_H__ */ /* End of Include Guard */
