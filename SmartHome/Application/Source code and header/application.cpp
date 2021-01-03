#include "application.h"
#include <iostream>

void application :: notify(bool thiefDetected){
    
}
void application :: waitUserResponse(int time){
    
}
void application :: emergencyCall(){
    
}

void application::HeatersetIdleTemperature(double temp)
{
    cout << "set idle temperature to " << temp << endl; // send code and value to heater to set idle temperature
}
void application::HeatersetSleepTemperature(double temp)
{
    cout << "set sleep temperature to " << temp << endl; // send code and value to heater to set sleep temperature
}
void application::Heateron()
{
    cout << "set heater to " << "on" << endl;   // send code to heater to turn on the heater
}
void application::Heateroff()
{
    cout << "set heater to " << "off" << endl; // send code to heater to turn on the heater
}
void application::HeatersleepMode()
{
    cout << "heater mode chang to" << "sleep mode" << endl; // send code to heater to change state to sleep state
}
void application::HeateridleMode(void)
{
    cout << "heater mode chang to" << "idle mode" << endl; // send code to heater to change state to idle state
}
void application::HeaterecoMode()
{
    cout << "heater mode chang to" << "eco mode" << endl; // send code to heater to change state to eco state
}

