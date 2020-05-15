#pragma once
#include "../Animation.h"
#include <ZombieState.h>

using namespace sf;
class DeadZombieState : public ZombieState
{
public:
	DeadZombieState();
	virtual ~DeadZombieState();
	virtual sf::Sprite* draw(float time);
	virtual ZombieState* Update(Zombie& zombie, Player& player, float time);
private:
	sf::Texture deadTexture;
	Animation* aDead;
};
