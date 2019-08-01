/**
****************************************************************************
* @file         accelerometer-example.c
* @author       Ayush Srivastava and Shunya Core Team
* @brief        Reads an Analog Devices ADXL3xx accelerometer and 
*               communicates the acceleration to the computer.
*         
@verbatim
-----------------------------------------------------------------------------
                        ## Description ## 
-----------------------------------------------------------------------------
## Introduction
This file contains an example code for interfacing ADXL3xx accelerometer 
module using Shunya Interfaces library.

ADXL3xx accelerometer module is an analog device we need an ADC(analog to 
digital converter) to convert analog values to digital. 
In this example we have used pcf8591 ADC.

## Connections
There are 5 pins to ADXL3xx accelerometer module
1. VCC (also called 5V) - Connect it to 3.3V or 5V on the dev Board
2. GND (also called GND) - Connect it to GND on the dev Board
3. X_out - Connect it to any Analog pin on the pcf8591 module
4. Y_out - Connect it to any Analog pin on the pcf8591 module
5. Z_out - Connect it to any Analog pin on the pcf8591 module

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
2. Run command `gcc -o accelerometer-example accelerometer-example.c 
-lshunyainterfaces`

## Run 
1. Open terminal 
2. Run command `./accelerometer-example`

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
#include<stdlib.h>

#include<shunyaInterfaces.h>
#include<pcf8591.h>


void main(){
        int x,y,z;
        /*Initialize Shunya Interfaces library*/
        shunyaInterfacesSetup();
        pcf8591Setup();
        while (1)
        {
                x = pcf8591Read(A1);
                y = pcf8591Read(A2);
                z = pcf8591Read(A3);
                /* Reading converted value at pins of ADC whose addresses 
                 * are given by 0x01, 0x10, 0x11
                 */
                printf("X pin : %d\n",x); 
                delay(100);
                printf("Y pin : %d\n",y); 
                delay(100);
                printf("Z pin : %d\n",z);
                delay(1000);
        }
}
