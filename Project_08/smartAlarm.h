#include <iostream>
using namespace std;


#ifndef SMART_ALARM
#define SMART_ALARM

class controllHub;
class smartAlarm
{
    public:
    
    bool thiefDetected;
    
    void ring();
    
    smartAlarm(controllHub* newController);
    
    private:
    
    controllHub controller;
};

#endif