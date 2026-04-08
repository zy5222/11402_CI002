#include<bits/stdc++.h>
using namespace std;

int main() {
    string line;
    bool first = true;

    while (getline(cin, line)) {
        
        if (!first) {
            cout << "\n";
        }
        first = false;

        int freq[256] = {0};
        for (int i = 0; i < line.length(); i++) {
            freq[line[i]]++; 
        }
        // 頻率最小是 1，最大不可能超過字串的長度
        for (int f = 1; f <= line.length(); f++) {
            // ASCII 碼從 255 往下檢查到 0 (符合題目：頻率相同時，ASCII 大的先印)
            for (int i = 255; i >= 0; i--) {
                // 如果該字元的頻率剛好等於目前找的頻率 f，就印出來
                if (freq[i] == f) {
                    cout << i << " " << f << "\n";
                }
            }
        }
    }

    return 0;
}
