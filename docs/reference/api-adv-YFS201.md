# YFS201 Advance Mode Functions 

| **API** | **Description** | **Details** |
| ------ | ------ | ------ |
| `yfs201Begin()`| Initialize the sensor | [Read More](#yfs201Begin) |
| `yfs201getFlow()`| Read flow rate in Liters/hr| [Read More](#yfs201getFlow) |

## Reference 

### `yfs201Begin()` 

**Description** : Initialize the sensor.

**Return-type** : void

**Parameters** :

*  `pin`(int) - GPIO pin connected to the sensor 

**Usage** :
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <YF-S201.h>

/* Allows the user to change defaults provided set in the library*/
yfs201Begin();

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

### `yfs201getFlow()` 

**Description** : Read flow rate in Liters/hr.

**Return-type** : int16_t

**Usage** : 
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <YF-S201.h>

/* Add this line to your main function 
 * to read data from the sensor */
int16_t flow = yfs201getFlow();

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