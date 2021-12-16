#include <iostream>

using namespace std;

class Worker
{
private:

    string m_surname, m_post;
    int m_year_admission, m_salary;

public:
    Worker(string surname, string post, int year_admission, int salary)
    {
      m_surname = surname;
      m_post = post;
      m_year_admission = year_admission;
      m_salary = salary;
    }

    void show()
    {
        cout << "������� � ��������: " << m_surname << " ���������: " << m_post << " ��� ����������� �� ������: " << m_year_admission << " ��������: " << m_salary << endl;
    }

    void experience(int year)
    {
        if (2021 - m_year_admission > year)
            show();
    }

    void salary(int salary)
    {
        if (m_salary > salary)
            show();
    }

    void post(string post)
    {
        if (post == m_post)
            show();
    }


};


int main()
{
    setlocale(LC_ALL,"Rus");
    const int total_workers = 5;
    Worker workers[total_workers]
    {
        Worker("������ �.�.", "Worker", 2000, 35500),
        Worker("������ �.�.", "Administrator", 1990, 95500),
        Worker("������ �.�.", "Manager", 2000, 55500),
        Worker("��������� �.�.", "Worker", 2002, 25500),
        Worker("������� �.�.", "Accountanter", 1995, 75500),
    };

    cout << "�) ������ ����������, ���� ������ ������� �� ������ ����������� ��������� �������� ����� ���: ";
    int experience;
    cin >> experience;

    for (int i = 0; i < total_workers; ++i)
    {
        workers[i].experience(experience);
    }

    cout << "�) ������ ����������, �������� ������� ������ ��������: ";
    int salary;
    cin >> salary;
    cin.ignore(32767, '\n');

    for (int i = 0; i < total_workers; ++i)
    {
        workers[i].salary(salary);
    }

    //�) ������ ����������, ���������� �������� ���������.
    cout << "�) ������ ����������, ���������� �������� ���������: ";
    string post;
    getline(cin, post);


    for (int i = 0; i < total_workers; ++i)
    {
        workers[i].post(post);
    }
    return 0;
}
