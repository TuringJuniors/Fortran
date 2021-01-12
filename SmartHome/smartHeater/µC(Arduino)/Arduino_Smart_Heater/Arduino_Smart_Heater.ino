#include <Wire.h> //communication using i2c protocol

#define IDLE_STATE 0
#define SLEEP_STATE 1
#define OFF_STATE 2

#define temperatureSensorPin A0
#define heaterPin 6


short int inputCode;  //where the code should be store
int inputValue;  //store any value from application and control hub

class controlHub {};
class smartHeater
{
public:
    smartHeater(controlHub* newController);
    int state = 2;
    double detectTemperature();

    void getInputApp();  //get input from application
    void getInputHub();  //get input from control hub

    void setIdleTemperature(double temp);
    void setSleepTemperature(double temp);

    double currentTemperature = 0;
    double runningTemperature = 0 ;   //temperature need to be mantained
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
    int sensorValue = digitalRead(temperatureSensorPin);     // get input from temperature sensor
    //translating the input to temperature value
      sensorValue = analogRead(A0);    //read the analog sensor and store it
  currentTemperature = (double)sensorValue / 1024;       //find percentage of input reading
  currentTemperature = currentTemperature * 5;                 //multiply by 5V to get voltage
  currentTemperature = currentTemperature - 0.5;               //Subtract the offset 
  currentTemperature = currentTemperature * 100;               //Convert to degrees 
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
    Wire.begin(4); //heater addess is 4
    Wire.onRequest(output);
    Wire.onReceive(input);
    Serial.begin(9600);
    pinMode(heaterPin, OUTPUT);
    pinMode(temperatureSensorPin, INPUT);
}

//void* UPDATE(void* threadid)  replaced as interupt
void input(int howMany)
{
    Serial.print("\nreceive input : ");
    if (Wire.available())
    {
        inputCode = Wire.read();
    }
    while (Wire.available())
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
        //***************test purpose**************//
        //Serial.print("idle temperature set to ");
        //Serial.print(heater1.idleTemperature);
        //Serial.println("");
    }
    else if (inputCode == 2) //code-2 -> to set sleep temperature
    {
        heater1.setSleepTemperature(inputValue);
        //***************test purpose**************//
        //Serial.print("sleep temperature set to ");
        //Serial.print(heater1.sleepTemperature);
        //Serial.println("");
        //Serial.print(heater1.runningTemperature);
        //Serial.println("");
    }
    else if (inputCode == 3) //code-3 -> to change the state to idle state
    {
        heater1.state = 0;//idle state
        //***************test purpose**************//
        //Serial.print("heater state change to  ");
        //Serial.print(heater1.state);
        //Serial.println("");
    }
    else if (inputCode == 4) //code-4 -> to change the state to sleep state
    {
        heater1.state = 1;//sleep state
        //***************test purpose**************//
        //Serial.print("heater state change to  ");
        //Serial.print(heater1.state);
        //Serial.println("");
    }

    //void smartHeater::getInputHub()
    if (inputCode == 5)  //code-0 -> do nothing
    {
    }
    else if (inputCode == 6)  //code-1 -> on the smartHeater
    {
        heater1.state = 0; //start the smart heater in idle state
        //***************test purpose**************//
        //Serial.print("heater state change to  ");
        //Serial.print(heater1.state);
        //Serial.println("");
    }
    else if (inputCode == 7)  //code-1 -> on the smartHeater
    {
        heater1.state = 2; //turn off the heater
        //***************test purpose**************//
        //Serial.print("heater state change to  ");
        //Serial.print(heater1.state);
        //Serial.println("");
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
          //pinMode(6,HIGH);
          //***************test purpose**************//
          //Serial.print("idle state");
           heater1.idleMode();
            break;
        case SLEEP_STATE:
          //***************test purpose**************//
          //Serial.print("sleep state");
            heater1.sleepMode();
            break;
        case OFF_STATE:
          //***************test purpose**************//
          //Serial.print("off state");
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
