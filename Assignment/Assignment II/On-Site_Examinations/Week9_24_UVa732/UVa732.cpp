#include <iostream>
#include <string>
#include <vector>
using namespace std;

void dfs(const string& source, const string& target, int s_idx, int t_idx, string current_stack, string path) {
    if (t_idx == target.length()) {
        for (int i = 0; i < path.length(); ++i) {
            cout << path[i] << (i == path.length() - 1 ? "" : " ");
        }
        cout << "\n";
        return;
    }

    // 分支 1：推入堆疊 (Push 'i')
    if (s_idx < source.length()) {
        dfs(source, target, s_idx + 1, t_idx, current_stack + source[s_idx], path + "i");
    }

    // 分支 2：彈出堆疊 (Pop 'o')
    if (!current_stack.empty() && current_stack.back() == target[t_idx]) {
        // substr 用來模擬 pop 掉最後一個字元
        string next_stack = current_stack.substr(0, current_stack.length() - 1);
        dfs(source, target, s_idx, t_idx + 1, next_stack, path + "o");
    }
}

int main() {
    string source, target;
    
    while (cin >> source >> target) {
        cout << "[\n";
        
        if (source.length() == target.length()) {
            dfs(source, target, 0, 0, "", "");
        }
        
        cout << "]\n";
    }
    
    return 0;
}
