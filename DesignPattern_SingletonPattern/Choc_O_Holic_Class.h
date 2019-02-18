#pragma once
#include <iostream>

using namespace std;

class ChocolateBoiler
{
private:
	bool empty;
	bool boiled;

private:
	static ChocolateBoiler *uniqueChocolateBoiled;

private:
	ChocolateBoiler();


public:
	static ChocolateBoiler* getInstanceOfChocolateBoiled();

public:
	void fill();

	void drain();

	void boil();

	bool isEmpty();

	bool isBoiled();
};
