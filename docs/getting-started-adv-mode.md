---
id: adv-mode
title: Shunya Interfaces - Advance Mode
sidebar_label: Advance Mode 
---

## Introduction

Advance mode is for people who are perfectionists and expect the same 
from Shunya Interfaces. 

It allows the users to tweak and change each setting according to their 
preferences.

Lets do a Tutorial using Advance mode.

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

/* This allows you to change default settings */
bme280Begin( BME280Settings( MODE_NORMAL, 
                            SAMPLING_X16,
                            SAMPLING_X16,
                            SAMPLING_X16,
                            FILTER_OFF,
                            STANDBY_MS_0_5 ));
/* Add this line to your main function 
 * to read data from the sensor */
float temp = bme280getTemperature ();
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
        /* This allows you to change default settings */
        bme280Begin( BME280Settings( MODE_NORMAL, 
                                    SAMPLING_X16,
                                    SAMPLING_X16,
                                    SAMPLING_X16,
                                    FILTER_OFF,
                                    STANDBY_MS_0_5 ));

        /* For Repeating actions */ 
        while (1) {
                /* Get Temperature data */
                float temp = bme280getTemperature ();
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
$ gcc -o advmode advmode.c -lshunyaInterfaces 
$ sudo ./advmode  
```

<!--JavaScript-->
```bash
$ sudo node advmode.js
```

<!--Python-->
```bash
$ sudo python3 advmode.py
```

<!--END_DOCUSAURUS_CODE_TABS-->

You should see the Ambient Temperature getting printed on the Terminal.
