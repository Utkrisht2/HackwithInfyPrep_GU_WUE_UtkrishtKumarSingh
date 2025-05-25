/*There are n apples with known weights. Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal.
Input
The first input line has an integer n: the number of apples.
The next line has n integers p_1,p_2,.....,p_n: the weight of each apple.
Output
Print one integer: the minimum difference between the weights of the groups.
Constraints

1 <= n <= 20
1 <= p_i <= 10^9

Example
Input:
5
3 2 7 4 1

Output:
1

Explanation: Group 1 has weights 2, 3 and 4 (total weight 9), and group 2 has weights 1 and 7 (total weight 8).*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> w(n);
    long long total = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        total += w[i];
    }

    long long min_diff = LLONG_MAX;

    // Try all subsets using bitmask
    for (int mask = 0; mask < (1 << n); ++mask) {
        long long group1 = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                group1 += w[i];
            }
        }
        long long group2 = total - group1;
        min_diff = min(min_diff, abs(group1 - group2));
    }

    cout << min_diff << endl;
    return 0;
}