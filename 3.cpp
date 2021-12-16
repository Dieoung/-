#include <iostream>
#include <string>
using namespace std;

class Goods
{
private:
    string m_name;
    string m_date;
    int m_price;
    int m_amount;
    int m_number;
public:

    Goods(string name = "", string date="", int price=0, int amount=0, int number=0)
    {
        m_name = name;
        m_date = date;
        m_price = price;
        m_amount = amount;
        m_number = number;

        cout << "���������� �����������" << endl;
    }

    Goods(const Goods &goods)
    {
        m_name = goods.m_name;
        m_date = goods.m_date;
        m_price = goods.m_price;
        m_amount = goods.m_amount;
        m_number = goods.m_number;
        cout << "���������� ����������� �����������" << endl;
    }

     Goods& operator=(const Goods &goods)
        {
        m_name = goods.m_name;
        m_date = goods.m_date;
        m_price = goods.m_price;
        m_amount = goods.m_amount;
        m_number = goods.m_number;

        cout << "���������� �������� ������������" << endl;
        }

    void change(string name, string date, int price, int amount, int number)
    {
        m_name = name;
        m_date = date;
        m_price = price;
        m_amount = amount;
        m_number = number;
    }

    int price()
    {
        return m_price;
    }

    void show()
    {
        cout << "�����: " <<m_name << "\t���� ����������: " << m_date << "\t����: " << m_price << "\t����������: " << m_amount << "\t����� ���������: " << m_number << endl;
    }

    ~Goods()
    {
        cout << "���������� ����������" << endl;
    }
};

Goods& tovar(Goods &s){ return s; }

int main()
{
    setlocale (LC_ALL, "RUS");

    cout<<"���� � ������� main()"<<endl;

    Goods product("������", "10.10.2020", 100, 50, 1);
    Goods product1 = product;
    Goods product2(product);

    product.show();
    product1.show();
    product2.show();

    tovar(product);

    Goods product3;
    product3 = product;
    product3.show();

    cout<<"����� �� ������� main()"<<endl;

    return 0;
}
