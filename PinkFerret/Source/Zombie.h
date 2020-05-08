#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Player.h"

using namespace sf;
class Zombie : public Entity
{
public:
	Zombie(Level& level, Player* player);
	void update(float time) override;
	void draw(RenderWindow& app, float time) override;
	void Meleeattack();
private:
	int state = 0;
	enum State
	{
		idle,
		move,
		meleeattack
	};
	bool amimationFinish;
	void checkCollisionWithMap(float Dx, float Dy) override;
	Texture move_texture;
	Texture meleeattack_texture;
	Animation* aMove;
	Animation* aMeleeattack;
	Sprite sprite;
	Player* pl;
};