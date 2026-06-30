#include <iostream>
using namespace std;

void solve() {
    int d, i;
    cin >> d >> i;
    
    int k = 1; // 從根節點 1 開始
    
    // 往下走 D-1 層
    for (int level = 0; level < d - 1; ++level) {
        if (i % 2 == 1) {
            // 奇數：往左走
            k = k * 2;
            i = (i + 1) / 2;
        } else {
            // 偶數：往右走
            k = k * 2 + 1;
            i = i / 2;
        }
    }
    
    cout << k << "\n";
}

int main() {
    int t;
    while (cin >> t && t != -1) {
        while (t--) {
            solve();
        }
    }
    
    return 0;
}
