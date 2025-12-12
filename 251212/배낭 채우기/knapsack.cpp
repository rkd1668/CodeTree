#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
pair<int, int> jewels[100];
int dp[10001];
int main() {
    // Please write your code here.
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        jewels[i] = {w, v};
    }

    for(int i = 1; i <= m; i++) {
        dp[i] == INT_MIN;
    }
    for(int i = 0; i < n; i++) {
        for(int j = m; j >= 0; j--) {
            if(j >= jewels[i].first) {
                if(dp[j - jewels[i].first] == INT_MIN) continue;

                dp[j] = max(dp[j], dp[j - jewels[i].first] + jewels[i].second);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= m; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}