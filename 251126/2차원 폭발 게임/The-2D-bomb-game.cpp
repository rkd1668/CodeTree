#include <iostream>
#include <vector>
using namespace std;


void Fall(vector<vector<int>> &grid, int n) {
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
    grid = temp;
}

void Rotate(vector<vector<int>> &grid, int n) {
    vector<vector<int>> temp(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temp[i][j] = grid[n - 1 - j][i];
        }
    }
    grid = temp;
    Fall(grid, n);
}

void Bomb(vector<vector<int>> &grid, int n, int m) {
    for(int j = 0; j < n; j++) {
        bool explosion = true;
        while(explosion) {
            bool check = true;
            int cnt = 1;
            int start = 0, end = 0;
            for(int i = 0; i < n ; i++) {
                if(i != n - 1 && grid[i][j] == grid[i + 1][j] && grid[i][j] != 0) {
                    cnt++;
                    end = i + 1;
                }
                if(n == 1 && grid[i][j] != grid[i + 1][j] || i == n - 2) {
                    if(cnt >= m) {
                        for(int k = start; k <= end; k++) {
                            grid[k][j] = 0;
                        }
                        check = false;
                        //if(n == 1) check = true;
                    }
                    cnt = 1;
                    start = i + 1;
                    end = i + 1;
                }
            }
            Fall(grid, n);
            if(check) explosion = false;
        }
    }
}


int main() {
    // Please write your code here.
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    for(int i = 0; i < k; i++) {
        Bomb(grid, n, m);
        Rotate(grid, n);
    }

    Bomb(grid, n, m);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] != 0) ans++;
        }
    }

    cout << ans;
    return 0;
}