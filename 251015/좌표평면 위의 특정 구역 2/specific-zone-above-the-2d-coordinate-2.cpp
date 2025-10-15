#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int N;
int x[100], y[100];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    // Please write your code here.
    int ans = INT_MAX;

    for(int i = 0; i < N; i++) {
        int extent = 0;
        int x1 = 0, x2 = INT_MAX, y1 = 0, y2 = INT_MAX;
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            x1 = max(x1, x[j]);
            x2 = min(x2, x[j]);
            y1 = max(y1, y[j]);
            y2 = min(y2, y[j]);
        }
        extent = (x1 - x2) * (y1 - y2);
        if(ans > extent) ans = extent;
    }
    cout << ans;
    return 0;
}