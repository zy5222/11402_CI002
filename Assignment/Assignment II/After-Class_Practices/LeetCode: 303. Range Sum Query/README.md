# LeetCode 303 - Range Sum Query - Immutable

## 1. 題目摘要

設計一個 `NumArray` 類別，支援多次查詢指定區間的元素總和。

需實作：

- `NumArray(vector<int>& nums)`：初始化陣列。
- `sumRange(left, right)`：回傳索引 `left` 到 `right`（包含兩端）的元素總和。

例如：

```text
Input:
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2,0,3,-5,2,-1]], [0,2], [2,5], [0,5]]

Output:
[null, 1, -1, -3]
```

---

## 2. 解題邏輯

本題適合使用 **Prefix Sum（前綴和）**。

由於陣列內容不會修改，因此可以先預先計算累積和，之後每次查詢都能在 **O(1)** 時間完成。

---

### Step 1：建立 Prefix Sum 陣列

建立大小為 `n + 1` 的陣列：

```cpp
prefix[0] = 0;
```

接著依序累加：

```cpp
prefix[i + 1] = prefix[i] + nums[i];
```

例如：

```text
nums:
[-2, 0, 3, -5, 2, -1]

prefix:
[0, -2, -2, 1, -4, -2, -3]
```

其中：

```text
prefix[i]
```

表示前 `i` 個元素的總和。

---

### Step 2：查詢區間總和

若要求：

```text
[left ... right]
```

則區間總和為：

```cpp
prefix[right + 1] - prefix[left]
```

例如：

```text
left = 2
right = 5

= prefix[6] - prefix[2]
= -3 - (-2)
= -1
```

因此每次查詢都只需一次減法即可完成。

---

## 3. 程式碼實作

```cpp
class NumArray {
private:
    vector<int> prefix;

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n + 1);

        prefix[0] = 0;

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| 建構時間 | **O(n)** |
| 查詢時間 | **O(1)** |
| 空間複雜度 | **O(n)** |

- 初始化時需建立 Prefix Sum，因此時間為 **O(n)**。
- 每次查詢只需一次減法，因此時間複雜度為 **O(1)**。
- Prefix Sum 陣列需額外儲存 `n + 1` 個元素，因此空間複雜度為 **O(n)**。

---

## 5. 重點整理

- 使用 **Prefix Sum（前綴和）** 預先計算累積總和。
- 建立大小為 `n + 1` 的 Prefix Sum 陣列，可簡化區間計算。
- 區間 `[left, right]` 的總和可利用：
  ```cpp
  prefix[right + 1] - prefix[left]
  ```
- 初始化需 **O(n)**，之後每次查詢皆可在 **O(1)** 時間完成。
- 此方法非常適合「大量查詢、資料不會修改」的情境。
