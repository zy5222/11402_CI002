# LeetCode 9 - Palindrome Number

## 1. 題目摘要
給定一個整數 `x`，請判斷其是否為「迴文數」（Palindrome Number）。若 `x` 由左至右讀取與由右至左讀取皆完全相同，則回傳 `true`；否則回傳 `false`。
進階挑戰要求：不可將整數轉換為字串（String）來進行判斷。

---

## 2. 解題邏輯
為避免整數反轉時可能遭遇之整數溢位（Integer Overflow）問題，並符合不轉換為字串之限制，最佳解法為「反轉後半段數字」並與前半段數字進行比對。

1. **排除必非迴文之極端邊界條件**：
   * 所有負數皆非迴文（例如 `-121` 反轉為 `121-`）。
   * 若數字不為 $0$，且其個位數為 $0$（即 `x % 10 == 0`），則必非迴文（因最高位數不可能為 $0$）。

2. **反轉後半段數字**：
   * 宣告一變數 `revertedNumber` 初始為 $0$。
   * 透過迴圈，不斷取出 `x` 的個位數（`x % 10`）並累加至 `revertedNumber` 的尾端（`revertedNumber = revertedNumber * 10 + x % 10`），隨後將 `x` 縮減一位（`x /= 10`）。
   * 當 `x` 小於或等於 `revertedNumber` 時，代表已反轉至數字的中心點，迴圈終止。

3. **奇偶數長度判斷**：
   * 若原數字長度為偶數（例如 `1221`），迴圈結束時 `x` 應完全等於 `revertedNumber`（皆為 `12`）。
   * 若原數字長度為奇數（例如 `12321`），迴圈結束時 `x` 為 `12`，而 `revertedNumber` 為 `123`。此時中心數字（`3`）不影響迴文對稱性，可透過 `revertedNumber / 10` 將其去除後再與 `x` 比較。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        // 排除負數，以及尾數為 0 但本身非 0 的數字
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int revertedNumber = 0;
        
        // 當 x 小於等於 revertedNumber 時，代表已經處理到數字的中心
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        
        // 偶數長度判斷：x == revertedNumber
        // 奇數長度判斷：x == revertedNumber / 10
        return x == revertedNumber || x == revertedNumber / 10;
    }
};
