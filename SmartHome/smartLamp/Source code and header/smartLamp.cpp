#include <iostream>
#include "smartLamp.h"

using namespace std;

void smartLamp :: blink(){
    for(int x=0;x<=50;x++){
    	on();
    	off();
	}
}

void smartLamp :: on(){
    cout<<"lampOn";
}

void smartLamp :: off(){
	cout<<"lampOff";
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
