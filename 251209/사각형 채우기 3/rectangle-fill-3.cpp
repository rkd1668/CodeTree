#include <iostream>
using namespace std;

long long int dp[1001], sum[1001];
int main() {
    // Please write your code here.
    int n;
    cin >> n;

    
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 7;
    sum[0] = 1;
    //dp[3] = 22;
    for(int i = 3; i <= n; i++) {
        sum[i - 2] = (sum[i - 2] + sum[i - 3] + dp[i - 2]) % 1000000007;
        dp[i] = (dp[i - 1] * 2 + dp[i - 2] * 3 + sum[i - 3] * 2) % 1000000007;
    }

    cout << dp[n];
    return 0;
}