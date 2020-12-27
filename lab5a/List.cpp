#include "List.h"

//Функция, рекурсивно удаляющая ячейки списка
void List::deleteList(Node* node)
{
	//Пока существует следующая ячейка
	if (node->getNext() != nullptr)
	{
		//Вызываем эту функцию для следующей ячейки
		deleteList(node->getNext());
	}
	//Удаляем переданную в функцию ячейку
	delete node;
}

//Функция, возвращающая указатель на ячейку с индексом index
Node* List::find(const int index) const
{
	//Начинаем идти с начала списка
	Node* tmp = head;
	//Переменная для хранения текущей позиции в списке
	int i = 0;
	//Пока позиция не равна index
	while (i < index)
	{
		//Переходим в следующую ячейку
		tmp = tmp->getNext();
		//Увеличиваем счетчик
		i++;
	}
	//Возвращаем найденный указатель
	return tmp;
}

//Деструктор, вызывает функцию, рекурсивно удаляющую ячейки
List::~List()
{
	if (head != nullptr)
	{
		deleteList(head);
	}
}

//Конструктор по умолчанию
List::List()
{
	head = nullptr;
	n = 0;
}

//Конструктор копирования, копирует переданный список в исходный список
List::List(const List& list)
{
	n = list.n;
	Node* tmp{ list.head }; //Переменная для передвижения по переданному списку
	Node* now{ nullptr }; //Переменная для передвижения по новым ячейкам
	Node* start{ nullptr }; //Переменная для хранения начала нового списка
	//Пока не прошли весь список
	while (tmp != nullptr)
	{
		//Если еще не создали ячейку нового списка, то создадим ее
		if (now == nullptr)
		{
			now = new Node;
		}
		//Копирем в текущую ячейку нового списка данные из текущей ячейки переданного списка
		now->setData(tmp->getData());
		//Если в переданном списке еще есть ячейки, то создаем новую ячейку, и вставим ее после текущей ячейки нового списка
		if (tmp->getNext() != nullptr)
		{
			now->setNext(new Node);
		}
		else //Иначе укажем что в списке больше нет ячеек
		{
			now->setNext(nullptr);
		}
		//Если еще не задано начало нового списка, то зададим его
		if (start == nullptr)
		{
			start = now;
		}
		//Переходим в следующую ячейку переданного списка
		tmp = tmp->getNext();
		//Если мы создали новую ячеку в новом списке, т.е. мы еще не дошли до конца переданного списка, то перейдем в нее
		if (now->getNext() != nullptr)
		{
			now = now->getNext();
		}
	}
	//Присваиваем началу исходного списка, начало нового списка
	head = start;
}

//Перегрузка оператора "=", копирует переданный список в исходный список
List& List::operator=(const List& list)
{
	//Проверка что мы не копируем список в самого себя
	if (this == &list)
	{
		return *this;
	}
	//Очищаем исходный список
	if (head != nullptr)
	{
		deleteList(head);
	}
	n = list.n;
	Node* tmp{ list.head };
	Node* now{ nullptr };
	Node* start{ nullptr };
	while (tmp != nullptr)
	{
		if (now == nullptr)
		{
			now = new Node;
		}
		now->setData(tmp->getData());
		if (tmp->getNext() != nullptr)
		{
			now->setNext(new Node);
		}
		else
		{
			now->setNext(nullptr);
		}
		if (start == nullptr)
		{
			start = now;
		}
		tmp = tmp->getNext();
		if (now->getNext() != nullptr)
		{
			now = now->getNext();
		}
	}
	head = start;
	return *this;
}

//Функция, возвращающая true - если список пуст, иначе - false
bool List::isEmpty() const
{
	return (n == 0);
}

//Функция, количество элементов в списке
int List::getSize() const
{
	return n;
}

