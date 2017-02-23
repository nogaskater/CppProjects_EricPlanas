// RandomEnemyGenerator.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <string>
#include <iostream>
#include <ctime>
enum class EnemyType 
{
	zombie,
	vampire,
	ghost,
	witch,
	max // Util para definir el final de la class
};

struct Enemy
{
	EnemyType type;
	std::string name;
	int health;
};

bool operator == (const Enemy &enemy1, const Enemy &enemy2) // Se usa el const para evitar modificar el contenido(only-read) // se usa el ampersan para no crear una variable nueva, simplemente acceder a la existente
{
	return enemy1.name == enemy2.name && enemy1.type == enemy2.type;
}

Enemy CreateRandomEnemy()
{
	const int MAX_LIFE{ 500 };
	std::string NAMES[] {"Isaaac", "Johny", "Jennifer", "Amador", "Harambee"};

	EnemyType enemyType{ EnemyType(rand() % 4) };
	int health = (rand() % 10) + 1;
	std::string enemyName = NAMES[rand() % 5];

	return{enemyType, enemyName, health};

}

std::string GetEnemyTypeString(EnemyType enemyType)
{
	std::string type;
	if (enemyType == EnemyType::ghost)
		type = "ghost";
	else if (enemyType == EnemyType::vampire)
		type = "vampire";
	else if (enemyType == EnemyType::witch)
		type = "witch";
	else if (enemyType == EnemyType::zombie)
		type = "zombie";

	return type;
}



void main()
{
	srand(time(nullptr));
	const int maxEnemies = 5;
	Enemy enemies[maxEnemies]{};
	std::cout << "List of enemies:\n\n";
	for (int i{ 0 }; i < maxEnemies; i++)
	{
		enemies[i] = CreateRandomEnemy();
		for (int j{ i }; j > 0; j--)
		{
			while (enemies[i] == enemies[j])
			{
				enemies[i] = CreateRandomEnemy();
			}

		}
		
	}

	for (int i{ 0 }; i < 5; i++)
	{
		std::cout << enemies[i].name << " is a " << GetEnemyTypeString(enemies[i].type) << " that has " << enemies[i].health << " health." << std::endl;
	}
}

