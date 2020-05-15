#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(RenderWindow& window);
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	Font font;
	Texture aboutTexture, menuBackground;
	Sprite menuBg;
	Vector2u TextureSize;  //Added to store texture size.
	Vector2u WindowSize;   //Added to store window size.;
	Text menu[MAX_NUMBER_OF_ITEMS];
};

