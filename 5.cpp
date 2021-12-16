#include <iostream>;

using namespace std;


class BASE {
public: int m_i;
protected: long m_l;
private: double m_d;
public:
	BASE(int i, long l, double d) {
		m_i = i;
		m_l = l;
		m_d = d;
	}
	BASE() {
		m_i = 0;
		m_l = 0;
		m_d = 0;
	}
	~BASE() {}

	double GetD() {
		return m_d;
	}

	void SetD(double d) {
		m_d = d;
	}

	void ff() {
		cout << "BASE" << endl;
	}

	double* GetAdressD() {
		return &m_d;
	}

	int* GetAdressI() {
		return &m_i;
	}

	long* GetAdressL() {
		return &m_l;
	}
};

class DERIVED : public BASE {
private:
	float m_f;
public:
	DERIVED(float f, int i, long l, double d):BASE(i,l,d) {
		m_f = f;
	}
	DERIVED(){
		m_f = 0;
	}
	float* GetAddresF() {
		return &m_f;
	}
	void Show() {
		cout << m_f;
	}
	void ff() {
		cout << "DERIVED" << endl;
	}
	friend class DERIVED_1;
	friend ostream& operator<<(ostream& out, DERIVED& ob);
};

void ff() {
	cout << "Global" << endl;
}

ostream& operator<<(ostream& out, DERIVED& ob) {

	out << ob.m_f << " " << ob.m_i << " " << ob.m_l << " " << ob.GetD()<< endl;
	out << ob.GetAddresF() << " " << ob.GetAdressI() << " " << ob.GetAdressL() << " " << ob.GetAdressD();
	return out;
}

class DERIVED_1 : public DERIVED {
public:
	DERIVED_1(float f, int i, long l, double d):DERIVED(f, i, l, d) {
		m_f = f;
		m_i = i;
		m_l = l;
		SetD(d);
	}
	void foo() {
		m_i++;
		m_l += 1;
		ff();
	}

};



int main() {
	setlocale(LC_ALL, "Russian");
	DERIVED_1 ob1(1,2,3,4);
	ob1.foo();
	 cout << "Размер BASE: " << sizeof(BASE) << endl;
    cout << "Размер DERIVED: " << sizeof(DERIVED) << endl;
	cout << ob1;
	return 0;
}
