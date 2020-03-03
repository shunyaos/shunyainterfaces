---
id: 06-connect
title: Connect Peripherals
sidebar_label: Connect Peripherals
---

## Step 0: Install Shunya OS 
See this page to [Install Shunya OS](../get-started/01-installation.md)

## Step 1: Connect  

Connect all your sensors and actuators to the selected board.

Look at their **[Board Pinout](https://docs.google.com/spreadsheets/d/1PR461zqh09Z32ytkGS-EKNDEGQN2yAKHoPj025rdatc/edit?ts=5d652506#gid=44567187)** and connect the sensors.  

## Step 2:  Fill YAML 

Tell ShunyInterfaces what sensor you have connected and where it is connected.


YAML Template will be present in `/etc/interfaces/config.yaml`

```shell
$ sudo cp /etc/interfaces/config.yaml .  
```
Copy the YAML into your projects folder 

Fill the YAML with the sensor IDs against the pin that you have connected the 
sensor.

> Example snippet of YAML file 

```yaml
pin 1: null # 3.3V Vcc Pin 
pin 2: null # 5V Vcc Pin
pin 3: 1.1 # connected to SCL pin of BME280 sensor
pin 4: null # 5V Vcc Pin
pin 5: 1.2 # connected to SCL pin of BME280 sensor
pin 6: null # GND Pin  
```

## Step 3: Code 

>Skeleton structure of Shunya Interfaces

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

Coding is simple with Shunya Interfaces  

For C shunya interfaces follows the standard C coding structure.



## Step 4: Run your program 

> Compile code and Run the program.

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
Compile code and start your application. 
