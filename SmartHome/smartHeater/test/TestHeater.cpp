#include <iostream>
#include "smartHeater.h"

using namespace std;

void validationTestRun();
void METHOD1();
void METHOD2();
void METHOD3();
void METHOD4();
void METHOD5();
void METHOD6();
void METHOD7();
void METHOD8();
void METHOD9();
void METHOD10();
void METHOD11();
void METHOD12();

void EVENT1();

//function  to validate
int doubleAreEqual(double a, double b)
{
	return a == b ? 1 : 0;
}

double testInput[] = { 12.3,900.444,-6.67,2000,-4000.32 };
double testOutput[] = { 12.3,900.444,-6.67,2000,-4000.32 };
int controllerInput[] = { 0,1,2,3,4,5 };  //input from app and hub



// creat object for test purpose
controlHub controller1;
smartHeater heater1(&controller1);

int main()
{
	validationTestRun();
	return EXIT_SUCCESS;
}

void validationTestRun()
{
	METHOD1();
	METHOD2();
	METHOD3();
	METHOD4();
	METHOD5();
	METHOD6();
	METHOD7();
	METHOD8();
	METHOD9();
	METHOD10();
	METHOD11();
	METHOD12();

	EVENT1();
}

void METHOD1()   //detectTemperature()
{
	int errorCounter = 0;
	cout << "test  for METHOD1-->detectTemperature()" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "please type " << testInput[i] << ": ";
		heater1.detectTemperature();
		if (doubleAreEqual(heater1.currentTemperature, testOutput[i]) != 1)
		{
			errorCounter++;
		}
	}

	if (errorCounter)
	{
		cout << "METHOD1 error\n" << endl;
	}
	else
	{
		cout << "METHOD1 success\n" << endl;
	}

}

void METHOD2() //setIdleTemperature(double temp)
{
	int errorCounter = 0;
	cout << "test  for METHOD2-->setIdleTemperature(double temp)" << endl;
	for (int i = 0; i < 5; i++)
	{
		heater1.setIdleTemperature(testInput[i]);

		if (doubleAreEqual(heater1.idleTemperature, testOutput[i]) != 1)
		{
			errorCounter++;
		}
	}

	if (errorCounter)
	{
		cout << "METHOD2 error\n" << endl;
	}
	else
	{
		cout << "METHOD2 success\n" << endl;
	}

}

void METHOD3() //setSleepTemperature(double temp);
{
	int errorCounter = 0;
	cout << "test  for METHOD3-->setSleepTemperature(double temp)" << endl;
	for (int i = 0; i < 5; i++)
	{
		heater1.setSleepTemperature(testInput[i]);

		if (doubleAreEqual(heater1.sleepTemperature, testOutput[i]) != 1)
		{
			errorCounter++;
		}
	}

	if (errorCounter)
	{
		cout << "METHOD3 error\n" << endl;
	}
	else
	{
		cout << "METHOD3 success\n" << endl;
	}

}

void METHOD4() //on();
{
	int errorCounter = 0;
	cout << "test  for METHOD4-->on()" << endl;
	for (int i = 0; i < 5; i++)
	{
		heater1.state = testInput[i];
		heater1.on();
		if (doubleAreEqual(heater1.state, 0) != 1)
		{
			errorCounter++;
		}
	}

	if (errorCounter)
	{
		cout << "METHOD4 error\n" << endl;
	}
	else
	{
		cout << "METHOD4 success\n" << endl;
	}

}

void METHOD5() //off()
{
	int errorCounter = 0;
	cout << "test  for METHOD5-->off()" << endl;
	for (int i = 0; i < 5; i++)
	{
		heater1.runningTemperature = testInput[i];
		heater1.off();

		if (doubleAreEqual(heater1.runningTemperature, -100) != 1)
		{
			errorCounter++;
		}
	}

	if (errorCounter)
	{
		cout << "METHOD5 error\n" << endl;
	}
	else
	{
		cout << "METHOD5 success\n" << endl;
	}

}

void METHOD6() //startHeating()
{
	int errorCounter = 0;
	cout << "test  for METHOD6-->startHeating()" << endl;
	for (int i = 0; i < 5; i++)
	{
		heater1.heating = testInput[i];
		heater1.startHeating();
		heater1.off();

		if (doubleAreEqual(heater1.heating, 1) != 1)
		{
			errorCounter++;
		}
	}

	if (errorCounter)
	{
		cout << "METHOD6 error\n" << endl;
	}
	else
	{
		cout << "METHOD6 success\n" << endl;
	}

}

