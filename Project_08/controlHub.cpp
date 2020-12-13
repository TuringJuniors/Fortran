using namespace std;
#include "controlHub.h"

void controlHub::addHeater(smartHeater* newHeater)
{
	heaterList.push_back(newHeater);
}

void controlHub::addLamp(smartLamp* newLamp)
{
	lampList.push_back(newLamp);
}
void controlHub::addAlarm(smartAlarm* newAlarm)
{
	alarmList.push_back(newAlarm);
}
void controlHub::addDoor(smartDoor* newDoor)
{
	doorList.push_back(newDoor);
}
void controlHub::addApplication(application* newApp)
{
	appList.push_back(newApp);
}

