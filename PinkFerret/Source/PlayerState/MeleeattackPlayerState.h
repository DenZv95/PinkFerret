#pragma once
#include "../Animation.h"
#include <PlayerState.h>

using namespace sf;
class MeleeattackPlayerState : public PlayerState
{
public:
	MeleeattackPlayerState();
	virtual ~MeleeattackPlayerState();
	virtual sf::Sprite draw(float time);
	virtual PlayerState* handleInput(Player& player, sf::Event event, float time);
private:
	sf::Texture meleeattack_texture;
	Animation* aMeleeattack;
};
