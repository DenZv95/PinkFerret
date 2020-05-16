#include "Player.h"


Player::Player(Level& level)
{	
	shootBuffer.loadFromFile("Media/Sound/shoot.wav");
	shoot = new Sound(shootBuffer);
	shoot->setVolume(12);
	moveBuffer.loadFromFile("Media/Sound/move.wav");
	move = new Sound(moveBuffer);
	
	obj = level.GetAllObjects();
	bullet_texture.loadFromFile("Media/survivor/FullMetalJacket.png");
	aBullet = Animation(bullet_texture, 0, 0, 5, 4, 1, 0.8);
	life = 200;
	name = "Player";
	view.reset(sf::FloatRect(x, y, 1280, 800));
	sprite.setOrigin(260 / 2, 230 / 2);
	States = StaticState();
	state_ = States.getMoveState();
}

void Player::update(float time)
{
	
}

void Player::draw(RenderWindow& window, float time)
{
	Vector2i pixelPos = Mouse::getPosition(window);
	Vector2f positionMouse = window.mapPixelToCoords(pixelPos);

	sprite = state_->draw(time);
	
	sprite.setPosition(x, y);
	if (life > 0)
		angle = (atan2(positionMouse.y - y, positionMouse.x - x)) * 180 / 3.14159265;
	
	sprite.setRotation(angle);
	window.draw(sprite);
	view.setCenter(x + 100, y);
	window.setView(view);
}

void Player::handleInput(Event event, float time)
{
	PlayerState* state = state_->handleInput(*this, event, time);
	if (state != nullptr)
	{
		state_ = state;
	}
}

void Player::checkCollisionWithMap(float Dx, float Dy)
{
	for (int i = 0; i < obj.size(); i++)
	{

		if (getRect().intersects(obj[i].rect))
		{
			if (obj[i].name == "TheWall")
			{

				if (Dy > 0) {
					y = obj[i].rect.top - 90;
				}
				if (Dy < 0) {
					y = obj[i].rect.top + obj[i].rect.height + 90;
				}

				if (Dx > 0) {
					x = obj[i].rect.left - 95;
				}

				if (Dx < 0) {
					x = obj[i].rect.left + obj[i].rect.width + 95;
				}
			}
		}
	}
}

void Player::Move(float dX, float dY, float time)
{
	if (move->getStatus() == move->Stopped)
		move->play();
	x += dX * time;
	y += dY * time;
	checkCollisionWithMap(dX, dY);
	dX = 0;
	dY = 0;
	view.setCenter(x + 100, y);
}


void Player::Meleeattack()
{
	for (auto a : entitys)
	{
		if (a->life)
			if (a->name == "Zombie")
				if (getRect().intersects(a->getRect()))
					a->damage();
	}
}

void Player::Shoot()
{
		if (ammo >= 0)
		{
			shoot->play();
			Bullet* b = new Bullet(aBullet, obj);
			b->settings(x + (112 * cos(angle * 0.017453f) - 48 * sin(angle * 0.017453f)), y + (112 * sin(angle * 0.017453f) + 48 * cos(angle * 0.017453f)), 4, 5, angle);
			bullets.push_back(b);
		}
}