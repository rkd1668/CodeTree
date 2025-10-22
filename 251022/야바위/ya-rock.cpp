#include <iostream>

using namespace std;

int N;
int a[100], b[100], c[100];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    // Please write your code here.
    int ans = 0;
    for(int i = 1; i <= 3; i++) {
        int arr[4] = {0, };
        int score = 0;
        arr[i] = 1;
        for(int j = 0; j < N; j++) {
            int temp = arr[a[j]];
            arr[a[j]] = arr[b[j]];
            arr[b[j]] = temp;

            score += arr[c[j]];
        }

        if(score > ans) ans = score;
    }

    cout << ans;
    return 0;
}