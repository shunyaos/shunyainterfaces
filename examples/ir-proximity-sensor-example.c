/**
****************************************************************************
* @file         ir-proximity-sensor-example.c
* @author       Saurav Pampattiwar and Shunya Core Team
* @brief        This file provides the source code for interfacing the
*               IR Proximity Sensor module KY-032.
*         
@verbatim
-----------------------------------------------------------------------------
                        ## Description ## 
-----------------------------------------------------------------------------
## Introduction
This file contains an example code for interfacing IR Proximity Sensor module 
KY-032 using Shunya Interfaces library.

## Connections
There are 3 pins to IR Proximity Sensor module KY-032
1. VCC (also called +) - Connect it to 3.3V on the dev Board
2. GND (also called -) - Connect it to GND on the dev Board
3. Signal (also called S) - Connect it to any GPIO pin on the dev Board

Note: Note the physical pin number of the GPIO pin that you have connected to
and replace #define sensorpin 11 with  #define sensorpin <your-GPIO-pin-number>
in the code below.

## Compile 
1. Open terminal 
2. Run command `gcc -o ir-proximity ir-proximity-sensor-example.c 
-lshunyainterfaces`

## Run 
1. Open terminal 
2. Run command `./ir-proximity`

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
#include <shunyaInterfaces.h>

/*define sensor pin interface*/     
#define sensorpin 11 

int main()
{
        int val;     
        /*Initialize Shunya Interfaces library*/
        shunyaInterfacesSetup(); 
        /*Initialize physical pin connected to the Sensor*/
        pinMode (sensorpin, INPUT);
        while(1)           
        {
                /*Read the Sensor*/
                val = digitalRead(sensorpin); 
                if(val == HIGH) {
                	printf("Obstacle Detected!!");
                } else {
                        printf("No Obstacle Detected.");
                }
                delay (100);
        }

        return 0;
}

