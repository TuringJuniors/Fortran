#include <iostream>
using namespace std;

#ifndef SMART_DOOR
#define SMART_DOOR

class controlHub;
class smartdoor
{
public:

    void open();
    void close();
    void lock();
    void unlock();
    void getInputControlHub();
    double lock_state =0;
    bool thiefDetected =0;
    bool smokeDetected =0;
    int state =0;
    int locked = 500;

    smartdoor(controlHub* newController);

private:

    controlHub* controller;

};

#endif
