#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int n, k, r1, c1, r2, c2;
int ans = INT_MAX;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int grid[100][100], visited[100][100], temp_grid[100][100];
vector<pair<int, int>> wall, selected_wall;
queue<pair<int, int>> q;

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool CanGo(int x, int y) {
    if(!InRange(x, y)) return false;
    if(visited[x][y] == 1 || temp_grid[x][y] == 1) return false;
    return true;
}

void BFS() {
    int temp_ans[100][100] = {0, };
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            visited[i][j] = 0;
            temp_grid[i][j] = grid[i][j];
        }
    }
    for(int i = 0; i < selected_wall.size(); i++) {
        int x = selected_wall[i].first;
        int y = selected_wall[i].second;
        temp_grid[x][y] = 0;
    }
    while(!q.empty()) {
        q.pop();
    }
    visited[r1][c1] = 1;
    q.push({r1, c1});

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(CanGo(new_x, new_y)) {
                visited[new_x][new_y] = 1;
                temp_ans[new_x][new_y] = temp_ans[x][y] + 1;
                q.push({new_x, new_y});
                if(visited[r2][c2] == 1 && ans > temp_ans[r2][c2]) {
                    ans = temp_ans[r2][c2];
                    return;
                } 
            }
        }
    }
}

void SelectWall(int cnt, int idx) {
    if(cnt == k) {
        BFS();
        return;
    }

    for(int i = idx; i < wall.size(); i++) {
        selected_wall.push_back(wall[i]);
        SelectWall(cnt + 1, i + 1);
        selected_wall.pop_back();
    }
}

int main() {
    // Please write your code here.
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 1) wall.push_back({i, j});
        }
    }

    cin >> r1 >> c1 >> r2 >> c2;
    r1--; c1--; r2--; c2--;
    SelectWall(0, 0);

    if(ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}