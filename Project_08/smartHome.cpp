#include <iostream>
#include "controlHub.h"
#include "smartHeater.h"
#include "smartAlarm.h"
#include "smartLamp.h"
#include "smartDoor.h"
#include "application.h"
#include "smartWindow.h"


#define THIEF_DETECTED 0
#define MEMBER_ENTERING 1



using namespace std;

int state = 0;
bool enterHouseScenario = true; // scenario 1

int main()
{
	controlHub controlHub1;
	smartHeater heater1(&controlHub1);
	smartAlarm alarm1(&controlHub1);
	smartLamp lamp1(&controlHub1);
	smartDoor door1(&controlHub1);
	application app1(&controlHub1);
	smartWindow window1(&controlHub1);


	controlHub1.addHeater(&heater1);
	controlHub1.addAlarm(&alarm1);
	controlHub1.addLamp(&lamp1);
	controlHub1.addDoor(&door1);
	controlHub1.addApplication(&app1);
	controlHub1.addWindow(&window1);

	//initialize
	door1.wrongPinCounter = 0;
	door1.detectedFace = "noFaceDetectted";


	while (enterHouseScenario)
	{

		if (door1.wrongPinCounter > 3 && door1.detectedFace == "unusual") // thief try to open the door
		{
			state = THIEF_DETECTED;                                // critical mode
		}
		if (door1.pinCorrect)
		{
			state = MEMBER_ENTERING;                               // safe/normal mode
		}


		switch (state)
		{
		case THIEF_DETECTED:
			app1.notify(controlHub1.thiefDetected);
			app1.waitUserResponse(10000);
			controlHub1.userResponse = app1.userResponse;
			if (controlHub1.userResponse == true)
			{
				door1.unlock();
				break;
			}
			else if (controlHub1.userResponse == false)
			{
				app1.emergencyCall();
				alarm1.ring();
				lamp1.blink();
				window1.close();
				break;
			}
		case MEMBER_ENTERING:
			door1.unlock();
			if (door1.checkFirstPerson() == true)
			{
				heater1.on();
				lamp1.on();
			}
			break;
		}
		door1.wrongPinCounter++;


	}
}
