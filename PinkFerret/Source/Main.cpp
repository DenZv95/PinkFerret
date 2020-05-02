#include <iostream> 
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "level.h"
#include "TinyXML/tinyxml.h"
//$(SolutionDir)\External\TinyXML\TinyXML

using namespace sf;
int main()
{
	RenderWindow window(sf::VideoMode(1280, 1024), "Game");
	float dX = 0;
	float dY = 0;

	Clock clock;
	bool stop = true;
	Level lvl;
	lvl.LoadFromFile("Media/Map/level1.tmx");//загрузили в него карту, внутри класса с помощью методов он ее обработает.
	Player player(300, 300);
	Sprite sp;


	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}



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
			player.Shoot();
		}

		if (Mouse::isButtonPressed(Mouse::Right)) {
			player.Meleeattack();
		}

		if (Keyboard::isKeyPressed(Keyboard::R)) {
			player.Reload();
		}


		Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
		Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)


		player.update(time, pos);//оживляем объект p класса Player с помощью времени sfml, передавая время в качестве параметра функции update. благодаря этому персонаж может двигаться


		window.clear();


		/////////////////////////////Рисуем карту/////////////////////
		window.clear(Color(77, 83, 140));
		lvl.Draw(window);//рисуем новую карту
		/////////////////////////////Рисуем карту/////////////////////
		sp = player.getSprite();
		window.draw(sp);//рисуем спрайт объекта p класса player
		window.setView(player.getViev());
		window.display();

	}

	return 0;
}