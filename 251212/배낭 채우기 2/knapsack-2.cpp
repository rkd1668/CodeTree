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

    for(int i = 1; i < n; i++) {
        dp[i] = INT_MIN;
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < n; j++) {
            if(i >= jewels[j].first) {
                if(dp[i - jewels[j].first] == INT_MIN) continue;

                dp[i] = max(dp[i], dp[i - jewels[j].first] + jewels[j].second);
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