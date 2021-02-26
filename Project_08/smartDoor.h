/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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
