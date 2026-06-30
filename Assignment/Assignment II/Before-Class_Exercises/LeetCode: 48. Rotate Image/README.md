# LeetCode 48 - Rotate Image

## 1. 題目摘要
給定一個 $n \times n$ 的二維矩陣 `matrix` 代表一張影像，請將該影像順時針旋轉 90 度。
規定必須在「原地」（In-place）進行矩陣的修改，不可宣告並配置另一個全新的二維矩陣來完成旋轉。

---

## 2. 解題邏輯
本題可透過兩個線性代數的基礎翻轉操作，達成順時針旋轉 90 度之效果，且完美符合 $O(1)$ 額外空間的限制。

1. **步驟一：矩陣轉置（Transpose）**：
   將矩陣沿著主對角線（左上至右下）進行翻轉。亦即，將索引位置 $(i, j)$ 的元素與 $(j, i)$ 的元素互換。需注意走訪時只需遍歷對角線右上或左下半部的元素，避免重複交換導致復原。

2. **步驟二：水平翻轉（Reverse/Reflect）**：
   轉置完成後，將矩陣的每一列（Row）各自進行水平反轉。亦即，將每一列中最左側的元素與最右側的元素互換，向中間靠攏。

綜合上述兩步，原矩陣之列（Row）將轉換為行（Column），且順序顛倒，進而達成順時針旋轉 90 度之目的。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // 步驟一：矩陣轉置 (Transpose)
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // 步驟二：水平翻轉 (Reverse each row)
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
