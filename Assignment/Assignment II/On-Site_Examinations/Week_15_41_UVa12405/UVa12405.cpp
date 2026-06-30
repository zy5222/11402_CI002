#include <iostream>
#include <string>
using namespace std;

void solve(int case_num) {
    int n;
    cin >> n;
    string field;
    cin >> field;

    int scarecrows = 0;
    for (int i = 0; i < n; ) {
        if (field[i] == '.') {
            scarecrows++;
            i += 3;
        } else {
            i++;
        }
    }

    cout << "Case " << case_num << ": " << scarecrows << "\n";
}

int main() {
    int t;
    if (cin >> t) {
        for (int i = 1; i <= t; ++i) {
            solve(i);
        }
    }
    return 0;
}
