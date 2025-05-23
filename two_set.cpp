/*Your task is to divide the numbers 1,2,....,n into two sets of equal sum.
Input
The only input line contains an integer n.
Output
Print "YES", if the division is possible, and "NO" otherwise.
After this, if the division is possible, print an example of how to create the sets. First, print the number of elements in the first set followed by the elements themselves in a separate line, and then, print the second set in a similar way.
Constraints

1 <= n <= 10^6

Example 1
Input:
7

Output:
YES
4
1 2 4 7
3
3 5 6
Example 2
Input:
6

Output:
NO*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long total = n * (n + 1) / 2;

    if (total % 2 != 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vector<long long> set1, set2;
        long long sum = 0;
        long long target = total / 2;

        for (long long i = n; i >= 1; --i) {
            if (sum + i <= target) {
                set1.push_back(i);
                sum += i;
            } else {
                set2.push_back(i);
            }
        }

        cout << set1.size() << "\n";
        for (auto num : set1) cout << num << " ";
        cout << "\n";
        cout << set2.size() << "\n";
        for (auto num : set2) cout << num << " ";
        cout << "\n";
    }

    return 0;
}