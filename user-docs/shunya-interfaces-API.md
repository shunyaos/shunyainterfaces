# Shunya Interfaces API

## Core API

| **API** | **Description** | **Details** |
| ------ | ------ | ------ |
| `shunyaInterfacesSetup()`| Initializes the Shunya-Interfaces library.| [Read More](#shunyainterfacessetup ) |

## GPIO API
| **API** | **Description** | **Details** |
| ------ | ------ | ------ |
| `pinmode()` | Sets the direction of the GPIO pin to INPUT or OUTPUT | [Read More](#pinmode) |
| `digitalWrite()` | Sets the digital value of the GPIO pin | [Read More](#digitalwrite) |
| `digitalRead()` | Read digital value of the GPIO pin | [Read More](#digitalread) |

## Interrupt API

| **API** | **Description** | **Details** |
| ------ | ------ | ------ |
| `attachInterrupt()`| Sets the digital value of the GPIO pin.| [Read More](#attachinterrupt) |

## Delay API
| **API** | **Description** | **Details** |
| ------ | ------ | ------ |
| `delay()` | Code sleeps for given milliseconds | [Read More](#delay) |
| `delayMicroseconds()` | Code sleeps for given microseconds | [Read More](#delaymicroseconds) |


## I2C API
| **API** | **Description** | **Details** |
| ------ | ------ | ------ |
| `wireSetup()` | Setup I2C device(for default I2C device node) | [Read More](#wiresetup) |
| `wireRead()` | Read from I2C device. **wireRead()** is useful in cases where devices present data when you read them without having to do any register transactions.  | [Read More](#wireread) |
| `wireReadReg16()` | Read 16-bit Register from I2C device | [Read More](#wirereadreg16) |
| `wireReadReg8()` | Read 8-bit Register from I2C device | [Read More](#wirereadreg8) |
| `wireWrite()` | Write to I2C device. **wireWrite()** is useful in cases where devices accept data this way without needing to access any internal registers. | [Read More](#wirewrite) |
| `wireWriteReg16()` | Write a 16-bit data value into the device register indicated | [Read More](#wirewritereg16) |
| `wireWriteReg8()` | Write a 8-bit data value into the device register indicated | [Read More](#wirewritereg8) |
| `wireSetupInterface()` | Setup I2C device(if you are using non-default i2c device node. Use it with care) | [Read More](#wiresetupinterface) |

## SPI API
| **API** | **Description** | **Details** |
| ------ | ------ | ------ |
| `SPISetup()` | Open the SPI device, and set it up, in the default MODE 0 | [Read More](#spisetup) |
| `SPIDataRW()` | Write and Read a block of data over the SPI bus | [Read More](#spidatarw) |
| `SPIGetFd()` | Return the file-descriptor for the given channel | [Read More](#spigetfd) |
| `SPISetupMode()` | Open the SPI device, and set it up, with the mode | [Read More](#spisetupmode) |


## UART API
| **API** | **Description** | **Details** |
| ------ | ------ | ------ |
| `serialOpen()` | Open and initialize the serial port | [Read More](#serialopen) |
| `serialClose()` | Release the serial port  | [Read More](#serialclose) |
| `serialGetchar()` | Get a single character from the serial device | [Read More](#serialgetchar) |
| `serialPrintf()` | Printf over Serial | [Read More](#serialprintf) |
| `serialPutchar()` | Send a single character to the serial port | [Read More](#serialputchar) |
| `serialPuts()` | Send a string to the serial port | [Read More](#serialputs) |
| `serialDataAvail()` | Return the number of bytes of data available to be read in the serial port | [Read More](#serialdataavail) |
| `serialFlush()` | Flush the serial buffers (both tx & rx) | [Read More](#serialflush) |


## Core API

### `shunyaInterfacesSetup()` 

**Description** : Initializes the Shunya-Interfaces library.

**Return-type** : void

**Usage** : shunyaInterfacesSetup ();

---

## GPIO API

### `pinmode()`

**Description** : Sets the direction of the GPIO pin to INPUT or OUTPUT 

**Parameters**  

*  `physicalPin`(int) - Physical pin number of the GPIO
*  `mode`(int) - GPIO mode either INPUT or OUTPUT 

**Return-type** : void

**Usage** : pinmode(7, OUTPUT);

---

### `digitalWrite()`

**Description** : Sets the digital value of the GPIO pin  

**Parameters**  

*  `physicalPin`(int) - Physical pin number of the GPIO
*  `value`(int) - value is either HIGH or LOW 

**Return-type** : void

**Usage** : digitalWrite(7, HIGH);

---

### `digitalRead()`

**Description** : Read digital value of the GPIO pin  

**Parameters**  

*  `physicalPin`(int) - Physical pin number of the GPIO

**Return-type** : int

**Returns** : Return GPIO pin value on SUCCESS, Return -1 on FAILURE

**Usage** : result = digitalRead(7);

---

## Delay API

### `delay()`

**Description** : Used to produce millisecond delays  

**Parameters**  

+  `howLong`(unsigned int) - Delay in ms to be produced

**Return-type** : void

**Usage** : delay(50);

---

### `delayMicroseconds()`

**Description**: Used to produce microsecond delays  

**Parameters**  

+  `howLong`(unsigned int) - Delay in us to be produced

**Return-type**: void

**Usage**: delayMicroseconds(50);

---

## I2C/TWI API

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

## SPI API

### `SPISetup()`

**Description**: Open the SPI device, and set it up, in the default MODE 0

**Parameters**
   + `channel` - SPI transfer channel
   + `speed`  - SPI transfer speed

**Return-type** : int

**Returns** : Return File descriptor of SPI device node on SUCCESS, Return -1 on FAILURE 

**Usage** : SPISetup (spiChannel, 5000000)

---

### `SPISetupMode()`

**Description**: Open the SPI device, and set it up, with the mode

Parameters
  +  `channel` -    SPI transfer channel
  +  `speed` -      SPI transfer speed
  +  `mode` -        SPI mode

**Return-type** : int

**Returns** : Return File descriptor of SPI device node on SUCCESS, Return -1 on FAILURE

**Usage** : SPISetupMode (spiChannel, 5000000, 3)

---

### `SPIDataRW()`

**Description**:Write and Read a block of data over the SPI bus

**Parameters**
   + `channel` -     File Descriptor to the device
   + `data` -       Data to be read and write to the device
   + `len` - Length of the data to be R/W

**Return-type** : int

**Returns** : Return 0 on SUCCESS, Return -1 on FAILURE

**Usage** : SPIDataRW (fd, (unsigned char )&spiData, 4)

---

### `SPIGetFd()`

**Description** : Return the file-descriptor for the given channel

**Parameters**
   + `channel` -     File Descriptor to the device

**Return-type** : int

**Returns** : Return File descriptor of SPI device node on SUCCESS, Return -1 on FAILURE

**Usage** : SPIGetFd (spiChannel)

---

## UART API

### `serialOpen()`

**Description** : Open and initialize the serial port

**Parameters**
    + `*device`     Device node for Serial device driver
    + `baud`        Baudrate for Serial communication

**Return-type** : int

**Returns** : Return file descriptor on SUCCESS

**Usage** : serialOpen("/dev/ttyS1",115200)

---

### `serialClose()`

**Description**: Release the serial port

**Parameters**
    + `fd`  File Descriptor to the device

**Return-type** : void

**Usage** : serialClose(fd)

---

### `serialGetchar()`

**Description** : Get a single character from the serial device

**Note** : Zero is a valid character and this function will time-out after 10 seconds. 

**Parameters**
    + `fd`  File Descriptor to the device

**Return-type** : int

**Returns**: Return the character on SUCCESS 

**Usage** : serialGetchar(fd)

---
 
### `serialPrintf()`

**Description**: Printf over Serial interface

**Parameters**
    + `fd`  File Descriptor to the device
    + `message`     Message to be printed in serial

**Return-type** : void

**Usage** : serialPrintf(fd,"Hello World"); 

---

### `serialPutchar()`

**Description**: Send a single character to the serial port

**Parameters**
    + `fd`  File Descriptor to the device
    + `c`   Character to be sent

**Return-type** : void

**Usage** : serialPutchar(fd,"I"); 

---

### `serialPuts()`

**Description**: Send a string to the serial port

**Parameters**
    + `fd`  File Descriptor to the device
    + `s`   String to be sent

**Return-type** : void

**Usage** : serialPuts(fd,"Hello World");

---

### `serialDataAvail()`

**Description**: Return the number of bytes of data available to be read in the serial port

**Parameters**
    + `fd`  File Descriptor to the device

**Return-type** : int

**Returns** : Return the number of bytes of data available to be read in the serial port

**Usage** : serialDataAvail(fd) 

---

### `serialFlush()`

**Description**: Flush the serial buffers (both tx & rx)

**Parameters**
    + `fd`  File Descriptor to the device

**Return-type** : void

**Usage** : serialFlush(fd)

---

## Interrupt API

### `attachInterrupt()`

**Description**: Sets the digital value of the GPIO pin.

**Parameters**
    + `pin` Physical pin number of the GPIO
    + `mode`        Interrupt modes EDGE_FALLING or EDGE_RISING
    + `(*function)` The function that will get the executed in the ISR

**Return-type** : int

**Returns** : Return 0 on SUCCESS, Return -1 on Failure 

**Usage** : attachInterrupt(30, INT_EDGE_BOTH, isr);

---