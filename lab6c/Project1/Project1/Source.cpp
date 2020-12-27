/*
Лаб. раб. №3
Построить класс для работы с односвязным списком. Элементы списка – действительные числа.
Создать два упорядоченных по невозрастанию списка, слить их в один (также упорядоченный по невозрастанию), построив новый список.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <clocale>
#include <string>

using namespace std;

//Класс ячейки списка
class Node {
private:
    double data; //Данные в ячейке
    Node* next; //Указатель на следующую ячейку
public:
    ~Node();

    Node();

    Node(const Node&);

    double getData() const;

    Node* getNext() const;

    void setData(const double);

    void setNext(Node*);

    Node& operator=(const Node&);

    friend istream& operator>>(istream&, Node&);

    friend ostream& operator<<(ostream&, const Node&);
};

//Класс списка
class List {
private:
    Node* head; //Указатель на начало списка
    int n; //Размер списка
    void deleteList(Node*);

    Node* find(const int) const;

public:
    ~List();

    List();

    List(const List&);

    List& operator=(const List&);

    bool isEmpty() const;

    int getSize() const;

    void insert(const int, const double);

    void remove(const int);

    double retrieve(const int) const;

    void sort();

    void print() const;

    friend istream& operator>>(istream&, List&);

    friend ostream& operator<<(ostream&, const List&);
};

int main() {
    //Русификатор
    setlocale(LC_ALL, "Russian");
    //Создаем три пустых списка
    List list1, list2, list3;
    //Открываем файлы для ввода и вывода
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    //Вводим списки из файла
    fin >> list1;
    fin >> list2;
    //Сортируем первый и второй список
    list1.sort();
    list2.sort();
    fout << "Первый список, отсортированный по невозрастанию:" << endl;
    cout << "Первый список, отсортированный по невозрастанию:" << endl;
    fout << list1;
    cout << list1;
    fout << "Второй список, отсортированный по невозрастанию:" << endl;
    cout << "Второй список, отсортированный по невозрастанию:" << endl;
    fout << list2;
    cout << list2;
    //Переменные для хранения того, на какой мы позиции в списке
    int index1 = 0, index2 = 0, index3 = 0;
    //Выполяем цикл пока не обошли оба списка
    while ((index1 < list1.getSize()) || (index2 < list2.getSize())) {
        //Если мы еще не обошли до конца оба списка
        if ((index1 < list1.getSize()) && (index2 < list2.getSize())) {
            //Если элемент в позиции index1 первого списка больше элемента в позиции index2 втрого списка
            if (list1.retrieve(index1) > list2.retrieve(index2)) {
                //Вставляем в третий список, на позицию index3, элемент первого списка
                list3.insert(index3, list1.retrieve(index1));
                //Двигаемся дальше по спискам
                index3++;
                index1++;
            }
            else {
                //Вставляем в третий список, на позицию index3, элемент второго списка
                list3.insert(index3, list2.retrieve(index2));
                //Двигаемся дальше по спискам
                index3++;
                index2++;
            }
        }
        else {
            //Если еще не обошли до конца первый список, а второй обошли до конца
            if (index1 < list1.getSize()) {
                //Вставляем элемент из первого списка
                list3.insert(index3, list1.retrieve(index1));
                //Двигаемся дальше по спискам
                index3++;
                index1++;
            }
            else //Если еще не обошли до конца второй список, а первый обошли до конца
            {
                //Вставляем элемент из второго списка
                list3.insert(index3, list2.retrieve(index2));
                //Двигаемся дальше по спискам
                index3++;
                index2++;
            }
        }
    }
    fout << "Итоговый список:" << endl;
    cout << "Итоговый список:" << endl;
    fout << list3;
    cout << list3;
    fin.close();
    fout.close();
    system("pause");
    return 0;
}

//Деструктор
Node::~Node() {}

//Конструктор по умолчанию
Node::Node() {
    data = NULL;
    next = nullptr;
}

//Конструктор копирования
Node::Node(const Node& node) {
    data = node.data;
    next = node.next;
}

//Функция, возвращающая данные в ячейке
double Node::getData() const {
    return data;
}

//Функция, возвращающая указатель на следующую ячейку
Node* Node::getNext() const {
    return next;
}

//Функция, задающая новые данные в ячейке
void Node::setData(const double newData) {
    data = newData;
}

//Функция, задающая новый указатель на следующую ячейку
void Node::setNext(Node* newNext) {
    next = newNext;
}

//Перегрузка оператора "=", копирует данные из переданной ячейки в исходную ячейку
Node& Node::operator=(const Node& node) {
    if (this == &node)
        return *this;
    data = node.data;
    next = node.next;
    return *this;
}

//Переопределение операции извлечения из потока
istream& operator>>(istream& stream, Node& node) {
    stream >> node.data;
    return stream;
}

//Переопределение операции добавления в поток
ostream& operator<<(ostream& stream, const Node& node) {
    stream << node.data;
    return stream;
}

//Функция, рекурсивно удаляющая ячейки списка
void List::deleteList(Node* node) {
    //Пока существует следующая ячейка
    if (node->getNext() != nullptr) {
        //Вызываем эту функцию для следующей ячейки
        deleteList(node->getNext());
    }
    //Удаляем переданную в функцию ячейку
    delete node;
}

//Функция, возвращающая указатель на ячейку с индексом index
Node* List::find(const int index) const {
    //Начинаем идти с начала списка
    Node* tmp = head;
    //Переменная для хранения текущей позиции в списке
    int i = 0;
    //Пока позиция не равна index
    while (i < index) {
        //Переходим в следующую ячейку
        tmp = tmp->getNext();
        //Увеличиваем счетчик
        i++;
    }
    //Возвращаем найденный указатель
    return tmp;
}

//Деструктор, вызывает функцию, рекурсивно удаляющую ячейки
List::~List() {
    if (head != nullptr) {
        deleteList(head);
    }
}

//Конструктор по умолчанию
List::List() {
    head = nullptr;
    n = 0;
}

//Конструктор копирования, копирует переданный список в исходный список
List::List(const List& list) {
    n = list.n;
    Node* tmp{ list.head }; //Переменная для передвижения по переданному списку
    Node* now{ nullptr }; //Переменная для передвижения по новым ячейкам
    Node* start{ nullptr }; //Переменная для хранения начала нового списка
    //Пока не прошли весь список
    while (tmp != nullptr) {
        //Если еще не создали ячейку нового списка, то создадим ее
        if (now == nullptr) {
            now = new Node;
        }
        //Копирем в текущую ячейку нового списка данные из текущей ячейки переданного списка
        now->setData(tmp->getData());
        //Если в переданном списке еще есть ячейки, то создаем новую ячейку, и вставим ее после текущей ячейки нового списка
        if (tmp->getNext() != nullptr) {
            now->setNext(new Node);
        }
        else //Иначе укажем что в списке больше нет ячеек
        {
            now->setNext(nullptr);
        }
        //Если еще не задано начало нового списка, то зададим его
        if (start == nullptr) {
            start = now;
        }
        //Переходим в следующую ячейку переданного списка
        tmp = tmp->getNext();
        //Если мы создали новую ячеку в новом списке, т.е. мы еще не дошли до конца переданного списка, то перейдем в нее
        if (now->getNext() != nullptr) {
            now = now->getNext();
        }
    }
    //Присваиваем началу исходного списка, начало нового списка
    head = start;
}

//Перегрузка оператора "=", копирует переданный список в исходный список
List& List::operator=(const List& list) {
    //Проверка что мы не копируем список в самого себя
    if (this == &list) {
        return *this;
    }
    //Очищаем исходный список
    if (head != nullptr) {
        deleteList(head);
    }
    n = list.n;
    Node* tmp{ list.head };
    Node* now{ nullptr };
    Node* start{ nullptr };
    while (tmp != nullptr) {
        if (now == nullptr) {
            now = new Node;
        }
        now->setData(tmp->getData());
        if (tmp->getNext() != nullptr) {
            now->setNext(new Node);
        }
        else {
            now->setNext(nullptr);
        }
        if (start == nullptr) {
            start = now;
        }
        tmp = tmp->getNext();
        if (now->getNext() != nullptr) {
            now = now->getNext();
        }
    }
    head = start;
    return *this;
}

//Функция, возвращающая true - если список пуст, иначе - false
bool List::isEmpty() const {
    return (n == 0);
}

//Функция, количество элементов в списке
int List::getSize() const {
    return n;
}

//Функция, вставляющая элемент data в позицию index
void List::insert(const int index, const double data) {
    if ((index < 0) || (index > n)) {
        cout << "Ошибка! Некорректное значение индекса" << endl;
        return;
    }
    //Сохдаем новую ячейку
    Node* newNode = new Node;
    //Записываем в нее переданные данные
    newNode->setData(data);
    //Если вставляем в начало
    if (index == 0) {
        //Задаем следующей ячейкой новой ячейки, текущую ячеку начала списка
        newNode->setNext(head);
        //Задаем ячеки начала списка значение новой ячейки
        head = newNode;
    }
    else {
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
void List::remove(const int index) {
    if ((index < 0) || (index >= n)) {
        cout << "Ошибка! Некорректное значение индекса" << endl;
        return;
    }
    Node* tmp;
    //Если удаляем ячейку начала списка
    if (index == 0) {
        //Сохраняем ячеку следующую за ней
        tmp = head->getNext();
        //Удаляем ячеку начала списка
        delete head;
        //Задаем ячекой начала списка, сохраненную ранее ячейку
        head = tmp;
    }
    else {
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
double List::retrieve(const int index) const {
    if ((index < 0) || (index >= n)) {
        cout << "Ошибка! Некорректное значение индекса" << endl;
        return NULL;
    }
    //Находим ячеку с индексом index и возвращаем данные в ней
    return find(index)->getData();
}

//Функция, сортирующая список по невозрастанию "пузырьком"
void List::sort() {
    bool flag;
    Node* now;
    for (int i = 0; i < (n - 1); i++) {
        flag = false;
        //Указываем на начало списка
        now = head;
        for (int j = 0; j < (n - 1 - i); j++) {
            //Сравниваем значения соседних ячеек
            if (now->getData() < now->getNext()->getData()) {
                //Меняем местами данные в них
                double tmp = now->getData();
                now->setData(now->getNext()->getData());
                now->getNext()->setData(tmp);
                flag = true;
            }
            //Переходим в следующую ячейку
            now = now->getNext();
        }
        if (flag == false) {
            break;
        }
    }
}

//Функция, выводящая элементы списка
void List::print() const {
    //Переменная для передвижения по списку
    Node* now = head;
    //Пока не дошли до конца списка
    while (now != nullptr) {
        //Выводим данные в ячейке
        cout << now->getData() << " ";
        //Переходим в следующую ячейку
        now = now->getNext();
    }
    cout << endl;
}

//Переопределение операции добавления в поток
ostream& operator<<(ostream& stream, const List& lst) {
    Node* now = lst.head;
    while (now != nullptr) {
        stream << *now << " ";
        now = now->getNext();
    }
    stream << endl;
    return stream;
}

//Переопределение операции извлечения из потока
istream& operator>>(istream& stream, List& lst) {
    int n;
    double tmp;
    stream >> n;
    if (n > 0) {
        lst = List();
        for (int i = 0; i < n; i++) {
            stream >> tmp;
            lst.insert(i, tmp);
        }
    }
    return stream;
}