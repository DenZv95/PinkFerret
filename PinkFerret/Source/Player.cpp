#include "Player.h"

Player::Player(Level& level)
{
	obj = level.GetAllObjects();

	view.reset(sf::FloatRect(x, y, 1280, 800));
	move_texture.loadFromFile("Media/survivor/handgun/survivor-move_handgun.png");
	meleeattack_texture.loadFromFile("Media/survivor/handgun/survivor-meleeattack_handgun.png");
	reload_texture.loadFromFile("Media/survivor/handgun/survivor-reload_handgun.png");
	shoot_texture.loadFromFile("Media/survivor/handgun/survivor-shoot_handgun.png");

	aMove = new Animation(move_texture,					0, 0, 260, 230, 20, 0.007f);
	aMeleeattack = new Animation(meleeattack_texture,	4, 0, 300, 240, 15, 0.01f);
	aReload = new Animation(reload_texture,				4, 0, 260, 230, 15, 0.016f);
	aShoot = new Animation(shoot_texture,				4, 0, 260, 230, 3, 0.009f);

	sprite.setTexture(move_texture);
	sprite.setOrigin(260 / 2, 230 / 2);
	amimationFinish = true;

}

void Player::update()
{
}

void Player::draw(RenderWindow& window)
{

	float time = 1;
	Vector2i pixelPos = Mouse::getPosition(window);
	Vector2f positionMouse = window.mapPixelToCoords(pixelPos);
	
	switch (state)
	{
	case move:
		aMove->update();
		sprite = aMove->sprite;
		break;
	case shoot:
		amimationFinish = false;
		if (aShoot->isEnd())
		{
			amimationFinish = true;
			ammo -= 1;
		}
		aShoot->update();
		sprite = aShoot->sprite;
		break;
	case reload:
		amimationFinish = false;
		if (aReload->isEnd())
		{
			amimationFinish = true;
			ammo = 5;
		}
		aReload->update();
		sprite = aReload -> sprite;
		break;
	case meleeattack:
		amimationFinish = false;
		if (aMeleeattack->isEnd())
		{
			amimationFinish = true;
		}
		aMeleeattack->update();
		sprite = aMeleeattack->sprite;
		break;
	default:
		sprite = aMove->sprite;
		break;
	}

	sprite.setPosition(x, y);

	angle = (atan2(positionMouse.y - y, positionMouse.x - x)) * 180 / 3.14159265;
	sprite.setRotation(angle);
	if (amimationFinish) {
		state = idle;
	}
	view.setCenter(x + 100, y);
	window.setView(view);
	window.draw(sprite);
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
	checkCollisionWithMap(dX, dY);
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

void Player::checkCollisionWithMap(float Dx, float Dy)
{

	for (int i = 0; i < obj.size(); i++)
		if (getRect().intersects(obj[i].rect))
		{
			if (obj[i].name == "TheWall")
			{

				if (Dy > 0) {
					y = obj[i].rect.top + obj[i].rect.height - 64 - 90;
				}
				if (Dy < 0) {
					y = obj[i].rect.top + obj[i].rect.height + 90;
				}

				if (Dx > 0) {
					x = obj[i].rect.left + obj[i].rect.width - 64 - 95;
				}

				if (Dx < 0) {
					x = obj[i].rect.left + obj[i].rect.width + 95;
				}
			}
		}

}
