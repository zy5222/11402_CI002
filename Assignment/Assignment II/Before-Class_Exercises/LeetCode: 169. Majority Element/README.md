# LeetCode 169 - Majority Element

## 1. 題目摘要
給定一個大小為 $n$ 的整數陣列 `nums`，請找出並回傳其中的「多數元素」（Majority Element）。多數元素係指在陣列中出現次數嚴格大於 $\lfloor n / 2 \rfloor$ 次的元素。題目保證輸入陣列中必定存在該多數元素。

---

## 2. 解題邏輯
本題具備多種解法（如雜湊表或排序），但最符合面試標準且能將空間複雜度最佳化至 $O(1)$ 的經典解法為**Boyer-Moore 投票演算法**（Boyer-Moore Voting Algorithm）。

1. **演算法核心思想**：
   此演算法基於「抵銷」的概念。因多數元素的出現總次數超過陣列長度的一半，若將多數元素視為 $+1$，其餘所有非多數元素視為 $-1$，將全數疊加後，最終的總和必定大於 $0$。這意味著多數元素永遠無法被其他元素完全抵銷。

2. **執行步驟**：
   * 宣告兩個變數：`candidate`（用以記錄目前的候選元素）與 `count`（用以記錄該候選元素的優勢次數），初始值皆為 $0$。
   * 逐一走訪陣列中的每一個元素 `num`：
     * 若 `count == 0`：表示先前的所有元素已兩兩互相抵銷完畢。此時，無條件將目前的 `num` 設為新的 `candidate`。
     * 若 `num == candidate`：表示遇到支持目前候選者的元素，將 `count` 加 $1$。
     * 若 `num != candidate`：表示遇到反對目前候選者的元素，將 `count` 減 $1$。
   * 走訪完畢後，`candidate` 即為所求之多數元素。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        
        for (int num : nums) {
            // 若計數歸零，更換候選人
            if (count == 0) {
                candidate = num;
            }
            
            // 進行投票抵銷
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
};
