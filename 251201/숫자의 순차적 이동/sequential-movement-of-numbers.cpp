#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool InRange(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

pair<int, int> GetPos(vector<vector<int>> grid, int x, int y, int n) {
    int num = 0;
    int next_x, next_y;
    for(int i = 0; i < 8; i++) {
        if(InRange(x + dx[i], y + dy[i], n) && num < grid[x + dx[i]][y + dy[i]]) {
            num = grid[x + dx[i]][y + dy[i]];
            next_x = x + dx[i];
            next_y = y + dy[i];
        } 
    }
    return make_pair(next_x, next_y);
}

int main() {
    // Please write your code here.
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(n));
    vector<pair<int, int>> num_pos(n * n + 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
            num_pos[grid[i][j]] = make_pair(i, j);
        }
    }
    
    for(int i = 0; i < m; i++) {
        for(int j = 1; j <= n * n; j++) {
            int x = num_pos[j].first, y = num_pos[j].second;
            pair<int, int> next_pos = GetPos(grid, x, y, n);
            swap(num_pos[grid[x][y]], num_pos[grid[next_pos.first][next_pos.second]]);
            swap(grid[x][y], grid[next_pos.first][next_pos.second]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}