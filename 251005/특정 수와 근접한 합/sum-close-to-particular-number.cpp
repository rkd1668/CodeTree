#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

int N, S;
int arr[100];

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    int ans = INT_MAX;

    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N ;j++) {
            int temp1 = arr[i], temp2 = arr[j];
            int sum = 0;
            arr[i] = 0;
            arr[j] = 0;
            for(int k = 0; k < N; k++) {
                sum += arr[k];
            }

            if(ans > abs(S - sum)) ans = abs(S - sum);
        }
    }

    cout << ans;
    return 0;
}