/** 
 * @file YF-S201.h
 * @brief Header file provides the function prototypes for 
 *               Water flow Sensor module YF-S201 library.
 *
 * @author Vaibhav Shinde
 * @bug No known bugs.
 */

/*! Include Guard */
#ifndef __YF_S201_H__
#define __YF_S201_H__

/*! CPP guard */
#ifdef __cplusplus
extern "C"
{
#endif

/**
 *  @brief      Setup Water Flow Sensor on given GPIO pin
 *  @param      Physical GPIO pin number
 *  @return     None
 */
extern void yfs201Begin(int pin);
/**
 *  @brief      Read Water Flow Sensor on given GPIO pin
 *  @param      Physical GPIO pin number
 *  @return     Return Heart rate in bpm on SUCCESS, 
 *              Return -1 on FAILURE
 */
extern int16_t yfs201getFlow();

/**
 * @brief Simple Wrappers for reading data from the sensor 
 *
 * @param pin GPIO pin connected to sensor 
 *
 * @return Water flow in liters/hour
 */
extern int16_t yfs201_flow_read(int pin);

#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __YF_S201_H__ */ /* End of Include Guard */
