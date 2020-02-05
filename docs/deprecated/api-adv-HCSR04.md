# HCSR04 Advance Mode Functions 

| **API** | **Description** | **Details** |
| ------ | ------ | ------ |
| `hcsr04Begin()`| Initialize the BME280 sensor | [Read More](#hcsr04begin ) |
| `hcsr04getDistance()`| Change settings of the BME280 sensor | [Read More](#hcsr04getdistance ) |

## Reference 

### `hcsr04Begin()` 

**Description** : Initialize the HCSR04 sensor.

**Return-type** : void

**Parameters** :

*  `echoPin`(int) - GPIO pin connected to the echo pin   
*  `triggerPin`(int) - GPIO pin connected to the trigger pin 


**Usage** :
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <HCSR04.h>

/* Add these lines to your main function */
const int echoPin = 40;
const int triggerPin = 38;

hcsr04Begin( echoPin, triggerPin );
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

### `hcsr04getDistance()` 

**Description** : Get proximity distance from the sensor 

**Return-type** : int16_t

**Parameters** :

*  `echoPin`(int) - GPIO pin connected to the echo pin   
*  `triggerPin`(int) - GPIO pin connected to the trigger pin 

**Usage** : 
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <HCSR04.h>

/* Add these lines to your main function */
const int echoPin = 40;
const int triggerPin = 38;

int16_t distance = hcsr04getDistance( echoPin, triggerPin );
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
