#include "smartWindow.h"
#include <iostream>

void smartWindow::open() {
    while (distanceValue == 0)
    {
        moveBackward();
    }

}

smartWindow::smartWindow(controlHub* newController) {

    controller = newController;
}

void smartWindow::close() {
    while (distanceValue != 0)
    {
        moveFoward();
    }

}

void smartWindow::ecoMode() {

}

void smartWindow::getDistance() {
    std::cin >> distanceValue;

}

void smartWindow::moveFoward() {
    std::cout << "motor_move_foward" << std::endl;

}

void smartWindow::moveBackward() {
    std::cout << "motor_move_backward" << std::endl;

}

void smartWindow::getInputControlHub() {
    int input;
    std::cin >> input;
    if (input == 1)
    {
        thiefDetected = true;
    }
    else if (input == 2)
    {
        smokeDetected = true;
    }
    else if (input == 3)
    {
        state = 0; //idlestate
    }

    if(thiefDetected==true)
    {
        state = 1;
    }

    else if (smokeDetected == true)
    {
        state = 2;
    }

}