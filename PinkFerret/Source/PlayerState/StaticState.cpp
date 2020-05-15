#include "StaticState.h"

StaticState::StaticState()
{
	Move = new MovePlayerState();
	Meleeattack = new MeleeattackPlayerState();
	Reload = new ReloadPlayerState();
	Shoot = new ShootPlayerState();
	Dead = new DeadPlayerState();
}

PlayerState* StaticState::getMoveState()
{
	return Move;
}

PlayerState* StaticState::getMeleeattackState()
{
	return Meleeattack;
}

PlayerState* StaticState::getReloadState()
{
	return Reload;
}

PlayerState* StaticState::getShootState()
{
	return Shoot;
}

PlayerState* StaticState::getDeadState()
{
	return Dead;
}