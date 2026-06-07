#include<iostream>
#include<vector>
using namespace std;

bool can_fill(vector<int>& v, int m, int cap) {
	int count = 1;//紀錄目前用到第幾個大桶子
	int cur_sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (cur_sum + v[i] > cap) {
			count++;
			cur_sum = v[i];
		}
		else {
			cur_sum += v[i];
		}
	}
	return count <= m;
}
int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<int> v(n);
		int max_val = 0;// 用來找下界 (最大那杯牛奶)
		int total_sum = 0;// 用來找上界 (全部牛奶總和)
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			max_val = max(max_val, v[i]);
			total_sum += v[i];
		}
		int left = max_val;
		int right = total_sum;
		int ans = right;// 先預設答案是最大值

		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (can_fill(v, m, mid)) {
				ans = mid;
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
