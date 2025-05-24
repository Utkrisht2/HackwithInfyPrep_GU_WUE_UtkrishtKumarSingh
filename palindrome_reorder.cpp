/*Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).
Input
The only input line has a string of length n consisting of characters A–Z.
Output
Print a palindrome consisting of the characters of the original string. You may print any valid solution. If there are no solutions, print "NO SOLUTION".
Constraints

1 <= n <= 10^6

Example
Input:
AAAACACBA

Output:
AACABACAA*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    vector<int> freq(26, 0);
    for(auto c : s){
        freq[c - 'A']++;
    }

    int oddcnt = 0;
    int oddIdx = -1;
    for(int i=0; i<26; i++){
        if(freq[i]%2 == 1){
            oddcnt++;
            oddIdx = i;
        }
    }

    if(oddcnt > 1){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }

    string left="", middle="", right="";
    for(int i=0; i<26; i++){
        string part(freq[i]/2, char('A'+i));
        left += part;
        right = part + right;
    }

    if(oddIdx != -1){
        middle = string(freq[oddIdx], char('A' + oddIdx));
    }
    cout<<left+middle+right<<endl;
    return 0;
}