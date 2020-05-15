#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Player.h"
#include <ZombieState.h>
#include <StaticStateZombie.h>
using namespace sf;
class Zombie : public Entity
{
public:
	Zombie(Level& level, Player* player);
	void update(float time) override;
	void draw(RenderWindow& app, float time) override;
	void checkCollisionWithMap(float Dx, float Dy) override;
	void Meleeattack();
	StaticStateZombie States;

private:
	ZombieState* state_;
	Sprite* sprite;
	Player* pl;
};