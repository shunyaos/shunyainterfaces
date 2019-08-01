# Using I2C with Shunya-Interfaces

## Code example

**Here is a sample code to find out the light intensity in lux using BH1750 sensor module(I2C). This code shows how to use I2C with shunya-interfaces. The light-intensity sensor is connected to the default I2C-device**

``` c
#include <stdio.h>
#include <stdlib.h>
// Header file for shunya-interfaces I2c
#include <Wire.h>
// Header file for shunya-interfaces
#include <shunyaInterfaces.h>
// I2C Address of sensor
#define BH1750_ADDR 0x23

int main (void){

	int fd,word,result;
//shunyaInterfacesSetup is used to do the board specific initialization
        shunyaInterfacesSetup();
//Initialises the I2C system with your given device identifier(sensor address)
        fd = wireSetup(BH1750_ADDR) ; 
        if(fd < 0)
        {
                printf("I2C-device not found. You might have forgotten to load the i2c module");
                return -1;
        }
	while(1)
	{
		wireWrite(fd,0x10);//Set data in continuious High-res mode 
		delay(1000); //Sleep for 1sec
        	word=wireReadReg16(fd,0x00);//read 16-bit value from the device register indicated.
        	result=((word & 0xff00)>>8) | ((word & 0x00ff)<<8); //converting 16bit hex to integer
        	printf("Current light intensity in Lux:%d \n",result); 
		delay(1000); //Sleep for 1sec
 	}  
return 0;
}
```

**To compile this code run the following command:**

``` shell
gcc -lshunyaInterfaces bh1750.c -o bh1750
```

**To run this code run the following command:**

``` shell
sudo ./bh1750
```

## API

### `wireSetup()`

**Description** : Setup I2C device(for default I2C device node)   

**Parameters**  

*  `devId`(const int) - I2C device address

**Return-type** : int

**Returns** :  Standard Linux filehandle on SUCCESS or returns -1 on FAILURE

**Usage** : fd = wireSetup(0X23); //0x23 is the device address

---

### `wireSetupInterface()`

**Description** : Setup I2C device(if you are using non-default i2c device node. Use it with care)   

**Parameters**  

+  `device`(const char *) - Linux device node
+  `devId`(const int) - I2C device address

**Return-type** : int

**Returns** :  Standard Linux filehandle on SUCCESS or returns -1 on FAILURE

**Usage** : wireSetupInterface(/dev/i2c-2,0X23); //0x23 is the device address

---

### `wireRead()`

**Description** : Read from I2C device. **wireRead()** is useful in cases where devices present data when you read them without having to do any register transactions.  

**Parameters**  

*  `fd`(int) - File Descriptor to the device (Obtained from the return value of **wireSetup()** function)

**Return-type** : int

**Returns** :  The value sent from sensor or returns -1 on FAILURE

**Usage** : ret = wireRead(fd);

---

### `wireReadReg16()`

**Description** : Read 16-bit Register from I2C device  

**Parameters**  

*  `fd`(int) - File Descriptor to the device (Obtained from the return value of **wireSetup()** function)
*  `reg`(int) - Address of Register to be read 

**Return-type** : int

**Returns** :  16-bit value present in the register whose address you specified or returns -1 on FAILURE

**Usage** : wireReadReg16(fd,0x10); //0x10 is the address of the register to be read

---

### `wireReadReg8()`

**Description** : Read 8-bit Register from I2C device  

**Parameters**  

*  `fd`(int) - File Descriptor to the device (Obtained from the return value of **wireSetup()** function)
*  `reg`(int) - Address of Register to be read 

**Return-type** : int

**Returns** :  8-bit value present in the register whose address you specified or returns -1 on FAILURE 

**Usage** : ret = wireReadReg8(fd,0x10); //0x10 is the address of the register to be read

---

### `wireWrite()`

**Description** : Write to I2C device. **wireWrite()** is useful in cases where devices accept data this way without needing to access any internal registers. 

**Parameters**  

*  `fd`(int) - File Descriptor to the device (Obtained from the return value of **wireSetup()** function)
*  `data`(int) - Data to be written into the device

**Return-type** : int

**Returns** : -1 on FAILURE

**Usage** : wireWrite(fd,0x01); //0x01 represent data to be sent to the sensor
        
---

### `wireWriteReg16()`

**Description** : Write a 16-bit data value into the device register indicated.   

**Parameters**  

*  `fd`(int) - File Descriptor to the device (Obtained from the return value of **wireSetup()** function)
*  `reg`(int) - Address of Register to be written to
*  `data`(int) - Data to be written into the device

**Return-type** : int

**Returns** : -1 on FAILURE

**Usage** : wireWriteReg16(fd,0x10,0x0100); //Write 0x0100 in the register whose address is 0x10

---

### `wireWriteReg8()`

**Description** : Write a 8-bit data value into the device register indicated.  

**Parameters**  

*  `fd`(int) - File Descriptor to the device (Obtained from the return value of **wireSetup()** function)
*  `reg`(int) - Address of Register to be written to 
*  `data`(int) - Data to be written into the device

**Return-type** : int

**Returns** : -1 on FAILURE

**Usage** : wireWriteReg8(fd,0x10,0x01); //Write 0x01 in the register whose address is 0x10

---