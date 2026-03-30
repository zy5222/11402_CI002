#include<bits/stdc++.h>
using namespace std;
int main(){
 int a, b;
 while(cin >> a >> b && (a != 0 || b != 0)){
  long long int c = 0, t = 0;
  while(a > 0 || b > 0 || c > 0){
   int s = a % 10 + b % 10 + c;
   if(s >= 10){
    t++;
   }
   
   c = s / 10;
   a = a / 10;
   b = b / 10;
  }
  if(t > 1){
   cout << t << " carry operations." << "\n";
  }else if( t == 1){
   cout << t << " carry operation." << "\n";
  }else{
   cout << "No carry operation." << "\n";
  }
 }
 return 0;
}
