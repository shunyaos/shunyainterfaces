---
id: demo
title: Connected Sensors for Farms 
sidebar_label: Connected Sensors for Farms
---

## Introduction 

In this project we will be monitoring various environmental parameters
critical for crops and will store the data and create graphs with the 
data getting logged.

![flow-001](assets/demo.gif)

## Ingredients for the Recipe 
1. Raspberry Pi 3/4 (or any variant of these)
1. SD card with Shunya OS installed, [instructions](installation.md)
1. Temperature, Pressure sensor - BME280  
1. Soil Moisture sensor 
1. Analog to Digital Converter PCF8591 module with light sensor 
1. OLED Display (128x64) (optional)
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
5. Send it to Dashboard
6. Repeat after 10 minutes 

Coding is simple with Shunya Interfaces 

### Skeleton structure of Shunya Interfaces



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



### API for reading Temperature from the sensor is  



```c
/* Add this line to your main function 
 * to read data from the sensor */
float temp = getCelsius();

```
 

### API for reading Pressure from the sensor is  



```c
/* Add this line to your main function 
 * to read data from the sensor */
float pressure = getPa();

```
 

### API for reading Light Intensity from the sensor is  




```c
/* Add this line to your main function 
 * to read data from the sensor */
int lux = getLux();

```
 

### API for reading Soil moisture from the sensor is  


```c
/* Add this line to your main function 
 * to read data from the sensor */
int moisture = getAdc(Ain1);

``` 

### Send the Data to Dashboard  




```c
/*Include this header file into your program */
#include <curl/curl.h>

#define DASBOARD_IP_ADDR "192.168.0.109"
#define DB_NAME "foo_farm"

/* Add these line to your main function  */
sprintf (&buf, "measurement,host=sensor value=%.2f", temp);
sendToDashboard(buf);

```
 

Here is the full code.



```c
#include <stdlib.h>
#include <stdio.h>

#include <shunyaInterfaces.h>
#include <simple-mode.h>

#define DASBOARD_IP_ADDR "192.168.0.109"
#define DB_NAME "foo_farm"

int sendToDashboard(char *msg) {
        CURL *curl;
        CURLcode res;
        char addr[1024];
        sprintf (&addr, "http://%s:8086/write?db=%s", DASBOARD_IP_ADDR, DB_NAME);
        curl = curl_easy_init();
        if(curl) {
                curl_easy_setopt(curl, CURLOPT_URL, addr);
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, msg);
                res = curl_easy_perform(curl);
                if(res != CURLE_OK)
                        fprintf(stderr, "curl_easy_perform failed: %s\n", curl_easy_strerror(res));
                curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
        return 0;
}

void main(void)
{
        char buf[36];

        /*Initialize Shunya Interfaces library*/
        initLib();
        
        while (1)
        {       
                /* Read data from the sensor */
                float temp = getCelsius();
                float pressure = getPa();
                int lux = getLux();
                int moisture =  getAdc(Ain1);
                
                char buf[128];
                /* Send data to dashboard */
                sprintf (&buf, "temperature,host=bme280 temp=%.2f", temp);
                sendToDashboard(buf);
                sprintf (&buf, "pressure,host=bme280 pressure=%.2f", pressure);
                sendToDashboard(buf);
                sprintf (&buf, "light.intensity,host=pcf8591 lux=%.2f", lux);
                sendToDashboard(buf);
                sprintf (&buf, "soil.moisture,host=pcf8591 moisture=%.2f", moisture);
                sendToDashboard(buf);

                delay(10*60*1000);
        }
}

```

 

## Step 3: Compile and Run 

To compile the code, run this command in terminal 

```bash
$ gcc -o iotfarm iotfarm.c -lshunyaInterfaces_user -lshunyaInterfaces_core
$ sudo ./iotfarm  
```

