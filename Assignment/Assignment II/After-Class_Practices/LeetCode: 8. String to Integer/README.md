# LeetCode 8 - String to Integer (atoi)

## 1. 題目摘要
實作 `myAtoi(string s)` 函式，將字串轉換為 32 位元有號整數。轉換規則如下：
1. **忽略前導空白**：移除字串開頭的所有空格。
2. **檢查正負號**：檢測下一個非空白字元是否為 `'+'` 或 `'-'`，決定結果的正負。
3. **數字轉換**：讀取連續的數字字元，直至遇到非數字字元或字串結尾。
4. **溢位處理**：若轉換後的數值超出 32 位元有號整數範圍（$[ -2^{31}, 2^{31} - 1 ]$），則需將結果夾擠（Clamp）至該範圍的邊界值。
5. **無效輸入**：若首個非空白字元非數字或符號，或字串為空，則回傳 `0`。

---

## 2. 解題邏輯
本題核心在於處理細瑣的邊界條件，並準確控管數值溢位風險。

1. **處理前導空白與符號**：
   使用指標遍歷字串，跳過所有 `' '`。接著檢查當前字元是否為 `'+'` 或 `'-'`，並更新正負號變數 `sign`（預設為 `1`）。

2. **轉換與溢位控管**：
   在將字元轉為數字並累加至結果 `result` 時，必須在「乘以 10」前預先檢查是否會導致溢位。
   * **最大值界限**：`INT_MAX` 是 `2147483647`。若 `result > INT_MAX / 10`，下一步必溢位。若 `result == INT_MAX / 10`，則需檢查最後一位數字是否大於 `7`。
   * **最小值界限**：`INT_MIN` 是 `-2147483648`。處理方式與最大值類似，檢查最後一位是否大於 `8`（注意絕對值）。

---

## 3. 程式碼實作

```cpp
#include <climits>

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length(), sign = 1;
        long long result = 0; // 使用 long long 輔助檢測

        // 1. 忽略前導空格
        while (i < n && s[i] == ' ') i++;

        // 2. 處理符號
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i++] == '-') ? -1 : 1;
        }

        // 3. 數字轉換與溢位處理
        while (i < n && isdigit(s[i])) {
            int digit = s[i++] - '0';
            
            result = result * 10 + digit;
            
            // 溢位截斷處理
            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;
        }

        return (int)(result * sign);
    }
};
