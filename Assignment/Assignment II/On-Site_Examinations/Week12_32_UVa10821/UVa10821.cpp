#include <iostream>
#include <algorithm>
using namespace std;

void buildBST(int L, int R, int H) {
    if (L > R) return;
    
    // 計算右子樹的極限容量
    int right_capacity = 0;
    if (H - 1 >= 30) {
        right_capacity = 1e9; // 若高度非常充裕，視為無限大
    } else {
        right_capacity = (1 << (H - 1)) - 1;
    }
    
    // 找出符合條件的最小根節點
    int root = max(L, R - right_capacity);
    
    cout << " " << root;
    
    // 遞迴左子樹與右子樹
    buildBST(L, root - 1, H - 1);
    buildBST(root + 1, R, H - 1);
}

int main() {

    int n, h;
    int case_num = 1;
    
    while (cin >> n >> h && (n != 0 || h != 0)) {
        cout << "Case " << case_num++ << ":";
        
        // 判斷是否超過最大節點容納數
        long long max_nodes = (h >= 30) ? 2e9 : (1LL << h) - 1;
        
        if (n > max_nodes) {
            cout << " Impossible.\n";
        } else {
            buildBST(1, n, h);
            cout << "\n";
        }
    }
    return 0;
}
