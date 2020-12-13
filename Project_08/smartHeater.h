#include <iostream>
using namespace std;


#ifndef SMART_HEATER
#define SMART_HEATER

class controlHub;
class smartHeater
{
    public:
     
    void on();
    
    smartHeater(controlHub* newController);
    
    private:
    
    controlHub* controller;
    
};

#endif