void METHOD7() //stopHeating()
{
	int errorCounter = 0;
	cout << "test  for METHOD7-->stopHeating()" << endl;
	for (int i = 0; i < 5; i++)
	{
		heater1.heating = testInput[i];
		heater1.stopHeating();
		heater1.off();

		if (doubleAreEqual(heater1.heating, 0) != 1)
		{
			errorCounter++;
		}
	}

	if (errorCounter)
	{
		cout << "METHOD7 error\n" << endl;
	}
	else
	{
		cout << "METHOD7 success\n" << endl;
	}

}

void METHOD8() //sleepMode()
{
	int errorCounter = 0;
	cout << "test  for METHOD8-->sleepMode()" << endl;
	for (int i = 0; i < 5; i++)
	{
		heater1.sleepTemperature = testInput[i];
		heater1.sleepMode();

		if (doubleAreEqual(heater1.runningTemperature, testOutput[i]) != 1)
		{
			errorCounter++;
		}
	}

	if (errorCounter)
	{
		cout << "METHOD8 error\n" << endl;
	}
	else
	{
		cout << "METHOD8 success\n" << endl;
	}

}

void METHOD9() //idleMode()
{
	int errorCounter = 0;
	cout << "test  for METHOD9-->idleMode()" << endl;
	for (int i = 0; i < 5; i++)
	{
		heater1.idleTemperature = testInput[i];
		heater1.idleMode();

		if (doubleAreEqual(heater1.runningTemperature, testOutput[i]) != 1)
		{
			errorCounter++;
		}
	}

	if (errorCounter)
	{
		cout << "METHOD9 error\n" << endl;
	}
	else
	{
		cout << "METHOD9 success\n" << endl;
	}

}

void METHOD10() //ecoMode()
{
	int errorCounter = 0;
	cout << "test  for METHOD10-->ecoMode()" << endl;
	for (int i = 0; i < 5; i++)
	{
		heater1.runningTemperature = testInput[i];
		heater1.ecoMode();

		if (doubleAreEqual(heater1.runningTemperature, 20) != 1)
		{
			errorCounter++;
		}
	}

	if (errorCounter)
	{
		cout << "METHOD10 error\n" << endl;
	}
	else
	{
		cout << "METHOD10 success\n" << endl;
	}

}

void METHOD11() //getInputHub()
{
	int errorCounter = 0;
	cout << "test  for METHOD11-->getInputHub()" << endl;

	for (int i = 0; i < 3; i++)
	{

		heater1.state = testInput[i];
		heater1.currentTemperature = testInput[i];
		heater1.runningTemperature = testInput[i];
		heater1.idleTemperature = testInput[i];
		heater1.sleepTemperature = testInput[i];
		heater1.heating = false;

		cout << "please type " << controllerInput[i] << " : ";
		heater1.getInputHub();

		//check for any changes to the artibute
		if (controllerInput[i] == 0)
		{
			if (doubleAreEqual(heater1.runningTemperature, testOutput[i]) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.idleTemperature, testOutput[i]) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.sleepTemperature, testOutput[i]) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.ecoTemperature, 20) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.heating, false) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.state, (int)testOutput[i]) != 1) { errorCounter++; }
		}
		else if (controllerInput[i] == 1)
		{
			if (doubleAreEqual(heater1.runningTemperature, testOutput[i]) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.idleTemperature, testOutput[i]) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.sleepTemperature, testOutput[i]) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.ecoTemperature, 20) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.heating, false) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.state, 0) != 1) { errorCounter++; }
		}
		else if (controllerInput[i] == 2)
		{
			if (doubleAreEqual(heater1.runningTemperature, testOutput[i]) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.idleTemperature, testOutput[i]) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.sleepTemperature, testOutput[i]) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.ecoTemperature, 20) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.heating, false) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.state, 2) != 1) { errorCounter++; }
		}

	}

	if (errorCounter)
	{
		cout << "METHOD11 error\n" << endl;
	}
	else
	{
		cout << "METHOD11 success\n" << endl;
	}

}

