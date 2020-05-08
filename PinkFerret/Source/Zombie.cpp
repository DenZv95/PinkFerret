#include "Zombie.h"

Zombie::Zombie(float X, float Y)
{
	x = X; y = Y;
	view.reset(sf::FloatRect(x, y, 1280, 1024));
	view.setCenter(x + 100, y);
	move_image.loadFromFile("Media/zombie/zombie-idle.png");
	move_image.createMaskFromColor(Color(255, 255, 255));
	move_texture.loadFromImage(move_image);

	sprite.setTextureRect(IntRect(0, 0, 260, 230));

	meleeattack_image.loadFromFile("Media/zombie/zombie-attack.png");
	meleeattack_image.createMaskFromColor(Color(255, 0, 0));
	meleeattack_texture.loadFromImage(meleeattack_image);

	sprite.setTexture(move_texture);
	amimationFinish = true;
}

void Zombie::update(float time, Vector2f positionMouse)
{
	switch (state)
	{
	case move:
		CurrentFrameMove += 0.007f * time;
		if (CurrentFrameMove > 17) {
			CurrentFrameMove = 0;
		}
		sprite.setTexture(move_texture);
		sprite.setTextureRect(IntRect(241 * int(CurrentFrameMove), 0, 241, 222));
		break;
	case meleeattack:
		amimationFinish = false;
		CurrentFrame += 0.012 * time;
		if (CurrentFrame > 9) {
			CurrentFrame = 0;
			amimationFinish = true;
		}
		sprite.setTexture(meleeattack_texture);
		sprite.setTextureRect(IntRect((318 * int(CurrentFrame) + 36), 38, 318, 294));
		break;
	default:
		sprite.setTexture(move_texture);
		sprite.setTextureRect(IntRect(241 * int(CurrentFrameMove), 0, 241, 222));
		break;
	}

	sprite.setPosition(x, y);
	sprite.setOrigin(241 / 2, 222 / 2);
	//float dX = positionMouse.x - x;
	//float dY = positionMouse.y - y;
	//float rotation = (atan2(dY, dX)) * 180 / 3.14159265;
	//sprite.setRotation(rotation);
	sprite.setRotation((atan2(positionMouse.y - y, positionMouse.x - x)) * 180 / 3.14159265);
	if (amimationFinish) {
		state = idle;
	}
}

void Zombie::Meleeattack()
{
	if (amimationFinish) {
		state = meleeattack;
	}
}


void Zombie::Move(float dX, float dY, float time)
{
	if (amimationFinish) {
		state = move;
	}
	x += dX * time;
	y += dY * time;

	dX = 0;
	dY = 0;
	view.setCenter(x + 100, y);
	
	isMove = false; 
	isSelect = false;
}


Sprite Zombie::getSprite()
{
	return sprite;
}

View Zombie::getViev()
{
	return view;
}

