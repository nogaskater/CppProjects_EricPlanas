// TheWalkingDead.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>


enum class Weapon
{
	FISTS,
	GUN,
	SHOTGUN,
	REVOLVER,
	SNIPER,
	MACHINE_GUN,
	MAX
};

class Zombie;
class Player
{
public:
	Weapon weapon;
	float precision;
	int life;

	Player() :weapon{ static_cast<Weapon>(rand() % static_cast<int>(Weapon::MAX)) }, precision{(0.1f*(rand() % 10)) }, life{ (rand() % 50) + 51 } {};
	Player(Weapon t_weapon, float t_precision, int t_life) :weapon{ t_weapon }, precision{ t_precision }, life{ t_life } {};
	~Player() {};

	void attack(Zombie &z);

	bool isAlive();
};

class Zombie
{
public:
	float distanceToPlayer;
	float speed;
	float damage;
	int life;

	Zombie() :distanceToPlayer{ (rand() & 180) + 20.0f }, speed{ static_cast<float>(0.1f*(rand() % 200)) }, damage{ static_cast<float>(0.1f*(rand() % 200)) }, life{ (rand() % 10) + 1 } {};
	~Zombie() {};

	void attack(Player &p);

	bool isAlive();
};

void Player::attack(Zombie &z)
{
	z.life -= static_cast<int>(weapon) * precision;
}
bool Player::isAlive()
{
	return life > 0;
}

void Zombie::attack(Player &p)
{
	if (distanceToPlayer <= 0)
	{
		p.life -= damage;
	}
	else
	{
		distanceToPlayer -= speed;
	}
}
bool Zombie::isAlive()
{
	return life > 0;
}

void main()
{
	srand(time(nullptr));
	Player player;
	const int MAX_ZOMBIES = 10;
	Zombie zombie[MAX_ZOMBIES];
	bool zombiesAreAlive = true;


	std::cout << "Player\n    life:" << player.life << "    weapon:" << static_cast<int>(player.weapon) << "    precision:" << player.precision << "\n\n";
	do
	{
		zombiesAreAlive = false;
		for (int i{ 0 }; i < MAX_ZOMBIES; i++)
		{
			if (zombie[i].isAlive())
			{
				zombiesAreAlive = true;
				player.attack(zombie[i]);
				zombie[i].attack(player);

				std::cout << "Zombie[" << i << "]    life:" << zombie[i].life << "    distance:" << zombie[i].distanceToPlayer << "    speed:" << zombie[i].speed << "    damage:" << zombie[i].damage << std::endl;
			}
			else
				std::cout << "Zombie[" << i << "]    --- DEAD ---\n";
		}
		std::cout << "\nPlayer HP: " << player.life << "\n\n";
	} while (zombiesAreAlive && player.isAlive());

	if (player.isAlive())	
		std::cout << "The Player WON! He killed all the zombies!";	
	else
		std::cout << "The Player GOT KILLED! The zombies won!";
}