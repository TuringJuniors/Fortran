#include <iostream>
using namespace std;


#ifndef APPLICATION
#define APPLICATION

class contollHub;
class application
{
    public:
    
    bool userResponse;
    
    void notify(bool thiefDetected);
    
    void waitUserResponse(int time);

    void emergencyCall();
    
    smartDoor(controlHub* newController);
    
    private:
    
    controlHub controller;
 
};

#endif