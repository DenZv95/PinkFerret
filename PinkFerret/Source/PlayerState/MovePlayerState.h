//#include "PlayerState.h"
#include "../Animation.h"
#include "../Player.h"

class	MovePlayerState : public PlayerState
{
public:
	MovePlayerState();
	~MovePlayerState();
	virtual Sprite draw(float time);
	virtual PlayerState *handleInput(Player& player, Event event, float time);
private:
	Texture move_texture;
	Animation* aMove;
};
