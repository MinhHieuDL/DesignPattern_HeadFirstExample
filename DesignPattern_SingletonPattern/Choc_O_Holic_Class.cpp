#include "Choc_O_Holic_Class.h"

ChocolateBoiler* ChocolateBoiler::uniqueChocolateBoiled = NULL;

ChocolateBoiler* ChocolateBoiler::getInstanceOfChocolateBoiled()
{
	if (uniqueChocolateBoiled == NULL)
	{
		uniqueChocolateBoiled = new ChocolateBoiler();
	}
	return uniqueChocolateBoiled;
}

ChocolateBoiler::ChocolateBoiler()
{
	empty = true;
	boiled = false;
}

void ChocolateBoiler::fill()
{
	if (isEmpty()) {
		empty = false;
		boiled = false;
		// fi ll the boiler with a milk/chocolate mixture
	}
}

void ChocolateBoiler::drain()
{
	if (!isEmpty() && isBoiled()) {
		// drain the boiled milk and chocolate
		empty = true;
	}
}

void ChocolateBoiler::boil()
{
	if (!isEmpty() && !isBoiled()) {
		// bring the contents to a boil
		boiled = true;
	}
}

bool ChocolateBoiler::isEmpty()
{
	return empty;
}

bool ChocolateBoiler::isBoiled()
{
	return boiled;
}
