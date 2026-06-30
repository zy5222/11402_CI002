#include <bits/stdc++.h>
using namespace std;

typedef vector<int> Big;

Big add(const Big &a, const Big &b){
    Big res;
    int carry = 0;
    size_t n = max(a.size(), b.size());
    for(size_t i = 0; i < n || carry; i++){
        int x = carry;
        if(i < a.size()) x += a[i];
        if(i < b.size()) x += b[i];
        res.push_back(x % 10);
        carry = x / 10;
    }
    return res;
}

string toString(const Big &a){
    string s;
    for(int i = (int)a.size() - 1; i >= 0; i--)
        s += char('0' + a[i]);
    return s;
}

int main(){
    int N;
    vector<Big> f(251);
    f[0] = Big{1};
    f[1] = Big{1};
    for(int i = 2; i <= 250; i++)
        f[i] = add(f[i-1], f[i-2]);

    while(cin >> N){
        cout << toString(f[N]) << "\n";
    }
    return 0;
}
