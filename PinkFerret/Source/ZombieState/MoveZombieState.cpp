#include "MoveZombieState.h"
#include "../Zombie.h"
#include"../Player.h"

MoveZombieState::MoveZombieState()
{
	move_texture.loadFromFile("Media/zombie/zombie-idle.png");
	aMove = new Animation(move_texture, 0, 0, 241, 222, 17, 0.007f);
}
//123
MoveZombieState::~MoveZombieState()
{
}

sf::Sprite MoveZombieState::draw(float time)
{
	aMove->update(time);
	return aMove->sprite;
}

ZombieState* MoveZombieState::Update(Zombie& zombie, Player& player, float time)
{
	return nullptr;
}
