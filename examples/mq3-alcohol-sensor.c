/**
****************************************************************************
* @file		Alcohol_sensor.c
* @author	Tanmay Desai
* @brief	This file provides the source code for interfacing the 
		alcohol sensor.

		                    #### How to use ####
============================================================================
(#) Connect the hardware as per the diagram and run the following code.
(#) Observe the terminal to see the changes in the switch state.
								 
****************************************************************************
*/

#include <stdlib.h>
#include <stdio.h>

#include <shunyaInterfaces.h>
#include <Wire.h>
#include <pcf8591.h>

int main(void)
{
        shunyaInterfacesSetup();
        pcf8591Setup();
        while (1) { 
                int value;
                value = pcf8591Read(A1);// 0x01 address of Ain1 pin of ADC
                printf("The alcohol value is BAC %d\n",value);
        }
        return 0;
}
