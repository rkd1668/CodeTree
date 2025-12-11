#include <iostream>
#include <climits>
using namespace std;

int n, m;
int grid[50][50], dp[50][50];

int main() {
    // Please write your code here.
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            dp[i][j] = INT_MIN;
        }
    }
    dp[0][0] = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            for(int x = 0; x < i; x++) {
                for(int y = 0; y < j; y++) {
                    if(dp[x][y] == INT_MIN) continue;
                    if(grid[x][y] < grid[i][j]) {
                        dp[i][j] = max(dp[i][j], dp[x][y] + 1);
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
    return 0;
}