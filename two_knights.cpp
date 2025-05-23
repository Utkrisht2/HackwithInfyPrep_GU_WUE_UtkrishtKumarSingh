/*Your task is to count for k=1,2,\ldots,n the number of ways two knights can be placed on a k \times k chessboard so that they do not attack each other.
Input
The only input line contains an integer n.
Output
Print n integers: the results.
Constraints

1 <= n <= 10000

Example
Input:
8

Output:
0
6
28
96
252
550
1056
1848*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter Number :"<<" ";
    cin>>n;

    for(int k=1; k<=n; k++){
        long long totalPosition = (k*k)*(k*k-1)/2;
        long long attackingPosition = 0;
        if(k > 2){
            attackingPosition = 4*(k-1)*(k-2);
        }
        cout<<totalPosition-attackingPosition<<endl;
    }
    return 0;
}