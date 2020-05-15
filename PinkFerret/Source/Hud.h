#include "Animation.h"
#include <sstream>
#include "Player.h"
class Hud
{
public:
	Hud();
	Texture hp_texture;
	Texture ammo_texture;
	Animation* aAmmo;
	Animation* aHP;
    void draw(RenderWindow& window, Player& plauer);
private:
	Font font;
	Vector2u sizeWindow;
};