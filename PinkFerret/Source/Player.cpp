#include "Player.h"

Player::Player(float X, float Y)
{
	x = X; y = Y;
	view.reset(sf::FloatRect(x, y, 1280, 1024));
	view.setCenter(x + 100, y);
	move_image.loadFromFile("Media/survivor/handgun/survivor-move_handgun.png");
	move_image.createMaskFromColor(Color(255, 255, 255));
	move_texture.loadFromImage(move_image);

	sprite.setTextureRect(IntRect(0, 0, 260, 230));

	meleeattack_image.loadFromFile("Media/survivor/handgun/survivor-meleeattack_handgun.png");
	meleeattack_image.createMaskFromColor(Color(255, 0, 0));
	meleeattack_texture.loadFromImage(meleeattack_image);


	reload_image.loadFromFile("Media/survivor/handgun/survivor-reload_handgun.png");
	reload_image.createMaskFromColor(Color(255, 255, 255));
	reload_texture.loadFromImage(reload_image);

	shoot_image.loadFromFile("Media/survivor/handgun/survivor-shoot_handgun.png");
	shoot_image.createMaskFromColor(Color(255, 255, 255));
	shoot_texture.loadFromImage(shoot_image);

	sprite.setTexture(move_texture);
	amimationFinish = true;
}

void Player::update(float time, Vector2f positionMouse)
{


	switch (state)
	{
	case move:
		CurrentFrameMove += 0.007f * time;
		if (CurrentFrameMove > 20) {
			CurrentFrameMove = 0;
		}
		sprite.setTexture(move_texture);
		sprite.setTextureRect(IntRect(260 * int(CurrentFrameMove), 0, 260, 230));
		break;
	case shoot:
		amimationFinish = false;
		CurrentFrame += 0.009f * time;
		if (CurrentFrame > 3) {
			CurrentFrame = 0;
			amimationFinish = true;
			ammo -= 1;
		}
		sprite.setTexture(shoot_texture);
		sprite.setTextureRect(IntRect((260 * int(CurrentFrame) + 4), 0, 260, 230));
		break;
	case reload:
		amimationFinish = false;
		CurrentFrame += 0.01f * time;
		if (CurrentFrame > 15) {
			CurrentFrame = 0;
			amimationFinish = true;
			ammo = 5;
		}
		sprite.setTexture(reload_texture);
		sprite.setTextureRect(IntRect((260 * int(CurrentFrame) + 4), 0, 260, 230));
		break;
	case meleeattack:
		amimationFinish = false;
		CurrentFrame += 0.012 * time;
		if (CurrentFrame > 15) {
			CurrentFrame = 0;
			amimationFinish = true;
		}
		sprite.setTexture(meleeattack_texture);
		sprite.setTextureRect(IntRect((300 * int(CurrentFrame) + 6), 4, 300, 240));
		break;
	default:
		sprite.setTexture(move_texture);
		sprite.setTextureRect(IntRect(260 * int(CurrentFrameMove), 0, 260, 230));
		break;
	}

	sprite.setPosition(x, y);
	sprite.setOrigin(260 / 2, 230 / 2);
	//float dX = positionMouse.x - x;
	//float dY = positionMouse.y - y;
	//float rotation = (atan2(dY, dX)) * 180 / 3.14159265;
	//sprite.setRotation(rotation);
	sprite.setRotation((atan2(positionMouse.y - y, positionMouse.x - x)) * 180 / 3.14159265);
	if (amimationFinish) {
		state = idle;
	}
}

void Player::Meleeattack()
{
	if (amimationFinish) {
		state = meleeattack;
	}
}


void Player::Move(float dX, float dY, float time)
{
	if (amimationFinish) {
		state = move;
	}
	x += dX * time;
	y += dY * time;

	dX = 0;
	dY = 0;
	view.setCenter(x + 100, y);
}

void Player::Reload()
{
	if (amimationFinish) {
		if (ammo < 5)
			state = reload;
	}
}

void Player::Shoot()
{
	if (amimationFinish) {
		if (ammo > 0)
			state = shoot;
	}
}

Sprite Player::getSprite()
{
	return sprite;
}

View Player::getViev()
{
	return view;
}

