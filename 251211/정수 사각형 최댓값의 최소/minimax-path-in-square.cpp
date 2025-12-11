#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    int grid[100][100] = {0};
    int dp[100][100] = {0};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    dp[0][0] = grid[0][0];
    for(int i = 1; i < n; i++) {
        dp[0][i] = max(dp[0][i - 1], grid[0][i]);
        dp[i][0] = max(dp[i - 1][0], grid[i][0]);
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = min(max(dp[i - 1][j], grid[i][j]), max(dp[i][j - 1], grid[i][j]));
        }
    }

    cout << dp[n - 1][n - 1];
    return 0;
}