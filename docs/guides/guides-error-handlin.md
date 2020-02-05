---
id: error-handling
title: Error Handling
sidebar_label: Error Handling 
---

## Global Error Indicator

Shunya Interfaces library sets a global error variable if any error occurs
while calling the functions of the library.

To debug what caused the error the user has to check if the error variable is 
set and pass it to the function `getError()` which will get the user the error 
message.


### For Example 

<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <shunyaInterfaces.h>

/* Main Function */
int main(void) {
        /* initialize the Library*/
        initLib();

        /* The global error variable is errNum
         * In case of error it is set to a -ve number 
         * and 0 for all other cases
         */
        if (errNum < 0) {
                /* This will print the Error message if initLib 
                 * function goes wrong */
                printf("%s\n", getError(errNum));
        }

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

## Error Logger 

User can also use built-in Error logger to debug their code. By default the logger is turned off. But user can turn it on with a simple function call.


### For Example 

<!--DOCUSAURUS_CODE_TABS-->
<!--C-->
```c
/*Include this header file into your program */
#include <shunyaInterfaces.h>

/* Main Function */
int main(void) {
        /* This will turn on the debug log */
        debugLogOn();
        /* Initialize the Library*/
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