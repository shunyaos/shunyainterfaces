---
id: water-meter
title: IoT Water Meter
sidebar_label: IoT Water Meter
---

## Introduction 

IoT Water Meter is a device which can be installed at your home 
and it will provide you with real-time water consumption data and will alert
you if there is an accidental wastage of water.

""" Insert a picture here of the project working GIF would be awesome """

## Ingredients for the Recipe 
1. Raspberry Pi 3/4 (or any variant of these)
1. SD card with Shunya OS installed, [instructions](getting-started-installation.md)
1. Flow sensor - YF-S201 
1. OLED Display (size : 128x64) (optional)  
1. Wire Cutter 
1. Screwdriver 
1. Micro SD card Reader
1. Female to Female Du-point cables  

## Step 1: Hardware Connections

![flow-001](assets/flow_bb.png)


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


### API for measuring water flow from the sensor is  
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <YF-S201.h>

/* Add this line to your main function 
 * to read data from the sensor */
const int pin = 40;
int flow = getflow(pin);

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
oled_disp_str_big_font (25,0,"Water meter!");

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

Here is the full code for the water meter.

<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
#include <stdlib.h>
#include <stdio.h>

#include <shunyaInterfaces.h>
/*Include this header file into your program */
#include <YF-S201.h>

/* Add this line to your main function 
 * to read data from the sensor */

#include <128x64_oled.h>

void main(void){
        const int pin = 40;
        char buf[36];

        /*Initialize Shunya Interfaces library*/
        initLib();
        
        /* Define OLED pins */
        oled_begin(31,33,35,37);
        
        while (1)
        {       

                int flow = getflow(pin);

                /* Display the data on the OLED Display */
                oled_disp_str_big_font (25,0,"Water meter!");

                sprintf (&buf, "Water flow = %.d", flow);
                oled_disp_str_big_font (5,2, buf);

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
$ gcc -o watermeter watermeter.c -lshunyaInterfaces -lsensors
$ sudo ./watermeter  
```

<!--JavaScript-->
```bash
$ sudo node watermeter.js
```

<!--Python-->
```bash
$ sudo python3 watermeter.py
```

<!--END_DOCUSAURUS_CODE_TABS-->
 
Having Fun! Try out more of our demos.
