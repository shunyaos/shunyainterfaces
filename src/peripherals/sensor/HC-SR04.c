/** @file HC-SR04.c
 *  @brief This file provides the function prototypes for 
 *               Ultrasonic Sensor module HC-SR04 library.
 *
 *  @author Ayush Shrivastava
 *  @author Yogesh Hegde (yh42)
 *  @bug No known bugs.
 */

/*
 *#####################################################################
 *  Initialization block
 *  ---------------------
 *  This block contains initialization code for this particular file.
 *  It typically contains Includes, constants or global variables used
 *  throughout the file.
 *#####################################################################
 */

/* --- Standard Includes --- */
#include <stdio.h>
#include <stdlib.h>

/* --- Project Includes --- */
#include <shunyaInterfaces.h>
#include "hc-sr04.h"

static int isultraSonicSetuped = FALSE;

/*
 *#####################################################################
 *  Process block
 *  -------------
 *  This block contains all the process code for the particular layer.
 *  It typically contains internal functions and external functions 
 *  which implement the functionalities of the respective layer.
 *#####################################################################
 */

/* Initialization */
/**
 *  @brief      Setup Ultrasonic Sensor on given pins 
 *  @param      echoPin GPIO pin number connected to the echo pin
 *  @param      triggerPin GPIO pin number connected to the trigger pin
 *  @return     None
 */
void hcsr04Begin(int echoPin, int triggerPin)
{ 
        
        if (!isultraSonicSetuped) {

                pinMode(echoPin,INPUT); //Setting up pin as INPUT
                pinMode(triggerPin,OUTPUT); //Setting up pin as output
                
                isultraSonicSetuped = TRUE;
        }

}

/* Configuration */
/**
 *  @brief      Send ultrasonic pulse 
 *  @param      trigger GPIO pin number connected to the trigger pin
 *  @return     None
 */
static void ping(int trigger)
{
        //Clearing the trigger pin 
        
        digitalWrite(trigger,LOW);
        
        delayMicroseconds(2);
        //Set the trigger pin HIGH for 10 microseconds
        digitalWrite(trigger, HIGH);
        
        delayMicroseconds(10);	
        
        digitalWrite(trigger, LOW);
}


/* Computing values */
/**
 *  @brief      Calculate distance from ultrasonic Sensor
 *  @param      echo GPIO pin number connected to the echo pin
 *  @param      duration duration of the echo
 *  @return     Return duration value on SUCCESS, -1 on FAILURE  
 */
static unsigned long computePulseDuration(int echo,unsigned long duration)
{
        static unsigned long rising_time;  // time of the rising edge
        static int last_state;             // previous pin state
        
        int state = digitalRead(echo);      // current pin state

        // On rising edge: record current time.
        if (last_state == LOW && state == HIGH) { 
                //Check if the echo pin state has changed from low to high
                rising_time = micros();
                /*Obtain the instance when the change takes place
                Note: micros() returns time passed before it was invoked*/
        }

        // On falling edge: report pulse length.
        if (last_state == HIGH && state == LOW) { 
                //Check once the echo pin state changes from high to low
                unsigned long falling_time = micros();
                /*Obtain the instance when echo changes from HIGH to LOW*/
                duration = falling_time - rising_time;
                /* Once the state changes from HIGH to LOW the total time can
                 * be computed for which the pulse on echo was high.
                 * This is then used to calculate the duration using the  
                 * formula falling_time - rising time.
                 */
        }

        last_state = state;
        return duration;
}


/* Reading Raw data */
/**
 *  @brief      Get distance from ultrasonic Sensor
 *  @param      echoPin GPIO pin number connected to the echo pin
 *  @param      triggerPin GPIO pin number connected to the trigger pin
 *  @return     Return distance value on SUCCESS, -1 on FAILURE  
 */
int16_t hcsr04getDistance(int echoPin, int triggerPin)
{
        static int8_t cm = 0;
        static int doPing = 1; 
        static unsigned long duration = 0;
        
        if(doPing){
                //Transmit a sound pulse if it hasn't been already sent 
                ping(triggerPin);
                doPing = 0; //No ping to be sent until echo is obtained
        }
        
        duration = computePulseDuration(echoPin, duration);
        
        if(duration!=0){
        	cm=duration*(0.034/2);
        	/* Note: The formula is calculated assuming the speed of sound
                 * as 340 m/s or 0.034 cm/us. 
                 * t = 2*s/v or s = t * 0.034/2 (in cm)
                 */	 
        	doPing = 1;
        }

        return cm;
}

/*
 *#####################################################################
 *  Passing block
 *  -------------
 *  This block contains functions which pass the data to the next layer.
 *
 *  Note : This block is not implemented yet.
 *  Reason : Since the code for passing the data is very trivial and
 *           Creating another function just to pass the data will make 
 *           a copy of the data increasing program's memory consumption.
 *#####################################################################
 */

/**
 * @brief Wrapper for reading distance from Ultrasonic sensor 
 *
 * @param echoPin GPIO pin connected to Echo 
 * @param triggerPin GPIO pin connected to Trigger
 *
 * @return Proximity Distance in cm from the sensor  
 */
int16_t ultrasonic_dist_read(int echoPin, int triggerPin)
{

        /* Initializes the I2C device */
        if (!isultraSonicSetuped){
                hcsr04Begin(echoPin,triggerPin);    
        }

        return hcsr04getDistance(echoPin,triggerPin);

}     
        
