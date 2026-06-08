#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, b, h, w;
	while (cin >> n >> b >> h >> w) {
		int min_cost = b + 1;
		while (h--) {
			int p;
			cin >> p;
			int cost = n * p;
			bool can_stay = false;

			for (int i = 0; i < w; i++) {
				int bed;
				cin >> bed;
				if (bed >= n) {
					can_stay = true;
				}
			}
			if (can_stay && cost <= b)
				min_cost = min(min_cost, cost);
		}
		if (min_cost <= b)
			cout << min_cost << "\n";
		else
			cout << "stay home\n";
	}
	return 0;
}
