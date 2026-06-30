#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int caseNo = 1;
    bool first = true;
    while(cin >> n && n != 0){
        vector<int> w(n);
        for(int i = 0; i < n; i++) cin >> w[i];

        int total = accumulate(w.begin(), w.end(), 0);
        int k1 = n / 2;

        vector<vector<vector<char>>> dp(n + 1,
            vector<vector<char>>(k1 + 1, vector<char>(total + 1, 0)));
        dp[0][0][0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= min(i, k1); j++){
                for(int s = 0; s <= total; s++){
                    if(dp[i-1][j][s]) dp[i][j][s] = 1;
                    if(j > 0 && s >= w[i-1] && dp[i-1][j-1][s-w[i-1]])
                        dp[i][j][s] = 1;
                }
            }
        }

        int bestS = -1, bestDiff = INT_MAX;
        for(int s = 0; s <= total; s++){
            if(dp[n][k1][s]){
                int diff = abs(total - 2 * s);
                if(diff < bestDiff){
                    bestDiff = diff;
                    bestS = s;
                }
            }
        }

        vector<int> groupA, groupB;
        int i = n, j = k1, s = bestS;
        while(i > 0){
            if(j > 0 && s >= w[i-1] && dp[i-1][j-1][s-w[i-1]] &&
               (!dp[i-1][j][s])){
                groupA.push_back(i-1);
                j--; s -= w[i-1];
            } else if(dp[i-1][j][s]){
            } else {
                groupA.push_back(i-1);
                j--; s -= w[i-1];
            }
            i--;
        }
        vector<char> inA(n, 0);
        for(int idx : groupA) inA[idx] = 1;
        for(int idx = 0; idx < n; idx++) if(!inA[idx]) groupB.push_back(idx);

        sort(groupA.begin(), groupA.end());
        sort(groupB.begin(), groupB.end());

        int sumA = 0, sumB = 0;
        for(int idx : groupA) sumA += w[idx];
        for(int idx : groupB) sumB += w[idx];

        if(!first) cout << "\n";
        first = false;

        cout << "Set #" << caseNo++ << "\n";
        for(int idx : groupA)
            cout << " " << idx + 1 << ": " << w[idx] << "\n";
        cout << fixed << setprecision(2);
        cout << "Average weight = " << (sumA / (double)groupA.size()) << "\n";
        cout << "\n";
        for(int idx : groupB)
            cout << " " << idx + 1 << ": " << w[idx] << "\n";
        cout << "Average weight = " << (sumB / (double)groupB.size()) << "\n";
    }
    return 0;
}
