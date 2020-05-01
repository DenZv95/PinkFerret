#include <iostream> 
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "map.h"

using namespace sf;
int main()
{
	RenderWindow window(sf::VideoMode(1280, 1024), "Game");
	float dX = 0;
	float dY = 0;

	Clock clock;
	bool stop = true;
	Player player(300, 300);
	Sprite sp;


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


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}



		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
			player.Move(-0.12f, 0.f, time);
		}


		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
			player.Move(0.12, 0, time);
		}

		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
			player.Move(0, -0.12, time);
		}

		if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
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


		Vector2i pixelPos = Mouse::getPosition(window);//�������� ����� �������
		Vector2f pos = window.mapPixelToCoords(pixelPos);//��������� �� � ������� (������ �� ����� ����)


		player.update(time, pos);//�������� ������ p ������ Player � ������� ������� sfml, ��������� ����� � �������� ��������� ������� update. ��������� ����� �������� ����� ���������


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
		window.draw(sp);//������ ������ ������� p ������ player
		window.setView(player.getViev());
		window.display();

	}

	return 0;
}