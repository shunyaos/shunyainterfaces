---
id: digitalread
title: Read data from the GPIO sensor  
sidebar_label: digitalRead
---

## Pre-requisites 
1. Shunya OS ready and Booted up.
2. PIR sensor 
3. Female to Female Du-point cables 


## Step 1: Connect  
Connect as per the image given below.

![pir-001](assets/pir-001.jpg)

## Step 2: Code 

1. We need to read data from the PIR sensor.
2. Print "Intruder!" if sensor detects any movement. 

We have made coding simple with Shunya Interfaces. 

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

### API for Reading PIR data is

<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/* Add this line to your main function 
 * to read data from the sensor */
int read = digitalRead(pirPin);
```

<!--JavaScript-->
```js
var commingsoon = 1;
```

<!--Python-->
```py
read = shunyaInterfaces.digitalRead(pirPin)
```
<!--END_DOCUSAURUS_CODE_TABS-->

### Print Intruder!
A simple `if else` conditions will do out job. 

<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
if ( 1 == read ) {
        printf("Intruder!\n");
}
```
<!--JavaScript-->
```js
var commingsoon = 1;
```

<!--Python-->
```py
read = shunyaInterfaces.digitalRead(pirPin)
```
<!--END_DOCUSAURUS_CODE_TABS-->


We wait for 2 seconds after Reading 

### API for waiting 2 seconds 

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
                /* Replace pirPin with the Pin number 
                 * where the PIR is connected */
                int read = digitalRead(pirPin);

                if ( 1 == read ) {
                        printf("Intruder!\n");
                }

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
import shunyaInterfaces
while :
        read = shunyaInterfaces.digitalRead(pirPin)
        if read == 1
                print "Intruder!"

        shunyaInterfaces.delay(2000)
```
<!--END_DOCUSAURUS_CODE_TABS-->

## Step 3 : Compile and Run 

To compile the code, run this command in terminal 

<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```bash
$ gcc -o pir pir.c -lshunyaInterfaces 
$ sudo ./pir  
```

<!--JavaScript-->
```bash
$ sudo node pir.js
```

<!--Python-->
```bash
$ sudo python3 pir.py
```

<!--END_DOCUSAURUS_CODE_TABS-->

You should see "Intruder!" getting printed when you block the PIR sensor with your hands.

