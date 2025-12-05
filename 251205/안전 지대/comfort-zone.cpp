#include <iostream>
#include <vector>
using namespace std;

int n, m;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
vector<vector<int>> grid;
vector<vector<int>> visited;
bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool CanGo(int x, int y, int k) {
    if(!InRange(x, y)) return false;
    if(grid[x][y] <= k || visited[x][y] == 1) return false;
    return true;
}

void DFS(int x, int y, int k) {
    
    for(int i = 0; i < 4; i++) {
        int next_x = x + dx[i], next_y = y + dy[i];
        if(CanGo(next_x, next_y, k)) {
            visited[next_x][next_y] = 1;
            DFS(next_x, next_y, k);
        }
    }
}

int main() {
    // Please write your code here.
    int k_max = 0;
    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    visited.resize(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(k_max < grid[i][j]) k_max = grid[i][j];
        }
    }

    int ans_k = 0;
    int ans_cnt = 0;
    for(int k = 1; k <= k_max; k++) {
        visited = vector<vector<int>>(n, vector<int>(m, 0));
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(CanGo(i, j, k)) {
                    visited[i][j] = 1;
                    DFS(i, j, k);
                    cnt++;
                }
                if(cnt > ans_cnt) {
                    ans_cnt = cnt;
                    ans_k = k;
                }
            }
        }
    }

    cout << ans_k << " " << ans_cnt;
    return 0;
}