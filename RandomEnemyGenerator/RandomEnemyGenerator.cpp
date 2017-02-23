// RandomEnemyGenerator.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <string>
#include <iostream>
#include <time.h>
enum class EnemyType {zombie, vampire, ghost, witch};

struct Enemy
{
	EnemyType type;
	std::string name;
	int health;
};

bool operator == (Enemy enemy1, Enemy enemy2)
{
	if (enemy1.name == enemy2.name && enemy1.type == enemy2.type)
	{
		return true;
	}
	else
		return false;
}

Enemy CreateRandomEnemy()
{
	std::string names[] {"Isaaac", "Johny", "Jennifer", "Amador", "Harambee"};

	int health = (rand() % 10) + 1;
	std::string enemyName = names[rand() % 5];
	EnemyType enemyType{EnemyType(rand() % 4)};

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

const int maxEnemies = 5;
Enemy enemies[maxEnemies]{};
void main()
{
	srand(time(nullptr));
	std::cout << "List of enemies:\n\n";
	for (int i{ 0 }; i < 5; i++)
	{
		enemies[i] = CreateRandomEnemy();
		while (enemies[i] == enemies[i - 1])
		{
			enemies[i] = CreateRandomEnemy();
		}
	}

	for (int i{ 0 }; i < 5; i++)
	{
		std::cout << enemies[i].name << " is a " << GetEnemyTypeString(enemies[i].type) << " that has " << enemies[i].health << " health." << std::endl;
	}
}

