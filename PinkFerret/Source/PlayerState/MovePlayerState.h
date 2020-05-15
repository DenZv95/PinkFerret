#pragma once
#include "../Animation.h"
#include <PlayerState.h>
#include <SFML/Audio.hpp>

using namespace sf;
class MovePlayerState : public PlayerState
{
public:
	MovePlayerState();
	virtual ~MovePlayerState();
	virtual sf::Sprite draw(float time);
	virtual PlayerState* handleInput(Player& player, sf::Event event, float time);
private:
	sf::Texture move_texture;
	Animation* aMove;
	SoundBuffer reloadBuffer, meleeattackBuffer, deathBuffer;
	Sound* meleeattack;
	Sound* reload;
	Sound* death;
};
