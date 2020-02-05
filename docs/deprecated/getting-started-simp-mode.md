---
id: simple-mode
title: Shunya Interfaces - Simple Mode
sidebar_label: Simple Mode 
---

## Introduction
Sensors are Complex! and Hence programming them should be complex right ? 

**No!**, We dont think so. Shunya Interfaces makes it super simple to program 
sensors and interact with them.

Lets do a Tutorial using simple mode.

## Pre-requisites 
1. Shunya OS ready and Booted up.
2. BME280 Sensor 
3. Female to Female Du-point cables 


## Step 1: Connect  
Connect as per the image given below.

![bme280-001](assets/blink-001.png)

## Step 2: Code 

We need to read Temperature from the sensor.

Coding is simple with Shunya Interfaces 

### Skeleton structure of Shunya Interfaces

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

### API for Reading Temperature data is 

<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
#include <bme280.h>
/* Add this line to your main function 
 * to read data from the sensor */
float temp = getTemperature ();
```
<!--JavaScript-->
```js
var commingsoon = 1;
```

<!--Python-->
```py
import comming soon
```
<!--END_DOCUSAURUS_CODE_TABS-->

Here is the full code.
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
#include <shunyaInterfaces.h>
#include <bme280.h>

int main(){

        /*Initialize Shunya Interfaces library*/
        initLib();
        
        /* For Repeating actions */ 
        while (1) {
                /* Get Temperature data */
                float temp = getTemperature ();
                /* Print Temperature data */
                printf("Temperature = %.2f deg C\n", temp);
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
$ gcc -o simplemode simplemode.c -lshunyaInterfaces 
$ sudo ./simplemode  
```

<!--JavaScript-->
```bash
$ sudo node simplemode.js
```

<!--Python-->
```bash
$ sudo python3 simplemode.py
```

<!--END_DOCUSAURUS_CODE_TABS-->

You should see the Ambient Temperature getting printed on the Terminal.

Next up we will do the same application, But with Advance mode.