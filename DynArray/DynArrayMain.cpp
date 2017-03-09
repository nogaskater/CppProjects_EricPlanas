
#include "stdafx.h"
#include "DynArray.hh"
#include <iostream>


void main()
{
	DynArray a1;
	DynArray a2(5, 10);

	a1.push(8);
	a1.push(31);
	a1.print();
	std::cout << std::endl;
	a2.push(30);
	a2.print();
}