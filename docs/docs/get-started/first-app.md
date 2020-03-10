---
id: first-app
title: Build your first IoT Application
sidebar_label: First App
---

import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import useBaseUrl from '@docusaurus/useBaseUrl';


Whether you are a Startup, Maker or a hobbyist 
you can use our API's to build IoT products on Embedded Devices.


This is a high level overview of Shunya Interfaces features. Click to 
interact with the image (it has direct links to our documentation).

<a href="http://releases.shunyaos.org/intro-interactive-page.html">
<img alt="Oops!, No Image to display." src={useBaseUrl('img/overview.png')} />
</a>


## Step 1: Select Sensors, Actuators and Insight tools   

Use the basic structure as a start point and Paste code accordingly.

<Tabs
  defaultValue="c"
  values={[
    { label: 'C/CPP', value: 'c', },
  ]
}>

<TabItem value="c">

```c
/*Include this header file into your program */
#include <shunyaInterfaces.h>

/* Main Function */
int main(void) {
        /* Initialize the Library*/
        initLib();


/*####################################
 *       PASTE CODE BELOW
 *####################################*/


        return 0;
}
```

</TabItem>
<TabItem value="py">

```py
import shunyaInterfaces 
```

</TabItem>
<TabItem value="js">

```js
var commingsoon = 1;
```

</TabItem>
</Tabs>

### Choose Sensors (Gather data)

1. [Voltage](categories/08-analog_voltage.md) 
1. [Distance](categories/05-distance.md)
1. [Light Intensity](categories/06-light.md)
1. [Current](categories/09-current.md)
1. [Liquid Flow](categories/07-liquid_flow.md)
1. Gas (coming soon)    
1. Pressure (coming soon)
1. Humidity (coming soon)
1. Motion (coming soon)
1. Temperature (coming soon)

### Choose Insight tools

1. Send Data to Cloud (AWS) 
2. Send Data to Dashboard (coming soon) 

### Choose to send Alerts

1. Send Alerts via Mail (coming soon) 
1. Send Alerts via Messages (coming soon) 
1. Send Alerts via WhatsApp messages (coming soon)  

#### Choose Actuators (Hardware Actions)

1. [LED's](categories/501-led.md)
2. [Relay](categories/502-relay.md) 
3. Pumps(coming soon)
4. Fan(coming soon)

## Step 2: Connect peripherals & Configure Shunya Interfaces

### Choose a dev Board  

Shunya Interfaces supports these development boards, you can choose any one of them
to work with.

1. RockPi-S-V10  
1. Raspberry Pi 4 
1. Raspberry Pi 3
1. OrangePi 2G IOT

### Connect peripherals

Connect all your hardware peripherals to the board. 

To help you with the connections use the links in the excel to easily find 
pinouts for the development boards.

1. **[Dev Board pinouts](https://docs.google.com/spreadsheets/d/1in0_qqWc5r-ngrlRduTemxfzUY_cOrZYDOE2uZ5Woqc/edit?usp=sharing)**  

### Configure Shunya Interfaces

Tell Shunya Interfaces your hardware connections.

You can configure by running command.
```
$ sudo vi /etc/shunya/interfaces/config.yaml
```
#### Sensor ID's and Connection ID's 

You tell all your Hardware connections to Shunya Interfaces via Sensor ID's and 
Connection ID's. 

Each Sensor is given a special ID which the Shunya Interfaces library recognizes.
And each Hardware pin on the Sensor is given a Connection ID.

So when we write `pin 1: 1.1` Shunya Interfaces understands it as `<Sensor 1>.<Sensor pin 1>` connected to `pin 1` of Raspberry Pi.      


For Example :
Let's say that, we have connected 2 devices to the  Raspberry Pi (BME280 and PCF8591) to pin 3 (SDA) & pin 5 (SCL) respectively.

Our Config file will look like.

```yaml

pin 3: [1.1, 6.1]
pin 4: null
pin 5: [1.2, 6.2]
```
Make sure to save your changes to the config file.


## Step 3: Install Shunya OS

Shunya Interfaces is built on top of Shunya OS and comes pre-installed with Shunya Interfaces. 
Shunya OS is an linux-based OS that runs on your hardware, it light-weight and configurable.

### What will you need. 
1. Chosen board and its peripherals
2. microSD card Reader/Adapter and microSD card  
3. Laptop/PC 

### Install Etcher 

Etcher allows you to Flash Shunya OS on the micro-SD card.

<Tabs
  defaultValue="nix"
  values={[
    { label: 'Windows', value: 'win', },
    { label: 'Ubuntu', value: 'nix', },
  ]
}>


<TabItem value="nix">

#### For Ubuntu 16.04 

Installing Etcher is Simple, just run few commands in the terminal

```bash
$ sudo apt update
$ sudo apt install balena-etcher-electron
```

</TabItem>
<TabItem value="win">

#### For Windows 10

Installing Etcher is Simple, download the executable file and Run.

1. Download [balenaEtcher](https://www.balena.io/etcher/) for Windows. 
2. Run balenaEtcherSetup-xxx.exe

</TabItem>
</Tabs>

### Flash Shunya OS  

1. Download [Shunya OS](http://releases.shunyaos.org/interfaces-images/)
1. Right click on the downloaded zip file.
1. Click Extract here.
1. Open Etcher.
1. Click Select Image.
1. You will find the Shunya OS `.img` file in the folder that we had extracted earlier. 
1. Select `shunya-aaaa-image-xxxx.img` file.
1. Insert SD card.
1. Click on Flash. 

<img alt="install-shunya-os-gif" src={useBaseUrl('img/install.gif')} />

This will load the micro-SD card with Shunya OS.

### Booting Up with Shunya OS 
1. Insert the micro-SD card into the board. 
1. Connect peripherals like Keyboard, Mouse and HDMI monitor. 
1. Connect Power Supply. 

The board should boot up with Shunya OS.

#### Login to Shunya
Login with these credentials:

- Username : shunya
- Password : shunya 

## Step 4: Run your program 

Compile code and Run the program.

<Tabs
  defaultValue="c"
  values={[
    { label: 'C/CPP', value: 'c', },
  ]
}>

<TabItem value="c">

```bash
$ gcc -o myapp program.c -lshunyaInterfaces_user -lshunyaInterfaces_core
$ sudo ./myapp  
```

</TabItem>
<TabItem value="py">

```bash
$ sudo python3 blink.py
```

</TabItem>
<TabItem value="js">

```bash
$ sudo node blink.js
```

</TabItem>
</Tabs>


