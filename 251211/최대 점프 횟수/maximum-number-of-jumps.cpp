#include <iostream>
#include <climits>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    int arr[1000];
    int dp[1000];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = INT_MIN;
    }

    dp[0] = 0;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(dp[j] == INT_MIN) continue;
            if(arr[j] + j >= i) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}