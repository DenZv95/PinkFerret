#include "Hud.h"

Hud::Hud()
{
	font.loadFromFile("Media/CyrilicOld.ttf");
	hp_texture.loadFromFile("Media/Hud/HitPoints.png");
	ammo_texture.loadFromFile("Media/Hud/Ammo.png");
	aHP = new Animation(hp_texture, 0, 0, 40, 40, 1, 1);
	aAmmo = new Animation(ammo_texture, 0, 0, 40, 40, 1, 1);
}

void Hud::draw(RenderWindow& window, int HP, int ammo, float X, float Y)
{

	sizeWindow = window.getSize();

	aHP->sprite.setPosition(X - (sizeWindow.x / 2) + 30, Y - (sizeWindow.y / 2) + 60);
	window.draw(aHP->sprite);

	std::ostringstream playerHP;
	Text textHp("", font, 50);
	playerHP << HP;
	textHp.setString(playerHP.str());
	textHp.setPosition(X - int(sizeWindow.x / 2) + 60, Y - int(sizeWindow.y / 2) + 26);
	textHp.setStyle(sf::Text::Bold);
	window.draw(textHp);

	aAmmo->sprite.setPosition(X - int(sizeWindow.x / 2) + 30, Y - int(sizeWindow.y / 2) + 120);
	window.draw(aAmmo->sprite);

	std::ostringstream playerAmmo;
	playerAmmo << ammo;
	Text textAmmo("", font, 50);
	textAmmo.setString(playerAmmo.str());
	textAmmo.setPosition(X - (sizeWindow.x / 2) + 60, Y - (sizeWindow.y / 2) + 86);
	textAmmo.setStyle(sf::Text::Bold);
	window.draw(textAmmo);


}
