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

	//to communicate with smart heater
	void HeatersetIdleTemperature(double temp);
	void HeatersetSleepTemperature(double temp);
	void Heateron();
	void Heateroff();
	void HeatersleepMode();
	void HeateridleMode(void);
	void HeaterecoMode();
};

#endif