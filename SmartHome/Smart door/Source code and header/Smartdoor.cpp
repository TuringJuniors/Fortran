/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include "smartdoor.h"
using namespace std;

#define idleState 0
#define thiefDetected 1
#define smokeDetected 2

int main()
{
	controlHub app;
	smartdoor door1(&app);






	switch (door1.state) {
	case idleState:
		while (door1.state == idleState) {
			door1.getInputControlHub();
			
		}
		break;

	case thiefDetected:
		while (door1.state == thiefDetected) {
			door1.getInputControlHub();

			while (door1.lock_state!= 0)
			{
				door1.close();
			}
			
		}
		break;
	case smokeDetected:
		while (door1.state == smokeDetected) {
			door1.getInputControlHub();

			while(door1.lock_state!=door1.locked)
			{
				door1.open();
			}
			
		}
		break;
	}
	

}