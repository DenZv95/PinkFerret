#pragma once
#include "../Animation.h"
#include <PlayerState.h>

using namespace sf;
class	ReloadPlayerState : public PlayerState
{
public:
	ReloadPlayerState();
	virtual ~ReloadPlayerState();
	virtual Sprite draw(float time);
	virtual PlayerState* handleInput(Player& player, Event event, float time);
private:
	Texture reload_texture;
	Animation* aReload;
};
