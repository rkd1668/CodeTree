#include <iostream>
#include <vector>
using namespace std;

void Shift(vector<vector<int>> &v, int m, int r, char d) {
    if(d == 'L') {
        int temp = v[r - 1][m - 1];
        for(int i = m - 1; i >= 1; i--) {
            v[r - 1][i] = v[r - 1][i - 1];
        }
        v[r - 1][0] = temp;
    }
    else {
        int temp = v[r - 1][0];
        for(int i = 0; i < m - 1; i++) {
            v[r - 1][i] = v[r - 1][i + 1];
        }
        v[r - 1][m - 1] = temp;
    }
}

int main() {
    // Please write your code here.
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < q; i++) {
        int r;
        char d;
        cin >> r >> d;
        Shift(grid, m, r, d);
        int up_r = r, down_r = r;
        char up_d = d, down_d = d;
        while(up_r > 1) {
            bool up_continue = false;
            for(int j = 0; j < m; j++){
                if(grid[up_r - 1][j] == grid[up_r - 2][j]) up_continue = true;
            }
            if(up_continue) {
                up_r--;
                if(up_d == 'L') up_d = 'R';
                else up_d = 'L';
                Shift(grid, m, up_r, up_d);
            }
            else break;
        }
        while(down_r < n) {
            bool down_continue = false;
            for(int j = 0; j < m; j++) {
                if(grid[down_r - 1][j] == grid[down_r][j]) down_continue = true;
            }
            if(down_continue) {
                down_r++;
                if(down_d == 'L') down_d = 'R';
                else down_d = 'L';
                Shift(grid, m, down_r, down_d);
            }
            else break;
        }
    }




    //출력
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}