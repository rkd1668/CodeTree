#include <iostream>

using namespace std;

int n;
int arr[20];

int GetNumber(int number, int position) {
    int ten_power = 10000;
    for(int i = 0; i < position; i++) {
        number %= ten_power;
        ten_power /= 10;
    }
    return number / ten_power;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    int ans = 0;

    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {
                bool isnotcarry = true;
                int sum = 0;
                for(int l = 0; l < 5; l++) {
                    int n = GetNumber(arr[i], l) + GetNumber(arr[j], l) + GetNumber(arr[k], l);
                    if(n >= 10) {
                        isnotcarry = false;
                        break;
                    }
                }
                if(isnotcarry) {
                    sum = arr[i] + arr[j] + arr[k];
                    if(ans < sum) ans = sum;
                }
            }
        }
    }

    cout << ans;

    return 0;
}