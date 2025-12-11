#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n;
vector<tuple<int, int, int>> v;
int dp[1000];

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++) {
        int s, e, p;
        cin >> s >> e >> p;
        v.push_back({s, e, p});
    }

    for(int i = 0; i < n; i++) {
        dp[i] = get<2>(v[i]);
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            int e1 = get<1>(v[j]);
            int s2 = get<0>(v[i]);
            if(e1 < s2) {
                dp[i] = max(dp[i], dp[j] + get<2>(v[i]));
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