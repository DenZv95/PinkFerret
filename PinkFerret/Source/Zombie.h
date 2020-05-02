#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Zombie
{
public:
	Zombie(float X, float Y);
	void update(float time, Vector2f positionMouse);
	void Meleeattack();
	void Move(float dX, float dY, float time);
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
		meleeattack
	};
	bool amimationFinish;
	
	Image move_image;
	Texture move_texture;

	Image meleeattack_image;
	Texture meleeattack_texture;

	Sprite sprite;
};