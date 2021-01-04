#include <iostream>
#include "controlHUb.h"

#define THIEF_DETECTED 0
#define MEMBER_ENTERING 1

using namespace std;

bool enterHouseScenario = true; // event 1

int main()
{
	controlHub controller1;
	while (enterHouseScenario)
	{

		int state;
		cin >> state;  //input from smart door

		switch (state)
		{
		case THIEF_DETECTED:
			controller1.Applicationnotify(1);// 1 means thief detected
			bool response = controller1.ApplicationwaitUserResponse();
			if (response == true)
			{
				controller1.Doorunlock();
				break;
			}
			else if (response == false)
			{
				controller1.ApplicationemergencyCall();
				controller1.Alarmring();
				controller1.Lampblink();
				controller1.Windowclose();
				break;
			}
		case MEMBER_ENTERING:
			controller1.Doorunlock();
			if (controller1.DoorcheckFirstPerson() == true)
			{
				controller1.Heateron();
				controller1.Lampon();
			}
			break;
		}
	}
}
