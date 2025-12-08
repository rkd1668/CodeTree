#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, glacier_cnt, ans_t, ans_cnt;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int grid[200][200], visited[200][200];
queue<pair<int, int>> q;

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool CanGo(int x, int y) {
    if(!InRange(x, y)) return false;
    if(visited[x][y] == 1 || grid[x][y] == 1) return false;
    return true; 
}

void BFS() {
    vector<pair<int, int>> water;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }
    visited[0][0] = 1;
    q.push({0, 0});
    water.push_back({0, 0});

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(CanGo(new_x, new_y)) {
                visited[new_x][new_y] = 1;
                q.push({new_x, new_y});
                water.push_back({new_x, new_y});
            }
        }
    }
    int temp_cnt = ans_cnt;
    for(int i = 0; i < water.size(); i++) {
        int x = water[i].first;
        int y = water[i].second;
        for(int j = 0; j < 4; j++) {
            if(InRange(x + dx[j], y + dy[j]) && grid[x + dx[j]][y + dy[j]] == 1) {
                grid[x + dx[j]][y + dy[j]] = 0;
                glacier_cnt--;
                temp_cnt--;
            }
        }
    }
    if(temp_cnt != 0) ans_cnt = temp_cnt;

}

int main() {
    // Please write your code here.
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 1) glacier_cnt++;
        }
    }

    ans_cnt = glacier_cnt;
    while(glacier_cnt > 0) {
        BFS();
        ans_t++;
    }

    cout << ans_t << " " << ans_cnt;
    return 0;
}