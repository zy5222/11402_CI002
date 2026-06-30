#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        vector<int> dragons(n);
        vector<int> knights(m);

        for (int i = 0; i < n; ++i) cin >> dragons[i];
        for (int i = 0; i < m; ++i) cin >> knights[i];

        sort(dragons.begin(), dragons.end());
        sort(knights.begin(), knights.end());

        long long total_cost = 0;
        int d_idx = 0, k_idx = 0;
        bool possible = true;

        while (d_idx < n) {
            while (k_idx < m && knights[k_idx] < dragons[d_idx]) {
                k_idx++;
            }
            if (k_idx < m) {
                total_cost += knights[k_idx];
                d_idx++; 
                k_idx++; 
            } else {
                possible = false;
                break;
            }
        }

        if (possible) cout << total_cost << "\n";
        else cout << "Loowater is doomed!\n";
    }
    return 0;
}
