#include <Wire.h> //communication using i2c


#define idleMode 0
#define thiefMode 1
#define smokeMode 2
#define buzzerPIN 5
#define smokeSensorPIN A5


class controlHub {};
class smartAlarm
{
public:
    
    bool thiefDetected = 0;
    int MODE = 0; //music
    int state = 0;
    void ring();

    void on();

    double volume = 0;
    double emergencyVolume=255;
    double alarmVolume = 0;

    void setAlarm(int MODE, double volume, double time);
    
    smartAlarm(controlHub* newController);
    
private:
    
    controlHub* controller;
};


controlHub mainController;
smartAlarm alarm1(&mainController);

void smartAlarm :: ring()
{
    volume = emergencyVolume;
    on();
}

void smartAlarm :: on()
{
    pinMode(buzzerPIN, HIGH); //output to bell
}





void smartAlarm :: setAlarm(int mode, double Volume, double times)
{
    MODE = mode;
    alarmVolume = Volume;
}

smartAlarm :: smartAlarm(controlHub* newController){
    
    controller = newController;
}

int inputCode;
int inputValue;

void input (int A)
{
  if (Wire.available())
  {
    inputCode = Wire.read();
  }

  if(Wire.available())
  {
    inputValue = Wire.read();
  }

  if (inputCode == 0)
    {
        
    }
    
    else if (inputCode == 1)
    {
        alarm1.ring();
    }
    
    else if (inputCode == 3)
    {
        alarm1.thiefDetected = true;
    }
    else if (inputCode == 4)
    {
        alarm1.state = 0;
    }
    else if (inputCode == 5)
    {
        alarm1.state = 1;
    }
    else if (inputCode == 6)
    {
        alarm1.state = 2;
    }
}



























void setup() 
{
  Wire.begin(3); //alarm address is 3
  Wire.onReceive(input);
  pinMode(buzzerPIN, OUTPUT);
  pinMode(smokeSensorPIN, INPUT);

}

void loop() 
{
  switch (alarm1.state) 
  {
  case idleMode:
    while (alarm1.state == idleMode) 
    {
     
      break;
    }

  case thiefMode:
    while (alarm1.state == thiefMode) 
    {
     
      alarm1.ring();
    
      break;
    }
  case smokeMode:
    while (alarm1.state == smokeMode) 
    {
     
      alarm1.ring();
    
      break;
    }
  }

}
