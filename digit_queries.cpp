/*Consider an infinite string that consists of all positive integers in increasing order:
12345678910111213141516171819202122232425...
Your task is to process q queries of the form: what is the digit at position k in the string?
Input
The first input line has an integer q: the number of queries.
After this, there are q lines that describe the queries. Each line has an integer k: a 1-indexed position in the string.
Output
For each query, print the corresponding digit.
Constraints

1 <= q <= 1000
1 <= k <= 10^{18}

Example
Input:
3
7
19
12

Output:
7
4
1*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

char find_digit(ll k) {
    ll digits = 1;
    ll count = 9;
    ll start = 1;

    // Step 1: find which digit length range the k-th digit falls into
    while (k > digits * count) {
        k -= digits * count;
        digits++;
        count *= 10;
        start *= 10;
    }

    // Step 2: find the exact number and digit
    ll number = start + (k - 1) / digits;
    int digit_index = (k - 1) % digits;
    string s = to_string(number);
    return s[digit_index];
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;
        cout << find_digit(k) << '\n';
    }
    return 0;
}
