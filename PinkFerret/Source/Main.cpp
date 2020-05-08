#include <iostream> 
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "level.h"
#include "TinyXML/tinyxml.h"
#include "Animation.h"
#include "Entity.h"
#include <list>
#include "Bullet.h"
#include "Zombie.h"

using namespace sf;
int main()
{
	RenderWindow window(sf::VideoMode(1280, 800), "Game");
	float dX = 0;
	float dY = 0;

	Clock clock;
	bool stop = true;
	Level lvl;
	lvl.LoadFromFile("Media/Map/level1.tmx");


	Texture sBullet_texture;
	sBullet_texture.loadFromFile("Media/survivor/FullMetalJacket.png");
	Animation sBullet(sBullet_texture, 0, 0, 5, 4, 1, 0.8);
	std::list<Entity*> entities;
	float time;


	Player* player = new Player(lvl);
	player->settings(300, 300, 190, 180, 1);
	entities.push_back(player);

	Zombie* zombie = new Zombie(lvl, player);
	zombie->settings(600, 300, 190, 180, 1);
	entities.push_back(zombie);
	Sprite sp;



	while (window.isOpen())
	{

		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();


			/*
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Space)
				{
					Bullet* b = new Bullet();
					//x = 20 * cos(angle) - 30 * sin(angle)
					//y = 20 * sin(angle) + 30 * cos(angle)
					//b->settings(sBullet, p->x, p->y, p->angle, 10);
					b->settings(sBullet, p->x + (100 * cos(p->angle) - 100 * sin(p->angle)), p->y + (100 * sin(p->angle) + 100 * cos(p->angle)), p->angle, 10);

					entities.push_back(b);
				}
				*/
		}



		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
			player->Move(-0.12f, 0.f, time);
		}


		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
			player->Move(0.12f, 0.f, time);
		}

		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
			player->Move(0.f, -0.12f, time);
		}

		if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
			player->Move(0.f, 0.12f, time);
		}


		if (Mouse::isButtonPressed(Mouse::Left)) {
			player->Shoot();
			Bullet* b = new Bullet(sBullet, lvl);

			//b->settings(sBullet, p->x, p->y, p->angle, 10);
			b->settings(player->x + (112 * cos(player->angle * 0.017453f) - 48 * sin(player->angle * 0.017453f)), player->y + (112 * sin(player->angle * 0.017453f) + 48 * cos(player->angle * 0.017453f)), 4, 5, player->angle);
			entities.push_back(b);
		}

		if (Mouse::isButtonPressed(Mouse::Right)) {
			player->Meleeattack();
		}

		if (Keyboard::isKeyPressed(Keyboard::R)) {
			player->Reload();
		}


		Vector2i pixelPos = Mouse::getPosition(window);
		Vector2f pos = window.mapPixelToCoords(pixelPos);


		//player.update(time, pos);
		for (auto i = entities.begin(); i != entities.end();)
		{
			Entity* e = *i;

			e->update();
			//e->anim.update();

			if (e->life == false) { i = entities.erase(i); delete e; }
			else i++;
		}


		window.clear();

		/////////////////////////////Цисуем/////////////////////
		window.clear(Color(77, 83, 140));
		lvl.Draw(window);
		for (auto i : entities) i->draw(window, time);
		window.display();

	}

	return 0;
}