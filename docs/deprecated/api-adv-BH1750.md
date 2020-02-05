# BH1750 Advance Mode Functions  

| **API** | **Description** | **Details** |
| ------ | ------ | ------ |
| `bh1750Begin()`| Initialize the sensor | [Read More](#bh1750begin ) |
| `bh1750End()`| De-initialize sensor | [Read More](#bh1750end ) |
| `bh1750Read()`| Read light intensity in lux  | [Read More](#bh1750read ) |

## Reference 

### `bme280Begin()` 

**Description** : Initialize the BH1750 sensor.

**Return-type** : void

**Usage** :
```c
/*Include this header file into your program */
#include <BH1750.h>

bh1750Begin();
```

---

### `bh1750End()` 

**Description** : De-Initializes the BH1750 sensor.

**Return-type** : void

**Usage** : 

<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <BH1750.h>

/* Add this line to your main function */
bh1750End();

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


### `bh1750Read()` 

**Description** :  Read Light Intensity from the sensor .

**Return-type** : int16_t 

**Usage** : 
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <bme280.h>

/* Add this line to your main function 
 * to read data from the sensor */
int16_t lux = bh1750Read();

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
