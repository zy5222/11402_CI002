#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main() {
    int t;
    int case_num = 1;
    
    while (cin >> t && t != 0) {
        cout << "Scenario #" << case_num++ << "\n";
        vector<int> team_of(1000000, -1);
        for (int i = 0; i < t; ++i) {
            int n;
            cin >> n;
            for (int j = 0; j < n; ++j) {
                int person;
                cin >> person;
                team_of[person] = i;
            }
        }
        
        queue<int> main_queue;        
        vector<queue<int>> team_queues(t); // 儲存各隊伍「正在排隊的成員」
        vector<bool> in_queue(t, false);   // 記錄該隊伍是否已在 main_queue 中
        
        string cmd;
        while (cin >> cmd && cmd != "STOP") {
            if (cmd == "ENQUEUE") {
                int person;
                cin >> person;
                int tid = team_of[person];
                
                // 如果這個人的隊伍還沒有人在排隊，就去排 main_queue
                if (!in_queue[tid]) {
                    main_queue.push(tid);
                    in_queue[tid] = true;
                }
                // 把人排進自己的隊伍佇列中
                team_queues[tid].push(person);
                
            } else if (cmd == "DEQUEUE") {
                int tid = main_queue.front();
                
                // 輸出該隊伍排在最前面的人，並讓他離開
                cout << team_queues[tid].front() << "\n";
                team_queues[tid].pop();
                
                // 如果該隊伍的人都走光了，就讓整個隊伍離開 main_queue
                if (team_queues[tid].empty()) {
                    main_queue.pop();
                    in_queue[tid] = false;
                }
            }
        }
        cout << "\n";
    }
    
    return 0;
}
