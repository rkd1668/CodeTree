#include <iostream>
using namespace std;

int n, m;
int arr[100];
int dp[10001];

int main() {
    // Please write your code here.
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = m; j >= 0; j--) {
            if(j >= arr[i]) {
                if(dp[j - arr[i]] == 0) continue;

                dp[j] = 1;
            }
        }
    }

    if(dp[m] == 1) cout << "Yes";
    else cout << "No";
   
    return 0;
}