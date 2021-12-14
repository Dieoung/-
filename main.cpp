#include <iostream>;
#include <math.h>;
using namespace std;

double pointDistance(double x1, double y1, double x2, double y2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

double pointDistance(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
}



int main() {
	setlocale(LC_ALL, "Russian");

	cout << "Двумерное пространство: ";
	double x = pointDistance(2.0,5.0,3.0, 1.0);
	double y = pointDistance(-3.0,3.0,5.0, -1.0);
	double z = pointDistance(1.0,7.0,2.0, -3.0);
	cout << "Периметр треугольника равен: " << x + y + z << endl;


	cout << "Трёхмерное пространство: ";
	x = pointDistance(3.0, 4.0, -2.0, -1.0, 4.0,1.0);
	y = pointDistance(2.0, -6.0, 2.0, 3.0, 1.0, -2.0);
	z = pointDistance(2.0, -2.0, 6.0, -4.0, 1.0, 5.0);
	cout << "Периметр треугольника равен: " << x + y + z << endl;

	return 0;
}
