#include "smartWindow.h"
#include <iostream>
using namespace std;

void smartWindow::open() {
    getDistance();
    while (distanceValue!= maxDistance)
    {
        getDistance();
        moveBackward();
    }

}

smartWindow::smartWindow(controlHub* newController) {

    controller = newController;
}

void smartWindow::close() {
    getDistance();
    while (distanceValue != 0)
    {
        getDistance();
        moveForward();
    }

}


void smartWindow::getDistance() {
    cin >> distanceValue;
    

}

void smartWindow::moveForward() {
    cout << "motor_move_foward" << std::endl;

}

void smartWindow::moveBackward() {
    cout << "motor_move_backward" << std::endl;

}

void smartWindow::getInputControlHub() {
    int input;
    cin >> input;
    if (input == 1)
    {
        thiefDetected = true;
    }
    if (input == 2)
    {
        smokeDetected = true;
    }
     if (input == 3)
    {
        
        state = 0; //idlestate
    }

    if (input == 4)
    {
      
        state = 1;//thiefDetected
    }

    else if (input == 5)
    {
        state = 2;//smokeDetected
    }

}