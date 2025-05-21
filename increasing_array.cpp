/*You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.
On each move, you may increase the value of any element by one. What is the minimum number of moves required?
Input
The first input line contains an integer n: the size of the array.
Then, the second line contains n integers x_1,x_2,\ldots,x_n: the contents of the array.
Output
Print the minimum number of moves.
Constraints

1 <= n <= 2*10^5
1 <= xi <= 10^9

Example
Input:
5
3 2 5 1 7

Output:
5*/

#include<bits/stdc++.h>
using namespace std;

void increasingArray(int n, vector<int>& arr1){
    int cnt = 0;

    for(int i=1; i<n; i++){
        if(arr1[i]<arr1[i-1]){
            cnt += arr1[i-1] - arr1[i];
            arr1[i] = arr1[i-1];
        }
    }
    cout<<cnt<<endl;
}

int main(){
    int n;
    cout<<"Enter the no :"<<" ";
    cin>>n;

    vector<int> arr1(n);
    for(int i=0; i<n; i++){
        cin>>arr1[i];
    }

    increasingArray(n, arr1);

    return 0;
}