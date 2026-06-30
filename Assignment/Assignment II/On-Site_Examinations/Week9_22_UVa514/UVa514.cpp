#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        int first_target;
        
        while (cin >> first_target && first_target != 0) {
            vector<int> target(n);
            target[0] = first_target;
            for (int i = 1; i < n; ++i) {
                cin >> target[i];
            }

            stack<int> station;
            int current_car = 1;
            bool possible = true;

            for (int i = 0; i < n; ++i) {
                // 如果車站頂部不是目標車廂，就把 A 方向的車持續開進站
                while (current_car <= n && (station.empty() || station.top() != target[i])) {
                    station.push(current_car);
                    current_car++;
                }

                // 檢查車站頂部是否為目標車廂
                if (station.top() == target[i]) {
                    station.pop();
                } else {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
