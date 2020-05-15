#pragma once
#include "../Animation.h"
#include <ZombieState.h>

using namespace sf;
class PasiveZombieState : public ZombieState
{
public:
	PasiveZombieState();
	virtual ~PasiveZombieState();
	virtual Sprite* draw(float time);
	virtual ZombieState* Update(Zombie& zombie, Player& player, float time);
private:
	Texture texture;
	Animation* animation;
	float angle;
};
