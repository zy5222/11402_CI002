# LeetCode 150 - Evaluate Reverse Polish Notation

## 1. 題目摘要

給定一個以 **Reverse Polish Notation（RPN，逆波蘭表示法）** 表示的運算式，請計算並回傳其結果。

RPN 的規則如下：

- 運算元（數字）直接放入堆疊。
- 遇到運算子時，取出堆疊頂端的兩個數字進行運算，再將結果放回堆疊。
- 題目保證運算式合法，且不會發生除以零的情況。

支援的運算子：

- `+`
- `-`
- `*`
- `/`

例如：

```text
Input:
tokens = ["2","1","+","3","*"]

Output:
9

Explanation:
((2 + 1) * 3) = 9
```

```text
Input:
tokens = ["4","13","5","/","+"]

Output:
6

Explanation:
4 + (13 / 5) = 6
```

---

## 2. 解題邏輯

本題最適合使用 **Stack（堆疊）**。

因為 RPN 的運算順序正好符合 Stack 的 **LIFO（Last In, First Out）** 特性。

---

### Step 1：遍歷所有字串

依序讀取 `tokens` 中的每個字串。

若目前不是運算子：

```cpp
stack.push(stoi(token));
```

直接轉成整數放入 Stack。

---

### Step 2：遇到運算子

若目前為：

```text
+
-
*
/
```

則從 Stack 中取出兩個數字：

```cpp
int b = stack.top();
stack.pop();

int a = stack.top();
stack.pop();
```

需注意順序：

```text
a operator b
```

不能寫成：

```text
b operator a
```

尤其是減法與除法。

---

### Step 3：計算並放回 Stack

依照不同運算子：

```cpp
+
-
*
/
```

計算結果後：

```cpp
stack.push(result);
```

繼續處理下一個 token。

---

### Step 4：回傳答案

當所有 token 都處理完成後：

Stack 中只會剩下一個數字，即為最終答案。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token : tokens) {
            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {

                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                if (token == "+")
                    st.push(a + b);
                else if (token == "-")
                    st.push(a - b);
                else if (token == "*")
                    st.push(a * b);
                else
                    st.push(a / b);

            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| 時間複雜度 | **O(n)** |
| 空間複雜度 | **O(n)** |

其中：

- `n` 為 `tokens` 的數量。

每個 token 僅會處理一次，因此時間複雜度為 **O(n)**。

Stack 最多可能存放所有運算元，因此空間複雜度為 **O(n)**。

---

## 5. 重點整理

- 使用 **Stack（堆疊）** 模擬 Reverse Polish Notation 的運算流程。
- 數字直接放入 Stack。
- 遇到運算子時，依序取出兩個元素進行運算。
- 注意運算順序為 **先取出的第二個元素（a）運算第一個元素（b）**，即 `a operator b`。
- 每個 token 只需處理一次，因此時間複雜度為 **O(n)**。
```
