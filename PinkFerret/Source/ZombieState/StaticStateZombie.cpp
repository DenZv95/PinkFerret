#include "StaticStateZombie.h"

StaticStateZombie::StaticStateZombie()
{
	Move = new MoveZombieState();
	Meleeattack = new MeleeattackZombieState();
	Pasive = new PasiveZombieState();
	Dead = new DeadZombieState();
}

ZombieState* StaticStateZombie::getMoveState()
{
	return Move;
}

ZombieState* StaticStateZombie::getMeleeattackState()
{
	return Meleeattack;
}

ZombieState* StaticStateZombie::getPasiveState()
{
	return Pasive;
}

ZombieState* StaticStateZombie::getDeadState()
{
	return Dead;
}
