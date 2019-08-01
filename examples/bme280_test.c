/**
  ******************************************************************************
  * @file       bme280_test.c
  * @author     Shunya Core Team
  * @brief      This file contains Test code for BME280 sensor  
  *         
  @verbatim
 
    @endverbatim
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 IoTIoT.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by IoTIoT under GPLv3 license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/GPL-3.0
  *
  ******************************************************************************
  */ 


#include <stdio.h>
#include <stdlib.h>

#include <shunyaInterfaces.h>
#include <Wire.h>

#include <bme280.h>



int main() {

	float temperature_C, temperature_F, pressure, humidity, altitude;

	// Uncomment the below line to put it in Infinite Loop
	//while(1) {
	temperature_C = bme280Read(temp_C);
	temperature_F = bme280Read(temp_F);
	pressure = bme280Read(pressure);
	humidity = bme280Read(humidity);
	altitude = bme280Read(altitude);

	printf("Temperature = %.2f degC ",temperature_C );
	printf("Temperature = %.2f degF ",temperature_F );
	printf("Pressure = %.2f Pa ",pressure );
	printf("Humidity = %.2f %RH (Relative Humidity) ",humidity );
	printf("Altutude = %.2f meters above sea Level ",altutude );
	//}
	return 0;
}
