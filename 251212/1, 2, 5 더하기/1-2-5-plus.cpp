#include <iostream>
#include <climits>
using namespace std;

int dp[1001];

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    int arr[3] = {1, 2, 5};

    dp[1] = 1;
    dp[2] = 1;
    dp[5] = 1;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            if(i >= arr[j]) {

                dp[i] += dp[i - arr[j]];
                dp[i] %= 10007;
            }
        }
    }
   
    cout << dp[n];
    return 0;
}