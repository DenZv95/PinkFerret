#include "ZombieState.h"
#include "MoveZombieState.h"
#include "MeleeattackZombieState.h"
#include "PasiveZombieState.h"
#include "DeadZombieState.h"

class StaticStateZombie
{
public:
	StaticStateZombie();
	ZombieState* getMoveState();
	ZombieState* getMeleeattackState();
	ZombieState* getPasiveState();
	ZombieState* getDeadState();
private:
	MoveZombieState* Move;
	MeleeattackZombieState* Meleeattack;
	PasiveZombieState* Pasive;
	DeadZombieState* Dead;
};