#pragma once
#include <SFML\Graphics.hpp>

class Zombie;
class Player;
class ZombieState
{
public:		
	virtual ~ZombieState();
	virtual sf::Sprite draw(float time);
	virtual ZombieState* Update(Zombie& zombie, Player& player, float time);
};