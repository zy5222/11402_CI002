# LeetCode 56 - Merge Intervals

## 1. 題目摘要

給定一組區間 `intervals`，其中：

```cpp
intervals[i] = [starti, endi]
```

請將所有**重疊的區間**合併，並回傳合併後的所有區間。

例如：

```text
Input:
intervals = [[1,3],[2,6],[8,10],[15,18]]

Output:
[[1,6],[8,10],[15,18]]
```

Explanation：

```text
[1,3] 與 [2,6] 重疊

合併為

[1,6]
```

```text
Input:
intervals = [[1,4],[4,5]]

Output:
[[1,5]]
```

因為兩區間相連（4 為共同端點），因此也需合併。

---

## 2. 解題邏輯

本題使用 **Sorting + Greedy（排序 + 貪心法）**。

先依照區間起點排序，再依序檢查是否與前一個區間重疊。

---

### Step 1：依起點排序

先依區間起點由小到大排序：

```cpp
sort(intervals.begin(), intervals.end());
```

排序後即可依序處理所有區間。

---

### Step 2：加入第一個區間

先將第一個區間放入答案：

```cpp
result.push_back(intervals[0]);
```

後續皆與答案中的最後一個區間比較。

---

### Step 3：判斷是否重疊

設：

```cpp
last = result.back();
```

若：

```cpp
intervals[i][0] <= last[1]
```

表示兩區間重疊。

更新終點為：

```cpp
last[1] = max(last[1], intervals[i][1]);
```

即可完成合併。

---

### Step 4：沒有重疊

若：

```cpp
intervals[i][0] > last[1]
```

表示為新的區間。

直接加入答案：

```cpp
result.push_back(intervals[i]);
```

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][0] <= result.back()[1]) {

                result.back()[1] =
                    max(result.back()[1], intervals[i][1]);

            } else {

                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| 時間複雜度 | **O(n log n)** |
| 空間複雜度 | **O(n)** |

其中：

- `n` 為區間數量。
- 排序需 **O(n log n)**。
- 排序後只需遍歷一次區間，因此為 **O(n)**。
- 整體時間複雜度由排序主導，因此為 **O(n log n)**。
- 合併後的結果最多可能包含所有區間，因此空間複雜度為 **O(n)**。

---

## 5. 重點整理

- 使用 **Sorting + Greedy（排序 + 貪心法）** 解決區間合併問題。
- 先依區間起點由小到大排序。
- 若目前區間與上一個區間重疊：
  ```cpp
  intervals[i][0] <= result.back()[1]
  ```
  則更新合併後區間的終點：
  ```cpp
  result.back()[1] = max(result.back()[1], intervals[i][1]);
  ```
- 若沒有重疊，直接加入新的區間。
- 此方法是本題最經典且效率最佳的解法，時間複雜度為 **O(n log n)**。
