#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int p, q, r, s, t, u;
double f(double x) {
	return p * exp(-x) + q * sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}
int main() {
	while (cin >> p >> q >> r >> s >> t >> u) {
		if (f(0) < 0 || f(1) > 0) {
			cout << "No solution\n";
			continue;
		}
		double left = 0.0;
		double right = 1.0;
		for (int i = 0; i < 100; i++) {
			double mid = left + (right - left) / 2.0;
			if (f(mid) > 0) 
				left = mid;
			else
				right = mid;
		}
		cout << fixed << setprecision(4) << left << "\n";
	}
	return 0;
}
