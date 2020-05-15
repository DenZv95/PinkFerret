#include "MovePlayerState.h"
#include "../Player.h"

MovePlayerState::MovePlayerState()
{
	//PlayerState::move = MovePlayerState();
	move_texture.loadFromFile("Media/survivor/handgun/survivor-move_handgun.png");
	aMove = new Animation(move_texture, 0, 0, 260, 230, 20, 0.007f);

	meleeattackBuffer.loadFromFile("Media/Sound/meleeattack.wav");
	meleeattack = new Sound(meleeattackBuffer);
	
	reloadBuffer.loadFromFile("Media/Sound/reload.wav");
	reload = new Sound(reloadBuffer);
}

MovePlayerState::~MovePlayerState()
{
}
/**/
sf::Sprite MovePlayerState::draw(float time)
{
	aMove->update(time);
	return aMove->sprite;
}

PlayerState* MovePlayerState::handleInput(Player& player, sf::Event event, float time)
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


	if (Mouse::isButtonPressed(Mouse::Left)) {
		if (player.ammo > 0) {
			player.ammo -= 1;
			player.Shoot();
			return player.States.getShootState();
		}
	}

	if (Mouse::isButtonPressed(Mouse::Right)) {
		player.Meleeattack();
		meleeattack->play();
		return player.States.getMeleeattackState();
	}

	if (Keyboard::isKeyPressed(Keyboard::R)) {
		if (player.ammo < 7){
			player.ammo = 7;
			reload->play();
			return player.States.getReloadState();
		}
	}

	if (player.life < 1)
		return player.States.getDeadState();

	return nullptr;
}
