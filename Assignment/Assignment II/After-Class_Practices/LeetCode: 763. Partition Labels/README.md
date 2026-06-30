# LeetCode 763 - Partition Labels

## 1. 題目摘要

給定一個字串 `s`，請將它切割成盡可能多的區段，使得：

> 每個字元最多只會出現在其中一個區段中。

回傳每個區段的長度。

例如：

```text
Input:
s = "ababcbacadefegdehijhklij"

Output:
[9,7,8]
```

Explanation：

可切割為：

```text
"ababcbaca"
"defegde"
"hijhklij"
```

每個字元皆只出現在其中一個區段內。

---

## 2. 解題邏輯

本題使用 **Greedy（貪心法）**。

核心想法是：

> 一個區段必須包含其中所有字元的最後一次出現位置。

---

### Step 1：記錄每個字元最後出現的位置

先遍歷一次字串，利用陣列記錄每個字元最後出現的位置：

```cpp
last[s[i] - 'a'] = i;
```

例如：

```text
s = "ababcbaca"

a 最後出現：8
b 最後出現：5
c 最後出現：7
```

---

### Step 2：決定目前區段的結束位置

再次遍歷字串。

對於目前字元：

```cpp
end = max(end, last[s[i] - 'a']);
```

表示目前區段至少要延伸到此字元最後一次出現的位置。

---

### Step 3：完成一個區段

若目前索引：

```cpp
i == end
```

表示目前區段中的所有字元都已完整包含。

因此可切割出一個區段：

```cpp
length = end - start + 1;
```

加入答案：

```cpp
result.push_back(length);
```

接著更新下一段起點：

```cpp
start = i + 1;
```

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26);

        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<int> result;

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i] - 'a']);

            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
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
| 空間複雜度 | **O(1)** |

其中：

- `n` 為字串長度。

需要遍歷字串兩次，因此時間複雜度為 **O(n)**。

額外使用大小固定為 `26` 的陣列紀錄最後出現位置，因此空間複雜度為 **O(1)**。

---

## 5. 重點整理

- 使用 **Greedy（貪心法）** 解決字串分割問題。
- 先記錄每個字元最後一次出現的位置。
- 遍歷字串時，不斷更新目前區段的最遠結束位置：
  ```cpp
  end = max(end, last[s[i] - 'a']);
  ```
- 當索引到達 `end` 時，即可完成一個合法區段。
- 每個字元只會處理兩次，因此時間複雜度為 **O(n)**，空間複雜度為 **O(1)**。
