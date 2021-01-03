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
    double distanceValue;
    bool thiefDetected;
	

    
    smartWindow(controlHub* newController);
    
    private:
    
    controlHub* controller;
    
};

#endif