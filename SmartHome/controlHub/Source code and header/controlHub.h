#ifndef CONTROL_HUB
#define CONTROL_HUB

class controlHub
{
public:


	//to communicate with smart heater
	void Heateron();

	//to communicate with application
	void Applicationnotify(int code);
	bool ApplicationwaitUserResponse();
	void ApplicationemergencyCall();

	//to communicate with smart door
	void Doorunlock();
	bool DoorcheckFirstPerson();

	//to communicate with smart Alarm
	void Alarmring();

	//to communicate with smart lamp
	void Lampblink();
	void Lampon();

	//to communicate with smart window
	void Windowclose();
	

};
#endif