#pragma once
#include <SFML\Graphics.hpp>
//#include "../Player.h"
class Player;
class PlayerState
{
public:		
	virtual ~PlayerState();
	virtual sf::Sprite draw(float time);
	virtual PlayerState* handleInput(Player& player, sf::Event event, float time);
};