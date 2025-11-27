#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dice[6] = {1, 2, 3, 4, 5, 6};
int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

bool InRange(int r, int c, int n) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

int main() {
    // Please write your code here.
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    vector<vector<int>> grid(n, vector<int>(n));
    r--;
    c--;
    grid[r][c] = dice[5];

    for(int i = 0; i < m; i++) {
        char d;
        cin >> d;
        if(d == 'L' && InRange(r + dr[0], c + dc[0], n)) {
            int temp = dice[0];
            dice[0] = dice[2];
            dice[2] = dice[5];
            dice[5] = dice[3];
            dice[3] = temp;
            r += dr[0];
            c += dc[0];
            grid[r][c] = dice[5];
        }
        else if(d == 'R' && InRange(r + dr[1], c + dc[1], n)) {
            int temp = dice[0];
            dice[0] = dice[3];
            dice[3] = dice[5];
            dice[5] = dice[2];
            dice[2] = temp;
            r += dr[1];
            c += dc[1];
            grid[r][c] = dice[5];
        }
        else if(d == 'U' && InRange(r + dr[2], c + dc[2], n)) {
            int temp = dice[0];
            dice[0] = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[4];
            dice[4] = temp;
            r += dr[2];
            c += dc[2];
            grid[r][c] = dice[5];
        }
        else if(d == 'D' && InRange(r + dr[3], c + dc[3], n)) {
            int temp = dice[0];
            dice[0] = dice[4];
            dice[4] = dice[5];
            dice[5] = dice[1];
            dice[1] = temp;
            r += dr[3];
            c += dc[3];
            grid[r][c] = dice[5];
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] != 0) ans += grid[i][j];
        }
    }
    cout << ans;
    return 0;
}