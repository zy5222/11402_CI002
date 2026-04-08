#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,l;
	cin >> n;
	while(n > 0){
		cin >> l;
		
		vector<int> train(l);
		int t = 0;
		
		for(int i = 0; i < l; i++){
			cin >> train[i]; 
		}
		for(int i = 0; i < l; i++){
			for(int j = 0; j < (l - i)- 1; j++){
				if(train[j] > train[j + 1]){
					swap(train[j],train[j + 1]);
					t++;
				}
			}
		}
		cout << "Optimal train swapping takes " << t << " swaps." << endl; 
		n--;
	}
	return 0;
}
