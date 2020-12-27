#include <iostream>
#include <windows.h>
#include <cmath>

#define PI 3.14159265

using namespace std;


class Circle {
public:
	double x;
	double y;
	double Radius;
	double Angle;
public:
	Circle() {
		x = 0;
		y = 0;
	}
	Circle(double x, double y) {
		cout << "enter the coordinates of the point:\n";
		cout << "x = "; cin >> this->x;
		cout << "y = "; cin >> this->y;
		x = this->x;
		y = this->y;
		cout << "coordinates of the point: " << "(" << x << ", " << y << ")" << endl << endl;
	}
	Circle operator-(Circle& a) {
		Circle b;
		b.x = this->x - a.x;
		b.y = this->y - a.y;
		Radius = sqrt(pow(b.x, 2) + pow(b.y, 2));
		cout << "Circle point coordinate: " << "(" << this->x << ", " << this->y << ")" << endl;
		return b;
	}
	Circle operator*(Circle& h) {
		Circle hh;
		hh.x = cos(Angle * PI / 180) * this->x + sin(Angle * PI / 180) * h.y;
		hh.y = -sin(Angle * PI / 180) * this->x + cos(Angle * PI / 180) * h.y;
		cout << "(" << hh.x << ", " << hh.y << ")" << endl;
		return hh;
	};
	bool operator==(Circle c) {
		return sqrt(pow(c.x, 2) + pow(c.y, 2)) == c.Radius;
	}
	void ChangeOb(Circle* aa, Circle* bb) {
		Circle a(0, 0), b(0, 0);
		*aa = a;
		*bb = b;
	}
	void ChangeObject() {
		Circle x, y, z, f, X, Y;
		ChangeOb(&x, &y);
		X = x - y;
		Y = y - z;
		double dx_x;
		double dx_y;
		double Angl;
		cout << "The length of the side of the circle is: " << x.FuncitonSide() << endl << endl;
		cout << "Enter the x and y values ​​that you want to move the circle points:\n";
		cout << "х = "; cin >> dx_x;
		cout << "у = "; cin >> dx_y;
		cout << endl;
		cout << "Point coordinates after moving: " << "(" << x.x + dx_x << ", " << x.y + dx_y << ")" << endl;
		cout << "Point coordinates after moving: " << "(" << y.x + dx_x << ", " << y.y + dx_y << ")" << endl;

		cout << "\nEnter the value for the angle you want to rotate the points: "; cin >> Angl;
		x.Angle = Angl;
		y.Angle = Angl;
		cout << endl;
		cout << "Point coordinates after moving: "; x* x;
		cout << "Point coordinates after moving: "; y* y;
		cout << endl;
	}
	double FuncitonSide() { return Radius; };
};

class Square {
public:
	double x;
	double y;
	double Side;
	double Angle;
public:
	Square() {
		x = 0;
		y = 0;
	}
	Square(double x, double y) {
		cout << "enter the coordinates of the point:\n";
		cout << "x = "; cin >> this->x;
		cout << "y = ";

		cin >> this->y;
		x = this->x;
		y = this->y;
		cout << "coordinates of the point: " << "(" << x << ", " << y << ")" << endl << endl;
	}
	Square operator-(Square& a) {
		Square b;
		b.x = this->x - a.x;
		b.y = this->y - a.y;
		Side = sqrt(pow(b.x, 2) + pow(b.y, 2));
		cout << "Square point coordinate: " << "(" << this->x << ", " << this->y << ")" << endl;
		return b;
	}
	Square operator*(Square& h) {
		Square hh;
		hh.x = cos(Angle * PI / 180) * this->x + sin(Angle * PI / 180) * h.y;
		hh.y = -sin(Angle * PI / 180) * this->x + cos(Angle * PI / 180) * h.y;
		cout << "(" << hh.x << ", " << hh.y << ")" << endl;
		return hh;
	};
	bool operator==(Square c) {
		return sqrt(pow(c.x, 2) + pow(c.y, 2)) == c.Side;
	}
	void ChangeOb(Square* aa, Square* bb, Square* cc, Square* dd) {
		Square a(0, 0), b(0, 0), c(0, 0), d(0, 0);
		*aa = a;
		*bb = b;
		*cc = c;
		*dd = d;
	}
	void ChangeObject() {
		Square x, y, z, f, X, Y, Z, F;
		ChangeOb(&x, &y, &z, &f);
		X = x - y;
		Y = y - z;
		Z = z - f;
		F = f - x;
		double dx_x;
		double dx_y;
		double Angl;
		if (x.Side == y.Side && x.Side == z.Side && x.Side == f.Side) {
			cout << endl << "square" << endl << endl;
			cout << "The side length of the square is: " << x.FuncitonSide() << endl << endl;
			cout << "Enter the x and y values ​​that you want to move the points of the square:\n";
			cout << "х = "; cin >> dx_x;
			cout << "у = "; cin >> dx_y;
			cout << endl;
			cout << "Point coordinates after moving: " << "(" << x.x + dx_x << ", " << x.y + dx_y << ")" << endl;
			cout << "Point coordinates after moving: " << "(" << y.x + dx_x << ", " << y.y + dx_y << ")" << endl;
			cout << "Point coordinates after moving: " << "(" << z.x + dx_x << ", " << z.y + dx_y << ")" << endl;
			cout << "Point coordinates after moving: " << "(" << f.x + dx_x << ", " << f.y + dx_y << ")" << endl;

			cout << "\nEnter the value of the angle you want to rotate the points: "; cin >> Angl;
			x.Angle = Angl;
			y.Angle = Angl;
			z.Angle = Angl;
			f.Angle = Angl;
			cout << endl;
			cout << "Point coordinates after moving: "; x* x;
			cout << "Point coordinates after moving: "; y* y;
			cout << "Point coordinates after moving: "; z* z;
			cout << "Point coordinates after moving: "; f* f;
			cout << endl;
		}
		else {
			cout << "\n";
		}
	}
	double FuncitonSide() { return Side; };
};

