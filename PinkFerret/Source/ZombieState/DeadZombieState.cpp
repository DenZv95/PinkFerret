#include "DeadZombieState.h"
#include "../Zombie.h"
#include"../Player.h"

DeadZombieState::DeadZombieState()
{
	deadTexture.loadFromFile("Media/zombie/zombie-idledead.png");
	aDead = new Animation(deadTexture, 0, 0, 260, 230, 1, 0.007f);

	angle = (atan2(241 - 258, 241 - 144)) * 180 / 3.14159265;
}
//123
DeadZombieState::~DeadZombieState()
{
}

sf::Sprite* DeadZombieState::draw(float time)
{
	aDead->update(time);
	aDead->sprite.setRotation(angle);
	return &(aDead->sprite);
}

ZombieState* DeadZombieState::Update(Zombie& zombie, Player& player, float time)
{
	if (life){
		angle = (atan2(player.y - zombie.y, player.x - zombie.x)) * 180 / 3.14159265;
		life = false;
	}
	return nullptr;
}
