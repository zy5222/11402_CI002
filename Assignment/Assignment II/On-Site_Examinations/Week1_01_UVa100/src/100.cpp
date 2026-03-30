#include<bits/stdc++.h>
using namespace std;

int alg(int n){
 int length = 1;
 while(n != 1){
  if(n % 2 == 1){
   n = 3 * n + 1;
  }else{
   n = n / 2;
  }
  length++;
 }
 return length;
}

int main(){
 int a, b;
 while(cin >> a >> b){
  cout << a << " " << b << " " ;
  if(a > b){
   swap(a, b);
  }
  int max_leng = 0;
  for(int i = a; i <= b; i++){
   int current_leng = alg(i);
   max_leng = max(current_leng, max_leng);
  }
  cout << max_leng << endl; 
 }
 return 0;
}
