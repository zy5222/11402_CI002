#include <iostream>
using namespace std;
 
int main() {
    int T, N;
    string s;
    cin >> T;
    while (T--){
        cin >> N;
        getline(cin, s);
        int a[N];
        for (int i = 0; i < N; i++){
            getline(cin, s);
            if (s == "LEFT") a[i] = -1;
            else if (s == "RIGHT") a[i] = 1;
            else {
                int idx = 0;
                for (int j = 8; j < s.size(); j++){
                    idx *= 10;
                    idx += s[j] - '0';
                }
                a[i] = a[idx-1];
            }
        }
        int pos = 0;
        for (int i = 0; i < N; i++){
            pos += a[i];
        }
        cout << pos << "\n";
    }
    return 0;
}
