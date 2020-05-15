#include "Zombie.h"

Zombie::Zombie(Level& level, Player* player)
{

	life = 100;
	name = "Zombie";
	obj = level.GetAllObjects();
	pl = player;
	States = StaticStateZombie();
	state_ = States.getPasiveState();
}

void Zombie::update(float time)
{
	ZombieState* state = state_->Update(*this, *pl, time);
	if (state != nullptr)
	{
		state_ = state;
	}
	//dx = cos(angle * 0.017453f) * 0.1 * time;
 //   dy = sin(angle * 0.017453f) * 0.1 * time;
	//if (getRect().intersects(pl->getRect()))
	//{
	//	if (state != meleeattack) {
	//		state = meleeattack;
	//		pl->damage();
	//		
	//	}
	//	dx = 0; dy = 0;
	//}
	//checkCollisionWithMap(dx, dy);
	//if (dx > 0 || dy > 0) state = move;
	//x += dx;
	//y += dy;
}

void Zombie::draw(RenderWindow& window, float time)
{

	angle = (atan2(pl->y - y, pl->x - x)) * 180 / 3.14159265;
	sprite = state_->draw(time);
	sprite->setRotation(angle);
	sprite->setPosition(x, y);
	window.draw(*sprite);
	/*switch (state)
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
	window.draw(sprite);*/
}

void Zombie::Meleeattack()
{
	//if (amimationFinish) {
	//	state = meleeattack;
	//}
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