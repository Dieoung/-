#include <iostream>
using namespace std;

class Test
{
private:
    int m_W;
public:

    Test(int W = 1)
    {
        m_W = W;
    }

    void z()
    {
        cout << "??? ???????? ??????? ?????? Test";
    }

    friend void fun(Test* ptr);
};

void fun(Test* ptr)
{
    cout << ptr->m_W << endl;
    ptr->z();
}

int main()
{
    setlocale(LC_ALL, "RUS");

    Test test;
    fun(&test);

    return 0;
}
