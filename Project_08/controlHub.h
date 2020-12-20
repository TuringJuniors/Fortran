#include <list>

using namespace std;

class smartHeater;
class smartLamp;
class smartAlarm;
class smartDoor;
class application;
class smartWindow;

#ifndef CONTROL_HUB
#define CONTROL_HUB
class controlHub
{
public:
	void addHeater(smartHeater*newHeater);
	void addLamp(smartLamp* newLamp);
	void addAlarm(smartAlarm* newAlarm);
	void addDoor(smartDoor* newDoor);
	void addApplication(application* newApp);
	void addWindow(smartWindow* newWindow);
	bool thiefDetected;
	bool userResponse;

	list<smartHeater*> heaterList;
	list<smartLamp*> lampList;
	list<smartAlarm*> alarmList;
	list<smartDoor*> doorList;
	list<application*> appList;
	list<smartWindow*> windowList;
};
#endif 
