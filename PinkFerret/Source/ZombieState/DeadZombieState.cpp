#include "DeadZombieState.h"
#include "../Zombie.h"
#include"../Player.h"

DeadZombieState::DeadZombieState()
{
	deadTexture.loadFromFile("Media/zombie/zombie-idledead.png");
	aDead = new Animation(deadTexture, 0, 0, 260, 230, 1, 0.007f);
}
//123
DeadZombieState::~DeadZombieState()
{
}

sf::Sprite* DeadZombieState::draw(float time)
{
	aDead->update(time);
	return &(aDead->sprite);
}

ZombieState* DeadZombieState::Update(Zombie& zombie, Player& player, float time)
{
	return nullptr;
}
