# LeetCode 228 - Summary Ranges

## 1. 題目摘要

給定一個**已排序且不重複**的整數陣列 `nums`，請將其中連續的數字合併為區間，並回傳所有區間的字串表示。

規則如下：

- 若區間只有一個數字，直接輸出該數字。
- 若區間包含多個連續數字，輸出：
  ```text
  start->end
  ```

例如：

```text
Input:
nums = [0,1,2,4,5,7]

Output:
["0->2","4->5","7"]
```

```text
Input:
nums = [0,2,3,4,6,8,9]

Output:
["0","2->4","6","8->9"]
```

---

## 2. 解題邏輯

本題使用 **Two Pointers（雙指標）**。

利用兩個指標記錄每段連續區間的起點與終點，依序掃描整個陣列。

---

### Step 1：記錄區間起點

從目前位置開始：

```cpp
start = nums[i];
```

代表一段新的區間起點。

---

### Step 2：尋找連續區間

只要下一個數字為：

```cpp
nums[i + 1] == nums[i] + 1
```

表示仍屬於同一個連續區間。

持續往後移動：

```cpp
i++;
```

直到遇到不連續的數字或陣列結尾。

---

### Step 3：加入答案

此時：

```cpp
end = nums[i];
```

若：

```cpp
start == end
```

表示區間只有一個元素：

```cpp
result.push_back(to_string(start));
```

否則加入：

```cpp
to_string(start) + "->" + to_string(end)
```

---

### Step 4：繼續下一段

外層迴圈會繼續從下一個尚未處理的元素開始，直到掃描完整個陣列。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int start = nums[i];

            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
            }

            int end = nums[i];

            if (start == end)
                result.push_back(to_string(start));
            else
                result.push_back(to_string(start) + "->" + to_string(end));
        }

        return result;
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| 時間複雜度 | **O(n)** |
| 空間複雜度 | **O(1)**（不計輸出結果） |

其中：

- `n` 為陣列長度。

每個元素最多被走訪一次，因此時間複雜度為 **O(n)**。

除了儲存答案外，只使用固定數量的變數，因此額外空間複雜度為 **O(1)**。

---

## 5. 重點整理

- 使用 **Two Pointers（雙指標）** 掃描連續區間。
- 每次記錄一段區間的起點，持續向後尋找連續數字。
- 若區間只有一個元素，直接輸出該數字；否則輸出 `"start->end"`。
- 每個元素只會被掃描一次，因此時間複雜度為 **O(n)**。
- 此方法是本題最簡潔且效率最佳的解法。
