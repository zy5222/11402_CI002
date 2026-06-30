# LeetCode 232 - Implement Queue using Stacks

## 1. 題目摘要

請使用**兩個 Stack（堆疊）**實作一個 Queue（佇列），並支援以下操作：

- `push(x)`：將元素加入佇列尾端。
- `pop()`：移除並回傳佇列前端元素。
- `peek()`：回傳佇列前端元素，但不移除。
- `empty()`：判斷佇列是否為空。

Queue 必須遵循 **FIFO（First In, First Out）** 原則，而 Stack 則是 **LIFO（Last In, First Out）**，因此需要利用兩個 Stack 模擬 Queue 的行為。

例如：

```text
Input:
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]

Output:
[null, null, null, 1, 1, false]
```

---

## 2. 解題邏輯

本題利用 **兩個 Stack**：

- `inStack`：負責新增元素。
- `outStack`：負責刪除與查看前端元素。

---

### Step 1：加入元素（push）

新元素直接放入 `inStack`：

```cpp
inStack.push(x);
```

時間複雜度為 **O(1)**。

---

### Step 2：搬移元素

當需要執行：

- `pop()`
- `peek()`

若 `outStack` 為空，就將 `inStack` 中所有元素依序移到 `outStack`：

```cpp
while (!inStack.empty()) {
    outStack.push(inStack.top());
    inStack.pop();
}
```

經過轉移後，最早加入的元素便會位於 `outStack` 的頂端，符合 Queue 的 FIFO 特性。

若 `outStack` 不為空，則不需再次搬移。

---

### Step 3：移除或查看前端元素

搬移完成後：

- `pop()`：回傳並移除 `outStack.top()`
- `peek()`：直接回傳 `outStack.top()`

---

### Step 4：判斷是否為空

當兩個 Stack 都沒有元素時：

```cpp
return inStack.empty() && outStack.empty();
```

表示 Queue 為空。

---

## 3. 程式碼實作

```cpp
class MyQueue {
private:
    stack<int> inStack;
    stack<int> outStack;

    void move() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        move();
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    int peek() {
        move();
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| `push()` | **O(1)** |
| `pop()` | **O(1)**（平均） |
| `peek()` | **O(1)**（平均） |
| `empty()` | **O(1)** |
| 空間複雜度 | **O(n)** |

- 每個元素最多只會從 `inStack` 搬移到 `outStack` 一次，因此 `pop()` 和 `peek()` 的**平均時間複雜度（Amortized Time Complexity）**為 **O(1)**。
- 最多需要儲存所有元素於兩個 Stack 中，因此空間複雜度為 **O(n)**。

---

## 5. 重點整理

- 使用兩個 Stack 模擬 Queue：
  - `inStack`：負責加入元素。
  - `outStack`：負責移除與查看元素。
- 只有當 `outStack` 為空時，才將 `inStack` 的元素全部搬移過去。
- 每個元素最多搬移一次，因此 `pop()` 與 `peek()` 的平均時間複雜度為 **O(1)**。
- 此方法符合 Queue 的 **FIFO** 行為，也是本題最常見且最佳的解法。
