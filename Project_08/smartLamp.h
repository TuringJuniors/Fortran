#include <iostream>
using namespace std;


#ifndef SMART_LAMP
#define SMART_LAMP

class controlHub;
class smartLamp
{
    public:
    
    bool thiefDetected;
    
    void blink();
    
    void on();
    
    smartLamp(controlHub* newController);
    
    private:
    
    controlHub* controller;
};

#endif