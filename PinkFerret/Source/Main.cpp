#include <iostream> 
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "level.h"
#include "TinyXML/tinyxml.h"

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

	Player player(300, 300, lvl);
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


		Vector2i pixelPos = Mouse::getPosition(window);
		Vector2f pos = window.mapPixelToCoords(pixelPos);


		player.update(time, pos);


		window.clear();
		
		/////////////////////////////Рисуем карту/////////////////////
		window.clear(Color(77, 83, 140));
		lvl.Draw(window);
		sp = player.getSprite();
		window.draw(sp);
		window.setView(player.getViev());
		window.display();

	}

	return 0;
}