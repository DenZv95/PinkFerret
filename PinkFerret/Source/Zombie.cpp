#include "Zombie.h"

Zombie::Zombie(Level& level, Player* player)
{

	life = 50;
	name = "Zombie";
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

void Zombie::update(float time)
{

	dx = cos(angle * 0.017453f) * 0.1 * time;
    dy = sin(angle * 0.017453f) * 0.1 * time;
	if (getRect().intersects(pl->getRect()))
	{
		if (state != meleeattack) {
			state = meleeattack;
			pl->damage();
			
		}
		dx = 0; dy = 0;
	}
	checkCollisionWithMap(dx, dy);
	if (dx > 0 || dy > 0) state = move;
	x += dx;
	y += dy;
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
	angle = (atan2(pl->y - y, pl->x - x)) * 180 / 3.14159265;
	sprite.setRotation(angle);
	sprite.setPosition(x, y);
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
				dx = 0; dy = 0;
			}
		}

}