# LeetCode 703 - Kth Largest Element in a Stream

## 1. 題目摘要

設計一個 `KthLargest` 類別，用來維護資料流（Stream）中的第 `k` 大元素。

需實作：

- `KthLargest(int k, vector<int>& nums)`：初始化物件。
- `add(int val)`：將新元素加入資料流，並回傳目前資料流中的第 `k` 大元素。

例如：

```text
Input:
["KthLargest","add","add","add","add","add"]

[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]

Output:
[null,4,5,5,8,8]
```

Explanation：

```text
初始資料流：4,5,8,2

加入 3 → 第 3 大 = 4
加入 5 → 第 3 大 = 5
加入 10 → 第 3 大 = 5
加入 9 → 第 3 大 = 8
加入 4 → 第 3 大 = 8
```

---

## 2. 解題邏輯

本題可利用 **Min Heap（最小堆積）** 維護目前最大的 `k` 個元素。

Heap 的大小始終保持為 `k`：

- Heap 中存放目前最大的 `k` 個元素。
- Heap 頂端（Top）就是第 `k` 大元素。

---

### Step 1：建立 Min Heap

使用 C++ 的 Priority Queue：

```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
```

其中：

```cpp
greater<int>
```

代表建立最小堆積。

---

### Step 2：初始化資料

將 `nums` 中所有元素依序加入 Heap。

每加入一個元素後：

```cpp
minHeap.push(num);
```

若 Heap 大小超過 `k`：

```cpp
minHeap.pop();
```

移除最小元素。

如此即可保留目前最大的 `k` 個元素。

---

### Step 3：加入新元素

呼叫：

```cpp
add(val)
```

時：

先加入：

```cpp
minHeap.push(val);
```

若 Heap 超過 `k`：

```cpp
minHeap.pop();
```

即可維持 Heap 大小固定。

---

### Step 4：回傳第 k 大元素

由於 Heap 中共有 `k` 個最大元素：

Heap 最小值就是：

```cpp
minHeap.top();
```

也就是目前資料流中的第 `k` 大元素。

---

## 3. 程式碼實作

```cpp
class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int num : nums) {
            minHeap.push(num);

            if (minHeap.size() > k)
                minHeap.pop();
        }
    }

    int add(int val) {
        minHeap.push(val);

        if (minHeap.size() > k)
            minHeap.pop();

        return minHeap.top();
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| 初始化 | **O(n log k)** |
| `add()` | **O(log k)** |
| 空間複雜度 | **O(k)** |

其中：

- `n` 為初始陣列長度。
- Heap 大小始終維持在 `k`。

每次插入或刪除 Heap 的成本皆為 **O(log k)**，因此 `add()` 的時間複雜度為 **O(log k)**。

---

## 5. 重點整理

- 使用 **Min Heap（最小堆積）** 維護目前最大的 `k` 個元素。
- Heap 大小固定為 `k`，超過時移除最小值。
- Heap 頂端即為目前的第 `k` 大元素。
- `add()` 每次僅需一次插入與可能的一次刪除，因此時間複雜度為 **O(log k)**。
- 此方法不需每次重新排序，是本題最常見且效率最佳的解法。
