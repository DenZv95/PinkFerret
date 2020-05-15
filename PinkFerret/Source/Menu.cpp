#include <SFML/Audio.hpp>
#include "Menu.h"
#include <iostream>

using namespace sf;

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("Media/ZXSpectrum.ttf")) {}
	if (!menuBackground.loadFromFile("Media/background.png")) {}
	
	menu[0].setFont(font);
	menu[0].setCharacterSize(80);
	//menu[0].setFillColor(Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(Vector2f(width / 2.5, height / 2.5));

	/*
	menu[1].setFont(font);
	menu[1].setCharacterSize(58);
	//menu[1].setFillColor(Color::White);
	menu[1].setString("Options");
	menu[1].setPosition(Vector2f(width / 2.5, height / 2));
	*/

	menu[2].setFont(font);
	menu[2].setCharacterSize(80);
	//menu[2].setFillColor(Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(Vector2f(width / 2.5, height / 1.7));

	selectedItemIndex = 0;
}

Menu::~Menu()
{}

void Menu::draw(RenderWindow& window)
{
	Music music;//создаем объект музыки
	music.openFromFile("Media/Sound/Music/menu.ogg");//загружаем файл
	music.setVolume(30);
	music.play();

	SoundBuffer shootBuffer;//создаём буфер для звука
	shootBuffer.loadFromFile("Media/Sound/shoot.wav");//загружаем в него звук
	Sound shooting(shootBuffer);//создаем звук и загружаем в него звук из буфера

	TextureSize = menuBackground.getSize();
	WindowSize = window.getSize();

	float ScaleX = (float)WindowSize.x / TextureSize.x;
	float ScaleY = (float)WindowSize.y / TextureSize.y;     //Calculate scale.

	menuBg.setTexture(menuBackground);
	menuBg.setScale(ScaleX, ScaleY);      //Set scale.

	bool isMenu = 1;
	while (isMenu)
	{
		menu[0].setFillColor(Color::Black);
		//menu[1].setFillColor(Color::Black);
		menu[2].setFillColor(Color::Black);

		std::cout << Mouse::getPosition(window).x << " " << Mouse::getPosition(window).y << std::endl;

		for (int i = 0; i < 3; i++)
		{
			if (menu[i].getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				menu[i].setFillColor(Color::White); selectedItemIndex = i;
			}
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (selectedItemIndex == 0) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			//if (selectedItemIndex == 1) { window.draw(menuBg); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (selectedItemIndex == 2) { window.close(); isMenu = false; }
		}

		window.clear();
		window.draw(menuBg);

		for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
		{
			window.draw(menu[i]);
		}

		window.display();
	}
}