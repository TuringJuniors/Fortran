#include <iostream>
using namespace std;


#ifndef SMART_WINDOW
#define SMART_WINDOW

class controlHub;
class smartWindow
{
public:

    void open();
    void close();
    void ecoMode();
    void getDistance();
    void moveFoward();
    void moveBackward();
    void getInputControlHub();
    double distanceValue;
    bool thiefDetected;
    bool smokeDetected;
    int state;
    int maxDistance = 500;




    smartWindow(controlHub* newController);

private:

    controlHub* controller;

};

#endif