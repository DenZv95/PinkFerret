#pragma once
#include "../Animation.h"
#include <PlayerState.h>

using namespace sf;
class DeadPlayerState : public PlayerState
{
public:
	DeadPlayerState();
	virtual ~DeadPlayerState();
	virtual sf::Sprite draw(float time);
	virtual PlayerState* handleInput(Player& player, sf::Event event, float time);
private:
	sf::Texture deadTexture;
	Animation* aDead;
};
