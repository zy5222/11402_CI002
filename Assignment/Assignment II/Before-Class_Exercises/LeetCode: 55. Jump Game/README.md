# LeetCode 55 - Jump Game

## 1. 題目摘要

給定一個整數陣列 `nums`，其中：

```cpp
nums[i]
```

表示站在第 `i` 個位置時，**最多可以向前跳躍的步數**。

一開始位於陣列的第一個位置（索引 `0`），請判斷是否能夠到達最後一個位置。

若可以到達，回傳 `true`；否則回傳 `false`。

例如：

```text
Input:
nums = [2,3,1,1,4]

Output:
true
```

Explanation：

```text
0 → 1 → 4

可成功到達最後一格。
```

```text
Input:
nums = [3,2,1,0,4]

Output:
false
```

Explanation：

```text
走到索引 3 時最多只能跳 0 步，
因此無法到達最後一格。
```

---

## 2. 解題邏輯

本題使用 **Greedy（貪心法）**。

核心想法是：

> 持續記錄目前能到達的**最遠位置（farthest）**，只要每一步都能更新最遠可達位置，就有機會到達終點。

---

### Step 1：初始化最遠可達位置

建立變數：

```cpp
farthest = 0;
```

表示目前最遠可以到達的索引。

---

### Step 2：遍歷陣列

依序遍歷每個位置。

若目前索引：

```cpp
i > farthest
```

表示此位置根本無法到達。

因此直接回傳：

```cpp
false;
```

---

### Step 3：更新最遠可達位置

若目前位置可到達，則更新：

```cpp
farthest = max(farthest, i + nums[i]);
```

表示從目前位置繼續跳躍後，可到達更遠的位置。

---

### Step 4：提前結束

若：

```cpp
farthest >= nums.size() - 1
```

表示已經可以到達最後一格。

可立即回傳：

```cpp
true;
```

若遍歷完成皆未失敗，也代表可以成功到達終點。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > farthest)
                return false;

            farthest = max(farthest, i + nums[i]);

            if (farthest >= nums.size() - 1)
                return true;
        }

        return true;
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| 時間複雜度 | **O(n)** |
| 空間複雜度 | **O(1)** |

其中：

- `n` 為陣列長度。

每個位置最多只會拜訪一次，因此時間複雜度為 **O(n)**。

只使用一個變數紀錄最遠可達位置，因此空間複雜度為 **O(1)**。

---

## 5. 重點整理

- 使用 **Greedy（貪心法）** 維護目前可到達的最遠位置。
- 若目前索引超過最遠可達位置：
  ```cpp
  i > farthest
  ```
  表示無法繼續前進，直接回傳 `false`。
- 每到一個可達位置，就更新：
  ```cpp
  farthest = max(farthest, i + nums[i]);
  ```
- 當最遠可達位置已到達或超過最後一格時，即可回傳 `true`。
- 此方法時間複雜度為 **O(n)**，空間複雜度為 **O(1)**，是本題最經典且效率最佳的解法。
