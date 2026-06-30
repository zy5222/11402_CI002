#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int r;
    cin >> r;
    
    vector<int> streets(r);
    for (int i = 0; i < r; ++i) {
        cin >> streets[i];
    }

    sort(streets.begin(), streets.end());
    int median = streets[r / 2];
    int total_distance = 0;
    for (int i = 0; i < r; ++i) {
        total_distance += abs(streets[i] - median);
    }
    
    cout << total_distance << "\n";
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
