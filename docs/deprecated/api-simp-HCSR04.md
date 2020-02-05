# HC-SR04 Simple Mode 

| **API** | **Description** | **Details** |
| ------ | ------ | ------ |
| `getDistance()`| Get distance from Ultrasonic Sensor | [Read More](#getdistance ) |

## Reference 

### `getDistance()` 

**Description** :  Get distance from Ultrasonic Sensor.

**Return-type** : int

**Parameters** :

*  `echoPin`(int) - GPIO pin connected to Echo  
*  `triggerPin`(int) -  GPIO pin connected to Trigger

**Usage** : 
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <hc-sr04.h>

/* Add this line to your main function 
 * to read data from the sensor */
int distance = getDistance(int echoPin, int triggerPin);

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

