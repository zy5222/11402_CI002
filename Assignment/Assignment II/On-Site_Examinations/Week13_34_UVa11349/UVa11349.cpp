#include <iostream>
#include <vector>
using namespace std;

void solve(int case_num) {
    char n_char, eq_char;
    long long n;
    
    cin >> n_char >> eq_char >> n;

    long long size = n * n;
    vector<long long> matrix(size);
    bool is_symmetric = true;

    for (long long i = 0; i < size; ++i) {
        cin >> matrix[i];
        if (matrix[i] < 0) {
            is_symmetric = false;
        }
    }

    if (is_symmetric) {
        for (long long i = 0; i <= size / 2; ++i) {
            if (matrix[i] != matrix[size - 1 - i]) {
                is_symmetric = false;
                break;
            }
        }
    }

    if (is_symmetric) {
        cout << "Test #" << case_num << ": Symmetric.\n";
    } else {
        cout << "Test #" << case_num << ": Non-symmetric.\n";
    }
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
