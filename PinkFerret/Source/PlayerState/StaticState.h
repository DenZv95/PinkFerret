#include "PlayerState.h"
#include "MovePlayerState.h"
#include "MeleeattackPlayerState.h"

class StaticState
{
public:
	StaticState();
	PlayerState* getMoveState();
	PlayerState* getMeleeattackState();
private:
	MovePlayerState* Move;
	MeleeattackPlayerState* Meleeattack;
};