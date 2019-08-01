/**
****************************************************************************
* @file         water-flow-sensor-example.c
* @author       Vaibhav Shinde and Shunya Core Team
* @brief        This file provides the source code for interfacing the
*               Water Flow Sensor module YF-S102.
*         
@verbatim
-----------------------------------------------------------------------------
                        ## Description ## 
-----------------------------------------------------------------------------
## Introduction
This file contains an example code for interfacing Water Flow Sensor module 
YF-S102 using Shunya Interfaces library.

## Connections
There are 3 pins to Water Flow Sensor module YF-S102
1. VCC (also called +) - Connect it to 5V on the dev Board as the sensor works with atleast 4.5V input upto 18V.
2. GND (also called -) - Connect it to GND on the dev Board
3. Signal (also called S) - Connect it to any GPIO pin on the dev Board that supports PWM input

Note: Note the physical pin number of the GPIO pin that you have connected to
and replace #define PIN 33 with  #define PIN <your-GPIO-pin-number>
in the code below.

## Compile 
1. Open terminal 
2. Run command `gcc -o waterflow water-flow-sensor-example.c
 -lshunyainterfaces`

## Run 
1. Open terminal 
2. Run command `./waterflow`

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
#include "YF-S201.h"

#define PIN 33

// Select the GPIO pin that supports PWM input. Pins 32 & 33 on Tinkerboard.

int main(void) {

    int flow;

    /*Initialize Shunya Interfaces library*/
    shunyaInterfacesSetup();

    /*Initialize physical pin connected to Water Flow Sensor*/
    waterFlowSensorSetup(PIN);

    while (1) {

        // Read the Water Flow Sensor for every 2 seconds
        flow = waterFlowSensorRead();

        if (flow == -1) {
            printf("Error reading water flow!\n");
        } else
            printf("Water flow in litres per hour (L/h) : %d \n", flow);

        delay(2000);
    }

    return 0;
}
