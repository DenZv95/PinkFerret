#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Animation
{
public:
    float Frame, speed = 0;
    Sprite sprite;
    std::vector<IntRect> frames; 
    Animation();
    Animation(Texture& t, int x, int y, int w, int h, int count, float Speed);
    void update();
    bool isEnd();

};