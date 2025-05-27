/*Your task is to construct an n \times n grid where each square has the smallest nonnegative integer that does not appear to the left on the same row or above on the same column.
Input
The only line has an integer n.
Output
Print the grid according to the example.
Constraints

1 <= n <= 100

Example
Input:
5

Output:
0 1 2 3 4
1 0 3 2 5
2 3 0 1 6
3 2 1 0 7
4 5 6 7 0*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> grid(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            set<int> used;

            // Elements to the left in the same row
            for (int k = 0; k < j; ++k)
                used.insert(grid[i][k]);

            // Elements above in the same column
            for (int k = 0; k < i; ++k)
                used.insert(grid[k][j]);

            // Find the smallest non-negative integer not in 'used'
            int x = 0;
            while (used.count(x)) ++x;
            grid[i][j] = x;
        }
    }

    // Output the grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << grid[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
