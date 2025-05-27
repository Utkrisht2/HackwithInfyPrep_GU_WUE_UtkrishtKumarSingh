/*Consider a two player game where each player has n cards numbered 1,2,\dots,n. On each turn both players place one of their cards on the table. The player who placed the higher card gets one point. If the cards are equal, neither player gets a point. The game continues until all cards have been played.
You are given the number of cards n and the players' scores at the end of the game, a and b. Your task is to give an example of how the game could have played out.
Input
The first line contains one integer t: the number of tests.
Then there are t lines, each with three integers n, a and b.
Output
For each test case print YES if there is a game with the given outcome and NO otherwise.
If the answer is YES, print an example of one possible game. Print two lines representing the order in which the players place their cards. You can give any valid example.
Constraints

1 <= t <= 1000
1 <= n <= 100
0 <= a,b <= n

Example
Input:
5
4 1 2
2 0 1
3 0 0
2 1 1
4 4 1

Output:
YES
1 4 3 2
2 1 3 4
NO
YES
1 2 3
1 2 3
YES
1 2
2 1
NO*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int n, int a, int b) {
    if (a + b > n) {
        cout << "NO\n";
        return;
    }

    vector<int> p1(n), p2(n);
    for (int i = 0; i < n; ++i) {
        p1[i] = i + 1;
        p2[i] = i + 1;
    }

    sort(p1.begin(), p1.end(), greater<int>()); // Player 1: high to low
    sort(p2.begin(), p2.end());                 // Player 2: low to high

    vector<int> final1(n), final2(n);
    int i = 0, j = 0;

    // Assign a wins for player 1
    int a_remaining = a, b_remaining = b;
    for (int k = 0; k < n && a_remaining > 0; ++k) {
        if (p1[i] > p2[j]) {
            final1[k] = p1[i++];
            final2[k] = p2[j++];
            --a_remaining;
        }
    }

    // Assign b wins for player 2
    for (int k = 0; k < n && b_remaining > 0; ++k) {
        if (final1[k] == 0) {
            if (p1[i] < p2[j]) {
                final1[k] = p1[i++];
                final2[k] = p2[j++];
                --b_remaining;
            }
        }
    }

    // Fill remaining slots (draws or unused wins)
    for (int k = 0; k < n; ++k) {
        if (final1[k] == 0) {
            final1[k] = p1[i++];
            final2[k] = p2[j++];
        }
    }

    // Count actual score to verify
    int actual_a = 0, actual_b = 0;
    for (int k = 0; k < n; ++k) {
        if (final1[k] > final2[k]) ++actual_a;
        else if (final2[k] > final1[k]) ++actual_b;
    }

    if (actual_a == a && actual_b == b) {
        cout << "YES\n";
        for (int x : final1) cout << x << " ";
        cout << "\n";
        for (int x : final2) cout << x << " ";
        cout << "\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        solve(n, a, b);
    }
    return 0;
}
