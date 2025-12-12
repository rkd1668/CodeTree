#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n;
int value[100];
int dp[101];

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> value[i];
    }

    for(int i = 1; i <= n; i++) {
        dp[i] = INT_MIN;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < n; j++) {
            if(i >= j + 1) {
                dp[i] = max(dp[i], dp[i - j - 1] + value[j]);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}