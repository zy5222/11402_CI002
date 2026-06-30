# LeetCode 304 - Range Sum Query 2D - Immutable

## 1. 題目摘要

設計一個 `NumMatrix` 類別，支援多次查詢二維矩陣指定區域的元素總和。

需實作：

- `NumMatrix(vector<vector<int>>& matrix)`：初始化矩陣。
- `sumRegion(row1, col1, row2, col2)`：回傳矩形區域 `(row1, col1)` 到 `(row2, col2)`（包含邊界）的元素總和。

例如：

```text
Input:
matrix =
[
  [3,0,1,4,2],
  [5,6,3,2,1],
  [1,2,0,1,5],
  [4,1,0,1,7],
  [1,0,3,0,5]
]

sumRegion(2,1,4,3)

Output:
8
```

---

## 2. 解題邏輯

本題可利用 **2D Prefix Sum（二維前綴和）**，讓每次查詢區域總和只需 **O(1)** 時間。

---

### Step 1：建立二維 Prefix Sum

建立大小為：

```cpp
(rows + 1) × (cols + 1)
```

的二維陣列 `prefix`，並將第 0 列與第 0 行初始化為 0，方便處理邊界。

每個位置的前綴和計算方式為：

```cpp
prefix[i][j] =
matrix[i - 1][j - 1]
+ prefix[i - 1][j]
+ prefix[i][j - 1]
- prefix[i - 1][j - 1];
```

其中：

- `prefix[i - 1][j]`：上方區域總和。
- `prefix[i][j - 1]`：左方區域總和。
- `prefix[i - 1][j - 1]`：重複計算的部分，因此需扣除一次。

---

### Step 2：查詢矩形區域

若查詢矩形：

```text
(row1, col1)
        ↓
(row2, col2)
```

即可利用前綴和快速計算：

```cpp
prefix[row2 + 1][col2 + 1]
- prefix[row1][col2 + 1]
- prefix[row2 + 1][col1]
+ prefix[row1][col1];
```

利用加減法即可得到指定區域的總和。

---

## 3. 程式碼實作

```cpp
class NumMatrix {
private:
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        prefix.assign(rows + 1, vector<int>(cols + 1, 0));

        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                prefix[i][j] = matrix[i - 1][j - 1]
                             + prefix[i - 1][j]
                             + prefix[i][j - 1]
                             - prefix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2 + 1][col2 + 1]
             - prefix[row1][col2 + 1]
             - prefix[row2 + 1][col1]
             + prefix[row1][col1];
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| 建構時間 | **O(m × n)** |
| 查詢時間 | **O(1)** |
| 空間複雜度 | **O(m × n)** |

其中：

- `m` 為矩陣列數。
- `n` 為矩陣行數。

初始化需遍歷整個矩陣一次，因此時間複雜度為 **O(m × n)**；每次查詢只需固定次數的加減運算，因此為 **O(1)**。

---

## 5. 重點整理

- 使用 **2D Prefix Sum（二維前綴和）** 預先計算所有矩形累積和。
- 建立 `(rows + 1) × (cols + 1)` 的前綴和矩陣，可簡化邊界處理。
- 查詢矩形區域時利用容斥原理：
  ```cpp
  prefix[row2 + 1][col2 + 1]
  - prefix[row1][col2 + 1]
  - prefix[row2 + 1][col1]
  + prefix[row1][col1];
  ```
- 初始化需 **O(m × n)**，之後每次查詢皆可在 **O(1)** 時間完成。
- 此方法非常適合「矩陣不會修改、需要大量區域查詢」的情境。
