#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int x1, y1, x2, y2;
int a1, b1, a2, b2;

int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> a1 >> b1 >> a2 >> b2;

    // Please write your code here.
    int area = (abs(max(x2, a2)) - abs(min(x1, a1))) * (abs(max(y2, b2)) - abs(min(y1, b1)));
    cout << area;
    return 0;
}