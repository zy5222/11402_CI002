#include <iostream>
#include <algorithm>
using namespace std;

// 計算節點的層級 (Level)，根節點 1 的層級為 0
int get_level(long long x) {
    int lvl = 0;
    while (x > 1) {
        x /= 2;
        lvl++;
    }
    return lvl;
}

void solve() {
    long long n, a, b;
    cin >> n >> a >> b;
    
    // 如果 A 和 B 已經是同一個節點，則沒有任何節點被額外合併
    if (a == b) {
        cout << (1LL << n) - 1 << "\n";
        return;
    }
    
    int lvl_a = get_level(a);
    int lvl_b = get_level(b);
    int max_lvl = max(lvl_a, lvl_b);
    
    // 較小子樹的節點數 (即被合併掉、損失的節點數)
    long long lost = (1LL << (n - max_lvl)) - 1;
    long long total_nodes = (1LL << n) - 1;
    cout << total_nodes - lost << "\n";
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
