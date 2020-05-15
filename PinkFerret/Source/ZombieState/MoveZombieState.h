#pragma once
#include "../Animation.h"
#include <ZombieState.h>

using namespace sf;
class MoveZombieState : public ZombieState
{
public:
	MoveZombieState();
	virtual ~MoveZombieState();
	virtual sf::Sprite draw(float time);
	virtual ZombieState* Update(Zombie& zombie, Player& player, float time);
private:
	Texture move_texture;
	Animation* aMove;
};
