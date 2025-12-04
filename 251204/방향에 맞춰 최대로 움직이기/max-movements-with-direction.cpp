#include <iostream>
#include <vector>
using namespace std;

int n;
int r, c, ans;
int dr[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1}, dc[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
vector<vector<int>> grid;
vector<vector<int>> direction;

bool InRange(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

void Move(int r, int c, int cnt) {
    if(ans < cnt) ans = cnt;
    int next_r = r + dr[direction[r][c]];
    int next_c = c + dc[direction[r][c]];
    if(!InRange(next_r, next_c)) {
        return;
    }

    while(InRange(next_r, next_c)) {
        if(grid[r][c] < grid[next_r][next_c]) {
            Move(next_r, next_c, cnt + 1);
        }
        next_r += dr[direction[r][c]];
        next_c += dc[direction[r][c]];
    }
}

int main() {
    // Please write your code here.
    cin >> n;
    grid.resize(n, vector<int>(n));
    direction.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> direction[i][j];
        }
    }
    cin >> r >> c;
    Move(r - 1, c - 1, 0);
    cout << ans;
    return 0;
}