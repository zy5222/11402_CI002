#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    long long p;
    int c;
    int case_num = 1;

    while (cin >> p >> c && (p != 0 || c != 0)) {
        cout << "Case " << case_num++ << ":\n";

        list<long long> q;
        long long limit = min(p, (long long)c);
        
        // 只需要初始化前 min(P, C) 個人即可
        for (long long i = 1; i <= limit; ++i) {
            q.push_back(i);
        }

        for (int i = 0; i < c; ++i) {
            char cmd;
            cin >> cmd;

            if (cmd == 'N') {
                long long front_person = q.front();
                cout << front_person << "\n";
                
                q.pop_front();
                q.push_back(front_person);
                
            } else if (cmd == 'E') {
                long long x;
                cin >> x;
                
                // 從串列中移除該人（若存在），並拉到最前面
                q.remove(x);
                q.push_front(x);
            }
        }
    }
    return 0;
}
