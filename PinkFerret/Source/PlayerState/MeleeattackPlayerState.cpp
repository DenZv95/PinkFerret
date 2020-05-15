#include "MeleeattackPlayerState.h"
#include "../Player.h"

MeleeattackPlayerState::MeleeattackPlayerState()
{
	meleeattack_texture.loadFromFile("Media/survivor/handgun/survivor-meleeattack_handgun.png");
	aMeleeattack = new Animation(meleeattack_texture, -10, 0, 300, 240, 15, 0.01f);
}

MeleeattackPlayerState::~MeleeattackPlayerState()
{
}
/**/
sf::Sprite MeleeattackPlayerState::draw(float time)
{
	aMeleeattack->update(time);
	return aMeleeattack->sprite;
}

PlayerState* MeleeattackPlayerState::handleInput(Player& player, sf::Event event, float time)
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
	if (aMeleeattack->isEnd())
	{
		//return new MovePlayerState();
		return player.States.getMoveState();
	}

	if (player.life < 1)
		return player.States.getDeadState();

	return nullptr;
}
