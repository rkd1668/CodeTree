#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    vector<int> pos(3);
    for(int i = 0; i < 3; i++) {
        cin >> pos[i];
    }

    int ans = max(pos[1] - pos[0], pos[2] - pos[1]) - 1;
    cout << ans;
    return 0;
}