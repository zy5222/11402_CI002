#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int a = v[0];
		int b = v[n - 1];
		int ans = (b - a) * 2;
		cout << ans << "\n";
	}
	return 0;
}
