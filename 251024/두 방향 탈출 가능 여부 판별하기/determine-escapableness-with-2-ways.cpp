#include <iostream>

using namespace std;

int n, m;
int grid[100][100];
int visited[100][100];
bool success;

int dx[2] = {1, 0}, dy[2] = {0, 1};

bool InRange(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

bool CanGo(int x, int y) {
    if(!InRange(x , y)) return false;
    if(visited[x][y] || grid[x][y] == 0) return false;
    return true;
}

void DFS(int x, int y) {
    for(int i = 0; i < 2; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if(CanGo(next_x, next_y)) {
            if(next_x == n - 1 && next_y == m - 1) {
                success = true;
                return;
            }
            visited[next_x][next_y] = 1;
            DFS(next_x, next_y);
        }
    }
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    visited[0][0] = 1;
    DFS(0, 0);

    if(success) cout << 1;
    else cout << 0;
    return 0;
}
