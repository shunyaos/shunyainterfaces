/** 
 * @file       sensor_ids.h
 * @brief      Header File contains list of Sensors and their IDS
 *             used throughout the library.
 *
 */

/*! Include Guard */
#ifndef __SENSOR_IDS_H__
#define __SENSOR_IDS_H__

/*! CPP guard */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Sensor Unique ID's.
 * 
 * @note Contains sensors which are in testing and sensors are in 
 *       the pipeline yet to be ported, but have been assigned ID's anyway.
 */
enum sensor_uids {
        BME280 = 1,
        BMP280,
        DHT11,
        SHT3x,
        BH1750,
        PCF8591,
        HCSR04,
        SEN11574,
        YFS201,
        PIR,
        IR_PROXY,
        TOUCH,
        LIGHT_BLOCK,
        KY_017,
        KY_025,
        BALL_SWITCH,
        WATER_DEPTH,
        ACS712,
        MPU6050
};

/**
 * @brief Connection ID's for Sensor HCSR04
 * 
 */
enum hcsr_conn_ids {
        HCSR04_ECHO_PIN = 1,
        HCSR04_TRIG_PIN
};

/**
 * @brief Connection ID's for Generic I2C Sensors
 * 
 */
enum generic_i2c_conn_ids {
        GEN_SDA = 1,
        GEN_SCL
};

/**
 * @brief Connection ID's for Generic SPI Sensors
 * 
 */
enum generic_spi_conn_ids {
        GEN_MOSI = 1,
        GEN_MISO,
        GEN_SCK,
        GEN_CS
};

/**
 * @brief Connection ID's Generic UART Sensors
 * 
 */
enum generic_uart_conn_ids {
        GEN_TX = 1,
        GEN_RX
};

#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* __SENSOR_IDS_H__ */  /* End of Include Guard */
