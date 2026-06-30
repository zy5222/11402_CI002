# LeetCode 64 - Minimum Path Sum

## 1. 題目摘要
給定一個包含非負整數的 $m \times n$ 網格 `grid`，請找出一條從左上角（座標 $(0, 0)$）移動至右下角（座標 $(m-1, n-1)$）的路徑，使得路徑上所有數字之總和為最小。規定機器人每次僅能向下或向右移動一步。

---

## 2. 解題邏輯
本題為標準之**動態規劃（Dynamic Programming, DP）**問題。由於移動方向之限制，抵達任意網格 $(i, j)$ 的最小路徑和，必定取決於其上方格 $(i-1, j)$ 與左方格 $(i, j-1)$ 兩者路徑和之較小值。

1. **狀態轉移方程式**：
   設 $dp[i][j]$ 為抵達網格 $(i, j)$ 之最小路徑和，則：
   $$dp[i][j] = grid[i][j] + \min(dp[i-1][j], dp[i][j-1])$$

2. **邊界條件（Base Case）處理**：
   * **起點**：$(0, 0)$ 之路徑和即為 $grid[0][0]$ 本身。
   * **第一列（Row 0）**：因無法從上方進入，僅能由左方一路向右移動，故 $dp[0][j] = dp[0][j-1] + grid[0][j]$。
   * **第一行（Column 0）**：因無法從左方進入，僅能由上方一路向下移動，故 $dp[i][0] = dp[i-1][0] + grid[i][0]$。

3. **空間最佳化（In-place Modification）**：
   若面試條件允許修改傳入之原始陣列，可直接將計算出之 DP 狀態覆寫於 `grid` 中，省去額外配置二維陣列之記憶體開銷。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // 處理第一行的邊界條件 (僅能由上往下)
        for (int i = 1; i < m; ++i) {
            grid[i][0] += grid[i - 1][0];
        }
        
        // 處理第一列的邊界條件 (僅能由左往右)
        for (int j = 1; j < n; ++j) {
            grid[0][j] += grid[0][j - 1];
        }
        
        // 處理剩餘內部網格
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        
        // 右下角即為整條路徑之最小總和
        return grid[m - 1][n - 1];
    }
};
