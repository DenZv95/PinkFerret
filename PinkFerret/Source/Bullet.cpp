#include "Bullet.h"
float DEGTORAD = 0.017453f;
const int W = 1200;
const int H = 800;

Bullet::Bullet(Animation& a)
{
    name = "bullet";
    anim = a;
}

void Bullet::draw(RenderWindow& app, float time)
{
    anim.sprite.setPosition(x, y);
    anim.sprite.setRotation(angle);
    anim.update(time);
    app.draw(anim.sprite);
}

void Bullet::update()
{
    dx = cos(angle * DEGTORAD) * 6;
    dy = sin(angle * DEGTORAD) * 6;
    x += dx;
    y += dy;

    if (x > W || x<0 || y>H || y < 0) life = 0;

}