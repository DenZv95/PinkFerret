#include <SFML/Graphics.hpp>
//#include "../Entity.h"
//#include "../Player.h"
//#include "MovePlayerState.h"
class Player;
class MovePlayerState;
class MeleeattackPlayerState;
//class ShootPlayerState;
//class ReloadPlayerState;


using namespace sf;
class PlayerState
{
public:		
	static MovePlayerState move;
	static MeleeattackPlayerState meleeattack;
	PlayerState();
	virtual ~PlayerState();
	virtual Sprite draw(float time) = 0;
	virtual PlayerState* handleInput(Player& player, Event event, float time) = 0;
};