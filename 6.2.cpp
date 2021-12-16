#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

class DomesticAnimal {
protected:
	int m_price;
	int m_weight;
	string m_color;

public:
	DomesticAnimal() {
		m_price = 0;
		m_weight = 0;
		m_color = "black";
	}

	DomesticAnimal(int price, int weight, string color) {
		m_price = price;
		m_weight = weight;
		m_color = color;
	}

	void Print() {
		cout << m_price << "  " << m_weight << "  " << m_color << "  ";
		cout << "Class domestic ";
	}

};

class Cow : virtual public DomesticAnimal {
public:
	Cow() {};
	Cow(int price, int weight, string color) : DomesticAnimal(price, weight, color) {}

	void Print() {
		cout << m_price << "  " << m_weight << "  " << m_color << "  ";
		cout << "Class Cow ";
	}
};

class Buffalo : virtual public DomesticAnimal {
public:
	Buffalo() {};
	Buffalo(int price, int weight, string color) : DomesticAnimal(price, weight, color) {}

	void Print() {
		cout << m_price << "  " << m_weight << "  " << m_color << "  ";
		cout << "Class Buffalo ";
	}
};

class Beefalo : public Cow, public Buffalo {
public:
	Beefalo(int price, int weight, string color) {
		m_price = price;
		m_weight = weight;
		m_color = color;
	}
	void Print() {
		cout << m_price << "  " << m_weight << "  " << m_color << "  ";
		cout << "class Beefalo ";
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	Cow a(1, 1, "red");
	Beefalo b(2, 2, "blue");
	a.Print();
	b.Print();

	return 0;

}
