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
	virtual string getDescription()
	{
		return description;
	}
};

class Condiments : public Beverage
{
public:
	virtual string getDescription() = 0;
};

class HouseBlend : public Beverage
{
public:
	HouseBlend()
	{
		description = "HouseBlend";
	}
	~HouseBlend()
	{
		cout << "Destructing HouseBlend" << endl;
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
		pbeverage = beverage;	
	}
	~Mocha()
	{
		cout << "Destructing Mocha" << endl;
	}
	string getDescription()
	{
		return pbeverage->getDescription() + ", Mocha";
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
		return pbeverage->getDescription() + ", Whip";
	}
	double cost()
	{
		return 0.1 + pbeverage->cost();
	}
};

int main(void)
{
	Beverage *pBeverage;
	pBeverage = new HouseBlend;
	cout << pBeverage->getDescription() << " has the price: " << pBeverage->cost() << "$" << endl;
	Beverage *pHouseBlendwithMocha = new Mocha(pBeverage);
	cout << pHouseBlendwithMocha->getDescription() << " has the price: " << pHouseBlendwithMocha->cost() << "$" << endl;
	Beverage *pHouseBlendwithMochaAndWhip = new Whip(pHouseBlendwithMocha);
	cout << pHouseBlendwithMochaAndWhip->getDescription() << " has the price: " << pHouseBlendwithMochaAndWhip->cost() << "$" << endl;
	cin.get();
	return 0;
}