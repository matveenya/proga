#include "Exception.h"

//Деструктор
Exception::~Exception()
{
}

//Конструктор с параметрами
Exception::Exception(const std::string& newMsg) : msg(newMsg)
{
}

//Виртуальная функция, возвращающая сообщение об ошибке
const char* Exception::what() const
{
	return msg.c_str();
}