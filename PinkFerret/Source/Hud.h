#include "Animation.h"
#include <sstream>
class Hud
{
public:
	Hud();
	Texture hp_texture;
	Texture ammo_texture;
	Animation* aAmmo;
	Animation* aHP;
    void draw(RenderWindow& window, int HP, int ammo, float X, float Y);
private:
	Font font;
	Vector2u sizeWindow;
};