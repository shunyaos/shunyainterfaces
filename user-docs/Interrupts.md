# Using SPI with Shunya-Interfaces

## Code example

**Here is a sample code to trigger an ISR when a button connected to GPIO pin 37 is pressed. This code shows how to use Interrupts with shunya-interfaces.**

``` c
#include <stdio.h>
#include <stdlib.h>

#include <shunyaInterfaces.h>
#define intPin 37

volatile int state = 0;
void isr();

int main(void) {
        /* Initialize Shunya-Interfaces library */
        shunyaInterfacesSetup();
        /* Initialize GPIO pin to be an INPUT pin */
        pinMode(intPin, INPUT);
        /* Attach ISR to the GPIO pin */
        attachInterrupt(intPin, INT_EDGE_BOTH, isr);

        while(1) {
                printf("Waiting ... \n");
                delay(100);
        }
        return 0;
}

void isr() {
        printf("Hello from inside ISR\n");
        if(state) state=0;
        else state=1;
}
```

**To compile this code run the following command:**

``` shell
gcc -lshunyaInterfaces buttonISRtest.c -o buttonISRtest
```

**To run this code run the following command:**

``` shell
sudo ./buttonISRtest
```

## API

#s## attachInterrupt()

**Description**: Sets the digital value of the GPIO pin.

**Parameters**
    + `pin` Physical pin number of the GPIO
    + `mode`        Interrupt modes EDGE_FALLING or EDGE_RISING
    + `(*function)` The function that will get the executed in the ISR

**Return-type** : int

**Returns** : Return 0 on SUCCESS, Return -1 on Failure 

**Usage** : attachInterrupt(30, INT_EDGE_BOTH, isr);