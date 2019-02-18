#include <iostream>

using namespace std;

// interface and concrete of flying
class FlyBehavior
{
public:
	virtual void fly() = 0;
};

class FlyWithWings : virtual public FlyBehavior
{
public:
	void fly()
	{
		cout << "I am flying by my wings dueeeee" << endl;
	}
};

class FlyNoWay : virtual public FlyBehavior
{
	void fly()
	{
		cout << "I can not fly nigga!!" << endl;
	}
};

// interface and concrete of quacking
class QuackBehavior
{
public:
	virtual void quack() = 0;
};

class Quack :virtual public QuackBehavior
{
public:
	void quack()
	{
		cout << "Quack, Quack...." << endl;
	}
};

class Squeck :virtual public QuackBehavior
{
public:
	void quack()
	{
		cout << "Squeck, Squeck...." << endl;
	}
};

class MuteQuack :virtual public QuackBehavior
{
public:
	void quack()
	{
		cout << "I can not quack nigga" << endl;
	}
};

// Duck class
class Duck
{
private:
	FlyBehavior *flyBehavior;
	QuackBehavior *quackBehavior;
public:
	void performFly()
	{
		flyBehavior->fly();
	}
	void performQuack()
	{
		quackBehavior->quack();
	}
	void setFlybehavior(FlyBehavior *fb)
	{
		flyBehavior = fb;
	}
	void setQuackBehavior(QuackBehavior *qb)
	{
		quackBehavior = qb;
	}
};

class MallardDuck : public Duck
{
public:
	MallardDuck()
	{
		setFlybehavior(new FlyWithWings);
		setQuackBehavior(new Quack);
	}
};
