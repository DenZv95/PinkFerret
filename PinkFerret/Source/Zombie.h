#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Player.h"

using namespace sf;
class Zombie : public Entity
{
public:
	Zombie(Level& level, Player* player);
	void update() override;
	void draw(RenderWindow& app, float time) override;
	void Meleeattack();
	void Move(float dX, float dY, float time);
private:
	int state = 0;
	float CurrentFrameMove = 0;
	float CurrentFrame = 0;
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