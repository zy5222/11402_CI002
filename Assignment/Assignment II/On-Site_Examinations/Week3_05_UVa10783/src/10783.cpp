#include<bits/stdc++.h>
using namespace std;
int main(){
 int n;
 cin >> n;
 for(int i = 1; i <= n; i++){
  int a, b;
  cin >> a >> b;
  int total = 0;
  for(int j = a; j <= b; j++){
   if(j % 2 == 1){
    total = total + j;
   }else{
    continue;
   }
  }
  cout << "Case " << i << ": " << total << "\n";
 }
 return 0;
}
