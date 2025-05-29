/*You are given an n\times m grid where each cell contains one character A, B, C or D.
For each cell, you must change the character to A, B, C or D. The new character must be different from the old one.
Your task is to change the characters in every cell such that no two adjacent cells have the same character.
Input
The first line has two integers n and m: the number of rows and columns.
The next n lines each have m characters: the description of the grid.
Output
Print n lines each with m characters: the description of the final grid.
You may print any valid solution.
If no solution exists, just print IMPOSSIBLE.
Constraints

1 <= n, m <= 500

Example
Input:
3 4
AAAA
BBBB
CCDD

Output:
CDCD
DCDC
ABAB*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
array<char, 4> letters = {'A', 'B', 'C', 'D'};

bool isValid(const vector<string>& result) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (result[i][j] == grid[i][j])
                return false; // character must be changed
            if (i > 0 && result[i][j] == result[i - 1][j])
                return false;
            if (j > 0 && result[i][j] == result[i][j - 1])
                return false;
        }
    return true;
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> grid[i];

    do {
        array<char, 2> even = {letters[0], letters[1]};
        array<char, 2> odd = {letters[2], letters[3]};
        vector<string> result(n, string(m, '.'));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                int parity = (i + j) % 2;
                char c1 = (parity == 0) ? even[0] : odd[0];
                char c2 = (parity == 0) ? even[1] : odd[1];

                // Pick a character different from the original
                result[i][j] = (grid[i][j] != c1) ? c1 : c2;
            }

        if (isValid(result)) {
            for (auto& row : result)
                cout << row << "\n";
            return 0;
        }
    } while (next_permutation(letters.begin(), letters.end()));

    cout << "IMPOSSIBLE\n";
    return 0;
}
