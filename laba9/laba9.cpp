#include <iostream>
#include <string>
#include <cmath>
#include <clocale>

using namespace std;

int a = 3, b = 9;
const double eps = 0.001, h = 0.01;
double F(double);
double find(double, double, double);

double F(double x) {
	return x - 5 * pow(sin(x), 2) - 5;
}

double find(double x0, double eps, double q) {
	double x1 = x0 - F(x0) * q / (F(x0) - F(x0 - q));
	while (fabs(x1 - x0) > eps) {
		x0 = x1;
		x1 = x1 - F(x1) * q / (F(x1) - F(x1 - q));
	}
	return x0;
}
int main() {
	setlocale(LC_ALL, "Russian");
	int n = 0;
	cout << "При параметрах:\na = " + to_string(a) + "\nb = " + to_string(b) + "\neps = " + to_string(eps) + "\nh = " + to_string(h) + "\n\n";
	for (double x = a; x <= b; x += h) {
		if (F(x) * F(x + h) < 0) {
			n++;
			cout << "x" + to_string(n) + "=" + to_string(find(x, eps, h)) + "    y = " + to_string(F(find(x, eps, h))) << endl;

		}
	}
	if (n == 0) cout << "Корней нет" << endl;
	system("pause");
}
//x1=5.856475
//x2=6.959655
//x3=8.445462