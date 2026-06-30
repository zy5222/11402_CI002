#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    int case_num = 1;
    
    while (cin >> s && s != "end") {
        vector<char> tops;
        
        for (char c : s) {
            bool placed = false;
            // 尋找第一個可以疊上去的堆疊
            for (int i = 0; i < tops.size(); ++i) {
                if (tops[i] >= c) {
                    tops[i] = c;
                    placed = true;
                    break;
                }
            }
            // 如果都不能疊，就開一個新的堆疊
            if (!placed) {
                tops.push_back(c);
            }
        }
        cout << "Case " << case_num++ << ": " << tops.size() << "\n";
    }
    return 0;
}
