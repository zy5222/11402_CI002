# LeetCode 35 - Search Insert Position

## 1. 題目摘要

給定一個**已依遞增順序排序**的整數陣列 `nums` 與一個目標值 `target`。

請找出 `target` 在陣列中的索引位置：

- 若 `target` 存在，回傳其索引。
- 若不存在，回傳它應該插入的位置，使陣列仍保持遞增排序。

要求演算法時間複雜度為 **O(log n)**。

例如：

```text
Input:
nums = [1,3,5,6]
target = 5

Output:
2
```

```text
Input:
nums = [1,3,5,6]
target = 2

Output:
1
```

```text
Input:
nums = [1,3,5,6]
target = 7

Output:
4
```

---

## 2. 解題邏輯

由於陣列已排序，因此可利用 **Binary Search（二分搜尋）** 快速找到答案。

### Step 1：設定搜尋範圍

建立左右指標：

```cpp
left = 0;
right = nums.size() - 1;
```

表示目前搜尋的區間。

---

### Step 2：取得中間位置

每次計算中間索引：

```cpp
mid = left + (right - left) / 2;
```

避免直接使用 `(left + right) / 2` 可能造成整數溢位。

---

### Step 3：比較目標值

共有三種情況：

若：

```cpp
nums[mid] == target
```

表示找到目標，直接回傳 `mid`。

若：

```cpp
nums[mid] < target
```

表示答案在右半部，因此：

```cpp
left = mid + 1;
```

若：

```cpp
nums[mid] > target
```

表示答案在左半部，因此：

```cpp
right = mid - 1;
```

---

### Step 4：回傳插入位置

當搜尋結束時：

```cpp
left > right
```

此時 `left` 即為 `target` 應插入的位置，因此直接回傳：

```cpp
return left;
```

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return left;
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| 時間複雜度 | **O(log n)** |
| 空間複雜度 | **O(1)** |

- 每次搜尋都將範圍縮小一半，因此時間複雜度為 **O(log n)**。
- 僅使用固定數個變數，因此空間複雜度為 **O(1)**。

---

## 5. 重點整理

- 陣列已排序，因此適合使用 **Binary Search（二分搜尋）**。
- 每次比較中間元素與 `target`，縮小搜尋範圍。
- 若找到目標，直接回傳索引。
- 若找不到，搜尋結束時的 `left` 即為正確插入位置。
- 此方法符合題目要求的 **O(log n)** 時間複雜度。
