/** 
 * @file pcf8591.h
 * @brief Header file containing functions prototypes for pcf8591 ADC 
 *  
 */


/*! Include Guard */
#ifndef __PCF8591_H__
#define __PCF8591_H__

/*! CPP guard */
#ifdef __cplusplus
extern "C" {
#endif

/* I2C Address for the ADC */
#define PCF8591_I2C_ADDRESS 0x48

/* All Sensor specific defintions below.
 * Definitions taken from 
 * - https://www.nxp.com/docs/en/data-sheet/PCF8591.pdf page 6
 */        
#define CHANNEL0 0b00000000
#define CHANNEL1 0b00000001
#define CHANNEL2 0b00000010
#define CHANNEL3 0b00000011

#define AUTOINCREMENT_READ_EN 0b00000100
#define AUTOINCREMENT_READ_DIS 0b00000000

/* ADC Modes */ 
#define SINGLE_ENDED_INPUT      0b00000000
#define TREE_DIFF_INPUT         0b00010000
#define TWO_SINGLE_ONE_DIFF_INPUT 0b00100000
#define TWO_DIFF_INPUT          0b00110000

#define ENABLE_OUTPUT   0b01000000
#define DISABLE_OUTPUT  0b01000000
#define OUTPUT_MASK     0b01000000

/* Channel Definitions */
#define Ain0 0
#define Ain1 1 
#define Ain2 2 
#define Ain3 3 

/**
 * @brief Stores all the sensor settings.
 * 
 */
struct pcf8591Settings {
	uint8_t def;
	uint8_t addr;
	uint8_t autoIncrement;
	uint8_t inputMode;
	uint8_t outputMode;
};

/**
 * @brief Initialize the PCF8591 sensor 
 *
 * @param set variable to the settings structure
 */
extern void pcf8591Begin(uint8_t busNum, struct pcf8591Settings set) ;

/**
 * @brief Deinit the sensor 
 */
extern void pcf8591End() ;

/**
 * @brief Read data from the sensor.
 *
 * @param channel ADC pin. 
 *
 * @return Integer value between 0 to 255. 
 */
extern int16_t pcf8591Read(uint8_t channel);   

/**
 * @brief Simple wrapper to read from the ADC.
 *
 * @param channel ADC channel to read from. 
 *
 * @return ADC value from 0 to 255.
 */
extern int16_t pcf8591_adc_read (uint8_t bus, uint8_t channel);

#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __PCF8591_H__ */  /* End of Include Guard */
