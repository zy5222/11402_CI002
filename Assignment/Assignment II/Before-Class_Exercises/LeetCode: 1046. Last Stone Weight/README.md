# LeetCode 1046 - Last Stone Weight

## 1. 題目摘要

給定一個整數陣列 `stones`，其中每個元素代表一顆石頭的重量。

每回合需取出**最重的兩顆石頭**進行碰撞：

- 若兩顆石頭重量相同，則兩者都會被粉碎。
- 若重量不同，則較重的石頭會剩下兩者重量差的新重量。

重複上述操作，直到剩下 **0** 或 **1** 顆石頭。

請回傳最後剩下石頭的重量；若沒有石頭，則回傳 `0`。

例如：

```text
Input:
stones = [2,7,4,1,8,1]

Output:
1
```

Explanation：

```text
8 和 7 → 剩 1

stones = [2,4,1,1,1]

4 和 2 → 剩 2

stones = [2,1,1,1]

2 和 1 → 剩 1

stones = [1,1,1]

1 和 1 → 消失

stones = [1]

答案 = 1
```

---

## 2. 解題邏輯

本題適合使用 **Max Heap（最大堆積）**。

因為每回合都需要快速取得目前最重的兩顆石頭，而 Max Heap 可以在 **O(log n)** 時間完成插入與刪除操作。

---

### Step 1：建立 Max Heap

使用 C++ 的 Priority Queue：

```cpp
priority_queue<int> maxHeap;
```

將所有石頭重量加入 Heap：

```cpp
for (int stone : stones)
    maxHeap.push(stone);
```

Heap 頂端即為目前最重的石頭。

---

### Step 2：取出最重的兩顆石頭

當 Heap 中至少有兩顆石頭時：

```cpp
int first = maxHeap.top();
maxHeap.pop();

int second = maxHeap.top();
maxHeap.pop();
```

取得目前最重的兩顆石頭。

---

### Step 3：碰撞後放回

若兩顆重量不同：

```cpp
first != second
```

則將重量差重新放回 Heap：

```cpp
maxHeap.push(first - second);
```

若重量相同，兩顆石頭皆消失，不需放回。

---

### Step 4：回傳答案

當 Heap 中剩下：

- 一顆石頭：

```cpp
return maxHeap.top();
```

- 沒有石頭：

```cpp
return 0;
```

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for (int stone : stones)
            maxHeap.push(stone);

        while (maxHeap.size() > 1) {
            int first = maxHeap.top();
            maxHeap.pop();

            int second = maxHeap.top();
            maxHeap.pop();

            if (first != second)
                maxHeap.push(first - second);
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
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

- `n` 為石頭數量。
- 建立 Max Heap 需 **O(n)**。
- 每次碰撞涉及兩次刪除與最多一次插入，每次操作皆為 **O(log n)**。
- 最多進行 `n - 1` 次碰撞，因此總時間複雜度為 **O(n log n)**。

---

## 5. 重點整理

- 使用 **Max Heap（最大堆積）** 快速取得目前最重的兩顆石頭。
- 每回合取出兩顆最重石頭進行碰撞。
- 若重量不同，將重量差重新放回 Heap。
- 若重量相同，兩顆石頭直接移除。
- 重複直到 Heap 中剩下 0 或 1 顆石頭。
- 此方法是本題最經典且效率最佳的解法，時間複雜度為 **O(n log n)**。
