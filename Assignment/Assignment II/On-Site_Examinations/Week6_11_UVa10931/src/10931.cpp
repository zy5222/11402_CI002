#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n && n > 0){
		string binary = "";
		int parity = 0;
		while(n > 0){
			int bit = n % 2;
			binary += to_string(bit);
			if(bit == 1){
				parity++;
			}
			n /= 2;
		}
		reverse(binary.begin(),binary.end());
		cout << "The parity of " << binary << " is " << parity << " (mod 2)." << endl;
	}
	return 0;
}
