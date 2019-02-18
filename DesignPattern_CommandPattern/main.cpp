#include "RemoteControlClass.cpp"

int main(void)
{
	SimpleRemoteControl *remote = new SimpleRemoteControl;  // invoker
	Light *light = new Light();								// receiver
	LightOnCommand *lighton = new LightOnCommand(light);	// command
	remote->setCommand(lighton);							// setCommand	
	remote->buttonWasPressed();								// execute
	cin.get();
	return 0;
}