#include "smartAlarm.h"
#include <iostream>


void ring()
{
    volume = emergencyVolume;
    on();
}

void on()
{
    cout << "ON"; //output to bell
}

void getInputHub()
{
    int input;
    cin >> input; //from control hub
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
    }
    else if (input == 6)
    {
        state = 2;
    }
}

    void getInputApp()
    {
        int input;
        cin >> input; //from app
        if (input == 0)
        {

        }

        else if (input == 2)
        {
            setAlarm(int mode, double Volume, double time);
            cin >> mode;  //from app
            cin >> volume;  //from app
            cin >> time;  //from app
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