#pragma once
#include "../Animation.h"
#include <PlayerState.h>

class	ShootPlayerState : public PlayerState
{
public:
	ShootPlayerState();
	virtual ~ShootPlayerState();
	virtual Sprite draw(float time);
	virtual PlayerState* handleInput(Player& player, Event event, float time);
private:
	Texture shoot_texture;
	Animation* aShoot;
};