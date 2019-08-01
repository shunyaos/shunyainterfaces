/**
****************************************************************************
* @file		example.c
* @author	Gaurav Kelkar
* @brief	This file provides the source code for interfacing the reed switch
            sensor.

		                    #### How to use ####
============================================================================
(#) Connect the hardware as per the diagram and run the following code.
(#) Observe the terminal to see the changes in the switch state.
								 
****************************************************************************
*/

#include "KY-025.h"
#define reedPin 40

int main(void)
{
    shunyaInterfacesSetup();
    while (1)
    {
        int x = readReedSwitch(reedPin);
        printf("Switch state: %d", x);
    }
    return 0;
}
