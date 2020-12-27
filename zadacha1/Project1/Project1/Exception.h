#pragma once
#include <string>

//Класс исключения, наследуется от стандартного класса исключений
class Exception : public std::exception
{
private:
	std::string msg; //Сообщение об ошибке
public:
	~Exception();

	Exception(const std::string&);

	virtual const char* what() const;
};