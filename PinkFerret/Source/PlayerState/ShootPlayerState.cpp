#include "ShootPlayerState.h"
#include "../Player.h"

ShootPlayerState::ShootPlayerState()
{
	shoot_texture.loadFromFile("Media/survivor/handgun/survivor-shoot_handgun.png");
	aShoot = new Animation(shoot_texture, 0, 0, 260, 230, 3, 0.009f);
}

ShootPlayerState::~ShootPlayerState()
{
}

Sprite ShootPlayerState::draw(float time)
{
	aShoot->update(time);
	return aShoot->sprite;
}

PlayerState  *ShootPlayerState::handleInput(Player& player, Event event, float time)
{
	

	if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
		player.Move(-0.12f, 0.f, time);
	}

	if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
		player.Move(0.12f, 0.f, time);
	}

	if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
		player.Move(0.f, -0.12f, time);
	}

	if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
		player.Move(0.f, 0.12f, time);
	}

	if (aShoot->isEnd())
	{
		return player.States.getMoveState();
	}

	if (player.life < 1)
		return player.States.getDeadState();

	return nullptr;
}
