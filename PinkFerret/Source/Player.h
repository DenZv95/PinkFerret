#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Entity.h"
#include <list>
#include <sstream>
#include "Bullet.h"
#include <PlayerState.h>
#include <StaticState.h>SoundBuffer shootBuffer;

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
	SoundBuffer shootBuffer, reloadBuffer, meleeattackBuffer, moveBuffer;
	Sound* shoot;
	Sound* move;
};