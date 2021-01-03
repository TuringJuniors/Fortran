#include <iostream>
#include "controlHub.h"
using namespace std;

void controlHub::HeatersetIdleTemperature(double temp)
{
    cout << "set idle temperature to " << temp << endl; // send code and value to heater to set idle temperature
}
void controlHub::HeatersetSleepTemperature(double temp)
{
    cout << "set sleep temperature to " << temp << endl; // send code and value to heater to set sleep temperature
}
void controlHub::Heateron()
{
    cout << "set heater to " << "on" << endl;   // send code to heater to turn on the heater
}
void controlHub::Heateroff()
{
    cout << "set heater to " << "off" << endl; // send code to heater to turn on the heater
}
void controlHub::HeatersleepMode()
{
    cout << "heater mode chang to" << "sleep mode" << endl; // send code to heater to change state to sleep state
}
void controlHub::HeateridleMode(void)
{
    cout << "heater mode chang to" << "idle mode" << endl; // send code to heater to change state to idle state
}
void controlHub::HeaterecoMode()
{
    cout << "heater mode chang to" << "eco mode" << endl; // send code to heater to change state to eco state
}