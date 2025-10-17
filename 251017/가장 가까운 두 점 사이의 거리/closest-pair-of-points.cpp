#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int n;
int x[100], y[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // Please write your code here.
    int ans = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = 0;
            dist = pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2);
            if (dist < ans) ans = dist;
        }
    }

    cout << ans;
    return 0;
}