void METHOD12() //getInputApp()
{
	int errorCounter = 0;
	cout << "test  for METHOD12-->getInputApp()" << endl;
	cout << "insert 255.999  for each temperature value" << endl;
	for (int i = 0; i < 5; i++)
	{

		heater1.state = testInput[i];
		heater1.currentTemperature = testInput[i];
		heater1.runningTemperature = testInput[i];
		heater1.idleTemperature = testInput[i];
		heater1.sleepTemperature = testInput[i];
		heater1.heating = false;

		cout << "please type " << controllerInput[i] << " : ";
		heater1.getInputApp();

		//check for any changes to the artibute
		if (controllerInput[i] == 0)
		{
			if (doubleAreEqual(heater1.runningTemperature, testOutput[i]) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.idleTemperature, testOutput[i]) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.sleepTemperature, testOutput[i]) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.ecoTemperature, 20) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.heating, false) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.state, (int)testOutput[i]) != 1) { errorCounter++; }
		}
		else if (controllerInput[i] == 1) //code-1 -> to set idle temperature
		{

			if (doubleAreEqual(heater1.runningTemperature, testOutput[i]) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.idleTemperature, 255.999) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.sleepTemperature, testOutput[i]) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.ecoTemperature, 20) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.heating, false) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.state, (int)testOutput[i]) != 1) { errorCounter++; }
		}
		else if (controllerInput[i] == 2)
		{
			if (doubleAreEqual(heater1.runningTemperature, testOutput[i]) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.idleTemperature, testOutput[i]) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.sleepTemperature, 255.999) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.ecoTemperature, 20) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.heating, false) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.state, (int)testOutput[i]) != 1) { errorCounter++; }
		}
		else if (controllerInput[i] == 3)
		{
			if (doubleAreEqual(heater1.runningTemperature, testOutput[i]) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.idleTemperature, testOutput[i]) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.sleepTemperature, testOutput[i]) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.ecoTemperature, 20) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.heating, false) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.state, 0) != 1) { errorCounter++; }
		}
		else if (controllerInput[i] == 4)
		{
			if (doubleAreEqual(heater1.runningTemperature, testOutput[i]) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.idleTemperature, testOutput[i]) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.sleepTemperature, testOutput[i]) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.ecoTemperature, 20) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.heating, false) != 1) { errorCounter++; }
			if (doubleAreEqual(heater1.state, 1) != 1) { errorCounter++; }
		}


	}

	if (errorCounter)
	{
		cout << "METHOD12 error\n" << endl;
	}
	else
	{
		cout << "METHOD12 success\n" << endl;
	}

}

void EVENT1()
{
	cout << "test  for EVENT1-->check any change in each state" << endl;

#define IDLE_STATE 0
#define SLEEP_STATE 1
#define OFF_STATE 2

	int errorCounter = 0;

	for (int i = 0; i < 3; i++)
	{
		heater1.state = i;
		heater1.currentTemperature = testInput[i];
		heater1.runningTemperature = 0;
		heater1.idleTemperature = testInput[i];
		heater1.sleepTemperature = testInput[i];
		heater1.heating = false;

		switch (heater1.state)
		{
		case IDLE_STATE:
			heater1.idleMode();
			break;
		case SLEEP_STATE:
			heater1.sleepMode();
			break;
		case OFF_STATE:
			heater1.off();
			break;
		}
		cout << "\nplease type any value for current temperature: ";
		heater1.detectTemperature();
		if (heater1.currentTemperature <= heater1.runningTemperature)
		{
			heater1.startHeating();
		}
		if (heater1.currentTemperature >= heater1.runningTemperature)
		{
			heater1.stopHeating();
		}

		//check for any change in each state
		if (heater1.state == 0 && heater1.runningTemperature == heater1.idleTemperature)
		{
			cout << "\nentering idle mode "<< endl;
			cout << "current temperature : " << heater1.currentTemperature << endl;
			cout << "idle temperature : " << heater1.idleTemperature << endl;
			cout << "running temperature : " << heater1.runningTemperature << endl;
			cout << "Heating status : " << heater1.heating << endl;
		}
		else if (heater1.state == 1 && heater1.runningTemperature == heater1.sleepTemperature)
		{
			cout << "\nentering sleep mode " << endl;
			cout << "current temperature : " << heater1.currentTemperature << endl;
			cout << "sleep temperature : " << heater1.sleepTemperature << endl;
			cout << "running temperature : " << heater1.runningTemperature << endl;
			cout << "Heating status : " << heater1.heating << endl;
		}
		else if (heater1.state == 2 && heater1.heating == false)
		{
			cout << "entering off mode " << endl;
			cout << "Heating status : " << heater1.heating << endl;
		}
		else
		{
			errorCounter++;
		}
	}

	if (errorCounter)
	{
		cout << "EVENT1 error\n" << endl;
	}
	else
	{
		cout << "EVENT1 success\n" << endl;
	}

}
