#include <iostream>
using namespace std;


#ifndef APPLICATION
#define APPLICATION

class controlHub;
class application
{
    public:
    
    bool userResponse;
    
    void notify(bool thiefDetected);
    
    void waitUserResponse(int time);

    void emergencyCall();
    
    application(controlHub* newController);
    
    private:
    
    controlHub* controller;
 
};

#endif