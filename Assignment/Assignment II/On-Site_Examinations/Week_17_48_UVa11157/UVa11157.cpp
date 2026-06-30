#include <bits/stdc++.h>
using namespace std;

int n;
long long cost[10][10];
int feas[1 << 10][10];

int solveFeas(int mask, int last, int full, long long T){
    if(mask == full) return 1;
    int &res = feas[mask][last];
    if(res != -1) return res;
    res = 0;
    for(int v = 0; v < n; v++){
        if(mask & (1 << v)) continue;
        if(cost[last][v] <= T){
            if(solveFeas(mask | (1 << v), v, full, T)){
                res = 1;
                break;
            }
        }
    }
    return res;
}

int main(){
    int caseNo = 1;
    bool first = true;
    while(cin >> n && n != 0){
        vector<int> x(n), y(n);
        for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cost[i][j] = (long long)(x[i]-x[j])*(x[i]-x[j]) +
                             (long long)(y[i]-y[j])*(y[i]-y[j]);

        vector<long long> cands;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cands.push_back(cost[i][j]);
        sort(cands.begin(), cands.end());
        cands.erase(unique(cands.begin(), cands.end()), cands.end());

        int full = (1 << n) - 1;
        long long bestT = -1;

        for(long long T : cands){
            memset(feas, -1, sizeof(feas));
            if(solveFeas(1, 0, full, T)){
                bestT = T;
                break;
            }
        }

        memset(feas, -1, sizeof(feas));
        solveFeas(1, 0, full, bestT);

        vector<int> path;
        int mask = 1, last = 0;
        path.push_back(0);
        while(mask != full){
            for(int v = 0; v < n; v++){
                if(mask & (1 << v)) continue;
                if(cost[last][v] <= bestT &&
                   solveFeas(mask | (1 << v), v, full, bestT)){
                    mask |= (1 << v);
                    last = v;
                    path.push_back(v);
                    break;
                }
            }
        }

        if(!first) cout << "\n";
        first = false;

        for(size_t i = 0; i < path.size(); i++){
            if(i) cout << " ";
            cout << path[i] + 1;
        }
        cout << "\n";
    }
    return 0;
}
