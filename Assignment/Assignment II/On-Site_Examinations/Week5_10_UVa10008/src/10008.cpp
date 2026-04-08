#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a,l = 0;
	int code[26] = {};
	string str;
	cin >> n;
	cin.ignore();
	for(int i = 0; i < n; i++){
		getline(cin,str);
		for(int j = 0; j < str.length(); j++){
			a = -1;
			if(str[j] >= 'a' && str[j] <= 'z'){
				a = str[j] - 'a';
			}else if(str[j] >= 'A' && str[j] <= 'Z'){
				a = str[j] - 'A';
		    }
		    if(a != -1){
				l++;
				code[a]++;
			}
    	}
	}
		for(int j = l;j >= 1; j--){
			for(int i = 0; i < 26; i++){
				if(code[i] == j){
					cout << (char)(i + 'A') << " " << code[i] << endl;
				}
			}
		}
	return 0;
}
