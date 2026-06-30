# LeetCode 1845 - Seat Reservation Manager

## 1. 題目摘要

設計一個 `SeatManager` 類別，用來管理座位預約。

共有 `n` 個座位，座位編號為：

```text
1 ~ n
```

需實作以下操作：

- `SeatManager(int n)`：初始化座位管理系統。
- `reserve()`：預約目前**編號最小**的未被預約座位，並回傳座位編號。
- `unreserve(int seatNumber)`：取消指定座位的預約，使其重新可被預約。

例如：

```text
Input:
["SeatManager","reserve","reserve","unreserve","reserve","reserve"]

[[5],[],[],[2],[],[]]

Output:
[null,1,2,null,2,3]
```

Explanation：

```text
初始可預約座位：

1 2 3 4 5

reserve() → 1

剩下：

2 3 4 5

reserve() → 2

取消座位 2

可預約：

2 3 4 5

reserve() → 2

reserve() → 3
```

---

## 2. 解題邏輯

本題適合使用 **Min Heap（最小堆積）**。

因為每次都需要快速取得**目前編號最小的可預約座位**，而 Min Heap 可在 **O(log n)** 時間完成插入與刪除。

---

### Step 1：初始化 Min Heap

建立：

```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
```

初始化時，將所有座位編號加入 Heap：

```cpp
for (int i = 1; i <= n; i++)
    minHeap.push(i);
```

Heap 頂端即為目前最小的可預約座位。

---

### Step 2：預約座位

呼叫：

```cpp
reserve()
```

時：

取出 Heap 頂端：

```cpp
int seat = minHeap.top();
minHeap.pop();
```

並回傳：

```cpp
seat;
```

---

### Step 3：取消預約

若取消座位：

```cpp
seatNumber
```

直接重新加入 Heap：

```cpp
minHeap.push(seatNumber);
```

即可讓該座位重新成為可預約狀態。

---

## 3. 程式碼實作

```cpp
class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            minHeap.push(i);
        }
    }

    int reserve() {
        int seat = minHeap.top();
        minHeap.pop();
        return seat;
    }

    void unreserve(int seatNumber) {
        minHeap.push(seatNumber);
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| 初始化 | **O(n)** |
| `reserve()` | **O(log n)** |
| `unreserve()` | **O(log n)** |
| 空間複雜度 | **O(n)** |

其中：

- `n` 為座位總數。
- 初始化將所有座位加入 Min Heap，時間複雜度為 **O(n)**。
- `reserve()` 與 `unreserve()` 都涉及 Heap 的插入或刪除操作，因此時間複雜度皆為 **O(log n)**。
- Heap 最多儲存 `n` 個座位，因此空間複雜度為 **O(n)**。

---

## 5. 重點整理

- 使用 **Min Heap（最小堆積）** 管理所有可預約的座位。
- Heap 頂端始終為目前**編號最小**的可預約座位。
- `reserve()` 取出 Heap 頂端並回傳座位編號。
- `unreserve()` 將取消預約的座位重新放回 Heap。
- 此方法可有效維持座位編號順序，是本題最經典且效率最佳的解法，`reserve()` 與 `unreserve()` 的時間複雜度皆為 **O(log n)**。
