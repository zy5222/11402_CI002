# UVa 272 -  TEX Quotes

## Problem Description
[<img width="1209" height="846" alt="image" src="https://github.com/user-attachments/assets/37030b58-ca8a-485a-8a52-13fbed45df03" />
](https://onlinejudge.org/external/2/272.pdf)

## Learning Objectives
* Understand character-by-character string processing.
* Implement state-tracking logic using a boolean flag.
* Practice standard I/O in C++, specifically reading full lines of text including spaces.

## Solution Approach

### Algorithm Logic
1. Initialize a boolean variable `open` to `true`. This acts as a state tracker to determine whether the next encountered quote is an opening quote or a closing quote.
2. Use a `while` loop with `getline(cin, str)` to read the input line by line until the end of the file (EOF) is reached.
3. Iterate through each character of the current string `str` using a `for` loop.
4. Condition Check:
   * If the character is a double quote (`"`):
     * If `open` is `true`, output two backticks ( ` `` `).
     * If `open` is `false`, output two single quotes (`''`).
     * Toggle the `open` state (`open = !open`).
5. After processing all characters in the string, output a newline (`cout << endl;`) to maintain the original formatting of the text.

### Key Insights
* **Global State Tracking**: The boolean variable `open` must be declared outside the `while` loop. This is crucial because a single quoted phrase might span across multiple lines, so the state needs to persist between `getline` iterations.
* **Preserving Whitespace**: Using `getline()` instead of `cin >>` ensures that spaces and empty lines are read and processed correctly without being skipped.
   
## Code Structure
```
//272
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
```

## Complexity Analysis
* Time Complexity: $O(N)$, where $N$ is the total number of characters in the input file. Every character is processed exactly once inside the nested loop structure.
* Space Complexity: $O(L)$, where $L$ is the maximum length of a single line in the input. This is because the str variable stores exactly one line of text in memory at any given time.

## Notes & Reflection
* **What challenges did you face?** Managing the state of the quotes properly when a quoted sentence breaks across multiple lines.
* **How would you improve this solution?** While <bits/stdc++.h> is convenient for competitive programming, it includes many unnecessary libraries. For cleaner code, explicitly including <iostream> and <string> is generally considered a better practice.
*  **What did you learn?** How to effectively use a boolean flag to toggle behaviors and safely iterate through strings in C++.

## References
* **Problem Link**: [UVA 272 - TEX Quotes](https://onlinejudge.org/external/2/272.pdf)
* **Related concepts**: Boolean flags, string manipulation, getline.
