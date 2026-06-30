# LeetCode 435 - Non-overlapping Intervals

## 1. 題目摘要

給定一組區間 `intervals`，其中：

```cpp
intervals[i] = [starti, endi]
```

請移除最少數量的區間，使得剩下的所有區間彼此**沒有重疊（Non-overlapping）**。

回傳需要移除的最少區間數。

例如：

```text
Input:
intervals = [[1,2],[2,3],[3,4],[1,3]]

Output:
1
```

Explanation：

移除 `[1,3]` 後，其餘區間互不重疊。

```text
Input:
intervals = [[1,2],[1,2],[1,2]]

Output:
2
```

---

## 2. 解題邏輯

本題使用 **Greedy（貪心法）**。

核心想法是：

> **優先保留結束時間較早的區間**，因為它能為後續區間留下最大的可用空間，降低重疊的機率。

---

### Step 1：依結束時間排序

先依照每個區間的結束時間由小到大排序：

```cpp
sort(intervals.begin(), intervals.end(),
     [](vector<int>& a, vector<int>& b) {
         return a[1] < b[1];
     });
```

若結束時間相同，排序順序不影響結果。

---

### Step 2：保留第一個區間

排序後，先保留第一個區間，並記錄其結束位置：

```cpp
end = intervals[0][1];
```

---

### Step 3：逐一檢查後續區間

依序遍歷其餘區間。

若目前區間的起點：

```cpp
intervals[i][0] >= end
```

表示沒有重疊，可保留此區間，並更新：

```cpp
end = intervals[i][1];
```

若：

```cpp
intervals[i][0] < end
```

表示發生重疊。

此時移除目前區間即可：

```cpp
count++;
```

由於目前區間的結束時間一定不早於已保留區間，因此保留原本區間才是最佳選擇。

---

### Step 4：回傳移除數量

最後：

```cpp
count
```

即為最少需移除的區間數。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return 0;

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        int count = 0;
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= end) {
                end = intervals[i][1];
            } else {
                count++;
            }
        }

        return count;
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| 時間複雜度 | **O(n log n)** |
| 空間複雜度 | **O(1)**（不計排序所需空間） |

其中：

- `n` 為區間數量。
- 排序需 **O(n log n)**。
- 排序後只需遍歷一次區間，因此為 **O(n)**。
- 整體時間複雜度由排序主導，因此為 **O(n log n)**。

---

## 5. 重點整理

- 使用 **Greedy（貪心法）** 解決區間重疊問題。
- 先依區間的**結束時間**由小到大排序。
- 優先保留結束時間較早的區間，可為後續區間保留更多空間。
- 若目前區間與已保留區間重疊，則移除目前區間並增加計數。
- 最終累計的移除次數，即為最少需刪除的區間數。
- 此方法是本題最經典且效率最佳的解法，時間複雜度為 **O(n log n)**。
