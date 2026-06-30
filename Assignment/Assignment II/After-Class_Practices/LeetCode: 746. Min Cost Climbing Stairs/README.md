# LeetCode 746 - Min Cost Climbing Stairs

## 1. 題目摘要

給定一個整數陣列 `cost`，其中：

```cpp
cost[i]
```

表示踩到第 `i` 階樓梯所需支付的花費。

每次可以選擇：

- 爬 **1 階**
- 爬 **2 階**

可以從：

- 第 `0` 階開始
- 第 `1` 階開始

請回傳到達樓梯頂端所需的**最小花費**。

例如：

```text
Input:
cost = [10,15,20]

Output:
15
```

Explanation：

```text
從第 1 階開始：

15 → Top

總花費 = 15
```

```text
Input:
cost = [1,100,1,1,1,100,1,1,100,1]

Output:
6
```

---

## 2. 解題邏輯

本題使用 **Dynamic Programming（動態規劃）**。

建立一維陣列：

```cpp
dp[i]
```

表示：

> 到達第 `i` 階所需的最小花費。

---

### Step 1：初始化

由於可以直接從第 0 或第 1 階開始，因此：

```cpp
dp[0] = cost[0];
dp[1] = cost[1];
```

---

### Step 2：狀態轉移

到達第 `i` 階有兩種方式：

- 從第 `i-1` 階爬 1 階。
- 從第 `i-2` 階爬 2 階。

因此：

```cpp
dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
```

表示選擇花費較小的路徑，再加上目前階梯的花費。

---

### Step 3：回傳答案

樓梯頂端位於最後一階之後，因此可以由：

- 最後一階
- 倒數第二階

直接到達。

因此答案為：

```cpp
min(dp[n - 1], dp[n - 2]);
```

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }

        return min(dp[n - 1], dp[n - 2]);
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

每個階梯只會計算一次，因此時間複雜度為 **O(n)**。

DP 陣列需儲存 `n` 個狀態，因此空間複雜度為 **O(n)**。

> **補充：** 此題也可透過滾動變數（Rolling Array）將空間複雜度最佳化為 **O(1)**。

---

## 5. 重點整理

- 使用 **Dynamic Programming（DP）** 計算到達每一階的最小花費。
- `dp[i]` 表示到達第 `i` 階所需的最小花費。
- 狀態轉移公式為：
  ```cpp
  dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
  ```
- 最終答案不是 `dp[n-1]`，而是：
  ```cpp
  min(dp[n - 1], dp[n - 2]);
  ```
  因為可從最後一階或倒數第二階直接到達樓梯頂端。
- 此方法時間複雜度為 **O(n)**，是本題最經典的動態規劃解法。
