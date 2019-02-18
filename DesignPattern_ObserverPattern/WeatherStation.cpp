#include <iostream>
#include <vector>

using namespace std;

class Observer
{
public:
	virtual void update(float temperature, float humidity, float pressure) = 0;
};

class Subject
{
public:
	virtual void registerObserver(Observer*) = 0;
	virtual void removeObserver(Observer*) = 0;
	virtual void notifyObserver() = 0;
};

class Display
{
public:
	virtual void display() = 0;
};


class CurrentConditionDisplay : public Observer, public Display
{
private:
	float temperature;
	float humidity;
	Subject *weatherData;
public:
	CurrentConditionDisplay(Subject *weatherData)
	{
		this->weatherData = weatherData;
		weatherData->registerObserver(this);
	}

	void update(float temperature, float humidity, float pressure)
	{
		this->temperature = temperature;
		this->humidity = humidity;
		display();
	}

	void display()
	{
		cout << "Current condition: " << temperature << "F degrees and " << humidity << "% humidity" << endl;
	}
	
	void RemoveByItself()
	{
		weatherData->removeObserver(this);
	}
};


class WeatherData : public Subject
{
private:
	vector<Observer*> observerList;
	float temperature;
	float humidity;
	float pressure;
	bool changed;
private:
	void notifyObserver()
	{
		if (changed)
		{
			for (unsigned int i = 0; i < (unsigned int)observerList.size(); i++)
			{
				Observer *observer = observerList.at(i);
				observer->update(temperature, humidity, pressure);
			}
		}
		changed = false;
	}

	void setChanged()
	{
		changed = true;
	}

	void measurementsChanged()
	{
		setChanged();
		notifyObserver();
	}
public:
	WeatherData()
	{
		changed = false;
	}

	void registerObserver(Observer *observerElement)
	{
		observerList.push_back(observerElement);
	}

	void removeObserver(Observer *observerElement)
	{
		for (unsigned int i = 0; i < (unsigned int)observerList.size(); i++)
		{
			if (observerList.at(i) == observerElement)
			{
				observerList.erase(observerList.begin() + i);
			}
		}
	}

	void setMeasurements(float temperature, float humidity, float pressure)
	{
		this->temperature = temperature;
		this->humidity = humidity;
		this->pressure = pressure;
		measurementsChanged();
	}
};

