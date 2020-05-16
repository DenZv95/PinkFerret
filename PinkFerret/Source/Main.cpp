#include <iostream> 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "level.h"
#include "TinyXML/tinyxml.h"
#include "Animation.h"
#include "Entity.h"
#include <list>
#include "Bullet.h"
#include "Zombie.h"
#include "Menu.h"
#include "Hud.h"

using namespace sf;

bool startGame() {
	RenderWindow window(sf::VideoMode(1280, 720), "Game");

	Menu menu(window.getSize().x, window.getSize().y);
	menu.draw(window);

	bool isFullsceen = true;

	Hud hud = Hud();
	Clock clock;
	Level lvl;
	lvl.LoadFromFile("Media/Map/level1.tmx");

	
	float time;
	
	Music music;
	music.openFromFile("Media/Sound/Music/game.ogg");
	music.setVolume(10);
	music.play();
	bool musicOn = true;

	Player* player = new Player(lvl);
	//player->settings(300, 300, 190, 180, 1);
	//player->settings(800, 300, 190, 180, 1);
	player->settings(2400, 2200, 190, 180, 1);
	player->entitys.push_back(player);

	Zombie* zombie = new Zombie(lvl, player);
	zombie->settings(2700, 2300, 190, 180, 1);
	player->entitys.push_back(zombie);

	Zombie* zombie2 = new Zombie(lvl, player);
	zombie2->settings(2700, 2700, 190, 180, 1);
	player->entitys.push_back(zombie2);

	Zombie* zombie3 = new Zombie(lvl, player);
	zombie3->settings(1700, 2200, 190, 180, 1);
	player->entitys.push_back(zombie3);

	Zombie* zombie4 = new Zombie(lvl, player);
	zombie4->settings(1700, 2700, 190, 180, 1);
	player->entitys.push_back(zombie4);

	Zombie* zombie5 = new Zombie(lvl, player);
	zombie5->settings(1700, 1600, 190, 180, 1);
	player->entitys.push_back(zombie5);

	Zombie* zombie6 = new Zombie(lvl, player);
	zombie6->settings(2300, 1900, 190, 180, 1);
	player->entitys.push_back(zombie6);

	while (window.isOpen())
	{
		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case Keyboard::F1:
					if (false == isFullsceen)
					{
						window.create(VideoMode(1280, 720), "Pink Ferret", Style::Default);
						isFullsceen = true;
					}
					else
					{
						window.create(VideoMode(1280, 720), "Pink Ferret", Style::Fullscreen);
						isFullsceen = false;
					}
					break;
				
				case Keyboard::F2:
					if (true == musicOn)
					{
						music.pause();
						musicOn = false;
					}
					else
					{
						music.play();
						musicOn = true;
					}
					break;
				}
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}

		player->handleInput(event, time);


		for (auto a : player->bullets)
		{
			if (a->life)
			{
				for (auto b : player->entitys)
				{
					if (b->name == "Zombie" && a->name == "Bullet")
						if (a->getRect().intersects(b->getRect()))
						{
							a->damage();
							b->damage();
						}
				}
			}
		}

		for (auto i = player->entitys.begin(); i != player->entitys.end();)
		{
			Entity* e = *i;

			e->update(time);

			i++;
		}


		for (auto i = player->bullets.begin(); i != player->bullets.end();)
		{
			Entity* e = *i;

			e->update(time);

			if (e->life == false)
			{
				i = player->bullets.erase(i);
				delete e;
			}
			else i++;
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape)) { return true; }

		window.clear();

		window.clear(Color(77, 83, 140));
		lvl.Draw(window);
		for (auto i : player->entitys)
			i->draw(window, time);

		for (auto i : player->bullets)
			i->draw(window, time);

		hud.draw(window, *player);
		window.display();

	}

}

void gameRunning() {
	if (startGame()) { gameRunning(); }
}

int main()
{
	gameRunning();

	return 0;
}