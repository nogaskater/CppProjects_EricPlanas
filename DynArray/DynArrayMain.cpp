
#include "stdafx.h"
#include "DynArray.hh"
#include <iostream>


void main()
{
	DynArray a1;
	DynArray a2(5, 11);

	a1.push(8);
	a1.push(31);
	a1.push(2);
	a1.push(1);
	a1.push(107);
	a1.push(78);
	a1.printArray();
	std::cout << std::endl;

	a2.push(30);
	a2.printArray();
	std::cout << std::endl;

	a1.printArray(5);
}