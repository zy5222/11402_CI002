# LeetCode 1022 - Sum of Root To Leaf Binary Numbers

## 1. 題目摘要

給定一棵二元樹，每個節點的值皆為 `0` 或 `1`。

每一條**從根節點（Root）到葉節點（Leaf）**的路徑都可視為一個二進位數字。

請計算所有根到葉路徑所代表的二進位數值總和。

例如：

```text
Input:
        1
      /   \
     0     1
    / \   / \
   0  1  0  1

Output:
22
```

Explanation：

```text
100 = 4
101 = 5
110 = 6
111 = 7

4 + 5 + 6 + 7 = 22
```

---

## 2. 解題邏輯

本題可利用 **Depth First Search（DFS）** 遞迴遍歷整棵二元樹。

在往下走的過程中，同步建立目前路徑所代表的二進位數值。

---

### Step 1：更新目前的二進位數值

當走到目前節點時：

```cpp
current = current * 2 + root->val;
```

也可以寫成：

```cpp
current = (current << 1) | root->val;
```

因為：

- 左移一位相當於乘以 2。
- 再加入目前節點的 0 或 1。

例如：

```text
目前：101 (5)

加入 1

1010 + 1

得到

1011 (11)
```

---

### Step 2：判斷是否為葉節點

若目前節點：

```cpp
root->left == nullptr &&
root->right == nullptr
```

表示已完成一條 Root → Leaf 路徑。

直接回傳目前的二進位數值：

```cpp
return current;
```

---

### Step 3：遞迴左右子樹

若不是葉節點，則繼續往左右子樹搜尋：

```cpp
return dfs(root->left, current)
     + dfs(root->right, current);
```

最後所有葉節點回傳的數值加總，即為答案。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    int dfs(TreeNode* root, int current) {
        if (!root)
            return 0;

        current = (current << 1) | root->val;

        if (!root->left && !root->right)
            return current;

        return dfs(root->left, current)
             + dfs(root->right, current);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| 時間複雜度 | **O(n)** |
| 空間複雜度 | **O(h)** |

其中：

- `n` 為樹中的節點數。
- `h` 為二元樹高度。

DFS 會走訪每個節點一次，因此時間複雜度為 **O(n)**。

遞迴呼叫堆疊最多為樹高，因此空間複雜度為 **O(h)**。

---

## 5. 重點整理

- 使用 **DFS（Depth First Search）** 遍歷所有 Root → Leaf 路徑。
- 每走到一個節點，就利用：
  ```cpp
  current = (current << 1) | root->val;
  ```
  更新目前的二進位數值。
- 到達葉節點時，回傳該路徑代表的十進位數值。
- 左右子樹的結果相加，即為所有路徑的總和。
- 每個節點只會拜訪一次，因此時間複雜度為 **O(n)**。
