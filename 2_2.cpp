#include <iostream>
#include <string>
using namespace std;

class Abonent
{
public:
    int m_id;
private:
    string m_surname;
    string m_number;
public:
    Abonent(int id, string surname, string number)
    {
        m_id = id;
        m_surname = surname;
        m_number = number;
    }

    friend class Notebook;

    ~Abonent() {};
};

class Notebook
{
private:

public:

    void change(Abonent &abonent, string number)
    {
        abonent.m_number = number;
    }

    void show(const Abonent &abonent)
    {
       cout << "ID: " <<abonent.m_id << "\t�������: " << abonent.m_surname << "\t����� ��������: " << abonent.m_number << endl;
    }

};

int main()
{
    setlocale(LC_ALL, "RUS");

    Notebook notebook;

    Abonent abonents[5]
    {
        Abonent(1, "�������", "+7 (979) 845-92-72"),
        Abonent(2, "���������", "+7 (975) 674-81-32"),
        Abonent(3, "���������", "+7 (917) 119-52-86"),
        Abonent(3, "��������", "+7 (913) 261-59-31"),
        Abonent(5, "�������", "+7 (948) 259-45-54")
    };

    for (int i = 0; i < 5; ++i)
        if (abonents[i].m_id == 5)
            notebook.change(abonents[i], "+7(999) 999-99-99");

    for (int i = 0; i < 5; ++i)
        notebook.show(abonents[i]);

    return 0;
}
