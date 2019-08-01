/**
****************************************************************************
* @file         pir-sensor-example.c
* @author       Piyush Chincholikar and Shunya Core Team
* @brief        This file provides the source code for interfacing the PIR 
*		Sensor Module
*         
@verbatim
-----------------------------------------------------------------------------
                        ## Description ## 
-----------------------------------------------------------------------------
## Introduction
This file contains an example code for interfacing PIR Sensor Module using 
Shunya Interfaces library.

## Connections
There are 3 pins to PIR sensor module
1. VCC (also called +) - Connect it to 3.3V or 5V on the dev Board
2. GND (also called -) - Connect it to GND on the dev Board
3. Signal - Connect it to any GPIO pin on the dev Board

Note: Note the physical pin number of the GPIO pin is given as
#define inputPin <your-GPIO-pin-number> in the code below.

## Compile 
1. Open terminal 
2. Run command `gcc -o pir pir.c -lshunyaInterfaces`

## Run 
1. Open terminal 
2. Run command `./pir`

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

#define inputPin 2 // input pin -> PIR Sensor

int main(){
        int PIR=0;
        // init shunya interfaces library
        shunyaInterfacesSetup();
        // set Given GPIO Pin to INPUT mode
        pinMode(inputPin, INPUT);

        // Infinite Loop
        while(1){
                printf("%d\n",digitalRead(inputPin));
                // if object detected by PIR
                if(digitalRead(inputPin)){
                        // check PIR=0
                        if(!PIR){
                                printf("Motion detected\n");
                                delay(100);
                                PIR=1;	
                        }
                } else {
                        // check PIR=1
                        // PIR is used to print message only when object detected till object vanished and not for other cases
                        if(PIR){
                                printf("Motion ended\n");
                                delay(100);
                                PIR=0;
                        }
                }
                delay(100);
        }
        return 0;
}
