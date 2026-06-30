# LeetCode 658 - Find K Closest Elements

## 1. 題目摘要
給定一個已排序之整數陣列 `arr`，以及兩個整數 `k` 與 `x`。請自陣列中找出最接近 `x` 的 `k` 個元素，並將結果以遞增排序之形式回傳。
距離判斷準則：對於任意兩數 `a` 與 `b`，若滿足 `|a - x| < |b - x|`，或者 `|a - x| == |b - x|` 且 `a < b`，則認定 `a` 比 `b` 更接近 `x`。

---

## 2. 解題邏輯
因輸入之原陣列已經歷排序，可充分利用此遞增特性。尋求最佳效能之解法為**二分搜尋法（Binary Search）**尋找長度為 `k` 之滑動視窗（Sliding Window）的「最佳左邊界」。

1. **定義搜尋區間**：
   欲回傳之子陣列長度為 `k`，故合法的起始索引（左邊界）最小為 $0$，最大為 $n - k$（預留右方 `k` 個元素之空間）。設定 `left = 0`，`right = n - k`。

2. **二分搜尋逼近邊界**：
   計算中間索引 `mid`，並評估若以 `mid` 為起點，與以 `mid + 1` 為起點，何者較佳。這可轉化為比較邊界兩端元素與 `x` 之距離：
   * 比較 `x - arr[mid]` 與 `arr[mid + k] - x` 之大小。
   * 若 `x - arr[mid] > arr[mid + k] - x`，代表右側元素 `arr[mid + k]` 比左側元素 `arr[mid]` 更接近目標 `x`，故視窗整體應向右移動，設定 `left = mid + 1`。
   * 反之，若左側距離較小或兩者距離相等，依題意（數值較小者優先），應將視窗向左逼近或保留，設定 `right = mid`。

3. **收斂與回傳**：
   當 `left == right` 時迴圈終止，此時之 `left` 即為所求之最佳起始索引。自原陣列中截取從 `left` 開始、長度為 `k` 之子陣列即可。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // 比較視窗左端點與視窗右端點外側第一個元素與 x 的距離
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        // 擷取並回傳結果
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
