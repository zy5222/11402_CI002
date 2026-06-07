#include<iostream>
#include<set>
using namespace std;

int main() {
	int n;
	int t = 0;
	while (cin >> n) {
		bool isB2 = true;
		int b[10000];
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			if (b[i] < 1) isB2 = false;
		}
			
		for (int i = 0; i < n - 1; i++) {
			if (b[i] >= b[i + 1])
				isB2 = false;
		}
		set<int> sums;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				int num = b[i] + b[j];
				if (sums.count(num))
					isB2 = false;
				sums.insert(num);
			}
		}
		cout << "Case #" << ++t << ": ";
		if (isB2)
			cout << "It is a B2-Sequence.\n";
		else
			cout << "It is not a B2-Sequence.\n";

		cout << "\n";
	}
	return 0;
}
