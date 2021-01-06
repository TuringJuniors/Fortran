#include <iostream>
#include "application.h"

#define CONTROL_HUB 0
#define SMART_HEATER 1


int state = 0;
int inputCode = 0;
int inputValue = 0;

using namespace std;


int main()
{
	cout << "code for devices" << endl << "control Hub 0" << endl << "smart heater 1" << endl;
	cout << "communicate with :";
	cin >> state;


	cout << "code :";
	cin >> state;

	cout << "value :";
	cin >> state;

	switch (state)
	{
	case CONTROL_HUB:

		//give  output to controlhub
		//get input from controlhub
		break;
	case SMART_HEATER:
		//give  output to smart heater
		break;
	}

	state = 0;
}