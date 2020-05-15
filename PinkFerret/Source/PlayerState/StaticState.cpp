#include "StaticState.h"

StaticState::StaticState()
{
	Move = new MovePlayerState();
	Meleeattack = new MeleeattackPlayerState();
	Reload = new ReloadPlayerState();
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
