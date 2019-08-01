/*
				### Example ###
***************************************************************************************************
*	A simple example to show the setting up and usage of LM393 Small sound sensor.
*	It can also be used to trigger a relay/switch by a simple addition of 1 output pin connected
* 	to the switch/relay
*	An useful application of LM393 is making a clap on/clap off switch

				### How to use ###
===================================================================================================
(#) Connect the hardware according to the circuit diagram
	(##) Add an LED to the pin defined as trigger (optional)
		(###) Make necessary changes to trigger LED
(#) Run the following code and the output can be seen when the LED flashes

***************************************************************************************************
*/
#include "LM393.h"
#define soundPin 40

int main(void) {
    shunyaInterfacesSetup(); //Initialize shunyaInterfaces
    smallSoundSetup(soundPin); //Initialize GPIO connected to LM393
    while (1) {
        int x = isSoundDetected(soundPin); //Read pin value
        if (x == HIGH)
        	printf("Sound detected\n");
        else
        	printf("No sound\n");
    }   
    return 0;
}
