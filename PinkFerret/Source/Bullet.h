#include "Entity.h"


class Bullet : public Entity
{
public:
    Animation anim;
    Bullet(Animation& a);
    void draw(RenderWindow& app) override;
    void update() override;
};