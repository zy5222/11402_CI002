#include <bits/stdc++.h>
using namespace std;

int main(){
    int cnt[3][3];
    while(cin >> cnt[0][0] >> cnt[0][1] >> cnt[0][2]
              >> cnt[1][0] >> cnt[1][1] >> cnt[1][2]
              >> cnt[2][0] >> cnt[2][1] >> cnt[2][2]){

        int total[3];
        for(int i = 0; i < 3; i++)
            total[i] = cnt[i][0] + cnt[i][1] + cnt[i][2];
        int sumAll = total[0] + total[1] + total[2];

        int perm[3] = {0, 1, 2};
        int bestCost = INT_MAX;
        int bestPerm[3];

        do{
            int cost = 0;
            for(int bin = 0; bin < 3; bin++){
                int keepType = perm[bin];
                cost += total[bin] - cnt[bin][keepType];
            }
            if(cost < bestCost){
                bestCost = cost;
                bestPerm[0] = perm[0];
                bestPerm[1] = perm[1];
                bestPerm[2] = perm[2];
            }
        } while(next_permutation(perm, perm + 3));

        const char* names[3] = {"BCG", "CGB", "GBC"};
        string label;
        for(int bin = 0; bin < 3; bin++)
            label += names[bestPerm[bin]][bin];

        cout << label << " " << bestCost << "\n";
    }
    return 0;
}
