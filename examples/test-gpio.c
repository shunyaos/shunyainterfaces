#include <shunyaInterfaces.h>
#include <stdio.h>
#include <stdlib.h>
#define GPIOpin 26

int main() {
	shunyaInterfacesSetup();
	pinMode(GPIOpin, INPUT);
	while(1) {
		int x = digitalRead(GPIOpin);
		printf("value: %d\n", x);
		delay(100);
	}
	return 0;
}
