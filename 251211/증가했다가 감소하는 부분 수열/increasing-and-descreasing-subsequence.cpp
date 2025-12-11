#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000];
int dp[1000][1000];
int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= i; j++) {
            for(int k = 0; k < j; k++) {
                if(arr[k] < arr[j]) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + 1);
                }
            }
        }
        for(int j = i + 1; j < n; j++) {
            for(int k = i; k < j; k++) {
                if(arr[k] > arr[j]) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + 1);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
    return 0;
}