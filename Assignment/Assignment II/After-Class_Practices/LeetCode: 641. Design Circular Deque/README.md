# LeetCode 641 - Design Circular Deque

## 1. 題目摘要

設計一個**循環雙端佇列（Circular Deque）**，並實作以下操作：

- `MyCircularDeque(k)`：建立容量為 `k` 的循環雙端佇列。
- `insertFront(value)`：在前端加入元素，成功回傳 `true`，失敗回傳 `false`。
- `insertLast(value)`：在尾端加入元素，成功回傳 `true`，失敗回傳 `false`。
- `deleteFront()`：刪除前端元素，成功回傳 `true`，失敗回傳 `false`。
- `deleteLast()`：刪除尾端元素，成功回傳 `true`，失敗回傳 `false`。
- `getFront()`：回傳前端元素，若為空則回傳 `-1`。
- `getRear()`：回傳尾端元素，若為空則回傳 `-1`。
- `isEmpty()`：判斷雙端佇列是否為空。
- `isFull()`：判斷雙端佇列是否已滿。

循環雙端佇列允許從**前端與尾端**皆可進行插入與刪除操作。

例如：

```text
Input:
["MyCircularDeque","insertLast","insertLast","insertFront",
 "insertFront","getRear","isFull","deleteLast",
 "insertFront","getFront"]

[[3],[1],[2],[3],[4],[],[],[],[4],[]]

Output:
[null,true,true,true,false,2,true,true,true,4]
```

---

## 2. 解題邏輯

本題可利用 **固定大小陣列 + 頭尾指標** 實作循環雙端佇列。

---

### Step 1：建立陣列與變數

建立固定大小陣列：

```cpp
vector<int> deque(k);
```

並維護：

- `front`：目前前端位置。
- `rear`：下一個尾端插入位置。
- `count`：目前元素數量。
- `capacity`：最大容量。

初始：

```cpp
front = 0;
rear = 0;
count = 0;
```

---

### Step 2：前端插入

插入前需先將 `front` 往前移動：

```cpp
front = (front - 1 + capacity) % capacity;
```

接著：

```cpp
deque[front] = value;
count++;
```

---

### Step 3：尾端插入

將元素放入：

```cpp
deque[rear] = value;
```

再更新：

```cpp
rear = (rear + 1) % capacity;
count++;
```

---

### Step 4：前端刪除

直接將：

```cpp
front = (front + 1) % capacity;
count--;
```

即可完成刪除。

---

### Step 5：尾端刪除

先將：

```cpp
rear = (rear - 1 + capacity) % capacity;
```

再：

```cpp
count--;
```

即可移除尾端元素。

---

### Step 6：取得前端與尾端元素

前端：

```cpp
deque[front]
```

尾端：

```cpp
deque[(rear - 1 + capacity) % capacity]
```

利用取餘數避免索引超出範圍。

---

## 3. 程式碼實作

```cpp
class MyCircularDeque {
private:
    vector<int> deque;
    int front;
    int rear;
    int count;
    int capacity;

public:
    MyCircularDeque(int k) {
        deque.resize(k);
        capacity = k;
        front = 0;
        rear = 0;
        count = 0;
    }

    bool insertFront(int value) {
        if (isFull())
            return false;

        front = (front - 1 + capacity) % capacity;
        deque[front] = value;
        count++;

        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;

        deque[rear] = value;
        rear = (rear + 1) % capacity;
        count++;

        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;

        front = (front + 1) % capacity;
        count--;

        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;

        rear = (rear - 1 + capacity) % capacity;
        count--;

        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;

        return deque[front];
    }

    int getRear() {
        if (isEmpty())
            return -1;

        return deque[(rear - 1 + capacity) % capacity];
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
| `insertFront()` | **O(1)** |
| `insertLast()` | **O(1)** |
| `deleteFront()` | **O(1)** |
| `deleteLast()` | **O(1)** |
| `getFront()` | **O(1)** |
| `getRear()` | **O(1)** |
| `isEmpty()` | **O(1)** |
| `isFull()` | **O(1)** |
| 空間複雜度 | **O(k)** |

其中：

- `k` 為雙端佇列容量。
- 所有操作皆只需固定次數運算，因此時間複雜度皆為 **O(1)**。
- 使用固定大小陣列儲存元素，因此空間複雜度為 **O(k)**。

---

## 5. 重點整理

- 使用固定大小陣列搭配 `front`、`rear` 指標實作循環雙端佇列。
- 利用 `% capacity` 實現索引循環，不需搬移元素。
- 使用 `count` 判斷是否為空或已滿，避免 `front == rear` 的判斷歧義。
- 支援前端與尾端的插入、刪除操作，所有操作皆可在 **O(1)** 時間完成。
- 此方法是實作 Circular Deque 最常見且效率最高的方式。
