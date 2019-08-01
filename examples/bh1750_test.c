/**
  ******************************************************************************
  * @file       bh1750_test.c
  * @author     Shunya Core Team
  * @brief      This file contains Test code for BH1750 sensor 
  *         
  @verbatim
 
    @endverbatim
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 IoTIoT.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by IoTIoT under GPLv3 license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/GPL-3.0
  *
  ******************************************************************************
  */ 


#include <stdio.h>
#include <stdlib.h>

#include <shunyaInterfaces.h>
#include <Wire.h>

#include <bh1750.h>


int main (void){

        int lux;
        // Uncomment the below line to put it in Infinite Loop
        //while(1) {
        lux = bh1750Read();
        printf("Light intensity = %d lux ",lux );
        //}
        return 0;
}       

