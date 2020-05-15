#include "PlayerState.h"
#include "MovePlayerState.h"
#include "MeleeattackPlayerState.h"
#include "ReloadPlayerState.h"
#include "ShootPlayerState.h"

class StaticState
{
public:
	StaticState();
	PlayerState* getMoveState();
	PlayerState* getMeleeattackState();
	PlayerState* getReloadState();
	PlayerState* getShootState();
private:
	MovePlayerState* Move;
	MeleeattackPlayerState* Meleeattack;
	ReloadPlayerState* Reload;
	ShootPlayerState* Shoot;
};