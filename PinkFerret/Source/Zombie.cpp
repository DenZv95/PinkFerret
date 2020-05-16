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
}

void Zombie::draw(RenderWindow& window, float time)
{

	sprite = state_->draw(time);
	sprite->setPosition(x, y);
	window.draw(*sprite);

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