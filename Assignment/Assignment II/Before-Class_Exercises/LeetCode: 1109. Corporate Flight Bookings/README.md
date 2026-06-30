# LeetCode 1109 - Corporate Flight Bookings

## 1. 題目摘要
給定 $n$ 個航班，編號從 $1$ 到 $n$。另給定一個二維陣列 `bookings` 代表訂位紀錄，其中 `bookings[i] = [first, last, seats]` 表示從編號 `first` 到 `last` 的所有航班皆預訂了 `seats` 個座位。請計算並回傳一個長度為 $n$ 的陣列 `answer`，其中 `answer[i]` 為第 `i + 1` 個航班的總預訂座位數量。

---

## 2. 解題邏輯
本題若針對每一筆訂位紀錄皆使用迴圈去逐一累加對應區間的座位數，時間複雜度將會過高。針對此類「頻繁對陣列之連續區間進行加減操作」的題型，最佳解法為**差分陣列（Difference Array）**。

1. **差分陣列之原理**：
   差分陣列的核心思想在於記錄陣列中「相鄰元素之間的變化量」。
   若欲對區間 `[first, last]` 內的所有元素皆加上數值 `seats`，轉換為差分陣列的操作僅需修改兩個端點：
   * 在區間起點 `first` 處加上 `seats`（表示從此處開始，後續的數值皆增加了 `seats`）。
   * 在區間終點之次一位 `last + 1` 處減去 `seats`（表示先前的增加效果至此終止，恢復原狀）。

2. **執行步驟**：
   * 宣告一個長度為 $n$ 的陣列 `answer` 並初始化為 $0$（此處直接將 `answer` 作為差分陣列使用，以節省空間）。
   * 走訪每一筆 `booking`：
     * 將起點對應的索引（即 `first - 1`）加上 `seats`。
     * 檢查終點的下一個索引（即 `last`）是否超出陣列範圍，若未越界，則在該處減去 `seats`。
   * 將差分陣列還原為原始數值：由左至右對 `answer` 進行**前綴和（Prefix Sum）**運算。亦即 `answer[i] += answer[i - 1]`，計算完畢後之陣列即為所求之各航班總座位數。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> answer(n, 0);
        
        // 建立差分陣列
        for (const auto& booking : bookings) {
            int first = booking[0] - 1; // 轉換為 0-based 索引
            int last = booking[1] - 1;
            int seats = booking[2];
            
            answer[first] += seats;
            if (last + 1 < n) {
                answer[last + 1] -= seats;
            }
        }
        
        // 計算前綴和以還原各航班之總座位數
        for (int i = 1; i < n; ++i) {
            answer[i] += answer[i - 1];
        }
        
        return answer;
    }
};
