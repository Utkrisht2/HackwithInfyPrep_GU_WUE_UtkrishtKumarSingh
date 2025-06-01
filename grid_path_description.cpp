/*There are 88418 paths in a 7 \times 7 grid from the upper-left square to the lower-left square. Each path corresponds to a 48-character description consisting of characters D (down), U (up), L (left) and R (right).
For example, the path

corresponds to the description DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD.
You are given a description of a path which may also contain characters ? (any direction). Your task is to calculate the number of paths that match the description.
Input
The only input line has a 48-character string of characters ?, D, U, L and R.
Output
Print one integer: the total number of paths.
Example
Input:
??????R??????U??????????????????????????LD????D?

Output:
201
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 7;
string path;
bool visited[N][N];
int result = 0;

// Directions: D, U, L, R
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'D', 'U', 'L', 'R'};

bool inside(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

void dfs(int x, int y, int i) {
    if (x == N - 1 && y == 0) {
        if (i == 48) result++;
        return;
    }

    // Dead-end: early stop
    if ((x == 0 || visited[x - 1][y]) &&
        (x == N - 1 || visited[x + 1][y]) &&
        (y == 0 || visited[x][y - 1]) &&
        (y == N - 1 || visited[x][y + 1]))
        return;

    visited[x][y] = true;

    char expected = path[i];
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (inside(nx, ny) && !visited[nx][ny] && (expected == '?' || expected == dir[d])) {
            dfs(nx, ny, i + 1);
        }
    }

    visited[x][y] = false;
}

int main() {
    cin >> path;
    dfs(0, 0, 0);
    cout << result << "\n";
    return 0;
}
