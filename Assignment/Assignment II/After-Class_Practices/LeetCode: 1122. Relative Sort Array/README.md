# LeetCode 1122 - Relative Sort Array

## 1. 題目摘要

給定兩個整數陣列 `arr1` 與 `arr2`，其中：

- `arr2` 中的元素皆互不重複。
- `arr2` 的所有元素都存在於 `arr1` 中。

請依照以下規則重新排列 `arr1`：

1. `arr2` 中出現的元素，需依照 `arr2` 的順序排列。
2. 不在 `arr2` 中的元素，依照**遞增順序**排列，並放在最後。

例如：

```text
Input:
arr1 = [2,3,1,3,2,4,6,7,9,2,19]
arr2 = [2,1,4,3,9,6]

Output:
[2,2,2,1,4,3,3,9,6,7,19]
```

---

## 2. 解題邏輯

本題可利用 **計數排序（Counting Sort）** 的概念完成。

由於題目限制：

```text
0 <= arr1[i], arr2[i] <= 1000
```

因此可以建立一個大小為 `1001` 的計數陣列來統計每個數字出現的次數。

---

### Step 1：統計每個數字出現次數

建立計數陣列：

```cpp
vector<int> count(1001, 0);
```

遍歷 `arr1`：

```cpp
count[num]++;
```

記錄每個數字出現幾次。

---

### Step 2：依照 arr2 的順序放入答案

依序遍歷 `arr2`。

若某數字出現多次：

```cpp
while (count[num]--)
```

就持續加入答案：

```cpp
result.push_back(num);
```

完成後，該數字的次數會變成 0。

---

### Step 3：加入剩餘元素

最後再從

```cpp
0 ~ 1000
```

依序檢查。

若還有剩餘次數：

```cpp
while (count[i]--)
```

便加入答案。

由於是依照數字大小遍歷，因此自然就是升序排列。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> count(1001, 0);

        // 統計每個數字出現次數
        for (int num : arr1)
            count[num]++;

        vector<int> result;

        // 依照 arr2 的順序加入答案
        for (int num : arr2) {
            while (count[num] > 0) {
                result.push_back(num);
                count[num]--;
            }
        }

        // 將剩餘元素依升序加入
        for (int i = 0; i <= 1000; i++) {
            while (count[i] > 0) {
                result.push_back(i);
                count[i]--;
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
| 時間複雜度 | **O(n + k)** |
| 空間複雜度 | **O(k)** |

其中：

- `n` 為 `arr1` 的長度。
- `k = 1001`，為數值範圍大小，可視為常數。

因此整體時間複雜度為 **O(n)**，空間複雜度亦為 **O(1)**（若將 `k` 視為常數）。

---

## 5. 重點整理

- 利用 **Counting Sort（計數排序）** 統計每個數字出現次數。
- 先依照 `arr2` 的順序輸出元素。
- 再依數值大小輸出剩餘元素，自然形成遞增排序。
- 不需要比較排序，效率優於一般排序方法。
- 適合數值範圍固定且較小的題目。
