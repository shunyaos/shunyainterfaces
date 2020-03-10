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
#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __FUNCTIONS_H__ */  /* End of Include Guard */
