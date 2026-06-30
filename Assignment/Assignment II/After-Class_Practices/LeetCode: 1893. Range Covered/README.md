# LeetCode 1893 - Check if All the Integers in a Range Are Covered

## 1. 題目摘要

給定一個整數區間陣列 `ranges`，其中：

```cpp
ranges[i] = [starti, endi]
```

表示所有介於 `starti` 到 `endi`（包含兩端）的整數皆被覆蓋。

另外給定兩個整數：

- `left`
- `right`

請判斷區間：

```text
[left, right]
```

中的每一個整數是否都至少被 `ranges` 中的一個區間覆蓋。

若全部皆被覆蓋，回傳 `true`；否則回傳 `false`。

例如：

```text
Input:
ranges = [[1,2],[3,4],[5,6]]
left = 2
right = 5

Output:
true
```

```text
Input:
ranges = [[1,10],[10,20]]
left = 21
right = 21

Output:
false
```

---

## 2. 解題邏輯

由於題目限制：

```text
1 <= starti, endi <= 50
```

數值範圍很小，因此可利用 **Difference Array（差分陣列）** 搭配 Prefix Sum 快速判斷每個整數是否被覆蓋。

---

### Step 1：建立差分陣列

建立大小為：

```cpp
52
```

的差分陣列：

```cpp
vector<int> diff(52, 0);
```

對每個區間：

```cpp
[start, end]
```

更新：

```cpp
diff[start]++;
diff[end + 1]--;
```

例如：

```text
[2,5]

diff：

2 : +1
6 : -1
```

---

### Step 2：計算 Prefix Sum

依序累加：

```cpp
cover += diff[i];
```

此時：

```cpp
cover
```

表示目前整數被多少個區間覆蓋。

---

### Step 3：檢查指定範圍

當：

```cpp
left <= i <= right
```

若：

```cpp
cover == 0
```

表示目前整數沒有被任何區間覆蓋。

立即回傳：

```cpp
false;
```

若全部整數皆有覆蓋，最後回傳：

```cpp
true;
```

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(52, 0);

        for (auto& range : ranges) {
            diff[range[0]]++;
            diff[range[1] + 1]--;
        }

        int cover = 0;

        for (int i = 1; i <= 50; i++) {
            cover += diff[i];

            if (i >= left && i <= right && cover == 0)
                return false;
        }

        return true;
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| 時間複雜度 | **O(n + 50)** |
| 空間複雜度 | **O(50)** |

其中：

- `n` 為區間數量。
- 更新差分陣列需 **O(n)**。
- Prefix Sum 最多遍歷 `1 ~ 50`，因此為 **O(50)**。

由於 `50` 為固定常數，因此整體時間複雜度可視為 **O(n)**。

---

## 5. 重點整理

- 題目的數值範圍僅為 **1 ~ 50**，可利用固定大小陣列處理。
- 使用 **Difference Array（差分陣列）** 快速標記每個區間：
  ```cpp
  diff[start]++;
  diff[end + 1]--;
  ```
- 再利用 **Prefix Sum** 計算每個整數的覆蓋次數。
- 若區間 `[left, right]` 中任一整數的覆蓋次數為 `0`，則回傳 `false`；否則回傳 `true`。
- 此方法比逐一檢查每個區間更有效率，也是本題常見的最佳解法。
