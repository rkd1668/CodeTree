#include <iostream>
#include <climits>

using namespace std;

int n;
int arr[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        arr[i] *= 2;
        for(int j = 0; j < n; j++) {
            int sum = 0, cnt = 0;
            int remaining_arr[100] = {0 , };
            for(int k = 0; k < n; k++) {
                if(k != j) remaining_arr[cnt++] = arr[k];
            }

            for(int k = 0; k < n - 2; k++) {
                sum += abs(remaining_arr[k + 1] - remaining_arr[k]);
            }
            if(sum < ans) ans = sum;
        }
        arr[i] /= 2;
    }

    cout << ans;
    return 0;
}