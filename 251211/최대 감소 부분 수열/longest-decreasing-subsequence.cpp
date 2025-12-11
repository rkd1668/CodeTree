#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    int arr[1000] = {0};
    int dp[1000];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[i]) {
                dp[i] = max(dp[j] + 1, dp[i]);
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