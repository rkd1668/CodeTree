#include <iostream>
#include <vector>
using namespace std;

void Shift(vector<vector<int>> &grid, int r, int c, int m1, int m2, int m3, int m4, int d) {
    int temp = grid[r - 1][c - 1];
    if(d == 0) {
        for(int i = 0; i < m4; i++) {
            grid[r - 1 - i][c - 1 - i] = grid[r - 1 - i - 1][c - 1 - i - 1];
        }
        for(int i = 0; i < m3; i++) {
            grid[r - 1 - m4 - i][c - 1 - m4 + i] = grid[r - 1 - m4 - i - 1][c - 1 - m4 + i + 1];
        }
        for(int i = 0; i < m2; i++) {
            grid[r - 1 - m1 - m2 + i][c - 1 + m1 - m2 + i] = grid[r - 1 - m1 - m2 + i + 1][c - 1 + m1 - m2 + i + 1] ;
        }
        for(int i = 0; i < m1 - 1; i++) {
            grid[r - 1 - m1 + i][c - 1 + m1 - i] = grid[r - 1 - m1 +i + 1][c - 1 + m1 - i - 1]; 
        }
        grid[r - 1 - 1][c - 1 + 1] = temp;
    }
    else {
        for(int i = 0; i < m1; i++) {
            grid[r - 1 - i][c - 1 + i] = grid[r - 1 - i - 1][c - 1 + i + 1]; 
        }
        for(int i = 0; i < m2; i++) {
            grid[r - 1 - m1 - i][c - 1 + m1 - i] = grid[r - 1 - m1 - i - 1][c - 1 + m1 - i - 1]; 
        }
        for(int i = 0; i < m3; i++) {
            grid[r - 1 - m1 - m2 + i][c - 1 + m1 - m2 - i] = grid[r - 1 - m1 - m2 + i + 1][c - 1 + m1 - m2 - i - 1];
        }
        for(int i = 0; i < m4 - 1; i++) {
            grid[r - 1 - m4 + i][c - 1 -m4 + i] = grid[r - 1 - m4 + i + 1][c - 1 -m4 + i + 1];
        }
        grid[r - 1 - 1][c - 1 - 1] = temp;
    }
}

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int r, c, m1, m2, m3, m4, d;
    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> d;
    Shift(grid, r, c, m1, m2, m3, m4, d);


    //출력
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}