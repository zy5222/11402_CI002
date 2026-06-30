# LeetCode 704 - Binary Search

## 1. 題目摘要
給定一個呈嚴格遞增排序之整數陣列 `nums`，以及一個目標值 `target`。請在該陣列中搜尋 `target`：若目標值存在，回傳其所在之索引值（Index）；若不存在，則回傳 `-1`。演算法之時間複雜度必須符合 $O(\log n)$ 之要求。

---

## 2. 解題邏輯
本題為最經典之**二分搜尋法（Binary Search）**實作。由於輸入陣列已保證為遞增排序，可透過不斷將搜尋區間折半之方式，快速定位目標值。

1. **定義搜尋區間**：
   宣告兩個指標 `left` 與 `right`，分別指向陣列之起始與終點。此處採用**左閉右閉區間** `[left, right]` 之設計，初始狀態設為 `left = 0` 且 `right = nums.size() - 1`。

2. **區間折半與逼近**：
   當 `left <= right` 時（即搜尋區間仍然有效），重複執行以下操作：
   * 計算區間中點 `mid`。為避免 `left + right` 造成 32 位元整數溢位（Integer Overflow），應採用 `left + (right - left) / 2` 之寫法。
   * 檢驗 `nums[mid]` 與 `target` 之大小關係：
     * 若 `nums[mid] == target`：已尋獲目標，直接回傳 `mid`。
     * 若 `nums[mid] < target`：代表目標值必位於中點右側，故將左邊界右移，更新 `left = mid + 1`。
     * 若 `nums[mid] > target`：代表目標值必位於中點左側，故將右邊界左移，更新 `right = mid - 1`。

3. **終止條件**：
   若迴圈結束仍未尋獲 `target`，表示目標值不在陣列中，回傳 `-1`。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            // 避免整數溢位之標準寫法
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
};
