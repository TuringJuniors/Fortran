#include "smartHeater.h"
#include <iostream>

void smartWindow :: open(){
     while(distanceValue==0)
    {
        moveBackward();
    }
    
}

smartWindow :: smartWindow(controlHub* newController){
    
    controller = newController;
}

void smartWindow :: close(){
    while(distanceValue!=0)
    {
        moveFoward();
    }
    
}

void smartWindow :: ecoMode(){
    
}

void smartWindow :: getDistance(){
    std::cin >> distanceValue;
    
}

void smartWindow :: moveFoward(){
    std::cout << "motor_move_foward" << std::endl;
    
}

void smartWindow :: moveBackward(){
    std::cout << "motor_move_backward" << std::endl;
    
}