#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int i = 0; i < n; ++i) {
            long long val;
            cin >> val;
            pq.push(val);
        }

        long long total_cost = 0;

        while (pq.size() > 1) {
            long long first = pq.top();
            pq.pop();
            
            long long second = pq.top();
            pq.pop();

            long long current_sum = first + second;
            total_cost += current_sum;
            
            pq.push(current_sum);
        }

        cout << total_cost << "\n";
    }

    return 0;
}
