/*Your task is to reorder the characters of a string so that no two adjacent characters are the same. What is the lexicographically minimal such string?
Input
The only line has a string of length n consisting of characters A–Z.
Output
Print the lexicographically minimal reordered string where no two adjacent characters are the same. If it is not possible to create such a string, print -1.
Constraints

1 <= n <= 10^6

Example
Input:
HATTIVATTI

Output:
AHATITITVT*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> freq(26, 0);

    for (char c : s) freq[c - 'A']++;

    // Check if it's possible
    for (int f : freq) {
        if (f > (n + 1) / 2) {
            cout << -1 << endl;
            return 0;
        }
    }

    string result = "";
    char prev = 0;

    for (int i = 0; i < n; ++i) {
        // Try to find the smallest lexicographic character that's valid
        bool found = false;
        for (int c = 0; c < 26; ++c) {
            if (freq[c] == 0) continue;
            if (prev == 'A' + c) continue;

            // Tentatively choose this char
            freq[c]--;
            bool ok = true;

            // Check future feasibility: no count > (remaining+1)/2
            int remaining = n - i - 1;
            for (int f : freq) {
                if (f > (remaining + 1) / 2) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                result += char('A' + c);
                prev = char('A' + c);
                found = true;
                break;
            }

            // backtrack
            freq[c]++;
        }

        if (!found) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << result << endl;
    return 0;
}
