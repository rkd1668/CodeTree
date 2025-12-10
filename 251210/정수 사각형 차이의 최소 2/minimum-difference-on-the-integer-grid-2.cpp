#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n;
int grid[100][100];
int dp[100][100][101];

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }    

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k <= 100; k++) {
                dp[i][j][k] = INT_MAX;
            }
        }
    }

    int start = grid[0][0];

    dp[0][0][start] = start;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) continue;

            int val = grid[i][j];

            for(int k = 1; k <= 100; k++) {
                if(i > 0 && dp[i - 1][j][k] != INT_MAX) {
                    int new_min = min(k, val);
                    int new_max = max(dp[i - 1][j][k], val);
                    dp[i][j][new_min] = min(dp[i][j][new_min], new_max);
                }

                if(j > 0 && dp[i][j - 1][k] != INT_MAX) {
                    int new_min = min(k, val);
                    int new_max = max(dp[i][j - 1][k], val);
                    dp[i][j][new_min] = min(dp[i][j][new_min], new_max);
                }
            }
        }
    }


    int ans = INT_MAX;

    for(int k = 1; k <= 100; k++) {
        if(dp[n - 1][n - 1][k] != INT_MAX) {
            ans = min(ans, dp[n - 1][n - 1][k] - k);
        }
    }
    cout << ans;
}