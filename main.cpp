#include <iostream>
using namespace std;

class Date
{
private:
    int m_day;
    int m_month;
    int m_year;

    int m_days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
public:

    Date(int day=0, int month=0, int year=0)
    {
        m_day = day;
        m_month = month;
        m_year = year;
    }

    friend std::ostream& operator<< (std::ostream &out, const Date &date);

    Date operator+(const Date &date)
    {
        return Date(m_day + date.m_day, m_month + date.m_month, m_year + date.m_year);
    }


    Date operator-(const Date &date)
    {
        return Date(m_day - date.m_day, m_month - date.m_month, m_year - date.m_year);
    }

    Date operator+(int value)
    {
        Date temp(m_day + value, m_month, m_year);
        while (temp.m_day > m_days[m_month])
        {
            temp.m_day -= m_days[m_month];
            temp.m_month++;
        }
        return temp;
    }


    Date operator-(int value)
    {
        Date temp(m_day - value, m_month, m_year);
        while (temp.m_day < m_days[m_month-1])
        {
            temp.m_day += m_days[m_month];
            temp.m_month--;
        }
        while (temp.m_day > m_days[m_month])
        {
            temp.m_day -= m_days[m_month]-1;
            temp.m_month++;
        }
        return temp;
    }

    Date operator++()
    {
        Date temp(m_day + 1, m_month, m_year);
        if (temp.m_day>temp.m_days[temp.m_month])
        {
            temp.m_day = 1;
            temp.m_month++;
        }
        while (temp.m_month > 12)
        {
            temp.m_month - 12;
            temp.m_year++;
        }
        return temp;
    }

    Date operator--()
    {
        Date temp(m_day - 1, m_month, m_year);
        if (temp.m_day < 1)
        {
            temp.m_month--;
            temp.m_day = temp.m_days[temp.m_month];
        }
        while (temp.m_month < 1)
        {
            temp.m_year--;
            temp.m_month + 12;
        }

    return temp;
    }




};

std::ostream& operator<< (std::ostream &out, const Date &date)
{
    out << date.m_day << "." << date.m_month << "." << date.m_year;

    return out;
}


int main()
{
    setlocale(LC_ALL, "RUS");

    Date start(1,4,2010);
    Date build(10,3,2);
    Date end = start + build;

    cout << "Дата сдачи объекта: " << start << " + "  << build << " = "  << end << endl;
    cout << "Cрок начала строительства: " << end - build << endl;
    cout << "Поставка через 35 дней: " << start << " + " << 35 << " = " << start + 35 << endl;
    cout << "++Data: " << start << " ++ "  << " = " << ++start << endl;
    cout << "--Data: " << start << " -- "  << " = " << --start << endl;

    return 0;
}
