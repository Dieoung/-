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
        cout << "Фамилия и инициалы: " << m_surname << " Должность: " << m_post << " Год поступления на работу: " << m_year_admission << " Зарплата: " << m_salary << endl;
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
        Worker("Греков А.Д.", "Worker", 2000, 35500),
        Worker("Греков В.И.", "Administrator", 1990, 95500),
        Worker("Орлова А.Г.", "Manager", 2000, 55500),
        Worker("Степанова В.В.", "Worker", 2002, 25500),
        Worker("Устинов Г.Е.", "Accountanter", 1995, 75500),
    };

    cout << "а) Список работников, стаж работы которых на данном предприятии превышает заданное число лет: ";
    int experience;
    cin >> experience;

    for (int i = 0; i < total_workers; ++i)
    {
        workers[i].experience(experience);
    }

    cout << "б) Список работников, зарплата которых больше заданной: ";
    int salary;
    cin >> salary;
    cin.ignore(32767, '\n');

    for (int i = 0; i < total_workers; ++i)
    {
        workers[i].salary(salary);
    }

    //в) список работников, занимающих заданную должность.
    cout << "в) Список работников, занимающих заданную должность: ";
    string post;
    getline(cin, post);


    for (int i = 0; i < total_workers; ++i)
    {
        workers[i].post(post);
    }
    return 0;
}
