#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> grid;
vector<vector<int>> visited;

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int ans_cnt, ans_size;

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool CanGo(int x, int y, int num) {
    if(!InRange(x, y) || visited[x][y] == 1) return false;
    if(grid[x][y] != num) return false;
    return true;
}

void DFS(int x, int y, int &cnt) {
    if(cnt == 4) ans_cnt++;
    if(ans_size < cnt) ans_size = cnt;
    for(int i = 0; i < 4; i++) {
        int next_x = x + dx[i], next_y = y + dy[i];
        if(CanGo(next_x, next_y, grid[x][y])) {
            visited[next_x][next_y] = 1;
            cnt++;
            
            DFS(next_x, next_y, cnt);
        }
    }
}
int main() {
    // Please write your code here.
    cin >> n;
    grid.resize(n, (vector<int>(n)));
    visited.resize(n, (vector<int>(n)));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int cnt = 1;
            if(CanGo(i, j, grid[i][j])) {
                visited[i][j] = 1;
                DFS(i, j, cnt);
            }
        }
    }

    cout << ans_cnt << " " << ans_size;
    return 0;
}