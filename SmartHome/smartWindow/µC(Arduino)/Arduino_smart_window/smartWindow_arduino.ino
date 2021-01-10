#include <Wire.h>
#define idleState 0
#define thiefDetect 1
#define smokeDetect 2

#define motorForwardPin 3
#define motorBackwardPin 8
#define trigPin 4
#define echoPin 2




class controlHub{};
class smartWindow
{
public:

    void open();
    void close();
    void ecoMode();
    void getDistance();
    void moveForward();
    void moveBackward();
    double distanceValue =0;
    bool thiefDetected =0;
    bool smokeDetected =0;
    int state =0;
    int maxDistance = 500;




    smartWindow(controlHub* newController);

private:

    controlHub* controller;

};

controlHub mainController;
smartWindow window1(&mainController);




void smartWindow::open() {
    getDistance();
    while (distanceValue!= maxDistance)
    {
      getDistance();
      moveBackward();
    }

}

smartWindow::smartWindow(controlHub* newController) {

    controller = newController;
}

void smartWindow::close() {
    getDistance();
    while (distanceValue != 0)
    {
      getDistance();
      moveForward();
    }

}


void smartWindow::getDistance() {
    double duration;

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    duration = pulseIn(echoPin,HIGH);
    distanceValue =duration * 0.034/2;
    
    

}

void smartWindow::moveForward() {
    digitalWrite(motorForwardPin, HIGH);
    delay(3000); //3second delay
    digitalWrite(motorForwardPin, LOW);
    

}

void smartWindow::moveBackward() {

    digitalWrite(motorBackwardPin, HIGH);
    delay(3000); //3second delay
    digitalWrite(motorBackwardPin, LOW);

}

void InputHub(int a) {
    int input;
    if(Wire.available())
    {
      input=Wire.read();
    }

    
    if (input == 1)
    {
        window1.thiefDetected = true;
    }
    if (input == 2)
    {
        window1.smokeDetected = true;
    }
     if (input == 3)
    {
        
        window1.state = 0; //idlestate
    }

    if (input == 4)
    {
      
        window1.state = 1;//thiefDetected
    }

    else if (input == 5)
    {
        window1.state = 2;//smokeDetected
    }

}



void setup() {
  Wire.begin(2);
  Wire.onReceive(InputHub);
  pinMode(motorForwardPin, OUTPUT);
  pinMode(motorBackwardPin, OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  

}

void loop() {
    switch (window1.state) {
  case idleState:
    while (window1.state == idleState) {
      
    break;
    }

  case thiefDetect:
    while (window1.state == window1.thiefDetected) {
      

      while (window1.distanceValue!= 0)
      {
        window1.getDistance();
        window1.moveForward();
      }
      break;
    }
  case smokeDetect:
    while (window1.state == window1.smokeDetected) {
      

      while(window1.distanceValue!=window1.maxDistance)
      {
        window1.getDistance();
        window1.moveBackward();
      }
      break;
    }
  }

}






  







  
