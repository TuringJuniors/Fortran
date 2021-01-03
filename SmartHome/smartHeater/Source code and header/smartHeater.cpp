#include<iostream>
using namespace std;
#include "smartHeater.h"

smartHeater::smartHeater(controlHub* newController) 
{
	controller = newController;
}

double smartHeater::detectTemperature()
{
	cin >> currentTemperature;     // get input from temperature sensor
	return currentTemperature;
}

void smartHeater::getInputApp()
{
	int Input;
	cin >> Input;    //input from application 
	if (Input == 0)  //code-0 -> do nothing
	{
	}
	else if (Input == 1)  //code-1 -> to set idle temperature
	{
		double temp;
		cin >> temp;
		setIdleTemperature(temp); 

	}
	else if (Input == 2) //code-2 -> to set sleep temperature
	{
		double temp;
		cin >> temp;
		setSleepTemperature(temp);
	}
	else if (Input == 3) //code-3 -> to change the state to idle state
	{
		state = 0;//idle state
	}
	else if (Input == 4) //code-4 -> to change the state to sleep state
	{
		state = 1;//sleep state
	}
}
void smartHeater::getInputHub()
{
	int Input;
	cin >> Input;    //input from control Hub
	if (Input == 0)  //code-0 -> do nothing
	{
	}
	else if (Input == 1)  //code-1 -> on the smartHeater
	{
		state = 0; //start the smart heater in idle state
	}
	else if (Input == 2)  //code-1 -> on the smartHeater
	{
		state = 2; //turn off the heater
	}
}

void smartHeater::setIdleTemperature(double temp)
{
	idleTemperature = temp;
}
void smartHeater::setSleepTemperature(double temp)
{
	sleepTemperature = temp;
}

void smartHeater::startHeating()
{
	heating = true;               //turn on heater
}
void smartHeater::stopHeating()
{
	heating = false;              //turn off heater
}

void smartHeater::sleepMode()
{
	runningTemperature = sleepTemperature;
}
void smartHeater::idleMode(void)
{
	runningTemperature = idleTemperature;
}
void smartHeater::ecoMode()
{
	runningTemperature = ecoTemperature;
}

void smartHeater::on() 
{
	state = 0; // start the smart heater in idle state
}
void smartHeater::off()
{
	runningTemperature = -100;
}