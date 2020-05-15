#include "ZombieState.h"

ZombieState::~ZombieState()
{
}

sf::Sprite ZombieState::draw(float time)
{
	return sf::Sprite();
}

ZombieState* ZombieState::Update(Zombie& zombie, Player& player, float time)
{
	return nullptr;
}

