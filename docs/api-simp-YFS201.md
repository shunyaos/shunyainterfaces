---
id: api-adv-bme280
sidebar_label: BME280 Advance API
---

## Advance Functions 

| **API** | **Description** | **Details** |
| ------ | ------ | ------ |
| `bme280Begin()`| Initialize the BME280 sensor | [Read More](#bme280Begin ) |
| `BME280Setting()`| Change settings of the BME280 sensor | [Read More](#BME280Setting ) |
| `bme280getTemperature()`| Get Temperature in deg C from the BME280 sensor | [Read More](#bme280getTemperature ) |
| `bme280getPressure()`| Get Pressure from the BME280 sensor | [Read More](#bme280getPressure ) |
| `bme280getHumidity()`| Get Humidity in %RH from the BME280 sensor | [Read More](#bme280getHumidity ) |
| `bme280getAltitude()`| Get Altitude in meters above sea level from the BME280 sensor | [Read More](#bme280getAltitude ) |

## Reference 

### `bme280Begin()` 

**Description** : Initialize the BME280 sensor.

**Return-type** : void

**Parameters** :

*  `set`(struct bme280Settings) - Structure which stores BME280 Settings   

**Usage** :
```c
/*Include this header file into your program */
#include <bme280.h>

/* Allows the user to change defaults provided set in the library*/
bme280Begin( BME280Setting( MODE_NORMAL, 
                           SAMPLING_NONE, 
                           SAMPLING_NONE, 
                           SAMPLING_NONE, 
                           FILTER_OFF, 
                           STANDBY_MS_0_5 ) );
```

---

### `BME280Setting()` 

**Description** : Initializes the Shunya-Interfaces library.

**Return-type** : void

**Parameters** :

*  `mode`(uint8_t) - Sets BME280 mode to Normal, Forced or Off  
*  `tempSampling`(uint8_t) - Set Sampling for Temperature 
*  `pressSampling`(uint8_t) -  Set Sampling for Temperature
*  `humSampling`(uint8_t) - Set Sampling for Temperature
*  `filter`(uint8_t) -  Set Filter in BME280
*  `duration`(uint8_t) - Set Measurement duration of the BME280 sensor 

**Usage** : 
```c
struct bme280 set = BME280Setting( MODE_NORMAL, 
                           SAMPLING_NONE, 
                           SAMPLING_NONE, 
                           SAMPLING_NONE, 
                           FILTER_OFF, 
                           STANDBY_MS_0_5 );
```

---

### `bme280getTemperature()` 

**Description** : Get Temperature from the BME280 sensor.

**Return-type** : float

**Usage** :
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <bme280.h>

/* Add this line to your main function 
 * to read data from the sensor */
float temperature = bme280getTemperature();

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

---

### `bme280getPressure()` 

**Description** :  Get Pressure from the BME280 sensor.

**Return-type** : float

**Usage** : 
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <bme280.h>

/* Add this line to your main function 
 * to read data from the sensor */
float pressure = bme280getPressure();

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

---

### `bme280getHumidity()` 

**Description** : Get Humidity in %RH from the BME280 sensor.

**Return-type** : float

**Usage** :
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <bme280.h>

/* Add this line to your main function 
 * to read data from the sensor */
float humidity = bme280getHumidity();

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

---

### `bme280getAltitude()` 

**Description** :  Get Altitude in meters above sea level from the BME280 sensor.

**Return-type** : float

**Usage** : 
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <bme280.h>

/* Add this line to your main function 
 * to read data from the sensor */
float altitude = bme280getAltitude();

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

---

