#include <iostream>
#include <windows.h>
#include <cstdio>
#include <conio.h>
#include <cstring>
#include <string>
#include <time.h>

using namespace std;


const int n = 10, m = 25;

class Product {
	char Name[8];
	char Productes_one[n][m]{
	"Asus X507MA-BR071", "Asus TUF Gaming A15", "Asus X509MA-EJ018", "Lenovo IdeaPad","Lenovo IdeaPad L3",
	"Asus X509JB-EJ063", "Acer Aspire A315", "Acer A315-34-C6W0", "Lenovo IdeaPad S145","Asus TUF Gaming",
	};
	char Productes_two[n][m] = {
	"Horizont", "Kivi 32H600GR", "Blaupunkt 32WE966T", "Kivi 40F730GR","Xiaomi MI TV 4S 43",
	"Xiaomi MI TV 4A 32", "Samsung UE43N5500AU", "Horizont 32LE5511D", "Blaupunkt 32WC965T","Samsung UE32T5300AUXRU",
	};
	char Productes_three[n][m] = {
	"HONOR 30 BMH-AN10 8GB", "Huawei P40 lite E", "HONOR 9C AKA-L29 4GB", "Xiaomi Mi Note 10 Lite","Samsung Galaxy M01 3GB",
	"Xiaomi Redmi 9A 2GB/32GB", "Xiaomi Redmi Note 8 4GB", "Xiaomi Redmi Note 9 Pro", "Samsung Galaxy A51 SM-A","Apple iPhone 11 64GB",
	};
	char Manufacturer_one[n][m] = {
	"Asus", "Asus","Asus","Lenovo","Lenovo",
	"Asus","Acer","Acer","Acer","Asus",
	};

	char Manufacturer_two[n][m] = {
	"Horizont", "Kivi","Blaupunkt","Kivi","Xiaomi",
	"Xiaomi","Samsung","Horizont","Blaupunkt","Samsung",
	};

	char Manufacturer_three[n][m] = {
	"HONOR", "Huawei","HONOR","Xiaomi Mi ","Samsung Galaxy",
	"Xiaomi Redmi","Xiaomi Redmi","Xiaomi Redmi","Samsung Galaxy","Apple iPhone",
	};
	int Price;
	int Shelf_life;
	int Quantity;
public:
	void show();
	void get();
	void setPC();
	void setMP();
	void setTV();
};

void Product::get() {
	cout << "Enter word or digit:\n";
	cout << "1. notebook\n";
	cout << "2. set tv\n";
	cout << "3. phone\n";
	gets_s(Name);
};

void Product::setPC() {
	Product* Using = new Product[10];
	int a;
	int b;
	char Password[10] = { "notebook" };
	for (int i = 0, j = i; j < n && i < n; i++, j++) {
		if (Name[i] == Password[j] || Name[i] == '1') {
			for (int i = 0; i < 10; i++) {
				Using[i].Price = rand() % 2000 + 1000;
				Using[i].Shelf_life = rand() % 20 + 10;
				Using[i].Quantity = rand() % 200 + 100;
			};
			for (int i = 0; i < 10; i++) {
				cout << "====================================================================\n";
				cout << "product name: ";
				for (int j = 0; j < 25; j++) {
					cout << Using[i].Productes_one[i][j];
				};
				cout << endl << "manufacturer name: ";
				for (int j = 0; j < 25; j++) {
					cout << Using[i].Manufacturer_one[i][j];
				}
				cout << endl << "unit price: ";
				cout << Using[i].Price;
				cout << endl << "shelf life: ";
				cout << Using[i].Shelf_life;
				cout << endl << "quantity: ";
				cout << Using[i].Quantity << endl << endl;
			};

			cout << "\n\nEnter a price that exceeds the prices of some items: "; cin >> a;
			for (int i = 0; i < 10; i++) {
				if (Using[i].Price <= a) {
					cout << "====================================================================\n";
					cout << "product name: ";
					for (int j = 0; j < 25; j++) {
						cout << Using[i].Productes_one[i][j];
					};
					cout << endl << "manufacturer name: ";
					for (int j = 0; j < 25; j++) {
						cout << Using[i].Manufacturer_one[i][j];
					}
					cout << endl << "unit price: ";
					cout << Using[i].Price;
					cout << endl << "shelf life: ";
					cout << Using[i].Shelf_life;
					cout << endl << "quantity: ";
					cout << Using[i].Quantity << endl << endl;
				};
			};

			cout << "\n\nEnter a shelf life (months) that exceeds the dates of some items: "; cin >> b;
			for (int i = 0; i < 10; i++) {
				if (Using[i].Shelf_life <= b) {
					cout << "====================================================================\n";
					cout << "product name: ";
					for (int j = 0; j < 25; j++) {
						cout << Using[i].Productes_one[i][j];
					};
					cout << endl << "manufacturer name: ";
					for (int j = 0; j < 25; j++) {
						cout <<

							Using[i].Manufacturer_one[i][j];
					}
					cout << endl << "unit price: ";
					cout << Using[i].Price;
					cout << endl << "shelf life: ";
					cout << Using[i].Shelf_life;
					cout << endl << "quantity: ";
					cout << Using[i].Quantity << endl << endl;
				};
			};
			break;
		}
	};
	delete[]Using;
};

