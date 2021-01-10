#include <iostream>
#include "smartLamp.h"

using namespace std;

void validationTestRun();
void METHOD1();
void METHOD2();
void METHOD3();
void METHOD4();

// create object for test purpose
controlHub controller1;
smartLamp lamp1(&controller1);


//function  to validate
int doubleAreEqual(double a, double b)
{
	return a == b ? 1 : 0;
}

double testInput[] = { 12.3,900.444,-6.67,2000,-4000.32 };
double testOutput[] = { 12.3,900.444,-6.67,2000,-4000.32 };
int controllerInput[] = { 0,1,2 };  //input from hub



int main()
{
	validationTestRun();
	return 0;
}




void validationTestRun()
{
	METHOD1();
	METHOD2();
	METHOD3();
	METHOD4();
	
}





void METHOD1()//on()
{
	cout<<"Test for METHOD1, on()"<< endl;
	cout<<"If console prints lampOn, METHOD1 is succesful"<< endl;
	cout<<"Commencing test..."<<endl;
	
	lamp1.on();
}

void METHOD2()//off()
{
	cout<<"Test for METHOD2, off()"<< endl;
	cout<<"If console prints lampOff, METHOD2 is succesful"<< endl;
	cout<<"Commencing test..."<<endl;
	
	lamp1.off();
}

void METHOD3()//blink()
{
	cout<<"Test for METHOD3, blink()"<< endl;
	cout<<"If console prints lampOn and lampOff repeatedly, METHOD3 is succesful"<< endl;
	cout<<"Commencing test..."<<endl;
	
	lamp1.blink();
}

void METHOD4()//getInputControlHub()
{
	
	int errorCounter = 0;
	cout << "test  for METHOD11, getInputControlHub()" << endl;

	for (int i = 0; i < 3; i++)
	{

		lamp1.state = testInput[i];
		
		

		cout << "please type " << controllerInput[i] << " : ";
		lamp1.getInputControlHub();

		//check for any changes to the attribute
		if (controllerInput[i] == 0)
		{
			
			if (doubleAreEqual(lamp1.state, (int)testOutput[i]) != 1) { errorCounter++; }
		}
		
		
		else if (controllerInput[i] == 1)
		{
		
			if (doubleAreEqual(lamp1.state, 0) != 1) { errorCounter++; }
		}
		
		
		else if (controllerInput[i] == 2)
		{
		
			if (doubleAreEqual(lamp1.state, 1) != 1) { errorCounter++; }
		}
		
		
			else if (controllerInput[i] == 3)
		{
		
			if (doubleAreEqual(lamp1.state, 2) != 1) { errorCounter++; }
		}

	}

	if (errorCounter)
	{
		cout << "METHOD4 not successful\n" << endl;
	}
	else
	{
		cout << "METHOD4 successful\n" << endl;
	}

}

