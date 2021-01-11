#include <Wire.h>
#define ON 0
#define OFF 1
#define BLINK 2

#define LED 7

 

  
class controlHub{
  
};
class smartLamp
{
    public:
    
    smartLamp(controlHub* newController);
    
    
    int state=1;
    
    void blink();
    
    void on();
    
    void off();
    
   
    
    private:
    
    controlHub* controller;
};

 controlHub mainController;
  smartLamp lamp1(&mainController);

  
void smartLamp :: blink(){
    double starttime=millis();
    while((millis()-starttime)<=50000){
      on();
      delay(1000);
      off();
      delay(1000);
    }
  
}

void smartLamp :: on(){
    digitalWrite(LED,HIGH);
}

void smartLamp :: off(){
  digitalWrite(LED,LOW);
} 

void InputHub(int a)
{
    int input;
    if(Wire.available())
    {
      input=Wire.read();
    }
  int buff=Wire.read();
     
    if (input == 0)
    {
        
    }

    else if (input == 1)
    {
        lamp1.state = 0;
    }
    else if (input == 2)
    {
        lamp1.state = 1;
    }
    else if (input == 3)
    {
        lamp1.state = 2;
    }
}

smartLamp :: smartLamp(controlHub* newController){
    
    controller = newController;
}

void setup() {
 
Wire.begin(1);
Wire.onReceive(InputHub);
pinMode(LED,OUTPUT);
  Serial.begin(9600);

}

void loop() {

  
  switch (lamp1.state){
    
    case ON:
    lamp1.on();
    break;
    
    case OFF:
    lamp1.off();
    break;
    
    case BLINK:
    lamp1.blink();
    break;
  }
  
  
}
