/**
****************************************************************************
* @file         SEN-11574_example.c
* @author       Gaurav Kelkar and Shunya Core Team
* @brief        This file provides the source code for interfacing the
*               Heartbeat Sensor module SEN-11574.
*         
@verbatim
-----------------------------------------------------------------------------
                        ## Description ## 
-----------------------------------------------------------------------------
## Introduction
This file contains an example code for interfacing Heartbeat Sensor module 
SEN-11574 using Shunya Interfaces library.

## Connections
There are 3 pins to Heartbeat Sensor module SEN-11574
1. VCC (also called +) - Connect it to 3.3V on the dev Board
2. GND (also called -) - Connect it to GND on the dev Board
3. Signal (also called S) - Connect it to any GPIO pin on the dev Board

Note: Note the physical pin number of the GPIO pin that you have connected to
and replace #define heartPin 40 with  #define heartPin <your-GPIO-pin-number>
in the code below.

## Compile 
1. Open terminal 
2. Run command `gcc -o heartbeat SEN-11574_example.c -lshunyainterfaces`

## Run 
1. Open terminal 
2. Run command `./heartbeat`

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
#include "SEN-11574.h"

#define heartPin 40

int main(void) {
        int bpm;
         /*Initialize Shunya Interfaces library*/
        shunyaInterfacesSetup();
        /*Initialize physical pin connected to Heartbeat Sensor*/
        heartbeatSensorSetup(heartPin);
        while (1) {
                /*Read the Heartbeat Sensor*/
                bpm = heartbeatSensorRead(heartPin);
                if (bpm < 0) {
                        printf("Error! while reading Heart Rate\n"
                                "Heart Rate greater than 220 bpm\n");
                        exit(EXIT_FAILURE);
                }
                printf("Heart Rate in beats/minute: %d \n", bpm);
        }   
        return 0;
}