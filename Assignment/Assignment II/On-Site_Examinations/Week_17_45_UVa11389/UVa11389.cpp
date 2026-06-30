#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    int caseNo = 1;
    while(T--){
        int n;
        scanf("%d", &n);
        vector<long long> S(n), D(n);
        for(int i = 0; i < n; i++) scanf("%lld", &S[i]);
        for(int i = 0; i < n; i++) scanf("%lld", &D[i]);

        sort(S.begin(), S.end());
        sort(D.begin(), D.end());

        long long total = 0;
        for(int i = 0; i < n; i++){
            long long mx = max(S[i], D[i]);
            long long diff = llabs(S[i] - D[i]);
            total += mx + 2 * diff;
        }

        printf("Case %d: %lld\n", caseNo++, total);
    }
    return 0;
}
