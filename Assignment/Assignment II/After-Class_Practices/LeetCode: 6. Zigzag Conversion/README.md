# LeetCode 6 - Zigzag Conversion

## 1. 題目摘要

給定一個字串 `s` 與整數 `numRows`，請依照 **Z 字形（Zigzag）** 的方式排列字元，再依序逐行讀取並回傳新的字串。

例如：

```text
Input:
s = "PAYPALISHIRING"
numRows = 3

排列方式：

P   A   H   N
A P L S I I G
Y   I   R

Output:
"PAHNAPLSIIGYIR"
```

若 `numRows = 1`，則不需進行任何轉換，直接回傳原字串。

---

## 2. 解題邏輯

本題可利用 **模擬（Simulation）** 的方式完成，不需要真正建立二維矩陣。

### Step 1：特殊情況處理

若

- `numRows == 1`
- 或 `numRows >= s.length()`

表示不會形成 Z 字形，直接回傳原字串即可。

---

### Step 2：建立每一列的字串

建立一個

```cpp
vector<string> rows(numRows);
```

每個元素代表 Z 字形中的一列。

例如：

```
rows[0]
rows[1]
rows[2]
...
```

---

### Step 3：模擬字元移動

使用兩個變數：

- `currentRow`：目前所在列
- `goingDown`：目前方向

初始：

```cpp
currentRow = 0
goingDown = false
```

當到達

- 第一列
- 最後一列

就反轉方向。

```cpp
if (currentRow == 0 || currentRow == numRows - 1)
    goingDown = !goingDown;
```

接著依方向更新列號：

```cpp
currentRow += goingDown ? 1 : -1;
```

每讀取一個字元，就加入目前列：

```cpp
rows[currentRow] += c;
```

---

### Step 4：合併所有列

最後依序將每一列接起來即可：

```cpp
result += row;
```

得到答案。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length())
            return s;

        vector<string> rows(numRows);

        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;

            if (currentRow == 0 || currentRow == numRows - 1)
                goingDown = !goingDown;

            currentRow += goingDown ? 1 : -1;
        }

        string result;

        for (string row : rows)
            result += row;

        return result;
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| 時間複雜度 | **O(n)** |
| 空間複雜度 | **O(n)** |

- 每個字元只會走訪一次，因此時間複雜度為 **O(n)**。
- 使用 `vector<string>` 儲存所有字元，因此需要 **O(n)** 額外空間。

---

## 5. 重點整理

- 使用 **模擬（Simulation）** 即可完成，不需建立真正的二維矩陣。
- 建立 `vector<string>` 儲存每一列的字元。
- 利用 `currentRow` 紀錄目前所在列。
- 利用 `goingDown` 控制向下或向上移動。
- 到達第一列或最後一列時切換方向。
- 最後依序合併每一列即可得到答案。
