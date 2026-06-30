# LeetCode 222 - Count Complete Tree Nodes

## 1. 題目摘要

給定一棵**完全二元樹（Complete Binary Tree）**的根節點 `root`，請計算並回傳樹中的節點總數。

完全二元樹的特性：

- 除了最後一層外，其餘各層皆已填滿。
- 最後一層的節點皆集中在最左側。

例如：

```text
Input:
root = [1,2,3,4,5,6]

Output:
6
```

```text
Input:
root = []

Output:
0
```

---

## 2. 解題邏輯

本題利用**完全二元樹的特性**，搭配遞迴（Recursion）進行計算。

若一棵子樹的左高度與右高度相同，表示它是一棵**滿二元樹（Perfect Binary Tree）**，可直接利用公式計算節點數，而不需逐一遍歷。

---

### Step 1：計算左右高度

從目前節點開始：

- 一路往左走，得到左高度 `leftHeight`。
- 一路往右走，得到右高度 `rightHeight`。

```cpp
while (left) {
    leftHeight++;
    left = left->left;
}

while (right) {
    rightHeight++;
    right = right->right;
}
```

---

### Step 2：判斷是否為滿二元樹

若：

```cpp
leftHeight == rightHeight
```

表示目前子樹為滿二元樹。

節點數可直接利用公式：

```cpp
(1 << leftHeight) - 1
```

例如：

```text
高度 = 3

節點數 = 2³ - 1 = 7
```

不需要再遞迴。

---

### Step 3：遞迴計算左右子樹

若左右高度不同，表示不是滿二元樹。

則節點總數為：

```cpp
1 + countNodes(root->left) + countNodes(root->right)
```

其中：

- `1` 為目前節點。
- 左右子樹繼續遞迴計算。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;

        int leftHeight = 0;
        int rightHeight = 0;

        TreeNode* left = root;
        TreeNode* right = root;

        while (left) {
            leftHeight++;
            left = left->left;
        }

        while (right) {
            rightHeight++;
            right = right->right;
        }

        if (leftHeight == rightHeight)
            return (1 << leftHeight) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| 時間複雜度 | **O((log n)²)** |
| 空間複雜度 | **O(log n)** |

- 每次遞迴需計算左右高度，耗時 **O(log n)**。
- 遞迴深度最多為 **O(log n)**，因此總時間複雜度為 **O((log n)²)**。
- 遞迴呼叫堆疊深度為 **O(log n)**。

---

## 5. 重點整理

- 利用**完全二元樹**的特性，不必逐一走訪所有節點。
- 計算左右高度判斷是否為**滿二元樹**。
- 若左右高度相同，可直接使用公式：
  ```cpp
  (1 << height) - 1
  ```
  快速得到節點數。
- 若不是滿二元樹，則遞迴計算左右子樹。
- 此方法比一般 DFS 的 **O(n)** 更有效率，可達 **O((log n)²)**。
