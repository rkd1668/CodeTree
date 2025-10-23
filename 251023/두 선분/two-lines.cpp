#include <iostream>

using namespace std;

int x1, x2, x3, x4;

int main() {
    cin >> x1 >> x2 >> x3 >> x4;

    // Please write your code here.
    if(x2 < x3 || x4 < x1) cout << "nonintersecting";
    else cout << "intersecting";
    return 0;
}