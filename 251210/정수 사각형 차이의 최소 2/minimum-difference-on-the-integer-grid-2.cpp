#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n;
int grid[100][100];
pair<int, int> dp[100][100];

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
            dp[i][j] = {grid[i][j], grid[i][j]};
        }
    }

    dp[0][0] = {grid[0][0], grid[0][0]};
    for(int i = 1; i < n; i++) {
        dp[0][i] = {min(dp[0][i - 1].first, grid[0][i]), max(dp[0][i - 1].second, grid[0][i])};
        dp[i][0] = {min(dp[i - 1][0].first, grid[i][0]), max(dp[i - 1][0].second, grid[i][0])};
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            int num1 = max(dp[i - 1][j].second, grid[i][j]) - min(dp[i - 1][j].first, grid[i][j]);
            int num2 = max(dp[i][j - 1].second, grid[i][j]) - min(dp[i][j - 1].first, grid[i][j]);

            if(num1 <= num2) {
                dp[i][j] = {min(dp[i - 1][j].first, grid[i][j]), max(dp[i - 1][j].second, grid[i][j])};
            }
            else {
                dp[i][j] = {min(dp[i][j - 1].first, grid[i][j]), max(dp[i][j - 1].second, grid[i][j])};
            }
        }
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << dp[i][j].first << dp[i][j].second << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n - 1][n - 1].second - dp[n - 1][n - 1].first;
    return 0;
}