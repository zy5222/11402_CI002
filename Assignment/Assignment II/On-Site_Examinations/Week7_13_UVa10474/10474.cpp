#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, q;
	int t = 0;
	while (cin >> n >> q) {
		if (n == 0 || q == 0) break;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		cout << "CASE# " << ++t << ":\n";
		int marble;
		for (int i = 0; i < q; i++) {
			cin >> marble;
			bool found = false;
			for (int j = 0; j < v.size(); j++) {
				if (marble == v[j]) {
					cout << marble << " found at " << j + 1 << "\n";
					found = true;
					break;
				}
			}
			if(!found)
				cout << marble << " not found\n";
		}
	}
	return 0;
}
