#include <iostream>
#include <algorithm>

using namespace std;

int pos[3];

int main() {
    for (int i = 0; i < 3; i++) cin >> pos[i];

    // Please write your code here.
    sort(pos, pos + 3);
    if(pos[1] - pos[0] == 1 && pos[2] - pos[1] == 1) cout << 0;
    else if(pos[1] - pos[0] == 2 || pos[2] - pos[1] == 2) cout << 1;
    else cout << 2;
    return 0;
}