#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        list<char> text;
        auto cursor = text.begin();

        for (char c : s) {
            if (c == '[') {
                // Home 鍵：游標移到最前面
                cursor = text.begin();
            } else if (c == ']') {
                // End 鍵：游標移到最後面
                cursor = text.end();
            } else {
                // 一般打字：在游標位置插入字元
                text.insert(cursor, c);
            }
        }

        // 依序印出結果
        for (char c : text) {
            cout << c;
        }
        cout << "\n";
    }

    return 0;
}
