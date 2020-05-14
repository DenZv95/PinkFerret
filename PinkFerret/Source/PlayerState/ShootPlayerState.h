#include "../Animation.h"
#include "../Player.h"

class	ShootPlayerState : public PlayerState
{
public:
	ShootPlayerState();
	~ShootPlayerState();
	virtual Sprite draw(float time);
	virtual PlayerState* handleInput(Player& player, Event event, float time);
private:
	Texture shoot_texture;
	Animation* aShoot;
};