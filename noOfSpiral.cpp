/*A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral:

Your task is to find out the number in row y and column x.
Input
The first input line contains an integer t: the number of tests.
After this, there are t lines, each containing integers y and x.
Output
For each test, print the number in row y and column x.
Constraints

1 <= t <= 10^5
1 <= y,x <= 10^9

Example
Input:
3
2 3
1 1
4 2

Output:
8
1
15*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cout<<"Enter Testcase : "<<" ";
    cin>>t;

    while(t--){
        long long y, x;
        cout<<"Enter row :"<<" ";
        cin>>y;
        cout<<"Enter column :"<<" ";
        cin>>x;

        long long n = max(x, y);
        long long ans;

        if(n%2 == 0){
            if(y==n){
                ans = (n*n)-x+1;
            }
            else{
                ans = (n-1)*(n-1)+y;
            }
        }
        else{
            if(x==n){
                ans = (n*n)-y+1;
            }
            else{
                ans = (n-1)*(n-1)+x;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}