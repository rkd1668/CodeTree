#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool InRange(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
    // Please write your code here.
    int n, m, t;
    cin >> n >> m >> t;
    vector<tuple<int, int, int>> grid[50][50];
    for(int i = 0; i < m; i++) {
        int r, c, w, dir;
        char d;
        cin >> r >> c >> d >> w;
        if (d == 'U') dir = 0;
        else if (d == 'D') dir = 3;
        else if (d == 'R') dir = 2;
        else dir = 1;
        grid[r - 1][c - 1].push_back(make_tuple(-(i + 1), w, dir));
    }

    for(int i = 0; i < t; i++) {
        vector<tuple<int, int, int>> next_grid[50][50];
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(grid[j][k].size() < 1) continue;
                int num, w, d;
                tie(num, w, d) = grid[j][k][0];
                int next_r = j, next_c = k;
                if(!InRange(j + dx[d], k + dy[d], n)) d = 3 - d;
                else {
                    next_r = j + dx[d];
                    next_c = k + dy[d];
                }
                next_grid[next_r][next_c].push_back(make_tuple(num, w, d));
            }
        }
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                grid[j][k] = next_grid[j][k];
            }
        }

        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(grid[j][k].size() > 1) {
                    sort(grid[j][k].begin(), grid[j][k].end());
                    int size = grid[j][k].size();
                    int w_sum = 0;
                    while(grid[j][k].size() > 1) {
                        int num, w, d;
                        tie(num, w, d) = grid[j][k].back();
                        w_sum += w;
                        grid[j][k].pop_back();
                    }
                    int num, w, d;
                    tie(num, w, d) = grid[j][k][0];
                    w_sum += w;
                    grid[j][k][0] = make_tuple(num, w_sum, d);
                }
            }
        }
    }

    int cnt = 0;
    int max_w = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j].size() != 0) {
                cnt++;
                int num, w, d;
                tie(num, w, d) = grid[i][j][0];
                if(max_w < w) max_w = w;
            }
        }
    }

    cout << cnt << " " << max_w;
    return 0;
}