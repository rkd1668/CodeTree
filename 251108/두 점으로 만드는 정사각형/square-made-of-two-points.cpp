#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int x1[2], x2[2], y1[2], y2[2];
    for(int i = 0; i < 2; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }

    int x_min = min(x1[0], x1[1]);
    int x_max = max(x2[0], x2[1]);
    int y_min = min(y1[0], y1[1]);
    int y_max = max(y2[0], y2[1]);
    int ans = max(x_max - x_min, y_max - y_min) * max(x_max - x_min, y_max - y_min);
    cout << ans;
    return 0;
}