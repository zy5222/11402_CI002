#include<bits/stdc++.h>
using namespace std;
int main(){
 string str;
 vector<string>lines;
 int max = 0;
 while(getline(cin,str)){
  lines.push_back(str);
  if(str.length() > max){
   max = str.length();
  }
 }
 for(int j = 0; j < max; j++){
  for(int i = lines.size() - 1; i >= 0; i--){
   if(lines[i].length() > j){
    cout << lines[i][j];
   }else{
    cout << " ";
   }
  }
  cout << endl;
 }
 
 return 0;
}
