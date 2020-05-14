#include "Menu.h"

using namespace sf;

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("Media/16586.ttf")) {}

	menuBackground.loadFromFile("Media/background.png");
	aboutTexture.loadFromFile("Media/background.png");

	menu[0].setFont(font);
	menu[0].setCharacterSize(48);
	//menu[0].setFillColor(Color::Red);
	menu[0].setString("Play");
	//menu[0].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	menu[0].setPosition(100, 30);

	menu[1].setFont(font);
	menu[1].setCharacterSize(48); 
	//menu[1].setFillColor(Color::White);
	menu[1].setString("Options");
	//menu[1].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	menu[1].setPosition(100, 90);

	menu[2].setFont(font);
	menu[2].setCharacterSize(48);	
	//menu[2].setFillColor(Color::White);
	menu[2].setString("Exit");
	//menu[2].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	menu[2].setPosition(100, 150);

	selectedItemIndex = 0;
}

Menu::~Menu()
{
}

void Menu::draw(RenderWindow &window) 
{	
	
	/*
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}*/

	Sprite about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	
	menuBg.setPosition(345, 0);
	
	while (isMenu)
	{
		menu[0].setFillColor(Color::White);
		menu[1].setFillColor(Color::White);
		menu[2].setFillColor(Color::White);
		
		window.clear(Color(255, 181, 221));

		if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { menu[0].setFillColor(Color::Red); selectedItemIndex = 0; }
		if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window))) { menu[1].setFillColor(Color::Red); selectedItemIndex = 1; }
		if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) { menu[2].setFillColor(Color::Red); selectedItemIndex = 2; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (selectedItemIndex == 0) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (selectedItemIndex == 1) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (selectedItemIndex == 2) { window.close(); isMenu = false; }
		}

		window.draw(menuBg);
		for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
		{
			window.draw(menu[i]);
		}

		window.display();
	}

}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}