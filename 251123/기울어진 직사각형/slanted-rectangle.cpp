#include <iostream>
#include <vector>
using namespace std;

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

    int ans = 0;
    for(int r = 2; r < n; r++) {
        for(int c = 1; c < n - 1; c++) {
            for(int i = 1; i < n; i++) {
                for(int j = 1; j < n; j++) {
                    if(r - i - j < 0 || c + i > n - 1 || c - j < 0) continue;
                    int cost = 0;
                    for(int k = 0; k <= i; k++) {
                        cost += grid[r - k][c + k];
                    }
                    for(int k = 0; k <= j; k++) {
                        cost += grid[r - i - k][c + i - k];
                    }
                    for(int k = 0; k <= i; k++) {
                        cost += grid[r - i - j + k][c + i - j - k];
                    }
                    for(int k = 0; k <= j; k++) {
                        cost += grid[r - j + k][c - j + k];
                    }
                    cost -= (grid[r][c] + grid[r - i][c + i] + grid[r - i - j][c + i - j] + grid[r -j][c - j]);
                    if(ans < cost) ans = cost;
                }
            }
        }
    }

    cout << ans;
    return 0;
}