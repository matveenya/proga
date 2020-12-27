#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class List
{
public:
    List();
    List(const List& other);
    ~List();
    bool is_empty() const
    {
        if (!head)
        {
            return true;
        }
        return false;
    }
    T& operator[](const int index);
    T& merge(List& other);
    T& operator=(const List& other);
    void push_head(T data);
    void push_back(T data);
    void print()
    {
        if (is_empty())
        {
            return;
        }
        Node<T>* tmp = head;
        cout << tmp->data << " ";
        while (tmp != tail)
        {
            tmp = tmp->pNext;
            cout << tmp->data << " ";
        }
    }

private:
    template <typename U>
    class Node {
    public:
        Node* pNext;
        U data;
        Node(U data = U(), Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };
    Node<T>* head;
    Node<T>* tail;
};

template <typename T>
List<T>::List()
{
    head = nullptr;
    tail = nullptr;
}

template <typename T>
List<T>::List(const List& other)
{
    if (other.is_empty()) {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else {
        Node<T>* tmp = other.head;
        Node<T>* tmp_end = other.tail;
        while (tmp != tmp_end) {
            this->push_back(tmp->data);
            tmp = tmp->pNext;
        }
        this->push_back(tmp->data);
    }
}

template <typename T>
List<T>::~List()
{
    if (head == nullptr) {
        return;
    }
    else {
        Node<T>* tmp = head->pNext;
        while (tmp != nullptr) {
            delete head;
            head = tmp;
            tmp = tmp->pNext;
        }
        delete head;
        tail = nullptr;
    }
}

template <typename T>
T& List<T>::operator[](const int index) {
    int count = 0;
    Node<T>* tmp = this->head;
    while (tmp != nullptr) {
        if (count == index) {
            return tmp->data;
        }
        tmp = tmp->pNext;
        count++;
    }
}

template <typename T>
T& List<T>::merge(List<T>& other) {
    this->tail->pNext = other.head;
    this->tail =

        other.tail;
    other.head = nullptr;
    return *this;
}

template <typename T>
T& List<T>::operator=(const List<T>& other) {
    if (other.is_empty()) {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else {
        Node<T>* tmp = other.head;
        Node<T>* tmp_end = other.tail;
        while (tmp != tmp_end) {
            this->push_back(tmp->data);
            tmp = tmp->pNext;
        }
        this->push_back(tmp->data);
    }
    return *this;
}

template <typename T>
void List<T>::push_head(T data) {
    if (head == 0) {
        head = tail = new Node<T>(data);
    }
    else
    {
        Node<T>* tmp =
            head;
        head = new Node<T>(data);
        head->pNext = tmp;
    }
}

template <typename T>
void List<T>::push_back(T data) {
    if (tail != nullptr) {
        Node<T>* tmp = tail;
        tail = new Node<T>(data);
        tmp->pNext = tail;
    }
    else {
        head = tail = new Node<T>(data);
    }
}

template <typename T>
void Blank(List<T> list1, List<T> list2) {
    T t1; T t2; int n1, n2; int i, j;
    cout << "enter size 1 list: "; cin >> n1;
    for (i = 0; i <= n1; i++) {
        list1.push_back(static_cast<T>(rand() % 43 + 1.6));
    }
    for (i = 1; i < n1; i++) {
        for (j = n1 - 1; j >= i; j--) {
            if (list1[j - 1] < list1[j]) {
                t1 = list1[j - 1];
                list1[j - 1] = list1[j];
                list1[j] = t1;
            }
        }
    }
    for (i = 0; i < n1; i++) {
        cout << list1[i] << " ";
    }
    cout << endl << "enter size 2 list: "; cin >> n2;
    for (i = 0; i <= n2; i++) {
        list2.push_back(static_cast<T>(rand() % 21 + 1.5));
    }
    for (i = 1; i < n2; i++) {
        for (j = n2 - 1; j >= i; j--) {
            if (list2[j - 1] < list2[j]) {
                t2 = list2[j - 1];
                list2[j - 1] = list2[j];
                list2[j] = t2;
            }
        }
    }
    for (i = 0; i < n2; i++) {
        cout << list2[i] << " ";
    }
    List<T> list3;
    cout << endl << "Merged and sorted list: " << endl;
    int k = 0;
    int f = 0;
    for (i = 0; i < n1 + n2; i++) {
        if (list2[f] < list1[k] && k < n1) {
            list3.push_back(list1[k]);
            k++;
        }
        else {
            list3.push_back(list2[f]);
            f++;
        }
    }

    for (i = 0; i < n1 + n2; i++) {
        cout << list3[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Rus");


    //с типом string
    List<string > list;
    list.push_back("1.1");
    list.push_back("1.3");
    list.push_back("1.5");
    list.print();

    //c типом int
    List<int > list2;
    list2.push_back(3);
    list2.push_back(2);
    list2.push_back(1);
    list2.print();
    cout << endl;


    cout << list.is_empty();

    // system("pause");
    return 0;
}