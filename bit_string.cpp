/*Your task is to calculate the number of bit strings of length n.
For example, if n=3, the correct answer is 8, because the possible bit strings are 000, 001, 010, 011, 100, 101, 110, and 111.
Input
The only input line has an integer n.
Output
Print the result modulo 10^9+7.
Constraints

1 <= n <= 10^6

Example
Input:
3

Output:
8*/

#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;

ll power(ll base, ll exp){
    ll res = 1;
    base %= MOD;

    while(exp > 0){
        if(exp%2 == 1){
            res = (base * res)%MOD;
        }
        base = (base*base)%MOD;
        exp /= 2;
    }
    return res;
}
int main(){
    int n;
    cout<<"Enter the no. :"<<" ";
    cin>>n;

    cout<<power(2, n)<<endl;
}