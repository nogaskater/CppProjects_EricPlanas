// DynArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DynArray.hh"
#include <iostream>

// Constructores
DynArray::DynArray() : m_capacity{ DYN_ARRAY_DEFAULT_SIZE }, m_size{ 0 }, m_data{ new int[DYN_ARRAY_DEFAULT_SIZE] } {};
DynArray::DynArray(size_t size, const int &value) : m_capacity{ size }, m_size{ size }, m_data{ new int[size] }
{
	// Primera forma de hacerlo a pelo
	/*
	for (int i{ 0 }; i < size; i++)
	{
		m_data[i] = value;
	}
	*/
	// Segunda forma de hacerlo 
	/* 
	for (int *i{ begin() }; i < end(); i++) // Inicializo puntero *i para coger la direccion del primer elemento del array con la funcion begin
	{
		*i = value; 
	}
	*/
	// Tercera forma
	fill(begin(), end(), value);
};

//  ESO ES EL VALOR INTERNO m_data[i] = *(m_data + i) //  ESTO ES LA DIRECCION &m_data[i] = (m_data + i)

// Destructor
DynArray::~DynArray()
{

};

// Operator ==

// Begin
int* DynArray::begin() const
{
	return m_data;
}

// End
int* DynArray::end() const
{
	return m_data + m_size;
}


// Fill
void DynArray::fill(int *first, int *last, int value)
{
	while (first < last)
	{
		*first = value;
		first++;
	}
}

void DynArray::push(const int &val)
{
	if (m_size < m_capacity)
	{
		//m_data[m_size] = val;
		*(m_data + m_size) = val;
	}
	else
	{
		int *m_data_provisional{ new int[m_capacity + 1]};

		for (int i{ 0 }; i < m_size; i++)
		{
			*(m_data_provisional + i) = *(m_data + i);
		}
		
		*(m_data_provisional + m_size) = val;

		delete[] m_data;
		m_data = m_data_provisional;
		m_capacity++;
	}
		m_size++;

}

void DynArray::printArray()
{
	for (int i{ 0 }; i < m_size; i++)
	{
		std::cout << *(m_data + i) << std::endl;

	}
}

void DynArray::printArray(int positionArray)
{
	std::cout << *(m_data + positionArray - 1);
}
