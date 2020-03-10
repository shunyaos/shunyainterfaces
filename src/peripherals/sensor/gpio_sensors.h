/** 
 * @file        gpio_sensors.h
 * @brief       Header file provides the function prototypes for 
 *              various Sensors based on GPIO.
 *
 * @author Yogesh Hegde
 * @bug No known bugs.
 */

/*! Include Guard */
#ifndef __GPIO_SEN_H__
#define __GPIO_SEN_H__

/*! CPP guard */
#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief      Reads the touch sensor.
 *
 * @param[in]  pin   The physical pin number that the sensor is connected.
 *
 * @return     0 if the touch is not detected and 1 if the touch is detected.
 */
extern uint8_t read_touch(uint8_t pin);

/**
 * @brief      Reads the PIR sensor.
 *
 * @param[in]  pin   The physical pin number that the sensor is connected.
 *
 * @return     0 if the motion is not detected and 1 if the motion is detected.
 */
extern uint8_t read_pir(uint8_t pin);

/**
 * @brief      Reads the small sound sensor.
 *
 * @param[in]  pin   The physical pin number that the sensor is connected.
 *
 * @return     0 if the Sound is lower than threshold and 
 *             1 if the Sound is higher than threshold. 
 */
extern uint8_t read_small_sound(uint8_t pin);

/**
 * @brief      Reads the PIR sensor.
 *
 * @param[in]  pin   The physical pin number that the sensor is connected.
 *
 * @return     0 if the motion is not detected and 1 if the motion is detected.
 */
extern uint8_t read_light_blocking(uint8_t pin);


/**
 * @brief      Reads the Reed sensor.
 *
 * @param[in]  pin   The physical pin number that the sensor is connected.
 *
 * @return     0 if the Not Tilted and 1 if Tilted.
 */
extern uint8_t read_reed(uint8_t pin);

/**
 * @brief      Reads the Tilt sensor.
 *
 * @param[in]  pin   The physical pin number that the sensor is connected.
 *
 * @return     0 if the Not Tilted and 1 if Tilted.
 */
extern uint8_t read_tilt(uint8_t pin);

/**
 * @brief      Reads the IR sensor.
 *
 * @param[in]  pin   The physical pin number that the sensor is connected.
 *
 * @return     0 if the Obstacle is not detected and 1 if the Obstacle is detected.
 */
extern uint8_t read_ir_proximity(uint8_t pin);


/**
 * @brief      Reads the ball_switch sensor.
 *
 * @param[in]  pin   The physical pin number that the sensor is connected.
 *
 * @return     0 if Not Tilted and 
 *             1 if Tilted. 
 */
extern uint8_t read_ball_switch(uint8_t pin);

#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __GPIO_SEN_H__ */ /* End of Include Guard */
