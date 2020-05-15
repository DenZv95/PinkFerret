#include "StaticState.h"

StaticState::StaticState()
{
	Move = new MovePlayerState();
	Meleeattack = new MeleeattackPlayerState();
}

PlayerState* StaticState::getMoveState()
{
	return Move;
}

PlayerState* StaticState::getMeleeattackState()
{
	return Meleeattack;
}
