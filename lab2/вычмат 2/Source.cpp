//Boytsov programming company
//All right reserved

#include <iostream>
#include <vector> 
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

struct Func {
public:	
	Func(vector<double> v) : coef(v) {}
	Func(std::initializer_list<double> l) : coef(l) {}

	//возвращает производную
	Func derivative() {
		vector<double> v;
		for (int i = 1; i < coef.size(); i++)
			v.push_back(coef[i] * i);
		return Func(v);
	}

	//возвращает значение функции в точке x
	double gorner(double x) {
		double ans = 0;
		for (int i = (int)coef.size() - 1; i >= 0; i--)
			ans = coef[i] + ans * x;
		return ans;
	}

	//возвращает функцию в удобочитаемом виде
	string make_string() {
		string ans;
		for (int i = (int)coef.size() - 1; i >= 0; i--) {
			if (coef[i] != 0) {
				if (!ans.empty())
					ans += " + ";
				ans += to_string(coef[i]);
				if (i >= 1) {
					ans += "*x";
					if (i > 1)
						ans += "^" + to_string(i);
				}
			}
		}
		return ans;
	}

	//возвращает список корней на промежутке [a,b] с шагом разбиения h и точностью eps
	vector <double> find_roots(double a, double b, double h, double eps) {
		vector<double> ans;
		for (double l = a; l < b; l += h) {
			if (abs(gorner(l)) < eps_y) {
				ans.push_back(l);
				continue;
			}
			double r = min(l + h, b);
			if (gorner(l) * gorner(r) < 0)
				ans.push_back(find_root(l, r, eps));
		}
		if (abs(gorner(b)) < eps_y) {
			ans.push_back(b);
		}
		return ans;
	}
	 
private:
	//коэффициенты при степенях
	vector <double> coef;
	const double eps_y = 1e-6;

	//находит корень на отрезке гибридным методом Ньютона-половинного деления
	double find_root(double a, double b, double eps_x) {
		while (true) {
			//step 2
			double x = (a + b) / 2;
			while (true) {
				//step 3
				if (abs(gorner(x)) < eps_y)
					return x;
				if (gorner(x) * gorner(a) < 0)
					b = x;
				else
					a = x;

				//step 4
				if (abs(derivative().gorner(x)) < eps_y)
					break; //to step 2
				
				//step 5
				double delta = gorner(x) / derivative().gorner(x);
				x -= delta;

				//step 6
				if (x < a || b < x) 
					break; //to step 2
				
				//step 7
				if (abs(delta) <= eps_x)
					return x;
				else 
					continue; //to step 3
			}
		} 
	}

};

int main() {
	Func f{ -14.766, 5.606, 2.84, 1};
	for (auto root : f.find_roots(0, 2, 0.5, 0.0002))
		cout << root << '\n';
}