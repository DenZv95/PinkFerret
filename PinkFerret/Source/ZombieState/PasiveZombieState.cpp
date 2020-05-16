#include "PasiveZombieState.h"
#include "../Zombie.h"
#include"../Player.h"

PasiveZombieState::PasiveZombieState()
{
	texture.loadFromFile("Media/zombie/zombie-stop.png");
	animation = new Animation(texture, 0, 0, 241, 222, 1, 0.007f);
	angle = (atan2(241 - 258, 241 - 144)) * 180 / 3.14159265;
}

PasiveZombieState::~PasiveZombieState()
{
}

Sprite* PasiveZombieState::draw(float time)
{

	animation->update(time);
	return &(animation->sprite);
}

ZombieState *PasiveZombieState::Update(Zombie& zombie, Player& player, float time)
{
	if (FloatRect(zombie.x - 500 / 2, zombie.y - 500 / 2, 500, 500).intersects(player.getRect()))
	{
		return zombie.States.getMoveState();
	}

	if (zombie.life < 95)
		return zombie.States.getMoveState();

	return nullptr;
}
