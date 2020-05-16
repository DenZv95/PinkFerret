#include "MeleeattackZombieState.h"
#include "../Zombie.h"
#include "../Player.h"

MeleeattackZombieState::MeleeattackZombieState()
{
	texture.loadFromFile("Media/zombie/zombie-attack.png");
	animation  = new Animation(texture, 0, 0, 318, 294, 9, 0.012f);
}

MeleeattackZombieState::~MeleeattackZombieState()
{
}

sf::Sprite* MeleeattackZombieState::draw(float time)
{
	animation->update(time);
	animation->sprite.setRotation(angle);
	return &(animation->sprite);
}

ZombieState* MeleeattackZombieState::Update(Zombie& zombie, Player& player, float time)
{

	angle = (atan2(player.y - zombie.y, player.x - zombie.x)) * 180 / 3.14159265;

	if (animation->isEnd())
	{
		return zombie.States.getMoveState();
	}

	if (zombie.life < 1)
		return zombie.States.getDeadState();

	return nullptr;
}
