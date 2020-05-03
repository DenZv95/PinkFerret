
#include "Objects.h"

int Object::GetPropertyInt(std::string name)//возвращаем номер свойства в нашем списке
{
	return atoi(properties[name].c_str());
}

float Object::GetPropertyFloat(std::string name)
{
	return strtod(properties[name].c_str(), NULL);
}

std::string Object::GetPropertyString(std::string name)//получить имя в виде строки.вроде понятно
{
	return properties[name];
}