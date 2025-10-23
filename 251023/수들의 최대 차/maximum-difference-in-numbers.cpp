#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int arr[1000];

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    int ans = 0;
    sort(arr, arr + N);
    for(int i = 0;i < N; i++) {
        int cnt = 1;
        for(int j = i + 1; j < N; j++) {
            if(arr[j] - arr[i] <= K) cnt++;
            else break;
        }
        if(ans < cnt) ans = cnt;
    }

    cout << ans;
    return 0;
}