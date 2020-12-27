#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//класс продукта
class Product {
private:
    //поле имени
    string name;
    //поле производителя
    string manuf;
    //поле цены
    int price;
    //поле срока хранения
    int term;
    //поле количества
    int quant;
public:
    //деструктор
    ~Product();

    //конструктор по умолчанию
    Product();

    //конструктор с параметрами
    Product(string, string, int, int, int);

    //метод заполняющий все поля переданными параметрами
    void set(string, string, int, int, int);

    //метод получающий значение поля имени
    string get_name();

    //метод выводящий на консоль все значения полей
    void print();

    //метод получающий значение поля цены
    int get_price();

    //метод получающий значение поля срока хранения
    int get_term();

    //переопределение оператора извлечения из потока
    friend istream& operator>>(istream&, Product&);

    //переопределение оператора вставки в поток
    friend ostream& operator<<(ostream&, const Product&);
};

//реализация всех методов класса
Product::~Product() {

}

Product::Product() : name{ "" }, manuf{ "" }, price{ 0 }, term{ 0 }, quant{ 0 } {

}

Product::Product(string name1, string manuf1, int price1, int term1, int quant1) {
    name = name1;
    manuf = manuf1;
    price = price1;
    term = term1;
    quant = quant1;
}

void Product::set(string name1, string manuf1, int price1, int term1, int quant1) {
    name = name1;
    manuf = manuf1;
    price = price1;
    term = term1;
    quant = quant1;
}

string Product::get_name() {
    return name;
}

void Product::print() {
    cout << "Имя - " << name << ", производство - " << manuf << ", цена - " << price << ", срок хранения " << term
        << ", количество - " << quant;
}

int Product::get_price() {
    return price;
}

int Product::get_term() {
    return term;
}

istream& operator>>(istream& stream, Product& product) {
    stream >> product.name;
    stream >> product.manuf;
    stream >> product.price;
    stream >> product.term;
    stream >> product.quant;
    return stream;
}

ostream& operator<<(ostream& stream, const Product& product) {
    stream << "Имя - " << product.name << ", производство - " << product.manuf << ", цена - " << product.price
        << ", срок хранения " << product.term << ", количество - " << product.quant;
    return stream;
}

int main() {
    //создаем объект для ввода значений из файла
    ifstream fin("input.txt");
    //создаем объект для вывлда результатов в файл
    ofstream fout("output.txt");
    setlocale(LC_ALL, "rus");
    //количество всех продуктов
    int n;
    fin >> n;
    string name;
    string manuf;
    int price;
    int time;
    int quant;
    //массив со всеми продуктами
    //Product* pr = nullptr;

    Product* pr = new Product[n];

    //pr = new Product[n];
    //обработка выделения памяти
    try {
        pr = new Product[n];
    }
    catch (bad_alloc& e) {
        cout << "Ошибка! Проблема с выделением памяти\n";
        exit(1);
    }
    //заполняем этот массив
    for (int i = 0; i < n; i++) {
        fin >> pr[i];
    }
    string new_name;
    int new_price;
    int new_term;
    int a;
    bool flag = true;
    while (flag) {
        cout << "Нажмите 1, для вывода списка товаров для заданного наименования" << endl;
        cout << "Нажмите 2, для вывода списка товаров для заданного наименования, цена которых не превышает указанной"
            << endl;
        cout << "Нажмите 3, для вывода списка товаров срок хранения которых больше заданного" << endl;
        cout << "Нажмите любую другую клавишу, для выхода из программы" << endl;
        cin >> a;
        switch (a) {
        case 1:
            cout << "Список товаров для заданного наименования: " << endl;
            cout << "Введите наименование: ";
            cin >> new_name;
            fout << "Список товаров для заданного наименования " << new_name << ": " << endl;
            for (int i = 0; i < n; i++) {
                if (pr[i].get_name() == new_name) {
                    fout << pr[i] << endl;
                    cout << pr[i] << endl;
                }
            }
            fout << endl;
            cout << endl;
            break;
        case 2:
            cout << "Список товаров для заданного наименования, цена которых не превышает указанной: " << endl;
            cout << "Введите наименование: ";
            cin >> new_name;
            cout << "Введите цену: ";
            cin >> new_price;
            fout << "Список товаров для заданного наименования " << new_name
                << ", цена которых не превышает указанной " << new_price << ": " << endl;
            for (int i = 0; i < n; i++) {
                if (pr[i].get_name() == new_name && pr[i].get_price() <= new_price) {
                    fout << pr[i] << endl;
                    cout << pr[i] << endl;
                }
            }
            fout << endl;
            cout << endl;
            break;
        case 3:
            cout << "Список товаров срок хранения которых больше заданного: " << endl;
            cout << "Введите срок хранения: ";
            cin >> new_term;
            fout << "Список товаров срок хранения которых больше заданного " << new_term << ": " << endl;
            for (int i = 0; i < n; i++) {
                if (pr[i].get_term() > new_term) {
                    fout << pr[i] << endl;
                    cout << pr[i] << endl;
                }
            }
            fout << endl;
            cout << endl;
            break;
        default:
            flag = false;
            break;
        }
    }
    //очищаю выделенную память
    delete[] pr;
    fin.close();
    fout.close();
    system("pause");
    return 0;
}