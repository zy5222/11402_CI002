#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }

        int max_sum = -1e9; 

        for (int top = 0; top < n; ++top) {
            vector<int> col_sum(n, 0); 
            
            for (int bottom = top; bottom < n; ++bottom) {
                int current_max = 0;
                int local_max = -1e9;

                // 1D Kadane's Algorithm
                for (int col = 0; col < n; ++col) {
                    col_sum[col] += matrix[bottom][col];

                    if (current_max >= 0) {
                        current_max += col_sum[col];
                    } else {
                        current_max = col_sum[col];
                    }
                    local_max = max(local_max, current_max);
                }
                max_sum = max(max_sum, local_max);
            }
        }
        cout << max_sum << "\n";
    }
    return 0;
}
