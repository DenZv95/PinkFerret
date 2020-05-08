#include "Entity.h"
Entity::Entity()
{
    life = 1;
    x = 1; 
    y = 1; 
    dx = 1; 
    dy = 1; 
    height = 1;
    width = 1;
    angle = 0;
}

void Entity::settings(int X, int Y, float Height, float Width, float Angle)
{
    x = X; 
    y = Y;
    height = Height;
    width = Width;
    angle = Angle;
}


void Entity::damage()
{
    life -= 10;
    if (life < 1) life = 0;
}

FloatRect Entity::getRect() 
{
    return FloatRect(x - height/2, y - width/2, height, width);
}


Entity::~Entity() {};