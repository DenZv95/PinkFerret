#include "Entity.h"
#include <Objects.h>
#include <level.h>

class Bullet : public Entity
{
public:
    Animation anim;
    Bullet(Animation& a, Level& level);
    void draw(RenderWindow& app, float time) override;
    void update() override;
private:
    std::vector<Object> obj;
    void checkCollisionWithMap(float Dx, float Dy);
};