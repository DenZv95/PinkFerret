#include "Entity.h"


class Bullet : public Entity
{
public:
    Animation anim;
    Bullet(Animation& a, Level& level);
    void draw(RenderWindow& app, float time) override;
    void update() override;
private:
    void checkCollisionWithMap(float Dx, float Dy) override;
};