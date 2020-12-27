#include "Node.h"

//ƒеструктор
Node::~Node()
{}

// онструктор по умолчанию
Node::Node()
{
	data = 0;
	next = nullptr;
}

// онструктор копировани€
Node::Node(const Node& node)
{
	data = node.data;
	next = node.next;
}

//‘ункци€, возвращающа€ данные в €чейке
double& Node::getData()
{
	return data;
}

//‘ункци€, возвращающа€ указатель на следующую €чейку
Node* Node::getNext() const
{
	return next;
}

//‘ункци€, задающа€ новые данные в €чейке
void Node::setData(const double& newData)
{
	data = newData;
}

//‘ункци€, задающа€ новый указатель на следующую €чейку
void Node::setNext(Node* newNext)
{
	next = newNext;
}

//ѕерегрузка оператора "=", копирует данные из переданной €чейки в исходную €чейку
Node& Node::operator =(const Node& node)
{
	if (this == &node)
		return *this;
	data = node.data;
	next = node.next;
	return *this;
}