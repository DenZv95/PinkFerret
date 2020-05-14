//#include "PlayerState.h"
#include "../Animation.h"
#include "../Player.h"
//class Player;

class	MeleeattackPlayerState : public PlayerState
{
public:
	MeleeattackPlayerState();
	~MeleeattackPlayerState();
	virtual Sprite draw(float time);
	virtual PlayerState *handleInput(Player& player, Event event, float time);
private:
	Texture meleeattack_texture;
	Animation* aMeleeattack;
};
