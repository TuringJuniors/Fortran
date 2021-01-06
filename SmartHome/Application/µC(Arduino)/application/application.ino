#include <Wire.h>

//interaction state
#define CONTROL_HUB 0
#define SMART_HEATER 1

#define SMART_HEATER_ADDRESS 4
#define SMART_DOOR_ADDRESS 5
#define SMART_ALARM_ADDRESS 6
#define SMART_LAMP_ADDRESS 7
#define SMART_WINDOW_ADDRESS 8


int inputDevice = 0;
int inputAction = 0;
int output[2];
double value;
bool response;

void controlHubAction();
void smartHeaterAction();

class application
{
public:

    bool userResponse;
    void notify(bool thiefDetected);
    bool waitUserResponse();
    void emergencyCall();

    //to communicate with smart heater
    void HeatersetIdleTemperature();
    void HeatersetSleepTemperature();
    void Heateron();
    void Heateroff();
    void HeatersleepMode();
    void HeateridleMode();
    void HeaterecoMode();
};


void application::notify(bool thiefDetected)
{
    if (thiefDetected)
    {
        Serial.println("thief detected\n");
    }
}
bool application::waitUserResponse()
{
    Serial.println("is this your member?\n");
    
    if (Serial.available() > 0)
    {
        response = Serial.read();
        response -= '0';
    }

    return response;
}
void application::emergencyCall()
{
    Serial.println("creating emergency call\n");
}

//i2c communication protocol

void wireCommunicationOuput()
{
    int address = output[0];
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
    Wire.requestFrom(output[0], 1);
    if (Wire.available())
    {
        value = Wire.read();
    }
}

void application::HeatersetIdleTemperature()
{
    output[0] = SMART_HEATER_ADDRESS;
    output[1] = 1;//code to set idle temperature in heater
    Serial.println("Value for idle temperature :");
    if (Serial.available() > 0)
    {
        value = Serial.read();
        value -= '0';
    }
    wireCommunicationOuput();

}
void application::HeatersetSleepTemperature()
{
    output[0] = SMART_HEATER_ADDRESS;
    output[1] = 2;//code to set sleep temperature in heater
    Serial.println("Value for sleep temperature :");
    if (Serial.available() > 0)
    {
        value = Serial.read();
        value -= '0';
    }
    

    wireCommunicationOuput();
}
void application::Heateron()
{
    output[0] = SMART_HEATER_ADDRESS;
    output[1] = 3;//code to on heater (start with idle mode)
    value = 0;//no value needed
    wireCommunicationOuput();
}
void application::Heateroff()
{
    output[0] = SMART_HEATER_ADDRESS;
    output[1] = 7;//code to off heater (stop heating)
    value = 0;//no value needed
    wireCommunicationOuput();
}
void application::HeatersleepMode()
{
    output[0] = SMART_HEATER_ADDRESS;
    output[1] = 4;//code to change heater state to sleep mode
    value = 0;//no value needed
    wireCommunicationOuput();
}
void application::HeateridleMode(void)
{
    output[0] = SMART_HEATER_ADDRESS;
    output[1] = 3;//code to change heater state to idle mode
    value = 0;//no value needed
    wireCommunicationOuput();
}
void application::HeaterecoMode()
{
    output[0] = SMART_HEATER_ADDRESS;
    output[1] = 8;//code to change heater state to eco mode
    value = 0;//no value needed
    wireCommunicationOuput();
}


application app1;

void controlHubAction()
{
    //what to do to control hub
}
void smartHeaterAction()
{
    //what to do to smart heater
    Serial.println("code action :");
    Serial.println("set idle temperature 1");
    Serial.println("set sleep temperature 2");
    Serial.println("on 3");
    Serial.println("off 4");
    Serial.println("sleep mode 5");
    Serial.println("idle mode 6");
    Serial.println("eco mode 7");

    Serial.println("");
    Serial.print("action :");
    delay(1000);
    if (Serial.available() > 0)
    {
        inputAction = Serial.read();
        inputAction -= '0';
    }

  

    switch (inputAction)
    {
    case 0:
        break;
    case 1:
        app1.HeatersetIdleTemperature();
        break;
    case 2:
        app1.HeatersetSleepTemperature();
        break;
    case 3:
        app1.Heateron();
        break;
    case 4:
        app1.Heateroff();
        break;
    case 5:
        app1.HeatersleepMode();
        break;
    case 6:
        app1.HeateridleMode();
        break;
    case 7:
        app1.HeaterecoMode();
        break;
    }
}
void setup()
{
    Wire.begin();
    Serial.begin(9600);
}
void loop()
{
    
    delayMicroseconds(100);
    Serial.println("");
    Serial.println("code for devices :");
    Serial.println("");
    Serial.println("control hub 0");
    Serial.println("smart heater 1");
    Serial.println("");
    Serial.print("communicate with :");
    while (Serial.available() > 0)
    {
      
        inputDevice = Serial.read();
        inputDevice -= '0';
    }
  delay(1000);


    switch (inputDevice)
    {
    case CONTROL_HUB:
        controlHubAction();
        break;
    case SMART_HEATER:
        smartHeaterAction();
        break;
    }

}
