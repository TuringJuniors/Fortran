#include <iostream>
using namespace std;


#ifndef SMART_WINDOW
#define SMART_WINDOW

class controlHub;
class smartWindow
{
    public:
     
    void open();
    void close();
    void ecoMode();
    
    smartWindow(controlHub* newController);
    
    private:
    
    controlHub* controller;
    
};

#endif