#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, m;
    int case_num = 1;
    bool first = true;

    while (cin >> n >> m && (n != 0 || m != 0)) {
        if (!first) {
            cout << "\n";
        }
        first = false;

        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }

        cout << "Field #" << case_num++ << ":\n";

        // 8 個方向的座標偏移量
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '*') {
                    cout << '*';
                } else {
                    int mines = 0;
                    for (int k = 0; k < 8; ++k) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '*') {
                            mines++;
                        }
                    }
                    cout << mines;
                }
            }
            cout << "\n";
        }
    }

    return 0;
}
