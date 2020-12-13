#include <iostream>
using namespace std;


#ifndef SMART_LAMP
#define SMART_LAMP

class contolHub;
class smartLamp
{
    public:
    
    bool thiefDetected;
    bool on;
    
    void blink();
    
    void on();
    
    smartLamp(contolHub* newController);
    
    private:
    
    controlHub controller;
};

#endif