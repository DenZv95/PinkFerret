#include <iostream> 
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Zombie.h"
#include "map.h"

using namespace sf;
int main()
{
	RenderWindow window(sf::VideoMode(1280, 1024), "Game");
	float dX = 0;
	float dY = 0;

	int tempX = 0;//��������� ����� �.������� �� ����� ������� ���� ���� ����
	int tempY = 0;//����� Y
	float distance = 0;//��� ���������� �� ������� �� ���� �������

	Clock clock;
	bool stop = true;
	Player player(300, 300);

	Zombie zombie(600, 300);
	Sprite sp, zm;
	
	Image map_image;
	map_image.loadFromFile("Media/map.png");
	Texture map;//�������� �����
	map.loadFromImage(map_image);//�������� �������� ���������
	Sprite s_map;//������ ������ ��� �����
	s_map.setTexture(map);//�������� �������� ��������

	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		Vector2i pixelPos = Mouse::getPosition(window);//�������� ����� �������
		Vector2f pos = window.mapPixelToCoords(pixelPos);//��������� �� � ������� (������ �� ����� ����)

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == Event::MouseButtonPressed)//���� ������ ������� ����
				if (event.key.code == Mouse::Left) {//� ������ �����
					if (zombie.Move.getGlobalBounds().contains(pos.x, pos.y))//� ��� ���� ���������� ������� �������� � ������
					{
						//p.sprite.setColor(Color::Green);//������ ������ � �������,��� ����� ������ ������,��� �� ������ ��������� � ����� ������� ���
						zombie.Move.isSelect = true;
					}
				}

			if (zombie.Move.isSelect)//���� ������� ������
				if (event.type == Event::MouseButtonPressed)//���� ������ ������� ����
					if (event.key.code == Mouse::Right) {//� ������ ������
						zombie.Move.isMove = true;//�� �������� ��������
						zombie.Move.isSelect = false;//������ ��� �� ������
						//zombie.Move.setColor(Color::White);//���������� ������� ���� �������
						tempX = pos.x;//�������� ���������� ������� ������� �
						tempY = pos.y;//� Y
					}
		}

		if (zombie.Move.isMove) {
			distance = sqrt((tempX - zombie.Move.x) * (tempX - zombie.Move.x) + (tempY - zombie.Move.y) * (tempY - zombie.Move.y));//������� ��������� (���������� �� ����� � �� ����� �). ��������� ������� ����� �������

			if (distance > 2) {//���� �������� ������� �������� �� ����� �������� ������� �������

				zombie.Move.x += 0.1 * time * (tempX - zombie.Move.x) / distance;//���� �� ���� � ������� ������� �������
				zombie.Move.y += 0.1 * time * (tempY - zombie.Move.y) / distance;//���� �� ������ ��� ��
			}
			else { zombie.Move.isMove = false; std::cout << "priehali\n"; }//������� ��� ��� ������ �� ���� � ������� ������� ��������� � �������
		}

		//player
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			player.Move(-0.12f, 0.f, time);
		}

		if (Keyboard::isKeyPressed(Keyboard::D)) {
			player.Move(0.12, 0, time);
		}

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			player.Move(0, -0.12, time);
		}

		if (Keyboard::isKeyPressed(Keyboard::S)) {
			player.Move(0, 0.12, time);
		}


		if (Mouse::isButtonPressed(Mouse::Left)) {
			player.Shoot();
		}

		if (Mouse::isButtonPressed(Mouse::Right)) {
			player.Meleeattack();
		}

		if (Keyboard::isKeyPressed(Keyboard::R)) {
			player.Reload();
		}

		//zombie
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			zombie.Move(-0.12f, 0.f, time);
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			zombie.Move(0.12, 0, time);
		}

		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			zombie.Move(0, -0.12, time);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			zombie.Move(0, 0.12, time);
		}

		if (Mouse::isButtonPressed(Mouse::Right)) {
			zombie.Meleeattack();
		}

		player.update(time, pos);//�������� ������ p ������ Player � ������� ������� sfml, ��������� ����� � �������� ��������� ������� update. ��������� ����� �������� ����� ���������
		
		zombie.update(time, pos);//�������� ������ p ������ Player � ������� ������� sfml, ��������� ����� � �������� ��������� ������� update. ��������� ����� �������� ����� ���������

		window.clear();

		/////////////////////////////������ �����/////////////////////
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //���� ��������� ������ ������, �� ������ 1� ���������
				if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//���� ��������� ������ s, �� ������ 2� ���������
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//���� ��������� ������ 0, �� ������ 3� ���������


				s_map.setPosition(j * 32, i * 32);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������

				window.draw(s_map);//������ ���������� �� �����
			}
		/////////////////////////////������ �����/////////////////////
		sp = player.getSprite();
		zm = zombie.getSprite();
		window.draw(sp);//������ ������ ������� p ������ player
		window.draw(zm);//������ ������ ������� p ������ player
		window.setView(player.getViev());
		window.display();

	}

	return 0;
}