#include <iostream>
using namespace std;



#ifndef SMART_DOOR
#define SMART_DOOR

class controlHub;
class smartDoor
{
    public:
    
    int pinNumber;
    bool thiefDetected;
    bool doorUnlock;
    bool pinCorrect;
    string detectedFace;
    int wrongPinCounter;
    
    void unlock();
    
    bool checkFirstPerson();
    
    smartDoor(controlHub* newController);
    
    private:
    
    controlHub controller;
    
};

#endif