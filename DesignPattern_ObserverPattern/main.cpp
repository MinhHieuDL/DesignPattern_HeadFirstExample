#include "WeatherStation.cpp"

int main(void)
{
	WeatherData *weatherData = new WeatherData;
	CurrentConditionDisplay *currentDisplay = new CurrentConditionDisplay(weatherData);
	weatherData->setMeasurements(60.0, 65.0, 30.4);
	weatherData->setMeasurements(30.0, 56.0, 30.4);
	weatherData->removeObserver(currentDisplay);
	cin.get();
	return 0;
}