#include <iostream>
#include <Windows.h>
#include <cmath>

using namespace std;

class Vector {
public:
	Vector();
	Vector(int*& arr, int size);
	~Vector();
	int quantity_unit();
	int left_unit();
	int addVector();
	void show();
protected:
	int* arr;
	int size;
};

Vector::Vector() {
	arr = nullptr;
}

Vector::Vector(int*& arr, int size) {
	this->size = size;
	this->arr = new int[this->size];
	arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 3;
	for (int i = 0; i < this->size; i++) {
		this->arr[i] = arr[i];
	}
}

Vector::~Vector() {
	delete[] arr;
}

void Vector::show() {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

int Vector::addVector() {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] != 0 && arr[i] != 1) {
			Vector a;
			count++;
		}
	}
	return count;
}

int Vector::quantity_unit() {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == 1) {
			count++;
		}
	}
	return count;
}

int Vector::left_unit() {
	int position = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == 1) {
			position = i;
			i = size;
		}
	}
	return position;
}

class BoolVector : public Vector {
private:
	bool* arr;
	int size;
	int* temp;
public:
	BoolVector();
	BoolVector(bool*& arr, int size) : Vector(temp, size) {
		this->size = size;
		this->arr = new bool[this->size];
		for (int i = 0; i < this->size; i++) {
			this->arr[i] = temp[i];
		}
		delete[] temp;
		temp = nullptr;
	}
	BoolVector(const BoolVector& other);
	~BoolVector();
	BoolVector operator&(const BoolVector& other);
	BoolVector operator|(const BoolVector& other);
	BoolVector operator~();
	BoolVector operator^(const BoolVector& other);
	BoolVector operator=(const BoolVector& other);
	int quantity_unit_boolVector();
	int

		left_unit_boolVector();
	void show_boolVector();
};

BoolVector::BoolVector() {
	arr = nullptr;
}

BoolVector::BoolVector(const BoolVector& other) {
	this->size = other.size;
	this->arr = new bool[this->size];
	for (int i = 0; i < this->size; i++) {
		this->arr[i] = other.arr[i];
	}
}

BoolVector BoolVector::operator=(const BoolVector& other) {
	if (this->arr != nullptr) {
		delete[] this->arr;
		this->size = other.size;
		this->arr = new bool[this->size];
		for (int i = 0; i < this->size; i++) {
			this->arr[i] = other.arr[i];
		}
	}
	else {
		this->size = other.size;
		this->arr = new bool[this->size];
		for (int i = 0; i < this->size; i++) {
			this->arr[i] = other.arr[i];
		}
	}
	return *this;
}

BoolVector BoolVector::operator&(const BoolVector& other) {
	BoolVector c;
	c.size = other.size;
	c.arr = new bool[c.size];
	for (int i = 0; i < c.size; i++) {
		if (this->arr[i] == false && other.arr[i] == false && this->arr[i] == other.arr[i]) {
			c.arr[i] = false;
		}
		else if (this->arr[i] > other.arr[i]) {
			c.arr[i] = false;
		}
		else if (this->arr[i] < other.arr[i]) {
			c.arr[i] = false;
		}
		else if (this->arr[i] == other.arr[i] && this->arr[i] != false && other.arr[i] != false) {
			c.arr[i] = true;
		}
	}
	return c;
}

BoolVector BoolVector::operator|(const BoolVector& other) {
	BoolVector c;
	c.size = other.size;
	c.arr = new bool[c.size];
	for (int i = 0; i < c.size; i++) {
		if (this->arr[i] == false && other.arr[i] == false && this->arr[i] == other.arr[i]) {
			c.arr[i] = false;
		}
		else if (this->arr[i] > other.arr[i]) {
			c.arr[i] = true;
		}
		else if (this->arr[i] < other.arr[i]) {
			c.arr[i] = true;
		}
		else if (this->arr[i] == other.arr[i] && this->arr[i] != false && other.arr[i] != false) {
			c.arr[i] = true;
		}
	}
	return c;
}

BoolVector BoolVector::operator~() {
	for (int i = 0; i < this->size; i++) {
		if (this->arr[i] != false) {
			this->arr[i] = false;
		}
		else {
			this->arr[i] = true;
		}
	}
	return *this;
}

