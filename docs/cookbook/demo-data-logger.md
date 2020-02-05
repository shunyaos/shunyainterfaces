---
id: data-logger
title: Connected Sensors for Farms 
sidebar_label: Connected Sensors for Farms
---

## Introduction 

In this project we will be monitoring various environmental parameters
critical for crops and will store the data and create graphs with the 
data getting logged.

""" Insert a picture here of the project working GIF would be awesome """

## Ingredients for the Recipe 
1. Raspberry Pi 3/4 (or any variant of these)
1. SD card with Shunya OS installed, [instructions](getting-started-installation.md)
1. Temperature, Pressure sensor - BME280  
1. Light Intensity Sensor - BH1750
1. Soil Moisture sensor 
1. Analog to Digital Converter PCF8591 
1. OLED Display (size : 128x64) (optional)  
1. Wire Cutter 
1. Screwdriver 
1. Micro SD card Reader
1. Female to Female Du-point cables  

## Step 1: Hardware Setup

![flow-001](assets/farm_bb.png)


## Step 2: Lets code!

Our device must be able to do 
1. Read Temperature 
2. Read Pressure 
3. Read Light Intensity 
4. Read Soil Moisture 
5. Store it in a database  
6. Display it on OLED display.
7. Repeat after 10 minutes 

Coding is simple with Shunya Interfaces 

### Skeleton structure of Shunya Interfaces

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


### API for reading Temperature from the sensor is  
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <bme280.h>

/* Add this line to your main function 
 * to read data from the sensor */
float temp = getTemperature();

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

### API for reading Pressure from the sensor is  
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <bme280.h>

/* Add this line to your main function 
 * to read data from the sensor */
float pressure = getPressure();

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

### API for reading Light Intensity from the sensor is  
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <BH1750.h>

/* Add this line to your main function 
 * to read data from the sensor */
int lux = getLux();

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

### API for reading Soil moisture from the sensor is  
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <PCF8591.h>

/* Add this line to your main function 
 * to read data from the sensor */
int moisture = analogRead(Ain0);

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


### API for displaying data on the OLED Display is 

<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <128x64_oled.h>

/* Add this line to your main function  */
oled_disp_str_big_font (25,0,"Farm Summary!");

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
#include <stdlib.h>
#include <stdio.h>

#include <shunyaInterfaces.h>
#include <bme280.h>
#include <BH1750.h>
#include <PCF8591.h>
#include <128x64_oled.h>

void main(void)
{
        char buf[36];

        /*Initialize Shunya Interfaces library*/
        initLib();
        
        /* Define OLED pins */
        oled_begin(31,33,35,37);
        
        while (1)
        {       
                /* Read data from the sensor */
                float temp = getTemperature();
                float pressure = getPressure();
                int lux = getLux();
                int moisture = analogRead(Ain0);

                /* Display the data on the OLED Display */
                oled_disp_str_big_font (25,0,"Farm Summary!");

                sprintf (&buf, "Temperature = %.2f C", temp);
                oled_disp_str_big_font (5,2, buf);
                
                sprintf (&buf, "Pressure = %.2f mgH", pressure);
                oled_disp_str_big_font (5,2, buf);

                sprintf (&buf, "Light = %d lux", lux);
                oled_disp_str_big_font (5,2, buf);

                sprintf (&buf, "Moisture  = %.2f %", moisture);
                oled_disp_str_big_font (5,4,buf);

                delay(10*60*1000);
        }
}

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

## Step 3: Compile and Run 
To compile the code, run this command in terminal 
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```bash
$ gcc -o iotfarm iotfarm.c -lshunyaInterfaces -lsensors
$ sudo ./iotfarm  
```

<!--JavaScript-->
```bash
$ sudo node iotfarm.js
```

<!--Python-->
```bash
$ sudo python3 iotfarm.py
```

<!--END_DOCUSAURUS_CODE_TABS-->
 
Having Fun! Try out more of our demos.
