#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"

using namespace sf;

bool startGame() {
	sf::RenderWindow window(sf::VideoMode(640, 480), "Pink Ferret");
	Menu menu(window.getSize().x, window.getSize().y);
	menu.draw(window);
	
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	
	bool isFullsceen = true;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyReleased)
			{
				switch (event.key.code)
				{

				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;
		
				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "Play button has been pressed" << std::endl;
						break;
					case 1:
						std::cout << "Option button has been pressed" << std::endl;
						break;
					case 2:
						window.close();
						break;
					}
					break;

				case Keyboard::Num5:
					if (false == isFullsceen)
					{
						window.create(VideoMode(640, 480), "Pink Ferret", Style::Default);
						isFullsceen = true;
					}
					else
					{
						window.create(VideoMode(640, 480), "Pink Ferret", Style::Fullscreen);
						isFullsceen = false;
					}
					break;
				}
			}
			if (event.type == Event::Closed) 
			{
				window.close();
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Tilde)) { return true; }//если тильда, то перезагружаем игру
		if (Keyboard::isKeyPressed(Keyboard::Escape)) { return false; }//если эскейп, то выходим из игры

		window.clear();
		window.draw(shape);
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