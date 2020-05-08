#pragma once
#include "Animation.h"

class Entity
{
public:
    float x, y, dx, dy, height, width, angle = 1;
    bool life = 0;
    std::string name;


    Entity();
    virtual ~Entity();

    void settings( int X, int Y, float height = 1, float width = 1, float Angle = 1);
    virtual void update() = 0;
    virtual void draw(RenderWindow& app) = 0;
    FloatRect getRect();
 
};