#include "Player.h"


Player::Player(Level& level)
{
	obj = level.GetAllObjects();
	bullet_texture.loadFromFile("Media/survivor/FullMetalJacket.png");
	aBullet = Animation(bullet_texture, 0, 0, 5, 4, 1, 0.8);
	life = 200;
	name = "Player";
	view.reset(sf::FloatRect(x, y, 1280, 800));
	sprite.setOrigin(260 / 2, 230 / 2);
	States = StaticState();

	state_ = States.getMoveState();
	int a = 1;
}

void Player::update(float time)
{
	
}

void Player::draw(RenderWindow& window, float time)
{
	Vector2i pixelPos = Mouse::getPosition(window);
	Vector2f positionMouse = window.mapPixelToCoords(pixelPos);

	sprite = state_->draw(time);
	
	sprite.setPosition(x, y);
	angle = (atan2(positionMouse.y - y, positionMouse.x - x)) * 180 / 3.14159265;
	sprite.setRotation(angle);
	window.draw(sprite);
	view.setCenter(x + 100, y);
	window.setView(view);
}

void Player::handleInput(Event event, float time)
{
	PlayerState* state = state_->handleInput(*this, event, time);
	if (state != nullptr)
	{
		state_ = state;
	}
}

void Player::checkCollisionWithMap(float Dx, float Dy)
{
	for (int i = 0; i < obj.size(); i++)
	{

		if (getRect().intersects(obj[i].rect))
		{
			if (obj[i].name == "TheWall")
			{

				if (Dy > 0) {
					y = obj[i].rect.top - 90;
				}
				if (Dy < 0) {
					y = obj[i].rect.top + obj[i].rect.height + 90;
				}

				if (Dx > 0) {
					x = obj[i].rect.left - 95;
				}

				if (Dx < 0) {
					x = obj[i].rect.left + obj[i].rect.width + 95;
				}
			}
		}
	}
}

void Player::Move(float dX, float dY, float time)
{

	x += dX * time;
	y += dY * time;
	checkCollisionWithMap(dX, dY);
	dX = 0;
	dY = 0;
	view.setCenter(x + 100, y);
}

void Player::Shoot()
{
		if (ammo > 0)
		{
			Bullet* b = new Bullet(aBullet, obj);
			b->settings(x + (112 * cos(angle * 0.017453f) - 48 * sin(angle * 0.017453f)), y + (112 * sin(angle * 0.017453f) + 48 * cos(angle * 0.017453f)), 4, 5, angle);
			bullets.push_back(b);
		}
}

/*
Player::Player(Level& level)
{
	obj = level.GetAllObjects();
	life = 200;
	name = "Player";
	view.reset(sf::FloatRect(x, y, 1280, 800));
	move_texture.loadFromFile("Media/survivor/handgun/survivor-move_handgun.png");
	meleeattack_texture.loadFromFile("Media/survivor/handgun/survivor-meleeattack_handgun.png");
	reload_texture.loadFromFile("Media/survivor/handgun/survivor-reload_handgun.png");
	shoot_texture.loadFromFile("Media/survivor/handgun/survivor-shoot_handgun.png");

	aMove = new Animation(move_texture, 0, 0, 260, 230, 20, 0.007f);
	aMeleeattack = new Animation(meleeattack_texture, -10, 0, 300, 240, 15, 0.01f);
	aReload = new Animation(reload_texture, 3, 0, 260, 230, 15, 0.011f);
	aShoot = new Animation(shoot_texture, 0, 0, 260, 230, 3, 0.009f);

	sprite.setOrigin(260 / 2, 230 / 2);
	amimationFinish = true;

	font.loadFromFile("Media/CyrilicOld.ttf");

	hud = new Hud();

}

void Player::update(float time)
{
}

void Player::draw(RenderWindow& window, float time)
{

	Vector2i pixelPos = Mouse::getPosition(window);
	Vector2f positionMouse = window.mapPixelToCoords(pixelPos);

	switch (state)
	{
	case move:
		aMove->update(time);
		amimationFinish = true;
		sprite = aMove->sprite;
		break;
	case shoot:
		amimationFinish = false;
		aShoot->update(time);
		if (aShoot->isEnd())
		{
			amimationFinish = true;
			ammo -= 1;
		}
		sprite = aShoot->sprite;
		break;
	case reload:
		amimationFinish = false;
		aReload->update(time);
		if (aReload->isEnd())
		{
			amimationFinish = true;
			ammo = 7;
		}

		sprite = aReload->sprite;
		break;
	case meleeattack:
		amimationFinish = false;
		aMeleeattack->update(time);
		if (aMeleeattack->isEnd())
		{
			amimationFinish = true;
		}
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
	if (tytyry)
	{
		Text text("", font, 30);
		text.setString("“утуру!");
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);

		text.setPosition(view.getCenter().x, view.getCenter().y);

		window.draw(text);
	}


	hud->draw(window, life, ammo, view.getCenter().x, view.getCenter().y);
	view.setCenter(x + 100, y);
	window.setView(view);
	window.draw(sprite);
}

void Player::Meleeattack(std::list<Entity*>& entities)
{
	if (amimationFinish)
	{
		state = meleeattack;
		for (auto a : entities)
		{
			if (a->life)
			{
				if (a->name == "Zombie")
					if (a->getRect().intersects(getRect()))
					{
						a->damage();
					}
			}
		}
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

void Player::Shoot(std::list<Entity*>& entities, Animation& sBullet, Level& lvl)
{
	if (amimationFinish)
	{
		if (ammo > 0)
		{
			state = shoot;
			Bullet* b = new Bullet(sBullet, lvl);
			b->settings(x + (112 * cos(angle * 0.017453f) - 48 * sin(angle * 0.017453f)), y + (112 * sin(angle * 0.017453f) + 48 * cos(angle * 0.017453f)), 4, 5, angle);
			entities.push_back(b);
		}
	}
}

void Player::checkCollisionWithMap(float Dx, float Dy)
{

	for (int i = 0; i < obj.size(); i++)
	{

		if (getRect().intersects(obj[i].rect))
		{
			if (obj[i].name == "TheWall")
			{

				if (Dy > 0) {
					y = obj[i].rect.top - 90;
				}
				if (Dy < 0) {
					y = obj[i].rect.top + obj[i].rect.height + 90;
				}

				if (Dx > 0) {
					x = obj[i].rect.left - 95;
				}

				if (Dx < 0) {
					x = obj[i].rect.left + obj[i].rect.width + 95;
				}
			}

			if (obj[i].name == "Exit")
			{
				tytyry = true;
			}
		}
	}

}
*/
