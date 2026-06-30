# LeetCode 110 - Balanced Binary Tree

## 1. 題目摘要
給定一棵二元樹，請判斷其是否為「高度平衡」（Height-Balanced）之二元樹。
高度平衡二元樹之定義為：樹中每個節點的左子樹與右子樹的高度差絕對值不得超過 $1$。

---

## 2. 解題邏輯
本題若採用由上而下（Top-down）的方式，針對每個節點皆呼叫函式重新計算其左右子樹之高度，將導致大量重複計算，最差時間複雜度會退化至 $O(N^2)$。為達最佳效能，應採用**由下而上（Bottom-up）的深度優先搜尋（DFS）**策略。

1. **遞迴高度計算與平衡檢驗**：
   撰寫一遞迴函式 `checkHeight(node)`，該函式具備雙重功能：若子樹平衡，則回傳該子樹之實際高度；若子樹不平衡，則回傳一個特殊標記值（如 $-1$）以代表失衡。

2. **遞迴終止條件**：
   若傳入之節點為空（`nullptr`），代表到達空節點，其高度為 $0$，直接回傳 $0$。

3. **子樹高度取得與失衡傳遞**：
   * 遞迴呼叫取得左子樹之高度 `leftHeight`。若 `leftHeight` 為 $-1$，代表左子樹內部已失衡，無需繼續計算，直接向上回傳 $-1$。
   * 遞迴呼叫取得右子樹之高度 `rightHeight`。若 `rightHeight` 為 $-1$，同樣直接向上回傳 $-1$。

4. **當前節點之平衡檢驗**：
   比較 `leftHeight` 與 `rightHeight` 之差值絕對值。
   * 若差距大於 $1$，代表以當前節點為根的子樹失衡，回傳 $-1$。
   * 若差距小於或等於 $1$，代表當前子樹平衡，計算並回傳其高度：`max(leftHeight, rightHeight) + 1`。

5. **回傳最終結果**：
   於主函式中呼叫 `checkHeight(root)`，若回傳值不等於 $-1$，則代表整棵樹為高度平衡，回傳 `true`；否則回傳 `false`。

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
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
    
private:
    int checkHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        
        // 檢查左子樹是否平衡
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) {
            return -1;
        }
        
        // 檢查右子樹是否平衡
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) {
            return -1;
        }
        
        // 檢查當前節點是否平衡
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        
        // 回傳當前節點之高度
        return max(leftHeight, rightHeight) + 1;
    }
};
