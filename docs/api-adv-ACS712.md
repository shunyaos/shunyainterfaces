## ACS712 Current sensor Advance Functions 

| **API** | **Description** | **Details** |
| ------ | ------ | ------ |
| `acs712Begin()`| Initialize the sensor | [Read More](#acs712begin ) |
| `ACS712Setting()`| Change settings of the sensor | [Read More](#acs712setting ) |
| `acs712getCurrentDC()`| Read DC Current in Amps | [Read More](#acs712getcurrentdc) |
| `acs712getCurrentAC()`| Read AC Current in Amps | [Read More](#acs712getcurrentdc) |

## Reference 

### `acs712Begin()` 

**Description** : Initialize the BME280 sensor.

**Return-type** : void

**Parameters** :

*  `set`(struct ACS712Setting) - Structure which stores BME280 Settings   

**Usage** :
```c
/*Include this header file into your program */
#include <ACS712.h>

/* Allows the user to change defaults provided set in the library*/
acs712Begin( ACS712Setting( ACS712_05B, /* ACS712 5A model */
                            8, /* ADC resolution in bits */  
                            5, /* Reference Voltage */
                            50 /* AC current frequency */) );
```

---

### `ACS712Setting()` 

**Description** : Change the default settings of the sensor.

**Return-type** : struct acs712Settings

**Parameters** :

*  `_model`(uint8_t) - ACS712 model number 
*  `_adcRes`(int) - ADC Resolution in bits (8 bit, 10 bit, 16 bit ...) 
*  `_vRef`(int) -  ADC Reference Voltage ( Vcc Voltage to the ADC)
*  `_inptFreq`(int) - AC frequency in your region 


**Usage** : 
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <ACS712.h>
/* Add this line to your main function */
struct acs712Settings set = ACS712Setting( ACS712_05B, /* ACS712 5A model */
                                          8, /* ADC resolution in bits */  
                                          5, /* Reference Voltage */
                                          50 /* AC current frequency */ );
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

### `acs712getCurrentDC()` 

**Description** : Read DC Current in Amps.

**Return-type** : float

**Usage** :
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <ACS712.h>

/* Add this line to your main function 
 * to read data from the sensor */
float current = acs712getCurrentDC();

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

### `acs712getCurrentAC()` 

**Description** : Read AC Current in Amps.

**Return-type** : float

**Usage** : 
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <ACS712.h>

/* Add this line to your main function 
 * to read data from the sensor */
float current = acs712getCurrentAC();

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