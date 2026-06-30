# LeetCode 148 - Sort List

## 1. 題目摘要

給定一個鏈結串列（Linked List）的頭節點 `head`，請將整個串列依照**遞增順序**排序，並回傳排序後的串列。

要求：

- 時間複雜度為 **O(n log n)**。
- 盡可能使用 **O(1)** 額外空間。

例如：

```text
Input:
head = [4,2,1,3]

Output:
[1,2,3,4]
```

```text
Input:
head = [-1,5,3,4,0]

Output:
[-1,0,3,4,5]
```

---

## 2. 解題邏輯

本題最適合使用 **Merge Sort（合併排序）**。

由於鏈結串列無法像陣列一樣快速存取中間元素，因此 Merge Sort 能有效利用鏈結串列的特性，在 **O(n log n)** 時間內完成排序。

---

### Step 1：找出鏈結串列中點

使用 **快慢指標（Fast & Slow Pointer）**：

- `slow` 每次走一步
- `fast` 每次走兩步

當 `fast` 到達尾端時，`slow` 即位於中間位置。

接著將串列切成左右兩半：

```cpp
mid->next = nullptr;
```

---

### Step 2：遞迴排序左右兩半

對左右兩段分別呼叫：

```cpp
sortList(left);
sortList(right);
```

直到串列長度為 0 或 1。

---

### Step 3：合併兩個已排序串列

建立一個虛擬節點（Dummy Node）：

```cpp
ListNode dummy;
```

比較左右串列目前節點：

- 較小者接到新串列
- 指標向前移動

直到其中一個串列走完，再把剩餘節點接上即可。

---

### Step 4：回傳排序結果

Merge 完成後：

```cpp
return dummy.next;
```

即為排序完成的鏈結串列。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        // 找中點
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = nullptr;

        // 遞迴排序左右兩半
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // 合併兩個排序好的串列
        ListNode dummy;
        ListNode* tail = &dummy;

        while (left && right) {
            if (left->val < right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        tail->next = left ? left : right;

        return dummy.next;
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| 時間複雜度 | **O(n log n)** |
| 空間複雜度 | **O(log n)**（遞迴呼叫堆疊） |

- 每一層 Merge 需要遍歷整個串列一次，共有 **log n** 層，因此時間複雜度為 **O(n log n)**。
- 雖然 Merge 本身只使用常數空間，但遞迴會產生 **O(log n)** 的呼叫堆疊。

---

## 5. 重點整理

- 鏈結串列排序最適合使用 **Merge Sort**。
- 使用 **快慢指標** 找出串列中點並切割成兩半。
- 遞迴排序左右兩個子串列。
- 利用 Dummy Node 合併兩個已排序串列。
- 可在 **O(n log n)** 時間內完成排序，是本題的最佳解法。
