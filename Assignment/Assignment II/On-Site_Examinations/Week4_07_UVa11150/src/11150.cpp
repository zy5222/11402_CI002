#include <iostream>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        // n 是一開始買的， n / 2 是靠空瓶換來的
        cout << n + n / 2 << "\n";
    }
    return 0;
}
