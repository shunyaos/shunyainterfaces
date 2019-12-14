# ACS712 simple mode  

| **API** | **Description** | **Details** |
| ------ | ------ | ------ |
| `getDCCurrent()`| Read DC current (Amps) | [Read More](#getdccurrent) |
| `getACCurrent()`| Read AC current (Amps) | [Read More](#getaccurrent) |

## Reference 

### `getDCCurrent()` 

**Description** : Read DC current (Amps).

**Return-type** : float

**Usage** :
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <ACS712.h>

/* Add this line to your main function 
 * to read data from the sensor */
float current = getDCCurrent();

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

### `getACCurrent()` 

**Description** : Read AC current (Amps).

**Return-type** : float

**Usage** : 
<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <ACS712.h>

/* Add this line to your main function 
 * to read data from the sensor */
float current = getACCurrent();

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