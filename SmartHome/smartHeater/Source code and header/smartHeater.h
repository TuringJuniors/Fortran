#include<iostream>
using namespace std;

#ifndef SMART_HEATER
#define SMART_HEATER

class controlHub;
class smartHeater
{
public:
	smartHeater(controlHub* newController);
	int state = 0;
	double detectTemperature();
	
	void getInputApp();  //get input from application
	void getInputHub();  //get input from control hub

	void setIdleTemperature(double temp);
	void setSleepTemperature(double temp);

	double currentTemperature = 0; 
	double runningTemperature = 0;      //temperature need to be mantained
	double idleTemperature = 0;         //default temperature set by owner
	double sleepTemperature = 0;        //temperature on sleep mode is on 
	double ecoTemperature = 20.0;   // room temperature. used to reduce energy conservation

	void on();
	void off();
	void startHeating();
	void stopHeating();

	bool heating =false;                  // heater status. either heating or cooling(stop heating) 

	void sleepMode();
	void idleMode(void);
	void ecoMode();
private:

	controlHub* controller;
};
#endif 

