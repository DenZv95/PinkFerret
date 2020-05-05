#include "Entity.h"
Entity::Entity()
{
    life = 1;
}

void Entity::settings(Animation& a, int X, int Y, float Angle, int radius)
{
    anim = a;
    x = X; y = Y;
    angle = Angle;
    R = radius;
}

void Entity::update() {};

void Entity::draw(RenderWindow& app)
{
    anim.sprite.setPosition(x, y);
    anim.sprite.setRotation(angle + 90);
    app.draw(anim.sprite);

    CircleShape circle(R);
    circle.setFillColor(Color(255, 0, 0, 170));
    circle.setPosition(x, y);
    circle.setOrigin(R, R);
    //app.draw(circle);
}

Entity::~Entity() {};