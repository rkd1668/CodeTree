#include <iostream>

using namespace std;

int N;
int dp[46];

int main() {
    cin >> N;

    // Please write your code here.
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i <= N; i++) {
        dp[i] = dp[i - 2] + dp[i - 1];
    }

    cout << dp[N];
    return 0;
}
