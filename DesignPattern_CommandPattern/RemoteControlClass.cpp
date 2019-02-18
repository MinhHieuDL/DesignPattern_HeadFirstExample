#include <iostream>
#include <vector>
using namespace std;

class Command
{
public:
	virtual void execute() = 0;
};

class Light
{
private:
	bool stateOfLight;
public:
	Light()
	{
		stateOfLight = false;
	}

	void on()
	{
		stateOfLight = true;
		cout << "Light is on" << endl;
	}

	void off()
	{
		stateOfLight = false;
		cout << "Light is off" << endl;
	}

	bool getStateOfLight()
	{
		return stateOfLight;
	}
};

class LightOnCommand : public Command
{
private:
	Light *light;
public:
	LightOnCommand(Light *light)
	{
		this->light = light;
	}

	void execute()
	{
		light->on();
	}
};

class SimpleRemoteControl
{
private:
	Command *slot
;
public:
	SimpleRemoteControl()
	{
		slot = NULL;
	}

	void setCommand(Command *command)
	{
		slot = command;
	}

	void buttonWasPressed()
	{
		slot->execute();
	}
};

class NoCommand : public Command
{
public:
	void execute()
	{
		cout << "Do nothing" << endl;
	}
};

class RemoteControl
{
private:
	Command *onCommand;
	Command *offCommand;
public:
	RemoteControl()
	{
		onCommand = new NoCommand[7];
		offCommand = new NoCommand[7];
	}
};