/*There is a knight on an n \times n chessboard. For each square, print the minimum number of moves the knight needs to do to reach the top-left corner.
Input
The only line has an integer n.
Output
Print the number of moves for each square.
Constraints

4 <= n <= 1000

Example
Input:
8

Output:
0 3 2 3 2 3 4 5 
3 4 1 2 3 4 3 4 
2 1 4 3 2 3 4 5 
3 2 3 2 3 4 3 4 
2 3 2 3 4 3 4 5 
3 4 3 4 3 4 5 4 
4 3 4 3 4 5 4 5 
5 4 5 4 5 4 5 6 
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    // 8 possible moves of a knight
    vector<pair<int, int>> moves = {
        {-2, -1}, {-1, -2}, {-2, 1}, {-1, 2},
        {1, -2},  {2, -1},  {1, 2},  {2, 1}
    };

    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int, int>> q;

    dist[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        pair<int, int> current = q.front(); q.pop();
        int x = current.first;
        int y = current.second;
        for (size_t i = 0; i < moves.size(); ++i) {
            int dx = moves[i].first;
            int dy = moves[i].second;
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    // Print the result
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << dist[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
