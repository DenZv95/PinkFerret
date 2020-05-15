#include "MeleeattackZombieState.h"
#include "../Player.h"

MeleeattackZombieState::MeleeattackZombieState()
{
	texture.loadFromFile("Media/zombie/zombie-attack.png");
	animation  = new Animation(texture, 0, 0, 318, 294, 9, 0.012f);
}

MeleeattackZombieState::~MeleeattackZombieState()
{
}
/**/
sf::Sprite* MeleeattackZombieState::draw(float time)
{
	animation->update(time);
	return &(animation->sprite);
}

ZombieState* MeleeattackZombieState::Update(Zombie& zombie, Player& player, float time)
{


	if (animation->isEnd())
	{
		//return new MovePlayerState();
		//return player.States.getMoveState();
	}

	if (player.life < 1)
		//return player.States.getDeadState();

	return nullptr;
}
