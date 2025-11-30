#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

bool InRange(int r, int c, int n) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

int main() {
    // Please write your code here.
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> count(n, vector<int>(n));
    for(int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        count[r - 1][c - 1] = 1;
    }

    for(int i = 0; i < t; i++) {
        vector<vector<int>> next_count(n, vector<int>(n));
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                if(count[r][c] != 0) {
                    int max_num = 0;
                    for(int d = 0; d < 4; d++) {
                        if(InRange(r + dx[d], c + dy[d], n)) {
                            if(max_num < grid[r + dx[d]][c + dy[d]]) max_num = grid[r + dx[d]][c + dy[d]];
                        }
                    }
                    for(int d = 0; d < 4; d++) {
                        if(InRange(r + dx[d], c + dy[d], n)) {
                            if(max_num == grid[r + dx[d]][c + dy[d]]) {
                                next_count[r + dx[d]][c + dy[d]]++;
                                break;
                            }
                        }
                    }
                }
            }
        }

        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                if(next_count[r][c] > 1) next_count[r][c] = 0;
            }
        }
        count = next_count;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(count[i][j] != 0) ans++;
        }
    }
    cout << ans;
    return 0;
}