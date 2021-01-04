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
			alarm1.ring()
		
			break;
		}
	case smokeMode:
		while (alarm1.state == smokeMode) {
			alarm1.getInputControlHub();
			alarm1.ring()
		
			break;
		}
	}
	

}