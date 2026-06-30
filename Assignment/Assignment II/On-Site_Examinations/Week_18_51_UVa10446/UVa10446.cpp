#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        if(s.empty()) continue;
        set<char> all(s.begin(), s.end());
        int need = (int)all.size();
        set<char> seen;
        int ans = -1;
        for(size_t i = 0; i < s.size(); i++){
            seen.insert(s[i]);
            if((int)seen.size() == need){
                ans = (int)i + 1;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
