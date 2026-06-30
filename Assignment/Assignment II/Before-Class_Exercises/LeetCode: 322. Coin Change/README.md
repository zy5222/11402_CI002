# LeetCode 322 - Coin Change

## 1. 題目摘要

給定一個整數陣列 `coins`，表示不同面額的硬幣，以及一個整數 `amount`，表示目標金額。

每種硬幣可以使用**無限次**。

請計算湊出 `amount` 所需的**最少硬幣數量**；若無法湊出，則回傳 `-1`。

例如：

```text
Input:
coins = [1,2,5]
amount = 11

Output:
3
```

Explanation：

```text
11 = 5 + 5 + 1

共使用 3 枚硬幣。
```

```text
Input:
coins = [2]
amount = 3

Output:
-1
```

---

## 2. 解題邏輯

本題使用 **Dynamic Programming（動態規劃）**。

建立一維陣列：

```cpp
dp[i]
```

表示：

> 湊出金額 `i` 所需的最少硬幣數量。

---

### Step 1：初始化

建立大小為：

```cpp
amount + 1
```

的 DP 陣列。

初始化為：

```cpp
amount + 1
```

代表目前無法湊出該金額（相當於無限大）。

並設定：

```cpp
dp[0] = 0;
```

表示湊出金額 0 不需要任何硬幣。

---

### Step 2：狀態轉移

依序計算每個金額：

```cpp
for (int i = 1; i <= amount; i++)
```

對每種硬幣：

```cpp
coin
```

若：

```cpp
i >= coin
```

即可使用此硬幣更新答案：

```cpp
dp[i] = min(dp[i], dp[i - coin] + 1);
```

表示：

- 先湊出 `i - coin`
- 再加入一枚 `coin`

---

### Step 3：判斷是否可湊出

若：

```cpp
dp[amount] > amount
```

代表從未成功更新。

因此回傳：

```cpp
-1;
```

否則回傳：

```cpp
dp[amount];
```

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| 時間複雜度 | **O(n × amount)** |
| 空間複雜度 | **O(amount)** |

其中：

- `n` 為硬幣種類數量。
- `amount` 為目標金額。

每個金額都會遍歷所有硬幣，因此時間複雜度為 **O(n × amount)**。

DP 陣列需儲存 `amount + 1` 個狀態，因此空間複雜度為 **O(amount)**。

---

## 5. 重點整理

- 使用 **Dynamic Programming（DP）** 解決最少硬幣數問題。
- `dp[i]` 表示湊出金額 `i` 所需的最少硬幣數。
- 初始化時，將所有狀態設為 `amount + 1`，代表尚不可達。
- 狀態轉移公式為：
  ```cpp
  dp[i] = min(dp[i], dp[i - coin] + 1);
  ```
- 若 `dp[amount]` 未被更新，表示無法湊出目標金額，回傳 `-1`。
- 此方法是本題最經典且效率最佳的動態規劃解法，時間複雜度為 **O(n × amount)**。
