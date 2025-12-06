#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

vector<vector<int>> grid;
vector<vector<int>> visited;
queue<pair<int, int>> q;

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool CanGo(int x, int y) {
    if(!InRange(x, y)) return false;
    if(visited[x][y] == 1 || grid[x][y] == 1) return false;
    return true;
}

void BFS() {

    while(!q.empty()) {
        pair<int, int> curr_pos = q.front();
        q.pop();

        int x = curr_pos.first;
        int y = curr_pos.second;
        visited[x][y] = 1;
        for(int i = 0; i < 4; i++) {
            int next_x = x + dx[i], next_y = y + dy[i];
            if(CanGo(next_x, next_y)) {
                q.push(make_pair(next_x, next_y));
            }
        }
    }
}
int main() {
    // Please write your code here.
    cin >> n >> k;
    grid.resize(n, vector<int>(n));
    visited.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        q.push(make_pair(r, c));
        BFS();
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(visited[i][j] == 1) ans++;
        }
    }

    cout << ans;
    return 0;
}