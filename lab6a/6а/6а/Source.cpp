#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//����� ��������
class Product {
private:
    //���� �����
    string name;
    //���� �������������
    string manuf;
    //���� ����
    int price;
    //���� ����� ��������
    int term;
    //���� ����������
    int quant;
public:
    //����������
    ~Product();

    //����������� �� ���������
    Product();

    //����������� � �����������
    Product(string, string, int, int, int);

    //����� ����������� ��� ���� ����������� �����������
    void set(string, string, int, int, int);

    //����� ���������� �������� ���� �����
    string get_name();

    //����� ��������� �� ������� ��� �������� �����
    void print();

    //����� ���������� �������� ���� ����
    int get_price();

    //����� ���������� �������� ���� ����� ��������
    int get_term();

    //��������������� ��������� ���������� �� ������
    friend istream& operator>>(istream&, Product&);

    //��������������� ��������� ������� � �����
    friend ostream& operator<<(ostream&, const Product&);
};

//���������� ���� ������� ������
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
    cout << "��� - " << name << ", ������������ - " << manuf << ", ���� - " << price << ", ���� �������� " << term
        << ", ���������� - " << quant;
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
    stream << "��� - " << product.name << ", ������������ - " << product.manuf << ", ���� - " << product.price
        << ", ���� �������� " << product.term << ", ���������� - " << product.quant;
    return stream;
}

int main() {
    //������� ������ ��� ����� �������� �� �����
    ifstream fin("input.txt");
    //������� ������ ��� ������ ����������� � ����
    ofstream fout("output.txt");
    setlocale(LC_ALL, "rus");
    //���������� ���� ���������
    int n;
    fin >> n;
    string name;
    string manuf;
    int price;
    int time;
    int quant;
    //������ �� ����� ����������
    //Product* pr = nullptr;

    Product* pr = new Product[n];

    //pr = new Product[n];
    //��������� ��������� ������
    try {
        pr = new Product[n];
    }
    catch (bad_alloc& e) {
        cout << "������! �������� � ���������� ������\n";
        exit(1);
    }
    //��������� ���� ������
    for (int i = 0; i < n; i++) {
        fin >> pr[i];
    }
    string new_name;
    int new_price;
    int new_term;
    int a;
    bool flag = true;
    while (flag) {
        cout << "������� 1, ��� ������ ������ ������� ��� ��������� ������������" << endl;
        cout << "������� 2, ��� ������ ������ ������� ��� ��������� ������������, ���� ������� �� ��������� ���������"
            << endl;
        cout << "������� 3, ��� ������ ������ ������� ���� �������� ������� ������ ���������" << endl;
        cout << "������� ����� ������ �������, ��� ������ �� ���������" << endl;
        cin >> a;
        switch (a) {
        case 1:
            cout << "������ ������� ��� ��������� ������������: " << endl;
            cout << "������� ������������: ";
            cin >> new_name;
            fout << "������ ������� ��� ��������� ������������ " << new_name << ": " << endl;
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
            cout << "������ ������� ��� ��������� ������������, ���� ������� �� ��������� ���������: " << endl;
            cout << "������� ������������: ";
            cin >> new_name;
            cout << "������� ����: ";
            cin >> new_price;
            fout << "������ ������� ��� ��������� ������������ " << new_name
                << ", ���� ������� �� ��������� ��������� " << new_price << ": " << endl;
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
            cout << "������ ������� ���� �������� ������� ������ ���������: " << endl;
            cout << "������� ���� ��������: ";
            cin >> new_term;
            fout << "������ ������� ���� �������� ������� ������ ��������� " << new_term << ": " << endl;
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
    //������ ���������� ������
    delete[] pr;
    fin.close();
    fout.close();
    system("pause");
    return 0;
}