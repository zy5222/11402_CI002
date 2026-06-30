# LeetCode 179 - Largest Number

## 1. 題目摘要
給定一個由非負整數組成的陣列 `nums`，請將其元素重新排列並串接，以形成可能的最大數字，並將結果以字串（String）形式回傳。

---

## 2. 解題邏輯
本題之核心無法單純依靠數字大小或一般字串之字典序進行排序（例如 `9` 應排在 `34` 之前，而 `3` 與 `30` 比較時，`3` 應排在前以形成 `330` 而非 `303`）。需採用「自定義排序規則」來解決。

1. **轉換型態**：
   由於整數拼接在數值運算上較為複雜，且可能引發整數溢位（Integer Overflow），故首要步驟是將陣列中的所有整數轉換為字串型態。

2. **自定義排序邏輯**：
   對於任意兩個字串 $a$ 與 $b$，比較其拼接結果：
   * 若字串 $a + b$ 大於 $b + a$（依字典序比較），則在最終結果中 $a$ 必須排在 $b$ 之前。
   * 利用此規則，呼叫內建之排序函式對整個字串陣列進行降冪排序。

3. **邊界情況處理（前導零）**：
   排序完成後，若陣列之第一個元素（即最大值）為 `"0"`，表示原陣列中僅包含多個 $0$（如 `[0, 0]`）。為避免回傳不合法之數字字串 `"00"`，此時應直接回傳 `"0"`。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        strs.reserve(nums.size());
        
        // 將所有整數轉換為字串
        for (int num : nums) {
            strs.push_back(to_string(num));
        }
        
        // 自定義排序：比較 a+b 與 b+a 之大小
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        
        // 處理全為 0 的極端情況
        if (strs.front() == "0") {
            return "0";
        }
        
        // 拼接所有字串
        string result = "";
        for (const string& s : strs) {
            result += s;
        }
        
        return result;
    }
};
