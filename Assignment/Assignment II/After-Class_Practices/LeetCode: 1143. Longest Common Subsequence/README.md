# LeetCode 1143 - Longest Common Subsequence

## 1. 題目摘要

給定兩個字串 `text1` 與 `text2`，請找出它們的**最長共同子序列（Longest Common Subsequence, LCS）**長度。

子序列（Subsequence）指的是在**不改變原本字元相對順序**的情況下，刪除部分字元後所形成的序列。

例如：

```text
Input:
text1 = "abcde"
text2 = "ace"

Output:
3

Explanation:
最長共同子序列為 "ace"。
```

```text
Input:
text1 = "abc"
text2 = "abc"

Output:
3
```

```text
Input:
text1 = "abc"
text2 = "def"

Output:
0
```

---

## 2. 解題邏輯

本題使用 **Dynamic Programming（動態規劃）**。

建立二維陣列：

```cpp
dp[i][j]
```

表示：

> `text1` 前 `i` 個字元與 `text2` 前 `j` 個字元的最長共同子序列長度。

---

### Step 1：初始化 DP

建立大小為：

```cpp
(m + 1) × (n + 1)
```

的 DP 陣列，全部初始化為 `0`。

其中：

- `m = text1.length()`
- `n = text2.length()`

第一列與第一行皆為 `0`，表示任一字串為空時，LCS 長度一定為 0。

---

### Step 2：狀態轉移

依序比較：

```cpp
text1[i - 1]
```

與

```cpp
text2[j - 1]
```

若兩字元相同：

```cpp
dp[i][j] = dp[i - 1][j - 1] + 1;
```

表示找到新的共同字元，LCS 長度加一。

若兩字元不同：

```cpp
dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
```

取：

- 不使用 `text1[i-1]`
- 不使用 `text2[j-1]`

兩種情況中的最大值。

---

### Step 3：回傳答案

DP 完成後：

```cpp
dp[m][n]
```

就是兩個字串的最長共同子序列長度。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m][n];
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| 時間複雜度 | **O(m × n)** |
| 空間複雜度 | **O(m × n)** |

其中：

- `m` 為 `text1` 的長度。
- `n` 為 `text2` 的長度。

每個 `dp[i][j]` 只計算一次，因此時間複雜度為 **O(m × n)**；DP 陣列需儲存 `(m + 1) × (n + 1)` 個元素，因此空間複雜度為 **O(m × n)**。

---

## 5. 重點整理

- 使用 **Dynamic Programming（DP）** 解決最長共同子序列問題。
- `dp[i][j]` 表示 `text1` 前 `i` 個字元與 `text2` 前 `j` 個字元的 LCS 長度。
- 若目前字元相同：
  ```cpp
  dp[i][j] = dp[i - 1][j - 1] + 1;
  ```
- 若目前字元不同：
  ```cpp
  dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
  ```
- 最終答案為 `dp[m][n]`，時間複雜度為 **O(m × n)**。
