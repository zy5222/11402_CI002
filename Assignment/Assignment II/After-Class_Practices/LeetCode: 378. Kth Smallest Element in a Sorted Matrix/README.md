# LeetCode 378 - Kth Smallest Element in a Sorted Matrix

## 1. 題目摘要

給定一個 `n × n` 的矩陣 `matrix`，其中：

- 每一列皆為遞增排序。
- 每一行皆為遞增排序。

請找出矩陣中第 `k` 小的元素。

例如：

```text
Input:
matrix = [
  [1, 5, 9],
  [10,11,13],
  [12,13,15]
]
k = 8

Output:
13
```

---

## 2. 解題邏輯

本題可利用 **Binary Search（二分搜尋）+ Matrix Counting** 完成。

由於矩陣的列與行皆已排序，因此可以對**數值範圍**進行二分搜尋，而不是對索引搜尋。

---

### Step 1：設定二分搜尋範圍

矩陣中的最小值為：

```cpp
left = matrix[0][0];
```

最大值為：

```cpp
right = matrix[n - 1][n - 1];
```

答案一定介於兩者之間。

---

### Step 2：計算小於等於 mid 的元素數量

每次取中間值：

```cpp
mid = left + (right - left) / 2;
```

接著統計矩陣中有多少元素：

```text
<= mid
```

利用矩陣已排序的特性：

- 從左下角開始。
- 若目前元素小於等於 `mid`，表示該列上方元素皆符合，可一次加入數量。
- 若目前元素大於 `mid`，則向上移動。

如此即可在 **O(n)** 時間完成一次計數。

---

### Step 3：調整搜尋範圍

若：

```cpp
count < k
```

表示第 `k` 小元素一定更大，因此：

```cpp
left = mid + 1;
```

否則：

```cpp
right = mid;
```

繼續搜尋較小的答案。

---

### Step 4：回傳答案

當：

```cpp
left == right
```

時，即找到第 `k` 小元素。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];

        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;

            int row = n - 1;
            int col = 0;

            while (row >= 0 && col < n) {
                if (matrix[row][col] <= mid) {
                    count += row + 1;
                    col++;
                } else {
                    row--;
                }
            }

            if (count < k)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| 時間複雜度 | **O(n log(range))** |
| 空間複雜度 | **O(1)** |

其中：

- `n` 為矩陣大小。
- `range` 為矩陣中數值範圍（最大值 − 最小值）。

每次二分搜尋需要 **O(n)** 完成計數，而二分搜尋最多進行 **log(range)** 次，因此總時間複雜度為 **O(n log(range))**。

---

## 5. 重點整理

- 不對矩陣位置進行二分，而是對**數值範圍**進行 Binary Search。
- 利用矩陣每列、每行皆已排序，可在 **O(n)** 時間統計小於等於 `mid` 的元素數量。
- 若數量不足 `k` 個，往較大的數值搜尋；否則縮小右邊界。
- 最終 `left` 即為第 `k` 小元素。
- 此方法比直接排序所有元素更有效率，符合題目最佳解法。
