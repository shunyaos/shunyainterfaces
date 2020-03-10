/** @file HC-SR04.h
 *  @brief Header file provides the function prototypes for 
 *               Ultrasonic Sensor module HC-SR04 library.
 *
 *  @author Ayush Shrivastava
 *  @author Yogesh Hegde
 *  @bug No known bugs.
 */

/*! Include Guard */
#ifndef __HC_SR04_H__
#define __HC_SR04_H__

/*! CPP guard */
#ifdef __cplusplus
extern "C"
{
#endif

/* Initialization */
/**
 *  @brief      Setup Ultrasonic Sensor on given pins 
 *  @param      echoPin GPIO pin number connected to the echo pin
 *  @param      triggerPin GPIO pin number connected to the trigger pin
 *  @return     None
 */
void hcsr04Begin(int echoPin, int triggerPin);

/* Reading Raw data */
/**
 *  @brief      Get distance from ultrasonic Sensor
 *  @param      echoPin GPIO pin number connected to the echo pin
 *  @param      triggerPin GPIO pin number connected to the trigger pin
 *  @return     Return distance value on SUCCESS, -1 on FAILURE  
 */
int16_t hcsr04getDistance(int echoPin, int triggerPin);

/**
 * @brief Wrapper for reading distance from Ultrasonic sensor 
 *
 * @param echoPin GPIO pin connected to Echo 
 * @param triggerPin GPIO pin connected to Trigger
 *
 * @return Proximity Distance in cm from the sensor  
 */
int16_t ultrasonic_dist_read(int echoPin, int triggerPin);

#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __HC_SR04_H__ */ /* End of Include Guard */
