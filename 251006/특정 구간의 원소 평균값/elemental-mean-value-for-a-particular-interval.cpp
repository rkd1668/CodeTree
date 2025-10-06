#include <iostream>

using namespace std;

int n;
int arr[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int sum = 0;
            for(int k = i; k <= j; k++) {
                sum += arr[k];
            }
            for(int k = i; k <= j; k++) {
                if(sum == arr[k] * (j - i + 1)) {
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans;
    return 0;
}