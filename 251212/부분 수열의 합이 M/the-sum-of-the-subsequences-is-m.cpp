#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
int arr[100];
int dp[10001];
int main() {
    // Please write your code here.
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i <= m; i++) {
        dp[i] = INT_MAX;
    }

    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = m; j >= 0; j--) {
            if(j >= arr[i]) {
                if(dp[j - arr[i]] == INT_MAX) continue;

                dp[j] = min(dp[j], dp[j - arr[i]] + 1);
            }
        }
    }

    int ans = dp[m];

    if(ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}