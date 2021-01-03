#ifndef CONTROL_HUB
#define CONTROL_HUB

class controlHub
{
public:


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