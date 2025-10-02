#include <iostream>

using namespace std;

int R, C;
char grid[15][15];

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    char start = grid[0][0];
    char end = grid[R - 1][C - 1];
    int ans = 0;
    for(int i = 1; i < R - 2; i++) {
        for(int j = 0; j < C - 2; j++) {
            for(int k = i + 1; k < R - 1; k++) {
                for(int l = j + 1; l < C - 1; l++) {
                    if(grid[i][j] != start && grid[k][l] != grid[i][j] && grid[k][l] != end) {
                        ans++;
                    }
                }
            }
        }
    } 

    cout << ans;
    return 0;
}