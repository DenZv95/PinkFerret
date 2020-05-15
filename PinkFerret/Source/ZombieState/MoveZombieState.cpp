#include "MoveZombieState.h"
#include "../Zombie.h"
#include"../Player.h"

MoveZombieState::MoveZombieState()
{
	move_texture.loadFromFile("Media/zombie/zombie-idle.png");
	aMove = new Animation(move_texture, 0, 0, 241, 222, 17, 0.007f);
}
//123
MoveZombieState::~MoveZombieState()
{
}

sf::Sprite* MoveZombieState::draw(float time)
{
	aMove->update(time);
	aMove -> sprite.setRotation(angle);
	return &(aMove->sprite);
}

ZombieState* MoveZombieState::Update(Zombie& zombie, Player& player, float time)
{
	angle = (atan2(player.y - zombie.y, player.x - zombie.x)) * 180 / 3.14159265;
	dx = cos(angle * 0.017453f) * 0.1 * time;
	dy = sin(angle * 0.017453f) * 0.1 * time;
	
	if (zombie.getRect().intersects(player.getRect()))
	{
		dx = 0; dy = 0;
		player.damage();
		return zombie.States.getMeleeattackState();
	}
	
	if (zombie.life < 1)
		return zombie.States.getDeadState();

	zombie.x += dx;
	zombie.y += dy;

	return nullptr;
}
