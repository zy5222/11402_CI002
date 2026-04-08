#include<bits/stdc++.h>
using namespace std;

int main(){
 string str;
 bool open = true;
 while(getline(cin,str)){
  for(int i = 0; i < str.length(); i++){
   char ch = str[i];
   if(ch == '"'){
    if(open){
     cout << "``";
    }else{
     cout << "''";
    }
    open = !open;
   }else{
    cout << ch;
   }
  }
  cout << endl;
 }
 return 0;
}
