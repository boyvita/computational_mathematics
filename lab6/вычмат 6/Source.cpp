//mathematics - queen of sciences
#include <iostream>
#include <vector> 
#include <cmath>

using namespace std;

double rectangle(vector<double> y, double h) {
	double ans = 0;
	for (int i = 0; i < y.size() - 1; i++)
		ans += y[i];
	return ans * h;
}

double 	trapeze(vector<double> y, double h) {
	double ans = 0;
	for (int i = 1; i < y.size() - 1; i++)
		ans += y[i];
	return ((y.front() + y.back()) / 2 + ans) * h;
}

double simpson(vector<double> y, double h) {
	double ans = 0;
	for (int i = 1; i < y.size() - 1; i += 2) {
		ans += y[i - 1] + 4 * y[i] + y[i + 1];
	}
	return ans * h / 3;
}

double integrate(double x) {
	return sqrt(x * x - x - 2) + log(-2 * sqrt(x * x - x - 2) - 2 * x + 1) / 2;
}

int main() {
	int n;
	double a, b, h;
	cin >> a >> b >> n;
	h = (b - a) / n;

	vector<double> values(n);
	for (int i = 0; i < n; i++) {
		double x = a + i * (b - a) / (n - 1);
		values[i] = x / sqrt(x * x - x - 2);
	}

	double I = integrate(b) - integrate(a);
	double J1 = rectangle(values, h);
	double J2 = trapeze(values, h);
	double J3 = simpson(values, h);
	printf("%lf\n%lf %lf\n%lf %lf\n%lf %lf\n", I, J1, abs(I - J1), J2, abs(I - J2), J3, abs(I - J3));
}