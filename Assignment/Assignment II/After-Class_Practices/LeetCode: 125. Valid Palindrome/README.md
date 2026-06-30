# LeetCode 125 - Valid Palindrome

## 1. 題目摘要
實作 `isPalindrome(string s)` 函式，判斷給定字串是否為回文（Palindrome）。

判斷時需遵守以下規則：

1. **忽略非英文字母與數字字元**：所有標點符號、空白及特殊字元皆不參與比較。
2. **忽略大小寫**：英文字母比較時不區分大小寫。
3. **回文判斷**：若處理後的字串正反讀皆相同，則回傳 `true`；否則回傳 `false`。

---

## 2. 解題邏輯

本題使用 **雙指標（Two Pointers）** 解法，不需額外建立新的字串，因此空間效率較佳。

### 1. 建立左右指標

- `left` 指向字串開頭。
- `right` 指向字串結尾。

### 2. 跳過非英數字元

利用 `isalnum()` 判斷目前字元是否為英文字母或數字。

- 若左側不是英數字元，則 `left++`。
- 若右側不是英數字元，則 `right--`。

直到左右指標皆停留在有效字元。

### 3. 比較字元

使用 `tolower()` 將左右兩側字元轉為小寫後比較。

- 若兩字元不同，表示不是回文，立即回傳 `false`。
- 若相同，左右指標同時向中間移動。

### 4. 完成判斷

當 `left >= right` 時，代表所有字元皆成功配對，因此回傳 `true`。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // 跳過非英數字元
            while (left < right && !isalnum(s[left]))
                left++;

            while (left < right && !isalnum(s[right]))
                right--;

            // 比較（忽略大小寫）
            if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| 時間複雜度 | **O(n)** |
| 空間複雜度 | **O(1)** |

- 每個字元最多只會被左右指標掃描一次，因此時間複雜度為 **O(n)**。
- 僅使用左右指標，不需建立新的字串，因此空間複雜度為 **O(1)**。

---

## 5. 重點整理

- 使用 **雙指標（Two Pointers）** 同時從字串兩端向中間掃描。
- 利用 `isalnum()` 忽略所有非英數字元。
- 利用 `tolower()` 忽略大小寫差異。
- 第一個不相同的字元即可直接回傳 `false`。
- 不需要建立新的字串，因此可用 **O(1)** 額外空間完成題目要求。
