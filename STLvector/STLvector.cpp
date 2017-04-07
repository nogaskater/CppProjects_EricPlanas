#include "stdafx.h"
#include <vector>
#include <stdio.h>
#include <iostream>
#include <time.h>

struct Persona
{
	std::string name;
	std::string birth;
	std::string dni;
};

std::vector<int> v1(5);
std::vector<int> v2(10, 0);
std::vector<int> v3({ 10,9,8,7,6,5,4,3,2,1 });
std::vector<std::string> v4({ "Gertrudiz", "Pancracia", "Anacleto", "Hipolito", "Eustaquio", "Fulgencia" });
std::vector<int> v5 = v3;

std::vector<Persona> v6({ { "paquito", "15/02/1995", "45791785G" },{ "manolo", "05/12/1944", "16284273D" },{ "anacardo", "25/06/2002", "51726328R" } });

std::vector<int> AddVectors(std::vector<int> v1, std::vector<int> v2)
{
	if (v1.size() == v2.size())
	{
		std::vector<int> v3(v1);

		for (int i{ 0 }; i < v1.size(); i++)
		{
			v3[i] += v2[i];
		}
		return v3;
	}
}

void ConcatVectors(std::vector<int> &v1, std::vector<int> v2)
{
	for(int e : v2)
		v1.push_back(e);
}

void ShiftRight(std::vector<int> &v1)
{
	v1.insert(v1.begin(), rand() % 10);
}

void RotateLeft(std::vector<int> &v1)
{
	v1.push_back(v1[0]);
	v1.erase(v1.begin());
}

void SearchAdjacent(std::vector<int> &v1)
{
	int temp = 1;
	int counter = 0;
	for (int i{ 0 }; i < v1.size(); i++)
	{
		if (i == 0)
		{
			temp = v1[i];
		}
		else
		{
			if (v1[i] == temp)
				counter++;
			else
			{
				temp = v1[i];
				counter = 1;
			}
		}

		if (counter == 3)
		{
			v1.erase(v1.begin() + i - 2, v1.begin() + i + 1);
			v1.insert(v1.begin(), { rand() % 10, rand() % 10, rand() % 10 });
			break;
		}
	}

}

void PrintVector(const std::vector<int> &v1)
{
	for (int e : v1)
		std::cout << e << " ";

	std::cout << std::endl;
	std::cout << std::endl;
}

int main()
{
	// Seed
	srand(time(nullptr));

	// Add Vectors
	PrintVector(AddVectors({ 5,5,5,5,5,5,5,5,5,5 }, v3));

	// Concat Vectors
	ConcatVectors(v3, { 22, 44, 66 });
	PrintVector(v3);

	// Shift Right
	ShiftRight(v3);
	PrintVector(v3);

	// Rotate Left
	RotateLeft(v3);
	PrintVector(v3);

	// Search Adjacent
	std::vector<int> vector1 ({ 1, 2, 2, 4, 5, 8, 8, 8, 9, 10 });
	SearchAdjacent(vector1);
	PrintVector(vector1);
	return 0;
}