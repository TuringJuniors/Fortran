#ifndef SMART_DOOR
#define SMART_DOOR

class smartDoor
{
    public:
    
    int pinNumber;
    bool thiefDetected;
    bool doorUnlock;
    bool pin;
    string detectedFace;
    int wrongPinCounter;
    
    void unlock();
        
    bool checkFirstPerson();
        
    
}

#endif