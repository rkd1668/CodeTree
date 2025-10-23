#include <iostream>

using namespace std;

int a, b, x, y;

int main() {
    cin >> a >> b >> x >> y;

    // Please write your code here.
    int ans = abs(a - b);
    int way1 = abs(x - a) + abs(y - b);
    int way2 = abs(y - a) + abs(x - b);
    if(ans > way1) ans = way1;
    if(ans > way2) ans = way2;

    cout << ans;
    return 0;
}