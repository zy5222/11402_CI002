#include <iostream>
#include <vector>

using namespace std;

int main() {
    int s, b;
    while (cin >> s >> b && (s != 0 || b != 0)) {
        vector<int> L(s + 2), R(s + 2);
        for (int i = 1; i <= s; ++i) {
            L[i] = i - 1;
            R[i] = i + 1;
        }
        L[1] = 0;
        R[s] = 0;

        for (int i = 0; i < b; ++i) {
            int l, r;
            cin >> l >> r;

            R[L[l]] = R[r];
            L[R[r]] = L[l];

            if (L[l] == 0) cout << "* ";
            else cout << L[l] << " ";

            if (R[r] == 0) cout << "*\n";
            else cout << R[r] << "\n";
        }
        cout << "-\n";
    }
    return 0;
}
