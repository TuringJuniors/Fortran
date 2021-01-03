#include <iostream>
#include "smartWindow.h"
using namespace std;

#define idleState 0
#define thiefDetected 1
#define smokeDetected 2

int main()
{
	controlHub mainController;
	smartWindow window1(&mainController);






	switch (window1.state) {
	case idleState:
		while (window1.state == idleState) {
			window1.getInputControlHub();
			break;
		}

	case thiefDetected:
		while (window1.state == thiefDetected) {
			window1.getInputControlHub();

			while (window1.distanceValue!= 0)
			{
				window1.getDistance();
				window1.moveFoward();
			}
			break;
		}
	case smokeDetected:
		while (window1.state == smokeDetected) {
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