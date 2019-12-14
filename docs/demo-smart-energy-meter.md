---
id: energy
title: Smart Energy Meter
sidebar_label: Smart Energy Meter
---

## Introduction 

Smart Energy Meter is a device which can be plugged to your electrical 
connection at you home and it will provide you with energy consumption, 
power usage and your energy bill in real-time.

""" Insert a picture here of the project working GIF would be awesome """

## Ingredients for the Recipe 
1. Raspberry Pi 3/4 (or any variant of these)
1. SD card with Shunya OS installed, [instructions](getting-started-installation.md)
2. Current sensor ACS712
3. Analog to Digital Converter PCF8591 
4. OLED Display (size : 128x64) (optional)  
5. Wire Cutter 
6. Screwdriver 
7. Micro SD card Reader
8. Female to Female Du-point cables  

## Step 1: Hardware Setup

![flow-001](assets/energy_bb.png)

## Step 2: Lets code!

Our smart Energy mater must be able to do 
1. Read AC Current from the sensor 
2. Convert the AC Current to Power and Energy 
3. Display it on OLED display.

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


### API for reading AC current from the sensor is  
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <ACS712.h>

/* Add this line to your main function 
 * to read data from the sensor */
float current = getACCurrent(0);

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

### Conversion logic for Power and Energy 

Power = Voltage x Current 

AC voltages are fixed for a region, Check the AC voltage in your region and multiply it with current to get power.

Energy = Power / Time 

Get time from the system and divide it by power to get energy consumption.

### API for displaying data on the OLED Display is 

<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <128x64_oled.h>

/* Add this line to your main function  */
oled_disp_str_big_font (25,0,"Power meter!");

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

Here is the full code for the smart energy meter.

<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
#include <stdlib.h>
#include <stdio.h>

#include <shunyaInterfaces.h>
#include <ACS712.h>
#include <128x64_oled.h>

void main(void){
        float current = 0;
        const float voltage = 250.0;
        float power = 0;
        float energy = 0;
        float cost = 0;
        long msec;
        long sec;
        char buf[36];

        /*Initialize Shunya Interfaces library*/
        initLib();
        
        /* Define OLED pins */
        oled_begin(31,33,35,37);
        
        while (1)
        {       
                /* Get time from the system and convert it to secs*/
                msec = millis();
                sec = msec/1000;   

                /* Read current from the sensor */
                current = getACCurrent(0);
                
                /* Calculate power */
                power = voltage * current;
                /* Calculate energy*/
                energy = power/sec;

                /* Display the data on the OLED Display */
                sprintf (&buf, "Power used = %.2f", power_used);
                oled_disp_str_big_font (25,0,"Power meter!");
                oled_disp_str_big_font (5,2, buf);
                sprintf (&buf, "Energy  = %.2f", energy);
                oled_disp_str_big_font (5,4,buf);

                delay(100);
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

 
Having Fun! Try out more of our demos .
