#pragma once
#include <SFML/Graphics.hpp>
#include "level.h"
#include "Entity.h"

using namespace sf;
class Player : public Entity
{
public:
	Player(Level& level);
	void update() override;
	void draw(RenderWindow& app) override;
	void Meleeattack();
	void Move(float dX, float dY, float time);
	void Reload();
	void Shoot();
	void checkCollisionWithMap(float Dx, float Dy);

private:
	std::vector<Object> obj;
	View view;

	int state = 0;
	float CurrentFrameMove = 0;
	float CurrentFrame = 0;
	enum State
	{
		idle,
		move,
		reload,
		shoot,
		meleeattack
	};
	bool amimationFinish;
	int ammo = 2;

	Texture move_texture;
	Texture meleeattack_texture;
	Texture reload_texture;
	Texture shoot_texture;

	Animation* aMove;
	Animation* aMeleeattack;
	Animation* aReload;
	Animation* aShoot;

	Sprite sprite;
};