/**
****************************************************************************
* @file         KY-036_example.c
* @author       Tanmay Desai and Shunya Core Team
* @brief        This file provides the source code for interfacing the Metal
*               Touch sensor module KY-036.
*         
@verbatim
-----------------------------------------------------------------------------
                        ## Description ## 
-----------------------------------------------------------------------------
## Introduction
This file contains an example code for interfacing Metal Touch sensor module  
KY-036 using Shunya Interfaces library.

## Connections
There are 3 pins to Metal Touch sensor module KY-036
1. VCC (also called +) - Connect it to 3.3V or 5V on the dev Board
2. GND (also called -) - Connect it to GND on the dev Board
3. Signal (also called S) - Connect it to any GPIO pin on the dev Board

Note: Note the physical pin number of the GPIO pin that you have connected to
and replace #define touchPin 11 with  #define touchPin <your-GPIO-pin-number>
in the code below.

## Compile 
1. Open terminal 
2. Run command `gcc -o KY-036_example KY-36_example.c -lshunyainterfaces`

## Run 
1. Open terminal 
2. Run command `./KY-036_example`

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

#define touchPin 11

int main (void)
{
        int touchState;
         /*Initialize Shunya Interfaces library*/
        shunyaInterfacesSetup();
         /*Initialize physical pin connected to tilt sensor as INPUT*/
        pinMode (touchPin, INPUT) ; 

        while(1)
        {
                /*Read the state of the tilt sensor*/
                touchState = digitalRead (touchPin) ; 
                /* When the metal touch sensor detects a signal print message*/
                if (touchState == HIGH) {
                        printf("Touch Detected!!\n");
                }
        }
        return 0;
}
