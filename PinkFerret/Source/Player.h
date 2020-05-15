#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <list>
#include <sstream>
#include <PlayerState.h>
#include <StaticState.h>

using namespace sf;

class Player : public Entity
{
public:
	//static MovePlayerState move;
	//static MeleeattackPlayerState meleeattack;
	Player(Level& level);
	void update(float time) override;
	void draw(RenderWindow& app, float time) override;
	void Move(float dX, float dY, float time);
	virtual void handleInput(Event event, float time);
	StaticState States;
private:
	void checkCollisionWithMap(float Dx, float Dy) override;
	
	PlayerState* state_;

	View view;
	Sprite sprite;

	/*(

	Texture meleeattack_texture;
	Texture reload_texture;
	Texture shoot_texture;

	Animation* aMove;
	Animation* aMeleeattack;
	Animation* aReload;
	Animation* aShoot;
	*/
};
/*
class Player : public Entity
{
public:
	Player(Level& level);
	void update(float time) override;
	void draw(RenderWindow& app, float time) override;
	void Meleeattack(std::list<Entity*>& entities);
	void Move(float dX, float dY, float time);
	void Reload();
	void Shoot(std::list<Entity*>& entities, Animation& sBullet, Level& lvl);
	int state = 0;
private:
	View view;
	Hud* hud;
	enum State
	{
		idle,
		move,
		reload,
		shoot,
		meleeattack
	};
	bool amimationFinish, tytyry = 0;
	int ammo = 2;
	void checkCollisionWithMap(float Dx, float Dy) override;
	Texture move_texture;
	Texture meleeattack_texture;
	Texture reload_texture;
	Texture shoot_texture;
	Animation* aMove;
	Animation* aMeleeattack;
	Animation* aReload;
	Animation* aShoot;
	Sprite sprite;
	Font font;

};
*/