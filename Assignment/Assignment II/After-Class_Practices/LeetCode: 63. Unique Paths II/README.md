# LeetCode 63 - Unique Paths II

## 1. 題目摘要

給定一個 `m × n` 的網格 `obstacleGrid`，其中：

- `0` 表示可通行。
- `1` 表示障礙物。

機器人起點位於左上角 `(0,0)`，終點位於右下角 `(m-1,n-1)`。

機器人每次只能：

- 向右移動。
- 向下移動。

請計算從起點走到終點共有多少種不同的路徑。

若起點或終點為障礙物，則無法到達，回傳 `0`。

例如：

```text
Input:
obstacleGrid =
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

Output:
2
```

---

## 2. 解題邏輯

本題可利用 **Dynamic Programming（動態規劃）**。

建立一個二維陣列 `dp`，其中：

```cpp
dp[i][j]
```

表示到達位置 `(i, j)` 的不同路徑數。

---

### Step 1：初始化起點

若起點就是障礙物：

```cpp
obstacleGrid[0][0] == 1
```

直接回傳：

```cpp
0
```

否則：

```cpp
dp[0][0] = 1;
```

代表起點只有一種走法。

---

### Step 2：遇到障礙物

若目前格子為障礙物：

```cpp
obstacleGrid[i][j] == 1
```

則：

```cpp
dp[i][j] = 0;
```

表示無法走到此位置。

---

### Step 3：狀態轉移

若不是障礙物，則目前位置可由：

- 上方
- 左方

走過來，因此：

```cpp
dp[i][j] =
dp[i-1][j] + dp[i][j-1];
```

但需注意邊界：

若第一列只能從左邊走來。

若第一行只能從上方走來。

---

### Step 4：回傳答案

最後：

```cpp
dp[m-1][n-1]
```

即為所有不同路徑數。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    if (i > 0)
                        dp[i][j] += dp[i - 1][j];
                    if (j > 0)
                        dp[i][j] += dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
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

- `m` 為列數。
- `n` 為行數。

每個格子只會計算一次，因此時間複雜度為 **O(m × n)**。

DP 陣列大小為 `m × n`，因此空間複雜度為 **O(m × n)**。

---

## 5. 重點整理

- 使用 **Dynamic Programming（DP）** 計算每個位置的路徑數。
- `dp[i][j]` 表示走到 `(i, j)` 的不同路徑數。
- 若遇到障礙物，則 `dp[i][j] = 0`。
- 狀態轉移公式為：
  ```cpp
  dp[i][j] = dp[i-1][j] + dp[i][j-1];
  ```
- 最終答案為 `dp[m-1][n-1]`。
- 此方法時間複雜度為 **O(m × n)**，是本題最常見的解法。
