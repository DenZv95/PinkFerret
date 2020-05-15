#include "Hud.h"

Hud::Hud()
{
	font.loadFromFile("Media/ZXSpectrum.ttf");
	hp_texture.loadFromFile("Media/Hud/HitPoints.png");
	ammo_texture.loadFromFile("Media/Hud/Ammo.png");
	aHP = new Animation(hp_texture, 0, 0, 40, 40, 1, 1);
	aAmmo = new Animation(ammo_texture, 0, 0, 40, 40, 1, 1);
}

void Hud::draw(RenderWindow& window, Player& player)
{

	sizeWindow = window.getSize();
	aHP->sprite.setPosition(player.x - (sizeWindow.x / 2) + 170, player.y - (sizeWindow.y / 2) + 25);
	window.draw(aHP->sprite);

	std::ostringstream playerHP;
	Text textHp("", font, 60);
	playerHP << player.life;
	textHp.setString(playerHP.str());
	textHp.setPosition(player.x - int(sizeWindow.x / 2) + 200, player.y - int(sizeWindow.y / 2) - 30);
	textHp.setStyle(sf::Text::Bold);
	window.draw(textHp);

	aAmmo->sprite.setPosition(player.x - int(sizeWindow.x / 2) + 170, player.y - int(sizeWindow.y / 2) + 85);
	window.draw(aAmmo->sprite);

	std::ostringstream playerAmmo;
	playerAmmo << player.ammo;
	Text textAmmo("", font, 60);
	textAmmo.setString(playerAmmo.str());
	textAmmo.setPosition(player.x - (sizeWindow.x / 2) + 200, player.y - (sizeWindow.y / 2) + 35);
	textAmmo.setStyle(sf::Text::Bold);
	window.draw(textAmmo);

	Text fullsc("", font, 40);
	fullsc.setString("Fullscreen: F1");
	fullsc.setPosition(player.x - (sizeWindow.x / 2) + 350, player.y - (sizeWindow.y / 2) - 10);
	fullsc.setStyle(sf::Text::Bold);
	window.draw(fullsc);

	Text music("", font, 40);
	music.setString("Music on/off: F2");
	music.setPosition(player.x - (sizeWindow.x / 2) + 350, player.y - (sizeWindow.y / 2) + 45);
	music.setStyle(sf::Text::Bold);
	window.draw(music);

	Text esc("", font, 40);
	esc.setString("Menu: Ecs");
	esc.setPosition(player.x - (sizeWindow.x / 2) + 700, player.y - (sizeWindow.y / 2) - 10);
	esc.setStyle(sf::Text::Bold);
	window.draw(esc);
}
