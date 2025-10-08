#include <iostream>

using namespace std;

int N, K;
int candy[100], pos[100];
int arr[101];

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> candy[i] >> pos[i];
    }

    // Please write your code here.
    for(int i = 0; i < N; i++) {
        arr[pos[i]] += candy[i];
    }
    int ans = 0;
    if(K <= 50) {
        for(int i = K; i <= 100 - K; i++) {
            int sum = 0;
            for(int j = 0; j < 2 * K + 1; j++) {
                sum += arr[i - K + j];
            }
        if(ans < sum) ans = sum;
        }
    }
    else {
        for(int i = 0; i <= 100; i++) {
            ans += arr[i];
        }
    }

    cout << ans;
    return 0;
}