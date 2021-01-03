#include<iostream>
#include "smartHeater.h"
#include "controlHub.h"
#include <pthread.h>

#define NUM_THREADS 2 
#define IDLE_STATE 0
#define SLEEP_STATE 1
#define OFF_STATE 2


controlHub mainController;
smartHeater heater1(&mainController);


using namespace std;

void* ON(void* threadid)
{
	
	while (1)
	{
		switch (heater1.state)
		{
		case IDLE_STATE:
			heater1.idleMode();
			break;
		case SLEEP_STATE:
			heater1.sleepMode();
			break;
		case OFF_STATE:
			heater1.off();
			break;
		}

		heater1.detectTemperature();
		if (heater1.currentTemperature <= heater1.runningTemperature)
		{
			heater1.startHeating();
		}
		if (heater1.currentTemperature >= heater1.runningTemperature)
		{
			heater1.stopHeating();
		}
	}
	pthread_exit(NULL);



}

void* UPDATE(void* threadid)
{
	while (1)
	{
		heater1.getInputApp();
		heater1.getInputHub();
	}
	pthread_exit(NULL);
}

int  main()
{
	pthread_t threads[NUM_THREADS];
	{
		pthread_create(&threads[0], NULL, ON, (void*)0); 
		pthread_create(&threads[1], NULL, UPDATE, (void*)1); 
	}
	pthread_exit(NULL);
}









/*
#define  IDLE 0
#define ECO 1
#define  SLEEP 2


int main()
{
	smartHeater heater1;
	heater1.idleMode();   // start the heater with idle mode
	int mode = 0;
	int on = 1;
	cin >> on;            // get input from control hub
	while (on)
	{

		cin >> mode;      //get input from control hub. as interupt on microcontroller
		switch (mode)
		{
		case IDLE:
			heater1.idleMode();
			break;
		case ECO:
			heater1.ecoMode();
			break;
		case SLEEP:
			heater1.sleepMode();
			break;
		}

		if (heater1.detectTemperature() != heater1.runningTemperature)
		{
			heater1.startHeating();
		}
		else
		{
			heater1.stopHeating();
		}
	}
}*/