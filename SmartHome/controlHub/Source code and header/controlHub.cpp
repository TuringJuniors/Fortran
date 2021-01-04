#include <iostream>
#include "controlHub.h"
using namespace std;




//to communicate with smart heater
void controlHub::Heateron()
{
    cout << "set heater to " << "on" << endl;   // send code to heater to turn on the heater
}

//to communicate with application
void controlHub::Applicationnotify(int code)
{
    cout << "thief detected" ; //output to application
}
bool controlHub::ApplicationwaitUserResponse()
{
    int response;
    cin >> response;   //input from application(by user)
    return response;
}
void controlHub::ApplicationemergencyCall()
{
    cout << "emergency call"; // output tu application
}

//to communicate with smart door
void controlHub::Doorunlock()
{
    cout << "door lock"; //to lock door(output to door)
}
bool controlHub::DoorcheckFirstPerson()
{
    bool result;
    cin >> result; //input from door to check either the person that come in is the first person
    return result;
}

//to communicate with smart Alarm
void controlHub::Alarmring() 
{
    cout << "ring alarm";// to ring the alarm(output to smart alarm)
}

//to communicate with smart lamp
void controlHub::Lampblink()
{
    cout << "blink lamp";// to blink the lamp(output to smart lamp)
}
void controlHub::Lampon()
{
    cout << "lamp on";// to on the lamp(output to smart lamp)
}

//to communicate with smart window
void controlHub::Windowclose()
{
    cout << "rwindow close";// to close the lamp(output to smart window)
}
