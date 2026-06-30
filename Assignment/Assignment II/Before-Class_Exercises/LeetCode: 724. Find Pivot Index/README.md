# LeetCode 724 - Find Pivot Index

## 1. 題目摘要
給定一個整數陣列 `nums`，請計算並回傳該陣列的「樞紐索引」（Pivot Index）。
樞紐索引的定義為：在該索引位置左側的所有元素總和，恰好等於其右側所有元素的總和。
若樞紐索引位於陣列之最左端，則左側總和視為 $0$；同理，若位於最右端，右側總和視為 $0$。若陣列中存在多個樞紐索引，請回傳最靠左的索引；若不存在任何樞紐索引，則回傳 $-1$。

---

## 2. 解題邏輯
本題若使用暴力解法，對於每一個索引皆重新計算其左右兩側之總和，時間複雜度將高達 $O(n^2)$。為達到最佳效能，應採用**前綴和（Prefix Sum）**之概念，透過預先計算總和，將時間複雜度降至 $O(n)$。

1. **計算陣列總和**：
   先進行一次完整的陣列走訪，將所有元素加總，取得 `total_sum`。

2. **動態維護左側總和**：
   宣告一個變數 `left_sum`，初始值設為 $0$。
   由左至右逐一走訪陣列，對於目前所指到的索引 `i` 與其對應之元素 `nums[i]`：
   * 其右側剩餘元素之總和 `right_sum` 可利用公式推導：`total_sum - left_sum - nums[i]`。
   * 比較 `left_sum` 是否等於推導出之 `right_sum`。若相等，代表尋獲最左側之樞紐索引，直接回傳 `i`。
   * 若不相等，則將目前的元素 `nums[i]` 累加至 `left_sum` 中，以便進行下一個索引之評估。

3. **終止條件**：
   若完成整趟走訪仍未尋獲任何符合條件之索引，依題意回傳 $-1$。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        int left_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // 右側總和 = 總和 - 左側總和 - 當前元素
            if (left_sum == total_sum - left_sum - nums[i]) {
                return i;
            }
            // 將當前元素加入左側總和，供下一個索引使用
            left_sum += nums[i];
        }
        
        return -1;
    }
};
