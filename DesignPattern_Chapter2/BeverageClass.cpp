#include <iostream>
#include <string>

using namespace std;

class Beverage
{
public:
	string description;
public:
	virtual ~Beverage()
	{
		cout << "Destructing Beverage" << endl;
	}
	virtual double cost() = 0;
	string getDescription()
	{
		return description;
	}
};

class Condiments : public Beverage
{
public:
	virtual string getDescription() = 0;
};

class Espresso : public	Beverage
{
public:
	Espresso()
	{
		description = "Espresso";
	}
	double cost()
	{
		return 1.99;
	}
};

class HouseBlend : public Beverage
{
public:
	HouseBlend()
	{
		description = "HouseBlend";
	}
	double cost()
	{
		return 0.89;
	}
};

class Mocha : public Condiments
{
private:
	Beverage *pbeverage;
public:
	Mocha(Beverage *beverage)
	{
		description = pbeverage->description + "Mocha";
		cout << description << " This statement was printed in Condiments constructor" << endl;
		pbeverage = beverage;
	}
	string getDescription()
	{
		return description;
	}
	double cost()
	{
		return 0.2 + pbeverage->cost();
	}
};

class Whip : public Condiments
{
private:
	Beverage *pbeverage;
public:
	Whip(Beverage *beverage)
	{
		pbeverage = beverage;
	}
	string getDescription()
	{
		return pbeverage->getDescription() + "Whip";
	}
	double cost()
	{
		return 0.1 + pbeverage->cost();
	}
};