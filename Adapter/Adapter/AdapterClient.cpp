#include <iostream>
#include "windows.h"
#include"Clock12.h"

int main()
{
	//clock 
	Clock12 clock(12,59,55);
	while (true)
	{
	clock.print();
	clock.tick();
	Sleep(1000);
	system("cls");
	}
}
