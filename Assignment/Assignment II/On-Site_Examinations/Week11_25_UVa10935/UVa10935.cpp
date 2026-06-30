#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    
    while (cin >> n && n != 0) {
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            q.push(i);
        }
        
        cout << "Discarded cards:";
        
        // 只要還有兩張牌以上，就繼續丟牌與移牌
        while (q.size() >= 2) {
            if (q.size() == n) {
                cout << " " << q.front();
            } else {
                cout << ", " << q.front();
            }
            q.pop(); 
            
            q.push(q.front()); 
            q.pop();        
        }
        cout << "\n";
        cout << "Remaining card: " << q.front() << "\n";
    }
    
    return 0;
}
