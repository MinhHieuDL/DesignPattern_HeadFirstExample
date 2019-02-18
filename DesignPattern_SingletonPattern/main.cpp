#include <iostream>
#include "Choc_O_Holic_Class.h"

using namespace std;


int main(void)
{
	ChocolateBoiler *DLBoiler = ChocolateBoiler::getInstanceOfChocolateBoiled();
	cout << "The address of DLBoiler is: " << DLBoiler << endl;
	cin.get();
	return 0;
}