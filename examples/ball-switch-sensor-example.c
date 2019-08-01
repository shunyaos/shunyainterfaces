/**
****************************************************************************
* @file         ball-switch-sensor-example.c
* @author       Saurav Pampattiwar and Shunya Core Team
* @brief        This file provides the source code for interfacing the
*               Ball Switch Sensor module KY-020.
*         
@verbatim
-----------------------------------------------------------------------------
                        ## Description ## 
-----------------------------------------------------------------------------
## Introduction
This file contains an example code for interfacing Ball Switch Sensor module 
KY-020 using Shunya Interfaces library.

## Connections
There are 3 pins to Heartbeat Sensor module SEN-11574
1. VCC (also called +) - Connect it to 3.3V on the dev Board
2. GND (also called -) - Connect it to GND on the dev Board
3. Signal (also called S) - Connect it to any GPIO pin on the dev Board

Note: Note the physical pin number of the GPIO pin that you have connected to
and replace int sensorpin = 11; with  int sensorpin = <your-GPIO-pin-number>
in the code below.

## Compile 
1. Open terminal 
2. Run command `gcc -o ball-switch ball-switch-sensor-example.c 
-lshunyainterfaces`

## Run 
1. Open terminal 
2. Run command `./ball-switch`

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

#include<stdio.h>
#include<shunyaInterfaces.h>


int sensorpin = 11 ; //define ball sensor input pin interface
int val;             //variable to store value

int main ()
{
        shunyaInterfacesSetup();
        /*define sensor pin as input */
        pinMode(sensorpin, INPUT); 
        //run infinite loop
        while(1) {

                val = digitalRead(sensorpin); //read sensor output
                /* print tilt if tilt of object is detected by sensor*/
        	if(val == HIGH){
        		printf("Sensor is tilted!!");
        	} else  {
                /*else the led is off*/
        		printf("Sensor is not tilted.");
                }
                delay(500);
        }
        return 0;
}

