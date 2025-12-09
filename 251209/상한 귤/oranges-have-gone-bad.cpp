#include <iostream>
#include <queue>
using namespace std;

int n, k;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int grid[100][100], ans[100][100], visited[100][100];
queue<pair<int, int>> q;

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool CanGo(int x, int y) {
    // if(!InRange(x, y)) return false;
    // if(grid[x][y] != 1 || visited[x][y] == 1) return false;
    // return true;
    return InRange(x, y) && grid[x][y] == 1 && visited[x][y] == 0;
}

void BFS() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(CanGo(new_x, new_y)) {
                visited[new_x][new_y] = 1;
                ans[new_x][new_y] = ans[x][y] + 1;
                q.push({new_x, new_y});
            }
        }

    }
}

int main() {
    // Please write your code here.
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 0) ans[i][j] = -1;
            if(grid[i][j] == 2) {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }
    
    BFS();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(ans[i][j] == 0 && grid[i][j] == 1) cout << -2 << " ";
            else cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}