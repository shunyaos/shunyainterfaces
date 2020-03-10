/** 
 * @file generic.h
 * @brief Header file provides the function prototypes for generic actuator
 *
 * @author Yogesh Hegde
 * @bug No known bugs.
 */

/*! Include Guard */
#ifndef __GENERIC_ACTUATOR_H__
#define __GENERIC_ACTUATOR_H__

/*! CPP guard */
#ifdef __cplusplus
extern "C"
{
#endif

/*
 *#####################################################################
 *  Process block
 *  -------------
 *#####################################################################
 */

/**
 * @brief      Initializes the actuator
 *
 * @param[in]  pin   The physical pin number that the led is connected.
 */
extern void generic_begin(uint8_t pin);
/**
 * @brief      Sets the actuator to on or off
 *
 * @param[in]  pin   The physical pin number that the actuator is connected.
 * @param[in]  mode  the mode of the pin ON or OFF.
 *
 */
extern void generic_set(uint8_t pin, uint8_t mode);

#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __GENERIC_ACTUATOR_H__ */ /* End of Include Guard */
