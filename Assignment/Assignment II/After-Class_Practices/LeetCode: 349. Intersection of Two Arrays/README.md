# LeetCode 349 - Intersection of Two Arrays

## 1. 題目摘要

給定兩個整數陣列 `nums1` 與 `nums2`，請找出它們的**交集（Intersection）**。

回傳的結果需符合以下條件：

- 每個元素只能出現 **一次**。
- 元素順序不限。

例如：

```text
Input:
nums1 = [1,2,2,1]
nums2 = [2,2]

Output:
[2]
```

```text
Input:
nums1 = [4,9,5]
nums2 = [9,4,9,8,4]

Output:
[4,9]
```

---

## 2. 解題邏輯

本題可利用 **Hash Set（雜湊集合）** 快速判斷元素是否存在，同時避免重複加入答案。

### Step 1：建立第一個集合

先將 `nums1` 所有元素放入 `unordered_set`：

```cpp
unordered_set<int> set1(nums1.begin(), nums1.end());
```

集合會自動去除重複元素。

---

### Step 2：遍歷第二個陣列

依序檢查 `nums2` 中的每個元素。

若元素存在於 `set1`：

```cpp
if (set1.count(num))
```

表示兩個陣列都有此數字。

---

### Step 3：加入答案並避免重複

將共同元素加入答案：

```cpp
result.push_back(num);
```

接著立即從集合中移除：

```cpp
set1.erase(num);
```

如此即使 `nums2` 中再次出現相同元素，也不會重複加入答案。

---

### Step 4：回傳答案

遍歷完成後，`result` 即為兩個陣列的交集。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        vector<int> result;

        for (int num : nums2) {
            if (set1.count(num)) {
                result.push_back(num);
                set1.erase(num);
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
| 時間複雜度 | **O(n + m)** |
| 空間複雜度 | **O(n)** |

其中：

- `n` 為 `nums1` 的長度。
- `m` 為 `nums2` 的長度。

建立集合需 **O(n)**，遍歷第二個陣列需 **O(m)**，因此總時間複雜度為 **O(n + m)**。

---

## 5. 重點整理

- 使用 **Hash Set（`unordered_set`）** 快速判斷元素是否存在。
- 建立集合時即可自動去除 `nums1` 中的重複元素。
- 找到共同元素後立即 `erase()`，避免重複加入答案。
- 不需排序即可完成，平均時間複雜度為 **O(n + m)**。
- 此方法簡潔且符合題目要求，每個交集元素只會出現一次。
