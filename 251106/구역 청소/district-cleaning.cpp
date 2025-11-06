#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ans = 0;
    if(b < c || d < a) {
        ans = b - a + d - c;
    }
    else {
        ans = max(b, d) - min(a, c);
    }
    cout << ans;
    return 0;
}