# PCF8591 Advance Mode Functions 

| **API** | **Description** | **Details** |
| ------ | ------ | ------ |
| `pcf8591Begin()`| Initialize the ADC | [Read More](#pcf8591begin) |
| `pcf8591End()`| De-Initialize the ADC | [Read More](#pcf8591end) |
| `pcf8591Read()`| Read raw Digital data from ADC | [Read More](#pcf8591read) |
| `PCF8591Setting()`| Change default settings | [Read More](#pcf8591setting) |


## Reference 

### `pcf8591Begin()` 

**Description** : Initialize the PCF8591 sensor.

**Return-type** : void

**Parameters** :

*  `set`(struct pcf8591Settings) - Structure which stores PCF8591 Settings   

**Usage** :
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <pcf8591.h>

/* Allows the user to change defaults provided set in the library*/
pcf8591Begin( PCF8591Setting( AUTOINCREMENT_READ_EN, /*Enable Auto increment*/ 
                           SINGLE_ENDED_INPUT, /* PCF8591 Single ended mode */
                           ENABLE_OUTPUT /* PCF8591 output enable */ );
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

### `PCF8591Setting()` 

**Description** : Allows the user to change the settings of the sensor.

**Return-type** : struct pcf8591Settings

**Parameters** :

*  `autoIncrement`(uint8_t) - PCF8591 provides this setting for Auto increment  
*  `inputMode`(uint8_t) - PCF8591 provides 4 modes of operation, set any one of these 4 modes of operation. 
*  `outputMode`(uint8_t) - PCF8591 provides one output pin you can enable or disable output using this setting


**Usage** : 

<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
#include <pcf8591.h>

struct pcf8591Settings set =  PCF8591Setting( AUTOINCREMENT_READ_EN, /*Enable Auto increment*/ 
                           SINGLE_ENDED_INPUT, /* PCF8591 Single ended mode */
                           ENABLE_OUTPUT /* PCF8591 output enable */ );
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

```c

```

---

### `pcf8591End()` 

**Description** : De-initialize the sensor.

**Return-type** : float

**Usage** :
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <pcf8591.h>

/* Add this line to your main function */
pcf8591End();
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

### `pcf8591Read()` 

**Description** :  Read the digital data from ADC.

**Return-type** : int16_t

**Usage** : 
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <pcf8591.h>

/* Add this line to your main function 
 * to read data from the sensor */
int16_t value = pcf8591Read();

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