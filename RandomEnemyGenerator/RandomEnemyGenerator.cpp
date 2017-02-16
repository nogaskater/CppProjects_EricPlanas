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
	srand(time(nullptr));

	int h = rand() % 9 + 1;
	std::string enemyName = names[rand() % (5)];
	EnemyType enemyType{EnemyType(rand() % 4)};

	return{enemyType, enemyName, h};

}

int main()
{
	CreateRandomEnemy();
    return 0;
}

