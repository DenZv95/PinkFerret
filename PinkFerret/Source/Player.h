#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Player
{
public:
	Player(float X, float Y);
	void update(float time, Vector2f positionMouse);
	void Meleeattack();
	void Move(float dX, float dY, float time);
	void Reload();
	void Shoot();
	Sprite getSprite();
	View getViev();
private:
	View view;
	float x, y = 0;
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