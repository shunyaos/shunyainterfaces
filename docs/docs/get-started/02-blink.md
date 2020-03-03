---
id: blink
title: Blink - Hello World for electronics 
sidebar_label: Blink
---

import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';


## Pre-requisites 
1. Shunya OS ready and Booted up.
2. LED 
3. Resistor (220 Ohms)


## Step 1: Connect  
Connect as per the image given below.

![blink-001](../assets/blink-001.png)

## Step 2: Code 

We need to make the LED blink i.e Turn ON for few seconds and then Turn Off 
and Repeat again.

Coding is simple with Shunya Interfaces 

>Skeleton structure of Shunya Interfaces

For C shunya interfaces follows the standard C coding structure.



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

>API for Turning on the LED is 

<Tabs
  defaultValue="c"
  values={[
    { label: 'C/CPP', value: 'c', },
  ]
}>

<TabItem value="c">

```c
/* Add this line to your main function 
 * to read data from the sensor */
digitalWrite(ledPin, HIGH);
```

</TabItem>
<TabItem value="py">

```py
import commingsoon 
```

</TabItem>
<TabItem value="js">

```js
var commingsoon = 1;
```

</TabItem>
</Tabs>


We wait for 2 seconds after turning on the led 

>API for waiting 2 seconds 

<Tabs
  defaultValue="c"
  values={[
    { label: 'C/CPP', value: 'c', },
  ]
}>

<TabItem value="c">

```c
/* Add this line to your main function  */
delay (2000);
```

</TabItem>
<TabItem value="py">

```py
import commingsoon 
```

</TabItem>
<TabItem value="js">

```js
var commingsoon = 1;
```

</TabItem>
</Tabs>

>API for Turning Off the LED is 

<Tabs
  defaultValue="c"
  values={[
    { label: 'C/CPP', value: 'c', },
  ]
}>

<TabItem value="c">

```c
/* Add this line to your main function 
 * to read data from the sensor */
digitalWrite(ledPin, LOW);
```

</TabItem>
<TabItem value="py">

```py
import commingsoon 
```

</TabItem>
<TabItem value="js">

```js
var commingsoon = 1;
```

</TabItem>
</Tabs>

>For repeating the steps we use 

<Tabs
  defaultValue="c"
  values={[
    { label: 'C/CPP', value: 'c', },
  ]
}>

<TabItem value="c">

```c
/* Add this line to your main function */
while(1) {
        /* Write Steps that you want to repeat */
}
```

</TabItem>
<TabItem value="py">

```py
import commingsoon 
```

</TabItem>
<TabItem value="js">

```js
var commingsoon = 1;
```

</TabItem>
</Tabs>

Here is the full code.

<Tabs
  defaultValue="c"
  values={[
    { label: 'C/CPP', value: 'c', },
  ]
}>

<TabItem value="c">

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

</TabItem>
<TabItem value="py">

```py
import commingsoon 
```

</TabItem>
<TabItem value="js">

```js
var commingsoon = 1;
```

</TabItem>
</Tabs>

## Step 3 : Compile and Run 
To compile the code, run this command in terminal 

<Tabs
  defaultValue="c"
  values={[
    { label: 'C/CPP', value: 'c', },
  ]
}>

<TabItem value="c">

```bash
$ gcc -o blink blink.c -lshunyaInterfaces -lshunyaInterfaces_core
$ sudo ./blink  
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

You should see the LED blinking.

