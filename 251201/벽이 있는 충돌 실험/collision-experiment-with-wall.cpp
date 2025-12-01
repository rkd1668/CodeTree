#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[5] = {0, -1, 0, 0, 1}, dy[5] = {0, 0, -1, 1, 0};

bool InRange(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
    // Please write your code here.
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n,(vector<int>(n)));
        vector<vector<int>> count(n,(vector<int>(n)));
        for(int j = 0; j < m; j++) {
            int x, y, dir;
            char d;
            cin >> x >> y >> d;
            if(d == 'U') dir = 1;
            else if(d == 'D') dir = 4;
            else if(d == 'R') dir = 3;
            else dir = 2;
            grid[x - 1][y - 1] = dir;
            count[x - 1][y - 1] = 1;
        }

        for(int j = 0; j < n * 2; j++) {
            vector<vector<int>> next_grid(n,(vector<int>(n)));
            vector<vector<int>> next_count(n,(vector<int>(n)));
            for(int x = 0; x < n; x++) {
                for(int y = 0; y < n; y++) {
                    int next_x = x + dx[grid[x][y]];
                    int next_y = y + dy[grid[x][y]];
                    if(grid[x][y] != 0) {
                        if(InRange(next_x, next_y, n)) {
                            next_grid[next_x][next_y] = grid[x][y];
                            next_count[next_x][next_y]++;
                        }
                        else {
                            next_grid[x][y] = 5 - grid[x][y];
                            next_count[x][y]++;
                        }
                    }
                }
            }

            for(int x = 0; x < n; x++) {
                for(int y = 0; y < n; y++) {
                    if(next_count[x][y] > 1) {
                        next_grid[x][y] = 0;
                        next_count[x][y] = 0;
                    }
                }
            }

            grid = next_grid;
            count = next_count;
        }


        int ans = 0;
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(grid[j][k] != 0) ans++;
            }
        }
        cout << ans << endl;
    }


    return 0;
}