//Функция, вставляющая элемент data в позицию index
void List::insert(const double& data, int index)
{
	if ((index < 0) || (index > n))
	{
		std::cout << "Ошибка! Некорректное значение индекса" << std::endl;
		return;
	}
	//Сохдаем новую ячейку
	Node* newNode = new Node;
	//Записываем в нее переданные данные
	newNode->setData(data);
	//Если вставляем в начало
	if (index == 0)
	{
		//Задаем следующей ячейкой новой ячейки, текущую ячеку начала списка
		newNode->setNext(head);
		//Задаем ячеки начала списка значение новой ячейки
		head = newNode;
	}
	else
	{
		//Ищем ячеку, после которой надо вставить новую ячейку
		Node* tmp = find(index - 1);
		//Следующей ячейкой новой ячейки задаем следующию ячеку найденной ячейки
		newNode->setNext(tmp->getNext());
		////Следующей ячейкой найденной ячейки задаем новую ячейку, т.е. вставляем ее в позицию index
		tmp->setNext(newNode);
	}
	//Увеличиваем количество элементов в списке
	n++;
}

//Функция, удаляющая ячеку с индексом index
void List::remove(const int index)
{
	if ((index < 0) || (index >= n))
	{
		std::cout << "Ошибка! Некорректное значение индекса" << std::endl;
		return;
	}
	Node* tmp;
	//Если удаляем ячейку начала списка
	if (index == 0)
	{
		//Сохраняем ячеку следующую за ней
		tmp = head->getNext();
		//Удаляем ячеку начала списка
		delete head;
		//Задаем ячекой начала списка, сохраненную ранее ячейку
		head = tmp;
	}
	else
	{
		//Ищем ячеку, после которой надо удалить ячейку
		Node* prev = find(index - 1);
		//Запоминаем ячеку, которую надо удалить
		tmp = prev->getNext();
		//Задаем следующей ячейкой найденной ячейки, ячеку следующую за удаляемой ячейкой
		prev->setNext(tmp->getNext());
		//Удаляем ячейку
		delete tmp;
	}
	//Уменьшаем количество элементов с списке
	n--;
}

//Функция, возвращающая значение в ячейке с индексом index
double List::retrieve(const int index) const
{
	if ((index < 0) || (index >= n))
	{
		std::cout << "Ошибка! Некорректное значение индекса" << std::endl;
		return 0;
	}
	//Находим ячеку с индексом index и возвращаем данные в ней
	return find(index)->getData();
}

//Перегрузка оператора индексации "[]"
double& List::operator[](const int index)
{
	if ((index < 0) || (index >= n))
	{
		std::cout << "Ошибка! Некорректное значение индекса" << std::endl;
		return *(new double);
	}
	//Находим ячеку с индексом index и возвращаем данные в ней
	return find(index)->getData();
}

//Перегрузка оператора индексации "[]" для константных объектов
const double& List::operator[](const int index) const
{
	if ((index < 0) || (index >= n))
	{
		std::cout << "Ошибка! Некорректное значение индекса" << std::endl;
		return *(new double);
	}
	//Находим ячеку с индексом index и возвращаем данные в ней
	return find(index)->getData();
}

//Перегрузка оператора ввода
std::istream& operator>>(std::istream& sstream, List& list)
{
	int n;
	sstream >> n;
	if (n < 0)
	{
		std::cout << "Ошибка! Некорректное значение, объекту оставлено прежнее значение" << std::endl;
		return sstream;
	}
	//Очищаем список
	if (list.head != nullptr)
	{
		list.deleteList(list.head);
	}
	list.n = 0;
	list.head = nullptr;
	Node* now = nullptr;
	double tmp;
	//Вставляем данные в список
	for (int i = 0; i < n; i++)
	{
		sstream >> tmp;
		if (i == 0)
		{
			now = new Node;
			now->setData(tmp);
			list.head = now;
			list.n++;
			continue;
		}
		now->setNext(new Node);
		now = now->getNext();
		now->setData(tmp);
		list.n++;
	}
	return sstream;
}

//Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& sstream, const List& list)
{
	//Переменная для передвижения по списку
	Node* now = list.head;
	//Пока не дошли до конца списка
	while (now != nullptr)
	{
		//Выводим данные в ячейке
		sstream << now->getData() << " ";
		//Переходим в следующую ячейку
		now = now->getNext();
	}
	return sstream;
}