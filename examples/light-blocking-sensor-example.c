/**
****************************************************************************
* @file         light-blocking-sensor-example.c
* @author       Ayush Srivastava and Shunya Core Team
* @brief        A simple example to show the setting up and usage of 
*               Photo Interrupter. It can also be used to trigger a 
*               relay/switch by a simple addition of 1 output pin connected
*               to the switch/relay    
*         
@verbatim
-----------------------------------------------------------------------------
                        ## Description ## 
-----------------------------------------------------------------------------
## Introduction
This file contains an example code for interfacing Light Blocking sensor
module using Shunya Interfaces library.

## Connections
There are 3 pins to Light Blocking sensor module
1. VCC (also called 5V) - Connect it to 3.3V or 5V on the dev Board
2. GND (also called GND) - Connect it to GND on the dev Board
3. Signal - Connect it to any GPIO pin on the dev Board

Note: Note the physical pin number of the GPIO pins that you have connected to
and replace #define sensorPin 40 with  
#define sensorPin <your-GPIO-pin-number> in the code below.

NOTE: Adding any sort of delay to print the values of distance can cause
issues with output being displayed as 0.

## Compile 
1. Open terminal 
2. Run command `gcc -o light-blocking-sensor-example 
light-blocking-sensor-example.c -lshunyainterfaces`

## Run 
1. Open terminal 
2. Run command `./light-blocking-sensor-example`

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

#include <stdio.h>
#include <stdlib.h>
#include <shunyaInterfaces.h>

#define sensorPin 40

int main(){
	int val;
	shunyaInterfacesSetup();  //Setting up shunyaOS interfaces
        pinMode(sensorPin, INPUT);    //Setting pin as input
	while(1){
		val = digitalRead(sensorPin);; //Reading Pin value
		if( val == 1) 
			printf("Light path blocked");
		else
			printf("Light path restored");
	}
}
