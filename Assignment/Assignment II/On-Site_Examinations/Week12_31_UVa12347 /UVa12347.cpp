#include <iostream>
#include <vector>

using namespace std;

vector<int> pre;

// 傳入當前子樹在陣列中的區間 [left, right]
void postOrder(int left, int right) {
    // 區間無效代表子樹為空，直接返回
    if (left > right) return;

    int root = pre[left];
    
    // 尋找左右子樹的分界點
    int split = left + 1;
    while (split <= right && pre[split] < root) {
        split++;
    }

    // 後序遍歷：先走左子樹，再走右子樹，最後印出根節點
    postOrder(left + 1, split - 1); // 左子樹區間
    postOrder(split, right);        // 右子樹區間
    
    cout << root << "\n";
}

int main() {
    int val;
    while (cin >> val) {
        pre.push_back(val);
    }
    if (!pre.empty()) {
        postOrder(0, pre.size() - 1);
    }

    return 0;
}
