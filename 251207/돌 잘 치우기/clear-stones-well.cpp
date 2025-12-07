#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, m, ans;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int grid[100][100], visited[100][100], temp_grid[100][100];
vector<pair<int, int>> stone;
vector<pair<int, int>> selected_stone;
vector<pair<int, int>> starts;
queue<pair<int, int>> q;

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool CanGo(int x, int y) {
    if(!InRange(x, y)) return false;
    if(temp_grid[x][y] == 1) return false;
    if(visited[x][y] == 1) return false;
    return true;
}

void BFS() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }

    int cnt = 0;

    for(int i = 0; i < starts.size(); i++) {
        int x = starts[i].first;
        int y = starts[i].second;
        if(temp_grid[x][y] == 0 && visited[x][y] == 0) {
            visited[x][y] = 1;
            q.push({x, y});
            cnt++;
        }
    }

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
                cnt++;
            }
        }
    }

    if(ans < cnt) ans = cnt;
}

void ChooseStone(int num, int cnt) {
    if(cnt == m) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                temp_grid[i][j] = grid[i][j];
            }
        }

        for(int i = 0; i < selected_stone.size(); i++) {
            int x = selected_stone[i].first;
            int y = selected_stone[i].second;
            temp_grid[x][y] = 0;
        }

        BFS();
        return;
    } 

    if(num >= stone.size()) return;

    for(int i = num; i < stone.size(); i++) {
        selected_stone.push_back(stone[i]);
        ChooseStone(i + 1, cnt + 1);
        selected_stone.pop_back();
    }
}

int main() {
    // Please write your code here.
    cin >> n >> k >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 1) {
                stone.push_back({i, j});
            }
        }
    }

    for(int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        starts.push_back({r - 1, c - 1});
    }

    ChooseStone(0, 0);

    cout << ans;

    return 0;
}