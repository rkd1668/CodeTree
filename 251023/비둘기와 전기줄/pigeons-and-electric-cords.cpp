#include <iostream>

using namespace std;

int N;
int pigeon[100];
int position[100];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> pigeon[i] >> position[i];
    }

    // Please write your code here.
    int ans = 0;
    int arr[11] = {};
    for(int i = 1; i < 11; i++) {
        arr[i] = -1;
    }

    for(int i = 0; i < N; i++) {
        if(arr[pigeon[i]] == -1) arr[pigeon[i]] = position[i];
        else if(arr[pigeon[i]] != position[i]) {
            ans++;
            arr[pigeon[i]] = position[i];
        }
    }

    cout << ans;
    return 0;
}