#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "tinyxml.h"

struct Object
{
	int GetPropertyInt(std::string name);//����� �������� ������� � ����� ������
	float GetPropertyFloat(std::string name);
	std::string GetPropertyString(std::string name);

	std::string name;//�������� ���������� name ���� string
	std::string type;//� ����� ���������� type ���� string
	sf::Rect<float> rect;//��� Rect � �������� ����������
	std::map<std::string, std::string> properties;//������ ������������ ������. ���� - ��������� ���, �������� - ���������

	sf::Sprite sprite;//�������� ������
};

struct Layer//����
{
	int opacity;//�������������� ����
	std::vector<sf::Sprite> tiles;//���������� � ������ �����
};

class Level//������� ����� - �������
{
public:
	bool LoadFromFile(std::string filename);//���������� false ���� �� ���������� ���������
	Object GetObject(std::string name);
	std::vector<Object> GetObjects(std::string name);//������ ������ � ��� �������
	std::vector<Object> GetAllObjects();//������ ��� ������� � ��� �������
	void Draw(sf::RenderWindow& window);//������ � ����
	sf::Vector2i GetTileSize();//�������� ������ �����

private:
	int width, height, tileWidth, tileHeight;//� tmx ����� width height � ������,����� ������ �����
	int firstTileID;//�������� ���� ������� �����
	sf::Rect<float> drawingBounds;//������ ����� ����� ������� ������
	sf::Texture tilesetImage;//�������� �����
	std::vector<Object> objects;//������ ���� �������, ������� �� �������
	std::vector<Layer> layers;
};

///////////////////////////////////////


int Object::GetPropertyInt(std::string name)//���������� ����� �������� � ����� ������
{
	return atoi(properties[name].c_str());
}

float Object::GetPropertyFloat(std::string name)
{
	return strtod(properties[name].c_str(), NULL);
}

std::string Object::GetPropertyString(std::string name)//�������� ��� � ���� ������.����� �������
{
	return properties[name];
}



#endif
