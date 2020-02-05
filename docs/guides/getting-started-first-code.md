---
id: blink
title: Blink - Hello World for electronics 
sidebar_label: Blink
---

## Pre-requisites 
1. Shunya OS ready and Booted up.
2. LED 
3. Resistor (220 Ohms)


## Step 1: Connect  
Connect as per the image given below.

![blink-001](assets/blink-001.png)

## Step 2: Code 

We need to make the LED blink i.e Turn ON for few seconds and then Turn Off 
and Repeat again.

Coding is simple with Shunya Interfaces 

>Skeleton structure of Shunya Interfaces

For C shunya interfaces follows the standard C coding structure.

<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <shunyaInterfaces.h>

/* Main Function */
int main(void) {
        /* initialize the Library*/
        initLib();
        return 0;
}
```
<!--JavaScript-->
```js
var commingsoon = 1;
```

<!--Python-->
```py
import shunyaInterfaces 
```
<!--END_DOCUSAURUS_CODE_TABS-->

>API for Turning on the LED is 

<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/* Add this line to your main function 
 * to read data from the sensor */
digitalWrite(ledPin, HIGH);
```
<!--JavaScript-->
```js
var commingsoon = 1;
```

<!--Python-->
```py
shunyaInterfaces.digitalWrite(ledPin,shunyaInterfaces.HIGH)
```
<!--END_DOCUSAURUS_CODE_TABS-->


We wait for 2 seconds after turning on the led 

>API for waiting 2 seconds 

<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/* Add this line to your main function  */
delay (2000);
```
<!--JavaScript-->
```js
var commingsoon = 1;
```

<!--Python-->
```py
shunyaInterfaces.delay(2000)
```
<!--END_DOCUSAURUS_CODE_TABS-->

>API for Turning Off the LED is 

<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/* Add this line to your main function 
 * to read data from the sensor */
digitalWrite(ledPin, LOW);
```
<!--JavaScript-->
```js
var commingsoon = 1;
```

<!--Python-->
```py
shunyaInterfaces.digitalWrite(ledPin,shunyaInterfaces.LOW)
```
<!--END_DOCUSAURUS_CODE_TABS-->


>For repeating the steps we use 

<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/* Add this line to your main function */
while(1) {
        /* Write Steps that you want to repeat */
}
```
<!--JavaScript-->
```js
var commingsoon = 1;
```

<!--Python-->
```py
while :
```
<!--END_DOCUSAURUS_CODE_TABS-->


Here is the full code.
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
#include <shunyaInterfaces.h>

int main(){

        /*Initialize Shunya Interfaces library*/
        initLib();
        
        /* For Repeating actions */ 
        while (1) {
                /* Replace ledPin with the Pin number 
                 * where the LED is connected */
                digitalWrite(ledPin, HIGH);
                delay(2000); 
                digitalWrite(ledPin, LOW); 
                delay(2000);
        }
}
```
<!--JavaScript-->
```js
var commingsoon = 1;
```

<!--Python-->
```py
while :
        shunyaInterfaces.digitalWrite(ledPin,shunyaInterfaces.HIGH)
        shunyaInterfaces.delay(2000)
        shunyaInterfaces.digitalWrite(ledPin,shunyaInterfaces.LOW)
        shunyaInterfaces.delay(2000)
```
<!--END_DOCUSAURUS_CODE_TABS-->

## Step 3 : Compile and Run 
To compile the code, run this command in terminal 
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```bash
$ gcc -o blink blink.c -lshunyaInterfaces 
$ sudo ./blink  
```

<!--JavaScript-->
```bash
$ sudo node blink.js
```

<!--Python-->
```bash
$ sudo python3 blink.py
```

<!--END_DOCUSAURUS_CODE_TABS-->

You should see the LED blinking.

