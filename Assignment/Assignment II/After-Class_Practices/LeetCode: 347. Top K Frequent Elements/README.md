# LeetCode 347 - Top K Frequent Elements

## 1. 題目摘要

給定一個整數陣列 `nums` 與一個整數 `k`，請找出出現頻率最高的 `k` 個元素，並回傳其結果。

題目保證答案唯一，且可依任意順序回傳。

例如：

```text
Input:
nums = [1,1,1,2,2,3]
k = 2

Output:
[1,2]
```

```text
Input:
nums = [1]
k = 1

Output:
[1]
```

---

## 2. 解題邏輯

本題可利用 **Hash Map + Min Heap** 解決。

首先使用 **Hash Map（雜湊表）** 統計每個元素出現的次數，再利用 **Min Heap（最小堆積）** 維護目前出現頻率最高的 `k` 個元素。

---

### Step 1：統計每個元素的出現次數

建立：

```cpp
unordered_map<int, int> freq;
```

遍歷陣列：

```cpp
freq[num]++;
```

即可得到每個元素對應的出現頻率。

例如：

```text
nums = [1,1,1,2,2,3]

freq：

1 → 3
2 → 2
3 → 1
```

---

### Step 2：建立 Min Heap

Heap 中儲存：

```cpp
{frequency, number}
```

因此建立：

```cpp
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> minHeap;
```

Heap 會依照頻率由小到大排序。

---

### Step 3：維持 Heap 大小為 k

遍歷 Hash Map：

```cpp
minHeap.push({count, num});
```

若 Heap 大小超過：

```cpp
k
```

則移除最小頻率：

```cpp
minHeap.pop();
```

最後 Heap 中即保留頻率最高的 `k` 個元素。

---

### Step 4：取出答案

Heap 中剩餘元素即為答案。

依序取出：

```cpp
result.push_back(minHeap.top().second);
minHeap.pop();
```

即可得到 Top K Frequent Elements。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // 統計每個元素出現次數
        for (int num : nums)
            freq[num]++;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > minHeap;

        // 維持 Heap 大小為 k
        for (auto& p : freq) {
            minHeap.push({p.second, p.first});

            if (minHeap.size() > k)
                minHeap.pop();
        }

        vector<int> result;

        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| 時間複雜度 | **O(n log k)** |
| 空間複雜度 | **O(n)** |

其中：

- `n` 為陣列長度。
- Hash Map 最多儲存 `n` 個不同元素。
- Heap 大小固定為 `k`。

統計頻率需 **O(n)**，Heap 插入每次為 **O(log k)**，因此總時間複雜度為 **O(n log k)**。

---

## 5. 重點整理

- 使用 **Hash Map** 統計每個元素出現的頻率。
- 使用 **Min Heap** 維護目前頻率最高的 `k` 個元素。
- Heap 大小固定為 `k`，超過時移除最小頻率元素。
- 最後 Heap 中剩餘的元素即為答案。
- 此方法比直接排序所有元素更有效率，時間複雜度為 **O(n log k)**。
