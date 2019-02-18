#include "DuckClass.cpp"

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>

int main(void)
{
	MallardDuck Jones;
	Jones.performFly();
	Jones.performQuack();
	cin.get();
	_CrtDumpMemoryLeaks();
	return 0;
}