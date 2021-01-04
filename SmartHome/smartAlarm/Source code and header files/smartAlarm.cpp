#include "smartAlarm.h"
#include <iostream>


void ring()
{
    volume = emergencyVolume;
    on();
}

void on()
{
    cout << "ON";
}

void getInputHub()
{
    int input;
    cin >> input;
    if (input == 0)
    {
        
    }
    int input;
    cin >> input;
    else if (input == 1)
    {
        ring();
    }
    int input;
    cin >> input;
    else if (input == 2)
    {
        setAlarm(int mode, double Volume, double time);
        cin >> mode;
        cin >> volume;
        cin >> time;
    }
    else if (input == 3)
    {
        theifDetected = true;
    }
    else if (input == 4)
    {
        state = 0;
    }
    else if (input == 5)
    {
        state = 1;
    else if (input == 6)
    {
        state = 2;

    }
    }
}

void setAlarm(int mode, double Volume, double time)
{
    MODE = mode;
    alarmVolume = Volume;
}

smartAlarm :: smartAlarm(controlHub* newController){
    
    controller = newController;
}