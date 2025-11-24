#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool InRange(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

int main() {
    // Please write your code here.
    int q;
    cin >> n >> m >> q;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        vector<int> v1, v2, v3, v4;
        v1.push_back(grid[r1][c1 - 1]);
        for(int i = c1 - 1; i < c2 - 1; i++) {
            v1.push_back(grid[r1 - 1][i]);
        }
        v2.push_back(grid[r1 - 1][c2 - 2]);
        for(int i = r1 - 1; i < r2 - 1; i++) {
            v2.push_back(grid[i][c2 - 1]);
        }
        v3.push_back(grid[r2 - 2][c2 - 1]);
        for(int i = c2 - 1; i >= c1; i--) {
            v3.push_back(grid[r2 - 1][i]);
        }
        v4.push_back(grid[r2 - 1][c1]);
        for(int i = r2 - 1; i >= r1; i--) {
            v4.push_back(grid[i][c1 - 1]);
        }
        for(int i = 0; i < v1.size(); i++) {
            grid[r1 - 1][c1 - 1 + i] = v1[i];
            grid[r2 - 1][c2 - 1 - i] = v3[i];
        }
        for(int i = 0; i < v2.size(); i++) {
            grid[r1 - 1 + i][c2 - 1] = v2[i];
            grid[r2 - 1 - i][c1 - 1] = v4[i];
        }

        vector<vector<int>> tmp_v = grid;
        for(int i = r1 - 1; i < r2; i++) {
            for(int j = c1 - 1; j < c2; j++) {
                int cnt = 1;
                int sum = tmp_v[i][j];
                if(InRange(i - 1, j)) {
                    cnt++;
                    sum += tmp_v[i - 1][j];
                }
                if(InRange(i, j - 1)) {
                    cnt++;
                    sum += tmp_v[i][j - 1];
                }
                if(InRange(i + 1, j)) {
                    cnt++;
                    sum += tmp_v[i + 1][j];
                }
                if(InRange(i, j + 1)) {
                    cnt++;
                    sum += tmp_v[i][j + 1];
                }
                grid[i][j] = sum / cnt;
            }
        }
    }

       

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}