#include "PlayerState.h"

PlayerState::~PlayerState()
{
}

sf::Sprite PlayerState::draw(float time)
{
	return sf::Sprite();
}

PlayerState* PlayerState::handleInput(Player& player, sf::Event event, float time)
{
	return nullptr;
}

