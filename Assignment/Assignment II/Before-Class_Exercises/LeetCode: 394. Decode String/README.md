# LeetCode 394 - Decode String

## 1. 題目摘要
給定一個經過編碼的字串 `s`，請回傳其解碼後的原始字串。
編碼規則為：`k[encoded_string]`，表示方括號內部的 `encoded_string` 必須被重複 `k` 次。
題目保證輸入字串必定有效，無多餘之空白字元，且方括號之格式皆正確對稱。此外，原字串中僅包含小寫英文字母，數字僅會作為重複次數 `k` 出現。

---

## 2. 解題邏輯
本題因涉及括號之嵌套與展開，具備「後進先出（LIFO）」之特性（最內層之括號需最先被解碼），故最佳解法為採用**堆疊（Stack）**資料結構。

1. **宣告資料結構**：
   需維護兩個主要狀態：
   * `count_stack`：用以儲存重複次數（整數）。
   * `string_stack`：用以暫存尚未展開之先前字串。
   同時宣告兩個變數 `current_string`（當前正在建構之字串）與 `current_num`（當前正在計算之倍數），初始皆為空或零。

2. **字串走訪與狀態切換**：
   逐一走訪輸入字串 `s` 中的每一個字元 `c`，依據其類型執行對應操作：
   * **若為數字（Digit）**：
     因倍數可能為多位數（如 `100`），需透過公式 `current_num = current_num * 10 + (c - '0')` 進行連續累加計算。
   * **若為左括號 `[`**：
     代表即將進入新一層的編碼區塊。必須將目前的 `current_num` 與 `current_string` 分別推入對應之堆疊中進行保存，隨後將兩變數重置（`current_num = 0`，`current_string = ""`），以迎接括號內部之新字串。
   * **若為右括號 `]`**：
     代表當前層級之編碼區塊已結束，需進行解碼拼接。自 `count_stack` 彈出重複次數 `k`，並自 `string_stack` 彈出上一層暫存之字串 `prev_string`。將當前的 `current_string` 重複 `k` 次後，附加於 `prev_string` 之後，並將結果重新指派給 `current_string`。
   * **若為英文字母**：
     直接將其附加至 `current_string` 末端。

3. **回傳結果**：
   走訪結束後，堆疊皆已清空，此時之 `current_string` 即為完全展開之最終解碼字串。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    string decodeString(string s) {
        stack<int> count_stack;
        stack<string> string_stack;
        
        string current_string = "";
        int current_num = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                // 處理多位數數字
                current_num = current_num * 10 + (c - '0');
            } else if (c == '[') {
                // 將當前狀態推入堆疊，並重置狀態以處理內層字串
                count_stack.push(current_num);
                string_stack.push(current_string);
                
                current_num = 0;
                current_string = "";
            } else if (c == ']') {
                // 取出堆疊中的倍數與前段字串進行展開與拼接
                int k = count_stack.top();
                count_stack.pop();
                
                string prev_string = string_stack.top();
                string_stack.pop();
                
                string temp = "";
                for (int i = 0; i < k; ++i) {
                    temp += current_string;
                }
                
                current_string = prev_string + temp;
            } else {
                // 一般英文字母直接附加
                current_string += c;
            }
        }
        
        return current_string;
    }
};
