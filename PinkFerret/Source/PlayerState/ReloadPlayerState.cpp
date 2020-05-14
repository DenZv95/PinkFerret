#include "ReloadPlayerState.h"

ReloadPlayerState::ReloadPlayerState()
{
	reload_texture.loadFromFile("Media/survivor/handgun/survivor-move_handgun.png");
	aReload = new Animation(reload_texture, 0, 0, 260, 230, 20, 0.007f);
}

ReloadPlayerState::~ReloadPlayerState()
{
}
/**/
Sprite ReloadPlayerState::draw(float time)
{
	aReload->update(time);
	return aReload->sprite;
}

PlayerState  *ReloadPlayerState::handleInput(Player& player, Event event, float time)
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

	return nullptr;
}