BoolVector BoolVector::operator^(const BoolVector& other) {
	BoolVector c;
	c.size = other.size;
	c.arr = new bool[c.size];
	for (int i = 0; i < c.size; i++) {
		if (this->arr[i] == false && other.arr[i] == false && this->arr[i] == other.arr[i]) {
			c.arr[i] = false;
		}
		else if (this->arr[i] > other.arr[i]) {
			c.arr[i] = true;
		}
		else if (this->arr[i] < other.arr[i]) {
			c.arr[i] = true;
		}
		else if (this->arr[i] == other.arr[i] && this->arr[i] != false && other.arr[i] != false) {
			c.arr[i] = false;
		}
	}
	return c;
}

BoolVector::~BoolVector() {
	delete[] arr;
}

void BoolVector::show_boolVector() {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

int BoolVector::quantity_unit_boolVector() {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == true) {
			count++;
		}
	}
	return count;
}

int BoolVector::left_unit_boolVector() {
	int position = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == true) {
			position = i;
			i = size;
		}
	}
	return position;
}

int main() {
	setlocale(LC_ALL, "RUS");

	bool* pointer_vector; int a, t;
	do
	{
		cout << "Vectors must be of equal dimension!\n";
		cout << "Enter the dimension of the 1st vector: "; cin >> a;
		cout << "Enter the dimension of the 2nd vector: "; cin >> t;

		BoolVector Vector1(pointer_vector, a);
		BoolVector Vector2(pointer_vector, t);
		BoolVector Vector3;

		if (a == t) {
			cout << "\n1st vector coordinates: ";
			Vector1.show_boolVector();
			cout << endl;
			cout << "The index of the leftmost unit of the vector: " << Vector1.left_unit_boolVector() << endl;
			cout << "Sum of vector units:" << Vector1.quantity_unit_boolVector() << endl;
			cout << "Empty vectors created: " << Vector1.addVector() << endl;
			cout << endl;
			cout << "2nd vector coordinates:";
			Vector2.show_boolVector();
			cout << endl;
			cout << "Index of the leftmost unit of the vector: " << Vector2.left_unit_boolVector() << endl;
			cout <<

				"Sum of vector units: " << Vector2.quantity_unit_boolVector() << endl;
			cout << "Empty vectors created: " << Vector2.addVector() << endl;
			cout << endl;

			int choose;

			cout << "\nSelect an operation on vectors:\n";
			cout << "1. Conjunction:\n";
			cout << "2. Disjunction:\n";
			cout << "3. Inversion:\n";
			cout << "4. EXCLUSIVE OR (^):\n";

			cin >> choose;

			switch (choose) {
			case 1:
				Vector3 = Vector1 & Vector2;
				cout << "\nCoordinates of the 3rd vector: ";
				Vector3.show_boolVector();
				cout << endl;
				cout << "The index of the leftmost unit of the vector:" << Vector3.left_unit_boolVector() << endl;
				cout << "Sum of vector units: " << Vector3.quantity_unit_boolVector() << endl;
				cout << endl;
				break;
			case 2:
				Vector3 = Vector1 | Vector2;
				cout << "\nCoordinates of the 3rd vector: ";
				Vector3.show_boolVector();
				cout << endl;
				cout << "The index of the leftmost unit of the vector:" << Vector3.left_unit_boolVector() << endl;
				cout << "Sum of vector units: " << Vector3.quantity_unit_boolVector() << endl;
				cout << endl;
				break;
			case 3:
				~Vector1;
				cout << "\n1st vector coordinates: ";
				Vector1.show_boolVector();
				cout << endl;
				cout << "The index of the leftmost unit of the vector: " << Vector1.left_unit_boolVector() << endl;
				cout << "Sum of vector units:" << Vector1.quantity_unit_boolVector() << endl;
				cout << endl;
				~Vector2;
				cout << "\n2nd vector coordinates:";
				Vector2.show_boolVector();
				cout << endl;
				cout << "The index of the leftmost unit of the vector: " << Vector2.left_unit_boolVector() << endl;
				cout << "Sum of vector units: " << Vector2.quantity_unit_boolVector() << endl;
				cout << endl;
				break;
			case 4:
				Vector3 = Vector1 ^ Vector2;
				cout << "\nCoordinates of the 3rd vector:";
				Vector3.show_boolVector();
				cout << endl;
				cout << "The index of the leftmost unit of the vector: " << Vector3.left_unit_boolVector() << endl;
				cout << "Sum of vector units:" << Vector3.quantity_unit_boolVector() << endl;
				cout << endl;
				break;
			}
		}
	} while (a != t);

	system("pause");
	return 0;
}
