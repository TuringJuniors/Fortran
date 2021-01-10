#include <iostream>
using namespace std;


#ifndef SMART_LAMP
#define SMART_LAMP

class controlHub{
	
};
class smartLamp
{
    public:
    
    smartLamp(controlHub* newController);
    
    void getInputControlHub();
    
    int state;
    
    void blink();
    
    void on();
    
    void off();
    
   
    
    private:
    
    controlHub* controller;
};

#endif
