//this is programm
#include <complex>
#include <iostream>
#include <iomanip>

using namespace std;

complex<double> arr[100000];
int n, m;
double re, im;

int main() {
	//begining of programm
	cin >> n;
	for (int i = 0; i < n + 1; i++) {
		cin >> re >> im;
		arr[i] = complex<double>(re, im);
	}

	cout << setprecision(10) << fixed;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> re >> im;
		complex<double> x(re, im), ans(0, 0);
		for (int j = n; j >= 0; j--)
			ans = arr[j] + x * ans;
		cout << ans.real() << ' ' << ans.imag() << '\n';
	}
	//profit
}