/** 
 * @file bh1750.h
 * @brief Header file provides the function prototypes for 
 *               BH1750 library.
 *
 * @author Yogesh Hegde
 * @bug No known bugs.
 */

/*! Include Guard */
#ifndef __BH1750_H__
#define __BH1750_H__

/*! CPP guard */
#ifdef __cplusplus
extern "C"
{
#endif

#define BH1750_I2C_ADDR 0x23
#define BH1750_CONTINIOUS_MODE 0x10

/**
 * @brief Initialize the Sensor 
 */
extern void bh1750Begin(uint8_t busNum);

/**
 * @brief Deinit the Sensor 
 */
extern void bh1750End();

/**
 * @brief Read the lux data from the sensor 
 *
 * @return value of Lux in 
 */
extern int16_t bh1750Read(uint8_t busNum);

#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __BH1750_H__ */ /* End of Include Guard */
