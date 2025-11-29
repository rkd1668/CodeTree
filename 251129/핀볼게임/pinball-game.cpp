#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

bool InRange(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int ChangeDir(vector<vector<int>> grid, int x, int y, int d) {
    int dir = d;
    if(d == 0) {
        if(grid[x][y] == 1) dir = 3;
        if(grid[x][y] == 2) dir = 2;
    }
    else if(d == 1) {
        if(grid[x][y] == 1) dir = 2;
        if(grid[x][y] == 2) dir = 3;
    }
    else if(d == 2) {
        if(grid[x][y] == 1) dir = 1;
        if(grid[x][y] == 2) dir = 0;
    }
    else {
        if(grid[x][y] == 1) dir = 0;
        if(grid[x][y] == 2) dir = 1;
    }
    return dir;
}

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    for(int d = 0; d < 4; d++) {
        for(int p = 0; p < n; p++) {
            int dir = d;
            int t = 1;
            int x, y;
            if(d == 0) {
                x = n - 1, y = p;
            }
            else if(d == 1) {
                x = 0, y = p;
            }
            else if(d == 2) {
                x = p, y = n - 1;
            }
            else {
                x = p, y = 0;
            }
            dir = ChangeDir(grid, x, y, dir);

            while(true) {
                t++;
                int next_x = x + dx[dir], next_y = y + dy[dir];
                if(InRange(next_x, next_y, n)) {
                    x = next_x;
                    y = next_y;
                    dir = ChangeDir(grid, x, y, dir);
                }
                else break;
            }
            if(t > ans) ans = t;
        }
    }

    cout << ans;
    return 0;
}