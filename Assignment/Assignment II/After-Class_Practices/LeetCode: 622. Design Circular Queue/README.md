# LeetCode 622 - Design Circular Queue

## 1. 題目摘要

設計一個**循環佇列（Circular Queue）**，並實作以下操作：

- `MyCircularQueue(k)`：建立容量為 `k` 的循環佇列。
- `enQueue(value)`：將元素加入佇列尾端，成功回傳 `true`，失敗回傳 `false`。
- `deQueue()`：刪除佇列前端元素，成功回傳 `true`，失敗回傳 `false`。
- `Front()`：回傳佇列前端元素，若為空則回傳 `-1`。
- `Rear()`：回傳佇列尾端元素，若為空則回傳 `-1`。
- `isEmpty()`：判斷佇列是否為空。
- `isFull()`：判斷佇列是否已滿。

循環佇列的特色是：當尾端到達陣列末端時，可回到陣列開頭繼續使用未被占用的空間。

例如：

```text
Input:
["MyCircularQueue","enQueue","enQueue","enQueue","enQueue",
 "Rear","isFull","deQueue","enQueue","Rear"]

[[3],[1],[2],[3],[4],[],[],[],[4],[]]

Output:
[null,true,true,true,false,3,true,true,true,4]
```

---

## 2. 解題邏輯

本題可利用 **固定大小陣列 + 頭尾指標** 來模擬循環佇列。

---

### Step 1：建立陣列與變數

建立：

```cpp
vector<int> queue(k);
```

並維護三個變數：

- `front`：前端索引。
- `rear`：尾端索引。
- `count`：目前元素數量。

初始：

```cpp
front = 0;
rear = 0;
count = 0;
```

---

### Step 2：加入元素（enQueue）

若佇列已滿：

```cpp
count == capacity
```

則加入失敗。

否則：

```cpp
queue[rear] = value;
rear = (rear + 1) % capacity;
count++;
```

利用 `% capacity`，當 `rear` 到達陣列尾端時即可回到開頭。

---

### Step 3：刪除元素（deQueue）

若佇列為空：

```cpp
count == 0
```

則刪除失敗。

否則：

```cpp
front = (front + 1) % capacity;
count--;
```

同樣利用取餘數實現循環。

---

### Step 4：取得前端與尾端元素

前端元素：

```cpp
queue[front]
```

尾端元素則位於：

```cpp
(rear - 1 + capacity) % capacity
```

需加上 `capacity` 避免索引為負數。

---

### Step 5：判斷是否為空或已滿

- 空佇列：

```cpp
count == 0
```

- 滿佇列：

```cpp
count == capacity
```

---

## 3. 程式碼實作

```cpp
class MyCircularQueue {
private:
    vector<int> queue;
    int front;
    int rear;
    int count;
    int capacity;

public:
    MyCircularQueue(int k) {
        queue.resize(k);
        capacity = k;
        front = 0;
        rear = 0;
        count = 0;
    }

    bool enQueue(int value) {
        if (isFull())
            return false;

        queue[rear] = value;
        rear = (rear + 1) % capacity;
        count++;

        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;

        front = (front + 1) % capacity;
        count--;

        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;

        return queue[front];
    }

    int Rear() {
        if (isEmpty())
            return -1;

        return queue[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| `enQueue()` | **O(1)** |
| `deQueue()` | **O(1)** |
| `Front()` | **O(1)** |
| `Rear()` | **O(1)** |
| `isEmpty()` | **O(1)** |
| `isFull()` | **O(1)** |
| 空間複雜度 | **O(k)** |

其中：

- `k` 為循環佇列容量。
- 所有操作皆只需固定次數的運算，因此時間複雜度皆為 **O(1)**。
- 使用固定大小陣列儲存元素，因此空間複雜度為 **O(k)**。

---

## 5. 重點整理

- 使用固定大小陣列搭配 `front`、`rear` 指標實作循環佇列。
- 利用 `% capacity` 實現索引循環，不需搬移元素。
- 使用 `count` 判斷佇列是否為空或已滿，避免 `front == rear` 的判斷歧義。
- 所有操作皆可在 **O(1)** 時間完成。
- 此方法是實作循環佇列最常見且效率最高的方式。
