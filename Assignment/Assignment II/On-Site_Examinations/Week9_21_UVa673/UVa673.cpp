#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isBalanced(const string& s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[') {
            st.push(c);
        } else if (c == ')') {
            if (st.empty() || st.top() != '(') return false;
            st.pop();
        } else if (c == ']') {
            if (st.empty() || st.top() != '[') return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    int n;
    if (cin >> n) {
        cin.ignore(); 
        
        while (n--) {
            string s;
            getline(cin, s);
            
            if (isBalanced(s)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
    return 0;
}
