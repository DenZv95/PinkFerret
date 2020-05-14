#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"

using namespace sf;

/*void menu(RenderWindow & window) {
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("Media/New Game.png");
	menuTexture2.loadFromFile("Media/Option.png");
	menuTexture3.loadFromFile("Media/Exit.png");
	menuBackground.loadFromFile("Media/background.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(100, 30);
	menu2.setPosition(100, 90);
	menu3.setPosition(100, 150);
	menuBg.setPosition(345, 0);

	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		menu1.setColor(Color::Black);
		menu2.setColor(Color::Black);
		menu3.setColor(Color::Black);
		menuNum = 0;
		window.clear(Color(255, 181, 221));

		if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::White); menuNum = 1; }
		if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::White); menuNum = 2; }
		if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::White); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { window.close(); isMenu = false; }

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
	////////////////////////////////////////////////////
}*/

bool startGame() {
	sf::RenderWindow window(sf::VideoMode(640, 480), "Pink Ferret");
	Menu menu(window.getSize().x, window.getSize().y);
	
	bool isFullsceen = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{

			}
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
		menu.draw(window);
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