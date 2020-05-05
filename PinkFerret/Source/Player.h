#pragma once
#include <SFML/Graphics.hpp>
#include "level.h"
using namespace sf;
class Player
{
public:
	float x, y, angle = 0;
	Player(float X, float Y, Level& level);
	void update(float time, Vector2f positionMouse);
	void Meleeattack();
	void Move(float dX, float dY, float time);
	void Reload();
	void Shoot();
	void checkCollisionWithMap(float Dx, float Dy);
	Sprite getSprite();
	FloatRect getRect();
	View getViev();
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

	Image move_image;
	Texture move_texture;

	Image meleeattack_image;
	Texture meleeattack_texture;

	Image reload_image;
	Texture reload_texture;

	Image shoot_image;
	Texture shoot_texture;

	Sprite sprite;
};