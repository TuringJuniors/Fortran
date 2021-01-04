#include <iostream>
#include "smartLamp.h"
using namespace std;

#define ON 0
#define OFF 1
#define BLINK 2




int main(){
	
	controlHub mainController;
	smartLamp lamp1(&mainController);
	
	switch(lamp1.state){
		case ON:
			while(lamp1.state==ON){
			lamp1.getInputControlHub();
			lamp1.on();
			break;	
			}
		
		case OFF:
			while(lamp1.state==OFF){
				lamp1.getInputControlHub();
				lamp1.off();
				break;
			}
			
		case BLINK:
			while(lamp1.state==BLINK){
				lamp1.getInputControlHub();
				blink();
				break;
			}
	}
	
}
