#include <iostream>

using namespace std;

int N;
int x[100];
int y[100];

int FindMax(int i, int j, int k) {
    int max = i;
    if (max < j) max = j;
    if (max < k) max = k;
    return max;
}

int FindMin(int i, int j, int k) {
    int min = i;
    if (min > j) min = j;
    if (min > k) min = k;
    return min;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    // Please write your code here.
    int ans = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                if (x[i] == x[j] && x[j] == x[k]) continue;
                if (y[i] == y[j] && y[j] == y[k]) continue;
                if (x[i] == x[j] || x[j] == x[k] || x[i] == x[k]) {
                    if(y[i] == y[j] || y[j] == y[k] || y[i] == y[k]) {
                        int x_dist = FindMax(x[i], x[j], x[k]) - FindMin(x[i], x[j], x[k]);
                        int y_dist = FindMax(y[i], y[j], y[k]) - FindMin(y[i], y[j], y[k]);
                        int extent = x_dist * y_dist;
                        if (ans < extent) ans = extent;
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}