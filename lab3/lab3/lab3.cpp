#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

class List
{
public:
	List();
	List(const List& other);
	~List();
	friend List merge_sorted(List other1, List other2) {
		List list; Node* p1, * p2;
		p1 = other1.head;
		p2 = other2.head;
		while (!p1 || !p2) {
			if (p1->data > p2->data) {
				list.push_head(p1->data);
				p1 = p1->pNext;
			}
			else {
				list.push_head(p2->data);
				p2 = p2->pNext;
			}
		}
		return list;
	}
	int Get_size1() { return size1; }
	int Get_size2() { return size2; }
	bool is_empty() const
	{
		if (!head)
		{
			return true;
		}
		return false;
	}

	float& operator[](const int index) {
		int count = 0;
		Node* tmp = this->head;
		while (tmp != nullptr) {
			if (count == index) {
				return tmp->data;
			}
			tmp = tmp->pNext;
			count++;
		}
	}
	List& merge(List& other) {
		this->tail->pNext = other.head;
		this->tail = other.tail;
		other.head = nullptr;
		return *this;
	}
	List& operator=(const List& other) {
		if (other.is_empty()) {
			this->head = nullptr;
			this->tail = nullptr;
		}
		else {
			Node* tmp = other.head;
			Node* tmp_end = other.tail;
			while (tmp != tmp_end) {
				this->push_back(tmp->data);
				tmp = tmp->pNext;
			}
			this->push_back(tmp->data);
		}
		return *this;
	}
	void push_head(float data) {
		if (head == 0) {
			head = tail = new Node(data);
		}
		else
		{
			Node* tmp = head;
			head = new Node(data);
			head->pNext = tmp;
		}
	}
	void push_back(float data) {
		if (tail != nullptr) {
			Node* tmp = tail;
			tail = new Node(data);
			tmp->pNext = tail;
		}
		else {
			head = tail = new Node(data);
		}
	}
	void print()
	{
		if (is_empty())
		{
			return;
		}
		Node* tmp = head;
		cout << tmp->data << " ";
		while (tmp != tail)
		{
			tmp = tmp->pNext;
			cout << tmp->data << " ";
		}
	}

private:
	class Node {
	public:
		Node* pNext;
		float data;
		Node(float data, Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	Node* head;
	Node* tail;
	int size1 = 0, size2 = 0;
};

List::List()
{
	head = nullptr;
	tail = nullptr;
}

List::List(const List& other)
{
	if (other.is_empty()) {
		this->head = nullptr;
		this->tail = nullptr;
	}
	else {
		Node* tmp = other.head;
		Node* tmp_end = other.tail;
		while (tmp != tmp_end) {
			this->push_back(tmp->data);
			tmp = tmp->pNext;
		}
		this->push_back(tmp->data);
	}
}

List::~List()
{
	if (head == nullptr) {
		return;
	}
	else {
		Node* tmp = head->pNext;
		while (tmp != nullptr) {
			delete head;
			head = tmp;
			tmp = tmp->pNext;
		}
		delete head;
		tail = nullptr;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	List list1, list2; float t1, t2; int n1, n2;
	cout <<"enter size 1 list: "; cin >> n1;
	for (t1 = 0; t1 <= n1; t1++) {
	list1.push_back(static_cast<float>(rand() % 11));
	}
	for (int i = 1; i < n1; i++) {
	for (int j = n1 - 1; j >= i; j--) {
	if (list1[j - 1] < list1[j]) {
	t1 = list1[j - 1];
	list1[j - 1] = list1[j];
	list1[j] = t1;
	}
	}
	}
	for (int t1 = 0; t1 < n1; t1++) {
	cout << list1[t1] << " ";
	}
	cout << endl << "enter size 2 list: "; cin >> n2;
	for (t2 = 0; t2 <= n2; t2++) {
	list2.push_back(static_cast<float>(rand() % 21));
	}
	for (int i = 1; i < n2; i++) {
	for (int j = n2 - 1; j >= i; j--) {
	if (list2[j - 1] < list2[j]) {
	t2 = list2[j - 1];
	list2[j - 1] = list2[j];
	list2[j] = t2;
	}
	}
	}
	for (int t2 = 0; t2 < n2; t2++) {
	cout << list2[t2] << " ";
	}

	List list3;

	cout << endl << "Merged and sorted list: " << endl;
	int k = 0;
	int j = 0;
	for (int i = 0; i < n1 + n2 ; i++) {
	if (list2[j] < list1[k] && k < n1) {
	list3.push_back(list1[k]);
	k++;
	}
	else {
	list3.push_back(list2[j]);
	j++;
	}
	}

	for (int i = 0; i < n1 + n2; i++) {
	cout << list3[i] << " ";
	}
	cout << endl;
	
	/*int a[7] = { 3,6,8,9,10,15,18 };
	int b[6] = { 2,4,7,20,37,38 };
	int c[13];

	int k = 0;
	int j = 0;


	for (int i = 0; i < 13; i++) {
		if (b[j] > a[k] && k < 7) {
			c[i] = a[k];
			k++;
		}
		else {
			c[i] = b[j];
			j++;
		}
	}



	for (int i = 0; i < 13; i++) {
		cout << c[i] << " ";
	}
	cout << endl;*/

	system("pause");
	return 0;
}