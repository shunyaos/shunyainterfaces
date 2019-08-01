# Using GPIO with Shunya-Interfaces

## Code example

**Here is a sample code to toggle an LED connected to pin23. This code
shows how to use a GPIO pin as an output**

``` c
#include <stdio.h>
//Header file for shunya-interfaces
#include <shunyaInterfaces.h>
#define LED 23

int main (void)
{
//shunyaInterfacesSetup is used to do the board specific initialization
shunyaInterfacesSetup () ;
//pinMode is used to set the direction of the pin LED(i.e pin23)
pinMode (LED, OUTPUT) ;
// Running an infinite loop to blink the LED
for (;;)
{
//digitalWrite is used to write a 1 or 0 to the pin LED(i.e pin23)
        digitalWrite (LED, HIGH) ;  // LED on
//delay is used to produce a millisecond delay
        delay (500) ;       // 500 mS delay
        digitalWrite (LED, LOW) ;   // Led off
        delay (500) ;       // 500 mS delay
}
return 0 ;
}
```

**To compile this code run the following command:**

``` shell
gcc -lshunyaInterfaces toggle-gpio.c -o toggle-gpio
```

**Note: Don't forget to add -lshunyaInterfaces while compiling the code, otherwise you will get linker errors**

**To run this code run the following command:**

``` shell
sudo ./toggle-gpio
```

## API

### `pinmode()`

**Description** : Sets the direction of the GPIO pin to INPUT or OUTPUT 

**Parameters**  

*  `physicalPin`(int) - Physical pin number of the GPIO
*  `mode`(int) - GPIO mode either INPUT or OUTPUT 

**Return-type** : void

**Usage** : pinmode(7, OUTPUT);

---

### `digitalWrite()`

**Description** : Sets the digital value of the GPIO pin  

**Parameters**  

*  `physicalPin`(int) - Physical pin number of the GPIO
*  `value`(int) - value is either HIGH or LOW 

**Return-type** : void

**Usage** : digitalWrite(7, HIGH);

---

### `digitalRead()`

**Description** : Read digital value of the GPIO pin  

**Parameters**  

*  `physicalPin`(int) - Physical pin number of the GPIO

**Return-type** : int

**Returns** : Return GPIO pin value on SUCCESS, Return -1 on FAILURE

**Usage** : result = digitalRead(7);

---