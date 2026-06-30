# LeetCode 1022 - Sum of Root To Leaf Binary Numbers

## 1. 題目摘要
給定一棵二元樹，其所有節點之值僅為 $0$ 或 $1$。每一條從根節點（Root）至葉節點（Leaf）之路徑，皆代表一個二進位數字（最頂端的根節點為最高有效位元）。請計算並回傳樹中所有從根節點到葉節點之二進位數字的總和。

---

## 2. 解題邏輯
本題屬於經典的二元樹路徑走訪問題，最佳解法為採用**深度優先搜尋（DFS，Depth-First Search）**，透過前序走訪（Preorder Traversal）在向下探索的過程中持續累加數值。

1. **二進位數值推導**：
   在 $10$ 進位系統中，將數字附加於尾端之操作為 `val = val * 10 + digit`。同理，於 $2$ 進位系統中，向尾端附加新位元之操作為 `val = val * 2 + bit`。
   為提升運算效率，可改用**位元運算**來實現此過程：`val = (val << 1) | bit`（向左位移一位等同於乘以 $2$，位元或運算等同於加上該位元值）。

2. **遞迴狀態傳遞**：
   撰寫一遞迴函式 `dfs(node, current_val)`：
   * 傳入當前節點 `node` 與累積至此之二進位數值 `current_val`。
   * 若 `node` 為空（`nullptr`），表示該路徑無效，回傳 $0$。
   * 更新累積數值：`current_val = (current_val << 1) | node->val`。
   * 若當前節點為**葉節點**（即無左子節點與右子節點），代表一條完整路徑已走訪完畢，直接回傳此時的 `current_val`。
   * 若非葉節點，則將其左子樹與右子樹之遞迴計算結果相加並回傳。

---

## 3. 程式碼實作

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
    
private:
    int dfs(TreeNode* node, int current_val) {
        if (node == nullptr) {
            return 0;
        }
        
        // 位元運算：左移一位並合併當前節點值
        current_val = (current_val << 1) | node->val;
        
        // 若為葉節點，回傳該路徑所代表之完整數值
        if (node->left == nullptr && node->right == nullptr) {
            return current_val;
        }
        
        // 將左右子樹之結果加總
        return dfs(node->left, current_val) + dfs(node->right, current_val);
    }
};
