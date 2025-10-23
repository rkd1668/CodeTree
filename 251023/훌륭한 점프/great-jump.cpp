#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int arr[100];

bool IsPossible(int max_val) {
    int available_indices[100] = {};
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] <= max_val) available_indices[cnt++] = i;
    }

    for(int i = 1; i < cnt; i++) {
        int dist = available_indices[i] - available_indices[i - 1];
        if(dist > k) return false;
    }

    return true;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    int ans = 100;
    for(int i = max(arr[0], arr[n - 1]); i <= 100; i++) {  
        if(IsPossible(i)) {
            if(ans > i) ans = i;
        }
    }

    cout << ans;
    return 0;
}