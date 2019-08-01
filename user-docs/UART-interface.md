# Using SPI with Shunya-Interfaces

## Code example

**Here is a sample code to To connect to the Wifi using ESP8266 connected over UART interface. This code shows how to use UART with shunya-interfaces.**

``` c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <shunyaInterfaces.h>
#include <Serial.h>


/* Function checks if "OK" was received via UART interface */
int checkOK(int fd) {
    char buf[100];
    char x;
        int i = 0;
        /* Read from the UART interface one char at a time*/
        while(x = serialGetchar(fd)) {
                if(x == '\n') break;
                /* Store the characters into a buffer*/        
                buf[i] = x;
                i++;
    }
    /* Check if buffer value = "OK" */
    if(!strncmp(buf,"OK",2)) {
        return 1;
    } else {
        printf("%s\n", buf);
    }
}

int main(void) {
        
        /* Initialize Shunya-Interfaces library */
        shunyaInterfacesSetup();
        
        /* Initialize UART interface with desired baudrate */
        int fd = serialOpen("/dev/ttyS1",115200);
        
        /* Send the AT command to the ESP8266 Module */
        serialPrintf(fd,"AT+GMR\r\n");
        delay(500);
        /* Check if we received "OK" from the ESP8266 module */
        while(checkOk(fd)==0);

        /* Send the AT command to the ESP8266 Module */
        serialPrintf(fd,"AT+CWMODE=1\r\n");
        delay(10);
        /* Check if we received "OK" from the ESP8266 module */
        while(checkOk(fd)==0);
        
        /* Send the AT command to the ESP8266 Module */
        serialPrintf(fd,"AT+CWLAP\r\n");
        delay(10);
        /* Check if we received "OK" from the ESP8266 module */
        while(checkOk(fd)==0);
        
        /* Send the AT command to the ESP8266 Module */
        serialPrintf(fd,"AT+CWJAP="SSID","Password"\r\n");
        /* Check if we received "OK" from the ESP8266 module */
        while(checkOk(fd)==0);
        delay(10);
        
        /* Send the AT command to the ESP8266 Module */
        serialPrintf(fd,"AT+CIFSR\r\n");
        delay(10);
        /* Check if we received "OK" from the ESP8266 module */
        while(checkOk(fd)==0);

        return 0;
}
```

**To compile this code run the following command:**

``` shell
gcc -lshunyaInterfaces esp8266.c -o esp8266
```

**To run this code run the following command:**

``` shell
sudo ./esp8266
```

## API

### serialOpen()

**Description** : Open and initialize the serial port

**Parameters**
    + `*device`     Device node for Serial device driver
    + `baud`        Baudrate for Serial communication

**Return-type** : int

**Returns** : Return file descriptor on SUCCESS

**Usage** : serialOpen("/dev/ttyS1",115200)

---

### serialClose()

**Description**: Release the serial port

**Parameters**
    + `fd`  File Descriptor to the device

**Return-type** : void

**Usage** : serialClose(fd)

---

### serialGetchar()

**Description** : Get a single character from the serial device

**Note** : Zero is a valid character and this function will time-out after 10 seconds. 

**Parameters**
    + `fd`  File Descriptor to the device

**Return-type** : int

**Returns**: Return the character on SUCCESS 

**Usage** : serialGetchar(fd)

---
 
### serialPrintf()

**Description**: Printf over Serial interface

**Parameters**
    + `fd`  File Descriptor to the device
    + `message`     Message to be printed in serial

**Return-type** : void

**Usage** : serialPrintf(fd,"Hello World"); 

---

### serialPutchar()

**Description**: Send a single character to the serial port

**Parameters**
    + `fd`  File Descriptor to the device
    + `c`   Character to be sent

**Return-type** : void

**Usage** : serialPutchar(fd,"I"); 

---

### serialPuts()

**Description**: Send a string to the serial port

**Parameters**
    + `fd`  File Descriptor to the device
    + `s`   String to be sent

**Return-type** : void

**Usage** : serialPuts(fd,"Hello World");

---

### serialDataAvail()

**Description**: Return the number of bytes of data available to be read in the serial port

**Parameters**
    + `fd`  File Descriptor to the device

**Return-type** : int

**Returns** : Return the number of bytes of data available to be read in the serial port

**Usage** : serialDataAvail(fd) 

---

### serialFlush()

**Description**: Flush the serial buffers (both tx & rx)

**Parameters**
    + `fd`  File Descriptor to the device

**Return-type** : void

**Usage** : serialFlush(fd)

---
