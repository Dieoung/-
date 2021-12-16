#include <iostream>;
#include <string>;

using namespace std;

class Base1 {

private:
	int m_i;

public:
	Base1() {
		m_i = 0;
		cout << "����������� Base1 ��� ���������� \n";
	}
	Base1(int i) {
		m_i = i;
		cout << "����������� Base1 c ���������� \n";
	}

	void PutInt(int value) {
		m_i = value;
	}

	int GetInt() {
		return m_i;
	}

};

class Base2 {
private:
	string m_name;

public:
	Base2() {
		m_name = "void";
		cout << "����������� Base2 ��� ���������� \n";
	}

	Base2(string name) {
		m_name = name;
		cout << "����������� Base2 � ���������� \n";
	}

	void PutString(string value) {
		m_name = value;
	}

	string GetString() {
		return m_name;
	}


};

class Derived : public Base2, public Base1 {
private:
	char m_ch;
public:
	Derived() {
		m_ch = 'V';
		cout << "����������� Derived ��� ���������� \n";
	}
	Derived(char ch, string name, int i) : Base2(name), Base1(i) {
		m_ch = ch;
		cout << "����������� Derived � ����������� \n";
	}
	void PutChar(char value) {
		m_ch = value;
	}
	char GetChar() {
		return m_ch;
	}

	friend ostream& operator<<(ostream& out, Derived& ob);
};

ostream& operator<<(ostream& out, Derived& ob) {
	return out << ob.GetInt() << "\n" << ob.GetString() << "\n" << ob.GetChar() << "\n";
}

int main() {
	setlocale(LC_ALL, "Russian");
	Derived ob, ob2('A', "bubble", 3);
	cout << ob << ob2;

	return 0;
}
