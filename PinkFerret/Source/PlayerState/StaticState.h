#include "PlayerState.h"
#include "MovePlayerState.h"
#include "MeleeattackPlayerState.h"
#include "ReloadPlayerState.h"

class StaticState
{
public:
	StaticState();
	PlayerState* getMoveState();
	PlayerState* getMeleeattackState();
	PlayerState* getReloadState();
private:
	MovePlayerState* Move;
	MeleeattackPlayerState* Meleeattack;
	ReloadPlayerState* Reload;
};