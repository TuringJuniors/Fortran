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