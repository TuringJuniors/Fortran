#include <Wire.h>

#define MEMBER_ENTERING 1
#define THIEF_DETECTED 0
#define IDLE_STATE 2

#define APPLICATION_ADDRESS 3
#define SMART_HEATER_ADDRESS 4
#define SMART_DOOR_ADDRESS 5
#define SMART_ALARM_ADDRESS 6
#define SMART_LAMP_ADDRESS 4
#define SMART_WINDOW_ADDRESS 4

int output[2]; //{adress,code,value //i2c
double value;
int serialComunicationInput;
int serialComunicationOutput;
int state=2;//start with idle state

void wireCommunicationOuput();
int wireCommunicationInput();

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
    value = 0;//no value needed
    wireCommunicationOuput();
}

//to communicate with application
void controlHub::Applicationnotify(int code)
{
    if(code==1); // code to notify the user
  {
    Serial.println(" Thief detected ");  //print on application using UART protocol
  }
}
bool controlHub::ApplicationwaitUserResponse()
{
    bool response = false;
    Serial.println("\n thief? (no-> 1, yes-> 0) : "); //print on application using UART protocol
    while(!Serial.available()){}
    response = (bool)Serial.parseInt();   //input from application(by user) using UART protocol
    delayMicroseconds(10);
    return response;
}
void controlHub::ApplicationemergencyCall()
{
    Serial.println("\n creating emergency call "); //print on application using UART protocol
}

//to communicate with smart door
void controlHub::Doorunlock()
{
    output[0] = SMART_DOOR_ADDRESS;//door address
    output[1] = 0;//to lock door(output to door)
    value = 0;
    wireCommunicationOuput();
}
bool controlHub::DoorcheckFirstPerson()
{
    bool firstPerson = 0;
    output[0] = SMART_DOOR_ADDRESS;//door address
    output[1] = 0;//code to request input from door to check either the person that come in is the first person 
    value = 0;//value recieved
    
    wireCommunicationInput();
    if ((int)value)
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
    output[1] = 0;//code to request input from door to check either there is thief or not
    value = 0;//value recieved
    
    wireCommunicationInput();
    
    if ((int)value!=1)
    {
        state = THIEF_DETECTED;
    }
    else
    {
        state = state;
    }
}

//to communicate with smart Alarm
void controlHub::Alarmring()
{
    output[0] = SMART_ALARM_ADDRESS;//alarm address
    output[1] = 0;// to ring the alarm(output to smart alarm)
    value = 0;
    wireCommunicationOuput();
}

//to communicate with smart lamp
void controlHub::Lampblink()
{
    output[0] = SMART_LAMP_ADDRESS;//lamp address 
    output[1] = 0;// to blink the lamp(output to smart lamp)
    value = 0;
    wireCommunicationOuput();
}
void controlHub::Lampon()
{
    output[0] = SMART_LAMP_ADDRESS;//lamp address
    output[1] = 0;// to on the lamp(output to smart lamp)
    value = 0;
    wireCommunicationOuput();
}

//to communicate with smart window
void controlHub::Windowclose()
{
    output[0] = SMART_WINDOW_ADDRESS;//windows address
    output[1] = 0;// to close the lamp(output to smart window)
    value = 0;
    wireCommunicationOuput();
}


void wireCommunicationOuput()
{
  int address=output[0];
  Wire.beginTransmission(address);
  Wire.write(output[1]);
  Wire.write((int)value);
  Wire.endTransmission();
}
int wireCommunicationInput()
{
  Wire.beginTransmission(output[0]);
  Wire.write(output[1]);
  Wire.endTransmission();
  delay(10);
  Wire.requestFrom(output[0],1);
  if(Wire.available())
  {
    value=Wire.parseInt();
  }
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
            state=MEMBER_ENTERING;
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
   case IDLE_STATE:
      //controller1.Heateroff();
      //controller1.Heateron();
        break;
    }
}
