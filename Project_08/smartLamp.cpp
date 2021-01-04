#include "smartLamp.h"
#include <iostream>

void smartLamp :: blink(){
    while(1){
    	on();
    	off();
	}
}

void smartLamp :: on(){
    cout<<lampOn;
}

void smartLamp :: off(){
	cout<<lampOff;
} 

smartLamp :: smartLamp(controlHub* newController){
    
    controller = newController;
}
