#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <shunyaInterfaces.h>
#define intPin 5
#define ledPin 3


volatile int state = 0;
volatile int loop = 0;
void abc();

int main(void) {
	shunyaInterfacesSetup();
	pinMode(ledPin,OUTPUT);
  	attachInterrupt(intPin, INT_EDGE_BOTH, abc);
	while(1) {     
		digitalWrite(ledPin, HIGH);
		delay(500);
		digitalWrite(ledPin, LOW);
		delay(500);
		printf("Loop %d \n", loop);
		loop++;
		if(loop == 10)
			exit(EXIT_SUCCESS);
	}
	return 0;
}

void abc() {
//	printf("Passed line %d in file %s\n", __LINE__, __FILE__);
	printf("State %d \n", state);
	state++;
}
