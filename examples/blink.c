/**
****************************************************************************
* @file         blink.c
* @author       Shunya Core Team
* @brief        This file provides the source code for interfacing LED
*               and Blinking it infinitely.
*         
@verbatim
-----------------------------------------------------------------------------
                        ## Description ## 
-----------------------------------------------------------------------------
## Introduction
This file contains an example code for interfacing LED and Blinking it 
infinitely using Shunya Interfaces library.

## Compile 
1. Open terminal 
2. Run command `gcc -o blink blink.c -lshunyainterfaces`

## Run 
1. Open terminal 
2. Run command `./blink`

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
//Header file for shunya-interfaces
#include <shunyaInterfaces.h>

#define LED 23

int main (void)
{
        /* Initialize the library */
        shunyaInterfacesSetup () ;
        /* pinMode is used to set the direction of the pin LED(i.e pin23) */
        pinMode (LED, OUTPUT) ;
        /* Running an infinite loop to blink the LED */ 
        for (;;)
        {
                digitalWrite (LED, HIGH) ;  // LED on
                delay (500) ;       // 500 mS delay
                digitalWrite (LED, LOW) ;   // LED off
                delay (500) ;       // 500 mS delay
        }
        return 0 ;
}

