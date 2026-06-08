#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	long long s;
	while (cin >> n >> s) {
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int left = 0;
		int sum = 0;
		int min_sum = n + 1;
		for (int right = 0; right < n; right++) {
			sum += arr[right];
			while (sum >= s) {
				min_sum = min(min_sum, right - left + 1);
				sum -= arr[left];
				left++;
			}
		}
		if (min_sum == n + 1)
			cout << 0 << "\n";
		else
			cout << min_sum << "\n";
	}
	return 0;
}
