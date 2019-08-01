#include<stdio.h>
#include<stdlib.h>

#include<shunyaInterfaces.h>
#include<pcf8591.h>

int main()
{
	shunyaInterfacesSetup();
	pcf8591Setup();

        while(1){
        	int output;
        	output= pcf8591Read(A1);
        	printf("moisture = %d \n",output);
        	delay(1000);
        }

        return 0;
	
}

