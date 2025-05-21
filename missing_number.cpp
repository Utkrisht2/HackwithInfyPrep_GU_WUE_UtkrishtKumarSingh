/*You are given all numbers between 1,2,\ldots,n except one. Your task is to find the missing number.
Input
The first input line contains an integer n.
The second line contains n-1 numbers. Each number is distinct and between 1 and n (inclusive).
Output
Print the missing number.
Constraints

2 \le n \le 2 \cdot 10^5

Example
Input:
5
2 3 1 5

Output:
4*/

#include<bits/stdc++.h>
using namespace std;

void missingNumber(int n, vector<int>& arr){
    // First Approch
    // for(int i=0; i<arr.size(); i++){
    //     if(arr[i] != i+1){
    //         cout<<i+1<<endl;
    //         return;
    //     }
    // }
    // cout<<n<<endl;

    //Second Approch
    int total = n*(n+1)/2;
    int sum = accumulate(arr.begin(), arr.end(), 0);

    cout<<total-sum<<endl;
}
int main(){
    int n;
    cin>>n;

    vector<int> arr(n-1);
    for(int i=0; i<n-1; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    missingNumber(n, arr);

    return 0;
}