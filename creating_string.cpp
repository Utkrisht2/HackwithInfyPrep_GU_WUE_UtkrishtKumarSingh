/*Given a string, your task is to generate all different strings that can be created using its characters.
Input
The only input line has a string of length n. Each character is between a–z.
Output
First print an integer k: the number of strings. Then print k lines: the strings in alphabetical order.
Constraints

1 <= n <= 8

Example
Input:
aabac

Output:
20
aaabc
aaacb
aabac
aabca
aacab
aacba
abaac
abaca
abcaa
acaab
acaba
acbaa
baaac
baaca
bacaa
bcaaa
caaab
caaba
cabaa
cbaaa*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    set<string> permutation;

    sort(s.begin(), s.end());

    do {
        permutation.insert(s);
    }    
    while(next_permutation(s.begin(), s.end()));

    cout<<permutation.size()<<endl;
    for(const string& p : permutation){
        cout<<p<<endl;
    }
    return 0;
}