#include <Wire.h>

#define MEMBER_ENTERING 1
#define THIEF_DETECTED 0

#define APPLICATION_ADDRESS 3
#define SMART_HEATER_ADDRESS 4
#define SMART_DOOR_ADDRESS 5
#define SMART_ALARM_ADDRESS 6
#define SMART_LAMP_ADDRESS 4
#define SMART_WINDOW_ADDRESS 4

long output[3]; //{adress,code,value //i2c
int serialComunicationInput;
int serialComunicationOutput;
int state;

class controlHub
{
public:
    //to communicate with smart heater
    void Heateron();
    //to communicate with application
    void Applicationnotify(int code);
    bool ApplicationwaitUserResponse();
    void ApplicationemergencyCall();
    //to communicate with smart door
    void Doorunlock();
    bool DoorcheckFirstPerson();
    bool DoorcheckThief();
    //to communicate with smart Alarm
    void Alarmring();
    //to communicate with smart lamp
    void Lampblink();
    void Lampon();
    //to communicate with smart window
    void Windowclose();


};

//to communicate with smart heater
void controlHub::Heateron()
{
    output[0] = SMART_HEATER_ADDRESS; //heater address
    output[1] = 6; //code to turn on the heater
    output[2] = 0; //no value needed
}

//to communicate with application
void controlHub::Applicationnotify(int code)
{
    Serial.write(code); // code to notify the user
}
bool controlHub::ApplicationwaitUserResponse()
{
    bool response = false;
    response = (bool)Serial.read();   //input from application(by user)
    delayMicroseconds(10);
    return response;
}
void controlHub::ApplicationemergencyCall()
{
    Serial.write(0); // code for emergency call by application
}

//to communicate with smart door
void controlHub::Doorunlock()
{
    output[0] = SMART_DOOR_ADDRESS;//door address
    output[1] = 0;//to lock door(output to door)
    output[2] = 0;
}
bool controlHub::DoorcheckFirstPerson()
{
    bool firstPerson = 0;
    output[0] = SMART_DOOR_ADDRESS;//door address
    output[1] = 0;//input from door to check either the person that come in is the first person
    output[2] = 0;
    Wire.requestFrom(SMART_DOOR_ADDRESS, 1);
    while (Wire.available())
    {
        firstPerson = (bool)Wire.read();
    }
    if (firstPerson)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool controlHub::DoorcheckThief()
{
    bool thief = 0;
    output[0] = SMART_DOOR_ADDRESS;//door address
    output[1] = 0;//input from door to check either the person that come in is the first person
    output[2] = 0;
    delayMicroseconds(10);
    Wire.requestFrom(SMART_DOOR_ADDRESS, 1);
    while (Wire.available())
    {
        thief = (bool)Wire.read();
    }
    if (thief)
    {
        state = THIEF_DETECTED;
    }
    else
    {
        state = MEMBER_ENTERING;
    }
}

//to communicate with smart Alarm
void controlHub::Alarmring()
{
    output[0] = SMART_ALARM_ADDRESS;//alarm address
    output[1] = 0;// to ring the alarm(output to smart alarm)
    output[2] = 0;
}

//to communicate with smart lamp
void controlHub::Lampblink()
{
    output[0] = SMART_LAMP_ADDRESS;//lamp address 
    output[1] = 0;// to blink the lamp(output to smart lamp)
    output[2] = 0;
}
void controlHub::Lampon()
{
    output[0] = SMART_LAMP_ADDRESS;//lamp address
    output[1] = 0;// to on the lamp(output to smart lamp)
    output[2] = 0;
}

//to communicate with smart window
void controlHub::Windowclose()
{
    output[0] = SMART_WINDOW_ADDRESS;//windows address
    output[1] = 0;// to close the lamp(output to smart window)
    output[2] = 0;
}


void setup()
{
    Wire.begin();
    Serial.begin(9600);
}


void loop()
{
    controlHub controller1;
    controller1.DoorcheckThief();
    bool response=false;

    switch (state)
    {
    case THIEF_DETECTED:
        controller1.Applicationnotify(1);// 1 means thief detected
        response= controller1.ApplicationwaitUserResponse();
        if (response == true)
        {
            controller1.Doorunlock();
            break;
        }
        else if (response == false)
        {
            controller1.ApplicationemergencyCall();
            controller1.Alarmring();
            controller1.Lampblink();
            controller1.Windowclose();
            break;
        }
        break;
        
    case MEMBER_ENTERING:
        controller1.Doorunlock();
        if (controller1.DoorcheckFirstPerson() == true)
        {
            controller1.Heateron();
            controller1.Lampon();
        }
        break;
    }
}
