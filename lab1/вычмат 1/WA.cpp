#include <complex>
#include <iostream>

using namespace std;

complex<double> arr[1000];
int n, m;
double re, im;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> re >> im;
		arr[i] = complex<double>(re, im);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> re >> im;
		complex<double> x(re, im), ans(0, 0);
		for (int j = n - 1; j >= 0; j--)
			ans = arr[j] + x * ans;
		cout << ans.real() << ' ' << ans.imag() << '\n';
	}
}