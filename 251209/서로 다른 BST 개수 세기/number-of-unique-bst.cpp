#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    int dp[20];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++) {
        int sum = 0;
        for(int j = 1; j <= i; j++) {
            int left = j - 1;
            int right = i - j;
            sum += dp[left] * dp[right];
        }
        dp[i] = sum;
    }
    cout << dp[n];
    return 0;
}