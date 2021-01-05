#include <Wire.h> //communication using i2c protocol
using namespace std;

#define NUM_THREADS 2 
#define IDLE_STATE 0
#define SLEEP_STATE 1
#define OFF_STATE 2

#define temperatureSensorPin A0
#define heaterPin 6


int inputCode;  //where the code should be store
int inputValue;  //store any value from application and control hub

class controlHub {};
class smartHeater
{
public:
    smartHeater(controlHub* newController);
    int state = 0;
    double detectTemperature();

    void getInputApp();  //get input from application
    void getInputHub();  //get input from control hub

    void setIdleTemperature(double temp);
    void setSleepTemperature(double temp);

    double currentTemperature = 0;
    double runningTemperature = 0;      //temperature need to be mantained
    double idleTemperature = 0;         //default temperature set by owner
    double sleepTemperature = 0;        //temperature on sleep mode is on 
    const double ecoTemperature = 20.0;   // room temperature. used to reduce energy conservation

    void on();
    void off();
    void startHeating();
    void stopHeating();

    bool heating = false;                  // heater status. either heating or cooling(stop heating) 

    void sleepMode();
    void idleMode(void);
    void ecoMode();
private:

    controlHub* controller;
};

smartHeater::smartHeater(controlHub* newController)
{
    controller = newController;
}
double smartHeater::detectTemperature()
{
    currentTemperature = digitalRead(temperatureSensorPin);     // get input from temperature sensor
    //here is the space for translating the input to temperature value
    return currentTemperature;
}


void smartHeater::setIdleTemperature(double temp)
{
    idleTemperature = temp;
}
void smartHeater::setSleepTemperature(double temp)
{
    sleepTemperature = temp;
}
void smartHeater::startHeating()
{
    digitalWrite(heaterPin, HIGH);  //turn on heater
}
void smartHeater::stopHeating()
{
    digitalWrite(heaterPin, LOW);              //turn off heater
}
void smartHeater::sleepMode()
{
    runningTemperature = sleepTemperature;
}
void smartHeater::idleMode(void)
{
    runningTemperature = idleTemperature;
}
void smartHeater::ecoMode()
{
    runningTemperature = ecoTemperature;
}
void smartHeater::on()
{
    state = 0; // start the smart heater in idle state
}
void smartHeater::off()
{
    runningTemperature = -100;
}

controlHub mainController;
smartHeater heater1(&mainController);

void setup()
{
    Wire.begin(4); //heater adress is 4
    Wire.onRequest(output);
    Wire.onReceive(input);
    Serial.begin(9600);
    pinMode(heaterPin, OUTPUT);
    pinMode(temperatureSensorPin,INPUT);
}

//void* UPDATE(void* threadid)  replaced as interupt
void input(int howMany)
{
    if (Wire.available())
    {
        inputCode = Wire.read();
    }
    if (Wire.available())
    {
        inputValue = Wire.read();
    }

    //void smartHeater::getInputApp()
    if (inputCode == 0)  //code-0 -> do nothing
    {
    }
    else if (inputCode == 1)  //code-1 -> to set idle temperature
    {
        heater1.setIdleTemperature(inputValue);
    }
    else if (inputCode == 2) //code-2 -> to set sleep temperature
    {
        heater1.setSleepTemperature(inputValue);
    }
    else if (inputCode == 3) //code-3 -> to change the state to idle state
    {
        heater1.state = 0;//idle state
    }
    else if (inputCode == 4) //code-4 -> to change the state to sleep state
    {
        heater1.state = 1;//sleep state
    }

    //void smartHeater::getInputHub()
    if (inputCode == 5)  //code-0 -> do nothing
    {
    }
    else if (inputCode == 6)  //code-1 -> on the smartHeater
    {
        heater1.state = 0; //start the smart heater in idle state
    }
    else if (inputCode == 7)  //code-1 -> on the smartHeater
    {
        heater1.state = 2; //turn off the heater
    }

}
void output()
{

}

//void* ON(void* threadid) as viod loop()
void loop()
{
    while (1)
    {
        switch (heater1.state)
        {
        case IDLE_STATE:
            heater1.idleMode();
            break;
        case SLEEP_STATE:
            heater1.sleepMode();
            break;
        case OFF_STATE:
            heater1.off();
            break;
        }

        heater1.detectTemperature();
        if (heater1.currentTemperature <= heater1.runningTemperature)
        {
            heater1.startHeating();
        }
        if (heater1.currentTemperature >= heater1.runningTemperature)
        {
            heater1.stopHeating();
        }
    }
}
