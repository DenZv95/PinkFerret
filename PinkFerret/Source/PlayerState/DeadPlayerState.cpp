#include "DeadPlayerState.h"
#include "../Player.h"

DeadPlayerState::DeadPlayerState()
{
	deadTexture.loadFromFile("Media/survivor/handgun/survivor-dead_handgun.png");
	aDead = new Animation(deadTexture, 0, 0, 260, 230, 1, 0.007f);
}

DeadPlayerState::~DeadPlayerState()
{
}

sf::Sprite DeadPlayerState::draw(float time)
{
	aDead->update(time);
	return aDead->sprite;
}

PlayerState* DeadPlayerState::handleInput(Player& player, sf::Event event, float time)
{
	
	return nullptr;
}
