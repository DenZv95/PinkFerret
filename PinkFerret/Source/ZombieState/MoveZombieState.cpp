#include "MoveZombieState.h"
#include "../Zombie.h"
#include"../Player.h"

MoveZombieState::MoveZombieState()
{
	move_texture.loadFromFile("Media/zombie/zombie-idle.png");
	aMove = new Animation(move_texture, 0, 0, 241, 222, 17, 0.007f);

	moveBuffer.loadFromFile("Media/Sound/zombiewalk.wav");
	move = new Sound(moveBuffer);
	move->setVolume(25);
	
	attackBuffer.loadFromFile("Media/Sound/zombieattack.ogg");
	attack = new Sound(attackBuffer);
	attack->setVolume(25);
	
	deathBuffer.loadFromFile("Media/Sound/zombiedeath.wav");
	death = new Sound(deathBuffer);
	death->setVolume(25);
}

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
	if (move->getStatus() == move->Stopped)	move->play();
	angle = (atan2(player.y - zombie.y, player.x - zombie.x)) * 180 / 3.14159265;
	zombie.dx = cos(angle * 0.017453f) * 0.1 * time;
	zombie.dy = sin(angle * 0.017453f) * 0.1 * time;
	zombie.checkCollisionWithMap(dx, dy);
	if (zombie.getRect().intersects(player.getRect()))
	{
		attack->play();
		move->stop();
		dx = 0; dy = 0;
		player.damage();
		return zombie.States.getMeleeattackState();
	}
	
	if (zombie.life < 1)
	{
		death->play();
		return zombie.States.getDeadState();
	}
	zombie.x += zombie.dx;
	zombie.y += zombie.dy;

	return nullptr;
}
