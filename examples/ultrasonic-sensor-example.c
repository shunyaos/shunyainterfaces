/**
****************************************************************************
* @file         ultrasonic-sensor-example.c
* @author       Ayush Srivastava and Shunya Core Team
* @brief        This file provides the source code for interfacing the *               Ultrasonic sensor module HC-SR04.
*         
@verbatim
-----------------------------------------------------------------------------
                        ## Description ## 
-----------------------------------------------------------------------------
## Introduction
This file contains an example code for interfacing Ultrasonic sensor module 
HC-SR04 using Shunya Interfaces library.

## Connections
There are 4 pins to Ultrasonic sensor module HC-SR04
1. VCC (also called 5V) - Connect it to 3.3V or 5V on the dev Board
2. GND (also called GND) - Connect it to GND on the dev Board
3. Trigger - Connect it to any GPIO pin on the dev Board
4. Echo - Connect it to any GPIO pin on the dev Board

Note: Note the physical pin number of the GPIO pins that you have connected to
and replace #define triggerPin 40 with  
#define triggerPin <your-GPIO-pin-number> and 
#define echoPin 38 with #define echoPin <your-GPIO-pin-number> in the 
code below.

NOTE: Adding any sort of delay to print the values of distance can cause
issues with output being displayed as 0.

## Compile 
1. Open terminal 
2. Run command `gcc -o ultrasonic-sensor-example ultrasonic-sensor-example.c
 -lshunyainterfaces`

## Run 
1. Open terminal 
2. Run command `./ultrasonic-sensor-example`

@endverbatim
******************************************************************************
* @attention
*
* <h2><center>&copy; Copyright (c) 2019 IoTIoT.in
* All rights reserved.</center></h2>
*
* This software component is licensed by IoTIoT under GPLv3 license,
* the "License"; You may not use this file except in compliance with the
* License. You may obtain a copy of the License at:
*                        opensource.org/licenses/GPL-3.0
*
******************************************************************************
*/

#define triggerPin 40
#define echoPin 38

#include "hc-sr04.h"
int main(){
        int distance;
        /*Initialize Shunya Interfaces library*/
	shunyaInterfacesSetup();
        /*Initialize Ultrasonic sensor*/
	ultrasonicSetup(echoPin,triggerPin);

	while(1){
                /*Get Distance from Ultrasonic sensor*/
		distance = measureDistance(echoPin, triggerPin);
		printf("Distance is %d cm \n",distance);
	}
}

