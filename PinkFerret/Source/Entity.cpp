#include "Entity.h"
Entity::Entity()
{
    life = 1;
    x, y, dx, dy, height, width = 1;
    angle = 0;
}

void Entity::settings(int X, int Y, float Height, float Width, float Angle)
{

    x = X; y = Y;
    height = Height;
    width = Width;
    angle = Angle;
}

FloatRect Entity::getRect() {
    return FloatRect(x - height/2, y - width/2, height, width);
}


Entity::~Entity() {};