void Product::setTV() {
Product *Using = new Product[10];
int a;
int b;
char Password[10] = { "tv set" };
for (int i = 0, j = i; j < n && i < n; i++, j++) {
if (Name[i] == Password[j] || Name[i] == '2') {
for (int i = 0; i < 10; i++) {
Using[i].Price = rand() % 1500 + 1000;
Using[i].Shelf_life = rand() % 15 + 10;
Using[i].Quantity = rand() % 150 + 100;
};
for (int i = 0; i < 10; i++) {
cout << "====================================================================\n";
cout << "product name: ";
for (int j = 0; j < 25; j++) {
cout << Using[i].Productes_two[i][j];
};
cout << endl << "Manufacturer name: ";
for (int j = 0; j < 25; j++) {
cout << Using[i].Manufacturer_two[i][j];
}
cout << endl << "Unit price: ";
cout << Using[i].Price;
cout << endl << "Storage period: ";
cout << Using[i].Shelf_life;
cout << endl << "quantity: ";
cout << Using[i].Quantity << endl << endl;
};

cout << "\n\nEnter a price that exceeds the prices of some products: "; cin >> a;
for (int i = 0; i < 10; i++) {
if (Using[i].Price <= a) {
cout << "====================================================================\n";
cout << "product name: ";
for (int j = 0; j < 25; j++) {
cout << Using[i].Productes_two[i][j];
};
cout << endl << "manufacturer name: ";
for (int j = 0; j < 25; j++) {
cout << Using[i].Manufacturer_two[i][j];
}
cout << endl << "Unit price: ";
cout << Using[i].Price;
cout << endl << "Storage period: ";
cout << Using[i].Shelf_life;
cout << endl << "quantity: ";
cout << Using[i].Quantity << endl << endl;
};
};

cout << "\n\nEnter a shelf life (months) that exceeds the dates of some items: "; cin >> b;
for (int i = 0; i < 10; i++) {
if (Using[i].Shelf_life <= b) {
cout << "====================================================================\n";
cout << "product name: ";
for (int j = 0; j < 25; j++) {
cout << Using[i].Productes_two[i][j];
};
cout << endl << "manufacturer name: ";
for (int j = 0; j < 25; j++) {
cout << Using[i].Manufacturer_two[i][j];
}
cout << endl << "Unit price: ";
cout << Using[i].Price;
cout << endl << "shelf life: ";
cout << Using[i].Shelf_life;
cout << endl << "quantity: ";
cout << Using[i].Quantity << endl << endl;
};
};
break;
}
};
delete[]Using;
};

void Product::setMP() {
Product *Using = new Product[10];
int a;
int b;
char Password[10] = { "phone" };
for (int i = 0, j = i; j < n && i < n; i++, j++) {
if (Name[i] == Password[j] || Name[i] == '3') {
for (int i = 0; i < 10; i++) {
Using[i].Price = rand() % 1300 + 1000;
Using[i].Shelf_life = rand() % 30 + 10;
Using[i].Quantity = rand() % 100 + 100;
};
for (int i = 0; i < 10; i++) {
cout << "====================================================================\n";
cout << "product name: ";
for (int j = 0; j < 25; j++) {
cout << Using[i].Productes_three[i][j];
};
cout << endl << "manufacturer name: ";
for (int j = 0; j < 25; j++) {
cout << Using[i].Manufacturer_three[i][j];
}
cout << endl << "unity price: ";
cout << Using[i].Price;
cout << endl << "shelf life: ";
cout << Using[i].Shelf_life;
cout << endl << "quantity: ";
cout << Using[i].Quantity << endl << endl;
};

cout << "\n\nEnter a price that exceeds the prices of some items: "; cin >> a;
for (int i =

0; i < 10; i++) {
if (Using[i].Price <= a) {
cout << "====================================================================\n";
cout << "prodcut name: ";
for (int j = 0; j < 25; j++) {
cout << Using[i].Productes_three[i][j];
};
cout << endl << "manufacturer name: ";
for (int j = 0; j < 25; j++) {
cout << Using[i].Manufacturer_three[i][j];
}
cout << endl << "unity price: ";
cout << Using[i].Price;
cout << endl << "shelf life: ";
cout << Using[i].Shelf_life;
cout << endl << "quantity: ";
cout << Using[i].Quantity << endl << endl;
};
};

cout << "\n\nEnter a shelf life (months) that exceeds the dates of some items: "; cin >> b;
for (int i = 0; i < 10; i++) {
if (Using[i].Shelf_life <= b) {
cout << "====================================================================\n";
cout << "product name: ";
for (int j = 0; j < 25; j++) {
cout << Using[i].Productes_three[i][j];
};
cout << endl << "manufacturer name: ";
for (int j = 0; j < 25; j++) {
cout << Using[i].Manufacturer_three[i][j];
}
cout << endl << "unity price: ";
cout << Using[i].Price;
cout << endl << "shelf life: ";
cout << Using[i].Shelf_life;
cout << endl << "quantity: ";
cout << Using[i].Quantity << endl << endl;
};
};
break;
}
};
delete[]Using;
};

void Product::show() {
	get();
	setPC();
	setTV();
	setMP();
};

int main() {
	setlocale(LC_ALL, "Rus");
	Product Use_of_Function;
	Use_of_Function.show();
	system("pause");
	return 0;
}