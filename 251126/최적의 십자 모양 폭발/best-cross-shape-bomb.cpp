#include <iostream>
#include <vector>
using namespace std;

bool InRange(int r, int c, int n) {
    return r >= 0 && r < n && c >= 0 && c < n; 
}

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<vector<int>> origin_grid(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> origin_grid[i][j];
        }
    }

    int ans = 0;

    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= n; c++) {
            vector<vector<int>> grid = origin_grid;
            int range = grid[r - 1][c - 1];
            grid[r - 1][c - 1] = 0;
            for(int i = 1; i < range; i++) {
                if(InRange(r - 1 + i, c - 1, n)) {
                    grid[r - 1 + i][c - 1] = 0;
                }
                if(InRange(r - 1 - i, c - 1, n)) {
                    grid[r - 1 - i][c - 1] = 0;
                }   
                if(InRange(r - 1, c - 1 - i, n)) {
                    grid[r - 1][c - 1 - i] = 0;
                }
                if(InRange(r - 1, c - 1 + i, n)) {
                    grid[r - 1][c - 1 + i] = 0;
                }
            }

            vector<vector<int>> temp(n, vector<int>(n));
            for(int j = 0; j < n; j++) {
                int temp_r = n - 1;
                for(int i = n - 1; i >= 0; i--) {
                    if(grid[i][j] != 0) {
                        temp[temp_r][j] = grid[i][j];
                        temp_r--;
                    }
                }
            }
            
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(temp[i][j] == 0) continue;
                    if(InRange(i, j + 1, n) && temp[i][j] == temp[i][j + 1]) {
                        if(InRange(i, j + 2, n) && temp[i][j + 2] == temp[i][j]) continue;
                        if(InRange(i, j - 1, n) && temp[i][j - 1] == temp[i][j]) continue;
                        cnt++;
                    }
                    if(InRange(i + 1, j, n) && temp[i][j] == temp[i + 1][j]) {
                        if(InRange(i + 2, j, n) && temp[i + 2][j] == temp[i][j]) continue;
                        if(InRange(i - 1, j, n) && temp[i - 1][j] == temp[i][j]) continue;
                        cnt++;
                    }
                }
            }
            if(ans < cnt) ans = cnt;
        }
    }

    cout << ans;
    return 0;
}