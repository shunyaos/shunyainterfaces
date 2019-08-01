/**
****************************************************************************
* @file         soil-moisture-sensor-example.c
* @author       Tanmay Desai and Shunya Core Team
* @brief        This file provides the source code for interfacing Capacitive 
*               soil moisture sensor module.
*         
@verbatim
-----------------------------------------------------------------------------
                        ## Description ## 
-----------------------------------------------------------------------------
## Introduction
This file contains an example code for interfacing Capacitive soil moisture 
sensor module using Shunya Interfaces library.

Capacitive soil moisture sensor module is an analog device we need an 
ADC(analog to digital converter) to convert analog values to digital. 
In this example we have used pcf8591 ADC.

## Connections
There are 3 pins to Capacitive soil moisture sensor module
1. VCC (also called 5V) - Connect it to 3.3V or 5V on the dev Board
2. GND (also called GND) - Connect it to GND on the dev Board
3. Signal - Connect it to any Analog pin on the pcf8591 module

Note: Note the Analog pin number of the pcf8591 module that you have 
connected to, These will be used as arguments for pcf8591Read() function 
in the code below.

There are 4 pins on the pcf8591 which need to be connected to the dev board.
1. VCC (also called 5V) - Connect it to 3.3V or 5V on the dev Board
2. GND (also called GND) - Connect it to GND on the dev Board
3. SDA - Connect it to SDA pin on dev Board
4. SCL - Connect it to SCL pin on dev Board

## Compile 
1. Open terminal 
2. Run command `gcc -o soil-moisture soil-moisture-sensor-example.c 
-lshunyainterfaces`

## Run 
1. Open terminal 
2. Run command `./soil-moisture`

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

#define <stdlib.h>
#define <stdio.h>

#define <shunyaInterfaces.h>
#define <Wire.h>
#define <pcf8591.h>

int main(void)
{
        int value;
        /*Initialize Shunya Interfaces library*/
        shunyaInterfacesSetup();
        /*Initialize pcf8591 library*/
        pcf8591Setup();
        while(1)
        {
                /*Read analog value at pin A2 on pcf8591 module*/
                value = pcf8591Read(A2);
                printf("Soil Moisture: %d ",value);
        }
        return 0;
}
	
