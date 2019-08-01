# Using SPI with Shunya-Interfaces

## Code example

**Here is a sample code to find out the temperature in lux using MAX31855 sensor module(SPI). This code shows how to use SPI with shunya-interfaces. Thesensor is connected to the default SPI-device**

``` c
#include <byteswap.h>
#include <stdint.h>

#include <shunyaInterfaces.h>
#include <SPI.h>


int main ()
{
        uint32_t spiData ;
        int fd, temp, temperatureInDegC, spiChannel = 1;

        /* Initialize Shunya-Interfaces library */
        shunyaInterfacesSetup () ;

        /* Initialize SPI interface with correct speed (5 MHz here) */
        fd = SPISetup (spiChannel, 5000000);

        if (fd < 0)
                return EXIT_FAILURE ;

        /* Gather raw data from SPI interface */        
        SPIDataRW (fd, (unsigned char *)&spiData, 4) ;

        /* The received raw data is LSB + MSB; we need data MSB + LSB hence we swap the data */
        spiData = __bswap_32(spiData) ;

        spiData >>= 18 ;

        /* Select only Bottom 13 bits of the data*/
        temp = spiData & 0x1FFF ;

        /* Check if data is Negative */
        if ((spiData & 0x2000) != 0) 
                temp = -temp ;

        /* Calculate data in deg Celsius */
        temperatureInDegC = (int)((((double)temp * 25) + 0.5) / 10.0) ;

        printf("Temperature in deg C = %d", temperatureInDegC);

        return 0 ;

}
```

**To compile this code run the following command:**

``` shell
gcc -lshunyaInterfaces max31855.c -o max31855
```

**To run this code run the following command:**

``` shell
sudo ./max31855
```

## API

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