# LeetCode 70 - Climbing Stairs

## 1. 題目摘要

假設共有 `n` 階樓梯，每次可以選擇：

- 爬 **1 階**
- 爬 **2 階**

請計算共有多少種不同的方法可以爬到樓梯頂端。

例如：

```text
Input:
n = 2

Output:
2
```

Explanation：

共有兩種方式：

```text
1 + 1
2
```

```text
Input:
n = 3

Output:
3
```

Explanation：

共有三種方式：

```text
1 + 1 + 1
1 + 2
2 + 1
```

---

## 2. 解題邏輯

本題使用 **Dynamic Programming（動態規劃）**。

建立一維陣列：

```cpp
dp[i]
```

表示：

> 爬到第 `i` 階樓梯的方法總數。

---

### Step 1：初始化

當：

```text
n = 1
```

只有一種方法：

```cpp
dp[1] = 1;
```

當：

```text
n = 2
```

共有兩種方法：

```cpp
dp[2] = 2;
```

---

### Step 2：狀態轉移

到達第 `i` 階有兩種方式：

1. 從第 `i-1` 階爬 1 階。
2. 從第 `i-2` 階爬 2 階。

因此：

```cpp
dp[i] = dp[i - 1] + dp[i - 2];
```

這與 **費波那契數列（Fibonacci Sequence）** 的遞推方式相同。

---

### Step 3：回傳答案

DP 計算完成後：

```cpp
dp[n]
```

即為爬到第 `n` 階的方法總數。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;

        vector<int> dp(n + 1);

        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| 時間複雜度 | **O(n)** |
| 空間複雜度 | **O(n)** |

其中：

- `n` 為樓梯階數。

每一階只需計算一次，因此時間複雜度為 **O(n)**。

DP 陣列需儲存 `n + 1` 個狀態，因此空間複雜度為 **O(n)**。

> **補充：** 由於每次只會使用前兩個狀態，因此可利用滾動變數（Rolling Array）將空間複雜度最佳化為 **O(1)**。

---

## 5. 重點整理

- 使用 **Dynamic Programming（DP）** 解決問題。
- `dp[i]` 表示爬到第 `i` 階的方法數。
- 狀態轉移公式為：
  ```cpp
  dp[i] = dp[i - 1] + dp[i - 2];
  ```
- 此題的遞推方式與 **費波那契數列（Fibonacci Sequence）** 相同。
- 時間複雜度為 **O(n)**，空間複雜度為 **O(n)**；若使用滾動變數，可將空間最佳化為 **O(1)**。
