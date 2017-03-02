// DynArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DynArray.hh"
#include <iostream>

// Constructores
DynArray::DynArray() : m_capacity{ DYN_ARRAY_DEFAULT_SIZE }, m_size{ 0 }, m_data{ new int[DYN_ARRAY_DEFAULT_SIZE] } {};
DynArray::DynArray(size_t size, const int &value) : m_capacity{ size }, m_size{ size }, m_data{ new int[size] }
{
	for (int i{ 0 }; i < size; i++)
	{
		m_data[i] = value; //  ESO ES EL VALOR INTERNO m_data[i] = *(m_data + i) //  ESTO ES LA DIRECCION &m_data[i] = (m_data + i)
	}
};

// Destructor
//DynArray::~DynArray();

// Operator ==

// Begin
int* DynArray::begin() const
{
	return m_data;
}

int* DynArray::end() const
{
	return m_data + m_size;
}

// End

// Fill
void DynArray::fill(int *first, int *last, int value)
{
	while (first < last)
	{
		*first = value;
		first++;
	}
}
