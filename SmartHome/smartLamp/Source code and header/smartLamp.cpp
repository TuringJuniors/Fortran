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

void getInputHub()
{
    int input;
    cin >> input; //from control hub
    if (input == 0)
    {
        
    }

    else if (input == 1)
    {
        state = 0;
    }
    else if (input == 2)
    {
        state = 1;
    }
    else if (input == 3)
    {
        state = 2;
    }
}

smartLamp :: smartLamp(controlHub* newController){
    
    controller = newController;
}