class Rectangl {
public:
	double x;
	double y;
	double Side;
	double Angle;
public:
	Rectangl() {
		x = 0;
		y = 0;
	}
	Rectangl(double x, double y) {
		cout << "enter the coordinates of the point:\n";
		cout << "x = "; cin >> this->x;
		cout << "y = "; cin >> this->y;
		x = this->x;
		y = this->y;
		cout << "coordinates of the point: " << "(" << x << ", " << y << ")" << endl << endl;
	}
	Rectangl operator-(Rectangl& a) {
		Rectangl b;
		b.x = this->x - a.x;
		b.y = this->y - a.y;
		Side = sqrt(pow(b.x, 2) + pow(b.y, 2));
		cout << "Rectangle point coordinates: " << "(" << this->x << ", " << this->y << ")" << endl;
		return b;
	}
	Rectangl operator*(Rectangl& h) {
		Rectangl hh;
		hh.x = cos(Angle * PI / 180) * this->x + sin(Angle * PI / 180) * h.y;
		hh.y = -sin(Angle * PI / 180) * this->x + cos(Angle * PI / 180) * h.y;
		cout << "(" << hh.x << ", " << hh.y << ")" << endl;
		return hh;
	};
	bool operator==(Rectangl c) {
		return sqrt(pow(c.x, 2) + pow(c.y, 2)) == c.Side;
	}
	void ChangeOb(Rectangl* aa, Rectangl* bb, Rectangl* cc, Rectangl* dd) {
		Rectangl a(0, 0), b(0, 0), c(0, 0), d(0, 0);
		*aa = a;
		*bb = b;
		*cc = c;
		*dd = d;
	}
	void ChangeObject() {
		Rectangl x, y, z, f, X, Y, Z, F, * Massive = new Rectangl[1];
		ChangeOb(&x, &y, &z, &f);
		X = x - y;
		Y = y - z;
		Z = z - f;
		F = f - x;
		double dx_x;
		double dx_y;
		double Angl;
		if (x.Side == z.Side && y.Side == f.Side) {
			cout << endl << "rectangle" << endl << endl;
			for (int i = 0; i < 1; i++) {
				cout << "The side lengths of the rectangle are equal: " << x.FuncitonSide() << ", " << y.FuncitonSide() << endl;
			}
			cout << "The side lengths of the rectangle are equal: "<< x.FuncitonSide() << endl << endl;
			cout << "Enter the x and y values ​​by which you want to move the points of the rectangle:\n";
			cout << "х = "; cin >> dx_x;
			cout << "у = "; cin >> dx_y;
			cout << endl;
			cout << "Point coordinates after moving: " << "(" << x.x + dx_x << ", " << x.y + dx_y << ")" << endl;
			cout << "Point coordinates after moving: " << "(" << y.x + dx_x << ", " << y.y + dx_y << ")" << endl;
			cout << "Point coordinates after moving: " << "(" << z.x + dx_x << ", " << z.y + dx_y << ")" << endl;
			cout << "Point coordinates after moving: " << "(" << f.x + dx_x << ", " << f.y + dx_y << ")" << endl;

			cout << "\nEnter the value for the angle you want to rotate the points: "; cin >> Angl;
			x.Angle = Angl;
			y.Angle = Angl;
			z.Angle = Angl;
			f.Angle = Angl;
			cout << endl;
			cout << "Point coordinates after moving: "; x* x;
			cout << "Point coordinates after moving: "; y* y;
			cout << "Point coordinates after moving: "; z* z;
			cout << "Point coordinates after moving: "; f* f;
			cout << endl;
		}
	}
	double FuncitonSide() { return Side; };
};

int main() {
	setlocale(LC_ALL, "RUs");
	int choice;
	Circle* a = new Circle[1];
	Square* b = new Square[1];
	Rectangl* c = new Rectangl[1];

	do
	{
		cout << "Select a shape (1-3) or enter 0 to exit:\n";
		cout << "1. circle\n";
		cout << "2. square\n";
		cout << "3. rectangle\n";
		cin >> choice;
		switch (choice) {
		case 1:
			for (int i = 0; i < 1; i++) {
				a[i].ChangeObject();
			}
			break;
		case 2:
			for (int i = 0; i < 1; i++) {
				b[i].ChangeObject();
			}
			break;
		case 3:
			for (int i = 0; i < 1; i++) {
				c[i].ChangeObject();
			}
			break;
		}
	} while (choice != false);
	delete[] a;
	delete[] b;
	delete[] c;
	system("pause");
	return 0;
}