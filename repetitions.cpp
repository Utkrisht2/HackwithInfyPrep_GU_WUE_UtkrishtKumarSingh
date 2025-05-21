/*You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.
Input
The only input line contains a string of n characters.
Output
Print one integer: the length of the longest repetition.
Constraints

1 <= n <= 10^6

Example
Input:
ATTCGGGA

Output:
3*/

#include<bits/stdc++.h>
using namespace std;

void repetition(string s){
    int n = s.length();
    int maxcnt = 0;
    int cnt = 0;
    for(int i=1; i<n; i++){
        if(s[i] == s[i-1]){
            cnt++;
            maxcnt = max(maxcnt, cnt); 
        }
        else{
            cnt = 0;
        }
    }
    cout<<maxcnt+1<<endl;
}

int main(){
    string s;
    cin>>s;

    repetition(s);

    return 0;
}