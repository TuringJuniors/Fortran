#include <iostream>
#include "smartWindow.h"
using namespace std;

#define idleMode 0
#define thiefMode 1
#define smokeMode 2

int main()
{
	controlHub mainController;
	smartAlarm alarm1(&mainController);






	switch (alarm1.state) {
	case idleMode:
		while (alarm1.state == idleMode) {
			alarm1.getInputControlHub();
			break;
		}

	case thiefMode:
		while (alarm1.state == thiefMode) {
			alarm1.getInputControlHub();

			while (window1.distanceValue!= 0)
			{
				window1.getDistance();
				window1.moveFoward();
			}
			break;
		}
	case smokeMode:
		while (alarm1.state == smokeMode) {
			window1.getInputControlHub();

			while(window1.distanceValue!=window1.maxDistance)
			{
				window1.getDistance();
				window1.moveBackward();
			}
			break;
		}
	}
	

}