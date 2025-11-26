#include <iostream>
#include <vector>
using namespace std;

bool InRange(int r, int c, int n) {
    return r >= 0 && r < n && c >= 0 && c < n;
}
int main() {
    // Please write your code here.
    int n, input_r, input_c;
    cin >> n >> input_r >> input_c;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int r = input_r - 1, c = input_c - 1;
    cout << grid[r][c] << " ";
    int check = true;
    while(check) {
        for(int i = 0; i < 4; i++) {
            if(InRange(r + dr[i], c + dc[i], n)) {
                if(grid[r][c] < grid[r + dr[i]][c + dc[i]]) {
                    r = r + dr[i];
                    c = c + dc[i];
                    cout << grid[r][c] << " ";
                    break;
                }
            }
            if(i == 3) check = false;
        }
    }
    return 0;
}