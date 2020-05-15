#include "PasiveZombieState.h"
#include "../Zombie.h"
#include"../Player.h"

PasiveZombieState::PasiveZombieState()
{
	texture.loadFromFile("Media/zombie/zombie-idle.png");
	animation = new Animation(texture, 0, 0, 241, 222, 1, 0.007f);
}

PasiveZombieState::~PasiveZombieState()
{
}
/**/
Sprite PasiveZombieState::draw(float time)
{
	animation->update(time);
	return animation->sprite;
}

ZombieState  * PasiveZombieState::Update(Zombie& zombie, Player& player, float time)
{
	
	if (zombie.life < 200)
		//return zombie.States.getDeadState();

	return nullptr;
}
