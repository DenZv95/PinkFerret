#include "Bullet.h"

float DEGTORAD = 0.017453f;
const int W = 1200;
const int H = 800;


Bullet::Bullet(Animation& a, Level& level)
{
	obj = level.GetAllObjects();
	name = "Bullet";
	anim = a;
}

void Bullet::draw(RenderWindow& app, float time)
{
    anim.sprite.setPosition(x, y);
    anim.sprite.setRotation(angle);
    anim.update(time);
    app.draw(anim.sprite);
}

void Bullet::update(float time)
{
    dx = cos(angle * DEGTORAD) * 6;
    dy = sin(angle * DEGTORAD) * 6;
    x += dx;
    y += dy;
	checkCollisionWithMap(dx, dy);
}

void Bullet::checkCollisionWithMap(float Dx, float Dy)
{

	for (int i = 0; i < obj.size(); i++)
		if (getRect().intersects(obj[i].rect))
		{
			if (obj[i].name == "TheWall")
			{
				life = false;
			}
		}

}