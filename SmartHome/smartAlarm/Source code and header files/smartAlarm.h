#include <iostream>
using namespace std;


#ifndef SMART_ALARM
#define SMART_ALARM

class controlHub;
class smartAlarm
{
public:
    
    bool thiefDetected;
    int MODE; //music
    int state;
    void ring();

    void on();

    double volume;
    double emergencyVolume=255;
    double alarmVolume;

    void getInputHub();
    void setAlarm(int MODE,double volume, double time);
    
    smartAlarm(controlHub* newController);
    
private:
    
    controlHub* controller;
};

#endif