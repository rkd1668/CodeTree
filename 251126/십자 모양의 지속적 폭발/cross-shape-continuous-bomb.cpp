#include <iostream>
#include <vector>
using namespace std;

bool InRange(int r, int c, int n) {
    return r >= 0 && r < n && c >= 0 && c < n; 
}

int main() {
    // Please write your code here.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }


    for(int i = 0; i < m; i++) {
        int c;
        cin >> c;
        int r = -1;
        for(int j = 0; j < n; j++) {
            if(grid[j][c - 1] != 0) {
                r = j + 1;
                break;
            }
        }
        if(r != -1) {
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
            grid = temp;   
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