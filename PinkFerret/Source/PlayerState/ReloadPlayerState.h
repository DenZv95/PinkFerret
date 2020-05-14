#include "../Animation.h"
#include "../Player.h"

class	ReloadPlayerState : public PlayerState
{
public:
	ReloadPlayerState();
	~ReloadPlayerState();
	virtual Sprite draw(float time);
	virtual PlayerState *handleInput(Player& player, Event event, float time);
private:
	Texture reload_texture;
	Animation* aReload;
};
