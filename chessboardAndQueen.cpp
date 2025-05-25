/*Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

How many possible ways are there to place the queens?

Input
The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (*).

Output
Print one integer: the number of ways you can place the queens.

Example
Input:

........
........
..*.....
........
........
.....**.
...*....
........
Output:

65*/

#include <iostream>
#include <vector>
using namespace std;

vector<string> board(8);
bool columns[8], diag1[15], diag2[15];
int count = 0;

void solve(int row) {
    if (row == 8) {
        count++;
        return;
    }

    for (int col = 0; col < 8; ++col) {
        if (board[row][col] == '*') continue;
        if (columns[col] || diag1[row + col] || diag2[row - col + 7]) continue;

        columns[col] = diag1[row + col] = diag2[row - col + 7] = true;
        solve(row + 1);
        columns[col] = diag1[row + col] = diag2[row - col + 7] = false;
    }
}

int main() {
    for (int i = 0; i < 8; ++i) {
        cin >> board[i];
    }

    solve(0);
    cout << count << endl;
    return 0;
}
