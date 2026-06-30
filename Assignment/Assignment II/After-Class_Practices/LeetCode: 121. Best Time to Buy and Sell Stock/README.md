# LeetCode 121 - Best Time to Buy and Sell Stock

## 1. 題目摘要

給定一個整數陣列 `prices`，其中 `prices[i]` 表示某支股票在第 `i` 天的價格。

你只能進行 **一次買進** 和 **一次賣出**（且必須先買後賣），請找出可以獲得的**最大利潤**。

若無法獲利，則回傳 `0`。

例如：

```text
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation:
第 2 天以價格 1 買入，第 5 天以價格 6 賣出，最大利潤為 6 - 1 = 5。
```

```text
Input: prices = [7,6,4,3,1]
Output: 0
```

---

## 2. 解題邏輯

本題可利用 **一次遍歷（One Pass）** 完成。

核心想法是：

- 持續記錄目前為止最低的買入價格。
- 每到一天，就計算若今天賣出可以得到多少利潤。
- 更新目前最大的利潤。

---

### Step 1：紀錄最低買入價格

建立變數：

```cpp
minPrice = INT_MAX;
```

遍歷陣列時：

```cpp
minPrice = min(minPrice, price);
```

讓 `minPrice` 永遠保持目前最低股價。

---

### Step 2：計算今天賣出的利潤

若今天價格為

```cpp
price
```

則今天賣出的利潤為：

```cpp
price - minPrice
```

更新最大利潤：

```cpp
maxProfit = max(maxProfit, price - minPrice);
```

---

### Step 3：遍歷完成

所有價格都檢查完後：

- 若有獲利，回傳最大利潤。
- 若始終沒有獲利，`maxProfit` 仍為 `0`。

---

## 3. 程式碼實作

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};
```

---

## 4. 複雜度分析

| 項目 | 複雜度 |
|------|--------|
| 時間複雜度 | **O(n)** |
| 空間複雜度 | **O(1)** |

- 僅遍歷陣列一次，因此時間複雜度為 **O(n)**。
- 只使用兩個額外變數，因此空間複雜度為 **O(1)**。

---

## 5. 重點整理

- 使用 **一次遍歷（One Pass）** 即可解決。
- `minPrice` 紀錄目前最低買入價格。
- 每一天都計算若今天賣出的利潤。
- 持續更新最大利潤 `maxProfit`。
- 若價格持續下跌，則無法獲利，最後回傳 `0`。
