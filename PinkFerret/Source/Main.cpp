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


using namespace sf;

bool startGame() {
	RenderWindow window(sf::VideoMode(1280, 800), "Game");

	Menu menu(window.getSize().x, window.getSize().y);
	menu.draw(window);

	bool isFullsceen = true;

	Clock clock;

	Level lvl;
	lvl.LoadFromFile("Media/Map/level1.tmx");

	Texture sBullet_texture;
	sBullet_texture.loadFromFile("Media/survivor/FullMetalJacket.png");
	Animation sBullet(sBullet_texture, 0, 0, 5, 4, 1, 0.8);
	std::list<Entity*> entities;
	float time;

	SoundBuffer shootBuffer;//создаём буфер для звука
	shootBuffer.loadFromFile("Media/shoot.wav");//загружаем в него звук
	Sound shooting(shootBuffer);//создаем звук и загружаем в него звук из буфера

	Music music;//создаем объект музыки
	music.openFromFile("Media/sailor.ogg");//загружаем файл
	bool musicOn = true;

	Player* player = new Player(lvl);
	//player->settings(300, 300, 190, 180, 1);
	//player->settings(800, 300, 190, 180, 1);
	player->settings(800, 2200, 190, 180, 1);
	entities.push_back(player);

	Zombie* zombie = new Zombie(lvl, player);
	zombie->settings(2700, 2300, 190, 180, 1);
	entities.push_back(zombie);

	Zombie* zombie2 = new Zombie(lvl, player);
	zombie2->settings(2700, 2700, 190, 180, 1);
	entities.push_back(zombie2);

	Zombie* zombie3 = new Zombie(lvl, player);
	zombie3->settings(1700, 2200, 190, 180, 1);
	entities.push_back(zombie3);

	Zombie* zombie4 = new Zombie(lvl, player);
	zombie4->settings(1700, 2700, 190, 180, 1);
	entities.push_back(zombie4);

	Zombie* zombie5 = new Zombie(lvl, player);
	zombie5->settings(1700, 1600, 190, 180, 1);
	entities.push_back(zombie5);

	Zombie* zombie6 = new Zombie(lvl, player);
	zombie6->settings(2300, 1900, 190, 180, 1);
	entities.push_back(zombie6);


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
						window.create(VideoMode(1280, 800), "Pink Ferret", Style::Default);
						isFullsceen = true;
					}
					else
					{
						window.create(VideoMode(1280, 800), "Pink Ferret", Style::Fullscreen);
						isFullsceen = false;
					}
					break;
				
				case Keyboard::F2:
					if (false == musicOn)
					{
						music.play();//воспроизводим музыку
						musicOn = true;
					}
					else
					{
						music.pause();//воспроизводим музыку
						musicOn = false;
					}
					break;
					/*case Keyboard::Escape:
						//menu.draw(window);
						window.close();
						break;*/
				}
			}
			if (event.type == sf::Event::Closed)
				window.close();
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
			player->Shoot(entities, sBullet, lvl);

		}

		if (Mouse::isButtonPressed(Mouse::Right)) {
			player->Meleeattack(entities);
		}

		if (Keyboard::isKeyPressed(Keyboard::R)) {
			player->Reload();
		}


		for (auto a : entities)
		{
			if (a->life)
			{
				for (auto b : entities)
				{
					if (a->name == "Zombie" && b->name == "Bullet")
						if (a->getRect().intersects(b->getRect()))
						{
							a->damage();
							b->damage();
						}
				}
			}
		}

		for (auto i = entities.begin(); i != entities.end();)
		{
			Entity* e = *i;

			e->update(time);
			//e->anim.update();

			if (e->life == false)
			{
				i = entities.erase(i);
				if (e->name != "Player")
					delete e;
			}
			else i++;
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape)) { return true; }

		window.clear(Color(77, 83, 140));
		lvl.Draw(window);
		for (auto i : entities) i->draw(window, time);
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