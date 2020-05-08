#pragma once
#include <string>
#include <SFML\Graphics.hpp>

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
