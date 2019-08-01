/**
****************************************************************************
* @file         water-level-depth-sensor-example.c
* @author       Advait Yermalkar
* @brief        This file provides the source code for interfacing water level 
*               depth sensor module.
*         
@verbatim
-----------------------------------------------------------------------------
                        ## Description ## 
-----------------------------------------------------------------------------
## Introduction
This file contains an example code for interfacing Water Level Depth Detection Sensor using Shunya Interfaces library.

Water Level Depth Detection sensor module is an analog device we need an 
ADC(analog to digital converter) to convert analog values to digital. 
In this example we have used pcf8591 ADC.

## Connections
There are 3 pins to Water level depth detection sensor module
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
2. Run command `gcc water-level-depth-sensor-example.c -o water-level-depth-sensor-example -lshunyaInterfaces`

## Run 
1. Open terminal 
2. Run command `sudo ./water-level-depth-sensor-example'


## Calibration/Setup 

1) compile and run the code
2) STEP 1 :
	- insert depth sensor into the water to a depth that you consider to
          trigger FULL (High level) indicator .
	- Note the value indicated in the stdout 
	- any value greater than this will indicate High Level
   STEP 2 :
	- repeat Step 1 to find the corresponding value for low level
          indication.
	- Note the value indicated in the stdout
	- any value greater than this will indicate Low Level

   NOTE :-any value between high and low will show a Medium level  indicator
3) replace the low and full values by your calibrated values.
4) compile and run the code with the updated values.

Your sensor is now calibrated.


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

#include <stdlib.h>
#include <stdio.h>
#include <shunyaInterfaces.h>
#include <Wire.h>
#include <pcf8591.h>

const int 	low = 79;
const int	full = 162;
int 		depthSensor = 0; 
int 		lastValue = 0;


int main(void)
{
        int value;

        /*Initialize Shunya Interfaces library*/
        shunyaInterfacesSetup();

        /*Initialize pcf8591 library*/
        pcf8591Setup();

	printf("Water Depth Sensor \n");


        while(1)
        {
                /*Read analog value at pin A1 on pcf8591 module*/
                value = pcf8591Read(A1);
                printf("\nWater Depth: %d ",value);
		if(value >= full) {		  
		  	printf("\tHIGH LEVEL \n"); 
		}
		else if((value < full) && (value >= low)) {
		   	printf("\tMEDIUM LEVEL \n");
		}
		else {
		   	printf("\tLOW LEVEL \n");		  
		}
		delay(1500); 
		
       }
        return 0;
}
	

