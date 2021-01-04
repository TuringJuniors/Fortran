#include <iostream>
using namespace std;


#ifndef SMART_ALARM
#define SMART_ALARM

class controlHub;
class smartAlarm
{
    public:
    
    bool thiefDetected;
    
    void ring();
    
    smartAlarm(controlHub* newController);
    
    private:
    
    controlHub* controller;
};

#endif