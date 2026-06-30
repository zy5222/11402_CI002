#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int m, c;
    cin >> m >> c;
    vector<vector<bool>> dp(c + 1, vector<bool>(m + 1, false));
    
    dp[0][0] = true;

    for (int g = 1; g <= c; ++g) {
        int k;
        cin >> k;
        for (int i = 0; i < k; ++i) {
            int price;
            cin >> price;
            for (int b = 0; b <= m - price; ++b) {
                if (dp[g - 1][b]) {
                    dp[g][b + price] = true;
                }
            }
        }
    }

    // 從最大預算開始往下找，第一個 true 就是最大可能花費
    for (int b = m; b >= 0; --b) {
        if (dp[c][b]) {
            cout << b << "\n";
            return;
        }
    }
    cout << "no solution\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
