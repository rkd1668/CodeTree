#include <iostream>
#include <climits>
using namespace std;

int n;
int arr[100];
int dp[100001];
int main() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    for(int i = 0; i <= sum; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = sum;
    for(int i = 0; i < n; i++) {
        for(int j = sum; j >= 0; j--) {
            if(j >= arr[i]) {
                if(dp[j - arr[i]] == INT_MAX) continue;

                dp[j] = abs(sum - 2 * j);
            }
        }
    }

    // for(int i = 0; i <= sum; i++) {
    //     cout << dp[i] << " ";
    // }
    
    int ans = INT_MAX;
    for(int i = 1; i < sum; i++) {
        ans = min(ans, dp[i]);
    }

    cout << ans;
    return 0;
}
