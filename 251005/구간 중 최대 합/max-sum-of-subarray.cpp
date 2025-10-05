#include <iostream>

using namespace std;

int n, k;
int arr[100];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    int ans = 0;
    for(int i = 0; i < n - k + 1; i++) {
        int sum = 0;
        for(int j = 0; j < k; j++) {
            sum += arr[i + j];
        }
        if(ans < sum) ans = sum;
    }
    cout << ans;
    return 0;
}