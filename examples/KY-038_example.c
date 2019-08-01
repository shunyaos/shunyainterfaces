/**
****************************************************************************
* @file		example.c
* @author	Gaurav Kelkar
* @brief	This file provides the source code for interfacing the big sound
            sensor.

		                    #### How to use ####
============================================================================
(#) Connect the hardware as per the diagram and run the following code.
(#) Observe the terminal to see the changes in the switch state.
								 
****************************************************************************
*/

#include "KY-038.h"
#define soundPin 40

int main(void) {
    shunyaInterfacesSetup();
    while (1) {
        int x = readSoundSensor(soundPin);
        printf("Sound level: %d", x);
    }   
    return 0;
}
