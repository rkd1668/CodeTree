#include <iostream>
#include <climits>

using namespace std;

int n;
int a[1003];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        int dist = 0;
        for(int j = 1; j < n; j++) {
            int room_number = (i + j) % 5;
            dist += a[room_number] * j;
        }
        if(ans > dist) ans = dist;
    }

    cout << ans;
    // Please write your code here.

    return 0;
}