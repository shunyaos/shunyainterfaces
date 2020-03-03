---
id: 06-connect
title: Connect Peripherals
sidebar_label: Connect Peripherals
---

import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import useBaseUrl from '@docusaurus/useBaseUrl';


## Step 1: Install Shunya OS 
See this page to [Install Shunya OS](../get-started/01-installation.md)

## Step 2: Connect  

Connect all your sensors and actuators to the selected board.

Look at their **[Board Pinout](https://docs.google.com/spreadsheets/d/1PR461zqh09Z32ytkGS-EKNDEGQN2yAKHoPj025rdatc/edit?ts=5d652506#gid=44567187)** and connect the sensors.  

## Step 3:  Configure Shunya Interfaces 

Tell ShunyInterfaces what sensor you have connected and where it is connected.

YAML Template will be present in `/etc/interfaces/config.yaml`

```shell
$ sudo cp /etc/interfaces/config.yaml .  
```
Copy the YAML into your projects folder 

Fill the YAML with the sensor IDs against the pin that you have connected the 
sensor.

> Example YAML file snippet :  

```yaml
pin 1: null # 3.3V Vcc Pin 
pin 2: null # 5V Vcc Pin
pin 3: 1.1 # connected to SCL pin of BME280 sensor
pin 4: null # 5V Vcc Pin
pin 5: 1.2 # connected to SCL pin of BME280 sensor
pin 6: null # GND Pin  
```

## Step 4: Code 

>Skeleton structure of Shunya Interfaces

<Tabs
  defaultValue="c"
  values={[
    { label: 'C/CPP', value: 'c', },
  ]
}>

<TabItem value="c">

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

</TabItem>
<TabItem value="py">

```py
import shunyaInterfaces 
```

</TabItem>
<TabItem value="js">

```js
var commingsoon = 1;
```

</TabItem>
</Tabs>

Fill the shunya interfaces skeleton structure with your chosen API's.


## Step 4: Run your program 

Compile code and Run the program.

<Tabs
  defaultValue="c"
  values={[
    { label: 'C/CPP', value: 'c', },
  ]
}>

<TabItem value="c">

```bash
$ gcc -o myapp program.c -lshunyaInterfaces_user -lshunyaInterfaces_core
$ sudo ./myapp  
```

</TabItem>
<TabItem value="py">

```bash
$ sudo python3 blink.py
```

</TabItem>
<TabItem value="js">

```bash
$ sudo node blink.js
```

</TabItem>
</Tabs>

