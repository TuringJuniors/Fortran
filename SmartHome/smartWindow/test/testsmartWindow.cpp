
#include <iostream>
using namespace std;
#include "smartWindow.h"

void validationTestRun();
void METHOD1();
void METHOD2();
void METHOD3();
void METHOD4();
void METHOD5();
void METHOD6();
controlHub hub1;
smartWindow window(&hub1);

void validationTestRun()
{
	METHOD1(); //window move backward
	METHOD2(); //window move forward
	METHOD3(); //get distance
	//METHOD4(); //window close (special test)
	//METHOD5(); //window open (special test)
	METHOD6(); //get input control hub
	
	
}


int main()
{
	validationTestRun();

}

void METHOD1()
{
	window.moveBackward();
	cout << "if motor move backward = success"<< endl;
}

void METHOD2()
{
	window.moveForward();
	cout << "if motor move Forward = success"<< endl;
}

void METHOD3()
{
	cout << "please type 2";
	window.getDistance();

	if(window.distanceValue==2)
	{
		cout << "successful"<< endl;
	}	
}

void METHOD4()
{
	cout << "motor move forward repeatedly = success" << endl;
	window.getDistance();
	window.close();
	
}

void METHOD5()
{
	cout << "motor move backward repeatedly = success" << endl;
	window.getDistance();
	window.open();

}

void METHOD6()
{
	cout << "please type 1" << endl;
	window.getInputControlHub();
	if (window.thiefDetected == true)
	{
		cout << "success" << endl;
	}
	else 
	{
		cout << "not success" << endl;
	}

	cout << "please type 2" << endl;
	window.getInputControlHub();
	if (window.smokeDetected == true)
	{
		cout << "success" << endl;
	}
	else
	{
		cout << "not success" << endl;
	}

	cout << "please type 3" << endl;
	window.getInputControlHub();
	if (window.state == 0)//idle state
	{
		cout << "success" << endl;
	}
	else
	{
		cout << "not success" << endl;
	}

	
	
}