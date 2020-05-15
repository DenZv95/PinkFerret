#pragma once
#include "../Animation.h"
#include <ZombieState.h>

using namespace sf;
class MeleeattackZombieState : public ZombieState
{
public:
	MeleeattackZombieState();
	virtual ~MeleeattackZombieState();
	virtual sf::Sprite draw(float time);
	virtual ZombieState* Update(Zombie& zombie, Player& player, float time);
private:
	sf::Texture texture;
	Animation* animation;
};