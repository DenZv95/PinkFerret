#include "Zombie.h"


Zombie::Zombie(Level& level, Player* player)
{


	move_texture.loadFromFile("Media/zombie/zombie-idle.png");
	meleeattack_texture.loadFromFile("Media/zombie/zombie-attack.png");

	aMove = new Animation(move_texture, 0, 0, 241, 222, 17, 0.007f);
	aMeleeattack = new Animation(meleeattack_texture, 0, 0, 318, 294, 9, 0.012f);

	sprite.setTexture(move_texture);
	sprite.setTextureRect(IntRect(0, 0, 260, 230));
	amimationFinish = true;

	obj = level.GetAllObjects();
	pl = player;
}

void Zombie::update()
{
	if (getRect().intersects(pl->getRect()))
	{
		state = meleeattack;
	}
}

void Zombie::draw(RenderWindow& window, float time)
{
	switch (state)
	{
	case move:
		aMove->update(time);
		sprite = aMove->sprite;
		break;
	case meleeattack:
		amimationFinish = false;
		if (aMeleeattack->isEnd())
		{
			amimationFinish = true;
		}
		aMeleeattack->update(time);
		sprite = aMeleeattack->sprite;
		break;
	default:
		sprite = aMove->sprite;
		break;
	}

	sprite.setPosition(x, y);
	sprite.setRotation((atan2(200 - y, 300 - x)) * 180 / 3.14159265);
	if (amimationFinish) {
		state = idle;
	}
	window.draw(sprite);
}

void Zombie::Meleeattack()
{
	if (amimationFinish) {
		state = meleeattack;
	}
}

void Zombie::checkCollisionWithMap(float Dx, float Dy)
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

void Zombie::Move(float dX, float dY, float time)
{
	if (amimationFinish) {
		state = move;
	}
	x += dX * time;
	y += dY * time;

	dX = 0;
	dY = 0;
}

