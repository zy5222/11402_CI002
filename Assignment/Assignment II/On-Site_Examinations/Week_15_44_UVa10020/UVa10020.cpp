#include <bits/stdc++.h>
using namespace std;

int main(){
    int L;
    bool first = true;
    while(scanf("%d", &L) == 1){
        vector<pair<int,int>> segs;
        int x, y;
        while(scanf("%d %d", &x, &y) == 2){
            if(x == -1 && y == -1) break;
            segs.push_back({x, y});
        }
        sort(segs.begin(), segs.end());

        vector<pair<int,int>> result;
        int covered = 0;
        bool ok = true;
        size_t i = 0;

        while(covered < L){
            int best = covered;
            int bestIdx = -1;
            while(i < segs.size() && segs[i].first <= covered){
                if(segs[i].second > best){
                    best = segs[i].second;
                    bestIdx = (int)i;
                }
                i++;
            }
            if(bestIdx == -1){
                ok = false;
                break;
            }
            result.push_back(segs[bestIdx]);
            covered = best;
        }

        if(!first) printf("\n");
        first = false;

        if(ok){
            printf("%d\n", (int)result.size());
            for(auto &p : result) printf("%d %d\n", p.first, p.second);
        } else {
            printf("0\n");
        }
    }
    return 0;
}
