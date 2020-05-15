#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <list>
#include <sstream>
#include "Bullet.h"
#include <PlayerState.h>
#include <StaticState.h>

using namespace sf;

class Player : public Entity
{
public:
	Player(Level& level);
	void update(float time) override;
	void draw(RenderWindow& app, float time) override;
	void Move(float dX, float dY, float time);
	virtual void handleInput(Event event, float time);
	StaticState States;
	int ammo = 2;
	std::list<Entity*> bullets;
	std::list<Entity*> entitys;
	void Meleeattack();
	void Shoot();
private:
	void checkCollisionWithMap(float Dx, float Dy) override;
	PlayerState* state_;
	View view;
	Sprite sprite;
	Texture bullet_texture;
	Animation aBullet;
	/*(

	Texture meleeattack_texture;
	Texture reload_texture;
	Texture shoot_texture;

	Animation* aMove;
	Animation* aMeleeattack;
	Animation* aReload;
	Animation* aShoot;
	*/
};